g++ -std=c++11 -o run code-2.cpp
g++ -std=c++11 -o run2 code.cpp
./run < $1 | cat
echo "-------------"
./run2 < $1 | cat
