% convert all the benchmarks

% close all slsf models (caution, will undo any changes):
bdclose('all'); % kill Simulink windows
close all; % kill figures

opt_simulate = 1; % do simulation after translation?

path_prefix = ['examples', filesep];

models = {...
['biology_1', filesep, 'biology_1']
['biology_2', filesep, 'biology_2']
['bouncing_ball', filesep, 'bouncing_ball']
['brusselator', filesep, 'brusselator']
['buckling_column', filesep, 'buckling_column']
['coupledVanderPol', filesep, 'coupledVanderPol']
['E5', filesep, 'E5']
['fischer', filesep, 'fischer_N2_flat_safe']
['fischer', filesep, 'fischer_N2_flat_unsafe'] 
['glycemic_control', filesep, 'glycemic_control_1']
['glycemic_control', filesep, 'glycemic_control_2']
['glycemic_control_polynomial', filesep, 'glycemic_control_poly1']
['glycemic_control_polynomial', filesep, 'glycemic_control_poly2']
['helicopter', filesep, 'helicopter']
['Hires', filesep, 'Hires']
['jet_engine', filesep, 'jet_engine']
['lac_operon', filesep, 'lac_operon']
['lorentz', filesep, 'lorentz']
['lotka_volterra', filesep, 'lotka_volterra']
['non_linear_transmission_line_circuits', filesep, 'circuits_n2']
['non_linear_transmission_line_circuits', filesep, 'circuits_n4']
['non_linear_transmission_line_circuits', filesep, 'circuits_n6']
['non_linear_transmission_line_circuits', filesep, 'circuits_n8']
['non_linear_transmission_line_circuits', filesep, 'circuits_n10']
['non_linear_transmission_line_circuits', filesep, 'circuits_n12']
['OREGO', filesep, 'OREGO']
['randgen', filesep, 'randgen']
['Rober', filesep, 'Rober']
['roessler', filesep, 'roessler']
['small_circuit', filesep, 'small_circuit']
['spiking_neuron', filesep, 'spiking_neuron']
['spring_pendulum', filesep, 'spring_pendulum']
['vanderpol', filesep, 'vanderpol']
};

table_header = ['Name & Type & |Var| & |Loc| & |Trans| & t_{c} & t_{s} \tabularnewline ', sprintf('\n')];
table_string = table_header;

for i = 1 : length(models)
	tic; % reset timer for benchmarking
	
	name = models(i);
	name_str = char(name);
	[pathstr,filename,ext] = fileparts(name_str);
	
	xml_file = [path_prefix, pathstr, filesep, filename, '.xml'];
	cfg_file = [path_prefix, pathstr, filesep, filename, '.cfg'];
	
	[out_slsf_model, out_slsf_model_path, out_config] = SpaceExToStateflow(xml_file, cfg_file, '-s');
	
	if out_config.root.constants.containsKey('tmax')
		tmax = out_config.root.constants.get('tmax');
	else
		tmax = 5; % default time units (seconds)
	end
	
	conversionTime = toc;
	
	figure;
	hold on;
	
	tic; % reset timer
	if opt_simulate
		simulationLoop(filename, 2, tmax, 1000);
	end
	simulationTime = toc;
	
	% latex table string
	table_row = [strrep(filename, '_', '\_'), ...
		' & ', 'todo type', ...
		' & ', num2str(out_config.root.variables.size), ...
		' & ', num2str(out_config.root.modes.size), ...
		' & ', num2str(out_config.root.transitions.size), ...
		' & ', num2str(conversionTime), ...
		' & ', num2str(simulationTime), '\tabularnewline  ', sprintf('\n')];
	
	table_string = [table_string, table_row];
	
	bdclose('all'); % kill Simulink window
	close all; % kill figure
end

table_string
