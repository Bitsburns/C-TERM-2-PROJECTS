/*Not a code to be run by a compiler. These are my notes mostly*/

#include <iostream>
#include <cstring> // -- Always add when using cstring functions

strcpy (destination, source); /*Aka string copy. Syntax is what you see. This function overwrites and erases whatever was in the original destination. 
It copies everything including the null terminator (\0)
- Note if source is longer than destination, you overwrite random memory.*/

strncpy (desination, source, count); /*AKA String "N" Copy. It copies only the first count characters. Note if the source is longer than count 
it does NOT add the null terminator at the end. You often have to add it manually to prevent garbage text from appearing.*/

strcat (destination, source); /*Aka String Concatenate. It finds the end of the destination string (the \0) 
and starts writing the source string purely after it. It "glues" them together. Note -  You need enough space in destination to hold Current Text + New Text + Null Terminator.*/

strncat (destination, source, count); /*Aka String "N" Concatenate. 
Appends but stops after count characters. Note - Unlike Strncpy, this function does automatically add the null terminator for you making it slightly easier to use.*/

/*Simple things to remember: 

strcpy - overwrites and defines end explicitly (adds null terminator)
strcnpy - overwrites but does not add null terminator if limit is hit
strcat - appends and adds null terminator
strncat - appends and adds null terminator as well */       