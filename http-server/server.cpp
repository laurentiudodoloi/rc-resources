#include "server.h"
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include "nlohmann/json.hpp"

#define RED "\x1B[31m"
#define BLUE "\x1B[34m"
#define YELLOW "\x1B[33m"
#define GREEN "\x1B[32m"
#define NORMAL "\x1B[0m"

using json = nlohmann::json;

#include "config/routes.h"

char *trim(char *text) {
	char *p = text;
	while (*p == ' ') {
		p++;
	}

	char *result = new char[sizeof(p)];
	p = result;

	while (*p != ' ' && *p != '\0') {
		p++;
	}

	if (*p == ' ') {
		*p = '\0';
	}

	return result;
}

void log_request(const char *method, const char *route) {
	printf("\n" BLUE);
	printf("[Request] ");
	printf("%s %s", method, route);
	printf(NORMAL);
}

void warn(const char *text) {
	printf("\n" YELLOW);
	printf("[Warning] ");
	printf("%s", text);
	printf(NORMAL);
}

void error(const char *text) {
	printf("\n" RED);
	printf("[ERROR] ");
	printf("%s", text);
	printf(NORMAL);
}

void log(const char *text, const char *color, bool prefix = 1) {
	if (prefix) {
		printf("\n[server] ");
	}

	printf("%s", color);
	printf("%s", text);
	printf(NORMAL);
}

Server::Server(const char *_ip_address, int _port) {
	this->ip_address = new char[strlen(_ip_address)];

	strcpy(this->ip_address, _ip_address);
	this->port = _port;

	this->init();
}

void Server::init() {
	log("Initializing...", NORMAL);

	if ((this->serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		error("Socket error.");
		this->errorList.push_back("Socket error.");
		return ;
	}

	bzero(&this->serverAddress, sizeof(this->serverAddress));

	this->serverAddress.sin_family = AF_INET;
	this->serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	this->serverAddress.sin_port = htons(this->port);

	log("OK.", GREEN, 0);

	log("Binding parameters...", NORMAL);
	if (bind(this->serverSocket, (struct sockaddr *) &this->serverAddress, sizeof(struct sockaddr)) == -1) {
		this->errorList.push_back("Bind error.");
		return ;
	}

	log("OK.", GREEN, 0);

	log("Setting up listener...", NORMAL);
	if (listen(this->serverSocket, 5) == -1) {
		error("Listener error.");
		this->errorList.push_back("Listen error.");
		return ;
	}

	log("OK.", GREEN, 0);

	log("READY", GREEN);

	log("Waiting for connections...", YELLOW);
}

void Server::start() {
	char buffer[100];

	while (1) {
		int client = accept(this->serverSocket, NULL, NULL);

		if (client != -1) {
			//this->clients[this->clients_number] = client;
			this->clients_number++;
			log("Client connected", GREEN);

			int pid = fork();

			if (pid < 0) {
				error("Process fork() failed.");
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
	char buffer[1024 * 5];

	bzero(&buffer, sizeof(buffer));

	if (client < 0) {
		error("Handling client request failed.");
		return ;
	}

	int bytesRead = read(client, buffer, sizeof(buffer));
	buffer[bytesRead] = '\0';

	if (!strstr(buffer, "HTTP")) {
		warn("UNKNOWN REQUEST");
		return ;
	}

	Request request(buffer);

	Response response = this->handleRequest(request);

	response.send(client);

	warn("Client connection closed.");
	close(client);
}

Response Server::handleRequest(Request request) {
	Response response;

	std::list<HttpHeader> headers;
	char *content = new char[1024 * 5];

	if (strstr(request.method, "GET")) {
		log_request("GET ", (const char *)request.route);

		strcpy(content, this->processGetRequest(request.route));
	} else if (strstr(request.method, "POST")) {
		log_request("POST ", (const char *)request.route);

		strcpy(content, this->processPostRequest(request));
	}

	response.setHeaders(headers);
	response.setContent(content);

	return response;
}

char *Server::processPostRequest(Request request) {
	char *response = new char[64];

	char *content = request.getContent();

	char *p = content;
	while (*p != '\r' && *p != '\0') {
		p++;
	}
	*p = '\0';

	if (strstr(request.route, "write")) {
		char *p = request.route;
		int i = 0;

		p++;
		while (*p != '/') {
			p++;
		}
		p++;

		char *fullPath = new char[9 + strlen(p)];
		strcpy(fullPath, "./public/");
		strcat(fullPath, p);
		int position = 4;

		int success = FileManager::writeToFile(fullPath, content);

		if (success) {
			strcpy(response, "File updated.");
		} else {
			strcpy(response, "error");
		}
	}

	return response;
}

char *Server::processGetRequest(char *route) {
	char *content = new char[1024 *5];

	if (strcmp(route, HOME_ROUTE) == 0) {
		std::list<std::string> files = FileManager::getFileList("./public");

		json j_list(files);

		error(j_list.dump().c_str());

		std::string s = j_list.dump();

		strcpy(content, s.c_str());
	} else {
		char *p = route;

		while (*p == '/') {
			p++;
		}

		char *fullPath = new char[9 + strlen(p)];
		strcpy(fullPath, "./public/");
		strcat(fullPath, p);

		if (FileManager::fileExists(fullPath)) {
			strcpy(content, FileManager::getFileContent(fullPath));
		}
	}

	return content;
}
