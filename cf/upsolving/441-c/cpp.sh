g++ -std=c++11 -o run code.cpp -Wall -O2 -fsanitize=undefined
./run < $1  cat
echo "-------------"
cat $1x
