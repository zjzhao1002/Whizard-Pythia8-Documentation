# Description

Here provides some scripts to install packages.
It is recommended to install them step by step, to avoid some unexpected issues.

Please install **LHAPDF6**, **HepMC2** and **FastJet3** first. 
What you need to do is giving your **INSTALL_PATH** in these scripts.

Installation of **OpenLoops** is quite simple. You may not need this script, 
but it can show you the steps clearly. 

The next step is installing **Pythia8**. Please give your paths to **LHAPDF6**, **HepMC2**, **FastJet3** and 
your **INSTALL_PATH** for Pythia8 in the **install_pythia8.sh**.

Finally, you can edit the paths to packages above in **install_whizard.sh**, and run it to install Whizard. 
In default, it is installed in the **install-3.1.4** directory.
