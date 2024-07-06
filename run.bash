#!/bin/bash
set -e
g++ -Wall -g main.cpp -o main
./main $*