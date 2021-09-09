
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

<summary><small>Screencaps of the completed app will be added soon!</small></summary>

<span>

<strike>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</strike>

4🙁4

<strike>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</strike>

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

* ***A Menu Screen***

* ***Events bound to Keys, for eg - pressing *'r'* opens file in read mode.***

* ***File opened in spell check mode won't be revised, just the words with wrong spelling will be highlighted and stored in a log file.***

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

Now you will see your executable file in the same client with name ***'editor ' .***

#### Execution 
Run the editor using:
```C
./editor
```
A Menu screen will appear.

---------------------------------------


## Learning Outcomes:

This project will help me to increase my overall knowledge of C language, its working in Linux operating system and further motivate me to do even more extensive projects using this language. It also boosts my self motivation to work as an individual and know my strengths and weaknesses.

Some technical skills that will definitely be improved are:

* **File I/O in C.**

* **Creating and including self defined header files in C.**

* ***Even deeper knowledge of different Data structures and Algorithms.***

* ***Knowledge of different applications of C programming Language.***

---------------------------------------

## Further features to add:

The main feature of Spell checking feels like a collosal task to implement right now but some additions regarding **Encoding/Decoding** can still be implemented in this project. Since I am not completely equipped with required knowledge on this topic, it can be put up on my to-do list which will be dealt with on some future date.

---------------------------------------
