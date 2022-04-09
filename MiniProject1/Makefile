# Reminders for me
# 	$@ - name of target 
#	$^ - list of dependencies 
#	$< - first dependencies 

CC = g++
SHELL = /bin/bash
CFLAGS = -c
# finds stats library with linker flags
LDFLAGS = -L "/home/rohdeg/Git/ubiquitous-succotash/Lab1"
# library directory 
LIBDIR = "/home/rohdeg/Git/ubiquitous-succotash"
# where the header file is 
INCDIR = -I "/home/rohdeg/Git/ubiquitous-succotash/Lab1"

# need to call stats library in Lab1
libstuff_stats.so:
	cd "/home/rohdeg/Git/ubiquitous-succotash/Lab1"
	make all

airspeed: rohdeg_miniproject1.cpp
	make libstuff_stats.so
	$(CC) $(CFLAGS) $(INCDIR) -o $^ -Wl, -rpath=$(LIBDIR) -libstats

clean: 
	rm airspeed
	rm -f *.o
	rm -f *.gch