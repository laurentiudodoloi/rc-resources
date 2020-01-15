all:
	g++ -c http-header.cpp
	g++ -c header-parser.cpp
	g++ app.cpp -o app http-header.o header-parser.o

clean:
	rm -f *.o
	rm -f app
