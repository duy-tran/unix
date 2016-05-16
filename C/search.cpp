#include <iostream>
#include <fstream>
#include <sys/types.h> 
#include <sys/stat.h>
#include <dirent.h> 
#include <string>
#include <cstdlib> 
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

bool fileExist(string fullPathFileName){
	ifstream fileAvailable(fullPathFileName.c_str());
  	return fileAvailable;
}

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

int main() {
	bool checkLoop = true;
	while (checkLoop) {
		DIR *dir;
		string searchingDir, keyword, destDir;
		while (true) {
			cout<<"Enter searching directory: ";
			cin>>searchingDir;
			dir = opendir(searchingDir.c_str());
			if (dir) {
				break;
			} else {
				cout <<"Folder invalid, please enter again.\n";
			}
		}
		while (true) {
	    	cout<<"Enter keyword: ";
	    	cin>>keyword;
	    	if (keyword == "") {
	    		cout << "Please enter a keyword.\n";
	    	}
	    	else {
	    		break;
	    	}
		}
	    while (true) {
	    	cout<<"Enter destination directory: ";
	    	cin>>destDir;
	    	if (destDir == "") {
	    		cout << "Please enter a directory.\n"; }
	    	else {
	    		DIR *checkDir = opendir(destDir.c_str());
	    		if (!checkDir){ // Directory not exist
		    		int createStatus = mkdir(destDir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		    		if (createStatus == -1 ){ // Error creating
		    			cout << "Please enter a valid directory.\n"; 
		    		}
		    		else {
		    			cout << "Folder "<< destDir <<" not found, created a new folder\n";
		    			break; 
		    		}
	    		} 
	    		else {
	    			break;
	    		}
	    	}
		}
	    string fileName;
	    struct dirent *ent; 
	    bool findSuccess = false;
	    // Read file and folder in *dir, one by one until NULL
	    while((ent = readdir(dir)) != NULL) { 
	        fileName=ent->d_name;	        
	        if (fileName.find(keyword) != string::npos) {
	            cout<<"Found file "<<fileName;
	            copy(searchingDir,destDir,fileName);
	            findSuccess = true;
	        }
	    } 
	    if (!findSuccess) {
	    	cout<<"Can't find "<<keyword<<" in "<<searchingDir<<endl;
	    }
	    closedir(dir);
	    while (true) {
	    	string confirmContinue;
	    	cout << "Do you want to continue? ";
	    	cin >> confirmContinue;
	    	transform(confirmContinue.begin(), confirmContinue.end(), confirmContinue.begin(), ::tolower);
	    	if ( confirmContinue == "y" || confirmContinue == "yes" ) {
	    		break;
	    	}
	    	else {
	    		if ( confirmContinue == "n" || confirmContinue == "no" ) {
	    			checkLoop = false;
	    			break;
	    		}
	    		else {
	    			cout << "Please enter a valid value (Y/N/Yes/No)\n";
	    		}
	    	}	        
	    }
	}
    return 0; 
} 