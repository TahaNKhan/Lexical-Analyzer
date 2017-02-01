Lexical Analyzer
----------------

This is a lexical analyzer that analyzes the toy language.

PreReqs:

1. g++ compiler, the g++ compiler did come with my linux distro,to get it type in "sudo apt-get install g++".
2. lex/flex, one of these should come with the linux distro, if not type in "sudo apt-get install lex"

Usage:

1. Go to the correct directory in terminal.
2. Type in "lex lexfile.l" in terminal.
3. Type in "g++ lex.yy.c" in terminal.
4. This will create a file called "a.out", 
   you can pipe in an input text file like:	
   "./a.out < test.toy", this will print out
	the output of the execution followed by
	the switch and symbol tables.
5. You can also type in "./a.out < test.toy > output1.txt
	to save the output to a text file.
