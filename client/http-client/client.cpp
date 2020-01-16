#include "http-client.h"
#include <cstring>
#include <stdio.h>

int main() {
	HttpClient client("127.0.0.1", 2048);

	client.makeConnection();

	//client.makeRequest();
}
