#include "user.h"
#include <cstring>
#include "nlohmann/json.hpp"

using jsonx = nlohmann::json;

User::User(char *_name) {
	this->name = new char[strlen(_name)];
	strcpy(this->name, _name);
}

User::User(const char *_name) {
	this->name = new char[strlen(_name)];
	strcpy(this->name, _name);
}

char *User::toJson() {
	char *json = new char[128];

	strcpy(json, "{ ");

	strcat(json, "\"name\":");
	strcat(json, "\"");
	strcat(json, this->name);
	strcat(json, "\"");

	strcat(json, " }");

	jsonx j;
	j["name"] = "test123";

	strcpy(json, j.dump().c_str());

	return json;
}
