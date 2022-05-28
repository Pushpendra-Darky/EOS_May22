# **Embedded OS Assignments**

## **Day1**
 #### ***Learned Concept***
 - 2 Tier and 3 Tier Embedded Systems
- Hardware
  - CPU
    - PC/ IP
    - GPRs
    - Flags
    - Stack Pointer (SP)
  - Memory
    - Code
    - Data
  - Peripheral
- Bare Metal Systems
- SP, SF, Stack
  - SP - Register inside a CPU -> pointing to the top of stack
  - Stack - Chunk of memory
  - SF - Frame created on the Stack when you call a function. Deleted when you return from the function
- Frame Pointer - points to the base of the frame
- How are arguments passed to the function
  - Stack
  - Registers

#### ***Work Done***
- **Arith demo** Is Uploaded.


## Day2
#### ***Learned Concept***
 - Booting procedure
  - ROM BL
  - PBL
  - SBL (Uboot)
  - Kernel (Linux)
  - RFS (Buildroot)

#### ***Work Done***
- **Arith demo** Updated.


## Day3
#### ***Learned Concept***
- Makefile
- Toolchain

  - Build System
  - Host System
  - Target System

- Program

  - Program Sections
    - Text
    - Data
    - BSS
    - Heap
    - Stack

- Address Space

- Program vs Process

  - Program
    - Executable// Binary
    - Compiled
    - Dormant
  - Process
    - Thread
    - Process / Program under execution
    - Active

- OS

  - Process Management
  - Memory Management
  - I/O Management
    - Device Drivers
    - File System
    - Networking
    - GUI

- Kernel Mode vs User Mode

  - Kernel Mode aka Supervisor Mode
    - Kernel Space
    - Kernel Heap
    - Kernel Stack
  - User Mode
    - User Space
    - User Heap
    - User Stack

- Process ID (PID)

  - getpid()

- Man

  - man -k pid
  - man 2 getpid

- Process Control Block (PCB)

  - PID
  - Base Address of the Process
  - Size of the Address space

- Library Calls
- System Calls

- strace

- Differentiated between library and system call

- Shell

  - Command Line
  - Parsing
  - Built-in Commands
  - Shell Scripts

- Users and Groups

  - Users
    - User ID
    - Group ID
    - User Name
    - Group Name
    - Home Directory
    - Shell
  - Groups
    - Group ID
    - Group Name
    - Group Members

- Superuser

#### ***Work Done***
- **Arith Prog** Updated Using **Cross-Compiling** of **x86-64[Host]** for **Arm-64 architecture[Target]**.
- **Calculator** Program Uploaded Using **Makefile**.
- **Section Demo** Program is uploaded[Used **objdump** to see the section].
- **Process Identity[pid]** Program is uploaded[checked the process[system trace] by **pstree**].
- **Library Call & System Call** Program is uploaded[cheacked by **strace**].


## Day4
#### ***Learned Concept***
- Library

  - Static Libraries
    - .a
  - Dynamic Libraries aka Shared Object Libraries

    - Windows => .dll
    - Linux => .so

  - Standard Library
    - GCC -> libc.a / libc.so
    - Bundled as part of the compiler /toolchain
    - ANSI
    - eg. printf, strcpy, strlen, scanf, fopen
  - User Library/ Third Party Library
    - App Developer
    - eg. Your own arith functionality, mp3 decoding library

- Archive command to create and extract libraries

  - ar crv
  - ar x

- Assignment (Both: Static and Shared Object):

  - Repeat the demo shown in the class
  - Enhance the library to add mul and div functions
  - Update the library and send it to your friend to use it

- Syscalls

  - open, write and close
  - File Descriptors (fd)
  - Assignment: 1
    - Create a file
    - Write to the file
    - Close the file
  - Assignment: 2
    - Create a file
    - Read from the file
    - Print it on screen
    - Close the file
  - Explore
    - Return values for read and write system calls

#### ***Work Done***
- Uploaded **Static Library[.a]** Program.[Used  **(CC) -o EXE_NAME SRC_NAME -L. -l_LIB_NAME** On Other System ].
- Uploaded **Dynamic Library[.so]** Program.[Used **(CC) -o EXE_NAME SRC_NAME -L. -l_LIB_NAME** WITH **$ export LD_LIBRARY_PATH=.** Command On Other System ].
- Uploaded **System Call** Demo.[For Create,Write].
- Uploaded System Call Assignment 1 [For Create & Write ].
- Uploaded System Call Assignment 2 [For Create,Read & Print].


## Day5
#### ***Learned Concept***
- CPU (Uniprocessor)

  - Physical Hardware => PC, SP, GPR, Flags

- One CPU -> One Process at any given instance
- One CPU => Multiple process

- Memory

  - Each process given a separate address space
  - Address space is divided into 2 parts:
    - Text
    - Data
    - BSS
    - Heap
    - Stack

- Context

  - Contents of the registers PC, SP, GPR, Flags
  - Context Saving
    - Physical registers to Logical Copy (in memory)
  - Context Restoring
    - Logical Copy to Physical registers
  - Context Switching
    - Save the current context
    - Scheduling
    - Restore the new context

- Process State Diagram
  - New
  - Ready
  - Running
  - Waiting/ Blocked
  - Terminated/ Exit

- Fork

#### ***Work Done***
- **Fork** Program Demo Uploaded.