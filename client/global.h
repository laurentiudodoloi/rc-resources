#ifndef GLOBAL_H
#define GLOBAL_H

#include "file.h"
#include <string>
#include "mainwindow.h"
#include <list>

class Global
{
public:
    static File currentFile;
    static std::string tempText;
    static MainWindow *window;
    static std::list<std::string> fileList;

    Global();
    static bool isFileSelected();
    static void selectFile(File file);
};

#endif // GLOBAL_H
