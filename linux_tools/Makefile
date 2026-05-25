CC = gcc
CFLAGS = -Wall

BIN_DIR = bin

TOOLS = myls mycat mycp

.PHONY: all clean install uninstall debug release package

all:
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) src/myls.c src/utils.c -Iinclude -o $(BIN_DIR)/myls
	$(CC) $(CFLAGS) src/mycat.c src/utils.c -Iinclude -o $(BIN_DIR)/mycat
	$(CC) $(CFLAGS) src/mycp.c src/utils.c -Iinclude -o $(BIN_DIR)/mycp

debug: CFLAGS += -g
debug: clean all

release: CFLAGS += -O2
release: clean all

install:
	mkdir -p $(BIN_DIR)/installed
	cp $(BIN_DIR)/* $(BIN_DIR)/installed/

uninstall:
	rm -rf $(BIN_DIR)/installed

clean:
	rm -rf $(BIN_DIR)/myls
	rm -rf $(BIN_DIR)/mycat
	rm -rf $(BIN_DIR)/mycp

package:
	tar --exclude=linux_tools.tar.gz -czf linux_tools.tar.gz .
