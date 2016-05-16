#include <string>
using namespace std;
bool fileExist(string fullPathDestFile);
string getFileName(string file);
string getFileType(string file);
int getNumberFromFileName(string fileName);
int getNumberOldFile(string destDir, string file);
string getNewName(string destDir, string file);
void copy(string searchingDir, string destDir, string fileName);