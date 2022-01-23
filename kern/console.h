/* See COPYRIGHT for copyright information. */

#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#ifndef JOS_KERNEL
# error "This is a JOS kernel header; user programs should not #include it"
#endif

#include <inc/types.h>

#define MONO_BASE	0x3B4
#define MONO_BUF	0xB0000
#define CGA_BASE	0x3D4
#define CGA_BUF		0xB8000

#define CRT_ROWS	25
#define CRT_COLS	80
#define CRT_SIZE	(CRT_ROWS * CRT_COLS)

enum ASCII_COLOR {
    BLACK = 0x0000,
    BLUE = 0x0100,
    GREEN = 0x0200,
    CYAN = 0x0300,
    RED = 0x0400,
    MAGENTA = 0x0500,
    BROWN = 0x0600,
    LIGHT_GRAY = 0x0700,
    DARK_GRAY = 0x0800,
    LIGHT_BLUE = 0x0900,
    LIGHT_GREEN = 0x0A00,
    LIGHT_CYAN = 0x0B00,
    LIGHT_RED = 0x0C00,
    PINK = 0x0D00,
    YELLOW = 0x0E00,
    WHITE = 0x0F00
};

void cons_init(void);
int cons_getc(void);

void kbd_intr(void); // irq 1
void serial_intr(void); // irq 4

// set color for ascii charter
int setcolor(enum ASCII_COLOR color, int c);

#endif /* _CONSOLE_H_ */
