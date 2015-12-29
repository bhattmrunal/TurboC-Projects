#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

#define SNAKE_COLOR 9
#define XWIDTH 4
#define YWIDTH 4

int sn_x,sn_y;
int knst,count,quit,oldx1,oldy1,oldx2,oldy2,latest_dir;

struct snake
{
 int x1,y1,x2,y2;
 int dir;
}snk[320];
void far *image[10];

void draw_scr();
void draw_snake();
void draw_uppr_scr();
void incr_size(int,int);
void forward();
void clear_trail();
int getkey();
void putpoint(int,int,int,int);

void main()
{
 int gd=DETECT,gm,chh,io;
 char ch;
 initgraph(&gd,&gm," ");
 quit=0;
 knst=10;
 count=0;

 sn_x=20;
 sn_y=130;

 draw_scr();
 io=0;
 while(quit!=1)
 {
  if(kbhit())
  {
   chh=getkey();
   if(chh==1)
   {
    quit=1;
   }
   if(chh==77&&latest_dir!=3)
   {
    latest_dir=1;
   }
   if(chh==80&&latest_dir!=2)
   {
    latest_dir=2;
   }
   if(chh==75&&latest_dir!=1)
   {
    latest_dir=3;
   }
   if(chh==72&&latest_dir!=2)
   {
    latest_dir=4;
   }
  }
  forward(latest_dir);
 }
}
void draw_scr()
{
 int i,kx,ky;
 i=0;
 kx=20;
 ky=130;

 draw_uppr_scr();
 setcolor(4);
 rectangle(1,100,getmaxx()-3,getmaxy()-3);
 setcolor(4);
 rectangle(2,99,getmaxx()-4,getmaxy()-4);

 latest_dir=1;
 while(i<knst)
 {

  snk[i].x1=kx;
  snk[i].y1=ky;
  snk[i].x2=kx+XWIDTH;
  snk[i].y2=ky+YWIDTH;
  snk[i].dir=1;

  kx=kx+XWIDTH;
  i++;
  count++;
  draw_snake();
 }
}
void forward(int dirr)
{
 int i,temx1,temx2,temy1,temy2;

 i=0;

 oldx1=snk[0].x1;
 oldx2=snk[0].x2;
 oldy1=snk[0].y1;
 oldy2=snk[0].y2;

  while(i<count)
 {
  temx1=snk[i].x1;
  temx2=snk[i].x2;
  temy1=snk[i].y1;
  temy2=snk[i].y2;

  if(i+1==count)
  {
   snk[i].dir=dirr;
   if(snk[i].dir==1)
   {
    snk[i].x1=temx1+4;
    snk[i].x2=temx2+4;
    snk[i-1].dir=snk[i].dir;
   }
   if(snk[i].dir==2)
   {
    snk[i].y1=temy1+4;
    snk[i].y2=temy2+4;
    snk[i-1].dir=snk[i].dir;
   }
   if(snk[i].dir==3)
   {
    snk[i].x1=temx1-4;
    snk[i].x2=temx2-4;
    snk[i-1].dir=snk[i].dir;
   }
   if(snk[i].dir==4)
   {
    snk[i].y1=temy1-4;
    snk[i].y2=temy2-4;
    snk[i-1].dir=snk[i].dir;
   }
  }
  else
  {
   if(snk[i].dir==1)
   {
    snk[i].x1=temx1+4;
    snk[i].x2=temx2+4;
    snk[i].y1=snk[i+1].y1;
    snk[i].y2=snk[i+1].y2;
    snk[i].dir=snk[i+1].dir;
   }
   if(snk[i].dir==2)
   {
    snk[i].y1=temy1+4;
    snk[i].y2=temy2+4;
    snk[i].x1=snk[i+1].x1;
    snk[i].x2=snk[i+1].x2;
    snk[i].dir=snk[i+1].dir;
   }
   if(snk[i].dir==3)
   {
    snk[i].x1=temx1-4;
    snk[i].x2=temx2-4;
    snk[i].y1=snk[i+1].y1;
    snk[i].y2=snk[i+1].y2;
    snk[i].dir=snk[i+1].dir;
   }
   if(snk[i].dir==4)
   {
    snk[i].y1=temy1-4;
    snk[i].y2=temy2-4;
    snk[i].x1=snk[i+1].x1;
    snk[i].x2=snk[i+1].x2;
    snk[i].dir=snk[i+1].dir;
   }
  }
  i++;
  delay(12);
  draw_snake();
  clear_trail();
 }
 //printf("%d",i);

}
void draw_snake()
{
 int i;
 i=0;
 while(i<count)
 {
   setcolor(9);
   rectangle(snk[i].x1,snk[i].y1,snk[i].x2,snk[i].y2);
   setfillstyle(1,9);
   floodfill(snk[i].x2-1,snk[i].y2-1,9);

   i++;
 }
 if(latest_dir==1)
 {
  putpoint(snk[i-1].x2+2,snk[i-1].y1+1,9,0);
  putpoint(snk[i-1].x2+2,snk[i-1].y2-1,9,0);
 }
 if(latest_dir==2)
 {
  putpoint(snk[i-1].x1+1,snk[i-1].y2+2,9,0);
  putpoint(snk[i-1].x2-1,snk[i-1].y2+2,9,0);
 }
}
void clear_trail()
{
 if(snk[0].dir==1)
 {
  setcolor(1);
  rectangle(oldx1-3,oldy1-3,oldx2-3,oldy2+3);
  setfillstyle(1,0);
  floodfill(oldx1-1,oldy2-3,1);
  setcolor(0);
  rectangle(oldx1-3,oldy1-3,oldx2-3,oldy2+3);
 }
 if(snk[0].dir==3)
 {
  setcolor(1);
  rectangle(oldx1,oldy1-3,oldx2-3,oldy2+5);
  setfillstyle(1,0);
  floodfill(oldx1-1,oldy2-3,1);
  setcolor(0);
  rectangle(oldx1,oldy1-3,oldx2-3,oldy2+5);
 }
 if(snk[0].dir==2)
 {
  setcolor(1);
  rectangle(oldx1-3,oldy1-3,oldx2+3,oldy2);
  setfillstyle(1,0);
  floodfill(oldx1+1,oldy2-3,1);
  setcolor(0);
  rectangle(oldx1-3,oldy1-3,oldx2+3,oldy2);
 }
 if(snk[0].dir==4)
 {
  setcolor(1);
  rectangle(oldx1-3,oldy1,oldx2+3,oldy2+5);
  setfillstyle(1,0);
  floodfill(oldx1,oldy2-3,1);
  setcolor(0);
  rectangle(oldx1-3,oldy1,oldx2+3,oldy2+5);
 }
}
void draw_uppr_scr()
{
 setcolor(2);
 rectangle(1,1,getmaxx()-2,98);
 rectangle(2,2,getmaxx()-3,97);
 line(2,3,getmaxx()-2,3);
 setcolor(1);
 line(500,4,500,96);
 line(501,4,501,96);
 setcolor(5);
 outtextxy(10,15,"Quit = ESC ");
 outtextxy(150,15,"Save = F3 ");
 outtextxy(260,15,"Load = F4 ");
 outtextxy(10,40,"Help = F5 ");
 outtextxy(150,40,"Credits = F8 ");
}
int getkey()
{
 union key
 {
  int i;
  char ch[2];
 }k;

 k.i=bioskey(0);

 return k.ch[1];
}
void putpoint(int x,int y,int color,int how)
{
 union REGS r;
 if(how==0x18) color=color | 128;
 r.h.bh=0;
 r.h.ah=12;
 r.h.al=color;
 r.x.dx=y;
 r .x.cx=x;
 int86(16,&r,&r);
}
