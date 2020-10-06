#include <iostream>
#include <fstream>
#include <string>
#include "matrix.h"

int main (int argc, char* argv[]){
	sMatrix cat=CSVmatrixparse(argv[1]);
	sMatrix list=CSVmatrixparse(argv[2]);
	std::string name=argv[2];
	name = name+"dl";
	sMatrix key=CSVmatrixparse(argv[3]);
	sMatrix down;
	for(int a=0;a<cat.matrix.size();a++){
		for(int b=0;b<key.matrix.size();b++){
			std::size_t find=cat.matrix[a].find(key.matrix[b]);
			if(find !=std::string::npos){
				down.matrix.push_back(list.matrix[a]);

			}
	/*
	*/
		}
	}
	CSVmatrixwrite(down,name);
}
