#ifndef COLAB_API_H
#define COLAB_API_H

#include <string>
#include <list>
#include "http-client.h"

class ColabApi {
private:
    static ColabApi *instance;

    ColabApi() {};

public:
    static ColabApi *getInstance();
    HttpClient *client;
    bool connected = false;

    void init();
    std::list<std::string> getFileList();
    bool downloadFile(std::string file, std::string path);
    std::string getFileContent(std::string file);
    std::string writeToFile(std::string file, std::string content);
};

#endif
