# Some programs that can help or may be needed for C projects

## Contents
- [Contents](#contents)
- [GCC](#gcc)
- [GDB (the GNU Debugger)](#gdb-the-gnu-debugger)
- [Clang-format](#clang-format)
- [CPP-check](#cpp-check)
- [Valgrind](#valgrind)
- [Check library](#check-library)
- [Google Test framework (gtest)](#google-test-framework-gtest)
- [Makefile](#makefile)
- [CMake](#cmake)
- [Gcov and Gcovr](#gcov-and-gcovr)
- [Git](#git)
- [Doxygen (automatic documentation generation)](#doxygen-automatic-documentation-generation)
- [Notes](#notes)
  - [Ultimate installation - Ubuntu](#ultimate-installation---ubuntu)
  - [Links](#links-1)

## GCC 
***Compiler***
The GCC (GNU Compiler Collection) is a powerful tool used to compile programs written in languages like C, C++, and others.

| Compiler | Language |
| --------- | -------- |
| g++       | C++      |
| gcc       | C        |

### Installation
#### Linux (Ubuntu)
```bash
sudo apt install gcc   
sudo apt install g++    
```
### Use
Example 1 (simple):
```shell
gcc code.c
g++ code.cpp
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
	g++ -E sourcefile.cpp -o preprocessed.i
	```
 1. Compilation
	- **Purpose**: This stage translates the preprocessed code into assembly language.
	- **Key Actions**:
		- Checks for syntax errors 
		- Converts the preprocessed code into assembly code, which is a low-level representation of the program.
	- **Command**: To generate the assembly code, use:
	```bash
	gcc -S preprocessed.c -o assembly.s
	g++ -S preprocessed.i -o assembly.s
	```
 3. Assembly
	- **Purpose**: The assembler converts the assembly code into machine code.
    - **Key Actions**:
        - Produces an object file (`.o`), which contains the machine code that the CPU can execute.
	- **Command**: To compile the assembly code into an object file, use:
    ```bash
    gcc -c assembly.s -o object.o
    g++ -c assembly.s -o object.o
    ```
4. Linking
	- **Purpose**: The linker combines one or more object files into a single executable.
    - **Key Actions**:
        - Resolves references between object files and libraries.
        - Combines all necessary code into a final executable file.
	- **Command**: To link the object file and create an executable, use:
    ```bash
    gcc object.o -o executable
    g++ object.o -o executable
	```

##### Summary
```bash
# C
# Preprocessing 
gcc -E sourcefile.c -o preprocessed.c 
# Compilation 
gcc -S preprocessed.c -o assembly.s 
# Assembly 
gcc -c assembly.s -o object.o 
# Linking 
gcc object.o -o executable

# C++
# Preprocessing
g++ -E sourcefile.cpp -o preprocessed.i
# Compilation 
g++ -S preprocessed.i -o assembly.s
# Assembly 
g++ -c assembly.s -o object.o
# Linking 
g++ object.o -o executable
```


### Flags

| Flag                                     | Use                                                                                                                                                                                           | Group       |
| ---------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------- |
| -o                                       | specify the output file name at any stage                                                                                                                                                     | Compilation |
| -E -S -c                                 | [GCC stages](#gcc-stages)                                                                                                                                                                     | Compilation |
| -Wall                                    | enable all compiler warnings                                                                                                                                                                  | Error check |
| -Werror                                  |  treat warnings as errors                                                                                                                                                                     | Error check |
| -Wextra                                  | handle additional warning messages that are not included with the `-Wall` option                                                                                                               | Error check |
| -std=<...><br>`-std=c11`<br>`-std=c++11` | specifies that the compiler should conform to the particular standard of the C/C++ programming language (examples: C11 and C++11)                                                             | Compilation |
| -D<define_name>=\<value>                 | a preprocessor directive that defines the macro with a specific value                                                                                                                         | code effect |
| -D_POSIX_C_SOURCE=201706L                | defines the macro `_POSIX_C_SOURCE`, it is used to enable certain features of the POSIX (Portable Operating System Interface) standard in your C code                                         | code effect |
| -g                                       | used to include debugging information in the compiled binary, this information is essential for debugging your program using tools like `gdb` (GNU Debugger) or other debugging environments. | Error check |
| -I                                       | a compiler flag for gcc and g++ that ADDs a folder to the list of include search paths - tells where to look for headers (```g++ main.cpp -I./include```) | Compilation |

## GDB (the GNU Debugger)
The GNU Debugger (GDB) is a tool used to debug programs, mainly C and C++.

### Abilities:
- it runs program step by step to find crashes and bugs
- shows which line caused the error
- lets user inspect variables, memory, and call stack
- helps track segmentation faults and logic bugs
- when running program under debugger user can:
  - pause execution
  - set breakpoints
  - step through code line by line
  - print variable values
  - see the function call history (```bt – backtrace```)
  
### Usage  
- Example for Viewer3D file
  1. ```gdb ./build/Viewer3D``` -Start the debugger and load your program:
  2. ```run``` - Inside gdb, this command starts running the program.
  3. When the program crashes (for example, segmentation fault), **gdb** will catch the crash instead of the program exiting normally.
  4. ```bt``` after crash will show:
     - Which function crashed
     - From which function it was called
     - Full stack trace
  5. Output example:
        ```
        #0  Foo::bar() at foo.cpp:42
        #1  main() at main.cpp:10
        ```


## Clang-format 
***Code Formatter*** ([***code style***](/C&C++/Parts/Code_style_notes.md))
- Can do the code compilation;
- Can be used for **code formatting**. Can automatically format C, C++, Java, JavaScript, Python, etc.
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

### Installation 
#### Linux (ubuntu)
```Shell
sudo apt install cppcheck 
```
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

### Installation
#### Linux (Ubuntu)
```Shell
sudo apt valgrind 

```

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
Check is a unit testing framework designed for C programming. It provides a simple interface for defining unit tests, allowing developers to focus on writing tests without much overhead. Tests are executed in a separate address space, which helps catch assertion failures and errors like segmentation faults.

### Installation
#### Linux (Ubuntu)
```Shell
sudo apt-get install check 
```

### Use
Added to a c file as a library allow to use functions to compare output or result of execution of your functions with prepared values or results of calculation.

#### [Example](/C&C++/materials/C/tetris_tests.c)
* see [Notes/links](#links-1)

### Links
* [Checking function list](https://libcheck.github.io/check/doc/check_html/check_4.html#Convenience-Test-Functions)

## Google Test framework (gtest)
It's a framework that is mainly used to create unit tests of a C++ code. 

### Use
#### Way #1
The test cpp-file includes: 
- The main function, which is the entry point for the program at the end of the file:
    ```C++
    int main(int argc, char** argv) { 
        ::testing::InitGoogleTest(&argc, argv); //This initializes the Google Test framework.
        return RUN_ALL_TESTS();                 //This function runs all the tests that have been defined using the Google Test framework.
    }
    ```
- Test functions:
```C++
    TEST(MatrixTest, destructor) { // name of the tests block, name of the test
    matrix::Matrix matrix(4, 5);
    EXPECT_EQ(matrix.getRows(), 4);
    EXPECT_EQ(matrix.getCols(), 5);
    EXPECT_NE(matrix.getMatrix(), nullptr);
    matrix.~Matrix();
    EXPECT_EQ(matrix.getRows(), 0);
    EXPECT_EQ(matrix.getCols(), 0);
    EXPECT_EQ(matrix.getMatrix(), nullptr);
    }
```
#### Way #2
The main function can be not included in the test file -default main function will be provided by Gtest automatically. 

### Info 
[Assertions Reference](https://google.github.io/googletest/reference/assertions.html)

### Example 
[Example #1](/C&C++//materials/CPP/model3d_tests.cpp)


## Makefile
A `Makefile` is a special file used by the `make` build automation tool to compile and link programs. It contains rules defining how to build your project, including which files need to be compiled and how to link them together.

### Installation
#### Linux (Ubuntu)
```Shell
 sudo apt install make  
```
### Use
Can be used via terminal from the folder where Makefile is located: ```make <target> ```.

#### Basic Structure of a Makefile
A simple Makefile typically includes:
- **Variables**: For compiler, flags, and source files.
- **Targets**: The output files or actions.
- **Rules**: Instructions on how to build the targets.

Here’s a simple example of a Makefile for a C project that consists of multiple source files:
```Makefile
# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -g
# Linker flags (if needed)
LDFLAGS = 

# Source files
SRCS = main.c utils.c math_operations.c
# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)
# Executable name
TARGET = my_program

# Default target
all: $(TARGET)
# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
    
# Phony targets
.PHONY: all clean
```

- -**.PHONY**: This tells `make` that `all` and `clean` are not files but commands.


#### [Example](/C&C++/materials/C/Makefile)
* see [Notes/links](#links-1)

### Tips and structure

| Point  | Example                                                   | Description                                                                                             |
| ------ | --------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| `@`    | `@rm -f $(OBJS) $(TARGET)`                                | silence the calling of the command in terminal                                                          |
| `make` | `clean: clean_a`<br>    `rm -f $(STH)`<br>	`make clean_b` | Make targets can be called inside other make targets                                                    |
| `-s`   | `clean: clean_a`<br>`rm -f $(STH)`<br>`make -s clean_b`   | To suppress the entering and leaving directory messages, you can run make with the -s option like this: |

### Comments
It's a good practice to leave comments in the beginning of the Makefile that include project's name and info about goals this file include.
#### Example:
```Makefile
# ----------------------------------------------------------------------
# Makefile for MyProject
# ----------------------------------------------------------------------
#
# Purpose:
#   This Makefile automates the build, clean, and testing processes
#   for the MyProject application. It compiles source code, links
#   libraries, and generates the final executable.
#
# Key Targets:
#   all      - Builds the project (default target).
#   clean    - Removes all build artifacts (e.g., object files, binaries).
#   test     - Runs the test suite to ensure code correctness.
#
# Usage:
#   To build the project:       make
#   To clean the build:         make clean
#   To run tests:               make test
#
# Notes:
#   - Requires GNU Make version 4.0 or later.
#   - Ensure all dependencies are installed before building.
#   - See the README.md for more details about the project.
#
# ----------------------------------------------------------------------
```

## CMake
CMake is a build system generator. Unlike Makefiles, which define explicit build rules, CMake generates platform-specific build scripts (e.g., Makefiles, Ninja files, Visual Studio solutions) based on a high-level description.

### Structure
- CMake can automatically create building rules for different systems.
- CMake organizes builds using targets. Each target can be:
  - Executable (add_executable)
  - Library (add_library)
  - Alias or Interface (for modular projects)
- CMake allows setting compilation flags that will be active for all the goals
- CMake has default goals (like ```install```) with preset parameters and executing (building) standards.
  - CMakelists.txt:
    ```
    install(TARGETS my_program RUNTIME DESTINATION bin)
    install(TARGETS mylib LIBRARY DESTINATION lib)
    install(FILES mylib.h DESTINATION include)
    ```
  - Build & install:
    ```bash
    cmake --install build --prefix /usr/local
    ```
- CMake defines many built-in variables:
  - **CMAKE_SOURCE_DIR**: Root source directory.
  - **CMAKE_BINARY_DIR**: Root binary directory.
  - **CMAKE_CURRENT_SOURCE_DIR**: Current directory being processed.
  - **CMAKE_CURRENT_BINARY_DIR**: Build directory for the current source directory.
- Custom variables:
    ```
    set(MY_VAR "Hello, World!")
    message(STATUS "My variable: ${MY_VAR}")
    ```
- CMake allows looking for a component installed at the PC or bring some of them from the net using links
  - ```find_package(Qt6 COMPONENTS ...)```
- Some IDEs create ***CMakeLists.txt.user*** file that stores some settings for running project with IDE. THIS FILE MUST NEVER BE PUSHED TO REMOTE REPOSITORY.
- CMake has different module that can be added and used.
  - Example: ```include(GNUInstallDirs)``` - sets a series of standardized install directory variables that follow conventional Linux filesystem layout. These variables let your project be portable and install-friendly across platforms and distros.


### Usage
1. Create a ***CMakeLists.txt*** file in the project directory (the best way is to have one global file and several smaller files in included folders - one for each included library or separate set of goals(life tests)).
2. Fill *CMakeLists.txt* with all the needed rules.
3. Run ```cmake /way_to_file/CMakeLists.txt``` from the directory where you want to build the project. It will generate Makefiles and other required files.
4. Run goals you need using cmake or Makefile or any other way you set in *CMakeLists.txt*.
    ```bash 
    cmake -S . -B build
    cmake --build build
    ./build/my_program
    ```


### Example
#### #1:Working with Multiple Components
Example: Libraries, Executables, and Tests
```
project_root/
 ├── CMakeLists.txt
 ├── src/
 │   ├── CMakeLists.txt
 │   ├── main.cpp
 │   ├── mylib.cpp
 │   ├── mylib.h
 ├── tests/
 │   ├── CMakeLists.txt
 │   ├── test_main.cpp
 ```

- Top-level CMakeLists.txt
    ```
    cmake_minimum_required(VERSION 3.10)
    project(MyProject LANGUAGES CXX)

    add_subdirectory(src)
    add_subdirectory(tests)
    ```
- src/CMakeLists.txt  
    ```
    add_library(mylib mylib.cpp)
    add_executable(my_program main.cpp)
    target_link_libraries(my_program PRIVATE mylib)
    ```
- tests/CMakeLists.txt  
    ```
    enable_testing()
    add_executable(test_main test_main.cpp)
    add_test(NAME MyTest COMMAND test_main)
    ```

Running Tests:  
    ```bash
    ctest --output-on-failure
    ```


#### #2: From [Viewer3D project](https://github.com/Georgiy-JO/Viewer3D)
- [Main CMakeLists.txt](/C&C++/materials/CPP/cmake_example/CMakeLists.txt)
  - [Tests CMakeLists.txt](/C&C++/materials/CPP/cmake_example/tests/CMakeLists.txt)
  - [Third part CMakeLists.txt](/C&C++/materials/CPP/cmake_example/third_party/CMakeLists.txt)

## Gcov and Gcovr
`gcov` and `gcovr` are tools used in C and C++ programming for code coverage analysis. They help developers understand which parts of their code are being exercised by tests, which can be crucial for improving test coverage and ensuring code quality.

#### **gcov**
`gcov` is a test coverage program that is part of the GNU Compiler Collection (GCC). It analyzes the execution of a program to determine which parts of the code were executed and how many times. It generates a report showing which lines of code were executed and which were not, providing a clear view of the test coverage.

#### **gcovr**
`gcovr` is a Python script that provides a convenient way to use `gcov` and generate coverage reports. It simplifies the process of running `gcov` and can produce reports in various formats, such as HTML, XML, and text. It can also aggregate coverage data from multiple source files.


### Installation
#### Linux (Ubuntu)
```Shell
  sudo apt-get install gcovr
  sudo apt-get install gcov 
```

### Use

1. **Compile your code with coverage flags:**  
	- `-fprofile-arcs` 
	- `-ftest-coverage`

```Bash	
gcc -fprofile-arcs -ftest-coverage -o my_program my_program.c
```
    
2. **Run your program:**   
    - Execute your program as you normally would. T
    - his will generate `.gcda` files that contain execution counts.
    
3. **Generate coverage reports:** 
    - Run `gcov` on your source file to generate a coverage report. 
    - This will create a `.gcov` file with the coverage information.
    
```bash
gcov my_program.c
```

4. **View the gcov report:** 
    - The `.gcov` file will contain the source code with annotations indicating which lines were executed and how many times.
    
4. **View the gcovr report:** 
    - Use `gcovr` to generate a coverage report.
```Shell
# to generate a simple text report:
gcovr 
# to generate an HTML report:
gcovr -r . --html --html-details -o coverage.html
```
- Here, `-r .` specifies the root directory for the report, and `--html` options create an HTML report.
#### Example

* see [Notes/links](#links-1)

## Git 
### Installation
#### Linux (Ubuntu)
```shell
sudo apt install git-all
```

### [Info](/DevOps/Git_notes.md)

## [Doxygen (automatic documentation generation)](/DevOps/Doc_notes.md)
## Notes
### Ultimate installation - Ubuntu
#### C
  ```Shell
    sudo apt update && sudo apt-get update
    sudo apt install valgrind cppcheck clang-format gcc g++ make git-all -y
    sudo apt-get install check gcovr -y
    sudo apt-get install gcov -y
  ```
### Links
[Example of the "Check" testing, Makefile and report creation](https://github.com/Georgiy-JO/te-tris_pet)
