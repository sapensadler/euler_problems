#!/bin/bash

projects=$(ls -v | grep problem)

if [ "$1" == "--concurrent" ]
then
    CONCURRENT=1
else
    CONCURRENT=0
fi

if [ $CONCURRENT -eq 1 ]
then
    i=0
    for project in $projects 
    do
        output[$i]=$(mktemp euler.XXXX)
        bash run-project.sh $project > ${output[$i]} &
        i=$((i+1))
    done
    wait
    i=0
    for file in ${output[@]}
    do
        cat $file
        rm $file
    done
else
    for project in $projects 
    do
        bash run-project.sh $project
    done
fi

