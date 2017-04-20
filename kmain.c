#include "io.h"
#include "fbdriver.h"

/* The C function */
int kmain()
{
  char str[] = "Hello World! 123";
  char st[] = "bla";
  char s[] = " Haha blubb\nBla";
  
  fb_clear(FB_COLOR_BLACK);
  write(str, sizeof(str));
  writeColor(st, sizeof(st), FB_COLOR_WHITE, FB_COLOR_GREEN);
  writeColor(s, sizeof(s), FB_COLOR_WHITE, FB_COLOR_BLUE);

  //fb_write_cell(0, str, FB_COLOR_GREEN, FB_COLOR_WHITE);
  return 0;
}