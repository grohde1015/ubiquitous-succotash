# Reminders for me
# 	$@ - name of target 
#	$^ - list of dependencies 
#	$< - first dependencies 

CC = g++ 
SHELL = bin/bash
# unsure what flags to use for compiler flags??? 
CFLAGS = -c

RohdeG_stats.o: RohdeG_stats.cpp RohdeG_stats.hpp
	$(CC) $(CFLAGS) $^ 

libstuff_stats.so: RohdeG_stats.o
	$(CC) -shared $^ -o $@

all: libstuff_stats.so

clean:
	rm -f *.o
	rm -f *.gch