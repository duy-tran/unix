#include <iostream>
#include <string>
#include "FileManager.h"

using namespace std;

int main(){
	FileManager *test= new FileManager("test1");
	test->append("test2");
	cout << "File "<< test->getFileName() <<" has " << test->wordCount() <<" words.\n";
	return 0;     
}