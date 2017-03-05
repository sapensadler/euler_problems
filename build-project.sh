#!/bin/bash

# Builds project using cmake using command line arguments for the project name

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
    cmake $2 .. 
    make 
}

build_project $1 $2
