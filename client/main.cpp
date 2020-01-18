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
#include "global.h"

using json = nlohmann::json;

int main(int argc, char *argv[]) {
 QApplication app(argc, argv);

 ColabApi *api = ColabApi::getInstance();

 MainWindow window;

 Global::window = &window;

 qDebug("App started.");

 window.show();

 return app.exec();
}
