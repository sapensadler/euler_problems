#1/bin/bash

function execute_project {
    if [ ! -e $1/build/bin/$1 ] 
    then
	echo Building $1
        bash build-project.sh $1
	echo Build of $1 complete
    fi 
    cd $1
    cd build 
    # Re-compile any code updates
    make >  /dev/null
    echo -en Running $1 '\t:\t '
    ./bin/$1
    cd ../../
}

execute_project $1
