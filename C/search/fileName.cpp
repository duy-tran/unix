#include "fileName.h"
#include <cstdlib>
#include <string>

string getFileName(string file){
	int mark = file.find_last_of(".");
	return file.substr(0,mark);
}

string getFileType(string file){
	int mark = file.find_last_of(".");
	return file.substr(mark+1);
}

int getNumberFromFileName(string fileName){
	int mark = fileName.find_last_of("]");
    string temp = fileName.substr(0,mark);
    mark = temp.find_last_of("[");
    temp = temp.substr(mark+1);
    return atoi(temp.c_str());
}