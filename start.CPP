#include<fstream.h>
#include <iostream.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include <conio.h>
#include <graphics.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<conio.h>
#include<iostream.h>
void dice(int);
void sleep(time_t delay)
{time_t timer0,timer1;
time(&timer0);
do
{time(&timer1);
}
while((timer1-timer0)<delay);
}
void drawsnake(int,int);
void drawladder(int,int);
int check(int);
void check1(int &t);
void main()
{clrscr();
int i,j;
char p1[10],p2[10];
int c1,c2;
c1=0;c2=0;
cout<<" Start Game "<<endl;
cout<<" Enter name of 1st player ";
cin>>p1;
cout<<" Enter name of 2nd player ";
cin>>p2;
int gd = DETECT,gm,errorcode;
initgraph (&gd, &gm, "c:\\turboc3\\bgi");
errorcode = graphresult();
 if (errorcode != grOk)
    {
      cout << "Graphics error occured : \n" << grapherrormsg(errorcode) << endl;
      cout << "Press any key to stop : ";
      getch();
      exit(1);
    }
  rectangle(600, 450, 20, 20);
  for(i=78;i<600;i=i+58)
  {line(i,450,i,20);
  }
  for(j=63;j<450;j=j+43)
  {line(20,j,600,j);
  }
  int g=1;
  char str[20];
  i=0;j=429.5;
  while(1)
{ if(i<=0)
{ for(i=49;i<600;i=i+58)
{ itoa(g++,str,10);
outtextxy(i,j,str);
 }}
 if(i==629)
 {j=j-43;
 for(i=571;i>20;i=i-58)
{itoa(g++,str,10);
 outtextxy(i,j,str);
}
 j=j-43;}
 if(j<=41.5)
 break;
 }
for(i=1;i<=100;i++)
{j=check(i);
if(j>0 && j<=100)
{ if(j<i)//snake;
drawsnake(i,j);
else if(i<j)//ladder
drawladder(i,j);
}}
srand ( time(NULL) );
int width,height,k,l;
while(1)
{ outtextxy(1,20,p1);
outtextxy(605,20,p2);
i=rand()%6+1;
outtextxy(0,190,"Enter");
outtextxy(0,200,"to roll");
getch();
width=textwidth("Enter");
height=textheight("Enter");
for(k=0;k<width;k++)
{ for(l=0;l<height;l++)
putpixel(k,l+190,0);
}
width=textwidth("to roll");
height=textheight("to roll");
for(k=0;k<width;k++)
{ for(l=0;l<height;l++)
putpixel(k,l+200,0);
}
dice(i);
sleep(2);
setcolor(YELLOW);
rectangle(610,350,639,386);
setfillstyle(SOLID_FILL,BLACK);
floodfill(620,360,YELLOW);
itoa(i,str,10);
setcolor(WHITE);
outtextxy(0,430,"P1");
outtextxy(0,445,str);
 sleep(3);
 width=textwidth(str);
 height=textheight(str);
for(k=0;k<width;k++)
{for(l=0;l<height;l++)
putpixel(k,l+445,0);
}
c1=c1+i;
itoa(c1,str,10);
if(c1>100)
 c1=c1-i;
check1(c1);
itoa(c1,str,10);
 width=textwidth(str);
 height=textheight(str);
for(k=0;k<width;k++)
{for(l=0;l<height;l++)
putpixel(k+1,l+30,0);
}
outtextxy(1,30,str);
sleep(2);
if(c1==100)
{ outtextxy(590,190,"Winner-");
outtextxy(590,200,p1);
 break;}
i=rand()%6+1;
outtextxy(0,190,"Enter");
outtextxy(0,200,"to roll");
getch();
width=textwidth("Enter");
height=textheight("Enter");
for(k=0;k<width;k++)
{ for(l=0;l<height;l++)
putpixel(k,l+190,0);
}
width=textwidth("to roll");
height=textheight("to roll");
for(k=0;k<width;k++)
{ for(l=0;l<height;l++)
putpixel(k,l+200,0);
}
dice(i);
sleep(2);
setcolor(YELLOW);
rectangle(610,350,639,386);
setfillstyle(SOLID_FILL,BLACK);
floodfill(620,360,YELLOW);
setcolor(WHITE);
itoa(i,str,10);
outtextxy(603,430,"P2");
outtextxy(601,445,str);
sleep(3);
 width=textwidth(str);
 height=textheight(str);
for(k=0;k<width;k++)
{for(l=0;l<height;l++)
putpixel(k+600,l+445,0);
}
c2=c2+i;
itoa(c2,str,10);
if(c2>100)
c2=c2-i;
check1(c2);
itoa(c2,str,10);
width=textwidth(str);
 height=textheight(str);
for(k=0;k<width;k++)
{for(l=0;l<height;l++)
putpixel(k+605,l+30,0);
}
outtextxy(605,30,str);
sleep(2);
 if(c2==100)
 {outtextxy(590,190,"Winner-");
 outtextxy(590,200,p2);
 break;}}
getch();
  closegraph();
}
void drawsnake(int s,int e)
{
int x,y,x1,y1,col_no=0;
 if(s%10==0)
{ col_no=s/10;
if(col_no%2==0) //even
 x=49;
else if(col_no%2!=0)//odd
x=571;
y=450-(43*col_no)+21.5;
 }
 else
{ col_no=s/10+1;
if(col_no%2==0) //even
 x=(10-s%10)*58+49;
else if(col_no%2!=0)//odd
x=(s%10-1)*58+49;
y=450-(43*col_no)+21.5;
}
if(e%10==0)
{col_no=e/10;
if(col_no%2==0) //even
 x1=49;
else if(col_no%2!=0)//odd
x1=571;
y1=450-(43*col_no)+21.5;
}
else
{col_no=e/10+1;
if(col_no%2==0) //even
 x1=(10-e%10)*58+49;
else if(col_no%2!=0)//odd
x1=(e%10-1)*58+49;
y1=450-(43*col_no)+21.5;
}
setcolor(RED);
line(x,y,x1,y1);
}
void drawladder(int s,int e)
{ int x,y,x1,y1,col_no=0;
 if(s%10==0)
 {col_no=s/10;
if(col_no%2==0) //even
 x=49;
else if(col_no%2!=0)//odd
x=571;
y=450-(43*col_no)+21.5;
 }
 else
{ col_no=s/10+1;
if(col_no%2==0) //even
 x=(10-s%10)*58+49;
else if(col_no%2!=0)//odd
x=(s%10-1)*58+49;
y=450-(43*col_no)+21.5;
}
if(e%10==0)
{ col_no=e/10;
if(col_no%2==0) //even
 x1=49;
else if(col_no%2!=0)//odd
x1=571;
y1=450-(43*col_no)+21.5;
}
else
{col_no=e/10+1;
if(col_no%2==0) //even
 x1=(10-e%10)*58+49;
else if(col_no%2!=0)//odd
x1=(e%10-1)*58+49;
y1=450-(43*col_no)+21.5;
}
setcolor(GREEN);
line(x,y,x1,y1);
}
void check1(int &t)
{  char str[20];
char l[10];
char line[20];
int m=0,s,e=0;
double o,count=0,j=0,p;
ifstream fin;
fin.open("game");
while(fin)
{ fin.getline(line,20);
while(line[m]!=' ')
m++;
strncpy(l,&line[0],m);
l[m]='\0';
for(s=m-1;s>=0;s--)
{
o=pow(10.0,count);
p=l[s]-48;
j=p*o+j;
count++;
}
if(t==j)
{ s=m;
while(line[m+1]!='\0')
m++;
strncpy(l,&line[s+1],m-s);
l[m-s]='\0';
count=0;
j=0;
for(int k=m-s-1;k>=0;k--)
{
l[k]=l[k]-48;
e=l[k]*pow(10,count)+e;
count++;
}
t=e;
break;}
m=0;
e=0;
j=0;
count=0;
}
}
int check(int t)
{
char l[10];
char line[20];
int m=0,s,e=0;
double o,count=0,j=0,p;
ifstream fin;
fin.open("game");
while(fin)
{ fin.getline(line,20);
while(line[m]!=' ')
m++;
strncpy(l,&line[0],m);
l[m]='\0';
for(s=m-1;s>=0;s--)
{
o=pow(10.0,count);
p=l[s]-48;
j=p*o+j;
count++;
}
if(t==j)
{ s=m;
while(line[m+1]!='\0')
m++;
strncpy(l,&line[s+1],m-s);
l[m-s]='\0';
count=0;
j=0;
for(int k=m-s-1;k>=0;k--)
{
l[k]=l[k]-48;
e=l[k]*pow(10,count)+e;
count++;
}
return e;}
m=0;
e=0;
j=0;
count=0;
}
return -1;
}
void dice(int h)
{int i,j,k=386+9;
setcolor(WHITE);
rectangle(610,350,639,386);
switch(h)
{ case 1:circle(625,368,2);
break;
case 2:circle(617.5,368,2);
circle(632.5,368,2);
break;
case 3:   circle(617.5,380,2);
circle(625,368,2);
circle(632.5,356,2);
break;
case 4: circle(617.5,380,2);
circle(632.5,380,2);
circle(617.5,356,2);
circle(632.5,356,2);
break;
case 5:   circle(625,368,2);
circle(617.5,380,2);
circle(632.5,380,2);
circle(617.5,356,2);
circle(632.5,356,2);
break;
case 6: circle(617.5,380,2);
circle(632.5,380,2);
circle(617.5,356,2);
circle(632.5,356,2);
circle(617.5,368,2);
circle(632.5,368,2);
}
}
