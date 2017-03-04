#!/bin/bash
projects=$(ls -v | grep problem)

bash build-all.sh $@
bash run-all.sh $@
