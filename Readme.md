# Dolly

Creation of graphic interfaces with zero memory leaks (Used Valgrind as
tool for generate the reports).

## Objectives

- Allow the use of an API for the creation of a graphical interface that
 does not suffer from memory leaks.
 
## Requirements

- X11 (Unix)
- CMake
- Compiler C++17

## Windows

Not exist support to Window only to Unix (X11)

## Commands

Clone this repository
```
mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
make
./Dolly
```