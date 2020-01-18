#include "request.h"
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>

Request::Request(char *data) {
	this->headers = HeaderParser::decode(data);

	this->method = new char[5];

	if (strstr(data, "GET")) {
		strcpy(this->method, "GET");
	} else if (strstr(data, "POST")) {
		strcpy(this->method, "POST");
	} else {
		strcpy(this->method, "UNKNOWN");
	}

	//this->method[strlen(this->method)] = '\0';

	this->route = new char[32];

	char *p = strchr(data, ' ');

	while (*p == ' ') {
		p++;
	}

	strcpy(this->route, p);

	p = this->route;

	while (p != NULL && (*p) != ' ') {
		p++;
	}

	*p = '\0';

	for (auto it = this->headers.begin(); it != this->headers.end(); it++) {
		if (strcmp((*it).key, "Content") == 0) {
			this->setContent((*it).value);
		}
	}
}

void Request::setContent(char *_content) {
	this->content = new char[sizeof(_content)];

	strcpy(this->content, _content);
}

char *Request::getContent() {
	return this->content;
}

void Request::setHeaders(std::list<HttpHeader> _list) {
	for (auto it = _list.begin(); it != _list.end(); it++) {
		this->headers.push_back(HttpHeader((*it).key, (*it).value));
	}
}

bool Request::send(int server) {
	char firstLine[128];
	strcpy(firstLine, this->method);
	strcat(firstLine, " ");
	strcat(firstLine, this->route);
	strcat(firstLine, " HTTP /1.1 \r\n");

	char *parsedHeaders = HeaderParser::encode(this->headers);

	char *data = new char[strlen(firstLine) + strlen(parsedHeaders) - 1];
	strcpy(data, firstLine);
	strcat(data, parsedHeaders);

	if (strstr(this->method, "POST")) {
		strcat(data, "Content:");
		strcat(data, this->content);
		strcat(data, " \r\n\r\n");
	}

	int success = write(server, data, sizeof(data));

	if (success) {
		return 1;
	}

	return 0;
}
