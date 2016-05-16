#include "FileManager.h"
#include <string>
#include <fstream>
#include <iostream>
#include <istream>

using namespace std;

FileManager::FileManager(string fileNameInput){
	fileName = fileNameInput;
}
string FileManager::getFileName(){
	return fileName;
}
void FileManager::changeFileName(string newFileName){
	fileName = newFileName;
}
void FileManager::append(string anotherFile){
	ofstream srcFile;
	srcFile.open(fileName.c_str(),ios_base::app);
	if (!srcFile.is_open()) {
		cout << "Can't open "<<fileName<<endl;
		return;
	}
	ifstream appendFile;
	string eachLine;
	appendFile.open(anotherFile.c_str());
	if (!appendFile.is_open()) {
		cout << "Can't open "<<anotherFile<<endl;
		return;
	}
	else {
		while (getline(appendFile, eachLine)) {
			srcFile << eachLine<<endl;
		}
		appendFile.close();
	}
	srcFile.close();
	cout<<"Append "<< anotherFile << " successfully!\n";
}
int FileManager::wordCount(){
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
bool fileExist(string filePath){
	ifstream fileAvailable(filePath.c_str());
  	return fileAvailable;
}