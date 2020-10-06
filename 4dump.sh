#!/bin/bash 
filename=$1
bboard=$2
cd $bboard
while read line; do
	thread=https://boards.4chan.org/$bboard/thread/$line 
	wget -P ./$line -nd -r -l 1 -H -D i.4cdn.org,is2.4chan.org -A png,gif,jpg,jpeg,webm $thread && rm ./$line/*s.*
	wget $thread
done < $filename
