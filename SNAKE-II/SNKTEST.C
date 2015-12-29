#include<stdio.h>
#include<conio.h>
#include<graphics.h>

#define sncol 9

int count,xw,yw,quit,chh,latest_dir;
int oldx1,oldx2,oldy1,oldy2;
struct snake
{
 int x1,y1,x2,y2;
 int dir;
}snk[300];

void draw_snake();
void animate(int);
void forward(int);
void clear_trail();
void draw_scr();
void draw_upr_scr();

void main()
{
 int gd=0,gm,ax1,ay1,ax2,ay2;
 //i=0;
 xw=5;
 yw=5;
 /*ax1=20;
 ay1=200;
 ax2=ax1+xw;
 ay2=ay1+yw;*/

 initgraph(&gd,&gm," ");
 latest_dir=1;
 draw_scr();
 getch();
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
 draw_snake();
 clear_trail();
 //getch();
 //animate(20);
}
void draw_snake()
{
 int i;
 i=0;
 oldx1=snk[0].x1;
 oldx2=snk[0].x2;
 oldy1=snk[0].y1;
 oldy2=snk[0].y2;
 while(i<count)
 {
  setcolor(sncol);
  rectangle(snk[i].x1,snk[i].y1,snk[i].x2,snk[i].y2);
  setfillstyle(1,sncol);
  //floodfill(snk[i].x1+2,snk[i].y1+2,sncol);
  i++;
 }
}
void animate(int m)
{
 int temx1,temy1,temx2,temy2,j,k;
 k=0;
 j=0;
 while(k<m)
 {
  j=0;
  while(j<count)
  {
    if(j==count-1)
    {
     snk[j].x1=snk[j].x1+xw;
     snk[j].x2=snk[j].x2+xw;
    }
    else
    {
     snk[j].x1=snk[j+1].x1;
     snk[j].x2=snk[j+1].x2;
    }
    j++;
    oldx1=snk[0].x1;
    oldx2=snk[0].x2;
   //clear_trail();
  }
  draw_snake();
  clear_trail();
  printf("%d",snk[0].x1);
  getch();
  //delay(400);
  k++;
 }
}
void clear_trail()
{
 int i;
 i=0;
 while(i<count)
 {
  oldx1=snk[0].x1;
 oldx2=snk[0].x2;
 oldy1=snk[0].y1;
 oldy2=snk[0].y2;
  setcolor(1);
 // rectangle(snk[0].x1,snk[0].y1,snk[0].x2,snk[0].y2);
  rectangle(oldx1-(2*xw),oldy1,oldx2-(2*xw),oldy2);
  setfillstyle(1,0);
  /// floodfill(oldx1-xw+2,oldy1+2,1);
  //floodfill(snk[0].x1+2,snk[0].y1+2,1);

  setcolor(0);
 //rectangle(snk[0].x1,snk[0].y1,snk[0].x2,snk[0].y2);
  rectangle(oldx1-(2*xw),oldy1,oldx2-(2*xw),oldy2);
  i++;
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
    snk[i].x1=temx1+xw;
    snk[i].x2=temx2+xw;
    snk[i-1].dir=snk[i].dir;
   }
   if(snk[i].dir==2)
   {
    snk[i].y1=temy1+yw;
    snk[i].y2=temy2+yw;
    snk[i-1].dir=snk[i].dir;
   }
   if(snk[i].dir==3)
   {
    snk[i].x1=temx1-xw;
    snk[i].x2=temx2-xw;
    snk[i-1].dir=snk[i].dir;
   }
   if(snk[i].dir==4)
   {
    snk[i].y1=temy1-yw;
    snk[i].y2=temy2-yw;
    snk[i-1].dir=snk[i].dir;
   }
  }
  else
  {
   if(snk[i].dir==1)
   {
    snk[i].x1=snk[i+1].x1;
    snk[i].x2=snk[i+1].x2;
    snk[i].y1=snk[i+1].y1;
    snk[i].y2=snk[i+1].y2;
    snk[i].dir=snk[i+1].dir;
   }
   if(snk[i].dir==2)
   {
    snk[i].y1=temy1+yw;
    snk[i].y2=temy2+yw;
    snk[i].x1=snk[i+1].x1;
    snk[i].x2=snk[i+1].x2;
    snk[i].dir=snk[i+1].dir;
   }
   if(snk[i].dir==3)
   {
    snk[i].x1=temx1-xw;
    snk[i].x2=temx2-xw;
    snk[i].y1=snk[i+1].y1;
    snk[i].y2=snk[i+1].y2;
    snk[i].dir=snk[i+1].dir;
   }
   if(snk[i].dir==4)
   {
    snk[i].y1=temy1-yw;
    snk[i].y2=temy2-yw;
    snk[i].x1=snk[i+1].x1;
    snk[i].x2=snk[i+1].x2;
    snk[i].dir=snk[i+1].dir;
   }
  }
  i++;
  delay(120);
  draw_snake();
  clear_trail();
 }
 //printf("%d",i);

}
void draw_scr()
{
 int i,kx,ky,ax1,ay1,ax2,ay2;
 ax1=20;
 ay1=200;
 ax2=ax1+xw;
 ay2=ay1+yw;

 i=0;

 draw_uppr_scr();
 setcolor(4);
 rectangle(1,100,getmaxx()-3,getmaxy()-3);
 setcolor(4);
 rectangle(2,99,getmaxx()-4,getmaxy()-4);

 latest_dir=1;
 while(i<5)
 {
  snk[i].x1=ax1;
  snk[i].y1=ay1;
  snk[i].x2=ax2;
  snk[i].y2=ay2;
  snk[i].dir=latest_dir;
  ax1=ax1+xw;
  ax2=ax2+xw;
  i++;
  count++;
 }
 oldx1=snk[0].x1;
 oldx2=snk[0].x2;
 oldy1=snk[0].y1;
 oldy2=snk[0].y2;
 printf("%d \n",snk[0].x1);
 printf("%d ",snk[0].x2);
}