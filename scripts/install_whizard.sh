#!/bin/bash

curl -O https://whizard.hepforge.org/downloads/?f=whizard-3.1.4.tar.gz
tar xvf whizard-3.1.4.tar.gz

WHIZARD_PATH=${PWD}/whizard-3.1.4
BUILD_PATH=${PWD}/build-3.1.4
INSTALL_PATH=${PWD}/install-3.1.4

LHAPDF_PATH=<YOUR_LHAPDF6_INSTALL_PATH>
HEPMC_PATH=<YOUR_HEPMC2_INSTALL_PATH>
FASTJET_PATH=<YOUR_FASTJET_INSTALL_PATH>
PYTHIA8_PATH=<YOUR_PYTHIA8_INSTALL_PATH>
OPENLOOPS_PATH=<YOUR_OPENLOOPS2_INSTALL_PATH>

export PATH="$PATH:${LHAPDF_PATH}/bin:${HEPMC_PATH}/bin:${FASTJET_PATH}/bin:${PYTHIA8_PATH}/bin"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:${LHAPDF_PATH}/lib:${FASTJET_PATH}/lib:${HEPMC_PATH}/lib:${PYTHIA8_PATH}/lib:${OPENLOOPS_PATH}/lib"
export HEPMC_DIR=${HEPMC_PATH}
export LHAPDF_DIR=${LHAPDF_PATH}

mkdir -p ${BUILD_PATH}
mkdir -p ${INSTALL_PATH}

cd ${BUILD_PATH}

${WHIZARD_PATH}/configure --prefix=${INSTALL_PATH} --enable-lhapdf --with-lhapdf=${LHAPDF_PATH} --enable-hepmc --with-hepmc=${HEPMC_PATH} --enable-fastjet --with-fastjet=${FASTJET_PATH} --enable-pythia8 --with-pythia8=${PYTHIA8_PATH} --enable-openloops --with-openloops=${OPENLOOPS_PATH} CXX="g++" CXXFLAGS="-std=c++11 -pthread"

make

make install 
