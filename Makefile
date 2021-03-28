CFLAGS=-Wall -O
SERVERPATH=server_src/

server:
	@echo '\E[31m'"Server compilation"
	@make -C $(SERVERPATH)

clean:
	@make -C $(SERVERPATH) clean

delete:
	@rm -f server
	@echo -e '\E[31m'"server was deleted"