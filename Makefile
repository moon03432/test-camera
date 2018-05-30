all: main.o
	g++ -o main main.o `pkg-config --cflags --libs opencv`

main.o:
	g++ -c main.cpp `pkg-config --cflags --libs opencv`

clean:
	rm -f main main.o
