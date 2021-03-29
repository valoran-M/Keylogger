CC=gcc
CFLGAS=-Wall -O
LDFLAGS=
EXEC=../server
SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

all: $(EXEC)

../server: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.c: server.h

server.c: server.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLGAS)

clean:
	@rm -f *.o