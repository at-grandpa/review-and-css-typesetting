#!/usr/bin/env sh

URL=$1

for i in `seq -w 10`
do
    STATUS=`curl -s ${URL} -o /dev/null -w '%{http_code}'`
    if [ $STATUS = '200' ]
    then
    	echo "[ok] status:${STATUS} ${URL}"
        exit 0
    fi
    echo "[${i}] status:${STATUS} ${URL}"
	sleep 1
done

exit 1
