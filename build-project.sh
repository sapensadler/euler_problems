#!/bin/bash

function build_project {
    cd $1
    mkdir build
    if [ -e setup.sh ] 
    then
        bash ./setup.sh
    fi
    cd build 
    cmake .. 
    make 
    cd ../../
}

build_project $1
