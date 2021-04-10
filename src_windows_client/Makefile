CC=gcc
CFLGAS=-Wall -O
LDFLAGS=
EXEC=../windows_client
SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

all: $(EXEC)

../windows_client: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLGAS)

main.o: key.c key.h

key.o: key.h

clean:
	@rm -f *.o