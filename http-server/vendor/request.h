#ifndef REQUEST_H
#define REQUEST_H

#include <list>
#include "http-header.h"
#include "header-parser.h"

class Request {
public:
	char *method;
	char *route;
	std::list<HttpHeader> headers;
	char *content;

	Request(char *data);
	void setHeaders(std::list<HttpHeader> _headers);
	void setContent(char *_content);
	char *getContent();
	bool send(int server);
};

#endif
