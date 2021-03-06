#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include<stdio.h>

void welcome();
void menubar();
void display(int,int,int,int);
void frame(int,int,int,int,int,int,int);
void push_frame(int,int,int,int,int,int);
int initmouse();
void showmouse();
void mousepos(int *,int *);
int ltbutton();
int rtbutton();
int getkey();
void button(int,int,int,int,char *);
void pushbutton(int,int,int,int,char *);
int check(int,int,int,int,char *,int,int,int);
int checkm(int);
void clickl(int,int,int,int,int,int,char *);
void test(int);

void main()
{
 int i,j,x1,y1,x2,y2,gd=0,gm,maxx,maxy,key,btstatus,x,y;

 char ch,string[40],*ptr;
 clrscr();
 initgraph(&gd,&gm," ");
 welcome();
 maxx=getmaxx();
 maxy=getmaxy();
 display(2,25,maxx-3,maxy-3);
 menubar();
  if(initmouse()==0)
 {
  cout<<"NO MOUSE DRIVER LOADED";
  getch();
  exit(1);
 }
 showmouse();
 x=0;
 y=0;
 btstatus=1;
 key=0;
 while(key!=1)
 {
  //key=getkey();
   mousepos(&x,&y);
  if(y>=10&&y<=24)
  {
   btstatus=check(2,41,10,24,"FILE",x,y,btstatus);
   btstatus=check(47,85,10,24,"EDIT",x,y,btstatus);
   btstatus=check(92,132,10,24,"FIND",x,y,btstatus);
   btstatus=check(137,175,10,24,"HELP",x,y,btstatus);
  }
  if(y>24)
  {
   btstatus=checkm(btstatus);
  }
  /*gotoxy(20,20);
   printf("%dhfgh  ,  %d   ,key= %d",x,y,key);*/
   delay(50);
  if(ltbutton()==1)
  {
   mousepos(&x,&y);
   clickl(x,y,2,41,10,24,"FILE");
   clickl(x,y,47,85,10,24,"EDIT");
   clickl(x,y,92,132,10,24,"FIND");
   clickl(x,y,137,175,10,24,"HELP");
    //file_menu();
    delay(700);
    key=1;
  }
 }


}
void welcome()
{
 char string[20]={NULL};
 char *ptr;
 ptr=string;
  setfillstyle(10,1);
  bar(0,0,639,479);
  settextstyle(3,HORIZ_DIR,4);
  setcolor(14);
  outtextxy(100,160,"TEXT EDITOR VERSION 1.1");
  settextstyle(0,0,0);
  setcolor(2);
  outtextxy(380,250,"MADE BY MRUNAL BHATT");
 /* while(*ptr!=NULL)
  {
   sound(*ptr*10);
   delay(200);
   nosound();
  } */
  delay(4000);
}
void btpressed(int x1,int y1,int x2,int y2,char *str)
{
 button(x1,y1,x2,y2,str);
 pushbutton(x1,y1,x2,y2,str);
}
int checkm(int btstatus)
{
 if(btstatus!=1)
 {
  menubar();
  btstatus=1;
 }
 return btstatus;
}
void clickl(int x,int y,int xg,int xl,int yg,int yl,char *str)
{
 if(x>=xg&&x<=xl&&y>=yg&&y<=yl)
 {
  btpressed(xg,yg,xl,yl,str);
  //delay(80);
  //button(xg,yg,xl,yl,str);

 }
}
void mousepos(int *x,int *y)
{
union REGS r;
r.x.ax=3;
int86(0x33,&r,&r);
*x=r.x.cx;
*y=r.x.dx;
}
void display(int x1,int y1,int x2,int y2)
{
 frame(x1,y1,x2,y2,LIGHTGRAY,DARKGRAY,WHITE);//LIGHTGREEN,GREEN,WHITE);
 push_frame(x1+3,y1+3,x2-3,y2-3,DARKGRAY,LIGHTGRAY);//GREEN,LIGHTGREEN);

}
int check(int xg,int xl,int yg,int yl,char *str,int x,int y,int btstatus)
{

 if(btstatus!=0)
   {
    if(x>=xg&&x<=xl&&y>=yg&&y<=yl)
    {
     menubar();
     button(xg,yg,xl,yl,str);
     btstatus=0;
    }
   }

   return btstatus;
}
void menubar()
{
 frame(3,10,639-3,24,LIGHTGRAY,DARKGRAY,LIGHTGRAY);
 outtextxy(5,12,"FILE");
 outtextxy(50,12,"EDIT");
 outtextxy(95,12,"FIND");
 outtextxy(140,12,"HELP");
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
 void button(int x1,int y1,int x2,int y2,char *str)
 {
  int seedx,seedy;
  seedx=x1+3;
  seedy=y1+2;
  frame(x1,y1,x2,y2,WHITE,DARKGRAY,LIGHTGRAY);
  outtextxy(seedx,seedy,str);
 }
 void pushbutton(int x1,int y1,int x2,int y2,char *str)
 {
  int seedx,seedy;
  seedx=x1+3;
  seedy=y1+2;
  frame(x1,y1,x2,y2,DARKGRAY,WHITE,LIGHTGRAY);
  outtextxy(seedx,seedy,str);
 }
void push_frame(int ax,int ay,int bx,int by,int co1,int co2)
 {
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
int getkey()
{
 union ky
 {
  int i;
  char ch[2];
 }k;
 k.i=bioskey(0);

 return k.ch[1];

}
int initmouse()
{
 union REGS r;
 r.x.ax=0;
 int86(0x33,&r,&r);
 return r.x.ax;
}
void showmouse()
{
 union REGS r;
 r.x.ax=1;
 int86(0x33,&r,&r);
}
int rtbutton()
{
 union REGS r;
 r.x.ax=3;
 int86(0x33,&r,&r);
 return r.x.bx & 2;
}
int ltbutton()
{
 union REGS r;
 r.x.ax=3;
 int86(0x33,&r,&r);
 return r.x.bx & 1;
}

