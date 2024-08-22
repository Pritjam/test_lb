# THIS FILE IS NOT PROVIDED TO STUDENTS!
# This file helps us (staff) create the files that will be provided to the students.

EXEC = whatday
CC = gcc
INCLUDE = .
CFLAGS = -Wall -Werror
DEBUGFLAGS = -g3
SRC = dayofweek.c dow.o

.PHONY: debug clean deploy

$(EXEC): $(SRC)
	gcc $(CFLAGS) -o $(EXEC) $(SRC) -I $(INCLUDE)

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(EXEC)

clean: 
	rm $(EXEC)
	rm -f dow.o

dow.o: dow.c
	gcc $(CFLAGS) -c -o dow.o dow.c

deploy: $(SRC)
	rm -f dow.c

dow.c:
	git checkout HEAD -- dow.c
