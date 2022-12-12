# Dynamic librairies in c

A **dynamic library** or **shared library** or **shared object** is a file that is intended
to be shared by executable file or other shared objects.

Modules used by a program are loaded from individual shared objects into memory at load time
or runtime, rather than being copied by a linker when it creates a single monolithic executable
file for the program.

Shared libraries can be statically linked during compile-time, meaning that references to the
library modules are resolved and the modules are allocated memory when the executable file is created.

The dynamic linker is then responsible for loading the shared librairies at runtime.

## Dynamic linking

A dynamic linker is the part of an operating system that loads and links the shared
libraries needed by an executable when it is executed (at "run time"), by copying the
content of libraries from persistent storage to RAM, filling jump tables and relocating pointers.

## How to create a dynamic library ?

A dynamic library an be created at compile time, using a compiler. For c we can use the
gcc compiler.


### 1- Step one : compiling our library (assembly code, .o files)

```bash
gcc -c -Wall -Werror -fPIC <c_file_name1, c_file_name2, ...>
# this will create object files c_file_name1.o, c_file_name2.o ...
```

### 2- Step two: Creating a shared library from an object file.
```bash
gcc -shared -o <output_file.so> <object_file.o>
# This will create a shared object file, called output_file.so
```

**N.B**: The two step above can be combine in one step as follow :
```bash
gcc -fPIC -shared -o <shared_lib.so> <c_file1.c, c_file2.c, ...>
```

## How to use a dynamic library ?

We can link a shared object to our executable file, when compiling our
code that uses modules from the shared object.

```bash
gcc [-L<shared_lib_dir>] -Wall -o <exec_name> <source_name.c> -l<shared_lib_name>
```

And then to make the libray availble at compile time, we must add the path to our shared object in
the `$LD_LIBRARY_PATH` variable as follow :

```bash
export LD_LIBRARY_PATH=<path_to_shared_lib>:$LD_LIBRARY_PATH
```
