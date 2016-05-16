#include "append.h"
#include <iostream>
#include <string>
#include <fstream>

bool fileExist(string fullPathFileName){
	ifstream fileAvailable(fullPathFileName.c_str());
  	return fileAvailable;
}

bool append(string srcFileName, string appendFileName){
	ofstream srcFile;
	srcFile.open(srcFileName.c_str(), ios_base::app);
	if (!srcFile.is_open()) {
		cout << "Can't open "<<srcFileName<<endl;
		return false;
	}
	ifstream appendFile;
	string eachLine;
	appendFile.open(appendFileName.c_str());
	if (!appendFile.is_open()) {
		cout << "Can't open "<<appendFileName<<endl;
		return false;
	}
	else {
		while (getline(appendFile, eachLine)) {
			srcFile << eachLine<<endl;
		}
		appendFile.close();
	}
	srcFile.close();
	return true;
}