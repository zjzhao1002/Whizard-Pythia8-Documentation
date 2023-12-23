#!/bin/bash

curl -O https://pythia.org/download/pythia83/pythia8309.tgz
tar xvf pythia8309.tgz

cd pythia8309

HEPMC2_PATH=<YOUR_HEPMC2_INSTALL_PATH>
LHAPDF6_PATH=<YOUR_LHAPDF6_INSTALL_PATH>
FASTJET3_PATH=<YOUR_FASTJET3_INSTALL_PATH>

INSTALL_PATH=<YOUR_PYTHIA8_INSTALL_PATH>

mkdir -p ${INSTALL_PATH}

./configure --prefix=${INSTALL_PATH} --with-hepmc2=${HEPMC2_PATH} --with-lhapdf6=${LHAPDF6_PATH} --with-fastjet3=${FASTJET3_PATH}
