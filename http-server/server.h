#ifndef SERVER_H
#define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <list>
#include "vendor/http-header.h"
#include "vendor/response.h"
#include "vendor/request.h"
#include "vendor/file-manager/file-manager.h"

class Server {
public:
	int clients[100];
	int clients_number = 0;
	char *ip_address;
	int port;
	int serverSocket;
	struct sockaddr_in serverAddress;
	std::list<const char *> errorList;

	Server(const char *, int);
	void init();
	void start();
	void handleClient(int client);
	char *processGetRequest(char *route);
	char *processPostRequest(Request request);
	Response handleRequest(Request request);
};

#endif
