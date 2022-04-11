# Reminders for me
# 	$@ - name of target 
#	$^ - list of dependencies 
#	$< - first dependencies 

# Makefile for miniproject1 calculating swallow speeds 

CC = g++
SHELL = /bin/bash
CFLAGS = -c
# finds stats library with linker flags
LDFLAGS = -L"/home/rohdeg/Git/ubiquitous-succotash/Lab1"
# library directory 
LIBDIR = "/home/rohdeg/Git/ubiquitous-succotash/Lab1"
# where the header file is 
INCDIR = -I"/home/rohdeg/Git/ubiquitous-succotash/Lab1"

# need to call stats library in Lab1 -- automatically goes into dir where lab1 is
libstuff_stats.so:
	cd "/home/rohdeg/Git/ubiquitous-succotash/Lab1"
	
airspeed: rohdeg_miniproject1.cpp
	make libstuff_stats.so
	$(CC) $(CFLAGS) $(INCDIR) -o $@ $^ -Wl,-rpath=$(LIBDIR) $(LDFLAGS) -libstats

clean: 
	rm airspeed
	rm -f *.o
	rm -f *.gch