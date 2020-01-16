#ifndef HTTP_HEADER_H
#define HTTP_HEADER_H

class HttpHeader {
public:
	char *key;
	char *value;

	HttpHeader(const char *_key, const char *_value);
	char *toString();
};

#endif
