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
- **Arith Prog** Updated Using **Cross-Compiling** of **x86-64 [ Host ] ** for **Arm-64 architecture [ Target ] **.
- **Calculator** Program Uploaded Using **Makefile**.
- **Section Demo** Program is uploaded[ Used **objdump** to see the section ].
- **Process Identity [ pid ] ** Program is uploaded [ checked the process [ system trace ] by **pstree** ].
- **Library Call & System Call** Program is uploaded [ cheacked by **strace** ].


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

#### ***Assignment (Both: Static and Shared Object):***

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
- Uploaded **Static Library [.a]** Program.[Used  **(CC) -o EXE_NAME SRC_NAME -L. -l_LIB_NAME** On Other System ].
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


## Day6
#### ***Learned Concept***
- Fork

  - Zombie Processes
  - Orphan Processes
  - Child inherits file descriptors from the parent

- Batch Systems
- Multiuser Systems
- Multiprogramming
- Multitasking Systems
- Multiprocessing Systems
- Multithreading Systems

- Process Scheduling

  - Round Robin
  - Priority
  - FIFO
  - Shortest Job First

- Priority Based Scheduling

  - Preemptive Scheduling
  - Non-Preemptive Scheduling

- Shortest Job First

  - Preemptive Scheduling
  - Non-Preemptive Scheduling

- Response Times
- Throughput

#### ***Work Done***
- **Fork** Program Is Implemented By Using getpid() & getppid()..
- **Zombie** Program Is Uploaded Using **Fork** To Create Child Process[Die/Exit Before Its Parent Proccess] Corresponding to Its Parent Process[Used Sleep()].
- **Orphan** Program Is Uploaded Using **Fork** To Create Child Process[Used Sleep()] Corresponding to Its Parent Process[Die/Exit First Before Child Process]. 

## Day7
#### ***Learned Concept***
- Interprocess Communication
  - Pipes
    - Unidrectional
    - Related processes
    - Data is Sequential
    - pipe, read, write, close
  - FIFO aka Named Pipes
    - Unidirectional
    - Unrelated processes
    - Data is Sequential
    - open, read, wirte, close

- POSIX Threads


#### ***Assignment***

1. Write your own utility using system calls (open, read, write, close) to copy data from one file to another file. Essentially you are implementing a copy utility. Fullfledged utility should support the following options:

- Handling all the errors
- cp srcfile destfile

2. Write your own utility using library calls (fopen, fread, fwrite, fclose) to copy data from one file to another file. Essentially you are implementing a copy utility. Fullfledged utility should support the following options:

- Handling all the errors
- cp srcfile destfile

3. Research

- Which of the following programs took more time to copy file
  1. Small
  2. Medium
  3. Large
- Justify your results => Why does system call / library call take time to copy file.

#### ***Work Done***
- **PIPE** Program Is Uploaded[ Used PIPE For IPC B/W **RELATED PROCESS** ]
- **FIFO** Program Is Uploaded[ Used FIFO For IPC B/W **UNRELATED PROCESS** ]
  - Created FIFO File By $ mkfifo -m 0660 fifofile[0660 ie for READ,WRITE ]
- **THREAD** Program Is Uploaded[ Used $ gcc -o executable source -lpthread ]
#### ***Assignment Uploaded***
- Assignment 1 Program Uploaded [ Creating Copy Utility Using System Call To Copy Data From Src To Dest file ]
- Assignment 2 Program Uploaded [ Creating Copy Utility Using Library Call To Copy Data From Src To Dest file ]


## Day8
#### ***Learned Concept***
- POSIX Threads

  - pthread_create
  - pthread_join

- Threads

  - Joinable and Detachable

- Thread Attributes

  - pthread_attr_init
  - pthread_attr_setdetachstate
  - pthread_attr_destroy
  - Scope
  - Inherit Scheduling
  - Scheduling Parameters
  - Stack and Stack Size

- Threads

  - are light weight processes
  - TCB
  - Threads share the following sections with Process
    - Text
    - Data
    - BSS
    - Heap
  - Threads do not share the following sections with Process
    - Stack
    - means that each threads has its own stack

- Resource
  - Anything that is used by a thread or a process is called a resource
  - Shared Resource
    - Resource that is shared between multiple threads/ processes
    - Race Condition => Data corruption

#### ***Work Done***
- **Thread** Program Is Implemented.
  - Uploaded **Joinable**[By Default Thread Is Joinable] And **Detachable** Thread Programs.

- Race Condition[Data curruption] Program Is Uploaded.
