#include "response.h"
#include <cstring>
#include <stdio.h>
#include <unistd.h>

Response::Response() {
	this->content = new char[1024 * 5];
}

void Response::setHeaders(std::list<HttpHeader> _list) {
}

void Response::setContent(char *_content) {
	strcpy(this->content, _content);
}

bool Response::send(int client) {
	char *data = new char[1024 * 5];

	strcpy(data, this->content);

	printf("\n\nSend: %s\n", data);

	int success = write(client, data, strlen(data));

	if (success) {
		return 1;
	}

	return 0;
}
