#include "global.h"
#include "file.h"
#include <cstring>

File Global::currentFile("");

std::string Global::tempText("");
std::list<std::string> Global::fileList = {};
MainWindow *Global::window = nullptr;

Global::Global()
{
    //
}

bool Global::isFileSelected() {
    return strcmp(currentFile.text.toStdString().c_str(), "") != 0;
}

void Global::selectFile(File file) {
    currentFile = file;
}
