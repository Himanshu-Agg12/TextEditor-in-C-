/* Program to implement a Text Editor in C with a feature which detects misspelled words and more.
 *Project -> 01
 *Editor Name -> DevPad
 *Date -> 30/08/2021 - 09/09/2021
 *author@Himanshu Aggarwal
 *Github -> https://github.com/Himanshu-Agg12/TextEditor-in-C- (Compilation and execution steps will be found in Readme.md)
 *Resources: 
 *1)https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/
 *2)https://www.geeksforgeeks.org/trie-insert-and-search/
 *3)https://stackoverflow.com/questions/22949500/how-to-create-file-inside-a-directory-using-c/22949610
 *4)https://www.tutorialspoint.com/c_standard_library/c_function_system.htm
 *5)https://man7.org/linux/man-pages/man3/fopen.3.html
 *6)https://www.tutorialspoint.com/cprogramming/c_file_io.htm
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#include "spellcheck.h"


/*--------------------------------------READ DATA FROM FILE--------------------------------*/


void read(){

    //reading file will print all the data of the file on the screen.
    printf("\n\t\t\t\t\t\t\t\033[33;4;1m You are in Read Only Mode\033[0m\n\n");

    //input filename.
    printf("\n\n\033[31m Enter the name of file you want to Read: \033[0m");
    char filename[20];
	scanf(" %s", filename);

    //opening file in r mode i.e, read mode.
    FILE *file;
    file = fopen(filename, "r");

    //cannot open the file.
    if(file == NULL){
        printf("\033[101;34m Sorry, File not found!!\033[0m\n");
        return;
    }

    printf("\n\t\t\t\t\t\t\t\033[38;2;124;217;210;48;2;155;106;0m %s opened.\033[0m\n", filename);

    //reading and printing the data of the file till the end of file.
    char word;
    while((word=fgetc(file))!=EOF){
        printf("%c", word); 
    }

    //closing the file
    fclose(file);

    //printing confirmation message.
    printf("\n\t\t\t\t\t\t\t\033[32m File read successully.\033[0m\n"); 

}


/*--------------------------------------WRITE DATA IN FILE/ CREATE A FILE--------------------------------*/

void write(){

    //writting the data in the file
    printf("\n\t\t\t\t\t\t\t\033[33;4;1m You are in Write Only Mode\033[0m\n\n");

    //input filename.
    printf("\n\n\033[31m Enter the name of file you want to Write: \033[0m");
    char filename[20];
	scanf(" %s", filename);

    //opening file in w mode for writting.
    FILE *file;
    file = fopen(filename, "w");

    //if file cannot be opened
    if(file == NULL){
        printf("\033[101;34m Sorry, File not found!!\033[0m\n");
        return;
    }

    //writting the file until user exit and save the file.
    printf("\n\t\t\t\t\t\t\t\033[38;2;124;217;210;48;2;155;106;0m %s opened.\033[0m\n", filename);
    printf("\n\033[31m Enter the text and press ':' and Enter to save file.\033[0m\n");
    while(1)
    {
        char ch = getchar();

        //exit condition.
        if(ch == ':'){
            fputc('\n', file);

            //closing file and printing confirmation message.
            fclose(file);
            printf("\n\t\t\t\t\t\t\t\033[32m File saved successfully as %s.\033[0m\n\n", filename);
            return;
        }

        fputc(ch, file);
    }  
}


/*--------------------------------------APPEND DATA IN FILE--------------------------------*/


void append(){

    //append mode allows to add/append data to the current file.
    printf("\n\t\t\t\t\t\t\t\033[33;4;1mYou are in Append Mode\033[0m");

    //taking input of filename
    printf("\n\n\033[31mEnter the name of file you want to Append data:\033[0m ");
    char filename[20];
	scanf(" %s", filename);

    //opneing file in a+ i.e, read and append.
    FILE *file;
    file = fopen(filename, "a+");
    if(file == NULL){
        printf("\n\033[101;34m Sorry, File not found!!\033[0m\n");
        return;
    }

    printf("\n\t\t\t\t\t\t\t\033[38;2;124;217;210;48;2;155;106;0m %s opened.\033[0m\n", filename);
    printf("\n\033[31m Input the text and press ':' and Enter to save file.\033[0m\n\n");

    //reading file to show the previous data.
    char word;
    while((word=fgetc(file))!=EOF){
       printf("%c", word); 
    }

    //writing in the file till user exit.
    while(1)
    {
        char ch = getchar();

        //exit condition for saving file.
        if(ch == ':'){
            fputc('\n', file);

            //closing file and printing confirmation message.
            fclose(file);
            printf("\n\t\t\t\t\t\t\t\033[32m File saved successfully as %s.\033[0m\n", filename);
            break;
        }

        //sending data to file
        fputc(ch, file);
    }
}


/*--------------------------------------DELETE--------------------------------*/


void delete(){

    //asking the name for file to be deleted.
    printf("\n\n\033[31mEnter the name of file you want to delete: \033[0m ");
    char filename[20];
	scanf(" %s", filename);

    //making command and copying it to 'p'
    char p[30];
    if (sprintf(p, "rm -rvf %s", filename) != -1)
    {
        system(p);
    }else{
        printf("\033[31mCurrently cannot run delete command.\033[0m\n");
    }
}


/*--------------------------------------ABOUT--------------------------------*/


void about(){

    //opening about file.
    FILE *aboutDev;
    aboutDev = fopen("./textFiles/about.txt", "r");
    if(aboutDev == NULL){
        printf("\033[101;34m Sorry, File not found!!\033[0m\n");
    }

    //reading about file.
    char word;
    while((word = fgetc(aboutDev)) != EOF){
        printf("%c", word);
    }

    //closing file.
    fclose(aboutDev);
}


/*--------------------------------------INSTRUCTIONS--------------------------------*/


void instructions(){

    //opening intructions file.
    FILE *instruct;
    instruct = fopen("./textFiles/instructions.txt", "r");
    if(instruct == NULL){
        printf("\033[101;34m Sorry, File not found!!\033[0m\n");
    }

    char word;

    //reading instructions file.
    while((word = fgetc(instruct)) != EOF){
        printf("%c", word); 
    }   

    //closing file.
    fclose(instruct);

}


/*--------------------------------------SPELL CHECKER--------------------------------*/


void checkFile(){
    //Epoch time for the execution.
    struct timeval tem;

    //take input of the file name from the user.
    char filename[20];
    printf("\n\n\033[31m Enter the name of file you want to Check: \033[0m");
    scanf("%s", filename);

    //starting time before loading dictionary.
    gettimeofday(&tem, NULL);
    long long time_before_load = tem.tv_sec *1000000LL + tem.tv_usec;

    //load the dictionary
    bool isLoaded;
    isLoaded = load_dicitonary();

    //if dictionary can not be loaded return back.
    if(!isLoaded){
        printf("Sorry, Dictionary can not be loaded.\n");
        return;
    }

    //time after loading dictioinary in trie.
    gettimeofday(&tem, NULL);
    long long time_after_load = tem.tv_sec *1000000LL + tem.tv_usec;

    //opens file of the user.
    FILE* check = fopen(filename, "r");
    if(check == NULL){
        printf("\033[101;34m Sorry, File not found!!\033[0m\n");
        unload();
        return;
    }

    //removing extension from the filename so to keep the log file name in format
    char filename2[20];
    for(int i = 0, len = strlen(filename); i < len; i++){
        if(filename[i] != '.')
            filename2[i] = filename[i];
        else{
            filename2[i] = '\0';
            break;
        }
    }

    //local time to get the local date and standard meridian time.
    time_t t = time(NULL);                                                        
    struct tm time = *localtime(&t);

    /*---------------------------get current date of the system----------------------*/

    char buffDate[30];
    sprintf(buffDate, "%.2d%.2d%.2d",(time.tm_year + 1900),(time.tm_mon + 1), (time.tm_mday));

    /*---------------------------get current time of the system----------------------*/

    char buffTime[30];
    sprintf(buffTime, "%.2d%.2d%.2d", (time.tm_hour), (time.tm_min), (time.tm_sec));

    //it will create an alternate file for logs.
    char newFile[30];

    //creating logfile name of the Format: filename_date_time.
    strcpy(newFile, filename2);
    strcat(newFile, "_");
    strcat(newFile, buffDate);
    strcat(newFile, "_");
    strcat(newFile, buffTime);
    strcat(newFile, ".txt");
    
    //setting path of logs file to 'Logs' folder.
    char path[360];
    sprintf(path, "./Logs/%s", newFile);

    //opening log file in the Logs folder.
    FILE* log = fopen(path, "w");

    //if logs cannot be created then unload the dictionary and return.
    if(log == NULL){
        printf("\033[101;34m Sorry, log file can't be created!!\033[0m\n");
        unload();
        return;
    }


    fprintf(log, "%s\n\n", "LOGs");
    char word[size + 1];

    //time before checking the word.
    gettimeofday(&tem, NULL);
    long long time_before_check = tem.tv_sec *1000000LL + tem.tv_usec / 1000;

    int index = 0, count_wrong = 0, count_words = 0, count_lines = 1, total_words = 0;

    /*traversing the whole file character by character and making a word when encountered with ' '
    also we check words that are alphabetical type and are less then 45 word length as this the maximum word lenght 
    present in the dictionary having meaning. After that we make a log file of the misspelled words in order to
    not change the original file of the user.
    Log file format: filename_yy_mm_dd_HH_MM_SS
    also we tell the line number and the word number on that line of the wrong word.
    */

    for(char c = fgetc(check); c != EOF; c = fgetc(check)){

        //only checks alphabetical words
        if(isalpha(c) && c != '\n'){
            word[index++] = c;
            if(index > size){
                while((c = fgetc(check)) != EOF && isalpha(c));
                index =0;
            }
        }

        //skipping if we encounter any digits
        else if(isdigit(c)){
            while((c = fgetc(check)) != EOF && isalnum(c));
            index = 0;
        }
        
        //otherwise if index > 0 means we found a word, now we check for the correctness of this word.

        else if(index > 0){
            
            //storing null at the end of the word buffer and making index again 0 for next words.
            word[index] = '\0';
            index = 0;

            //count of total words and the word in the specific linewise manner.
            total_words++;
            count_words++;

            //if wrong word found store in log file also tell about the line number and word number.
            if(!check_for_misspells(word)){
                count_wrong++;
                fprintf(log, "%d) ", count_wrong);
                fprintf(log, "[Line number: %d] ", count_lines);
                fprintf(log, "[Word Number: %d] ", count_words);
                fprintf(log,"\t%s\t\n\n", word);
            }

            //if line ends make count_words(count of words in a line) equal 0.
            if(c == '\n'){
                count_lines++;
                count_words = 0;
            }
        }
    }

    //time after checking file.
    gettimeofday(&tem, NULL);
    long long time_after_check = tem.tv_sec *1000000LL + tem.tv_usec;


    //printing the time calculated for each functions.
    printf("Time to Load dictionary: %lld micro-seconds\n", time_after_load - time_before_load);
    printf("Time to check the whole file: %lld micro-seconds\n", time_after_check - time_before_check);
    printf("Average Time to check the file: %lld micro-seconds\n", (time_after_check - time_before_check) / total_words);

    
    //closing the files.{logs and check}
    fclose(check);
    fclose(log);

    //time before onloading dictionary.
    gettimeofday(&tem, NULL);
    long long time_before_unload = tem.tv_sec *1000000LL + tem.tv_usec;

    //destroying/unloading the dictionary from trie.
    unload();

    //time after onloading dictionary.
    gettimeofday(&tem, NULL);
    long long time_after_unload = tem.tv_sec *1000000LL + tem.tv_usec;
    printf("Time to unload the dictionary: %lld micro-seconds\n", (time_after_unload - time_before_unload));

    //printing the confirmation message.
    printf("\033[32mLog file generated successfully in 'Logs' folder!!\033[0m\n");
}


/*<<<--------------------------------------MAIN METHOD-------------------------------->>>*/


int main()
{
    while(1){

        
        /*--------------------------------------M E N U--------------------------------*/


        system("clear");
        printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\t\t\t*\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[102;30m ***************DevPad*************** \033[0;0m\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\t\t\t\t\t\t\t\t\t*\n");
        char choice; 
        printf("\t\t\t\t*\t\t\033[94m Enter in the following mode:\033[0m\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[90m -------------------------------------\033[0m\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[38;2;239;122;122m Press 'r' to enter Read Mode.\033[0m\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[38;2;239;122;122m Press 'w' to enter Write Mode.\033[0m\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[38;2;239;122;122m Press 'a' to enter Append Mode.\033[0m\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[38;2;239;122;122m Press 'd' to Delete a file.\033[0m\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[38;2;239;122;122m Press 'l' to List all the files/folders present in this directory.\033[0m\t*\n");
        printf("\t\t\t\t*\t\t\033[38;2;239;122;122m Press 'p' to print Present Working Directory.\033[0m\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[38;2;239;122;122m Press 'c' for Checking Misspelled Words in your file.\033[0m\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[38;2;239;122;122m Press 'i' for Instructions.\033[0m\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[38;2;239;122;122m Press 'm' to Know More about developer.\033[0m\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\033[38;2;239;122;122m Press 'q' to quit.\033[0m\t\t\t\t\t\t\t*\n");
        printf("\t\t\t\t*\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");


        /*--------------------------------------USER CHOICE--------------------------------*/


        printf(" Enter Input: ");
        scanf(" %c", &choice);


        /*--------------------------------------READ A FILE (CHOICE)--------------------------------*/


        if(choice == 'r'){
            read();
            
            printf("\n\033[38;5;206;48;5;57m Press Enter to continue -> \033[0m"); 
            getc(stdin);
            getc(stdin);
            continue;
        }
        

        /*--------------------------------------WRITE A FILE (CHOICE)--------------------------------*/


        else if(choice == 'w'){
            write();

            printf("\n\033[38;5;206;48;5;57m Press Enter to continue ->\033[0m"); 
            getc(stdin);
            getc(stdin);
            continue;
        }

        
        /*--------------------------------------APPEND A FILE (CHOICE)--------------------------------*/


        else if(choice == 'a'){
            append();
            printf("\n\033[38;5;206;48;5;57m Press Enter to continue ->\033[0m "); 
            getc(stdin);
            getc(stdin);
            continue;
        }


         /*--------------------------------------DELETE A FILE (CHOICE)--------------------------------*/


        else if(choice == 'd'){
            delete();
            printf("\n\033[38;5;206;48;5;57m Press Enter to continue ->\033[0m "); 
            getc(stdin);
            getc(stdin);
            continue;
        }
    

        /*--------------------------------------CHECK FOR FILE SPELLS (CHOICE)--------------------------------*/


        else if(choice == 'c'){
            checkFile();
            printf("\n\033[38;5;206;48;5;57m Press Enter to continue ->\033[0m"); 
            getc(stdin);
            getc(stdin);
            continue;
        }


        /*--------------------------------------LISTING ALL FILES/FOLDERS (CHOICE)--------------------------------*/


        if(choice == 'l'){
            system("ls");
            
            printf("\n\033[38;5;206;48;5;57m Press Enter to continue -> \033[0m"); 
            getc(stdin);
            getc(stdin);
            continue;
        }


        /*--------------------------------------PATH OF WORKING DIRECTORY (CHOICE)--------------------------------*/


        if(choice == 'p'){
            system("pwd");
            printf("\n\033[38;5;206;48;5;57m Press Enter to continue -> \033[0m"); 
            getc(stdin);
            getc(stdin);
            continue;
        }
        
        /*--------------------------------------INSTRUCTIONS (CHOICE)--------------------------------*/

        
        else if(choice == 'i'){
            instructions();
            printf("\n\033[38;5;206;48;5;57m Press Enter to continue ->\033[0m"); 
            getc(stdin);
            getc(stdin);
            continue;
        } 

        
        /*--------------------------------------ABOUT (CHOICE)--------------------------------*/


        else if(choice == 'm'){
            about();
            printf("\n\033[38;5;206;48;5;57m Press Enter to continue ->\033[0m"); 
            getc(stdin);
            getc(stdin);
            continue;
        }

        
        /*--------------------------------------QUIT (CHOICE)--------------------------------*/


        else if(choice == 'q')
            break;

        
        /*--------------------------------------INVALID CHOICE--------------------------------*/


       else{
           printf("\n\t\t\033[33m Invalid choice, Try again.\n");
           printf("\n\t\t\033[38;5;206;48;5;57m Press Enter to continue ->\033[0m "); 
           getc(stdin);
           getc(stdin);
           continue;
       }

    }
    return 0;
}