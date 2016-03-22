#include <iostream>
#include <string>
#include <sstream>
#include "VolImage.h"

int main(int argc, char* argv[]) {
	using namespace std;
	std::string imageBase = argv[1];
	VolImage voliImage;						//VoliImage Object
	bool flag = voliImage.readImages(imageBase);	
	
	if (flag) {	
		//Extract Image	
		if(argc == 5) {	
			if(string(argv[2]).compare("-x") == 0) {		
			int idxSlice;
			std::istringstream (argv[3]) >> idxSlice;
			string output_file_name = argv[4];					
			voliImage.extract(idxSlice, output_file_name);
			}
			else if (string(argv[2]).compare("-g") == 0) {
			int idxSlice;
			std::istringstream (argv[3]) >> idxSlice;
			string output_file_name = argv[4];					
			voliImage.extract_along_row(idxSlice, output_file_name);
				
			}
		}
		//Compute Difference Map
		else if (argc == 6) {
			int i, j;
			std::istringstream (argv[3]) >> i;
			std::istringstream (argv[4]) >> j;
			string output_file_name = argv[5];
			voliImage.diffmap(i, j, output_file_name); 		
	}
	else {
		//Output when no flags i.e ./volimage ./raws/MRI
		std::cout << "Number of images: (int): " << voliImage.noImages << std::endl;
		std::cout << "Number of bytes required: (int) " << voliImage.volImageSize() << std::endl;
		
		}
	}
	else {
		std::cerr << "Prefix for file sequence returned error!" << std::endl; 		
		}
return 0;
}
