#include "generateFileName.h"
#include "fileName.h"
#include <string>
#include <sys/types.h> 
#include <sys/stat.h>
#include <dirent.h> 
#include <sstream>

int getNumberOldFile(string destDir, string file){
	int maxOrder=0, order=0;
	string foundFile, temp, initFileName;
	string nameOfFile = getFileName(file);
	string typeOfFile = getFileType(file);
	DIR *dir = opendir(destDir.c_str());
	struct dirent *ent; 
	// Search the dest folder and make sure we find the right file
	while((ent = readdir(dir)) != NULL) { 
        foundFile=ent->d_name;
        if (getFileName(foundFile).find(nameOfFile) != string::npos && getFileType(foundFile) == typeOfFile) { 
        	int mark = foundFile.find_last_of("[");
        	initFileName = getFileName(foundFile).substr(0,mark);
        	if (initFileName == nameOfFile){
           		order =  getNumberFromFileName(foundFile);
        		if (order > maxOrder)
        			maxOrder = order;
        	}
        }
    } 
    closedir(dir);
    return maxOrder;
}

string getNewName(string destDir, string file){
	int order=getNumberOldFile(destDir,file)+1;
	ostringstream convert;   
	convert << order;
	string orderInString = convert.str();
	return getFileName(file)+"["+orderInString+"]."+getFileType(file);
}