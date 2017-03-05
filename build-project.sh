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
    echo Building $1 with arguments $2 1>&2
    cmake $2 .. 
    make 
}

build_project $1 $2
