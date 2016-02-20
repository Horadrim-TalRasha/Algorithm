#!/bin/sh

g++ -g sha256.cpp -lcrypto -o sha256.out
gcc -g md5.c -lcrypto -o md5.out
gcc -g sha1.c -lcrypto -o sha1.out
gcc -g des.c -lcrypto -o des.out
