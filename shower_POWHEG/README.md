# Description
This is a simple program to run Pythia8 parton shower and hadronization with POWHEG matching. 
You have to prepare POWHEG events in a LHE file as input.
The output file is HepMC2 format. 
You can edit your paths to **Pythia8** and **HepMC2** in the Makefile, and run
```
make 
```
to compile the codes. 

The POWHEG commands can be found in the **pythia8_input.cmnd**. Most of these parameters are in their default values. 
In many cases, we just need to edit the **POWHEG:nfinal = 2** to the final state in our process.
More details of these parameters can be found on the Pythia8 manual:
* [https://pythia.org//latest-manual/Welcome.html](https://pythia.org//latest-manual/Welcome.html)
