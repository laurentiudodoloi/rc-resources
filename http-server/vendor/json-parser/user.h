#include "jsonable.h"

class User : public Jsonable {
public:
	char *name;
	User(char *_name);
	User(const char *_name);
	char *toJson();
};
