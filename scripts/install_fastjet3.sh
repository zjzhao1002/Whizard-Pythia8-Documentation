#!/bin/bash

curl -O http://fastjet.fr/repo/fastjet-3.4.2.tar.gz
tar zxvf fastjet-3.4.2.tar.gz

cd fastjet-3.4.2/

INSTALL_PATH=<YOUR_FASTJET3_INSTALL_PATH>

mkdir -p ${INSTALL_PATH}

./configure --prefix=${INSTALL_PATH}
make
make install
