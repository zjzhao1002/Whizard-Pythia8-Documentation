# Description
**NLO_ee4j_OpenLoops.sin** is an example file to generate 4 jets events at e+e- collider. If you install Whizard with OpenLoops interface successfully, you can run
```
whizard NLO_ee4j_OpenLoops.sin
```
to generate events. The process library **pplljj** is needed.

The basic usage of NLO mode can be found in the **eeqq_nlo/README.md** file. Some comments for this process are:
* Born process e+e- -> 4j is not infrared safe, you need to apply a clustering algorithm, that is infrared-safe for both 4- and 5-jet topologies. In this example, we did a jet selection with Pt>30 GeV, |eta| < 4 for the jets.
* OpenLoops only provides process with **alpha_power=2** and **alphas_power=2**, so we have to exclude the diagrams with W exchange.
* **$method="openloops"** is needed to calculate color- and spin-correlated matrix elements, but the color flows are not written into the output LHE file in this case.
