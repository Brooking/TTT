# GDB Commands
## A cheat sheet for debugging with 'gdb'

* Launch
  *  $ **gdb** <executable file>

* Control Execution
  * start execution
    * (gdb) **r** \<command line arguments>
    * (gdb) **run** \<command line arguments>
  * continue execution (eg. after a break)
    * (gdb) **c**
    * (gdb) **continue**
  * quit execution
    * (gdb) **q**
    * (gdb) **quit**
  * run to next command (stepping *over* called functions)
    * (gdb) **n**
    * (gdb) **next**
  * step to next command (stepping *into* called functions)
    * (gdb) **s**
    * (gdb) **step**
  * step out of current function
    * (gdb) **finish**
  * step out of current loop
    * (gdb) **u**
    * (gdb) **until**

* Function Breakpoints
  * set a breakpoint at a given function
    * (gdb) **b** \<function name>
    * (gdb) **break** \<function name>
  * set a breakpoint at a given line in the currently broken into file
    * (gdb) **b** \<line number>
  * set a breakpoint at a spot in a file
    * (gdb) **b** \<filename>:\<line number>
  * see all of the current breakpoints
    * (gdb) **info break**
    * (gdb) **info breakpoints**
  * clear a breakpoint (using the breakpoint index given by **info break** above)
    * (gdb) **d** \<breakpoint index>
    * (gdb) **delete** \<breakpoint index>
  * clear a breakpoint (using same specifier as **set** above)
    * (gdb) **clear** \<specifier>

* Stack Frames
  * display the current stack
    * (gdb) **bt**
    * (gdb) **backtrace**
  * select a frame
    * (gdb) **f** \<frame number>
    * (gdb) **frame** \<frame number>
  * go up the stack
    * (gdb) **up** (# frames)
  * go down the stack
    * (gdb) **down** (# frames)
  * display the current stack frame
    * (gdb) **info f**
    * (gdb) **info frame**

* Show information
  * display arguments to the current function
    * (gdb) **info args**
  * display the local variables in the current scope
    * (gdb) **info locals**
  * print variable
    * (gdb) **p** \<variable>
    * (gdb) **print** \<variable>    
