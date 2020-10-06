#include <iostream>
#include <fstream>
#include <string>
int main (int argc, char* argv[]){
	if (argc < 2){
		std::cerr << "Usage:" << argv[0] << " filename" <<std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::ifstream file(filename);
	if (file.is_open()){
		std::ofstream threads;
		std::ofstream threadslist;
		threads.open(filename+".csv");
		threadslist.open(filename+"list");
		char c;
		int a=0;
		bool t=false;
		bool s=false;
		std::string out;
		std::string ssub;
		std::string tteaser;
		std::string ds;
		std::string ts;
		std::string ls;
		while (file.get(c)){
			if(c!='"'){
				ds=ds+c;
				ls=ls+c;
				if(c==','){
					ls="";
					ds="";
				}
				if(c==':'){
					ds="";
				}
				if(ds=="{date"){
					threadslist<< ls.substr(0,ls.find(":"))+'\n';
				}
			}
			if(c!=':'){
			if (s == true && a%2 ==0 && c=='"'){
				ssub = ssub+c;
			}
			if (s == true && a%2 !=0) {
				ssub = ssub+c;

			}
			if(s==true && a%2 !=0 && c=='"'){
				out = out+ssub;
				ssub="";
				s= false;
			}
			if (t == true && a%2 ==0 && c=='"'){
				tteaser = tteaser+c;
			}
			if (t == true && a%2 !=0) {
				tteaser = tteaser+c;

			}
			if(t==true && a%2 !=0 && c=='"'){
				out = out+tteaser+'\n';
				tteaser="";
				t= false;
				threads << out;
				out ="";
			}
			if(a % 2!= 0 )
			{
				if(ts =="sub"){
						s=true;
				}
				if(ts =="teaser"){
						t=true;
				}
				ts = ts+c; 

			}
			else{
				ts="";
			}
			if(c=='"'){
				a=a+1;
			}
			}

		}
		file.close();
		threads.close();
		threadslist.close();
	}
	else{
	return 0;
	}
}
