#ifndef GLOBAL_H
#define GLOBAL_H

#include "file.h"

class Global
{
public:
    static File currentFile;

    Global();
    static bool isFileSelected();
    static void selectFile(File file);
};

#endif // GLOBAL_H
