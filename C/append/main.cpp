#include <iostream>
#include <string>
#include <algorithm>
#include "append.h"

using namespace std;

int main(){
	bool checkLoop = true;
	while (checkLoop) {
		string srcFileName, appendFileName;
		while (true){
			cout << "Enter source file name: ";
			cin >> srcFileName;
			if (srcFileName == "" || !fileExist(srcFileName))
				cout << "Invalid file name.\n";
			else
				break;
		}
		while (true){
			cout << "Enter file name to append: ";
			cin >> appendFileName;
			if (appendFileName == "" || !fileExist(appendFileName))
				cout << "Invalid file name.\n";
			else
				break;
		}
		if (append(srcFileName,appendFileName)) {
			cout << "Successfully append "<<appendFileName<<" to "<<srcFileName<<endl;
		} 
		else {
			cout << "Error appending";
		}
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