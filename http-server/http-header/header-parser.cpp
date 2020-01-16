#include "header-parser.h"
#include <cstring>
#include <list>
#include <stdio.h>

char *HeaderParser::encode(std::list<HttpHeader> headers) {
	char *str = new char[32];
	strcpy(str, "");

	char *line;
	for (auto it = headers.begin(); it != headers.end(); it++) {
		line = new char[strlen((*it).key) + strlen((*it).value) + 12];

		strcpy(line, (*it).key);
		strcat(line, ":");
		strcat(line, (*it).value);
		strcat(line, "\r\n");

		strcat(str, line);
	}

	return str;
}

std::list<HttpHeader> HeaderParser::decode(char *headers) {
	std::list<HttpHeader> l;

	char *p;

	char tokens[12][64];
	int i;
	int n = 0;
	p = strtok(headers, "\r\n");
	while (p != NULL) {
		strcpy(tokens[n], p);
		n++;

		p = strtok(NULL, "\r\n");
	}

	char key[64];
	char value[64];
	for (i = 0; i < n; ++i) {
		if (strchr(tokens[i], ':')) {
			p = strtok(tokens[i], ":");
			strcpy(key, p);

			p = strtok(NULL, ":");
			strcpy(value, p);

			l.push_back(HttpHeader(key, value));
		}
	}

	return l;
}
