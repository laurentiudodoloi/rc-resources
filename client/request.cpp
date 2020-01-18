#include "request.h"
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include "header-parser.h"
#include "qdebug.h"

Request::Request() {
    //
}

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

std::string Request::get(std::string resource, int server) {
    char buffer[1024 * 5];

    char firstLine[128];
    strcpy(firstLine, "GET /");
    strcat(firstLine, resource.c_str());
    strcat(firstLine, " HTTP /1.1 \r\n");

    char *parsedHeaders = HeaderParser::encode(this->headers);

    char *data = new char[strlen(firstLine) + strlen(parsedHeaders) - 1];
    strcpy(data, firstLine);
    strcat(data, parsedHeaders);

    qDebug(data);

    write(server, data, strlen(data));

    int n = read(server, buffer, sizeof(buffer));

    buffer[n] = '\0';

    qDebug(("Response: " + std::string(buffer)).c_str());

    return std::string(buffer);
}

std::string Request::post(std::string resource, std::string content, int server) {
    char buffer[1024 * 5];

    char firstLine[128];
    strcpy(firstLine, "POST /");
    strcat(firstLine, resource.c_str());
    strcat(firstLine, " HTTP /1.1 \r\n");

    char *parsedHeaders = HeaderParser::encode(this->headers);

    char *data = new char[strlen(firstLine) + strlen(parsedHeaders) - 1];
    strcpy(data, firstLine);
    strcat(data, parsedHeaders);
    strcat(data, "\r\n");
    strcat(data, "Content: ");
    strcat(data, content.c_str());
    strcat(data, "\r\n\r\n");

    qDebug(data);

    write(server, data, strlen(data));

    int n = read(server, buffer, sizeof(buffer));

    buffer[n] = '\0';

    qDebug(("Response: " + std::string(buffer)).c_str());

    return std::string(buffer);
}
