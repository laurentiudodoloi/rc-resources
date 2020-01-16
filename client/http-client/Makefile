all:
	g++ -c http-client.cpp colab-api.cpp request.cpp http-header/*.cpp
	g++ client.cpp -o client http-client.o colab-api.o request.o header-parser.o http-header.o

clean:
	rm -f client
