#include "server.h"
#include "request.h"
#include "response.h"
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "routes.h"

Server::Server(const char *_ip_address, int _port) {
	this->ip_address = new char[strlen(_ip_address)];

	strcpy(this->ip_address, _ip_address);
	this->port = _port;

	this->init();
}

void Server::init() {
	printf("Init.\n");

	if ((this->serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		this->errorList.push_back("Socket error.");
		return ;
	}

	bzero(&this->serverAddress, sizeof(this->serverAddress));

	this->serverAddress.sin_family = AF_INET;
	this->serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	this->serverAddress.sin_port = htons(this->port);

	printf("Binding\n");
	if (bind(this->serverSocket, (struct sockaddr *) &this->serverAddress, sizeof(struct sockaddr)) == -1) {
		this->errorList.push_back("Bind error.");
		return ;
	}

	printf("Listening\n");
	if (listen(this->serverSocket, 5) == -1) {
		this->errorList.push_back("Listen error.");
		return ;
	}

	printf("Ready.\n");
}

void Server::start() {
	printf("\nServer started.");
	const char *msg = "Hai salut!";
	char buffer[100];

	while (1) {
		int client = accept(this->serverSocket, NULL, NULL);

		if (client != -1) {
			//this->clients[this->clients_number] = client;
			this->clients_number++;

			int pid = fork();

			if (pid < 0) {
				printf("\nFork error.\n");
				return ;
			}

			if (pid == 0) {
				this->handleClient(client);
			} else {
				close(client);
				continue;
			}
		}
	}
}

void Server::handleClient(int client) {
	printf("\nHandle client.\n");
	char msg[64];
	strcpy(msg, "Hello client.");

	char buffer[512];

	bzero(&buffer, sizeof(buffer));

	if (client < 0) {
		printf("\nClient error.\n");
		return ;
	}

	printf("\nReading from client..\n");
	read(client, buffer, sizeof(buffer));

	printf("\nRead from client: %s\n", buffer);

	if (!strstr(buffer, "HTTP")) {
		printf("\nUNKNOWN REQUEST\n");
		return ;
	}

	Request request(buffer);

	Response response = this->handleRequest(request);

	//response->send(client);

	//write(client, msg, sizeof(msg));

	close(client);
}

Response Server::handleRequest(Request request) {
	printf("\nHandle request\n");
	Response response;

	std::list<HttpHeader> headers;
	char *content;

	if (strstr(request.method, "GET")) {
		printf("\nProcess GET Request\n");

		strcpy(content, this->processGetRequest(request.route));

	} else if (strstr(request.method, "POST")) {
		printf("\nProcess POST Request\n");
	}

	printf("\nProcessed content: %s\n", content);

	response.setHeaders(headers);
	response.setContent(content);

	return response;
}

char *Server::processGetRequest(char *route) {
	printf("\nProcessing GET: %s\n", route);

	if (strcmp(route, HOME_ROUTE) == 0) {
		printf("\nRoute: Home\n");
	} else if (strcmp(route, USERS_ROUTE) == 0) {
		printf("\nRoute: Users\n");
	} else if (strcmp(route, LOGIN_ROUTE) == 0) {
		printf("\nRoute: Login\n");
	}
}
