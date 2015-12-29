#include<dos.h>
#include<conio.h>
#include<bios.h>

union REGS r;

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
void offmouse()
{
 r.x.ax=2;
 int86(0x33,&r,&r);
}
void mousepos(int *x,int *y)
{
 r.x.ax=3;
 int86(0x33,&r,&r);
 *x=r.x.cx;
 *y=r.x.dx;
}
void setmousepos(int x,int y)
{
 r.x.ax=4;
 r.x.cx=x;
 r.x.dx=y;
 int86(0x33,&r,&r);
}
int ltbutton()
{
 r.x.ax=3;
 int86(0x33,&r,&r);
 return r.x.bx&1;
}
int rtbutton()
{
 r.x.ax=3;
 int86(0x33,&r,&r);
 return r.x.bx&2;
}
