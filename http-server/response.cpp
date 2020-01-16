#include "response.h"
#include <cstring>
#include <stdio.h>
#include <unistd.h>

Response::Response() {
	//
}

void Response::setHeaders(std::list<HttpHeader> _list) {
}

void Response::setContent(char *_content) {
	strcpy(this->content, _content);
}

bool Response::send(int client) {
	char *data;

	int success = write(client, data, sizeof(data));

	if (success) {
		return 1;
	}

	return 0;
}
