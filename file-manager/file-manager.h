#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <list>

class FileManager {
private:
	FileManager();

public:
	static std::list<char *> getFileList(char *path);
	static char *getFileContent(char *file);
	static bool writeToFile(char *file, char *content);
};

#endif
