#include "file-manager.h"
#include <list>
#include <dirent.h>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string>

bool FileManager::fileExists(const char *file) {
	return access(file, F_OK) != -1;
}

std::list<std::string> FileManager::getFileList(const char *path) {
	std::list<std::string> list;

	DIR *d = opendir(path);

	if (d == NULL) {
		return list;
	}

	struct dirent *dir;
	while ((dir = readdir(d)) != NULL) {
		if (dir->d_type != DT_DIR && strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")) {
			list.push_back(std::string(dir->d_name));
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

	close(fd);

	return content;
}

bool FileManager::writeToFile(char *file, char *content) {
	int fd = open(file, O_WRONLY);

	printf("\nOVERRIDE %s: %s\n\n", file, content);
	int success = write(fd, content, strlen(content));

	close(fd);

	return success > 0;
}

bool FileManager::writeToFile(char *file, char *content, int position) {
	printf("\n\nWRITE to %s: %s at %d", file, content, position);

	int fd = open(file, O_RDONLY);

	char buffer[1024 * 5];

	int readBytes = read(fd, buffer, sizeof(buffer) - 1);
	buffer[readBytes] = '\0';

	printf("\nREAD: %s", buffer);

	char *temp = new char[strlen(content) + strlen(buffer)];

	if (position == 0) {
		strcpy(temp, content);
		strcat(temp, buffer);
	} else if (position >= strlen(buffer) - 1) {
		strcpy(temp, buffer);
		strcat(temp, content);
	} else {
		char *temp2 = new char[sizeof(temp)];
		strcpy(temp, buffer);


		char *p = temp;
		int i = 0;
		while (i < position) {
			i++;
			p++;
		}

		strcpy(temp2, p);

		strcpy(temp + i, content);

		strcat(temp, temp2);
	}

	close(fd);

	return writeToFile(file, temp);
}
