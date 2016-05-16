#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#include <string>

using namespace std;

class FileManager{
	protected:
		string fileName;
	public:
		FileManager(string fileNameInput);
		string getFileName();
		void changeFileName(string newFileName);
		void append(string anotherFile);
		int wordCount();
};

bool fileExist(string filePath);

#endif
