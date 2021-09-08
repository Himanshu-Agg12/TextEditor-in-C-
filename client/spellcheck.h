#ifndef spell_check
#define spell_check

//declaration of the functions.

#include <stdbool.h>
#define size 45 //maximum words length exist in dictionary.

bool load_dicitonary(); //loads the dictionary.
bool check_for_misspells(); //check for the word is misspelled or not.
void unload(); //unloads dictionary.

#endif