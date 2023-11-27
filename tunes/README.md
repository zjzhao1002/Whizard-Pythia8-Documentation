# Description
**lep1.sin** is an example sindarin file to run Whizard interface with Pythia8. If you have linked Pythia8 to Whizard correctly, you can run 
```
whizard lep1.sin
```
to generate events.

The most important commands in this file are 
```
?ps_fsr_active = true
?hadronization_active = true
$shower_method = "PYTHIA8"
$hadronization_method = "PYTHIA8"
```
This means that we activate the final state radiation, and the parton shower and hadronization are performed by Pythia8. 

The configurations of Pythia8 are done by the flag
```
$ps_PYTHIA8_config_file = "<config-file-name>"
```
In this example, I provide two configuration files with OPAL tune and ALEPH tune. If you just want to modify a few parameters, you can also use this flag
```
$ps_PYTHIA8_config = "[option1]; [option2]"
```
