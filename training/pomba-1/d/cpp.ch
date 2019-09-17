rm run 
g++ code.cpp -o run -Wall -O2 -fsanitize=undefined -std=c++11
./run < $1 | cat
echo "-----------"
cat $1x
