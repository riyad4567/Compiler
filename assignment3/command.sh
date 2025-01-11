#!/bin/bash

yacc -d -y 2005053.y
g++ -w -c -o y.o y.tab.c
flex 2005053.l
#g++ -fpermissive -w -c -o l.o lex.yy.c
g++ -w -c -o l.o lex.yy.c
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
g++ y.o l.o -lfl -o out
./out input.c
