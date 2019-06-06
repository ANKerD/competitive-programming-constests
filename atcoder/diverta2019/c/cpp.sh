g++ -std=c++11 -o run code.cpp -fsanitize=undefined -Wall
./run < $1  cat
echo "-------------"
cat $1x
