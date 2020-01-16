all:
	g++ -c *.cpp ./http-header/*.cpp
	g++ http.cpp -o http server.o request.o response.o ./http-header/*.o

clean:
	rm -f http
