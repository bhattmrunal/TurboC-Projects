/*
  THIS SIMULATOR IS DESIGNED AND PROGRAMMED BY MRUNAL BHATT.
  FOR PROGRAMS PLEASE CONTACT

  1> Mob.+919822693522
  2>E-mail "bhattmrunal@yahoo.co.in"
*/

/* HEADER FILES & SUPPORTED FILES DECLARED */
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include<stdlib.h>
#include<process.h>
#include<time.h>
#include<alloc.h>
#include"d:\MYimpC~1\SIMULA~1\simmouse.cpp"
/* END OF HEADER FILES */

/* MACROS DEFINED */
#define BGIpath "\recog"

#define BTCOLOR 12
#define BTBORDER 4
#define TXTCOLOR 1
#define BGCOLOR 9
#define TXTBGCOLOR 13

#define xbtsz2 20
#define xbtsz3 30
#define xbtsz4 40
#define ybtsz 13

/* END OF MACROS */




/* ERRORS IN SIMULATOR */

/* END OF ERRORS */
/* FUNCTION DECLARATION */
void menubar();
void display(int);
void frame(int,int,int,int,int,int,int);
void push_frame(int,int,int,int,int,int);
void button(int,int,int,int,char *,int,int,int);
void pushbutton(int,int,int,int,char *,int,int,int);
void menu_button(int,int,int,int,char *);
void pmenu_button(int,int,int,int,char *);
void txtscreen(int);
//FRAMES
void regframe(int);
void datrframe(int);
void ariframe(int);
void logiframe(int);
void brnchframe(int);
void numberframe(int);
void stcframe(int);
void free();

/*END OF FUNCTION DECLARATION */

/* MAIN FUNCTION STARTS HERE */

void main(/*int argc,char argv[]*/)
{
 int gd=DETECT,gm,status,mx,my,co;
 initgraph(&gd,&gm,"BGIpath");
 menubar();
 display(9);
 status=0;
 co=0;
 if(initmouse()==0)
 {
  outtextxy(200,200,"NO MOUSE DRIVER LOADED ");
  exit(1);
 }
 showmouse();
  while(status!=1)
 {
  mousepos(&mx,&my);
  if(rtbutton()==2)
  {
   status=1;
  }
  if(ltbutton()==1)
  {
   if(mx>10&&mx<25&&my>50&&my<64)
   {
    pushbutton(10,50,25,64,"A",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(10,50,25,64,"A",BTCOLOR,BTBORDER,TXTCOLOR);
    setmousepos(mx,my);
   }
   if(mx>40&&mx<55&&my>50&&my<64)
   {
    pushbutton(40,50,55,64,"B",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(40,50,55,64,"B",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>65&&mx<80&&my>50&&my<64)
   {
    pushbutton(65,50,80,64,"C",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(65,50,80,64,"C",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>95&&mx<110&&my>50&&my<64)
   {
    pushbutton(95,50,110,64,"D",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(95,50,110,64,"D",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>120&&mx<135&&my>50&&my<64)
   {
    pushbutton(120,50,135,64,"E",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(120,50,135,64,"E",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>150&&mx<165&&my>50&&my<64)
   {
    pushbutton(150,50,165,64,"H",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(150,50,165,64,"H",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>175&&mx<190&&my>50&&my<64)
   {
    pushbutton(175,50,190,64,"L",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(175,50,190,64,"L",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>205&&mx<220&&my>50&&my<64)
   {
    pushbutton(205,50,220,64,"M",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(205,50,220,64,"M",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   /*FRAME TWO STARTED */

   if(mx>8&&mx<38&&my>100&&my<113)
   {
    pushbutton(8,100,8+xbtsz3,100+ybtsz,"MOV",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,100,8+xbtsz3,100+ybtsz,"MOV",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>48&&mx<48+xbtsz3&&my>100&&my<100+ybtsz)
   {
    pushbutton(48,100,48+xbtsz3,100+ybtsz,"MVI",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(48,100,48+xbtsz3,100+ybtsz,"MVI",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>88&&mx<88+xbtsz3&&my>100&&my<100+ybtsz)
   {
    pushbutton(88,100,88+xbtsz3,100+ybtsz,"LXI",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(88,100,88+xbtsz3,100+ybtsz,"LXI",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>128&&mx<128+xbtsz3&&my>100&&my<100+ybtsz)
   {
    pushbutton(128,100,128+xbtsz3,100+ybtsz,"LDA",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(128,100,128+xbtsz3,100+ybtsz,"LDA",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>168&&mx<168+xbtsz3&&my>100&&my<100+13)
   {
    pushbutton(168,100,168+xbtsz3,100+ybtsz,"STA",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(168,100,168+xbtsz3,100+ybtsz,"STA",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>8&&mx<48&&my>123&&my<123+13)
   {
    pushbutton(8,123,8+xbtsz4,123+ybtsz,"LHLD",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,123,8+xbtsz4,123+ybtsz,"LHLD",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>58&&mx<58+xbtsz4&&my>123&&my<123+13)
   {
    pushbutton(58,123,58+xbtsz4,123+ybtsz,"SHLD",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(58,123,58+xbtsz4,123+ybtsz,"SHLD",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>108&&mx<108+xbtsz4&&my>123&&my<123+ybtsz)
   {
    pushbutton(108,123,108+xbtsz4,123+ybtsz,"LDAX",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(108,123,108+xbtsz4,123+ybtsz,"LDAX",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>158&&mx<158+xbtsz4&&my>123&&my<123+ybtsz)
   {
    pushbutton(158,123,158+xbtsz4,123+ybtsz,"STAX",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(158,123,158+xbtsz4,123+ybtsz,"STAX",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>8&&mx<8+xbtsz4&&my>146&&my<146+ybtsz)
   {
    pushbutton(8,146,8+xbtsz4,146+ybtsz,"XCHG",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,146,8+xbtsz4,146+ybtsz,"XCHG",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>58&&mx<58+xbtsz4&&my>146&&my<146+ybtsz)
   {
    pushbutton(58,146,58+xbtsz4,146+ybtsz,"PCHL",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(58,146,58+xbtsz4,146+ybtsz,"PCHL",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>8&&mx<8+30&&my>195&&my<195+13)
   {
    pushbutton(8,195,8+xbtsz3,195+ybtsz,"INR",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,195,8+xbtsz3,195+ybtsz,"INR",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>48&&mx<48+30&&my>195&&my<195+13)
   {
    pushbutton(48,195,48+xbtsz3,195+ybtsz,"DCR",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(48,195,48+xbtsz3,195+ybtsz,"DCR",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>88&&mx<88+30&&my>195&&my<195+13)
   {
    pushbutton(88,195,88+xbtsz3,195+ybtsz,"INX",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(88,195,88+xbtsz3,195+ybtsz,"INX",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>128&&mx<128+30&&my>195&&my<195+13)
   {
    pushbutton(128,195,128+xbtsz3,195+ybtsz,"DCX",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(128,195,128+xbtsz3,195+ybtsz,"DCX",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>168&&mx<168+30&&my>195&&my<195+13)
   {
    pushbutton(168,195,168+30,195+13,"ADD",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(168,195,168+30,195+13,"ADD",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>8&&mx<8+30&&my>218&&my<218+13)
   {
    pushbutton(8,218,8+xbtsz3,218+ybtsz,"SUB",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,218,8+xbtsz3,218+ybtsz,"SUB",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>48&&mx<48+30&&my>218&&my<218+13)
   {
    pushbutton(48,218,48+xbtsz3,218+ybtsz,"DAA",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(48,218,48+xbtsz3,218+ybtsz,"DAA",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>88&&mx<88+30&&my>218&&my<218+13)
   {
    pushbutton(88,218,88+xbtsz3,218+ybtsz,"ADC",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(88,218,88+xbtsz3,218+ybtsz,"ADC",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>128&&mx<128+30&&my>218&&my<218+13)
   {
    pushbutton(128,218,128+xbtsz3,218+ybtsz,"SBB",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(128,218,128+xbtsz3,218+ybtsz,"SBB",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>168&&mx<168+30&&my>218&&my<218+13)
   {
    pushbutton(168,218,168+xbtsz3,218+ybtsz,"CMP",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(168,218,168+xbtsz3,218+ybtsz,"CMP",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>8&&mx<8+30&&my>241&&my<241+13)
   {
    pushbutton(8,241,8+xbtsz3,241+ybtsz,"DAD",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,241,8+xbtsz3,241+ybtsz,"DAD",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>48&&mx<48+30&&my>241&&my<241+13)
   {
    pushbutton(48,241,48+xbtsz3,241+ybtsz,"ADI",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(48,241,48+xbtsz3,241+ybtsz,"ADI",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>88&mx<88+30&&my>241&my<241+13)
   {
    pushbutton(88,241,88+xbtsz3,241+ybtsz,"ACI",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(88,241,88+xbtsz3,241+ybtsz,"ACI",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>128&&mx<128+30&&my>241&&my<241+13)
   {
    pushbutton(128,241,128+xbtsz3,241+ybtsz,"SUI",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(128,241,128+xbtsz3,241+ybtsz,"SUI",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>168&&mx<168+30&&my>241&&my<241+13)
   {
    pushbutton(168,241,168+xbtsz3,241+ybtsz,"CPI",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(168,241,168+xbtsz3,241+ybtsz,"CPI",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   /*FRAME 4 STARTS HERE*/
   if(mx>8&&mx<8+30&&my>290&&my<290+13)
   {
    pushbutton(8,290,8+xbtsz3,290+ybtsz,"CMA",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,290,8+xbtsz3,290+ybtsz,"CMA",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>48&&mx<48+30&&my>290&&my<290+13)
   {
    pushbutton(48,290,48+xbtsz3,290+ybtsz,"STC",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(48,290,48+xbtsz3,290+ybtsz,"STC",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>88&&mx<88+30&&my>290&&my<290+13)
   {
    pushbutton(88,290,88+xbtsz3,290+ybtsz,"CMC",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(88,290,88+xbtsz3,290+ybtsz,"CMC",BTCOLOR,BTBORDER,TXTCOLOR);
   }

   if(mx>128&&mx<128+30&&my>290&&my<290+13)
   {
    pushbutton(128,290,128+xbtsz3,290+ybtsz,"RRC",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(128,290,128+xbtsz3,290+ybtsz,"RRC",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>168&&mx<168+30&&my>290&&my<290+13)
   {
    pushbutton(168,290,168+xbtsz3,290+ybtsz,"RAR",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(168,290,168+xbtsz3,290+ybtsz,"RAR",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>208&&mx<208+30&&my>290&&my<290+13)
   {
    pushbutton(208,290,208+xbtsz3,290+ybtsz,"RLC",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(208,290,208+xbtsz3,290+ybtsz,"RLC",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>8&&mx<8+30&&my>313&&my<313+13)
   {
    pushbutton(8,313,8+xbtsz3,313+ybtsz,"RAL",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,313,8+xbtsz3,313+ybtsz,"RAL",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>48&&mx<48+30&&my>313&&my<313+13)
   {
    pushbutton(48,313,48+xbtsz3,313+ybtsz,"ANA",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(48,313,48+xbtsz3,313+ybtsz,"ANA",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>88&&mx<88+30&&my>313&&my<313+13)
   {
    pushbutton(88,313,88+xbtsz3,313+ybtsz,"ORA",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(88,313,88+xbtsz3,313+ybtsz,"ORA",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>128&&mx<128+30&&my>313&&my<313+13)
   {
    pushbutton(128,313,128+xbtsz3,313+ybtsz,"ANI",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(128,313,128+xbtsz3,313+ybtsz,"ANI",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>168&&mx<168+30&&my>313&&my<313+13)
   {
    pushbutton(168,313,168+xbtsz3,313+ybtsz,"ORI",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(168,313,168+xbtsz3,313+ybtsz,"ORI",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   /* FRAME STARTS HERE*/

   if(mx>8&&mx<8+30&&my>365&&my<365+13)
   {
    pushbutton(8,365,8+xbtsz3,365+ybtsz,"JMP",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,365,8+xbtsz3,365+ybtsz,"JMP",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>48&&mx<48+20&&my>365&&my<365+13)
   {
    pushbutton(48,365,48+xbtsz2,365+ybtsz,"JC",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(48,365,48+xbtsz2,365+ybtsz,"JC",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>78&&mx<78+30&&my>365&&my<365+13)
   {
    pushbutton(78,365,78+xbtsz3,365+ybtsz,"JNC",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(78,365,78+xbtsz3,365+ybtsz,"JNC",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>118&&mx<118+20&&my>365&&my<365+13)
   {
    pushbutton(118,365,118+xbtsz2,365+ybtsz,"JZ",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(118,365,118+xbtsz2,365+ybtsz,"JZ",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>148&&mx<148+30&&my>365&&my<365+13)
   {
    pushbutton(148,365,148+xbtsz3,365+ybtsz,"JNZ",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(148,365,148+xbtsz3,365+ybtsz,"JNZ",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>188&&mx<188+20&&my>365&&my<365+13)
   {
    pushbutton(188,365,188+xbtsz2,365+ybtsz,"JP",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(188,365,188+xbtsz2,365+ybtsz,"JP",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>218&&mx<218+20&&my>365&&my<365+13)
   {
    pushbutton(218,365,218+xbtsz2,365+ybtsz,"JM",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(218,365,218+xbtsz2,365+ybtsz,"JM",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>8&&mx<8+30&&my>388&&my<388+13)
   {
    pushbutton(8,388,8+xbtsz3,388+ybtsz,"JPO",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,388,8+xbtsz3,388+ybtsz,"JPO",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>48&&mx<48+30&&my>388&&my<388+13)
   {
    pushbutton(48,388,48+xbtsz3,388+ybtsz,"JPE",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(48,388,48+xbtsz3,388+ybtsz,"JPE",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>88&&mx<88+30&&my>388&&my<388+13)
   {
    pushbutton(88,388,88+xbtsz3,388+ybtsz,"CALL",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(88,388,88+xbtsz3,388+ybtsz,"CALL",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>128&&mx<128+20&&my>388&&my<388+13)
   {
    pushbutton(128,388,128+xbtsz2,388+ybtsz,"CC",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(128,388,128+xbtsz2,388+ybtsz,"CC",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>158&&mx<158+30&&my>388&&my<388+13)
   {
    pushbutton(158,388,158+xbtsz3,388+ybtsz,"CNC",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(158,388,158+xbtsz3,388+ybtsz,"CNC",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>198&&mx<198+30&&my>388&&my<388+13)
   {
    pushbutton(198,388,198+xbtsz3,388+ybtsz,"CNZ",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(198,388,198+xbtsz3,388+ybtsz,"CNZ",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>8&&mx<8+20&&my>411&&my<411+13)
   {
    pushbutton(8,411,8+xbtsz2,411+ybtsz,"CZ",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(8,411,8+xbtsz2,411+ybtsz,"CZ",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>38&&mx<38+20&&my>411&&my<411+13)
   {
    pushbutton(38,411,38+xbtsz2,411+ybtsz,"CP",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(38,411,38+xbtsz2,411+ybtsz,"CP",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>68&&mx<68+20&&my>411&&my<411+13)
   {
    pushbutton(68,411,68+xbtsz2,411+ybtsz,"CM",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(68,411,68+xbtsz2,411+ybtsz,"CM",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>98&&mx<98+30&&my>411&&my<411+13)
   {
    pushbutton(98,411,98+xbtsz3,411+ybtsz,"CPO",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(98,411,98+xbtsz3,411+ybtsz,"CPO",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>138&&mx<138+30&&my>411&&my<411+13)
   {
    pushbutton(138,411,138+xbtsz3,411+ybtsz,"CPE",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(138,411,138+xbtsz3,411+ybtsz,"CPE",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   /*BRANCH  FRAME ENDS HERE */

   /*FREE FRAME STARTS HERE */
   if(mx>270&&mx<270+30&&my>280&&my<280+13)
   {
    pushbutton(270,280,270+xbtsz3,280+ybtsz,"NOP",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(270,280,270+xbtsz3,280+ybtsz,"NOP",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>320&&mx<320+30&&my>280&&my<280+13)
   {
    pushbutton(320,280,320+xbtsz3,280+ybtsz,"HLT",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(320,280,320+xbtsz3,280+ybtsz,"HLT",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>80&&mx<145&&my>422&&my<472)
   {
    settextstyle(0,0,2);
    setcolor(4);
    pushbutton(80,442,145,472,"",LIGHTGRAY,DARKGRAY,1);
    outtextxy(80,447,"BACK");
    delay(100);
    button(80,442,145,472,"",LIGHTGRAY,DARKGRAY,1);
     setcolor(4);
    outtextxy(80,447,"BACK");
    settextstyle(0,0,0);
   }
   if(mx>170&&mx<220&&my>442&&my<472)
   {
    settextstyle(0,0,2);
    setcolor(4);
    pushbutton(170,442,220,472,"",LIGHTGRAY,DARKGRAY,1);
    outtextxy(170,447,"RUN");
    delay(100);
    button(170,442,220,472,"",LIGHTGRAY,DARKGRAY,1);
    setcolor(4);
    outtextxy(170,447,"RUN");
    settextstyle(0,0,0);
   }
   if(mx>391&&mx<400&&my>30&&my<40)
   {
    pushbutton(391,30,400,40,"",LIGHTGRAY,DARKGRAY,LIGHTGRAY);
    frame(391,30,400,40,DARKGRAY,WHITE,LIGHTGRAY);
    setcolor(0);
    line(395,33,391,37);
    line(395,33,399,37);
    line(391,38,399,38);
    setfillstyle(0,0);
    floodfill(396,35,0);
    delay(100);
    button(391,30,400,40,"",LIGHTGRAY,DARKGRAY,LIGHTGRAY);
    frame(391,30,400,40,WHITE,DARKGRAY,LIGHTGRAY);
    setcolor(0);
    line(395,33,391,37);
    line(395,33,399,37);
    line(391,38,399,38);
    setfillstyle(0,0);
    floodfill(396,35,0);

   }
   if(mx>391&&mx<400&&my>467&&my<477)
   {
    pushbutton(391,467,400,477,"",LIGHTGRAY,DARKGRAY,LIGHTGRAY);
    frame(391,467,400,477,DARKGRAY,WHITE,LIGHTGRAY);
    setcolor(0);
    line(395,474,391,470);
    line(395,474,399,470);
    line(391,469,399,469);
    setfillstyle(0,0);
    floodfill(396,472,0);
    delay(100);
    button(391,467,400,477,"",LIGHTGRAY,DARKGRAY,LIGHTGRAY);
    frame(391,467,400,477,WHITE,DARKGRAY,LIGHTGRAY);
    setcolor(0);
    line(395,474,391,470);
    line(395,474,399,470);
    line(391,469,399,469);
    setfillstyle(0,0);
    floodfill(396,472,0);

   }
   /*FREE FRAME ENDS HERE */

   /*HEX NUMBER FRAME STARTS HERE */

   if(mx>260&&mx<274&&my>50&&my<50+13)
   {
    pushbutton(260,50,274,50+ybtsz,"0",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(260,50,274,50+ybtsz,"0",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>294&&mx<308&&my>50&&my<50+13)
   {
    pushbutton(294,50,308,50+ybtsz,"1",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(294,50,308,50+ybtsz,"1",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>328&&mx<342&&my>50&&my<50+13)
   {
    pushbutton(328,50,342,50+ybtsz,"2",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(328,50,342,50+ybtsz,"2",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>362&&mx<376&&my>50&&my<50+13)
   {
    pushbutton(362,50,376,50+ybtsz,"3",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(362,50,376,50+ybtsz,"3",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>260&&mx<274&&my>80&&my<80+13)
   {
    pushbutton(260,80,274,80+ybtsz,"4",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(260,80,274,80+ybtsz,"4",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>294&&mx<308&&my>80&&my<80+13)
   {
    pushbutton(294,80,308,80+ybtsz,"5",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(294,80,308,80+ybtsz,"5",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>328&&mx<342&&my>80&&my<80+13)
   {
    pushbutton(328,80,342,80+ybtsz,"6",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(328,80,342,80+ybtsz,"6",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>362&&mx<376&&my>80&&my<80+13)
   {
    pushbutton(362,80,376,80+ybtsz,"7",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(362,80,376,80+ybtsz,"7",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>260&&mx<274&&my>110&&my<110+13)
   {
    pushbutton(260,110,274,110+ybtsz,"8",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(260,110,274,110+ybtsz,"8",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>294&&mx<308&&my>110&&my<110+13)
   {
    pushbutton(294,110,308,110+ybtsz,"9",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(294,110,308,110+ybtsz,"9",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>328&&mx<342&&my>110&&my<110+13)
   {
    pushbutton(328,110,342,110+ybtsz,"A",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(328,110,342,110+ybtsz,"A",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>362&&mx<376&&my>110&&my<110+13)
   {
    pushbutton(362,110,376,110+ybtsz,"B",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(362,110,376,110+ybtsz,"B",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>260&&mx<274&&my>140&&my<140+13)
   {
    pushbutton(260,140,274,140+ybtsz,"C",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(260,140,274,140+ybtsz,"C",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>294&&mx<308&&my>140&&my<140+13)
   {
    pushbutton(294,140,308,140+ybtsz,"D",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(294,140,308,140+ybtsz,"D",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>328&&mx<342&&my>140&&my<140+13)
   {
    pushbutton(328,140,342,140+ybtsz,"E",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(328,140,342,140+ybtsz,"E",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>362&&mx<376&&my>140&&my<140+13)
   {
    pushbutton(362,140,376,140+ybtsz,"F",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(362,140,376,140+ybtsz,"F",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   /*HEX NUMBER FRAME ENDS HERE */

   /*STACK FRAME STARTS HERE */
   if(mx>270&&mx<270+40&&my>205&&my<205+13)
   {
    pushbutton(270,205,270+xbtsz4,205+ybtsz,"SPHL",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(270,205,270+xbtsz4,205+ybtsz,"SPHL",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>330&&mx<330+40&&my>205&&my<205+13)
   {
    pushbutton(330,205,330+xbtsz4,205+ybtsz,"PUSH",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(330,205,330+xbtsz4,205+ybtsz,"PUSH",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>270&&mx<270+30&&my>233&&my<233+13)
   {
    pushbutton(270,233,270+xbtsz3,233+ybtsz,"POP",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(270,233,270+xbtsz3,233+ybtsz,"POP",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   if(mx>330&&mx<330+40&&my>233&&my<233+13)
   {
    pushbutton(330,233,330+xbtsz4,233+ybtsz,"XTHL",BTCOLOR,BTBORDER,TXTCOLOR);
    delay(100);
    button(330,233,330+xbtsz4,233+ybtsz,"XTHL",BTCOLOR,BTBORDER,TXTCOLOR);
   }
   setmousepos(mx,my);

  }
  if(mx>3&&mx<200&&my>9&&my<23)
  {
   if(mx>3&&mx<=50&&my>9&&my<23&&co!=1)
   {
    menubar();
    co=1;
    menu_button(3,9,3+44,23,"FILE");
   }
   if(mx>51&&mx<=98&&my>9&&my<23&&co!=2)
   {
    menubar();
    co=2;
    menu_button(51,9,94,23,"GOTO");
   }
   if(mx>99&&mx<108+30&&my>9&&my<23&&co!=3)
   {
    menubar();
    co=3;
    menu_button(100,9,105+30,23,"RUN");
   }
   if(mx>106+30&&mx<106+73&&my>9&&my<23&&co!=4)
   {
    menubar();
    co=4;
    menu_button(107+30,9,107+73,23,"HELP");
   }
  }
  else
  {
   if(co!=0)
   {
    menubar();
    co=0;
   }
  }
 }

}
void menubar()
{
 frame(3,9,639-3,23,LIGHTGRAY,DARKGRAY,LIGHTGRAY);
 setcolor(0);
 outtextxy(7,11,"FILE");
 outtextxy(55,11,"GOTO");
 outtextxy(104,11,"RUN");
 outtextxy(107+34,11,"HELP");
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
void button(int x1,int y1,int x2,int y2,char *str,int btcolor,int btborder,int txtcolor)
{
 int seedx,seedy;
 seedx=x1+3;
 seedy=y1+4;
 frame(x1,y1,x2,y2,btcolor,btborder,btcolor);
 setcolor(txtcolor);
 outtextxy(seedx,seedy,str);
}
void menu_button(int x1,int y1,int x2,int y2,char *str)
{
 int seedx,seedy;
 seedx=x1+4;
 seedy=y1+2;
 frame(x1,y1,x2,y2,WHITE,DARKGRAY,LIGHTGRAY);
 setcolor(0);
 outtextxy(seedx,seedy,str);
}
void pmenu_button(int x1,int y1,int x2,int y2,char *str)
{
 int seedx,seedy;
 seedx=x1+4;
 seedy=y1+2;
 frame(x1,y1,x2,y2,DARKGRAY,WHITE,LIGHTGRAY);
 setcolor(0);
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
void display(int col)
{
 if(col!=15)
 {

  frame(2,30,384,477,12,4,col);
  txtscreen(13);

  regframe(14);//FRAME FOR REGISTER GROUP
  datrframe(3);//DATA TRANSFER FRAME GROUP
  ariframe(10);//ARITHEMATIC GROUP
  logiframe(11);//LOGICAL INSTRUCTIONS
  brnchframe(0);//BRANCHED INSTRUCTIONS
  numberframe(2);//HEX NUMBER PLATE
  stcframe(7);
  free();

 }
 if(col==15)
 {
  frame(389,30,400,477,DARKGRAY,LIGHTGRAY,LIGHTGRAY);
  frame(2,30,384,477,12,4,9);
  txtscreen(13);

  regframe(15);//FRAME FOR REGISTER GROUP
  datrframe(15);//DATA TRANSFER FRAME GROUP
  ariframe(15);
  logiframe(15);
  brnchframe(15);
  numberframe(15);
  stcframe(15);
  free();
 }
}
void txtscreen(int col)
{
 int x,y;
 x=407;
 y=45;
 if(col!=15)
 {
  frame(407,30,637,477,14,14,col);
  frame(444,30,637,477,14,14,col);
  frame(538,30,637,477,14,14,col);

  line(570,45,570,477);
  line(571,45,571,477);

  line(603,45,603,477);
  line(604,45,604,477);
  while(y<=637)
  {
   line(x,y,637,y);
   line(x,y+1,637,y+1);
   y=y+15;
  }
  if(col==0||col==1||col==6)
  {
   setcolor(15);
  }
  else
  {
   setcolor(1);
  }
  outtextxy(408,35,"ADDR");
  outtextxy(445,35,"INSTRUCTION");
  outtextxy(570,35,"CODE");
  outtextxy(545,50,"OP");
  outtextxy(572,50,"A(l)");
  outtextxy(606,50,"A(h)");
 }
  frame(391,30,400,477,DARKGRAY,DARKGRAY,LIGHTGRAY);
  button(391,30,400,40,"",LIGHTGRAY,DARKGRAY,LIGHTGRAY);
  frame(391,30,400,40,WHITE,DARKGRAY,LIGHTGRAY);

  button(391,467,400,477,"",LIGHTGRAY,DARKGRAY,LIGHTGRAY);
  frame(391,467,400,477,WHITE,DARKGRAY,LIGHTGRAY);

 setcolor(0);
 line(395,33,391,37);
 line(395,33,399,37);
 line(391,38,399,38);

 setfillstyle(0,0);
 floodfill(396,35,0);

 setcolor(0);
 line(395,474,391,470);
 line(395,474,399,470);
 line(391,469,399,469);

 setfillstyle(0,0);
 floodfill(396,472,0);
}
void regframe(int col)
{
 int x,y;
 frame(3,31,228,70,12,4,col);
 setcolor(1);
 outtextxy(50,35,"REGISTER GROUP");
 button(10,50,25,64,"A",BTCOLOR,BTBORDER,TXTCOLOR);

 button(40,50,55,64,"B",BTCOLOR,BTBORDER,TXTCOLOR);
 button(65,50,80,64,"C",BTCOLOR,BTBORDER,TXTCOLOR);

 button(95,50,110,64,"D",BTCOLOR,BTBORDER,TXTCOLOR);
 button(120,50,135,64,"E",BTCOLOR,BTBORDER,TXTCOLOR);

 button(150,50,165,64,"H",BTCOLOR,BTBORDER,TXTCOLOR);
 button(175,50,190,64,"L",BTCOLOR,BTBORDER,TXTCOLOR);

 button(205,50,220,64,"M",BTCOLOR,BTBORDER,TXTCOLOR);
}
void datrframe(int col)
{
 frame(3,80,205,165,12,4,col);
 setcolor(4);
 outtextxy(50,85,"DATA TRANSFER ");

 button(8,100,8+xbtsz3,100+ybtsz,"MOV",BTCOLOR,BTBORDER,TXTCOLOR);
 button(48,100,48+xbtsz3,100+ybtsz,"MVI",BTCOLOR,BTBORDER,TXTCOLOR);
 button(88,100,88+xbtsz3,100+ybtsz,"LXI",BTCOLOR,BTBORDER,TXTCOLOR);
 button(128,100,128+xbtsz3,100+ybtsz,"LDA",BTCOLOR,BTBORDER,TXTCOLOR);
 button(168,100,168+xbtsz3,100+ybtsz,"STA",BTCOLOR,BTBORDER,TXTCOLOR);

 button(8,123,8+xbtsz4,123+ybtsz,"LHLD",BTCOLOR,BTBORDER,TXTCOLOR);
 button(58,123,58+xbtsz4,123+ybtsz,"SHLD",BTCOLOR,BTBORDER,TXTCOLOR);
 button(108,123,108+xbtsz4,123+ybtsz,"LDAX",BTCOLOR,BTBORDER,TXTCOLOR);
 button(158,123,158+xbtsz4,123+ybtsz,"STAX",BTCOLOR,BTBORDER,TXTCOLOR);

 button(8,146,8+xbtsz4,146+ybtsz,"XCHG",BTCOLOR,BTBORDER,TXTCOLOR);
 button(58,146,58+xbtsz4,146+ybtsz,"PCHL",BTCOLOR,BTBORDER,TXTCOLOR);

}
void ariframe(int col)
{
 frame(3,175,205,260,12,4,col);
 setcolor(5);
 outtextxy(50,180,"ARITHEMATIC GROUP");

 button(8,195,8+xbtsz3,195+ybtsz,"INR",BTCOLOR,BTBORDER,TXTCOLOR);
 button(48,195,48+xbtsz3,195+ybtsz,"DCR",BTCOLOR,BTBORDER,TXTCOLOR);
 button(88,195,88+xbtsz3,195+ybtsz,"INX",BTCOLOR,BTBORDER,TXTCOLOR);
 button(128,195,128+xbtsz3,195+ybtsz,"DCX",BTCOLOR,BTBORDER,TXTCOLOR);
 button(168,195,168+xbtsz3,195+ybtsz,"ADD",BTCOLOR,BTBORDER,TXTCOLOR);

 button(8,218,8+xbtsz3,218+ybtsz,"SUB",BTCOLOR,BTBORDER,TXTCOLOR);
 button(48,218,48+xbtsz3,218+ybtsz,"DAA",BTCOLOR,BTBORDER,TXTCOLOR);
 button(88,218,88+xbtsz3,218+ybtsz,"ADC",BTCOLOR,BTBORDER,TXTCOLOR);
 button(128,218,128+xbtsz3,218+ybtsz,"SBB",BTCOLOR,BTBORDER,TXTCOLOR);
 button(168,218,168+xbtsz3,218+ybtsz,"CMP",BTCOLOR,BTBORDER,TXTCOLOR);


 button(8,241,8+xbtsz3,241+ybtsz,"DAD",BTCOLOR,BTBORDER,TXTCOLOR);
 button(48,241,48+xbtsz3,241+ybtsz,"ADI",BTCOLOR,BTBORDER,TXTCOLOR);
 button(88,241,88+xbtsz3,241+ybtsz,"ACI",BTCOLOR,BTBORDER,TXTCOLOR);
 button(128,241,128+xbtsz3,241+ybtsz,"SUI",BTCOLOR,BTBORDER,TXTCOLOR);
 button(168,241,168+xbtsz3,241+ybtsz,"CPI",BTCOLOR,BTBORDER,TXTCOLOR);
}
void logiframe(int col)
{
 frame(3,270,245,335,12,4,col);
 setcolor(4);
 outtextxy(50,275,"LOGICAL GROUP");

 button(8,290,8+xbtsz3,290+ybtsz,"CMA",BTCOLOR,BTBORDER,TXTCOLOR);
 button(48,290,48+xbtsz3,290+ybtsz,"STC",BTCOLOR,BTBORDER,TXTCOLOR);
 button(88,290,88+xbtsz3,290+ybtsz,"CMC",BTCOLOR,BTBORDER,TXTCOLOR);
 button(128,290,128+xbtsz3,290+ybtsz,"RRC",BTCOLOR,BTBORDER,TXTCOLOR);
 button(168,290,168+xbtsz3,290+ybtsz,"RAR",BTCOLOR,BTBORDER,TXTCOLOR);
 button(208,290,208+xbtsz3,290+ybtsz,"RLC",BTCOLOR,BTBORDER,TXTCOLOR);

 button(8,313,8+xbtsz3,313+ybtsz,"RAL",BTCOLOR,BTBORDER,TXTCOLOR);
 button(48,313,48+xbtsz3,313+ybtsz,"ANA",BTCOLOR,BTBORDER,TXTCOLOR);
 button(88,313,88+xbtsz3,313+ybtsz,"ORA",BTCOLOR,BTBORDER,TXTCOLOR);
 button(128,313,128+xbtsz3,313+ybtsz,"ANI",BTCOLOR,BTBORDER,TXTCOLOR);
 button(168,313,168+xbtsz3,313+ybtsz,"ORI",BTCOLOR,BTBORDER,TXTCOLOR);
}
void brnchframe(int col)
{
 frame(3,345,245,430,12,4,col);
 if(col==0)
 {
  setcolor(15);
 }
 else
 {
  setcolor(0);
 }
 outtextxy(30,350,"BRANCH INSTRUCTIONS GROUP");

 button(8,365,8+xbtsz3,365+ybtsz,"JMP",BTCOLOR,BTBORDER,TXTCOLOR);
 button(48,365,48+xbtsz2,365+ybtsz,"JC",BTCOLOR,BTBORDER,TXTCOLOR);
 button(78,365,78+xbtsz3,365+ybtsz,"JNC",BTCOLOR,BTBORDER,TXTCOLOR);
 button(118,365,118+xbtsz2,365+ybtsz,"JZ",BTCOLOR,BTBORDER,TXTCOLOR);
 button(148,365,148+xbtsz3,365+ybtsz,"JNZ",BTCOLOR,BTBORDER,TXTCOLOR);
 button(188,365,188+xbtsz2,365+ybtsz,"JP",BTCOLOR,BTBORDER,TXTCOLOR);
 button(218,365,218+xbtsz2,365+ybtsz,"JM",BTCOLOR,BTBORDER,TXTCOLOR);

 button(8,388,8+xbtsz3,388+ybtsz,"JPO",BTCOLOR,BTBORDER,TXTCOLOR);
 button(48,388,48+xbtsz3,388+ybtsz,"JPE",BTCOLOR,BTBORDER,TXTCOLOR);
 button(88,388,88+xbtsz3,388+ybtsz,"CALL",BTCOLOR,BTBORDER,TXTCOLOR);
 button(128,388,128+xbtsz2,388+ybtsz,"CC",BTCOLOR,BTBORDER,TXTCOLOR);
 button(158,388,158+xbtsz3,388+ybtsz,"CNC",BTCOLOR,BTBORDER,TXTCOLOR);
 button(198,388,198+xbtsz3,388+ybtsz,"CNZ",BTCOLOR,BTBORDER,TXTCOLOR);

 button(8,411,8+xbtsz2,411+ybtsz,"CZ",BTCOLOR,BTBORDER,TXTCOLOR);
 button(38,411,38+xbtsz2,411+ybtsz,"CP",BTCOLOR,BTBORDER,TXTCOLOR);
 button(68,411,68+xbtsz2,411+ybtsz,"CM",BTCOLOR,BTBORDER,TXTCOLOR);
 button(98,411,98+xbtsz3,411+ybtsz,"CPO",BTCOLOR,BTBORDER,TXTCOLOR);
 button(138,411,138+xbtsz3,411+ybtsz,"CPE",BTCOLOR,BTBORDER,TXTCOLOR);
}
void numberframe(int col)
{
 frame(248,30,384,165,12,4,col);
 setcolor(0);
 outtextxy(260,35,"HEX NUMBERS");

 button(260,50,274,50+ybtsz,"0",BTCOLOR,BTBORDER,TXTCOLOR);
 button(294,50,308,50+ybtsz,"1",BTCOLOR,BTBORDER,TXTCOLOR);
 button(328,50,342,50+ybtsz,"2",BTCOLOR,BTBORDER,TXTCOLOR);
 button(362,50,376,50+ybtsz,"3",BTCOLOR,BTBORDER,TXTCOLOR);

 button(260,80,274,80+ybtsz,"4",BTCOLOR,BTBORDER,TXTCOLOR);
 button(294,80,308,80+ybtsz,"5",BTCOLOR,BTBORDER,TXTCOLOR);
 button(328,80,342,80+ybtsz,"6",BTCOLOR,BTBORDER,TXTCOLOR);
 button(362,80,376,80+ybtsz,"7",BTCOLOR,BTBORDER,TXTCOLOR);

 button(260,110,274,110+ybtsz,"8",BTCOLOR,BTBORDER,TXTCOLOR);
 button(294,110,308,110+ybtsz,"9",BTCOLOR,BTBORDER,TXTCOLOR);
 button(328,110,342,110+ybtsz,"A",BTCOLOR,BTBORDER,TXTCOLOR);
 button(362,110,376,110+ybtsz,"B",BTCOLOR,BTBORDER,TXTCOLOR);

 button(260,140,274,140+ybtsz,"C",BTCOLOR,BTBORDER,TXTCOLOR);
 button(294,140,308,140+ybtsz,"D",BTCOLOR,BTBORDER,TXTCOLOR);
 button(328,140,342,140+ybtsz,"E",BTCOLOR,BTBORDER,TXTCOLOR);
 button(362,140,376,140+ybtsz,"F",BTCOLOR,BTBORDER,TXTCOLOR);
}
void stcframe(int col)
{
 frame(260,180,384,260,12,4,col);
 setcolor(4);
 outtextxy(280,185,"STACK GROUP");

 button(270,205,270+xbtsz4,205+ybtsz,"SPHL",BTCOLOR,BTBORDER,TXTCOLOR);
 button(330,205,330+xbtsz4,205+ybtsz,"PUSH",BTCOLOR,BTBORDER,TXTCOLOR);

 button(270,233,270+xbtsz3,233+ybtsz,"POP",BTCOLOR,BTBORDER,TXTCOLOR);
 button(330,233,330+xbtsz4,233+ybtsz,"XTHL",BTCOLOR,BTBORDER,TXTCOLOR);
}
void free()
{
 button(270,280,270+xbtsz3,280+ybtsz,"NOP",BTCOLOR,BTBORDER,TXTCOLOR);
 button(320,280,320+xbtsz3,280+ybtsz,"HLT",BTCOLOR,BTBORDER,TXTCOLOR);

 button(80,442,145,472,"",LIGHTGRAY,DARKGRAY,1);
 button(170,442,220,472,"",LIGHTGRAY,DARKGRAY,1);
 settextstyle(0,0,2);
 setcolor(4);
 outtextxy(80,447,"BACK");
 outtextxy(170,447,"RUN");
 settextstyle(0,0,0);
}


