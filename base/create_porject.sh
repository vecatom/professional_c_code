#!/bin/bash


echo "create project $1 boot dir.."

mkdir $1

cd $1

echo "create project $1/src dir..."
mkdir src
echo "create project $1/inc dir..."

mkdir inc
echo "create project $1/obj dir..."
mkdir obj
echo "create project $1/bin dir..."
mkdir bin

echo "create dir stuct success!"
