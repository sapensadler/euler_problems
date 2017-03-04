#!/bin/bash

# Build all projects
bash build-all.sh $@
tmp_file=$(mktemp)
bash run-all.sh $@ > $tmp_file


# Run the projects and check results

paste -d " " results.txt $tmp_file | while read -r line
do
    project=$(echo $line | awk '{print $2}')
    correct_result=$(echo $line | awk '{print $4}')
    result=$(echo $line | awk '{print $8}')
    if [ "$result" == "$correct_result" ]
    then
        echo -e "\e[32mPASS $project \e[39mexpected: '$correct_result' actual: '$result'"
    else
        echo -e "\e[31mFAIL $project \e[39mexpected: $correct_result actual: $result"
    fi
done 

rm $tmp_file
