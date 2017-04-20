#include "io.h"
#include "fbdriver.h"

/* The C function */
int kmain()
{
  char str[] = "Hello World! 123";
  char st[] = "bla";
  char s[] = " Haha blubb\nBla";
  CONSOLE_BACKGROUND_COLOR = FB_COLOR_CYAN;
  fb_clear(FB_COLOR_BLACK);
  fb_write(str, sizeof(str));
  fb_writeColor(st, sizeof(st), FB_COLOR_WHITE, FB_COLOR_GREEN);
  fb_writeColor(s, sizeof(s), FB_COLOR_WHITE, FB_COLOR_BLUE);

  //fb_write_cell(0, str, FB_COLOR_GREEN, FB_COLOR_WHITE);
  return 0;
}