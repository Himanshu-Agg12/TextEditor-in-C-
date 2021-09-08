#makefile will compile the source file and create an obejct file then it will link with the library
#target clean will clean all the object files to give a better experience

CC = gcc
FILE = editor
LIB = lib_spellcheck
SPELL = spellcheck


start:
	$(CC) -c $(FILE).c -o $(FILE).o
	$(CC) -o $(FILE) $(FILE).o -L. $(LIB).a

library:
	cp ../libs/$(SPELL).c $(SPELL).c
	$(CC) -c $(SPELL).c -o $(SPELL).o
	ar -cvrs $(LIB).a $(SPELL).o
	rm $(SPELL).c
clean:
	rm *.o
	rm $(LIB).a
