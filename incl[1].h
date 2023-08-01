#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define ANSI_COLOR_DARK_GRAY 	"\e[0;36m"
#define ANSI_COLOR_GREEN	  "\e[0;32m"
#define ANSI_COLOR_ORANGE	  "\e[4;33m"
#define ANSI_COLOR_YELLOW	  "\e[1;93m"

int concint(int x,int y) {
  int m=10;
  while(y/m>0)
    m*=10;
  return  y+m*x;
}

