# empilhador-generico-hokama

Your program should read from the system's standard input a sequence of commands, which can either push an integer, push a character, or pop (print) show the stack size and exit the program. The commands will be given as follows: ● e : push the data that can be an integer or a character ● d: pop and print the data from the top of the stack ● t: print the current size of the stack ● x: terminate the program

INPUT:  
e 10
e a
e 20
d
d
e b
t
d
d
x
  
OUTPUT:
20
a
2
b
10
