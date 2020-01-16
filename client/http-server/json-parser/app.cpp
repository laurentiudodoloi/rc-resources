#include <stdio.h>
#include "nlohmann/json.hpp"
#include "user.h"
#include <string>
#include <list>
#include <vector>
#include <cstring>

using json = nlohmann::json;

int main() {
	std::list<char *> list;

	list.push_back("File 1");
	list.push_back("File 2");

	json j;

	for (auto it = list.begin(); it != list.end(); it++) {
		printf("\n%s", *it);
	}

	json j_list(list);

	j = {
		{ "files", j_list }
	};

	printf("\nJson: %s\n", j.dump().c_str());
}
