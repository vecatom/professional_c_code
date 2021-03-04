#!/bin/bash


echo "clear...."


rm -rf obj/*.o

rm -rf bin/*


echo "build ..."

gcc -c src/main.c -o obj/main.o
gcc obj/main.o -o bin/main


echo "build success ..."


echo "run   bin/main  "
bin/main

echo "run   bin/main 2 2"
bin/main 2 2

echo "run    bin/main 2 1"
bin/main 2 1
