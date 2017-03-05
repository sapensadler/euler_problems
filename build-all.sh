#!/bin/bash

# Build all projects

# Default to consecutive build
if [ "$1" == "--concurrent" ]
then
    CONCURRENT_BUILD=1
elif [ "$1" == "--consecutive" ]
then
    CONCURRENT_BUILD=0
else
    CONCURRENT_BUILD=0
fi

while read -r line
do
    project=$(echo $line | awk '{print $2}')

    if [ $CONCURRENT_BUILD -eq 1 ]
    then
        bash build-project.sh $project $2 > /dev/null &
    else
        bash build-project.sh $project $2 > /dev/null
    fi
done < results.txt

wait
