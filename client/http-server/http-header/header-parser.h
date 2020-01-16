#include <list>
#include "http-header.h"

class HeaderParser {
private:
	HeaderParser();

public:
	static char *encode(std::list<HttpHeader> headers);
	static std::list<HttpHeader> decode(char *headers);
};
