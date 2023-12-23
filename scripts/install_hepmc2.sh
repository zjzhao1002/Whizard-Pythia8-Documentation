#!/bin/bash

curl https://hepmc.web.cern.ch/hepmc/releases/hepmc2.06.11.tgz --output hepmc2.06.11.tgz
tar xvf hepmc2.06.11.tgz

INSTALL_PATH=<YOUR_HEPMC2_INSTALL_PATH>

cd HepMC-2.06.11

mkdir -p ${INSTALL_PATH}

./configure --prefix=${INSTALL_PATH} --with-momentum=GEV --with-length=MM
make
make install
