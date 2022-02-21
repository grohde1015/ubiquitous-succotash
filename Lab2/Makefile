# Gabbie Rohde
# Lab 2 Makefile 

# Reminders for me
# 	$@ - name of target 
#	$^ - list of dependencies 
#	$< - first dependencies 

# Variable definitions:
CC = g++
#CFLAGS = -

# code from lab 1 stats stuff
RohdeG_stats.o: RohdeG_stats.cpp RohdeG_stats.hpp
	$(CC) -c $^

# code from lab 2 vector stuff
RohdeG_vector_ops.o: RohdeG_vector_ops.cpp RohdeG_vector_ops.hpp
	$(CC) -c $^


RohdeG_pre_processing.o: RohdeG_pre_processing.cpp RohdeG_pre_processing.hpp RohdeG_stats.o RohdeG_vector_ops.o
	$(CC) -o $@ $^

all: RohdeG_pre_processing.o

clean:
	rm -f *.o
	rm -f *.gch