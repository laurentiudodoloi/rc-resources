#include <stdio.h>
#include "nlohmann/json.hpp"
#include "user.h"
#include <string>

using json = nlohmann::json;

int main() {
	User user("John");

	printf("User: %s\n", user.toJson());

	auto j = json::parse(user.toJson());

	printf("Here: %s\n", j["name"].get<std::string>().c_str());

	//struct json_object *name;

	//json_object_object_get_ex(parsed, "name", &name);

	//printf("\nParsed: %s\n\n", json_object_get_string(name));
}
