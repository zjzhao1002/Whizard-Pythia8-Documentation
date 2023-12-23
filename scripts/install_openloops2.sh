#!/bin/bash

git clone https://gitlab.com/openloops/OpenLoops.git

cd OpenLoops
./scons

./openloops libinstall eett
./openloops libinstall ppllj
./openloops libinstall tbw
