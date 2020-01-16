#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class HttpClient {
public:
	char *ipAddress;
	int port;
	int clientSocket;
	struct sockaddr_in serverAddress;

	HttpClient(char *, int);
	void init();
	int makeConnection();
	char *makeRequest();
};
