#include "count.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool fileExist (string fullPathFileName) {
	ifstream fileAvailable(fullPathFileName.c_str());
  	return fileAvailable.is_open();
}

// bool validWord(string word){
// 	string validForm = "?[A-Za-z]+";
// 	return (regex_match (word, regex(validForm) )) ? true : false;
// }

int countWord (string fileName) {	
	ifstream srcFile(fileName.c_str());
	if (!srcFile.is_open()){
		cout << "Can't open "<<fileName<<endl;
		return -1;
	}
	else {
		int count=0;
		string word;
		while ( srcFile >> word ) {
			count++;
		}
		return count;
	}
}