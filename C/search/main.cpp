#include <iostream>
#include <fstream>
#include <sys/types.h> 
#include <sys/stat.h>
#include <dirent.h> 
#include <string>
#include <cctype>
#include <algorithm>
#include "copy.h"

using namespace std;

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