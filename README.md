
# Text Editor with Spell Check.

## Overview

Welcome to **DevPad**, a simple Text-editor built purely in C. I have used a lot of notepad apps but they are either too heavy or look less appealing. So I have decided to create a minimalist notepad capable of doing all necessary tasks (i.e. enter, change, store and print text) without using any external library.

---------------------------------------

## Features

Some basic features provided in **DevPad** are:

* ***Creating a file.***
* ***Opening a file.***
* ***Saving text to a file.***
* ***Checking word spelling in a file.***

Spell checking is the *caractéristique principale* of DevPad.

## Preview

<details>

<summary><small>Screencaps of the completed App!</small></summary>

<span>

* Menu
<img src="https://github.com/Himanshu-Agg12/TextEditor-in-C-/blob/main/ScreenShots/Menu.png"/>
	
<hr/>
	
* Write Mode
<img src="https://github.com/Himanshu-Agg12/TextEditor-in-C-/blob/main/ScreenShots/write-mode.png"/>

<hr/>
	
* Read Mode
<img src="https://github.com/Himanshu-Agg12/TextEditor-in-C-/blob/main/ScreenShots/read-mode.png"/>
	
<hr/>
	
* Append Mode
<img src="https://github.com/Himanshu-Agg12/TextEditor-in-C-/blob/main/ScreenShots/append-mode.png"/>
	
<hr/>
	
* Check Mode
<img src="https://github.com/Himanshu-Agg12/TextEditor-in-C-/blob/main/ScreenShots/check-mode.png"/>
	
<hr/>
	
* Delete Mode
<img src="https://github.com/Himanshu-Agg12/TextEditor-in-C-/blob/main/ScreenShots/delete-mode.png"/>
	
<hr/>
	
* List Mode
<img src="https://github.com/Himanshu-Agg12/TextEditor-in-C-/blob/main/ScreenShots/list-mode.png"/>
	
<hr/>
	
* PWD - Mode
<img src="https://github.com/Himanshu-Agg12/TextEditor-in-C-/blob/main/ScreenShots/pwd-mode.png"/>
	
<hr/>
	
* Logs - Demo
<img src="https://github.com/Himanshu-Agg12/TextEditor-in-C-/blob/main/ScreenShots/log-file.png"/>
	
<hr/>
	
</span>

</details>

---------------------------------------

## Goals

Implementing a text-editor in itself is not burdensome but equipping it with a spell checker is the main aim here.

An efficient method will have to be implemented to check spell of a word from the whole dictionary containing over ***100,000+ words .***

Finding and implementing this efficient algorithm is the main goal of this project.

---------------------------------------
  

## Design & Specifications

The final product will be neat and user-friendly along with good code readability. Some key design/functionality elements that will be present are listed as follows:

* **A Menu Screen**

* **Events bound to Keys, for eg - pressing *'r'* opens file in read mode.**

* **File opened in spell check mode won't be revised, just the words with wrong spelling will be highlighted and stored in a log file.**

---------------------------------------
## Installation

Download both the folders ***clients and libs*** in same the folder of your workspace.
Run the following commands to use *DevPad.*

#### Compilation

* Traverse to the client directory using: 
    ```C
   cd client
   ```
* Make library for spell check using:
    ```C
   make library
   ```
* Make executable file of editor using:
    ```C
   make start
   ```
* Remove all the unwanted file using:
    ```C
   make clean
   ```

Now you will see your executable file in the same client with name ***editor***.

#### Execution
 
Run the editor using:
```C
./editor
```
    
A Menu screen will appear.

---------------------------------------
## How to use ?

* When editor is in run mode a menu screen will appear. (screen-cap for the same added above)
* User have to choose a option for changing its current mode to the following mode
	* 'r' for read mode
	* 'w' for write mode
	* 'a' for append mode
	* 'd' for delete mode
	* 'l' for list all the folder/files.
	* 'p' for print working directory
	* 'c' for Checking spellings of each words of file
* After selecting any mode a prompt appear to enter the name of the desired file.

#### Read Mode 
   Entered file will be read if file exist else an error message appears.
 >Screenshot of the read mode added in Preview
#### Write Mode
   File will open for write, remember if file already exist it will be overwritten.
   Save the file by pressing ' : + *enter-key*'.
 >Screenshot of the write mode added in Preview
#### Append Mode
   File will open in append mode, user can add text and save the file by pressing ' : +    *enter-key*'.
 >Screenshot of the append mode added in Preview
#### Check Mode
   Entered File will be checked and a logs file will be generated in the ***Logs*** folder it       will tell the user in which ***Line*** and which ***Word*** is incorrect so that user can make correction easily.
   
 After Checking of the file user will see the **Time** information(in micro-seconds) such as :
 
* Loading of dictionary.
* Checking the file.
* Average time to check file.
* Unloading the dictionary.

##### Format of log file:
filename_date_time.txt
   or
filename_yymmdd_HHMMSS.txt
   
>Screenshot of the Check Mode added in Preview
 
Moreover all the modes are self descriptive in itself, further it you need more help you can read description of each mode described in the Instructions file.

---------------------------------------

### Time-Complexity and Space-complexity of Some functions:
|                  Functions                 | Time Complexity | Space Complexity |
|--------------------------------------------|-----------------|------------------|
|load_dictionary()               | O(N)            | O(N*26)             |
|read() | O(1)            | O(1)             |
|write() | O(1)            | O(1)             |
|append()            | O(1)            | O(1)             |
|check_for_misspells(char* word)             | O(N*M)            | O(N*26)             |
|delete()          | O(1)            | O(1)             

>M is maximum size of word.


---------------------------------------

## Learning Outcomes:

This project will help me to increase my overall knowledge of C language, its working in Linux operating system and further motivate me to do even more extensive projects using this language. It also boosts my self motivation to work as an individual and know my strengths and weaknesses.

Some technical skills that will definitely be improved are:

* **File I/O in C.**

* **Creating and including self defined header files in C.**

* ***Even deeper knowledge of different Data structures and Algorithms.***

* ***Knowledge of different applications of C programming Language.***

---------------------------------------

## Further features to add :

The main feature of Spell checking feels like a colossal task to implement right now but some additions regarding:
* **Encoding/Decoding** 
* **Auto-Correct**
* **Working at the directory level.**

These can still be implemented in this project. Since I am not completely equipped with required knowledge on this topic, it can be put up on my to-do list which will be dealt with on some future date.

---------------------------------------
