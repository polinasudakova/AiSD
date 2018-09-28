#!/bin/bash
g++ ./Source/lab1.cpp -o lab1.exe
echo 'Test 1'
echo 'Input data:'
cat Tests/test1.txt
echo 'Output data:'
./lab1.exe < ./Tests/test1.txt
echo ''
echo 'Test 2'
echo 'Input data:'
cat Tests/test2.txt
echo 'Output data:'
./lab1.exe < ./Tests/test2.txt
echo ''
echo 'Test 3'
echo 'Input data:'
cat Tests/test3.txt
echo 'Output data:'
./lab1.exe < ./Tests/test3.txt
echo ''
echo 'Test 4'
echo 'Input data:'
cat Tests/test4.txt
echo 'Output data:'
./lab1.exe < ./Tests/test4.txt
echo ''
echo 'Test 5'
echo 'Input data:'
cat Tests/test5.txt
echo 'Output data:'
./lab1.exe < ./Tests/test5.txt