# Evidence Management System

## Project Overview
This project provides a command-line interface for managing a database of categorized evidence. The program supports basic CRUD (Create, Read, Update, Delete) operations on evidence data, organized with custom dynamic array structures in C. This program leverages dynamic memory allocation to create resizable arrays.

## Project Files
  - `defs.h`: Contains all necessary declarations and definitions used across the source files.
  - `main.c`: Contains the main function, handles program flow, and user interaction.
  - `evidence.c`: Manages the evidence database functions, including add, remove, and display operations.
  - `init.c`: Handles initialization routines for the program's data structures.

## Prerequisites
- **CLion IDE**: Recommended for compilation and debugging.
- **GCC Compiler**: Ensure GCC is installed, or configure CLion to use a suitable C compiler.

## Compilation
To compile the project manually using GCC, run the following command:
  gcc main.c init.c evidence.c -o A3.out

In CLion, simply load the project and run the build configuration.

## Launching the Program
After compilation, execute the following command in the terminal:
  ./A3.out


## Usage Instructions
Upon launching, the program will prompt the user with the following options:

1. **0**: Exit the program.
2. **1**: Add a piece of evidence.
3. **2**: Remove a piece of evidence.
4. **3**: Print all evidence records.

### Operation Details
1. **Adding Evidence**:
   - Select option `1`.
   - Enter the following information when prompted:
     - **Evidence ID**: A unique identifier for the evidence.
     - **Room Name**: The room where the evidence was found.
     - **Device Code**: Enter `1` for EMF, `2` for THERMAL, or `3` for SOUND.
     - **Evidence Value**: Numeric value representing the evidence data.
     - **Timestamp**: Enter as hours, minutes, and seconds separated by spaces.
  
2. **Removing Evidence**:
   - Select option `2`.
   - Enter the **Evidence ID** of the record you wish to remove.
   - The program will confirm the removal if successful or return an error if the ID does not exist.

3. **Displaying All Evidence**:
   - Select option `3` to print all evidence currently stored in the database.

## Project Goals
This project demonstrates the use of dynamic memory and custom array structures in C to manage a simple database. It also emphasizes working with user input, handling errors gracefully, and practicing good memory management.
