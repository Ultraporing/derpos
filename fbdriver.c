#include "fbdriver.h"

static unsigned int cur = 0;
unsigned int CONSOLE_BACKGROUND_COLOR = FB_COLOR_BLACK;

void fb_move_cursor(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

/** fb_write_cell:
  *  Writes a character with the given foreground and background to position i
  *  in the framebuffer.
  *
  *  @param i  The location in the framebuffer
  *  @param c  The character
  *  @param fg The foreground color
  *  @param bg The background color
  */
void fb_write_cell(unsigned int i, char c[], unsigned char fg, unsigned char bg)
{
    char key = c[i];
    if (key != 0){
        char *fb = (char *) 0x000B8000;
        fb[i * 2] = key;
        fb[i * 2 + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
        i++;
        fb_write_cell(i, c, fg, bg);
    }
}

unsigned int cursor_target(unsigned int newVal) {
  if (newVal >= FB_ROWS*FB_COLUMNS) {
    return newVal - FB_ROWS*FB_COLUMNS;
  }
  
  return newVal;
}

int fb_write(char* buf, unsigned int len) {
  char *fb = (char *) 0x000B8000;

  for (unsigned int count = 0; count < len; count++) {
    char key = buf[count];

    if (key == '\n')
    {
      fb_lineBreak();
    }
    else 
    {
      fb[cur * 2] = key;
      fb[cur * 2 + 1] = ((CONSOLE_BACKGROUND_COLOR & 0x0F) << 4) | (FB_COLOR_WHITE & 0x0F);

      if (count != len-1) {
        unsigned int tc = cursor_target(cur+1);
        fb_move_cursor(tc);
        cur = tc;
      }
    }
  }
  
  fb[cur * 2] = ' ';
  fb[cur * 2 + 1] = ((CONSOLE_BACKGROUND_COLOR & 0x0F) << 4) | (FB_COLOR_WHITE & 0x0F);
  unsigned int tc = cursor_target(cur);
  fb_move_cursor(tc);
  cur = tc;

  return cur;
}

int fb_writeColor(char* buf, unsigned int len, unsigned char fg, unsigned char bg) {
  char *fb = (char *) 0x000B8000;

  for (unsigned int count = 0; count < len; count++) 
  {
    char key = buf[count];

    if (key == '\n')
    {
      fb_lineBreak();
    }
    else
    {
      fb[cur * 2] = key;
      fb[cur * 2 + 1] = ((bg & 0x0F) << 4) | (fg & 0x0F);

      if (count != len-1) {
        unsigned int tc = cursor_target(cur+1);
        fb_move_cursor(tc);
        cur = tc;
      }
    }
  }

  fb[cur * 2] = ' ';
  fb[cur * 2 + 1] = ((CONSOLE_BACKGROUND_COLOR & 0x0F) << 4) | (FB_COLOR_WHITE & 0x0F);
  unsigned int tc = cursor_target(cur);
  fb_move_cursor(tc);
  cur = tc;

  return cur;
}

void fb_clear() {
  char clArr[FB_ROWS*FB_COLUMNS];

  for (int i = 0; i < FB_ROWS*FB_COLUMNS; i++){
    clArr[i] = ' ';
  }

  fb_writeColor(clArr, FB_ROWS*FB_COLUMNS, FB_COLOR_WHITE, CONSOLE_BACKGROUND_COLOR);
  cur = 0;
  fb_move_cursor(0);
}

void fb_lineBreak() {
  unsigned int cToEnd = FB_COLUMNS - cur + 1;

  char chArr[cToEnd];
  for (unsigned int i = 0; i < cToEnd; i++) 
  {
    chArr[i] = ' ';
  }

  fb_writeColor(chArr, cToEnd, FB_COLOR_WHITE, CONSOLE_BACKGROUND_COLOR);
}