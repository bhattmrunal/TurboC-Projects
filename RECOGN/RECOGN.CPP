#include<graphics.h>
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<io.h>
#include<fcntl.h>
#include<stat.h>

#define BGIpath "\recog"

const int MAX=150;
const int scale=10;
const int offsetx=10,offsety=80;//10,80,10+150,80+150
const int dis_offx=10+470,dis_offy=80;
const int dis_datax=10+230,dis_datay=80;

int gmode,errorcode,gdriver=DETECT;
int xx,yy;
int mnx,mny,mxx,mxy;
int image_data[scale][scale];
int image_save[scale][scale];
int stat_cha='h',stat_cur='h';
char buffer[80];

void main_menu();
void init_graphic();
unsigned far getpixel(int x,int y);
void init_mouse();
void show_mouse();
void hide_mouse();
void move_mouse(int x,int y);
void recog();
void status_window();
void recog_screen();
void scanline(unsigned int *bufsize);
void check_text();
void open_file(unsigned int bufsize);
void teach___(unsigned int bufsize);
int file_exists(char *filename);
void credits();
void frame(int ax,int ay,int bx,int by,int co1,int co2,int co3);
void push_frame(int ax,int ay,int bx,int by,int co1,int co2);
void shadow(int ax,int ay,char *tex);
void shadowy(int ax,int ay,char *tex);

void main()
 {
  char choice;
  int key;
  unsigned int size;
  int option,status=1;
  int quit=0,ButtonStatus,x,y;
  void *arrow;

  init_graphic();
  init_mouse();
  main_menu();

  setcolor(WHITE);
  setfillstyle(1,WHITE);
  line(100,100,120,120);
  line(100,100,100,140);
  line(100,140,120,120);
  floodfill(101,120,WHITE);
  size=imagesize(100,100,120,140);
  arrow=malloc(size);
  getimage(100,100,120,140,arrow);
  setfillstyle(1,LIGHTBLUE);
  bar(100,100,120,140);
  show_mouse();
  move_mouse(30,20);

  while(!quit)
   {
    while(kbhit())
     {
      key=getch();
      if(key==80)
       {
	if(status==3)
	 status=1;
	else
	 status++;
       }
      else
       if(key==72)
	{
	 if(status==1)
	  status=3;
	 else
	  status--;
	}
       else
	if(key==27)
	 {
	  if(status!=3)
	   status=3;
	 }
	else
	 if(key==13)
	  {
	   ButtonStatus=1;
	  }

      switch(status)
       {
	case 1 : move_mouse(320,150);
		 option=0;
		 break;
	case 2 : move_mouse(320,250);
		 option=0;
		 break;
	case 3 : move_mouse(320,350);
		 option=0;
		 break;
       }//switch
     }//while kbhit

    _AX=3;
    geninterrupt(0X33);
    x=_CX;
    y=_DX;

    if(key!=13)
     ButtonStatus=_BX;
    else
     key=0;

    if(x>160&&x<xx-160&&y>140&&y<200)
     {
      if(option!=1)
       {
	hide_mouse();
	setfillstyle(1,LIGHTBLUE);
	bar(100,100,120,400);
	putimage(100,140,arrow,XOR_PUT);
	show_mouse();
	option=1;
       }
     }
    else
     if(x>160&&x<xx-160&&y>240&&y<300)
      {
       if(option!=2)
	{
	 hide_mouse();
	 setfillstyle(1,LIGHTBLUE);
	 bar(100,100,120,400);
	 putimage(100,240,arrow,XOR_PUT);
	 show_mouse();
	 option=2;
	}
      }
     else
      if(x>160&&x<xx-160&&y>340&&y<400)
       {
	if(option!=3)
	 {
	  hide_mouse();
	  setfillstyle(1,LIGHTBLUE);
	  bar(100,100,120,400);
	  putimage(100,340,arrow,XOR_PUT);
	  show_mouse();
	  option=3;
	 }
       }
      else
       {
	status=0;
	option=0;
	continue;
       }

    if(ButtonStatus)
     {
      hide_mouse();
      switch(option)
       {
	case 1 : delay(100);
		 push_frame(160,140,xx-160,200,DARKGRAY,WHITE);
		 delay(100);
		 frame(160,140,xx-160,200,WHITE,DARKGRAY,LIGHTGRAY);
		 delay(100);
		 cleardevice();
		 closegraph();
		 mnx=0;mny=0;mxx=0;mxy=0;
		 recog();
		 init_graphic();
		 break;

	case 2 : delay(100);
		 push_frame(160,240,xx-160,300,DARKGRAY,WHITE);
		 delay(100);
		 frame(160,240,xx-160,300,WHITE,DARKGRAY,LIGHTGRAY);
		 delay(100);
		 cleardevice();
		 closegraph();
		 credits();
		 init_graphic();
		 break;

	case 3 : delay(100);
		 push_frame(160,340,xx-160,400,DARKGRAY,WHITE);
		 delay(100);
		 frame(160,340,xx-160,400,WHITE,DARKGRAY,LIGHTGRAY);
		 delay(100);
		 free(arrow);
		 cleardevice();
		 closegraph();
		 clrscr();
		 exit(0);
	default: show_mouse();
		 continue;
       }

      if(!quit)
       {
	main_menu();
	show_mouse();
	status=1;
	option=0;
       }//if
     }//if
   }//quit while
 }//main

void main_menu()
 {
  struct palettetype pal;

  cleardevice();
  setbkcolor(LIGHTBLUE);

  frame(3,3,xx-3,yy-3,LIGHTGRAY,DARKGRAY,LIGHTBLUE);
  push_frame(3+3,3+3,xx-3-3,yy-3-3,DARKGRAY,LIGHTGRAY);
	//	main menu screen

  settextjustify(1,1);

  setcolor(WHITE);
  settextstyle(0,0,2);
  outtextxy(xx/2,60,"Recognization Text Software");

  frame(160,140,xx-160,200,WHITE,DARKGRAY,LIGHTGRAY);
  outtextxy(xx/2,yy/2-70,"RECOGNIZATION TEXT");
	//	recognization text button
  frame(160,240,xx-160,300,WHITE,DARKGRAY,LIGHTGRAY);
  outtextxy(xx/2,yy/2+30,"CREDITS");
	//	credits button
  frame(160,340,xx-160,400,WHITE,DARKGRAY,LIGHTGRAY);
  outtextxy(xx/2,yy/2+130,"EXIT");
	//	exit button
 }

void init_graphic()
 {
  initgraph(&gdriver,&gmode,BGIpath);
  errorcode=graphresult();

  if(errorcode!=grOk)
   {
    printf("Graphics error. %s\n",grapherrormsg(errorcode));
    printf("Press any key to HALT.");
    getch();
    exit(1);
   }
  xx=getmaxx();
  yy=getmaxy();
 }

void init_mouse()
 {
  char status;
  _AX=0;
  geninterrupt(0X33);
  status=_AX;
  if(status!=-1)
   return;
 }

void show_mouse()
 {
  _AX=1;
  geninterrupt(0X33);
 }

void hide_mouse()
 {
  _AX=2;
  geninterrupt(0X33);
 }

void move_mouse(int x,int y)
 {
  _AX=4;
  _CX=x;
  _DX=y;
  geninterrupt(0X33);
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

void shadow(int ax,int ay,char *tex)
 {
  setcolor(DARKGRAY);
  outtextxy(ax+2,ay+2,tex);
  setcolor(WHITE);
  outtextxy(ax,ay,tex);
 }

void shadowy(int ax,int ay,char *tex)
 {
  setcolor(DARKGRAY);
  outtextxy(ax+2,ay+2,tex);
  setcolor(YELLOW);
  outtextxy(ax,ay,tex);
 }

void recog()
 {
  int quit=0,key,ButtonStatus,x,y;
  unsigned int bufsize;

  init_graphic();
  cleardevice();

  recog_screen();

  while(!quit)
   {
    show_mouse();
    while(kbhit())
     {
      key=getch();
      if(key==27)
       {
	move_mouse(xx-10-140,yy-10-15);
	delay(100);
	ButtonStatus=1;
       }
      else
       if(key=='c')
	{
	 move_mouse(xx-10-140,yy-10-45);
	 delay(100);
	 ButtonStatus=1;
	}
       else
	if(key=='r')
	 {
	  move_mouse(xx-10-140,yy-10-75);
	  delay(100);
	  ButtonStatus=1;
	 }
	else
	 if(key=='t')
	  {
	   move_mouse(xx-10-140,yy-10-105);
	   delay(100);
	   ButtonStatus=1;
	  }
	 else
	  if(key=='o')
	   {
	    move_mouse(xx-10-140,yy-10-135);
	    delay(100);
	    ButtonStatus=1;
	   }
     }//while kbhit

    _AX=3;
    geninterrupt(0X33);
    x=_CX;
    y=_DX;

    if(key!=27&&key!='c'&&key!='r'&&key!='t'&&key!='o')
     ButtonStatus=_BX;
    else
     key=0;

    if(ButtonStatus)
     {
      hide_mouse();
      settextjustify(1,1);

      if(x>10+6&&y>80+6&&x<10+150-6&&y<80+150-6)
       {
	setcolor(BLACK);
	circle(x,y,1);
	circle(x,y,2);
	circle(x,y,3);
	circle(x,y,4);
	circle(x,y,5);
       }
      else
       if(x>(xx-10-150)&&y>(yy-10-145)&&x<(xx-10-10)&&y<(yy-10-130))
	{
	 delay(100);
	 push_frame(xx-10-150,yy-10-145,xx-10-10,yy-10-130,DARKGRAY,WHITE);
	 delay(100);
	 frame(xx-10-150,yy-10-145,xx-10-10,yy-10-130,WHITE,DARKGRAY,LIGHTGRAY);
	 setcolor(BLACK);
	 outtextxy(xx-10-150+70,yy-10-145+8,"Open File");
	 delay(100);
	 open_file(bufsize);
	}
       else
	if(x>(xx-10-150)&&y>(yy-10-115)&&x<(xx-10-10)&&y<(yy-10-100))
	 {
	  delay(100);
	  push_frame(xx-10-150,yy-10-115,xx-10-10,yy-10-100,DARKGRAY,WHITE);
	  delay(100);
	  frame(xx-10-150,yy-10-115,xx-10-10,yy-10-100,WHITE,DARKGRAY,LIGHTGRAY);
	  setcolor(BLACK);
	  outtextxy(xx-10-150+70,yy-10-115+8,"Teach ...");
	  delay(100);
	  scanline(&bufsize);
	  teach___(bufsize);
	 }
	else
	 if(x>(xx-10-150)&&y>(yy-10-85)&&x<(xx-10-10)&&y<(yy-10-70))
	  {
	   delay(100);
	   push_frame(xx-10-150,yy-10-85,xx-10-10,yy-10-70,DARKGRAY,WHITE);
	   delay(100);
	   frame(xx-10-150,yy-10-85,xx-10-10,yy-10-70,WHITE,DARKGRAY,LIGHTGRAY);
	   setcolor(BLACK);
	   outtextxy(xx-10-150+70,yy-10-85+8,"Recognize Text");
	   delay(100);
	   check_text();
	  }
	 else
	  if(x>(xx-10-150)&&y>(yy-10-55)&&x<(xx-10-10)&&y<(yy-10-40))
	   {
	    delay(100);
	    push_frame(xx-10-150,yy-10-55,xx-10-10,yy-10-40,DARKGRAY,WHITE);
	    delay(100);
	    frame(xx-10-150,yy-10-55,xx-10-10,yy-10-40,WHITE,DARKGRAY,LIGHTGRAY);
	    setcolor(BLACK);
	    outtextxy(xx-10-150+70,yy-10-55+8,"Clear Screen");
	    delay(100);
	    cleardevice();
	    recog_screen();
	   }
	  else
	   if(x>(xx-10-150)&&y>(yy-10-25)&&x<(xx-10-10)&&y<(yy-10-10))
	    {
	     delay(100);
	     push_frame(xx-10-150,yy-10-25,xx-10-10,yy-10-10,DARKGRAY,WHITE);
	     delay(100);
	     frame(xx-10-150,yy-10-25,xx-10-10,yy-10-10,WHITE,DARKGRAY,LIGHTGRAY);
	     setcolor(BLACK);
	     outtextxy(xx-10-150+70,yy-10-25+8,"Return to MENU");
	     delay(100);
	     cleardevice();
	     closegraph();
	     return;
	    }
     }//if
    else
     {
      if(x>(xx-10-150)&&y>(yy-10-145)&&x<(xx-10-10)&&y<(yy-10-130))
       stat_cha='o';
      else
       if(x>(xx-10-150)&&y>(yy-10-115)&&x<(xx-10-10)&&y<(yy-10-100))
	stat_cha='t';
       else
	if(x>(xx-10-150)&&y>(yy-10-85)&&x<(xx-10-10)&&y<(yy-10-70))
	 stat_cha='r';
	else
	 if(x>(xx-10-150)&&y>(yy-10-55)&&x<(xx-10-10)&&y<(yy-10-40))
	  stat_cha='c';
	 else
	  if(x>(xx-10-150)&&y>(yy-10-25)&&x<(xx-10-10)&&y<(yy-10-10))
	   stat_cha='m';
	  else
	   stat_cha='h';
	  if(stat_cha!=stat_cur)
	   status_window();
     }//else
   }//quit while
 }

void status_window()
 {
  settextjustify(1,1);
  setfillstyle(SOLID_FILL,BLACK);
  bar(10+10+5,330+60+5,xx-10-200-5,yy-10-10-5);
  stat_cur=stat_cha;

  switch(stat_cha)
   {
    case 'o' : shadowy(10+10+410/2,330+60+5+5,"HELP : Open File");
	       shadowy(10+10+410/2,330+60+20+5,"Just click the Open button to open FILE");
	       shadowy(10+10+410/2,330+60+35+5,"then type in your FILENAME");
	       shadowy(10+10+410/2,330+60+50+5,"Try it...");
						//	display open help
	       break;
    case 't' : shadowy(10+10+410/2,330+60+5+5,"HELP : Teach ...");
	       shadowy(10+10+410/2,330+60+20+5,"Just click the Teach button to TEACH");
	       shadowy(10+10+410/2,330+60+35+5,"then type in your teach CHARACTER");
	       shadowy(10+10+410/2,330+60+50+5,"Try it...");
						//	display teach help
	       break;
    case 'r' : shadowy(10+10+410/2,330+60+5+5,"HELP : Recognize Text");
	       shadowy(10+10+410/2,330+60+20+5,"Just click the Recognize button to recognize text");
	       shadowy(10+10+410/2,330+60+35+5,"then the recognized text will display at above");
	       shadowy(10+10+410/2,330+60+50+5,"Try it...");
						//	display recognize help
	       break;
    case 'c' : shadowy(10+10+410/2,330+60+5+5,"HELP : Clear");
	       shadowy(10+10+410/2,330+60+20+5,"Just click the clear button to CLEAR screen");
	       shadowy(10+10+410/2,330+60+35+5,"then conticue to draw");
	       shadowy(10+10+410/2,330+60+50+5,"Try it...");
						//	display clear help
	       break;
    case 'm' : shadowy(10+10+410/2,330+60+5+5,"HELP : Return to MENU");
	       shadowy(10+10+410/2,330+60+20+5,"Just click the that button to");
	       shadowy(10+10+410/2,330+60+35+5,"then it will go back to MAIN MENU");
	       shadowy(10+10+410/2,330+60+50+5,"Try it...");
						//	display return to menu help
	       break;
    default  : shadowy(10+10+410/2,330+60+5+5," Thanks for using this software ");
	       shadowy(10+10+410/2,330+60+20+5," Just move the mouse to the Draw Area,");
	       shadowy(10+10+410/2,330+60+35+5," then drag the mouse when you want to draw.");
	       shadowy(10+10+410/2,330+60+50+5," Nice Try ...");
						//	display status window
   }//switch
 }

void recog_screen()
 {
  frame(10,10,xx-10,10+60,LIGHTGREEN,GREEN,LIGHTBLUE);
  push_frame(10+3,10+3,xx-10-3,10+60-3,GREEN,LIGHTGREEN);
  settextjustify(1,1);
  settextstyle(0,0,2);
  shadowy(xx/2-150/2,40,"Recognization Text Software");
  settextjustify(2,2);
  settextstyle(0,0,0);
  shadow(xx-15,45,"    Design By    ");
  shadow(xx-15,55,"Mrunal Bhatt ");
	// header area

  frame(10,80,10+150,80+150,LIGHTGRAY,DARKGRAY,WHITE);//LIGHTGREEN,GREEN,WHITE);
  push_frame(10+3,80+3,10+150-3,80+150-3,DARKGRAY,LIGHTGRAY);//GREEN,LIGHTGREEN);
  settextjustify(1,1);
  shadowy(10+75,80+150+20,"Draw Area");
	//	display draw area
  frame(10+230,80,10+150+230,80+150,LIGHTGRAY,DARKGRAY,WHITE);////LIGHTGREEN,GREEN,WHITE);
  push_frame(10+3+230,80+3,10+150-3+230,80+150-3,DARKGRAY,LIGHTGRAY);//GREEN,LIGHTGREEN);
  settextjustify(1,1);
  shadowy(10+230+75,80+150+20,"Data Area");
	//	display data area
  frame(10+470,80,10+150+470,80+150,LIGHTGRAY,DARKGRAY,WHITE);////LIGHTGREEN,GREEN,WHITE);
  push_frame(10+3+470,80+3,10+150-3+470,80+150-3,DARKGRAY,LIGHTGRAY);//GREEN,LIGHTGREEN);
  settextjustify(1,1);
  shadowy(10+470+75,80+150+20,"Display Teach Area");
	//	display teach area
  frame(10,300,xx-10,yy-10,LIGHTGREEN,GREEN,LIGHTBLUE);
  push_frame(10+3,300+3,xx-10-3,yy-10-3,GREEN,LIGHTGREEN);
	//	lower window
  frame(10+10,300+10,xx-10-320,yy-10-90,DARKGRAY,LIGHTGRAY,BLACK);
	//	display text area in lower window
  frame(10+10,330+60,xx-10-200,yy-10-10,DARKGRAY,LIGHTGRAY,BLACK);
  settextjustify(1,1);
  shadowy(10+10+410/2,330+60+5+5," Thanks for using this software ");
  shadowy(10+10+410/2,330+60+20+5," Just move the mouse to the Draw Area,");
  shadowy(10+10+410/2,330+60+35+5," then drag the mouse when you want to draw.");
  shadowy(10+10+410/2,330+60+50+5," Nice Try ...");
	//	display status window
  frame(xx-10-150,yy-10-145,xx-10-10,yy-10-130,WHITE,DARKGRAY,LIGHTGRAY);
  setcolor(BLACK);
  outtextxy(xx-10-150+70,yy-10-145+8,"Open File");
	//	open file button
  frame(xx-10-150,yy-10-115,xx-10-10,yy-10-100,WHITE,DARKGRAY,LIGHTGRAY);
  setcolor(BLACK);
  outtextxy(xx-10-150+70,yy-10-115+8,"Teach ...");
	//	Teach ... button

  frame(xx-10-150,yy-10-85,xx-10-10,yy-10-70,WHITE,DARKGRAY,LIGHTGRAY);
  setcolor(BLACK);
  outtextxy(xx-10-150+70,yy-10-85+8,"Recognize Text");
	//	recognize text button
  frame(xx-10-150,yy-10-55,xx-10-10,yy-10-40,WHITE,DARKGRAY,LIGHTGRAY);
  setcolor(BLACK);
  outtextxy(xx-10-150+70,yy-10-55+8,"Clear Screen");
	//	clear screen button
  frame(xx-10-150,yy-10-25,xx-10-10,yy-10-10,WHITE,DARKGRAY,LIGHTGRAY);
  setcolor(BLACK);
  outtextxy(xx-10-150+70,yy-10-25+8,"Return to MENU");
	//	return to menu button
 }

void scanline(unsigned int *bufsize)
 {
  int s_x,s_y,l_x,l_y;
  int i,j,x1_;
  int x1,x2,y1,y2;
  int off_s_x,off_s_y;

  mnx=MAX;
  mny=MAX;
  mxx=0;
  mxy=0;

  *bufsize=sizeof(image_save);

  for(int jj=0;jj<MAX;jj++)
   for(int ii=0;ii<MAX;ii++)
    {
     if(getpixel(ii+offsetx,jj+offsety)==BLACK)
      {
       if(ii<mnx)
	mnx=ii;
       if(jj<mny)
	mny=jj;
       if(ii>mxx)
	mxx=ii;
       if(jj>mny)
	mxy=jj;
      }
    }

  x1=mnx;
  x2=mxx;
  y1=mny;
  y2=mxy;

  l_x=x2-x1;
  l_y=y2-y1;
  l_x+=6;
  l_y+=6;

  s_x=l_x/scale;
  s_y=l_y/scale;
  off_s_x=s_x;
  off_s_y=s_y;

	/* read the image */
  for(int b=0;b<scale;b++)
   {
    x1_=0;
    for(int a=0;a<scale;a++)
     {
      for(int j=0;j<s_y;j++)
       for(int i=0;i<s_x;i++)
	{
	 if(a==scale-1)
	  s_x=off_s_x+(l_x%scale);
	 else
	  s_x=off_s_x;

	 if(b==scale-1)
	  s_y=off_s_y+(l_y%scale);
	 else
	  s_y=off_s_y;

	 image_save[a][b]=getpixel(i+x1+x1_+offsetx,j+y1+offsety);

	 if((image_save[a][b])==BLACK)
	  {
	   i=s_x;
	   j=s_y;
	  }
	}//for
      x1_+=s_x;
     }//for
    y1+=s_y;
   }//for
	/* display the image */
  for(int m=0;m<scale;m++)
   for(int n=0;n<scale;n++)
    {
     if((image_save[n][m])==BLACK)
      {
       setcolor(BLACK);
       circle(n*MAX/scale+dis_offx+1+3+4,m*MAX/scale+dis_offy+1+3+4,4);
      }
     if((image_save[n][m])==WHITE)
      {
       setcolor(WHITE);
       circle(n*MAX/scale+dis_offx+1+3+4,m*MAX/scale+dis_offy+1+3+4,4);
      }
     if(image_save[n][m]==BLACK)
      image_save[n][m]=1+'0';
     else
      if(image_save[n][m]==WHITE)
       image_save[n][m]=0+'0';
    }//for
 }

void check_text()
 {
  int handle,per_match;
  char data[20],*FileName,*ext,sample[3],cor_text[3];
  int m,n;
  unsigned int bufsize;
  char backup_num='\0',rec_num='\0';
  char rec_sam[3];
  int per_max,no_file,total_file;

  setfillstyle(SOLID_FILL,BLACK);
  bar(30-5,265-2,200+100,265+8);
  bar(30-5,278-2,30+300,278+8);
  scanline(&bufsize);
  FileName="data";
  ext=".rec";
  backup_num='0';
  cor_text[0]='0';
  cor_text[1]='\0';
  sample[0]='0';
  sample[1]='\0';
  per_max=0;
  total_file=0;

  for(m=0;m<scale;m++)
   for(n=0;n<scale;n++)
    {
     if(image_save[n][m]=='1')
      image_save[n][m]=BLACK;
     else
      if(image_save[n][m]=='0')
       image_save[n][m]=WHITE;
    }

  do
   {
    per_match=0;
    for(int i=0;i<20;i++)
     data[i]='\0';
    if(backup_num!=cor_text[0])
     {
      backup_num=cor_text[0];
      sample[0]='0';
      sample[1]='\0';
     }
    strcpy(data,cor_text);
    strcat(data,FileName);
    strcat(data,sample);
    strcat(data,ext);

    if((handle=open(data,O_RDWR|O_TEXT,S_IWRITE|S_IREAD))==-1)
     {
      no_file=1;//return;
     }
    else
     if((read(handle,image_data,bufsize)) == -1)
      {
       outtextxy(30,278,"Read Failed. ");
       no_file=1;//return;
      }
     else
      {
       no_file=0;
       total_file++;
      }
    close(handle);
		/* display the image */
    if(!no_file)
     for(m=0;m<scale;m++)
      for(n=0;n<scale;n++)
       {
	if(image_data[n][m]=='1')
	 image_data[n][m]=BLACK;
	else
	 if(image_data[n][m]=='0')
	  image_data[n][m]=WHITE;

	setcolor(image_data[n][m]);
	circle(n*MAX/scale+dis_datax+1+3+4,m*MAX/scale+dis_datay+1+3+4,4);

	if(image_save[n][m]==image_data[n][m])
	 {
	  per_match++;
	 }
       }

      if(per_max<per_match)
       {
	per_max=per_match;
	rec_num=cor_text[0];
	strcpy(rec_sam,sample);
       }

      if( (((cor_text[0]<='z')&&(cor_text[0]>='a'))
	  || ((cor_text[0]<='9')&&(cor_text[0]>='0')))
	  && (atoi(sample)<=99&&!no_file) )
       {
	int num;
	num=atoi(sample)+1;
	sample[0]='\0';
	sample[1]='\0';
	itoa(num,sample,10);
       }
      else
       if(cor_text[0]=='9')
	{
	 cor_text[0]='a';
	}
       else
	if((cor_text[0]<'9'||cor_text[0]>='0')&&no_file)
	 {
	  ++cor_text[0];
	 }
	else
	 if((cor_text[0]<'z'||cor_text[0]>='a')&&no_file)
	  {
	   ++cor_text[0];
	  }

   } while( ((cor_text[0]<='z')&&(cor_text[0]>='a'))
	    || ((cor_text[0]<='9')&&(cor_text[0]>='0'))
	    || (!no_file) );

  setfillstyle(SOLID_FILL,BLACK);
  bar(10+10+5,300+10+5,xx-10-320-5,yy-10-90-5);
  settextjustify(0,2);
  sprintf(buffer,"Percent Macth MAX = %d\%  ",per_max);
  shadow(30,320,buffer);
  sprintf(buffer,"Recognized NUMBER = %c ",rec_num);
  shadow(30,340,buffer);
  sprintf(buffer,"Total Data file   = %d files ",total_file);
  shadow(30,360,buffer);

  cor_text[0]=rec_num;
  cor_text[1]='\0';
  strcpy(sample,rec_sam);

  for(int i=0;i<10;i++)
   data[i]='\0';
  strcpy(data,cor_text);
  strcat(data,FileName);
  strcat(data,sample);
  strcat(data,ext);

  if((handle=open(data,O_RDWR|O_TEXT,S_IWRITE|S_IREAD))==-1)
   {
    sprintf(buffer,"Error: %s ",strerror(errno));
    buffer[strlen(buffer)-2]='\0';
    outtextxy(30,278,buffer);
   }

  if((read(handle,image_data,bufsize)) == -1)
   {
    sprintf(buffer,"Error: %s ",strerror(errno));
    buffer[strlen(buffer)-2]='\0';
    outtextxy(30,278,buffer);
   }
  close(handle);

  for(m=0;m<scale;m++)
   for(n=0;n<scale;n++)
    {
     if(image_data[n][m]=='1')
      image_data[n][m]=BLACK;
     else
      if(image_data[n][m]=='0')
       image_data[n][m]=WHITE;

     setcolor(image_data[n][m]);
     circle(n*MAX/scale+dis_datax+1+3+4,m*MAX/scale+dis_datay+1+3+4,4);
    }
 }

void open_file(unsigned int bufsize)
 {
  char FileName[12];//,*path;
  int handle;

  setfillstyle(SOLID_FILL,BLACK);
  bar(30-5,265-2,200+100,265+8);
  bar(30-5,278-2,30+300,278+8);
  setcolor(WHITE);
  settextjustify(0,2);
  outtextxy(30,265,"Enter File Name : ");
  gotoxy(1,1);
  outtextxy(200,265,"_");
  for(int j=0;j<12;j++)
   FileName[j]='\0';

  int i=0;
  while(FileName[i-1]!=13&&i<9)
   {
    if(FileName[i-1]=='\0')
     {
      outtextxy(30,278,"BAD input character !!! ");
      return;
     }
    FileName[i++]=getche();
    if((FileName[i-1]=='\b')&&(i==1))
     FileName[--i]='\0';
    else
     if(FileName[i-1]=='\b')
      {
       FileName[i-1]='\0';
       FileName[i-2]='\0';
       i-=2;
      }
    bar(200-5,265-2,200+100,265+8);
    outtextxy(200,265,FileName);
    outtextxy(200+textwidth(FileName),265,"_");
   }
  FileName[i-1]='\0';
  bar(200-5,265-2,200+100,265+8);
  outtextxy(200,265,FileName);
  strcat(FileName,".rec");

  if((handle=open(FileName,O_RDWR|O_TEXT,S_IWRITE|S_IREAD))==-1)
   {
    sprintf(buffer,"Error: %s ",strerror(errno));
    buffer[strlen(buffer)-2]='\0';
    outtextxy(30,278,buffer);
    return;
   }

  if((read(handle,image_save,bufsize)) == -1)
   {
    outtextxy(30,278,"Read Failed. ");
    return;
   }
  close(handle);
	/* display the image */
  for(int m=0;m<scale;m++)
   for(int n=0;n<scale;n++)
    {
     if(image_save[n][m]=='1')
      image_save[n][m]=BLACK;
     else
      if(image_save[n][m]=='0')
       image_save[n][m]=WHITE;

     setcolor(image_save[n][m]);
     circle(n*MAX/scale+dis_offx+1+3+4,m*MAX/scale+dis_offy+1+3+4,4);
    }
 }

void teach___(unsigned int bufsize)
 {
  char data[20];
  int handle;
  char sample[3],FileName[3];//,*path='\0';

  sample[0]='0';
  sample[1]='\0';
  FileName[0]='\0';
  FileName[1]='\0';
  setfillstyle(SOLID_FILL,BLACK);
  bar(30-5,265-2,200+100,265+8);
  bar(30-5,278-2,30+300,278+8);
  setcolor(WHITE);
  settextjustify(0,2);
  outtextxy(30,265,"Enter TEACH number : ");
  gotoxy(1,1);
  FileName[0]=getche();
  outtextxy(200,265,FileName);

  if(!FileName[0]||FileName[0]=='\r'||FileName[0]==27)
   {
    outtextxy(30,278,"Please key in NUMBER to teach ...");
    return;
   }
  for(int i=0;i<20;i++)
   data[i]='\0';

  strcpy(data,FileName);
  strcat(data,"data");
  strcat(data,sample);
  strcat(data,".rec");
  while(file_exists(data))
   {
    if(atoi(sample)>=99)
     return;
    int num;
    num=atoi(sample)+1;
    sample[0]='\0';
    sample[1]='\0';
    itoa(num,sample,10);
    strcpy(data,FileName);
    strcat(data,"data");
    strcat(data,sample);
    strcat(data,".rec");
   }

  if(!file_exists(data))
   {
    if((handle=open(data,O_CREAT|O_RDWR|O_BINARY,S_IWRITE|S_IREAD))==-1)
     {
      sprintf(buffer,"Error: %s ",strerror(errno));
      buffer[strlen(buffer)-2]='\0';
      outtextxy(30,278,buffer);
      return;
     }
    write(handle,image_save,bufsize);
    close(handle);
   }
 }

int file_exists(char *filename)
 {
  return (access(filename, 0) == 0);
 }

void credits()
 {
  int quit=0,ButtonStatus;

  init_graphic();
  cleardevice();

  xx=getmaxx();
  yy=getmaxy();

  frame(10,10,xx-10,yy-10,LIGHTGREEN,GREEN,LIGHTBLUE);
  push_frame(10+3,10+3,xx-10-3,yy-10-3,GREEN,LIGHTGREEN);
	//	credits screen

  settextjustify(1,1);
  settextstyle(0,0,2);
  setcolor(YELLOW);
  outtextxy(xx/2,yy/2-200,"My Names");
  setcolor(WHITE);
  outtextxy(xx/2,yy/2-150,"Aaa bb");
  outtextxy(xx/2,yy/2-100,"E-mail : ");
  outtextxy(xx/2,yy/2-50,"aaabb@hotmail.com");
  outtextxy(xx/2,yy/2,"Address : ");
  outtextxy(xx/2,yy/2+50,"City, Country.");

  settextstyle(0,0,0);
  outtextxy(xx/2,yy-20,"Press any key OR click to exit ... ");

  while(!quit)
   {
    while(kbhit())
     {
      cleardevice();
      closegraph();
      return;
     }

    _AX=3;
    geninterrupt(0X33);
    ButtonStatus=_BX;

    if(ButtonStatus)
     {
      cleardevice();
      closegraph();
      return;
     }
   }
 }
