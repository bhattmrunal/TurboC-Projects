#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>

int initmouse();
void showmouse();
int right_button();
int left_button();
void pos(int *x,int *y);

union REGS r;
void main()
{
 int i,j,x,y,maxx,maxy,gd=0,gm,button;

 initgraph(&gd,&gm," ");
 if(initmouse()==0)
 {
  printf("NO MOUSE DRIVER LOADED ");
  getch();
  closegraph();
  exit(0);
 }
 maxx=getmaxx();
 maxy=getmaxy();
 showmouse();
 setcolor(2);
 rectangle(2,50,maxx-1,maxy-1);
 while(!kbhit())
 {


  gotoxy(20,1);
  printf("MOUSE DEMOSTRATION PROGRAM");
  pos(&x,&y);
  gotoxy(2,5);
  printf("X= %d  ",x);
  gotoxy(20,5);
  printf("Y= %d  ",y);
  gotoxy(5,15);
  printf("Button 1");
  gotoxy(25,15);
  printf("Button 2");
  gotoxy(7,18);
  printf(" UP  ");
  gotoxy(15,18);
  printf(" UP  ");
  if(right_button())
  {
     gotoxy(15,18);
   printf("DOWN");
  }
  if(left_button())
  {
   gotoxy(7,18);
   printf("DOWN");
  }
 }

}
int initmouse()
{
 r.x.ax=0;
 int86(0x33,&r,&r);

 return r.x.ax;
}
void showmouse()
{
 r.x.ax=1;
 int86(0x33,&r,&r);
}
int right_button()
{
 r.x.ax=3;
 int86(0x33,&r,&r);

 return r.x.bx & 2;
}
int left_button()
{
 r.x.ax=3;
 int86(0x33,&r,&r);

 return r.x.bx & 1;
}
void pos(int *x,int *y)
{
 r.x.ax=3;
 int86(0x33,&r,&r);
 *x=r.x.cx;
 *y=r.x.dx;
}
