#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>

#define IY 144
#define IX 240
#define XDIM 40
#define YDIM 34
#define XPAND 3
#define DOWN 1

struct icon_type {
  unsigned int image[40][34];//icon image
  unsigned char text[12];//icon text
  void (*func)();/*pointer to function associated
		  with each icon*/
  int ix,iy; //X,Y coordinates
  }icon;


void frame(int,int,int,int,int,int,int);
void display_grid(void);
void putpoint(int,int,int,int);
void mode(int);
void icon_edit(int,int,int,int,int,int);
void display_icon(void);
void ma_scr(void);
void menubar(void);
void save_icon(void);
void sav_ico(char *);
int getkey();

int sav;
char fname[80];

void main(void)
{
 int gd=DETECT,gm,vertualx,vertualy,status,pen,col,cur,k;
 int ch,x,y;
  //char far *egabase;
  //egabase=(char far *) MK_FP(0xA000,0000);
 clrscr();
 initgraph(&gd,&gm," ");
 mode(18);

 k=0;
 sav=0;
 status=0;
 cur=4;
 col=2;
 pen=0;

 menubar();
 ma_scr();
 vertualx=0;
 vertualy=0;
 x=240;
 y=144;
 putpoint(x,y,4,0);
 while(status!=1)
 {
  ch=getkey();
    icon_edit(x,y,vertualx,vertualy,col,pen);
    switch(ch)
    {
     case 75:/* LEFT */
	       if(vertualx>0)
	       {
		vertualx--;
		x=x-4;
	       }
	       break;
       case 77:/* RIGHT  */
	       if(vertualx<39)
	       {
		vertualx++;
		x=x+4;
	       }
	       break;
       case 72:/* UP */
	       if(vertualy>0)
	       {
		vertualy--;
		y=y-4;
	       }
	       break;
       case 80:/* LEFT */
	       if(vertualy<33)
	       {
		vertualy++;
		y=y+4;
	       }
	       break;
       case 71:/* UP LEFT */
	       if(vertualx>0&&vertualy>0)
	       {
		x=x-4,y=y-4;
		vertualx--;vertualy--;
	       }
	       break;
       case 73:/* UP RIGHT */
	       if(vertualx<39&&vertualy>0)
	       {
		x=x+4,y=y-4;
		vertualx++;vertualy--;
	       }
	       break;
       case 79:/* DOWN LEFT */
	       if(vertualx>0&&vertualy<33)
	       {
		x=x-4,y=y+4;
		vertualx--;vertualy++;
	       }
	       break;
       case 81:/* DOWN RIGHT */
	       if(vertualx<39&&vertualy<33)
	       {
		x=x+4,y=y+4;
		vertualx++;vertualy++;
	       }
	       break;
       case 59:pen=1; /* F1 - PEN DOWN */
	       break;
       case 60:pen=0; /* F2 - PEN UP */
	       break;
       case 61:save_icon();
	      break;
      /* case 62:load_icon(" ");
	       display_icon(0,IY);
	       display_grid();
	       break;
       case 63:init_icon();
	       display_icon(0,IY);
	       display_grid();
	       break;*/
       case 15:gotoxy(5,20);
	       printf("Please enter the color      ");clreol();
	       scanf("%d",&col);
	       gotoxy(5,20);
	       clreol();
	       setfillstyle(1,0);
	       floodfill(300,310,0);
	       break;
       case 46:gotoxy(5,20);
	       printf("Please enter the cursor color ");clreol();
	       scanf("%d",&cur);
	       gotoxy(5,20);
	       clreol();
	       setfillstyle(1,0);
	       floodfill(330,310,0);
	       break;
       case 20:setcolor(13);
	       outtextxy(20,308,"Please enter the icon text ");
	       gotoxy(30,20);clreol();gets(icon.text);gotoxy(3,20);
	       clreol();
	       setfillstyle(1,0);
	       floodfill(330,310,0);
	       break;
       case 1 :status=1;
	       break;
    }
    if(sav!=0) sav=2;

    if(x<240)x=x+4;if(x>240+160)x=x-4;
    {
    if(y<144)y=y+4;if(y>144+136)y=y-4;
    {
     putpoint(x,y,cur,0);
     icon.image[vertualx][vertualy]=col;
    }
   }
 }
 if(x<240)x=x+4;if(x>240+160)x=x-4;
    if(y<144)y=y+4;if(y>144+136)y=y-4;
    putpoint(x,y,cur,0);
    icon.image[vertualx][vertualy]=col;
 if(sav==0)
 {
  setcolor(12);
  outtextxy(10,308,"The icon is not saved do you want to save it now ?");
  gotoxy(55,20);scanf("%d",&k);
  if(k==1)
  {
   gotoxy(2,20);clreol();gotoxy(5,20);
	       setfillstyle(1,0);
	       floodfill(330,310,0);
   printf("Please enter the file name ");scanf("%s",&fname);
   gotoxy(5,20);
   clreol();
   setfillstyle(1,0);
   floodfill(330,310,0);
   strcat(fname,".chi");
   sav_ico(fname);
  }
  k=0;
 }
 if(sav==2)
 {
  setcolor(12);
  outtextxy(10,308,"Do you want to save the changes to icon file ?");
  gotoxy(52,20);scanf("%d",&k);
  if(k==1) sav_ico(fname);

 }
 //if(yn=="y"||yn=="Y"||yn=="yes"||yn=="YES"||yn=="Yes") printf("Y");
 //mode(2);
 /*
 for(vertualy=0;vertualy<34;vertualy++)
 {
  for(vertualx=0;vertualx<40;vertualx++)
  {
   printf("%d ",icon.image[vertualx][vertualy]);
  }
  printf("\n");
 } */
}
void display_icon(void)
{
 int disx,disy;
 for(disx=590;disx<590+40;disx++)
 {
  for(disy=130;disy<130+34;disy++)
  {
   putpoint(disx,disy,15,0);
  }
 }
}
void ma_scr(void)
{
 frame(3,26,639-1,419,RED,LIGHTRED,0);
 frame(3,426,639-1,480-5,GREEN,LIGHTGREEN,13);
 display_grid();
 display_icon();
}
void icon_edit(int x,int y,int vertualx,int vertualy,int col,int pen)
{
  if(pen==DOWN)
  {
   if(col==33)
   {
    putpoint(vertualx+590,vertualy+130,0,0);
    putpoint(x,y,0,0);
   }
   else
   {
    putpoint(vertualx+590,vertualy+130,col,0);
    putpoint(x,y,col,0);
   }
   icon.image[vertualx][vertualy]=col;
  }
  else
  {
   putpoint(vertualx+590,vertualy+130,15,0);
   putpoint(x,y,15,0);
   icon.image[vertualx][vertualy]=15;
  }
}
void display_grid()
  {
   register int x,y,verx,very;
   verx=0;
   very=0;
   for(y=144;y<144+136;y=y+4)
   {
    for(x=240;x<240+160;x=x+4)
    {
     putpoint(x,y,15,0);
    }
   }
   for(verx=0;verx<40;verx++)
   {
    for(very=0;very<34;very++)
    {
     icon.image[verx][very]=15;
    }
   }
  }
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
 void mode(int mode_code)
  {
   union REGS r;
   r.h.al=mode_code;
   r.h.ah=0;
   int86(0x10,&r,&r);
  }
 int getkey(void)
    {
     union key
     {
      int i;
      char ch[2];
     }k;

     k.i=bioskey(0);

     return k.ch[1];
  }
void icon_desgn(int x,int y,int col,int pen,int vertualx,int vertualy)
{
 if(x<=240+160&&y<=144+136&&pen==1)
 {
  putpoint(x,y,col,0);
  putpoint(vertualx,vertualy+130,col,0);
  icon.image[vertualx][vertualy]=col;
 }
 if(x<=IX+XDIM&&y<=IY+YDIM&&pen==0)
 {
  putpoint(x+((x-IX)*XPAND),y+((y-IY)*XPAND),15,0);
  putpoint(x+950,y+5,15,0);
  icon.image[vertualx][vertualy]=15;
 }
}
void frame(int ax,int ay,int bx,int by,int co1,int co2,int co3)
{
 setfillstyle(1,co3);
 bar(ax,ay,bx,by);

 setcolor(co1);
 rectangle(ax-1,ay-1,bx+1,by+1);
 rectangle(ax-2,ay-2,bx+2,by+2);
 rectangle(ax-3,ay-3,bx+3,by+3);

 setcolor(co2);
 line(bx+1,ay-1,bx+1,by+3);
 line(bx+2,ay-2,bx+2,by+3);
 line(bx+3,ay-3,bx+3,by+3);
 setcolor(co2);
 line(ax-1,by+1,bx+3,by+1);
 line(ax-2,by+2,bx+3,by+2);
 line(ax-3,by+3,bx+3,by+3);
}
void menubar()
{
 frame(3,5,639-1,23-4,LIGHTGRAY,DARKGRAY,LIGHTGRAY);
 setcolor(0);
 outtextxy(7,7,"FILE");
 outtextxy(55,7,"EDIT");
 outtextxy(104,7,"CREDIT");
}


void sav_ico(char *name)
{
 FILE *fp;
 if((fp=fopen(name,"wb"))==NULL)
   {
    gotoxy(5,22);
    printf("CANNOT OPEN FILE \n press any key to exit ");
    getch();
    exit(0);
   }

   fwrite(&icon,sizeof icon,1,fp);

   if(ferror(fp))
   {
    gotoxy(5,20);
    clreol();
    setfillstyle(1,0);
    floodfill(300,310,0);
    printf("Sorry error writing the file");
    getch();
   }
   else
   {
    gotoxy(5,20);
    printf("File written successfully");
    sav=1;
    getch();
    gotoxy(5,20);clreol();
    setfillstyle(1,0);
    floodfill(300,310,0);
   }
   fclose(fp);
  }