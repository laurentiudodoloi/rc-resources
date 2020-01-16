#include "colab-api.h"
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include "qdebug.h"
#include "request.h"

ColabApi *ColabApi::instance = 0;

ColabApi *ColabApi::getInstance() {
    if (!instance) {
        instance = new ColabApi;
    }

    return instance;
}

void ColabApi::init() {
    this->client = new HttpClient("127.0.0.1", 2048);
    this->client->makeConnection();
}

std::string ColabApi::getFileList() {
    std::string result("Filelist");

    qDebug("Get file-list.");

    Request request();

    return result;
}

std::string ColabApi::getFileContent(std::string file) {
	//
}

std::string ColabApi::writeToFile(std::string file, std::string content) {
}
