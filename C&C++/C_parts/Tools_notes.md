# Some programs that can help or may be needed for C projects

## GCC 
***Compiler***
The GCC (GNU Compiler Collection) is a powerful tool used to compile programs written in languages like C, C++, and others.
### Installation
#### Linux
```bash
```

### Use
Example 1 (simple):
```shell
gcc code.c
# result: a.out
```
#### GCC stages
1.  Preprocessing
	- **Purpose**: The preprocessor prepares the source code for compilation by handling directives.
	- **Key Actions**:
        - Removes comments from the code.
        - Includes header files specified by `#include` directives.
        - Replaces macros defined by `#define` with their corresponding values.
    - **Command**: To stop after preprocessing and see the output, use:
	```bash
	gcc -E sourcefile.c -o preprocessed.c
	```
 1. Compilation
	- **Purpose**: This stage translates the preprocessed code into assembly language.
	- **Key Actions**:
		- Converts the preprocessed code into assembly code, which is a low-level representation of the program.
	- **Command**: To generate the assembly code, use:
	```bash
	gcc -S preprocessed.c -o assembly.s
	```
 3. Assembly
	- **Purpose**: The assembler converts the assembly code into machine code.
    - **Key Actions**:
        - Produces an object file (`.o`), which contains the machine code that the CPU can execute.
	- **Command**: To compile the assembly code into an object file, use:
    ```bash
    gcc -c assembly.s -o object.o
    ```
4. Linking
	- **Purpose**: The linker combines one or more object files into a single executable.
    - **Key Actions**:
        - Resolves references between object files and libraries.
        - Combines all necessary code into a final executable file.
	- **Command**: To link the object file and create an executable, use:
    ```bash
    gcc object.o -o executable
	```

##### Summary
```bash
# Preprocessing 
gcc -E sourcefile.c -o preprocessed.c 
# Compilation 
gcc -S preprocessed.c -o assembly.s 
# Assembly 
gcc -c assembly.s -o object.o 
# Linking 
gcc object.o -o executable
```

### Flags

| Flag                      | Use                                                                                                                                                                                           | Groub       |
| ------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------- |
| -o                        | specify the output file name at any stage                                                                                                                                                     | Compilation |
| -E -S -c                  | [GCC stages](#gcc-stages)                                                                                                                                                                     | Compilation |
| -Wall                     | enable all compiler warnings                                                                                                                                                                  | Error check |
| -Werror                   |  treat warnings as errors                                                                                                                                                                     | Error check |
| -Wextra                   | nable additional warning messages that are not included with the `-Wall` option                                                                                                               | Error check |
| -std=<...><br>`-std=c11`  | specifies that the compiler should conform to the particular standard of the C programming language, in the example C11                                                                       | Compilation |
| -D<define_name>=\<value>  | a preprocessor directive that defines the macro with a specific value                                                                                                                         | code effect |
| -D_POSIX_C_SOURCE=200809L | defines the macro `_POSIX_C_SOURCE`, it is used to enable certain features of the POSIX (Portable Operating System Interface) standard in your C code                                         | code effect |
| -g                        | used to include debugging information in the compiled binary, this information is essential for debugging your program using tools like `gdb` (GNU Debugger) or other debugging environments. | Error check |

## Clang-format 
***Code Formatter*** (***code style***)
### Installation
#### Linux (example for ubuntu)
```bash
# last version
sudo apt-get install clang-format

# particuler version (17th) 
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 17
sudo apt install clang-format-17
```

### Use

| Language  | C     | C++                        | Objective-C | Objective-C++ | JavaScript | TypeScript | JSON  | Protobuf |
| --------- | ----- | -------------------------- | ----------- | ------------- | ---------- | ---------- | ----- | -------- |
| File type | .c .h | .cpp .cxx .cc .h .hpp .hxx | .m .h       | .mm           | .js        | .ts        | .json | .proto   |

```bash
# format code
clang-format -i <list_of_files>
# check the code format
clang-format -n <list_of_files>
# add the particular code style standart
clang-format -n --style=Google 
```



## CPP-check
 Static analysis tool for C and C++ code that helps identify bugs, undefined behavior, memory leaks, and other issues in your code.
 
### Use
```bash
# check headers or code files
cppcheck <list_of_files>
```

### Flags

| Flag                            | Use                                                                                                                                                                      |
| ------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| --enable=all                    | enables all available checks in cppcheck (checks for potential bugs, performance issues, style problems, etc)                                                            |
| --suppress=missingIncludeSystem | suppresses warnings about missing system include files                                                                                                                   |
| --force                         | forces cppcheck to analyze all files, even those that might not be recognized as C or C++ source files (if you want to ensure that all files in a directory are checked) |
| --checkers-report=\<file>       | This option specifies where to write the report of the checks                                                                                                            |


## Valgrind
A powerful programming tool used for memory debugging, memory leak detection, and profiling in programs written in languages like C and C++.

### Use
```bash
valgrind <way_to_executable_file>
#example: in the same foulder
valgrind ./<file>
```

####  Main Tools
Valgrind includes several tools, but the most commonly used one is **Memcheck**. Here’s a brief overview of some of the main tools:
1. **Memcheck**: The default tool for detecting memory-related errors. It checks for:    
    - Memory leaks
    - Invalid memory access
    - Use of uninitialized memory
    - Overlapping memory operations
2. **Cachegrind**: A cache profiler that helps you analyze cache usage and optimize your program's performance by providing insights into how your program interacts with the CPU cache.    
3. **Callgrind**: A call graph profiler that provides information about function call relationships and how much time is spent in each function, helping you identify performance bottlenecks.    
4. **Massif**: A heap profiler that helps you understand memory usage over time, allowing you to see how your program's memory consumption changes during execution.    
5. **Helgrind**: A tool for detecting data races in multi-threaded programs.    
6. **DRD**: Another tool for detecting data races and other threading issues.
7. 
### Flags
    
3. **`--show-leak-kinds=all`**: This option instructs Valgrind to show all kinds of memory leaks, including:
    
    - **Definitely lost**: Memory that was allocated but cannot be accessed anymore (i.e., no pointers to it).
    - **Indirectly lost**: Memory that is still accessible through other lost memory.
    - **Possibly lost**: Memory that might be lost, but there are still pointers to it.
    - **Still reachable**: Memory that is still accessible when the program exits but was not freed.
4. **`--track-origins=yes`**: This option enables tracking of the origins of uninitialized values. It helps you identify where uninitialized memory was allocated, which can be very useful for debugging.
    
5. **`--verbose`**: This option increases the verbosity of the output, providing more detailed information about what Valgrind is doing and the issues it finds.
    
6. **`--log-file=$(VALG_FILE)`**: This option specifies the file where Valgrind will write its output. The `$(VALG_FILE)` is a shell variable that should contain the path to the output file. You would typically set this variable in your shell or script before running the command, like so:

| Flag                              | Use                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| --------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| --tool=<...><br>`--tool=memcheck` | Specifies which tool to be used, in the example - Memcheck tool.                                                                                                                                                                                                                                                                                                                                                                                                                   |
| --leak-check=full                 | Tells Valgrind to perform a detailed analysis of memory leaks, it will provide information about each leak, including the size and location of the allocated memory that was not freed.                                                                                                                                                                                                                                                                                            |
| --show-leak-kinds=all             | Instructs Valgrind to show all kinds of memory leaks, including:    <br>    - **Definitely lost**: Memory that was allocated but cannot be accessed anymore (i.e., no pointers to it).<br>    - **Indirectly lost**: Memory that is still accessible through other lost memory.<br>    - **Possibly lost**: Memory that might be lost, but there are still pointers to it.<br>    - **Still reachable**: Memory that is still accessible when the program exits but was not freed. |
| --track-origins=yes               | Enables tracking of the origins of uninitialized values - helps identify where uninitialized memory was allocated, which can be very useful for debugging.                                                                                                                                                                                                                                                                                                                         |
| -log-file=\<file>                 | Specifies the file where Valgrind will write its output.                                                                                                                                                                                                                                                                                                                                                                                                                           |

## Check library
* [Checking function list](https://libcheck.github.io/check/doc/check_html/check_4.html#Convenience-Test-Functions)
