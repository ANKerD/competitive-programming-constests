rm run
g++ -std=c++14 -o run code.cpp -Wall -fsanitize=undefined
./run < $1  cat
echo "-------------"
cat $1x
