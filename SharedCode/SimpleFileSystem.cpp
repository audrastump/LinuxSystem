// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"

int SimpleFileSystem ::addFile(std::string name, AbstractFile* a) {
	if (fileMap.count(name)==0) {
		if (a != nullptr) {

			fileMap.insert(std::pair<std::string, AbstractFile*>(name,a));
		}
		return 1;
	}
	return 2;
}
int createFile(std::string name);
int deleteFile(std::string name);
AbstractFile* openFile(std::string name);
int closeFile(AbstractFile* a);