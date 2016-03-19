#include <iostream>
#include "VolImage.h"
#include <fstream>
#include <string>
#include <sstream>

//Volimage Method definitions
VolImage::VolImage() {
	}
VolImage::~VolImage() {
	
	}

bool VolImage::readImages(std::string baseName){ 
	using namespace std;
	baseName += ".data";
	int noImages;
	string line;
	ifstream ifs (baseName.c_str(), ios::in|ios::binary);
	
	if(ifs.is_open()) {
		while(getline(ifs, line)){
			istringstream iss(line);
			for(int i = 0; i < 3; i++) {
				if(i == 0)iss >> width;
				if(i == 1)iss >> height;
				iss	>> noImages;
				}
		}
		
		ifs.close();
		return true;
		}
	
	return false;
	}
void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {
	
	}
void VolImage::extract(int sliceId, std::string output_prefix) {
	}
int VolImage::volImageSize(void){
	
	return 1;
	}
