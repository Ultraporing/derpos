#define FB_BLACK 0
#define FB_BLUE 1
#define FB_GREEN 2
#define FB_CYAN 3
#define FB_RED 4
#define FB_MAGENTA 5
#define FB_BROWN 6
#define FB_LIGHT_GREY 7
#define FB_DARK_GREY 8
#define FB_LIGHT_BLUE 9
#define FB_LIGHT_GREEN 10
#define FB_LIGHT_CYAN 11
#define FB_LIGHT_RED 12
#define FB_LIGHT_MAGENTA 13
#define FB_LIGHT_BROWN 14
#define FB_WHITE 15

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

/* The C function */
int kmain()
{
  char str[] = "Hello World!";
  fb_write_cell(0, str, FB_GREEN, FB_WHITE);
  return 0;
}