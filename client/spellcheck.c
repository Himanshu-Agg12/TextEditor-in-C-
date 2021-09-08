//declaring the standard libraries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "spellcheck.h"

//there are only 26 alphabets in the english dictionary.
#define n 26


/*--------------------------------------Declaring the structure--------------------------------*/

//defining the trie structure for storing the nodes/characters.
typedef struct trie_structure{
    //declaring array of 26 characters.
    struct trie_structure* children[n];
    //tells wether the word is completed according to dictionary or not.
    bool isCompleted;
}trie;

/*--------------------------------------Initialize the memory of nodes--------------------------------*/

//initialize the node as NULL.
void initialize(trie* treeNode){
     treeNode -> isCompleted = false;
    for(int i = 0; i < n; i++){
        treeNode -> children[i] = NULL;
    }
}

//root node act as head of all the children nodes.
trie* root;

/*--------------------------------------Load Dictionary in Trie--------------------------------*/

bool load_dicitonary(){

    //allocate memory to root
    root = malloc(sizeof(trie));
    if(root == NULL)
        printf("Root cannot be initialized\n");

    //initializing the root
    initialize(root);

    //open dicitonaray file
    FILE* dictionary = fopen("./textFiles/dictionary.txt", "r");

     //if dictionary not opened
    if(dictionary == NULL){
         printf("Dictionary is not opened\n");
         unload();
         return false;
    }

    //buffer of the each word from dictionary file.
    char buffer[size + 1];

    //index keeps track at which position next pointer should be created.
    int index;

    //it will traverse on every word in the dictionary and store it in trie as when we need for checking the 
    //words we search in this trie

    while (fscanf(dictionary, "%s", buffer) != EOF)
    {

         //creating child for the refrence and for traversing the trie
         //don't use root as the head will loss.
         //child is pointing to the first node i.e, parent/root node.
          trie* child = root;

          //finding word length
          int length = strlen(buffer);

          //traversing all characters of the word.
          for(int i = 0; i < length; i++){

               //it will find the index of the word. Eg: (a is at 0, b is at 1 etc...)
               index = (int)buffer[i] - (int)'a';

               //if the index at that word's place is null it means no word exist there and we can
               // store our word there.
               if(child -> children[index] == NULL)
               {
                    //hence we have to store the word we have to allocate the memory 
                    //and have to initialize it as null.
                    child -> children[index] = malloc(sizeof(trie));
                    if(child -> children[index] == NULL){
                         printf("child's children array cannot be initialized\n");
                         return false;
                    }
                    initialize(child -> children[index]);

               }

               //after storing we will move to that children and ask for the next index.
               child = child -> children[index];
          }

          //after storing all the words we maintain a isCompleted variable which 
          //will tell us that word is finished and it is a valid word.
          child -> isCompleted = true;
    }

    //closing the dictionary file.
    fclose(dictionary);

    //returning true as we made dictionary's trie.
    return true;
}

/*--------------------------------------Check For Spellings--------------------------------*/

/*it will takes the input word by word and checks for the same in the trie created above, if we found
a valid word we say that it is correct else it is a misspelled.
Valid word have 2 conditons:
1) all the children should exist at that indices
2) Word should be completed(checked with the help of isCompleted).
*/

bool check_for_misspells(const char* word){

     //stores the index of the characters
     int index;

     //creating the child for traversing the trie.
	trie* child = root;

     //finding the word length
     int len = strlen(word);

     //traverse till length of the word.
	for (int i = 0; i < len; i++){

          //we will convert all the word to lower case for finding the valid index.
		index = (int)tolower(word[i]) - (int)'a';

          //traverse to the children of that index.
		child = child -> children[index];

          //if children at that index is null it means word does'nt exist.
		if (child == NULL) {
			return false;
		}
	}

     //traversal completed means all words exist now we return true is isCompleted is true means words is valid
     //else return flase i.e, word is not valid.
	return child->isCompleted;
}

/*--------------------------------------Free the nodes data of Trie--------------------------------*/

//it destoyes/unloads the trie of each node and free space of each nodes.
void unload_dictionary(trie* head){

     //if head is null i.e, reached at the end.
     if(head == NULL)
          return;
     
     //recursive call to traverse all the children of the root
     for(int i = 0; i < n; i++){
          if(head -> children[i] != NULL){
               unload_dictionary(head -> children[i]);
          }
     }
     //function call stack for freeing up the memory.
     free(head);
}

//it will called from the client side.
void unload(){
     unload_dictionary(root);
}