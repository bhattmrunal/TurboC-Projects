#include<dos.h>
#include<graphics.h>
#include<mouse.h>
#include<string.h>
#include<alloc.h>
#include<stdio.h>

#define chkmspos  mousepos(&mx,&my);
#define ltbtpr if(ltbutton()==1){
#define rtbtpr if(rtbutton()==2){
#define mstwhl while(quit!=1){
#define endblk }
#define initms initmouse(); showmouse();

int check_popup(int);
int quit,changes;
struct click_button
{
 int bposx,bposy,bxwidth,bywidth;
 char *string;
 void (*func)();
}buttons[25];
struct textf
{
 int x1,y1,length;
 int textcolor;
}text[20];
struct pop_up
{
 int x1,y1,x2,y2;
 int itemnos;
 char *items[10];
 int returnno;
}popup[3];

unsigned image_size;
void *image_ptr;

char *itm[10];
char *ostr;
int total_buttons,total_textbox,yesno,pop,ox1,ox2,oy1,oy2,oz1,zzgreat;
int mx,my,in,txt_select;
static int rin;

void ok(),yes(),no(),select_menu(int,int,int,int,char*,int);

/****************** General Segment *************************/
void frame_box(int x1,int y1,int x2,int y2,int col)
{
 int cl1,cl2,cl3;
 if(col!=0)
 {
  cl1=7;
  cl2=15;
  cl3=8;
 }
 else
 {
  cl1=0;
  cl2=0;
  cl3=0;
 }
 setcolor(1);
 rectangle(x1+3,y1+3,x2-3,y2-3);
 setfillstyle(1,1);
 floodfill(x1+10,y1+10,1);

 setcolor(cl1);
 rectangle(x1+3,y1+3,x2-3,y2-3);
 setfillstyle(1,cl1);
 floodfill(x1+10,y1+10,cl1);

 setcolor(cl2);

 line(x1+2,y1+2,x2-2,y1+2);
 line(x1+1,y1+1,x2-1,y1+1);
 line(x1,y1,x2,y1);

 line(x1+2,y1+2,x1+2,y2-2);
 line(x1+1,y1+1,x1+1,y2-1);
 line(x1,y1,x1,y2);

 setcolor(cl3);

 line(x2-2,y1+2,x2-2,y2-2);
 line(x2-1,y1+1,x2-1,y2-1);
 line(x2,y1,x2,y2);

 line(x1+2,y2-2,x2-2,y2-2);
 line(x1+1,y2-1,x2-1,y2-1);
 line(x1,y2,x2,y2);
}
void ok()
{
 //Empty
}
void yes()
{
 yesno=1;
}
void no()
{
 yesno=0;
}

/***************End of General segment  ****************************/
/**************  Button Section ***********************/
void button(int id_no,int posx,int posy,int xwidth,int ywidth,char *str,void (*fun)())
{
 int len;
 setcolor(7);
 rectangle(posx,posy,posx+xwidth,posy+ywidth);
 setfillstyle(1,7);
 floodfill(posx+3,posy+3,7);
 setcolor(15);
 line(posx-1,posy-1,posx+xwidth,posy-1);
 line(posx-2,posy-2,posx+xwidth+1,posy-2);
 line(posx-3,posy-3,posx+xwidth+2,posy-3);

 line(posx-1,posy+ywidth,posx-1,posy-1);
 line(posx-2,posy+ywidth+1,posx-2,posy-2);
 line(posx-3,posy+ywidth+2,posx-3,posy-2);

 setcolor(8);
 line(posx+xwidth,posy-1,posx+xwidth,posy+ywidth);
 line(posx+xwidth+1,posy-2,posx+xwidth+1,posy+ywidth+1);
 line(posx+xwidth+2,posy-3,posx+xwidth+2,posy+ywidth+2);

 line(posx-1,posy+ywidth,posx+xwidth,posy+ywidth);
 line(posx-2,posy+ywidth+1,posx+xwidth+1,posy+ywidth+1);
 line(posx-3,posy+ywidth+2,posx+xwidth+2,posy+ywidth+2);

 len=strlen(str);
 settextstyle(0,0,0);
 setcolor(1);
 outtextxy(posx-3+len+7,posy-3+(ywidth/2)-1,str);

 buttons[id_no].bposx=posx;
 buttons[id_no].bposy=posy;
 buttons[id_no].bxwidth=xwidth;
 buttons[id_no].bywidth=ywidth;
 buttons[id_no].string=str;
 buttons[id_no].func=fun;

 total_buttons++;
}
void opbutton(int id_no)
{
 int posx,posy,xwidth,ywidth,len;
 char *str;

 posx=buttons[id_no].bposx;
 posy=buttons[id_no].bposy;
 xwidth=buttons[id_no].bxwidth;
 ywidth=buttons[id_no].bywidth;
 str=buttons[id_no].string;

 setcolor(15);
 line(posx-1,posy-1,posx+xwidth,posy-1);
 line(posx-2,posy-2,posx+xwidth+1,posy-2);
 line(posx-3,posy-3,posx+xwidth+2,posy-3);

 line(posx-1,posy+ywidth,posx-1,posy-1);
 line(posx-2,posy+ywidth+1,posx-2,posy-2);
 line(posx-3,posy+ywidth+2,posx-3,posy-2);

 setcolor(8);
 line(posx+xwidth,posy-1,posx+xwidth,posy+ywidth);
 line(posx+xwidth+1,posy-2,posx+xwidth+1,posy+ywidth+1);
 line(posx+xwidth+2,posy-3,posx+xwidth+2,posy+ywidth+2);

 line(posx-1,posy+ywidth,posx+xwidth,posy+ywidth);
 line(posx-2,posy+ywidth+1,posx+xwidth+1,posy+ywidth+1);
 line(posx-3,posy+ywidth+2,posx+xwidth+2,posy+ywidth+2);

 len=strlen(str);
 settextstyle(0,0,0);
 setcolor(1);
 outtextxy(posx-3+len+7,posy-3+(ywidth/2)-1,str);
}

void clbutton(int id_no)
{
 int posx,posy,xwidth,ywidth,len;
 char *str;

 posx=buttons[id_no].bposx;
 posy=buttons[id_no].bposy;
 xwidth=buttons[id_no].bxwidth;
 ywidth=buttons[id_no].bywidth;
 str=buttons[id_no].string;

 setcolor(8);
 line(posx-1,posy-1,posx+xwidth,posy-1);
 line(posx-2,posy-2,posx+xwidth+1,posy-2);
 line(posx-3,posy-3,posx+xwidth+2,posy-3);

 line(posx-1,posy+ywidth,posx-1,posy-1);
 line(posx-2,posy+ywidth+1,posx-2,posy-2);
 line(posx-3,posy+ywidth+2,posx-3,posy-2);

 setcolor(15);
 line(posx+xwidth,posy-1,posx+xwidth,posy+ywidth);
 line(posx+xwidth+1,posy-2,posx+xwidth+1,posy+ywidth+1);
 line(posx+xwidth+2,posy-3,posx+xwidth+2,posy+ywidth+2);

 line(posx-1,posy+ywidth,posx+xwidth,posy+ywidth);
 line(posx-2,posy+ywidth+1,posx+xwidth+1,posy+ywidth+1);
 line(posx-3,posy+ywidth+2,posx+xwidth+2,posy+ywidth+2);

 len=strlen(str);
 settextstyle(0,0,0);
 setcolor(4);
 outtextxy(posx-3+len+7,posy-3+(ywidth/2)-1,str);
}
void click(int button_id)
{
 int temx,temy;
 delay(100);
 mousepos(&temx,&temy);
 offmouse();
 clbutton(button_id);
 delay(120);
 opbutton(button_id);
 setmousepos(temx,temy);
 changes=1;
 showmouse();
 (*buttons[button_id].func)();
}
void btmonitor(int mox,int moy,int enable)
{
 int j;
 if(enable==1)
 {
  for(j=0;j<total_buttons;j++)
  {
   if(mox>buttons[j].bposx&&mox<buttons[j].bposx+buttons[j].bxwidth&&moy>buttons[j].bposy&&moy<buttons[j].bposy+buttons[j].bywidth)
   {
    click(j);
   }
  }
 }
}
void del_last_button()
{
 total_buttons--;
}
/*************** End of Button Segment ************************/

/**********************  Message box segment  **********************/
void msgbox_ok(char *msg,int xsize,int ysize)
{
 int maxx,maxy,midx,midy,x1,y1,x2,y2,st;
 maxx=getmaxx();
 maxy=getmaxy();

 midx=maxx/2;
 midy=maxy/2;
 st=0;
 if(xsize==0||ysize==0)
 {
  xsize=200;
  ysize=160;
 }
 x1=midx-(xsize/2);
 y1=midy-(ysize/2);
 x2=midx+(xsize/2);
 y2=midy+(ysize/2);

 offmouse();
 image_size=imagesize(x1,y1,x2,y2);
 image_ptr=malloc(image_size);
 getimage(x1,y1,x2,y2,image_ptr);

 frame_box(x1,y1,x2,y2,1);
 setcolor(4);
 outtextxy(x1+10,midy-30,msg);

 button(total_buttons,midx-15,midy+20,25,15,"OK",ok);

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
    click(total_buttons-1);
    delay(100);
    del_last_button();
    st=1;
   }
   else
   {
    printf("\007");
   }
  }
 }
 offmouse();
 frame_box(x1,y1,x2,y2,0);
 putimage(x1,y1,image_ptr,1);
 free(image_ptr);
 showmouse();
}
void msgbox_yn(char *msg,int xsize,int ysize)
{
 int maxx,maxy,midx,midy,x1,y1,x2,y2,st;
 maxx=getmaxx();
 maxy=getmaxy();

 midx=maxx/2;
 midy=maxy/2;
 st=0;
 if(xsize==0||ysize==0)
 {
  xsize=200;
  ysize=160;
 }
 x1=midx-(xsize/2);
 y1=midy-(ysize/2);
 x2=midx+(xsize/2);
 y2=midy+(ysize/2);

 offmouse();
 image_size=imagesize(x1,y1,x2,y2);
 image_ptr=malloc(image_size);
 getimage(x1,y1,x2,y2,image_ptr);

 frame_box(x1,y1,x2,y2,1);
 setcolor(4);
 outtextxy(x1+10,midy-30,msg);

 button(total_buttons,midx-45,midy+20,35,15,"Yes",yes);
 button(total_buttons,midx+30,midy+20,25,15,"No",no);

 setmousepos(mx,my);
 showmouse();

 while(st!=1)
 {
  showmouse();
  mousepos(&mx,&my);

  if(ltbutton()==1)
  {
   if(mx>(midx-45)&&mx<(midx-10)&&my>(midy+20)&&my<(midy+35))
   {
    click(total_buttons-2);
    del_last_button();
    del_last_button();
    st=1;
    break;
   }
   if(mx>(midx+30)&&mx<(midx+55)&&my>(midy+20)&&my<(midy+35))
   {
    click(total_buttons-1);
    del_last_button();
    del_last_button();
    st=1;
    break;
   }
   else
   {
    printf("\007");
   }
  }
 }
 offmouse();
 frame_box(x1,y1,x2,y2,0);
 putimage(x1,y1,image_ptr,1);
 free(image_ptr);
 showmouse();
}

/******************  End of Message box segment *********************/

/********************* Textbox Segment **********************/
void textbox(int id_no,int x1,int y1,int length)
{
 setcolor(15);
 rectangle(x1,y1,x1+length,y1+13);
 setfillstyle(1,15);
 floodfill(x1+3,y1+3,15);
 setcolor(0);
 line(x1,y1,x1+length,y1);
 line(x1,y1,x1,y1+13);
 text[total_textbox].x1=x1;
 text[total_textbox].y1=y1;
 text[total_textbox].length=length;
 total_textbox++;
}
/******************** End of textbox segment *************************/

/*******************  Input Box segment ************************************/
char* inputbox(char *msg)
{
 char ch[1],*ptr,str;
 int ix1,iy1,ix2,iy2,c,tx,ct,ctt;
 ix1=getmaxx()/2-150;
 ix2=getmaxx()/2+150;
 iy1=getmaxy()/2-90;
 iy2=getmaxy()/2+90;
 tx=0;

 frame_box(ix1,iy1,ix2,iy2,1);
 setcolor(4);
 outtextxy(ix1+5,iy1+30,msg);
 textbox(total_textbox,ix1+10,iy1+90,250);
 tx=text[0].x1+3;
 ct=0;
 while(c!=13)
 {
  c=getch();
  if(c!=13)
  {
   sprintf(ch,"%c",c);
   outtextxy(tx,text[0].y1+5,ch);
   printf("%c",ch[0]);
   *ptr=ch[0];
   ptr++;
   tx=tx+9;
   ct++;
  }
 }
 ctt=ct;
 while(ct!=0)
 {
  ptr--;
  ct--;
 }
 return ptr;
 /*while(ct!=ctt)
 {
  printf("%c",*ptr);
  ptr++;
  ct++;
 } */
}
/******************* End ofInput box segment  ***************************/
/******************** Popup menu segment ***************************/

int popup_menu(int menunos,int itemnos)//,char *items[])
{
 int x1,x2,y1,y2,i,z,tem_sel,sel,z1,z2,fin;

 zzgreat=0;
 for(i=0;i<itemnos;i++)
 {
  popup[menunos].items[i]=itm[i];
 }
 mousepos(&mx,&my);
 i=0;
 x1=mx;
 y1=my;
 x2=x1+80;
 y2=y1+(18*(itemnos));
 offmouse();

 popup[menunos].x1=x1;
 popup[menunos].y1=y1;
 popup[menunos].x2=x2;
 popup[menunos].y2=y2;
 popup[menunos].itemnos=itemnos;

 image_size=imagesize(x1,y1,x2,y2);
 image_ptr=malloc(image_size);
 getimage(x1,y1,x2,y2,image_ptr);
 frame_box(x1,y1,x2,y2,0);
 frame_box(x1,y1,x2,y2,1);

 z=y1+8;
// z1=y1+5;
 //z2=z1+15;
 for(;i<itemnos;i++)
 {
  setcolor(1);
  outtextxy(x1+40/2-5,z,popup[menunos].items[i]);
  z=z+15;
 }
 showmouse();
 mousepos(&mx,&my);
 sel=0;
 while(ltbutton()!=1||sel==0)
 {
  mousepos(&mx,&my);
  if(mx>x1+3&&mx<x2-3&&my>y1+3&&my<y2+3)
  {
   sel=check_popup(menunos);
  }
 }
 mousepos(&mx,&my);
 if(mx>x1+3&&mx<x2-3&&my>y1+3&&my<y2-3)
 {
  fin=sel;
  printf("%d",fin);
 }
 ox1=0;
 //z1=y1+5;
 //z2=z1+15;
 //z=y1+8;

 //delay(2000);
 offmouse();
 frame_box(x1,y1,x2,y2,0);
 putimage(x1,y1,image_ptr,1);
 free(image_ptr);
 showmouse();
 return fin;
}
int check_popup(int menun)
{
 int f,z1,z2,z,sel_made,zgreat;
 f=0;
 //zgreat=0;
 z1=popup[menun].y1+3;
 z2=z1+15;
 z=popup[menun].y1+8;
 in=0;
 while(f<popup[menun].itemnos)
 {
  mousepos(&mx,&my);
  if(my>z1&&my<z2)
  {
   showmouse();
   if(rin!=1)
   {
    select_menu(popup[menun].x1+3,z1,popup[menun].x2-3,z2,popup[menun].items[f],z);
    rin=1;
   }
   sel_made=f+1;
   return sel_made;
  }
  else
  {
   z1=z2;
   z2=z1+15;
   z=z+15;
   rin=0;
  }
  f++;
 }
 return 0;
}
void select_menu(int x1,int y1,int x2,int y2,char *str,int z)
{
 if(ox1!=0)
 {
 offmouse();
 setcolor(1);
 rectangle(ox1,oy1,ox2,oy2);
 setfillstyle(1,1);
 floodfill(ox1+5,oy1+5,1);
 setcolor(7);
 rectangle(ox1,oy1,ox2,oy2);
 setfillstyle(1,7);
 floodfill(ox1+5,oy1+5,7);
 setcolor(1);
 outtextxy(ox1+40/2-5,oz1,ostr);
 }
 //
 ox1=x1;
 oy1=y1;
 ox2=x2;
 oy2=y2;
 oz1=z;
 ostr=str;
 mousepos(&mx,&my);
 //offmouse();
 setcolor(1);
 rectangle(x1,y1,x2,y2);
 setfillstyle(1,1);
 floodfill(x1+5,y1+5,1);

 setcolor(0);
 rectangle(x1,y1,x2,y2);
 setfillstyle(1,0);
 floodfill(x1+5,y1+5,0);
 setcolor(15);
 outtextxy(x1+40/2-5,z,str);
 //setmousepos(mx,my);
 showmouse();
}
void qui()
{
 quit=1;
}
/******************** End of popup menu segment ********************/

