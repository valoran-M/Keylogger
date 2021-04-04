CC=gcc
CFLGAS=-Wall -O -g
LDFLAGS=
EXEC=../client
SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLGAS)

clean:
	@rm -f *.o