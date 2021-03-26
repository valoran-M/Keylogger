CC=gcc
CFLAGS=-Wall -O

server: server.o main.o server_src/server.h
	$(CC) main.o server.o -o server

server.o: server_src/server.c server_src/server.h server_src/client.h
	$(CC) -c -Wall server_src/server.c $(CFLAGS)

main.o: server.o server_src/main.c server_src/server.h
	$(CC) -c -Wall server_src/main.c $(CFLAGS)

clean:
	rm -f *o

remove: clean
	rm -f server