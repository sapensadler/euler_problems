#!/bin/bash

function build_project {
    cd $1
    if [ ! -d build ] 
    then
        mkdir build
    fi
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
