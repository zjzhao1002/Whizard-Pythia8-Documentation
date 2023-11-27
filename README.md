# Whizard-Pythia8-Documentation
This is a documentation for running events generation with Whizard+Pythia8 framework, including the Leading-Order (LO) and Next-to-Leading-Order (NLO) cases.
## Prerequisites
The following packages are necessary to install before installing Whizard and Pythia8.
### LHAPDF
LHAPDF is the standard tool for evaluating parton distribution functions (PDFs) in high-energy physics. It is not necessary for lepton collision, but Whizard will check if it exists when your configuration includes the arguements for NLO calculations.

LHAPDF can be downloaded from 
* [https://lhapdf.hepforge.org/](https://lhapdf.hepforge.org/)

The website contains comprehensive documentation on the configuring and installation procedure. Whizard will check if you install the following PDF sets:
* CT10
* cteq6l1
* NNPDF23_lo_as_0130_qed
* NNPDF23_nlo_as_0118

Please make sure your PDF sets are located in the directory
```
<YOUR_INSTALL_PATH>/share/LHAPDF
```
### HEPMC2
The HepMC package is an object oriented, C++ event record for High Energy Physics Monte Carlo generators and simulation. It can be downloaded from
* [http://hepmc.web.cern.ch/hepmc/](http://hepmc.web.cern.ch/hepmc/)

Be careful! You have to install the version 2 rather than the 3.x.x, because the **ddsim** can only read the version 2 at present. The configure should be something like:
```
configure --with-momentum=GEV --with-length=MM --prefix=<install dir>
```
This means that the momentum unit is GeV and the length unit is mm in the hepmc file.
### FastJet
FastJet is a C++ class library for handling jet clustering. It is necessary for some NLO runs. It can be downloaded from
* [http://fastjet.fr/](http://fastjet.fr/)
### OpenLoops
The OpenLoops is a fully automated implementation of the Open Loops algorithm combined with on-the-fly reduction methods, which allows for the fast and stable numerical evaluation of tree and one-loop matrix elements for any Standard Model process at NLO QCD and NLO EW. It acts as an one loop provider for Whizard. It can be obtained by 
```
git clone https://gitlab.com/openloops/OpenLoops.git
```
After checkout or download of OpenLoops you can compile the code using the following procedure: 
```
cd OpenLoops
./scons 
```
Before starting to use OpenLoops you have to download and compile the process libraries for the amplitudes you want to use. You can download several individual processes via
```
./openloops libinstall <processes>
```
Whizard will check if you have installed the following processes:
* eett
* ppllj
* tbw

It is recommended to create a **openloops.cfg** file in the OpenLoops directory with following contents:
```
[OpenLoops]
process_repositories=public, whizard
compile_extra=1
```
So you can also download some libraries for Whizard in particular.

## Installation of Pythia8
Now you can download Pythia8 from
* [https://pythia.org/](https://pythia.org/)

In the configure of Pythia8, you should add your path to **HepMC2**, **LHAPDF**, and **FastJet** by 
```
--with-PACKAGE=[=DIR]
```
If Pythia8 finds them successfully, some messages should be printed on your screen. After that, you can just run
```
make
make install
```

## Installation of Whizard
Finally, you can install Whizard. In this case, your configure is quite long, because you have to add
```
--enable-PACKAGE --with-PACKAGE=<YOUR_PATH_TO_THIS_PACKAGE>
```
for all packages described above. If Whizard finds them successfully, some messages should be printed on your screen. If some packages are missed, you can try to edit the environment variables:
```
PATH
LD_LIBRARY_PATH
```
or add some environment variables like
```
HEPMC_DIR
LHAPDF_DIR
```
If everything is fine, you can just run 
```
make
make install
```
