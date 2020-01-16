#include "global.h"
#include "file.h"
#include <cstring>

File Global::currentFile("");

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
