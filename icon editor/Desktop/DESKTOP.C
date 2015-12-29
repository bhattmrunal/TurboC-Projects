#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
#include<mouse.h>
#include<graphics.h>
//union REGS r;
#define MAX_ICO 9
#define xstrt 30
#define ystrt 20

struct icon_type {
  unsigned int image[40][34];//icon image
  unsigned char text[12];//icon text
  void (*func)();/*pointer to function associated
		  with each icon*/
  int ix,iy; //X,Y coordinates
  }icon[MAX_ICO];
char *file_names[]={"ico1.chn","ico2.chn","ico3.chn","ico4.chn","ico5.chn","ico6.chn","ico7.chn","ico8.chn","ico9.chn","ico10.chn"};
int run,BGCOLOR,BORDER,status;
void main_scr();
int mousepos_monitor(int,int);
void video_mode(int);
void putpoint(int,int,int,int);
int load_icons();
int flag,oldix,oldiy,sflag;
void main()
{
 int gd=0,gm,mx,my;

 mx=100;my=100;
 status=0;
 oldix=oldiy=0;
 run=1;
 BGCOLOR=6;
 BORDER=14;
 flag=sflag=-1;
 initgraph(&gd,&gm," ");
 main_scr();
 while(status!=1)
 {
  mousepos(&mx,&my);
  mousepos_monitor(mx,my);
  if(ltbutton()==1)
  {
   if(kbhit())
   {
    kb_monitor();
   }
   mousepos(&mx,&my);
   mousebtn_monitor(mx,my);
  }

 }
 //getch();
}// end of main
void crx_btn()
{
 setcolor(1);
 rectangle(625,1,636,10);
 setfillstyle(1,1);
 floodfill(630,6,1);
 setcolor(15);
 line(627,2,634,8);
 line(626,2,635,8);

 line(634,2,627,8);
 line(635,2,626,8);

}
void main_scr()
{
int test,ms;
 run=1;
 setcolor(BORDER);
 rectangle(0,1,getmaxx()-3,getmaxy()-3);
 rectangle(1,2,getmaxx()-4,getmaxy()-4);
 setfillstyle(1,BGCOLOR);
 floodfill(230,300,BORDER);
 crx_btn();

 test=load_icons();
 ms=initmouse();
 if(ms==0)
 {
  printf("\n\nSorry No Mouse driver loaded ");
  getch();
  exit(0);
 }
 showmouse();
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
void icon1()
{
 int i=0;
 BGCOLOR=BGCOLOR++;
 BORDER=4;
 //cleardevice();
 //for(i=0;i<MAX_ICO;i++)
 //free(&icon[i]);
 main_scr();
}
void icon2()
{
 int re;
 //cleardevice();
 //for(re=0;re<MAX_ICO;re++)
 //free(&icon[re]);
 re=execl("g:\tcc\getkey.exe",NULL,NULL);
 if(re==-1)
 {
 printf("\nSpawnl error loading exe file");
 }
 //main_scr();
}
void icon3()
{
 status=1;
}
int load_icons()
{
 int i=0,icx,icy,color,posx,posy,len;
 FILE *fp;
 for(i=0;i<MAX_ICO;i++)
 {
  if((fp=fopen(file_names[i],"rb"))==NULL)
   {
    printf("Cannot open file %s \n",file_names[i]);
    return 0;
   }
   fread(&icon[i],sizeof(struct icon_type),1,fp);
   if(run==1)
   {
    posx=xstrt;
    posy=ystrt;
    icon[0].ix=30;
    icon[0].iy=20;
    run++;
   }
   else
   {
    if(i<7)
    {
     posx=posx;
     posy=posy+60;
     icon[i].ix=posx;
     icon[i].iy=posy;
    }
    else
    {
     if(i==7)
     {
      posx=posx+60;
      posy=ystrt;
      icon[i].ix=posx;
      icon[i].iy=posy;
     }
     else
     {
      posx=posx;
      posy=posy+60;
      icon[i].ix=posx;
     icon[i].iy=posy;
     }
    }
   }

   for(icy=0;icy<34;icy++)
   {
    for(icx=0;icx<40;icx++)
    {
     color=icon[i].image[icx][icy];
     if(color!=33)
     {
      putpoint(posx+icx,posy+icy,color,0);
     }
    }
   }
   if(icon[i].text!=NULL)
   {
    len=strlen(icon[i].text);
    settextstyle(0,0,0);
    setcolor(0);
    outtextxy(posx-(len*2)+7,posy+37,icon[i].text);
   }

  }
 return 1;
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
void link_ico(int icono)
{
 switch(icono)
 {
  case 0:
	icon1();
	break;
  case 1:
	 icon2();
	 break;
   case 2:
	icon3();
	break;
 }
}
int kb_monitor()
{
 int key;

}
int mousepos_monitor(int x,int y)
{
 int i;

 for(i=0;i<MAX_ICO;i++)
 {
 if(x>icon[i].ix&&x<icon[i].ix+41&&y>icon[i].iy&&y<icon[i].iy+35&&sflag!=i)
 {
  offmouse();
  setcolor(BGCOLOR);
  rectangle(icon[sflag].ix-3,icon[sflag].iy-3,icon[sflag].ix+43,icon[sflag].iy+47);
  setcolor(0);
  rectangle(icon[i].ix-3,icon[i].iy-3,icon[i].ix+43,icon[i].iy+47);
  showmouse();
  sflag=i;
  //printf("%d",sflag);
  return i;
 }
}
return 0;
}
int mousebtn_monitor(int x,int y)
{
 int i;

 if(x>623&&x<639&&y>0&&y<12)
 {
  status=1;
  return 0;
 }
 else
 {
 for(i=0;i<MAX_ICO;i++)
 {
  if(x>icon[i].ix&&x<icon[i].ix+41&&y>icon[i].iy&&y<icon[i].iy+35&&flag!=i)
  {
   link_ico(i);
   sflag=i;
   flag=i;
   return 1;
  }

 }
}
 return 0;
}