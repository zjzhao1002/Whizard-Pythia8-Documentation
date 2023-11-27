# Description
**NLO_eeqq_OpenLoops.sin** is an example file to generate qqbar events at e+e- collider. If you install Whizard with OpenLoops interface successfully, you can run
```
whizard NLO_eeqq_OpenLoops.sin
```
to generate events.

Whizard do not provide one-loop matrix elements, you have to specify the one-loop provider by 
```
$loop_me_method = "openloops"
```
The other options are GoSam and Recola, but they are not well tested. 

The electroweak coupling powers and strong coupling powers at tree-level must be fixed by
```
alpha_power
alphas_power
```
Setting these values is necessary for the correct generation of OLP-files. 
Having inconsistent values yields to error messages by the corresponding OLP-providers.

To perform NLO calculation, you have to add
```
{nlo_calculation = full}
```
after the process. This means the full NLO calculation, but you can replace **full** with **born**, **virtual**, **real**, or **dglap** to the component you are interested in.

The following flags are needed to generate POWHEG events:
```
?fixed_order_nlo_events = false
?combined_nlo_integration = true
?negative_weights = true
?powheg_matching = true
```
These events can be written to a LHE file, and this file can be an input to run Pythia8.
