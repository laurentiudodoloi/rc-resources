#ifndef REQUEST_H
#define REQUEST_H

#include <list>
#include "http-header.h"
#include <string>

class Request {
public:
	char *method;
	char *route;
	std::list<HttpHeader> headers;
	char *content;

    Request();
	Request(char *data);
	void setHeaders(std::list<HttpHeader> _headers);
	void setContent(char *_content);
	bool send(int server);
    std::string get(std::string resource, int server);
};

#endif
