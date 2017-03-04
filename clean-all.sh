#! /bin/bash
# Cleans build directories for each project

function clean_project {
    if [  -d $1/build/ ] 
    then
        rm -rf $1/build
    fi
}
projects=$(ls -v | grep problem)

for project in $projects 
do
    clean_project $project 
done
