# Description
**NLO_eebbmumu_OpenLoops.sin** is an example file to generate 4 jets events at e+e- collider. If you install Whizard with OpenLoops interface successfully, you can run
```
whizard NLO_ee4j_OpenLoops.sin
```
to generate events. The process library **ppllll** is needed.

The basic usage of NLO mode can be found in the **eeqq_nlo/README.md** file. Some comments for this process are:
* **$restrictions = "3+4~H && 5+6~Z"** has been commented out because it does not work for select diagram.
* To select the contribution of ZH, we implement two cuts: **85 GeV < M < 95 GeV [e2, E2]** and **110 GeV < M < 140 GeV [collect[bjet]]**.
* **alias bjet = b:B:gl** is necessary because we should have p(b)+p(B)+p(gl)=p(H) in the real component.
* **?resonance_history = true** and **$fks_mapping_type = "resonances"** can switch the subtraction method to the resonance-aware FKS subctraction.
  With this option, Whizard tends to generate phase space points in the reasonant regions, so the integration can be speeded up.
  However, some errors occur if we generate events with this option, so they are commented out.
