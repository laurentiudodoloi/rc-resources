all:
	g++ -c server.cpp
	g++ -c ./vendor/*.cpp
	g++ -c ./vendor/file-manager/*.cpp
	g++ app.cpp -o app server.o request.o response.o http-header.o file-manager.o header-parser.o

clean:
	rm -f http
	rm *.o
