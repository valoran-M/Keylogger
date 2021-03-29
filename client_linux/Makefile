CC=gcc
CFLGAS=-Wall -O
LDFLAGS=
EXEC=../client_linux
SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

all: $(EXEC)

../client_linux: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLGAS)

clean:
	@rm -f *.o