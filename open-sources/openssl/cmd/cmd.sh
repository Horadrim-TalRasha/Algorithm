#!/bin/sh

openssl genrsa -out test.key 1024
openssl rsa -in test.key -pubout -out test_pub.key
openssl rsautl -encrypt -in test -inkey test_pub.key -pubin -out test.en 
openssl rsautl -decrypt -in test.en -inkey test.key -out test.de
