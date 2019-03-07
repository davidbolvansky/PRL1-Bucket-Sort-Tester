#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

if [ -z "$1" ]
then
    start=1
else
    start=$1
fi

if [ -z "$2" ]
then
    end=256
else
    end=$2
fi

g++ -std=c++11 -O3 tester.cpp -o tester
for i in `seq $start $end`;
do
    # test.sh must compile your code and remove compiled binary
    # and numbers file!
    bash test.sh $i &> out
    ./tester &> ref
    diff out ref
    if [ "$?" == "0" ]
    then
      echo -e "[n = $i] ${GREEN}OK${NC}"
    else
      echo -e "[n = $i] ${RED}BAD${NC}"

    rm out ref
  fi

done