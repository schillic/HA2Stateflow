This is supplementary material for the article [*Hybrid automata: from verification to implementation*](http://dx.doi.org/10.1007/s10009-017-0458-1), STTT, 2017.

The tool has also been integrated in [HyST](https://github.com/verivital/hyst).

---

The archive contains:
* a folder `examples` that includes all benchmarks
* a folder `lib` that includes an executable Jar file of [Hyst](http://verivital.com/hyst/)
* a folder `src` that includes the source code of the translator
* a folder `buck_interval` that includes all necessary files to reproduce the experimental results for the buck converter evaluated in the paper;
  Particularly, this folder contains the following:
   * SpaceEx model files for buck converter using intervals 
   * a folder "buck_interval_data" that includes data obtained from SLSF simulation, reachability analysis with SpaceEx, and hardware experiment with dSPACE DS1103 system 
   * a folder "code_generation" that includes C code generation for the buck converter by dSPACE
   * a file "dSPACE Experiment Report" that describes in details the dSPACE experiment for the buck converter

---

To run the translator, do the following:

* Open Matlab.
* Move to the folder where you extracted the files.
* Add the source code to the Matlab path (in the "Current Folder" view).
   For that, right-click on the folder "src" and select "Add to Path" and the subcategory "Selected Folders and Subfolders".
* Run the following command (where you replace "MODEL_NAME" by a meaningful relative path of your model file):

    `SpaceExToStateflow('MODEL_NAME', '-s');`

This produces a StateFlow model (which might take some time, especially when the Simulink libraries have not been loaded yet).


  Example call:
  
     `SpaceExToStateflow('examples\vanderpol\vanderpol.xml', '-s');`

---

To run the simulation loop, run the following (parametrized) command:

    `simulationLoop('MODEL_NAME', NUM_SIMULATION, MAX_TIME, NUM_BACKTRACK);`

Here, the parameters denote the following:
* the model name (automatically taken from the `*.xml` file)
* the number of simulations
* the maximum simulation time
* the number of backtrackings

Again, this might take some time the first time of the call because Simulink compiles the model in the background.


  Example call:
  
     `simulationLoop('vanderpol', 5, 50, 3);`

---

To reproduce the table of benchmarks in the appendix, run the following script file:

    `generateTable`
