#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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

int main(){
	string srcFileName, appendFileName;
	while (true){
		cout << "Enter source file name: ";
		cin >> srcFileName;
		if (srcFileName == "" || !fileExist(srcFileName))
			cout << "Invalid file name.";
		else
			break;
	}
	while (true){
		cout << "Enter file name to append: ";
		cin >> appendFileName;
		if (appendFileName == "" || !fileExist(appendFileName))
			cout << "Invalid file name.";
		else
			break;
	}
	if (append(srcFileName,appendFileName)) {
		cout << "Successfully append "<<appendFileName<<" to "<<srcFileName<<endl;
	} 
	else {
		cout << "Error appending";
	}
	return 0;
}