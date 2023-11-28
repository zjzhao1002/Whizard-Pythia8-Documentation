# Description
MadGraph5_aMC@NLO is a framework that aims at providing all the elements necessary for SM and BSM phenomenology, 
such as the computations of cross sections, the generation of hard events and their matching with event generators, 
and the use of a variety of tools relevant to event manipulation and analysis. Processes can be simulated to LO accuracy for any user-defined Lagrangian, 
and the NLO accuracy in the case of models that support this kind of calculations -- prominent among these are QCD and EW corrections to SM processes. 
Matrix elements at the tree- and one-loop-level can also be obtained. 

MadGraph5 can be downloaded from 
* [https://launchpad.net/mg5amcnlo](https://launchpad.net/mg5amcnlo)

or clone a git version:
```
git clone https://github.com/mg5amcnlo/mg5amcnlo.git
```

The configurations of MadGraph5 are done in the following file
```
<YOUR_PATH_TO_MADGRAPH5>/input/mg5_configuration.txt
```
Especially, you should give your path to Pythia8 if you want to use Pythia8 shower. 
Pythia8.2 has been well tested for NLO, and Pythia8.3 has been well tested for LO. 
Principlely, Pythia8.3 should work for both. But we need some further checks.

Now you can go to MadGraph5 directory and run
```
./bin/mg5_aMC
```

Now you are running MadGraph in command line mode. To generate events, you can run something like
```
generate e+ e- > b b~ mu+ mu- aEW=4 aS=0 [all=QCD]
```
It will generate bbmumu process at ee collision, with the electroweak coupling power up to 4 and the strong coupling power up to zero.
In default, MadGraph5 only generates diagrams with the highest strong coupling power. 
You have to specify the aEW value to obtain all diagrams of the process.
[all=QCD] means including all QCD corrections. If you only need LO result, please just remove this part. 

The next step is generating codes for the simulation of this process. You can run something like
```
output eebbmumu_NLO
```
eebbmumu_NLO is a folder name and can be anything. 
All codes for simulation are stored in the directory
```
<YOUR_PATH_TO_MADGRAPH5>/eebbmumu_NLO
```
From now on, I assume you are working in this directory. You should find 
```
bin/generate_events
```
to generate events.

The model parameters and collider setup can be input by editing following files
```
Cards/parm_card.dat
Cards/run_card.dat
```
In the **param_card.dat**, you can modify some physical parameters, such as the masses, widths and couplings.
In the **run_card.dat**, you can modify the beam energy, beam structure functions, cuts, scales and so on. 
These cards have some differences between the LO case and the NLO case. 
Examples can be found here.

There are two methods to implement cuts: 
* Editting the run_card.dat
* Writing some fortran codes to implement user defined cuts

Template of the second method can be found in
```
SubProcesses/dummy_fct.f
```
**dummy_fct_LO.f** and **dummy_fct_NLO.f** provide two examples to implement user defined cuts for LO and NLO, respectively.
What we need to do is coding the contents of **dummy_cuts** function. 
If the event do not pass the user defined cuts, set the value of **dummy_cuts** to false.
Finally, you have to give your path to this file to **custom_fcts** in the **run_card.dat**.
