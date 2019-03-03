g++ -std=c++17 -o ex code.cpp
./ex < $1 | cat
echo "------------"
cat $1x
echo ""
