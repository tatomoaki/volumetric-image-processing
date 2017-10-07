#include <iostream>
#include "VolImage.h"
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
//Volimage Method definitions
VolImage::VolImage() {
	}
VolImage::~VolImage() {
	for(unsigned int i = 0; i < slices.size(); i++) {
		for(int j = 0; j < height; j++) {
			delete[] slices[i][j];			
			}
			delete []slices[i];	
		}
		//std::cout << "Destructor called" << std::endl;	
	}

bool VolImage::readImages(std::string baseName){ 
	using namespace std;
	string *file_name = &baseName;	
	//streampos size;
	//int noImages;
	string line;
	unsigned char **array = NULL;
	ifstream ifs ((baseName+".data").c_str(), ios::in);
	
	if(ifs.is_open()) {
		while(getline(ifs, line)){
			istringstream iss(line);			
				iss >> width;
				iss >> height;
				iss	>> noImages;				
		ifs.close();	
		}				
		for (int i = 0; i < noImages; ++i) {
			
			ostringstream ss;
			ss << i;
			string file_ = *(file_name) + ss.str() + ".raw";
			//cout << file_ << endl;
			ifstream rfs(file_.c_str(), ios::in|ios::binary);
			
			if(rfs.is_open()) {
					array = new unsigned char*[height];	
					/**			
					for(int i = 0; i < height; i++) {
						array[i] = new unsigned char[width];						
 					}**/
 					unsigned char* array_;
 					//rfs.seekg(0, ios::beg); 					
 					for (int i = 0;i < height; i++) {
						array_ = new unsigned char[width];
						//rfs.read((unsigned char*)(&array[i),width);
						//rfs.read(reinterpret_cast<char*>array[i]), width);
						rfs.read((char*)array_, width);	
						array[i] = array_;					
					}
 					slices.push_back(array);
					rfs.close();				
				}							
			}
			//cout << slices.size();
			return true;				
		}
	cerr << "Header File not opened" << endl;
	return false;
}
void VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix) {
	using namespace std;
	string file = output_prefix+".raw";
	ofstream ofs(file.c_str(), ios::out|ios::binary);
	if(ofs.is_open()) {
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
				char diff = abs(((float)slices[sliceI][i][j]- (float)slices[sliceJ][i][j])/2);
				ofs.write(&diff, 1);	
							
			}		
		}
		}
	
	}
void VolImage::extract(int sliceId, std::string output_prefix) {
	using namespace std;
	
	string file = output_prefix+".raw";
	ofstream ofs ((output_prefix+".data").c_str(), ios::out); 
	if(ofs.is_open()) {
		ofs << width << " " << height << " 1" << endl; 
		ofs.close();
	}
	ofstream raws((file).c_str(), ios::out|ios::binary);
	if (raws.is_open()){
	for(int i = 0; i < height; i++) {
		char* raw = (char*)slices[sliceId][i];
		raws.write(raw,width);			
		}
		raws.close();
	}
		
	}
void VolImage::extract_along_row(int sliceId, std::string output_prefix){
	using namespace std;
	
	string file = output_prefix+".raw";
	ofstream ofs ((output_prefix+".data").c_str(), ios::out); 
	if(ofs.is_open()) {
		ofs << width << " " << height << " 1" << endl; 
		ofs.close();
	}
	ofstream raws((file).c_str(), ios::out|ios::binary);
	if (raws.is_open()){
	for(unsigned int i = 0; i < slices.size(); i++) {
		char* raw = (char*)slices[i][sliceId];
		raws.write(raw,width);			
		}
		raws.close();
	}
	
	
	
	}
	
int VolImage::volImageSize(void){
	return noImages* height*(sizeof(unsigned char**)+ width);
	
	}
