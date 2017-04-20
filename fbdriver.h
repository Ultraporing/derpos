 #ifndef INCLUDE_FBDRIVER_H
#define INCLUDE_FBDRIVER_H
#include "io.h"

#define FB_COLOR_BLACK 0
#define FB_COLOR_BLUE 1
#define FB_COLOR_GREEN 2
#define FB_COLOR_CYAN 3
#define FB_COLOR_RED 4
#define FB_COLOR_MAGENTA 5
#define FB_COLOR_BROWN 6
#define FB_COLOR_LIGHT_GREY 7
#define FB_COLOR_DARK_GREY 8
#define FB_COLOR_LIGHT_BLUE 9
#define FB_COLOR_LIGHT_GREEN 10
#define FB_COLOR_LIGHT_CYAN 11
#define FB_COLOR_LIGHT_RED 12
#define FB_COLOR_LIGHT_MAGENTA 13
#define FB_COLOR_LIGHT_BROWN 14
#define FB_COLOR_WHITE 15

#define FB_ROWS 25
#define FB_COLUMNS 80

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

/** fb_move_cursor:
  *  Moves the cursor of the framebuffer to the given position
  *
  *  @param pos The new position of the cursor
  */
void fb_move_cursor(unsigned short pos);

/** fb_write_cell:
  *  Writes a character with the given foreground and background to position i
  *  in the framebuffer.
  *
  *  @param i  The location in the framebuffer
  *  @param c  The character
  *  @param fg The foreground color
  *  @param bg The background color
  */
void fb_write_cell(unsigned int i, char c[], unsigned char fg, unsigned char bg);

void fb_clear(unsigned char color);

int write(char* buf, unsigned int len);

int writeColor(char* buf, unsigned int len, unsigned char fg, unsigned char bg);

#endif /* INCLUDE_IO_H */