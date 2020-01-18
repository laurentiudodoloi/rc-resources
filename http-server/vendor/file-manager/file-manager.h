#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <list>
#include <string>

class FileManager {
private:
	FileManager();

public:
	static std::list<std::string> getFileList(const char *path);
	static char *getFileContent(char *file);
	static bool writeToFile(char *file, char *content);
	static bool writeToFile(char *file, char *content, int position);
	static bool fileExists(const char *file);
};

#endif
