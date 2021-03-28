CFLAGS=-Wall -O
SERVERPATH=server_src/
CLIENLINUX=linux_client

server:
	@echo -e "\E[31m Server compilation\E[0m"
	@make -C $(SERVERPATH)
	@rm -f $(SERVERPATH)*.o

client_linux:
	@echo -e "\E[31m Client linux compilation\E[0m"
	@make -C $(CLIENLINUX)
	@rm -f $(CLIENLINUX)*.o

clean:
	@make -C $(SERVERPATH) clean

delete:
	@rm -f server
	@echo -e '\E[31m'"server was deleted"