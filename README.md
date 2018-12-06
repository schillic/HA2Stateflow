This is supplementary material for the paper "Hybrid automata: from verification to implementation" pusblished in the journal STTT in 2017.

The tool has also been integrated in [HyST](https://github.com/verivital/hyst).

---

The archive contains:
1) a folder `examples` that includes all benchmarks
2) a folder `lib` that includes an executable Jar file of Hyst tool: http://verivital.com/hyst/
3) a folder `src` that includes the source code for the translator
4) a folder `buck_interval` that includes all necessary files to reproduce the experimental results for the buck converter evaluated in the paper;
  Particularly, this folder contains the following:
   a) SpaceEx model files for buck converter using intervals 
   b) a folder "buck_interval_data" that includes data obtained from SLSF simulation, reachability analysis with SpaceEx, and hardware experiment with dSPACE DS1103 system 
   c) a folder "code_generation" that includes C code generation for the buck converter by dSPACE
   d) a file "dSPACE Experiment Report" that describes in details the dSPACE experiment for the buck converter

---

To run the translator, do the following:

1) Open Matlab.
2) Move to the folder where you extracted the files.
3) Add the source code to the Matlab path (in the "Current Folder" view).
   For that, right-click on the folder "src" and select "Add to Path" and the subcategory "Selected Folders and Subfolders".
4) Run the following command (where you replace "MODEL_NAME" by a meaningful relative path of your model file):

    `SpaceExToStateflow('MODEL_NAME', '-s');`

This produces a StateFlow model (which might take some time, especially when the Simulink libraries have not been loaded yet).


  Example call:
  
     `SpaceExToStateflow('examples\vanderpol\vanderpol.xml', '-s');`

---

To run the simulation loop, run the following (parametrized) command:

    `simulationLoop('MODEL_NAME', NUM_SIMULATION, MAX_TIME, NUM_BACKTRACK);`

Here, the parameters denote the following:
1) the model name (automatically taken from the `*.xml` file)
2) the number of simulations
3) the maximum simulation time
4) the number of backtrackings

Again, this might take some time the first time of the call because Simulink compiles the model in the background.


  Example call:
  
     `simulationLoop('vanderpol', 5, 50, 3);`

---

To reproduce the table of benchmarks in the appendix, run the following script file:

    `generateTable`
