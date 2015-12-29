/*ICON EDITOR */
#define TURBOC
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<bios.h>
#include<string.h>

#define IY 144
#define IX 240
#define XDIM 40
#define YDIM 32
#define XPAND 3

#define BCK_GND 4
#define FORE_GND 2
#define HIGHLIGHT 13

char getpoint(int x,int y),getkey(void);
void mode(int mode_code),gotoxy(int x,int y);
void clr_eol(int x,int y);
void palette(int pnum);
void display_grid(void),edit_icon(void);
void display_icon(int x,int y);
void init_icon (void);
int save_icon(void),load_icon(char *fname);
void putpoint(int x,int y,int color,int how);

struct icon_type {
  unsigned char image[XDIM][YDIM];//icon image
  void (*func)();/*pointer to function associated
		  with each icon*/
  int x,y; //X,Y coordinates
  }icon;

  char far *egabase;

  void main(int argc,char *argv[])
  {
   mode(16);
   /*initialize the pointer to the EGA/VGA video RAM. */
   #ifdef TURBOC
   egabase=(char far *) MK_FP(0xA000,0000);
   #endif
   #ifdef MICROSOFTC
   egabase=(char far *)0xA0000000;
   #endif

   printf("F1: pen down  F2: pen up  F3: save icon ");
   printf("F4: load icon  F5: erase  F6: quit");

   init_icon();//initialize  the icon
   if(argc==2) load_icon(argv[1]);

   edit_icon();
   mode(2);
  }
  /*DISPLAY THE EXPANDED GRID */
  void display_grid(void)
  {
   register int x,y;

   for(y=IY;y<(IY+YDIM);y++)
    for(x=IX;x<(IX+XDIM);x++)
    putpoint(x+((x-IX)*XPAND),y+((y-IY)*XPAND),icon.image[x-IX][y-IY],0);
  }
  /*edit an icon .This function displays an expanded
    grid to make editing easy.It also displays the normal size
    version of the icon being edited.*/

  void edit_icon()
  {
   register int x,y;
   char ch,pen,temp;

   x=IX;//TO SET X,Y
   y=IY;//TO UPPER LEFT CORNER
   pen=BCK_GND;

   display_icon(0,IY);
   display_grid();
   do{
      /* write pixel to grid */
      putpoint(x+((x-IX)*XPAND),y+((y-IY)*XPAND),pen,0);
      /* save pixel color in icon image */
      icon.image[x-IX][y-IY]=pen;
      /* write pixel to icon */
      putpoint(x-IX,y,icon.image[x-IX][y-IY],0);

      /* this code displays a dot that indicates the current
	position, waits for a keystroke and then replaces
	the original value. */
      temp=getpoint(x+((x-IX)*XPAND),y+((y-IY)*XPAND));
      putpoint(x+((x-IX)*XPAND),y+((y-IY)*XPAND),HIGHLIGHT,0);

      ch=getkey();
      putpoint(x+((x-IX)*XPAND),y+((y-IY)*XPAND),temp,0);

      switch(ch)
      {
       case 75:/* LEFT */
	       x--;
	       break;
       case 77:/* RIGHT  */
	       x++;
	       break;
       case 72:/* UP */
	       y--;
	       break;
       case 80:/* LEFT */
	       y++;
	       break;
       case 71:/* UP LEFT */
	       x--,y--;
	       break;
       case 73:/* UP RIGHT */
	       x++,y--;
	       break;
       case 79:/* DOWN LEFT */
	       x--,y++;
	       break;
       case 81:/* DOWN RIGHT */
	       x++,y++;
	       break;
       case 59:pen=FORE_GND; /* F1 - PEN DOWN */
	       break;
       case 60:pen=BCK_GND; /* F2 - PEN UP */
	       break;
       case 61:save_icon();
	       break;
       case 62:load_icon(" ");
	       display_icon(0,IY);
	       display_grid();
	       break;
       case 63:init_icon();
	       display_icon(0,IY);
	       display_grid();
	       break;
    }
    if(x<IX)x++;if(x>IX+XDIM-1)x--;
    if(y<IY)y++;if(y>IY+YDIM-1)y--;
  }while(ch!=64);
 }

 /*DISPLAY THE ICON AT THE SPECIFIED X,Y. */
  void display_icon(int startx, int starty)
  {
   register int x,y;
   for(y=starty;y<starty+YDIM;y++)
    for(x=startx;x<startx+XDIM;x++)
     putpoint(x,y,icon.image[x-startx][y-starty],0);
  }
  /* INITIALIZE THE ICON */
  void init_icon()
  {
   register int x,y;
   for(x=0;x<XDIM;x++)
    for(y=0;y<YDIM;y++)
    icon.image[x][y]=BCK_GND;
  }

  /* SAVE THE ICON */
  save_icon(void)
  {
   FILE *fp;
   char fname[80];
   int result;
   gotoxy(0,22);
   printf("Save to : ");
   gets(fname);

   if((fp=fopen(fname,"wb"))==NULL)
   {
    printf("CANNOT OPEN FILE ");
    return 0;
   }

   fwrite(&icon,sizeof icon,1,fp);

   if(ferror(fp))result=0;
   else result=1;
   fclose(fp);
   clr_eol(0,22);
   return result;
  }

  /* LOAD THE ICON */
  load_icon(char *name)
  {
   FILE *fp;
   char fname[80];
   int result;

   if(!*name)
   {
    gotoxy(0,22);
    printf("load from : ");
    gets(fname);
   }
   else strcpy(fname,name);

   if((fp=fopen(fname,"rb"))==NULL)
   {
    printf("cannot open file ");
    return 0;
   }
   fread(&icon,sizeof icon,1,fp);

   if(ferror(fp)) result=0;
   else result=1;
   fclose(fp);
   clr_eol(0,22);

   return result;
 }

 /* RETURN THE SCAN CODE OF THE KEY PRESSED.
    THIS FUNCTION IS COMPATIBLE WITH TURBO/BORLAND C/C++
    AND MICROSOFT C/C++(BE SURE TO #define THE APPROPRIATE
    SYMBOL). IF YOU USE A DIFFERENT COMPILER, CONSULT THE TEXT. */

    char getkey(void)
    {
     union key
     {
      int i;
      char ch[2];
     }k;

    #ifdef TURBOC
    k.i=bioskey(0);
    #endif

    #ifdef MICROSOFTC
    k.i=_bios_keybrd(0);
    #endif

    return k.ch[1];
  }

  /* SET THE VIDEO MODE */
  void mode(int mode_code)
  {
   union REGS r;
   r.h.al=mode_code;
   r.h.ah=0;
   int86(0x10,&r,&r);
  }

  /* send the cursor to xy */
  void gotoxy(int x,int y)
  {
   union REGS r;
   r.h.al=2;//cursor addressing function
   r.h.dl=x;//column coordinates
   r.h.dh=y;//row coordinates
   r.h.bh=0;
   int86(16,&r,&r);
  }

  /* CLEARS TO END OF LINE */
  void clr_eol(int x,int y)
  {
   for(;x<80;x++)
   {
    gotoxy(x,y);
    printf(" ");
   }
  }

  /* RETURN THE VALUE OF THE SPECIFIED PIXEL */


  char getpoint(int x,int y)
  {
   union REGS r;
   r.h.ah=13;
   r.x.dx=y;
   r.x.cx=x;
   r.h.bh=0;
   int86(16,&r,&r);
   return r.h.al;
  }

  /* THIS VERSION OF PUTPOINT WILL WORK FOR ALL VIDEO
     ADAPTERS BUT IT IS INCREDIBLY SLOW!!! */

     /*
      void putpoint(int x,int y,int color,int how)
      {
       union REGS r;
       if(how==0x18) color=color | 128;
       r.h.bh=0;
       r.h.ah=12;
       r.h.al=color;
       r.x.dx=y;
       r.x.cx=x;
       int86(16,&r,&r);
      }
      */
      /* THIS FUNCTION SETS THE SPECIFIED PIXEL TO THE
	 SPECIFIED COLOR USING EGA/VGA VIDEO ADAPTER.
	 THE VALUE OF how MAY BE ONE OF THESE ::

	 ACTION                 VALUE
	 overwrite                0
	 XOR                     0x18
	 AND                      8
	 OR                      0X10

      */

      #define ENABLE 0X0F
      #define INDEXREG 0X3CE
      #define VALREG 0X3CF
      #define OUTINDEX(index,val) outp((INDEXREG),(index));\
				  outp((VALREG),(val));

      #define WIDTH 80L

      /* These range values assume EGA mode 16 */

      #define XMAX 639
      #define YMAX 349
      #define XMIN 0
      #define YMIN 0

      void putpoint(int x,int y,int color,int  how)
      {
       register unsigned char mask=0x80;
       register char far *base;
       unsigned dummy;

       /* if you want range cheching at this point, activate
       this line of code .it will slow down the function.
       however.
       */
       /*if(x<XMIN || x>XMAX ||y<YMIN || y>YMAX) return; */
       base=(char far *)(egabase + ( (long) y * WIDTH + (long) x/8L ));
       mask >>=x % 8;
       /* This causes the mamory READ necessary to
	  load the EGA/VGA's internal registers. */

	  dummy= *base;
	  OUTINDEX(0, color);
	  OUTINDEX(1, ENABLE);
	  OUTINDEX(3, how);
	  OUTINDEX(8, mask);

	  *base=1;

	  OUTINDEX(0, 0);
	  OUTINDEX(1, 0);
	  OUTINDEX(3, 0);
	  OUTINDEX(8, 0Xff);
	 }












