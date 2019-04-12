#!/bin/sh
# set -x
NUM=1

while [ $NUM -lt 256  ];do 
    ping -q -c 1 10.70.3.$NUM > /dev/null 
    RESULT=$(echo $?)
    if [ $RESULT -eq 0 ]; then 
        printf 10.70.3.$NUM"\n"
    fi
    NUM=$(expr $NUM + 1)
done
