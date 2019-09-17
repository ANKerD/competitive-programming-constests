rm run
g++ -std=c++17 -o run code.cpp -Wall -fsanitize=undefined -O2
./run < $1  cat
echo "-------------"
cat $1x
