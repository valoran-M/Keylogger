CC=gcc
LDFLAGS=
CFLAGS=-Wall -O
SERVERPATH=server_src/

SRCSERVER=$(wildcard $(SERVERPATH)*.c)
OBJSERV=$(SRC:.c=.o)

server: $(OBJSERV)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o core

mrproper: clean
	rm -f server
