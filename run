echo "Executing $1"

g++ -std=c++17 -o out_tmp.o $1

if [ $? -eq 0 ]
then
    ./out_tmp.o
    rm ./out_tmp.o
else
    echo "Error"
fi