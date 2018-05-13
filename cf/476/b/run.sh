g++ -o run $1
# cat out$2.txt
./run < inp$2.txt | cat
echo "----"
# cat expect$2.txt
# diff out$2.txt expect$2.txt
