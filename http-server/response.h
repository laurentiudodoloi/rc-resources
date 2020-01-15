#include "http-header.h"
#include <list>

class Response {
public:
	std::list<HttpHeader> headers;
	char *content;

	Response();
	bool send(int client);
}
