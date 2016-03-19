#include <iostream>
#include <string>
#include <sstream>
#include "VolImage.h"

int main(int argc, char* argv[]) {
	std::string imageBase = argv[1];
	VolImage vImage;
	bool flag = vImage.readImages(imageBase);
	
	if (flag) {	
		if(argc == 5) {
			std::cout << "Extract Image" << std::endl;	
			int idxSlice;
			std::istringstream (argv[3]) >> idxSlice;		
			std::cout << idxSlice << std::endl;
			
		}
		else if (argc == 6) {
			std::cout << "Compute Difference Map" << std::endl;	 		
	}
	else {
		std::cout << "Build internal representation" << std::endl;
		
		}
	}
	else {
		std::cerr << "Prefix for file sequence returned error!" << std::endl; 
		
		}
return 0;
}
