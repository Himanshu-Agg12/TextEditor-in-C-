#Making library from the .c files

CC = gcc
SPELL = spellcheck
LIB = lib_spellcheck

library:
	$(CC) -c $(SPELL).c -o $(SPELL).o
	ar -cvrs $(LIB).a $(SPELL).o
	rm *.o
	
