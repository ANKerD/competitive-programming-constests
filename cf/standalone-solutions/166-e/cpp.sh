g++ -std=c++17 -o run code.cpp -fsanitize=undefined
./run < $1  cat
echo "-------------"
cat $1x
