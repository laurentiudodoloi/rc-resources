#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <list>
#include "response.h"

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
	Response handleRequest(Request request);
};
