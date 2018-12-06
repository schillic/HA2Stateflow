function [out_slsf_model, out_slsf_model_path, out_config] = SpaceExToStateflow(varargin)
%SPACEEXTOSTATEFLOW SpaceEx to Stateflow conversion
%
% example call without semantics preservation:
% SpaceExToStateflow('..\..\examples\myfolder\mymodel.xml')
% This uses SpaceEx model ..\..\examples\myfolder\mymodel.xml with mymodel.cfg.
% users can be able to specify a configuration file (myconfig.cfg) by calling
% SpaceExToStateflow('..\..\examples\myfolder\mymodel.xml', '..\..\examples\myfolder\myconfig.xml')
% example call with semantics preservation: add '-s' like in the following:
% SpaceExToStateflow('..\..\examples\myfolder\mymodel.xml', '-s')
% 
%
% Actual calls on example systems:
%
% 1) Heater Lygeros system
% This model has nondeterminism, so to simulate all executions, we need to
% use the semantics preserving converter. The non-semantics preserving
% converter will work, but it will generate ONE of the infinitely many
% executions (all modulo numeric accuracy of course).
%
% SpaceExToStateflow('..\..\examples\heaterLygeros\heaterLygeros.xml')
% 
% 2) Van Der Pol Oscillator (nonlinear example)
%
% SpaceExToStateflow('..\..\examples\vanderpol\vanderpol.xml')
%
% You can manually add an X-Y graph scope/plot and see that its phase
% portrait looks correct.

    %Ex: how to instantiate java objects into Matlab
    %add java library for spaceex parsing library 
    addpath(['lib', filesep]);
    javaaddpath(['lib', filesep, 'Hyst.jar']);
       
    import com.verivital.hyst.automaton.*;
    import com.verivital.hyst.grammar.antlr.*;
    import com.verivital.hyst.grammar.formula.*;
    import com.verivital.hyst.importer.*;
    import com.verivital.hyst.ir.*;
    import com.verivital.hyst.ir.base.*;
    import com.verivital.hyst.ir.network.*;
    import com.verivital.hyst.junit.*;
    import com.verivital.hyst.main.*;
    import com.verivital.hyst.outputparser.*;
    import com.verivital.hyst.passes.*;
    import com.verivital.hyst.passes.basic.*;
    import com.verivital.hyst.passes.complex.*;
    import com.verivital.hyst.passes.flatten.*;
    import com.verivital.hyst.printers.*;
    import com.verivital.hyst.python.*;
    import com.verivital.hyst.simulation.*;
    import com.verivital.hyst.util.*;
   
    import de.uni_freiburg.informatik.swt.spaceexxmlprinter.*;
    import de.uni_freiburg.informatik.swt.spaxeexxmlreader.*;
    import de.uni_freiburg.informatik.swt.sxhybridautomaton.*;
    
    %
    % add classes and functions subfolders to path
    addpath(genpath('functions'));
    % Specify options from the input argument
    [options, path_name, xml_filename, cfg_filename] = ...
        option_SpaceExToStateflow(varargin);
    
    xml_filepath = [path_name, filesep, xml_filename];
    cfg_filepath = [path_name, filesep, cfg_filename];
    
    [config, name] = createConfigFromSpaceEx(xml_filepath, cfg_filepath);
    
    output_path = ['.', filesep, 'output_slsf_models', filesep];
    if isequal(exist(output_path, 'dir'),7) == 0
        % if the output directory does not exist, generate it
        mkdir(output_path);       
    end
    
    bdclose(name); % close model (uncoditionally, careful in case this is called and open diagrams are not saved!)
    
    % Reference: http://blogs.mathworks.com/seth/2010/01/21/building-models-with-matlab-code/
    % Reference: http://www.mathworks.com/help/stateflow/api/quick-start-for-the-stateflow-api.html
    rt = sfroot;
    % chart_ref = m.find('-isa','Stateflow.Chart');
    prev_models = rt.find('-isa','Simulink.BlockDiagram');
    % create new model with Matlab action language
    sfnew('-MATLAB');
    % get current models
    curr_models = rt.find('-isa','Simulink.BlockDiagram');
    % new model is current models - previous models
    m = setdiff(curr_models, prev_models);
    % save model file
    slsf_model_path = [output_path, name, '.mdl'];
    sfsave(m.Name, slsf_model_path);
    
    % translates the automaton to Stateflow
    translateAutomaton(m, config, options);
    
    % Save model file
    sfsave(m.Name, slsf_model_path);
    % output
    out_slsf_model_path = slsf_model_path;
    out_slsf_model = m;
    out_config = config;
end