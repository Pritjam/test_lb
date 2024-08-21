EXEC = dow
CC = gcc
INCLUDE = .
CFLAGS = -Wall -Werror
DEBUGFLAGS = -g3
SRC = dayofweek.c dow.o

.PHONY: debug clean deploy

dow: $(SRC)
	gcc $(CFLAGS) -o $(EXEC) $(SRC) -I $(INCLUDE)

debug: CFLAGS += $(DEBUGFLAGS)
debug: dow

clean: 
	rm $(EXEC)
	rm -f dow.o

dow.o: restore dow.c
	gcc $(CFLAGS) -c -o dow.o dow.c

deploy: $(SRC)
	rm -f dow.c

restore:
ifeq ($(wildcard dow.c),)
	# git checkout HEAD -- dow.c
	$(shell git checkout HEAD -- dow.c)
endif
