#include "copy.h"
#include <iostream>
#include <fstream>
#include "generateFileName.h"

bool fileExist(string fullPathDestFile){
	ifstream fileAvailable(fullPathDestFile.c_str());
  	return fileAvailable;
}

void copy(string searchingDir, string destDir, string fileName){
	string fullPathSrcFile = searchingDir + "/" + fileName;
    string fullPathDestFile = destDir + "/" + fileName;
    ifstream src(fullPathSrcFile.c_str()); 
    if (fileExist(fullPathDestFile)) {
    	fullPathDestFile = destDir + "/" + getNewName(destDir,fileName);
    }
    ofstream dst(fullPathDestFile.c_str());
	dst << src.rdbuf();
	cout<< ", copied to "<<fullPathDestFile<<endl;
}