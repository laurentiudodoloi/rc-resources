all:
	g++ -c *.cpp ./http-header/*.cpp ./file-manager/file-manager.cpp
	g++ http.cpp -o http server.o request.o response.o http-header.o file-manager.o header-parser.o

clean:
	rm -f http
	rm *.o
