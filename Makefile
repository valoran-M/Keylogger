CFLAGS=-Wall -O
SERVERPATH=server_src/

server:
	@echo -e "\E[31m Server compilation\E[0m"
	@make -C $(SERVERPATH)
	@rm -f $(SERVERPATH)*.o

clean:
	@make -C $(SERVERPATH) clean

delete:
	@rm -f server
	@echo -e '\E[31m'"server was deleted"