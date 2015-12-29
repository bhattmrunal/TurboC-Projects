#include<bios.h>
#include<stdio.h>
int getkey();

void main()
{
 int ch;

 while(ch!=1)
 {
  ch=getkey();
  printf("%d",ch);
 }
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
