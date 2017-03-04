#1/bin/bash

function execute_project {
    echo -en Running $1 '\t:\t '
    cd $1

    if [ ! -e "build/bin/$1" ]
    then
        echo "Project file $1 not built. Please build the project first."
    else
        ./build/bin/$1
    fi
        
}

execute_project $1
