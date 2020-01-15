#include <stdio.h>
#include "server.h"

int main(int argc, char *argv[]) {
	printf("Http Server.\n");

	Server server("127.0.0.1", 2048);

	server.start();

	printf("\n");
}
