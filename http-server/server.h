#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <list>
#include "http-header/http-header.h"
#include "response.h"
#include "request.h"

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
	Response handleRequest(Request request);
};
