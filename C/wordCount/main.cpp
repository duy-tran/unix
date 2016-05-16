#include <string>
#include <iostream>
#include <algorithm>
#include "count.h"

using namespace std;

int main() {
	bool checkLoop = true;
	while (checkLoop) {	
	string fileName;
	while (true){
		cout <<"Enter file name: ";
		cin >> fileName;
		if (fileName == "" || !fileExist(fileName))
			cout << "Invalid file name.\n";
		else
			break;
	}
	if (countWord(fileName) != -1)
		cout << "File "<<fileName<<" has "<<countWord(fileName)<<" words\n";
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