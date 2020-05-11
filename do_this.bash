#! /bin/bash -f

rm -rf  *.exe *.out

gcc -o normal-opt.exe p63.c 
./normal-opt.exe

gcc -o o5.exe -O5 p63.c 
./o5.exe
