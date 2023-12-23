#!/bin/bash

curl https://lhapdf.hepforge.org/downloads/?f=LHAPDF-6.5.4.tar.gz --output LHAPDF-6.5.4.tar.gz

tar xvf LHAPDF-6.5.4.tar.gz

cd LHAPDF-6.5.4

INSTALL_PATH=<YOUR_LHAPDF_INSTALL_PATH>
PDFSETS_PATH=${INSTALL_PATH}/share/LHAPDF

mkdir -p ${INSTALL_PATH}

./configure --prefix=${INSTALL_PATH} PYTHON_VERSION=3
make
make install

####### Download PDF sets ##########
cd ${PDFSETS_PATH}

curl https://lhapdfsets.web.cern.ch/current/cteq6l1.tar.gz --output cteq6l1.tar.gz
tar xvf cteq6l1.tar.gz

curl https://lhapdfsets.web.cern.ch/current/CT10.tar.gz --output CT10.tar.gz
tar xvf CT10.tar.gz

curl https://lhapdfsets.web.cern.ch/current/NNPDF23_lo_as_0130_qed.tar.gz --output NNPDF23_lo_as_0130_qed.tar.gz
tar xvf NNPDF23_lo_as_0130_qed.tar.gz

curl https://lhapdfsets.web.cern.ch/current/NNPDF23_nlo_as_0118.tar.gz --output NNPDF23_nlo_as_0118.tar.gz
tar xvf NNPDF23_nlo_as_0118.tar.gz
