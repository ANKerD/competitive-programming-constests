g++ -std=c++17 -Wall -fsanitize=undefined -o run code.cpp
./run < $1  cat
echo "-------------"
cat $1x
