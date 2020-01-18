#ifndef RESPONSE_H
#define RESPONSE_H

#include "http-header.h"
#include <list>

class Response {
public:
	std::list<HttpHeader> headers;
	char *content;

	Response();
	void setHeaders(std::list<HttpHeader> _headers);
	void setContent(char *_content);
	bool send(int client);
};

#endif
