CFLAGS=-Wall -O
SERVERPATH=src_server/
LINUXCLIENT=src_linux_client/

all: server linux_client

server: $(SERVERPATH)*.[ch]
	@echo -e "\E[32m Server compilation\E[0m"
	@make -C $(SERVERPATH)
	@rm -f $(SERVERPATH)*.o

linux_client: $(LINUXCLIENT)*.[ch]
	@echo -e "\E[32m Linux client compilation\E[0m"
	@make -C $(LINUXCLIENT)
	@rm -f $(LINUXCLIENT)*.o

clean:
	@rm -f */*.o

delete: clean
	@rm -f server
	@echo -e '\E[31m'"server was deleted"
	@rm -f client
	@echo -e '\E[31m'"client was deleted"