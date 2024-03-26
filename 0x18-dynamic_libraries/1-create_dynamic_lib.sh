#!/bin/bash

# creates a dynamic library called liball.so from all the .c files that are in the current directory.
gcc -fPIC -shared -o liball.so *.c
