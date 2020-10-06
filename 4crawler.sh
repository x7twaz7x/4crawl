#!/bin/bash
board=$1
mkdir $board
wget https://boards.4chan.org/$board/catalog -O $board/catalog &&
./cut $board/catalog
./search $board/catalog.csv $board/cataloglist $board/keywords
./4dump.sh cataloglistdl $board
