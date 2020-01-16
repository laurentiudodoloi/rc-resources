#include "file-manager.h"
#include <list>
#include <dirent.h>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

std::list<char *> FileManager::getFileList(const char *path) {
	std::list<char *> list;

	DIR *d = opendir(path);

	if (d == NULL) {
		return list;
	}

	struct dirent *dir;
	while ((dir = readdir(d)) != NULL) {
		if (dir->d_type != DT_DIR) {
			list.push_back(dir->d_name);
		}
	}

	closedir(d);

	return list;
}

char *FileManager::getFileContent(char *file) {
	char *content = new char[1024 * 5];
	char buffer[64];

	strcpy(content, "");

	int fd = open(file, O_RDONLY);

	int bytesRead = 0;
	while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
		buffer[bytesRead] = '\0';
		strcat(content, buffer);
	}

	return content;
}

bool FileManager::writeToFile(char *file, char *content) {
	return 1;
}
