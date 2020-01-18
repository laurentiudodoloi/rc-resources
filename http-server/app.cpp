#include <stdio.h>
#include "server.h"
#include "config/config.h"

int main(int argc, char *argv[]) {
	printf("Http Server.\n");

	Server server(SERVER_ADDRESS, SERVER_PORT);

	server.start();

	printf("\n");
}
