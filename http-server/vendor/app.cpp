#include <stdio.h>
//#include "http-header.h"
#include "header-parser.h"
#include <list>
#include <cstring>

int main() {
	char *headersStr = new char[1024];
	strcpy(headersStr, "HTTP/1.1 200\r\n");
	strcat(headersStr, "Content-Type: text/html; charset=utf-8\r\n");
	strcat(headersStr, "Content-Length: 19912\r\n");
	strcat(headersStr, "\r\n");

	std::list<HttpHeader> headers;

	headers = HeaderParser::decode(headersStr);

	//headers.push_back(HttpHeader("content-length", "20166"));
	//headers.push_back(HttpHeader("content-type", "text/html"));
	//headers.push_back(HttpHeader("status", "200"));

	printf("Decode list\n\n");

	for (auto it = headers.begin(); it != headers.end(); it++) {
		printf("%s", (*it).toString());
	}

	printf("\n\nEncode list \n\n");

	char *headerString = HeaderParser::encode(headers);

	printf("%s", headerString);

	return 0;
}
