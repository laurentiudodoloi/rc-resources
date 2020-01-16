#include <QtGui>
#include <QApplication>
#include <QLabel>
#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <QTextStream>
#include "qdebug.h"
#include <QObject>
#include "colab-api.h"
#include "request.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main(int argc, char *argv[]) {
 QApplication app(argc, argv);

 ColabApi *api = ColabApi::getInstance();
 api->init();

// std::string fileList = api->getFileList();

// Request request;

// json j = json::parse(request.get("/", api->client->clientSocket));

// auto& files = j["files"];

// std::list<std::string> fileList;
// for (json::iterator it = files.begin(); it != files.end(); it++) {
////     qDebug((*it).dump().c_str());
// }

// qDebug(j.dump().c_str());

// json h = j["files"];

 MainWindow window;

 qDebug("App started.");

 window.show();

 return app.exec();
}
