
echo "clear ..."

rm -rf obj/*.o
rm -rf bin/*

echo "clean success! "

echo " build c program ！"
gcc -c -Iinc  src/main.c -o obj/main.o
gcc -c -Iinc  src/param.c -o obj/param.o
echo "link c program ! "
gcc obj/param.o obj/main.o -o bin/main

echo "bgin run test"
echo "run bin/$1.."
bin/$1
echo $?

echo "run bin/$1 1 2  ..."
bin/$1 1 2
echo $?

echo "run bin/$1 1 2 3 ..."
bin/$1 1 2 3
echo $?


echo "run bin/$1 1 2 3 r ..."
bin/$1 1 2 3 r
echo $?
