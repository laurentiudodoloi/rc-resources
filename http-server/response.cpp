#include "response.h"

Response::Response() {
	//
}

Response::setHeaders(std::list<HttpHeader> _list) {
}

Response::setContent(char *_content) {
	strcpy(this->content, _content);
}

bool Response::send(int client) {
	char *data;

	int success = write(client, data, sizeof(data));

	if (success) {
		return TRUE;
	}

	RETURN FALSE;
}
