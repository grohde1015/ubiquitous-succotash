# Gabbie Rohde
# Lab 2 Makefile 

# Reminders for me
# 	$@ - name of target 
#	$^ - list of dependencies 
#	$< - first dependencies 

# Variable definitions:
CC = g++

# code from lab 1 stats stuff
RohdeG_stats.o: RohdeG_stats.cpp RohdeG_stats.hpp
	$(CC) -o $@ $<

# code from lab 2 vector stuff
RohdeG_vector_ops.o: RohdeG_vector_ops.cpp RohdeG_vector_ops.hpp
	$(CC) -o $@ $<

All: RohdeG_stats.o RohdeG_vector_ops.o
