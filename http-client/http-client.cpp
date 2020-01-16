#include "http-client.h"
#include <cstring>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>

HttpClient::HttpClient(char *_ipAddress, int _port) {
	this->ipAddress = new char[strlen(_ipAddress)];

	strcpy(this->ipAddress, _ipAddress);
	this->port = port;

	this->init();
}

void HttpClient::init() {
	this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	this->serverAddress.sin_family = AF_INET;
	this->serverAddress.sin_addr.s_addr = inet_addr(this->ipAddress);
	this->serverAddress.sin_port = htons(this->port);
}

int HttpClient::makeConnection() {
	int success = connect(this->clientSocket, (struct sockaddr *) &this->serverAddress, sizeof(struct sockaddr));

	if (success == -1) {
		printf("\nConnection failed\n");
	}
}
