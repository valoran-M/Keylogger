CC=gcc
CFLGAS=-Wall -O
LDFLAGS= -lws2_32
EXEC=../windows_client
SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

all: $(EXEC)

../windows_client: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLGAS)

main.o: key.c key.h network.c network.h

key.o: key.h

network.o: network.c key.c key.h

clean:
	@rm -f *.o