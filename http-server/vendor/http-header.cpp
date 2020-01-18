#include "http-header.h"
#include <cstring>
#include <stdio.h>

HttpHeader::HttpHeader(const char *_key, const char *_value) {
	this->key = new char[strlen(_key)];
	this->value = new char[strlen(_value)];

	strcpy(this->key, _key);
	strcpy(this->value, _value);
}

char *HttpHeader::toString() {
	char *string = new char[strlen(this->key) + strlen(this->value) + 12];

	strcpy(string, this->key);
	strcat(string, ":");
	strcat(string, this->value);
	strcat(string, "\r\n\0");

	return string;
}
