#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>

#define FREE 1000
#define INFINIT 999

int initmouse();
void showmouse();
void restrictmouse(int,int);
void offmouse();
void mousepos(int *,int *);
void setmousepos(int,int);
int ltbutton();
int rtbutton();

void mai_scr();
void sec_scr();
void tert_scr();
int getkey();
void convert(int);
void mode(int);

void insert_node();
void done();
void free_node(int);
void freefrm_node(int,int);
void del_node(int);
void connect(int,int);
void button(int,int,int,int,char *,int,int,int);
void pushbutton(int,int,int,int,char *,int,int,int);
void frame(int,int,int,int,int,int,int);
void msgbox(char *,int,int);

union REGS r;
int cou,mx,my,y,nomoreflag;
char chnum[1];

void *ptr;
unsigned size;

struct n_node
{
 int node_no;
 int posx,posy;
 int neighbours;
 int con_no[15];
 int con_node[15];
}node[15];

int flag[5];

void main()
{
 int gd=0,gm,ch,status,i,no1,no2;

 initgraph(&gd,&gm," ");
 mode(18);

 mai_scr();
 sec_scr();
 tert_scr();
 initmouse();
 showmouse();
 cou=1;
 y=50;
 status=0;
 i=0;
 for(i=0;i<5;i++)
 {
  flag[i]=0;
 }
 mousepos(&mx,&my);
 while(status!=1)
 {
  mousepos(&mx,&my);
  if(ltbutton()==1)
  {
   mousepos(&mx,&my);
   if(my>=350)
   {
   if(mx>15&&mx<108&&my>380&&my<395)
   {
    if(flag[2]==0)
    {
     offmouse();
     pushbutton(15,380,108,395,"INSERT NODE",7,8,0);
     delay(150);
     button(15,380,108,395,"INSERT NODE",7,8,0);
     insert_node();
     showmouse();
     setmousepos(mx,my);
     delay(300);
     flag[3]=1;
    }
    else
    {
     offmouse();
     pushbutton(15,380,108,395,"CHANGE WT",7,8,0);
     delay(150);
     button(15,380,108,395,"CHANGE WT",7,8,0);
     //change_wt();
     showmouse();
     setmousepos(mx,my);
     delay(300);
    }
   }
   if(mx>125&&mx<218&&my>380&&my<395&&flag[2]==1)
   {
    offmouse();
    pushbutton(125,380,218,395,"DELETE NODE",7,8,0);
    delay(150);
    button(125,380,218,395,"DELETE NODE",7,8,0);
    showmouse();
    setmousepos(mx,my);
   }
   if(mx>235&&mx<313&&my>380&&my<395&&flag[2]==1)
   {
    offmouse();
    pushbutton(235,380,313,395,"FREE NODE",7,8,0);
    delay(150);
    button(235,380,313,395,"FREE NODE",7,8,0);
    showmouse();
   setmousepos(mx,my);
   }
   if(mx>330&&mx<413&&my>380&&my<395&&flag[2]==1)
   {
    offmouse();
    pushbutton(330,380,413,395,"CONNECT TO",7,8,0);
    delay(150);
    button(330,380,413,395,"CONNECT TO",7,8,0);

   conect: setfillstyle(1,4);
    bar(10,433,232,447);
    setcolor(2);
    outtextxy(15,437,"Please enter the first node ");
    gotoxy(31,28);
    scanf("%d",&no1);
    setfillstyle(1,9);
    bar(9,432,500,448);

    setfillstyle(1,4);
    bar(10,433,238,447);
    setcolor(2);
    outtextxy(15,437,"Please enter the second node ");
    gotoxy(32,28);
    scanf("%d",&no2);
    setfillstyle(1,9);
    bar(9,432,500,448);

    if(no1!=no2&&no1<=cou&&no2<=cou)
    {
     showmouse();
     setmousepos(mx,my);
     connect(no1,no2);
    }
    else
    {
     msgbox("You can't connect the same node",260,160);
     goto conect;
    }
   }
   if(mx>430&&mx<467&&my>380&&my<395&&flag[3]==1)
   {
    offmouse();
    pushbutton(430,380,467,395,"DONE",7,8,0);
    delay(150);
    button(430,380,467,395,"DONE",7,8,0);
    done();
    msgbox("THIS IS DONE ",150,90);
    showmouse();
   setmousepos(mx,my);
   }
   if(mx>484&&mx<520&&my>380&&my<395)
   {
    offmouse();
    pushbutton(484,380,520,395,"EXIT",7,8,0);
    delay(150);
    button(484,380,520,395,"EXIT",7,8,0);
    exit(0);
   showmouse();
   setmousepos(mx,my);
   }
   }
   else
   {
    while(my<350&&flag[1]!=1)
    {
     mousepos(&mx,&my);
     showmouse();
     for(i=0;i<cou;i++)
     {
      if(ltbutton()==1)
      {
      if(mx>(node[i].posx-3)&&mx<(node[i].posx+3)&&my>(node[i].posy-3)&&my<(node[i].posy+3))
      {
       if(flag[0]!=1)
       {
	 setcolor(10);
	 circle(node[i].posx,node[i].posy,3);
	 setfillstyle(1,0);
	 floodfill(node[i].posx,node[i].posy,10);
       }
       while(ltbutton()==1)
       {
	mousepos(&mx,&my);
	offmouse();

	setcolor(0);
	circle(node[i].posx,node[i].posy,3);

	setcolor(10);
	circle(mx,my,3);
	showmouse();

	node[i].posx=mx;
	node[i].posy=my;

	if(flag[0]!=1)
	{
	 setcolor(15);
	 rectangle(node[i].posx-13,node[i].posy-18,node[i].posx+15,node[i].posy+15);
	 setfillstyle(1,0);
	 floodfill(node[i].posx,node[i].posy,15);
	 floodfill(node[i].posx,node[i].posy,15);
	 setcolor(0);
	 rectangle(node[i].posx-13,node[i].posy-18,node[i].posx+15,node[i].posy+15);
	 flag[0]=1;
	}


       }
      }
      }
      flag[0]=0;
      convert(node[i].node_no);
      outtextxy(node[i].posx-3,node[i].posy-15,chnum);
     }
    }//while
   }//else
  }
 }//ENd of WHILE
}//END of main()

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
void mai_scr()
{
 setcolor(2);
 rectangle(0,0,getmaxx(),getmaxy());
 rectangle(1,1,getmaxx()-1,getmaxy()-1);
}
void sec_scr()
{
 setcolor(4);
 rectangle(4,4,getmaxx()-5,350);
 rectangle(5,5,getmaxx()-6,349);
}
void tert_scr()
{
 setcolor(13);
 rectangle(4,354,getmaxx()-5,getmaxy()-4);
 rectangle(5,355,getmaxx()-6,getmaxy()-5);
 setfillstyle(1,9);
 floodfill(10,359,13);
 button(15,380,108,395,"INSERT NODE",7,8,0);
 button(125,380,218,395,"DELETE NODE",7,8,0);
 button(235,380,313,395,"FREE NODE",7,8,0);
 button(330,380,413,395,"CONNECT TO",7,8,0);
 button(430,380,467,395,"DONE",7,8,0);
 button(484,380,520,395,"EXIT",7,8,0);
}
/*int getkey()
{
 union key
 {
  int i;
  char ch[2];
 }k;

 k.i=bioskey(0);
 return k.ch[1];
} */
void insert_node()
{
 int x,tem,i;
 tem=cou;
 if(cou<15)
 {
  x=tem*30;
  setcolor(15);
  setcolor(10);
  circle(x,y,3);
  node[cou].node_no=cou;
  node[cou].posx=x;
  node[cou].posy=y;
  node[cou].neighbours=0;
  for(i=0;i<15;i++)
  {
   node[cou].con_node[i]=0;
   node[cou].con_no[i]=0;
  }
  convert(node[cou].node_no);
  outtextxy(x-3,y-15,chnum);
  cou++;
 }
 else
 {
  printf("\007");
  nomoreflag=1;
  msgbox("NO MORE NODES CAN BE INSERTED ",250,90);
  cou=15;
 }
}
void button(int x1,int y1,int x2,int y2,char *str,int btcolor,int btborder,int txtcolor)
{
 int seedx,seedy;
 seedx=x1+3;
 seedy=y1+4;
 frame(x1,y1,x2,y2,15,btborder,btcolor);
 setcolor(txtcolor);
 outtextxy(seedx,seedy,str);
}
void pushbutton(int x1,int y1,int x2,int y2,char *str,int btcolor,int btborder,int txtcolor)
{
 int seedx,seedy;
 seedx=x1+3;
 seedy=y1+4;
 frame(x1,y1,x2,y2,btborder,btcolor,btcolor);
 setcolor(txtcolor);
 outtextxy(seedx,seedy,str);
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
void convert(int node_no)
{
 int rem,ans,i;
 i=2;
 rem=node_no;
 while(i!=0)
 {
  i--;
  ans=rem%10;
  switch(ans)
  {
   case 1: chnum[i]='1';
   break;
   case 2: chnum[i]='2';
   break;
   case 3: chnum[i]='3';
   break;
   case 4: chnum[i]='4';
   break;
   case 5: chnum[i]='5';
   break;
   case 6: chnum[i]='6';
   break;
   case 7: chnum[i]='7';
   break;
   case 8: chnum[i]='8';
   break;
   case 9: chnum[i]='9';
   break;
   case 0: chnum[i]='0';
   break;
  }
  rem=node_no/10;
 }
 //printf("%s",chnum);
}
void mode(int mode_code)
{
 union REGS r;
 r.h.al=mode_code;
 r.h.ah=0;
 int86(0x10,&r,&r);
}
void msgbox(char *msg,int xsize,int ysize)
{
 int maxx,maxy,midx,midy,st;
 maxx=getmaxx();
 maxy=getmaxy();

 midx=maxx/2;
 midy=maxy/2;
 st=0;

 size=imagesize(midx-(xsize/2)-6,midy-(ysize/2)-6,midx+(xsize/2)+6,midy+(ysize/2)+6);
 ptr=malloc(size);
 getimage(midx-(xsize/2)-6,midy-(ysize/2)-6,midx+(xsize/2)+6,midy+(ysize/2)+6,ptr);
 offmouse();
 frame(midx-(xsize/2),midy-(ysize/2),midx+(xsize/2),midy+(ysize/2),15,8,7);
 setcolor(4);
 outtextxy(midx-(xsize/2)+10,midy-30,msg);

 button(midx-15,midy+20,midx+10,midy+35,"OK",7,8,1);

 setmousepos(mx,my);
 showmouse();

 while(st!=1)
 {
  showmouse();
  mousepos(&mx,&my);

  if(ltbutton()==1)
  {
   if(mx>(midx-15)&&mx<(midx+10)&&my>(midy+20)&&my<(midy+35))
   {
    pushbutton(midx-15,midy+20,midx+10,midy+35,"OK",7,8,1);
    delay(150);
    button(midx-15,midy+20,midx+10,midy+35,"OK",7,8,1);
    st=1;
   }
   else
   {
    printf("\007");
   }
  }
 }
 offmouse();
 frame(midx-(xsize/2),midy-(ysize/2),midx+(xsize/2),midy+(ysize/2),0,0,0);
 putimage(midx-(xsize/2)-6,midy-(ysize/2)-6,ptr,1);
 free(ptr);
 showmouse();
 setmousepos(mx,my);
}
void done()
{
 int no;

 for(no=0;no<cou;no++)
 {
  setcolor(10);
  circle(node[no].posx,node[no].posy,3);
  setfillstyle(1,10);
  floodfill(node[no].posx,node[no].posy,10);
 }
 button(15,380,108,395,"CHANGE Wt",7,8,0);

 flag[1]=1;
 flag[2]=1;
}
void connect(int node1,int node2)
{
 int temp_hold1,temp_hold2,x1,y1,x2,y2,i,ti,wt1,wt2;
 int weh,medx,medy;
 char wtstr[5];

 temp_hold1=node[node1].neighbours;

 node[node1].con_no[temp_hold1]=node2;
 node[node1].neighbours=temp_hold1+1;

 temp_hold2=node[node2].neighbours;

 node[node2].con_no[temp_hold2]=node1;
 node[node2].neighbours=temp_hold2+1;

 x1=node[node1].posx;
 y1=node[node1].posy;

 setcolor(10);
 circle(x1,y1,3);
 setfillstyle(1,10);
 floodfill(x1,y1,10);

 x2=node[node2].posx;
 y2=node[node2].posy;

 setcolor(10);
 circle(x2,y2,3);
 setfillstyle(1,10);
 floodfill(x2,y2,10);

 setcolor(10);
 line(x1,y1,x2,y2);

 if(x1>=x2)
 {
  wt1=x1-x2;
 }
 else
 {
  wt1=x2-x1;
 }
 if(y1>=y2)
 {
  wt2=y1-y2;
 }
 else
 {
  wt2=y2-y1;
 }

 medx=(x1+x2)/2;
 medy=(y1+y2)/2;


 weh=wt1+wt2;

 node[node1].con_node[temp_hold1]=weh;
 node[node2].con_node[temp_hold2]=weh;

 itoa(weh,wtstr,10);
 printf("%d  %d  %d",weh,wt1,wt2);
 setcolor(12);
 if(y1>y2)
 {
  outtextxy(medx-8,medy-8,wtstr);
 }
 if(y2>=y1)
 {
  outtextxy(medx-5,medy-5,wtstr);
 }

}

