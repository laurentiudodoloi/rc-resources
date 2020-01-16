#ifndef COLLABAPI_H
#define COLLABAPI_H

class CollabApi
{
public:
    CollabApi();

    void connect();
    void disconnect();

    void getFiles();
    void getFileContents();
    void downloadFile();
};

#endif // COLLABAPI_H
