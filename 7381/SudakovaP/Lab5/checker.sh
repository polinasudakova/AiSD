#!/bin/bash
if [ -f "result.txt" ]; then
    rm result.txt;
fi
make
for i in $(ls tests/light_without_removal); do
    echo "running test: \"tests/light_without_removal$i\" ";
    echo "light without removal test: \"$i\"" >>result.txt;
    ./randomized_binary_search_tree <tests/light_without_removal/$i >>result.txt; 
done; 
for i in $(ls tests/light_with_removal); do 
    echo "running test: \"tests/light_with_removal$i\" ";
    echo "light with removal test: \"$i\"" >>result.txt;
    ./randomized_binary_search_tree <tests/light_with_removal/$i >>result.txt; 
done; 
for i in $(ls tests/invalid); do 
    echo "running test: \"tests/invalid$i\" ";
    echo "invalid test: \"$i\"" >>result.txt;
    ./randomized_binary_search_tree <tests/invalid/$i >>result.txt;
done;
make clean