#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
class sMatrix{
	public:
		std::vector<std::string> matrix;
};

// CSV tools
sMatrix CSVmatrixparse(std::string filename){
	std::ifstream ifile;
	ifile.open(filename);
	if (ifile.is_open())
	{
		std::string line;
		sMatrix matrix;
		while (getline(ifile, line)){
			matrix.matrix.push_back(line);

		}
		return matrix;
	}
	else{
		std::cout << "Error: File could not be opened" << std::endl;
	}
}
void CSVmatrixwrite(sMatrix mat, std::string filename)
{
	std::ofstream offile(filename);
	std::string Mat;
	for (int k = 0; k<mat.matrix.size();k++){
		Mat =Mat + mat.matrix[k]+'\n';
	}
	offile << Mat;
	offile.close();
}
