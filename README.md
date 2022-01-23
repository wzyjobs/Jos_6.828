# Exercise
#### Exercise 1
```
[Steps]
1. Familiarize yourself with the assembly language materials available on the 6.828 reference page. 
You don't have to read them now, but you'll almost certainly want to refer to some of this material when reading and writing x86 assembly.
We do recommend reading the section "The Syntax" in Brennan's Guide to Inline Assembly. 
It gives a good (and quite brief) description of the AT&T assembly syntax we'll be using with the GNU assembler in JOS.

[What should i learn in this exercise ?]
1. AT&T Assembly language
2. The PC's Physical Address Space
3. The ROM BIOS
4. How to debug a kernel

[Questions]
N/A
```
#### Exercise 2
```
[Steps]
1. Use GDB's si (Step Instruction) command to trace into the ROM BIOS for a few more instructions, 
and try to guess what it might be doing. You might want to look at Phil Storrs I/O Ports Description, 
as well as other materials on the 6.828 reference materials page. No need to figure out all the details 
- just the general idea of what the BIOS is doing first. 

[What should i learn in this exercise ?]
1. The ROM BIOS load flow.
2. How to transfer from 16-bit to 32-bit ?
3. How to transfer from 16-bit to 20-bit ?
4. Why ROM BIOS code need to block all instructions when initializing ?

[Questions]

```
#### Exercise 3
```
[Steps]
1.Take a look at the lab tools guide, especially the section on GDB commands. 
Even if you're familiar with GDB, this includes some esoteric GDB commands that are useful for OS work.
Set a breakpoint at address 0x7c00, which is where the boot sector will be loaded. 
Continue execution until that breakpoint. 
Trace through the code in boot/boot.S, using the source code and the disassembly file obj/boot/boot.asm to keep track of where you are. 
Also use the x/i command in GDB to disassemble sequences of instructions in the boot loader, and compare the original boot loader source code with both the disassembly in obj/boot/boot.asm and GDB.
Trace into bootmain() in boot/main.c, and then into readsect(). 
Identify the exact assembly instructions that correspond to each of the statements in readsect(). 
Trace through the rest of readsect() and back out into bootmain(), and identify the begin and end of the for loop that reads the remaining sectors of the kernel from the disk. 
Find out what code will run when the loop is finished, set a breakpoint there, and continue to that breakpoint. Then step through the remainder of the boot loader.

[What should i learn in this exercise ?]
1. The Boot Loader

[Questions]
1. At what point does the processor start executing 32-bit code? What exactly causes the switch from 16- to 32-bit mode? 
   Answer: [f000:cf5d]    0xfcf5d: mov    %ecx,%cr0
2. What is the last instruction of the boot loader executed, and what is the first instruction of the kernel it just loaded?
   Answer: 
3. Where is the first instruction of the kernel?
   Answer:
4. How does the boot loader decide how many sectors it must read in order to fetch the entire kernel from disk? Where does it find this information?
```

#### Exercise 4
```
[Steps]
1.Read about programming with pointers in C. 
The best reference for the C language is The C Programming Language by Brian Kernighan and Dennis Ritchie (known as 'K&R'). 
We recommend that students purchase this book (here is an Amazon Link) or find one of MIT's 7 copies.

Read 5.1 (Pointers and Addresses) through 5.5 (Character Pointers and Functions) in K&R. 
Then download the code for pointers.c, run it, and make sure you understand where all of the printed values come from. 
In particular, make sure you understand where the pointer addresses in printed lines 1 and 6 come from, 
how all the values in printed lines 2 through 4 get there, and why the values printed in line 5 are seemingly corrupted.

There are other references on pointers in C (e.g., A tutorial by Ted Jensen that cites K&R heavily), though not as strongly recommended.

Warning: Unless you are already thoroughly versed in C, do not skip or even skim this reading exercise. 
If you do not really understand pointers in C, you will suffer untold pain and misery in subsequent labs, 
and then eventually come to understand them the hard way. Trust us; you don't want to find out what "the hard way" is.

[What should i learn in this exercise ?]
1.What is ELF?

[Questions]
```

#### Exercise 5
```
[Steps]
1.Trace through the first few instructions of the boot loader again and identify the first instruction that would "break" or otherwise do the wrong thing if you were to get the boot loader's link address wrong. 
Then change the link address in boot/Makefrag to something wrong, run make clean, recompile the lab with make, 
and trace into the boot loader again to see what happens. Don't forget to change the link address back and make clean again afterward!

[What should i learn in this exercise ?]
1. Why the address of kernel should be 0x7C00 ? What will happen if we change this address to 0x7e00 ?

[Questions]
```

#### Exercise 6
```
[Steps]
1. We can examine memory using GDB's x command. 
The GDB manual has full details, but for now, it is enough to know that the command x/Nx ADDR prints N words of memory at ADDR. 
(Note that both 'x's in the command are lowercase.) Warning: The size of a word is not a universal standard. 
In GNU assembly, a word is two bytes (the 'w' in xorw, which stands for word, means 2 bytes).

Reset the machine (exit QEMU/GDB and start them again). 
Examine the 8 words of memory at 0x00100000 at the point the BIOS enters the boot loader, and then again at the point the boot loader enters the kernel. 
Why are they different? What is there at the second breakpoint? (You do not really need to use QEMU to answer this question. Just think.)

[What should i learn in this exercise ?]

[Questions]
```

#### Exercise 7
```
[Steps]

[What should i learn in this exercise ?]

[Questions]
```

#### Exercise 8
```
[Steps]
1. Challenge: colorful console
    Due to Windows cant provide hardware simulator so will do it later.
     
[What should i learn in this exercise ?]

[Questions]
1. Explain the interface between printf.c and console.c. 
Specifically, what function does console.c export? How is this function used by printf.c?
    Answer: 
    1.console.c export 
        void cputchar(int c);
        int getchar(void);
        int iscons(int fd);
    2. void cputchar(int c); used in printf.c

2. Explain the following from console.c:
` if (crt_pos >= CRT_SIZE) {
      int i;
      memmove(crt_buf, crt_buf + CRT_COLS, (CRT_SIZE - CRT_COLS) * sizeof(uint16_t));
      for (i = CRT_SIZE - CRT_COLS; i < CRT_SIZE; i++)
              crt_buf[i] = 0x0700 | ' ';
      crt_pos -= CRT_COLS;
}`

      
3. For the following questions you might wish to consult the notes for Lecture 2. 
These notes cover GCC's calling convention on the x86.
Trace the execution of the following code step-by-step:
    · int x = 1, y = 3, z = 4;
    · cprintf("x %d, y %x, z %d\n", x, y, z);
In the call to cprintf(), to what does fmt point? 
To what does ap point?
List (in order of execution) each call to cons_putc, va_arg, and vcprintf. 
For cons_putc, list its argument as well. For va_arg, list what ap points to before and after the call. 
For vcprintf list the values of its two arguments.

4. Run the following code.
    `unsigned int i = 0x00646c72;
     cprintf("H%x Wo%s", 57616, &i);`
What is the output? 
Explain how this output is arrived at in the step-by-step manner of the previous exercise. 
Here's an ASCII table that maps bytes to characters.
The output depends on that fact that the x86 is little-endian. 
If the x86 were instead big-endian what would you set i to in order to yield the same output? 
Would you need to change 57616 to a different value?

Here's a description of little- and big-endian and a more whimsical description.

5.In the following code, what is going to be printed after 'y='? (note: the answer is not a specific value.) 
Why does this happen?

    `cprintf("x=%d y=%d", 3);`
    
6.Let's say that GCC changed its calling convention so that it pushed arguments on the stack in declaration order, 
so that the last argument is pushed last. 
How would you have to change cprintf or its interface \
so that it would still be possible to pass it a variable number of arguments?
```

#### Exercise ?
```
[Steps]

[What should i learn in this exercise ?]

[Questions]
```
