#ifndef COLAB_API_H
#define COLAB_API_H

#include <string>
#include "http-client.h"

class ColabApi {
private:
    static ColabApi *instance;

    ColabApi() {};

public:
    static ColabApi *getInstance();
    HttpClient *client;

    void init();
    std::string getFileList();
    std::string getFileContent(std::string file);
    std::string writeToFile(std::string file, std::string content);
};

#endif
