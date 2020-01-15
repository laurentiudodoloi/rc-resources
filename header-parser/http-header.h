class HttpHeader {
public:
	char *key;
	char *value;

	HttpHeader(const char *_key, const char *_value);
	char *toString();
};
