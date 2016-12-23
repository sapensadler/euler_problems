#!/bin/bash
projects=$(ls -v | grep problem)

function build_project {
    cd $1
    mkdir build
    if [ -e setup.sh ] 
    then
        bash ./setup.sh
    fi
    cd build 
    cmake .. > /dev/null
    make > /dev/null
    cd ../../
}

function execute_project {
    if [ ! -e $1/build/bin/$1 ] 
    then
        build_project $1
    fi 
    cd $1
    cd build 
    make >  /dev/null
    echo -n $1 ": "
    ./bin/$1
    cd ../../
}

if [ $# -ge 1 ]
then
    projects=$@
fi

for project in $projects 
do
    execute_project $project 
done
