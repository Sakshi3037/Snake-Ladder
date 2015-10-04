#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
FILE *ptr;
struct node
{ int start,end;
struct node *next;
};
class list
{ node *head;
node *p,*q;
public:list()
{
head=NULL;
}
void create(int s,int e)
{
p=new node;
p->start=s;
p->end=e;
p->next=NULL;
if(head==NULL)
{head=p;
q=p;
}else
{
q->next=p;
q=p;
}
fprintf(ptr,"%d",p->start);
fwrite(" ",1,1,ptr);
fprintf(ptr,"%d",p->end);
fwrite("\n",1,1,ptr);
}
void show()
{p=head;
while(p!=NULL)
{
cout<<p->start<<" "<<p->end<<endl;
p=p->next;
}
}
int check(int s, int e)
{p=head;
while(p!=NULL)
{if(p->start==s)
return -1;
p=p->next;
}
return 0;
}
};
void main()
{
ptr=fopen("game","a+");
if(ptr==NULL)
printf("\n Cannot open the file \n");
list snake;
int s,e;
list ladder;
cout<<" Enter for snake ";
for(int i=0;i<8;i++)
{a: cout<<" Enter starting and last points ";
cin>>s;
fflush(stdin);
cin>>e;
if(e>s)
{ cout<<" Enter again, Invalid entry ";
goto a;
}
snake.create(s,e);
}

cout<<" Enter for ladder ";
for(i=0;i<8;i++)
{ b:cout<<" Enter starting and last points ";
fflush(stdin);
cin>>s>>e;
if(s>e)
{ cout<<" Enter again, Invalid entry ";
goto b;
}
int j=snake.check(s,e);
if(j==-1)
{ cout<<" Enter again, Invalid entry, a snake already exists there ";
goto b;
}
ladder.create(s,e);
}
snake.show();
ladder.show();
fclose(ptr);
}
