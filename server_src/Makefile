CC=gcc
CFLGAS=-Wall -O
LDFLAGS=
EXEC=../server
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

../server: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@a -c $< $(CFLGAS)

clean:
	rm -f *.o