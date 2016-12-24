#!/bin/bash
while read -r line
do
    project=$(echo $line | awk '{print $2}')
    bash build-project.sh $project > /dev/null
    correct_result=$(echo $line | awk '{print $4}')
    result=$(bash run-project.sh $project | awk '{print $4}')
    if [ $result -eq $correct_result ]
    then
        echo PASS $project expected: $correct_result actual: $result
    else
        echo FAIL $project expected: $correct_result actual: $result
    fi
done < results.txt

