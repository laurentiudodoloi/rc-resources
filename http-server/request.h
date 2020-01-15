#include <list>
#include "http-header.h"

class Request {
public:
	char *method;
	char *route;
	std::list<HttpHeader> headers;
	char *content;

	Request(char *data);
	bool send(int server);
}
