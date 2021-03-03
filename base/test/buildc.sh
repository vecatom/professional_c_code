
echo "clear $1"

rm -rf obj/$1.o

rm -rf bin/$1

echo " build c program ！"
gcc -c src/$1.c -o obj/$1.o
echo "link c program ! "
gcc obj/$1.o -o bin/$1

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
