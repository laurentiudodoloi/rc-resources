#include "colab-api.h"
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include "qdebug.h"
#include "request.h"
#include "nlohmann/json.hpp"
#include "file-manager.h"

using json = nlohmann::json;

ColabApi *ColabApi::instance = 0;

ColabApi *ColabApi::getInstance() {
    if (!instance) {
        instance = new ColabApi;
    }

    instance->init();

    return instance;
}

void ColabApi::init() {
    this->client = new HttpClient("127.0.0.1", 2048);
    this->connected = this->client->makeConnection();
}

std::list<std::string> ColabApi::getFileList() {
    std::list<std::string> list;

    if (!connected) {
        qDebug("Network error.");
    } else {
        Request request;

        json j = json::parse(request.get("", client->clientSocket));

        auto& files = j;

        std::list<std::string> fileList;
        for (json::iterator it = files.begin(); it != files.end(); it++) {
            list.push_back((*it).get<std::string>());
        }
    }

    return list;
}

bool ColabApi::downloadFile(std::string file, std::string path) {
    std::string content = getFileContent(file);

    char *c = new char[content.length()];
    strcpy(c, content.c_str());

    char *fullPath = new char[file.length() + path.length()];
    strcpy(fullPath, path.c_str());
    strcat(fullPath, "/");
    strcat(fullPath, file.c_str());

    int created = FileManager::createFile(fullPath);

    int override = FileManager::writeToFile(fullPath, c);

    return created || override;
}

std::string ColabApi::getFileContent(std::string file) {
    Request request;

    std::string content = request.get(file, client->clientSocket);

    return content;
}

std::string ColabApi::writeToFile(std::string file, std::string content) {
}
