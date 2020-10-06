A very simple 4chan crawler. For a specific board, it looks for keywords specified in the keywords file for that board, parses the boards catalog, finds threads whose OPs title or text contains those keywords and downloads all of the images in that thread. 

Requirements:
gcc
wget
bash

Installation:
git clone https://github.com/x7twaz7x/4crawl
cd 4crawl
make

Usage:
1. Make a directory with the name of the board you wish to crawl. 
2. Add a file named keywords with no extension. This contains the phrases you wish to search for. Each phrase is the exact string. The keywords are case sensitive. See examples for /diy/ and /w/ boards. 
3. Run ./4crawler.sh <name of the board>. For example ./4crawler.sh diy or ./4crawler.sh w
