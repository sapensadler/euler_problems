#!/bin/bash
projects=$(ls -v | grep problem)

if [ $# -ge 1 ]
then
    projects=$@
fi

for project in $projects 
do
    bash run-project.sh $project 
done
