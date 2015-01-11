#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<graphics.h>

void intopost();
void filllist();
void parse(int,double);
void showaxis();
void modifyPostfix(int,char);
const int size=50;
char infix[size],postfix[size],stack[size];
int top=-1,n=0;
int precedence(char ch);
char pop();
char topelement();
void push(char ch);
void modifylist(int i,double y);
void options();
int braces(char *);
double y=0.0,y2,y3,h=0.00001,area=0.0,lowerlimit,upperlimit;

struct graph
{
graph *pre;
char c;
double f;
int pos;
graph *next;
}*start,*ptr,*naya,*temp;

void main()
{
clrscr();

options();

intopost();

char post[size];
strcpy(post,postfix);

filllist();

 cout<<"\nplot 1st or 2nd derivative  (1/2) -\n";
  cout<<"\narea under curve (3) -";
  cout<<"\nsave function (4)-";
  cout<<"\nplot graph (5)- ";
  cin>>n;

if(n==3)
{
  cout<<"\nunder the lower limit - ";cin>>lowerlimit;
  cout<<"\nunder the upper limit - ";cin>>upperlimit;
}

showaxis();

	for(double x=-50.0;x<=50;x=x+0.00003)
	{
		for(int i=0;postfix[i];i++)
		{
			if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^')
			{parse(i,x+h);i=0;}
		}

	 y2=y;strcpy(postfix,post);

		for(i=0;postfix[i];i++)
		{
			if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^')
			{parse(i,x+2*h);i=0;}
		}

	  y3=y;strcpy(postfix,post);

		for(i=0;postfix[i];i++)
		{
			if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^')
			{parse(i,x);i=0;}
		}
	   if(n==3)
		{
		if(x>lowerlimit&&x<upperlimit)
		area=area+y*0.00003;
		}

	   if(n==1)
	   start->f=(y2-y)/h;

	   else if(n==2)
	   start->f=(y3+y-2*y2)/(h*h);

	//putpixel(10*x+getmaxx()/2,10*(-y)+getmaxy()/2,CYAN);
	putpixel(10*x+getmaxx()/2,10*(-(start->f))+getmaxy()/2,CYAN);
	strcpy(postfix,post);

	}

clrscr();
if(n==3)
cout<<area;

getch();
}

void parse(int i,double x)
{
 double a,b;
 char t;

 for(ptr=start;ptr->pos!=i;ptr=ptr->next);

 if(postfix[i-1]=='x')
 b=x;

	else if(postfix[i-1]=='y')
	{
	ptr=ptr->pre;
	b=ptr->f;
	}
		else
		b=int(postfix[i-1])-48;

 for(ptr=start;ptr->pos!=i;ptr=ptr->next);

 if(postfix[i-2]=='x')
 a=x;

	else if(postfix[i-2]=='y')
	{
	ptr=ptr->pre;ptr=ptr->pre;
	a=ptr->f;
	 }
		else
		a=int(postfix[i-2])-48;


   switch(postfix[i])
   {
     case '+': y=a+b;break;
     case '-': y=a-b;break;
     case '*': if(postfix[i-2]=='s')
		y=sin(b);
	       else if(postfix[i-2]=='c')
	       y=cos(b);
	       else if(postfix[i-2]=='l')
		      { if(b>0)
			y=log(b);
			else y=1000;
		      }
	       else if(postfix[i-2]=='t')
	       y=tan(b);
	       else if(postfix[i-2]=='g')
	       {if(b<0)
	       y=int(b-1);
	       else y=int(b);
	       }
	       else if(postfix[i-2]=='f')
	       {if(b<0)
	       y=b-int(b-1);
	       else y=b-int(b);
	       }
	       else if(postfix[i-2]=='m')
	       {if(b<0)
	       y=-b;
	       else y=b;
	       }

	       else
		y=a*b;break;
     case '/': y=a/b;break;
     case '^': y=pow(a,b);break;
   }

   modifyPostfix(i,'y');
}

void modifyPostfix(int i,char t)
{

for(ptr=start;ptr->pos!=i;ptr=ptr->next);

ptr=ptr->pre;ptr=ptr->pre;
ptr->f=y;

postfix[i-2]=t;

for(;postfix[i+1];i++)
postfix[i-1]=postfix[i+1];

postfix[i-1]='\0';

modifylist(i,y);


}

//(*&%^*$^E(&$^(%*%^&%(&%^&)(%(&)$^^%*#^*#)&%^&$^&$)$(%&#$^*%#%^*$(&$%*^($*%^#

void intopost()
{
 clrscr();
 char ele,elem,st[2];
 int pre,prep,popped,j=0,chk=0;
 strcpy(postfix," ");
 cout<<"Enter the expression - ";gets(infix);
 chk=braces(infix);
 if(chk!=0)
 {
  cout<<"\nunbalanced no. of braces!!\nExtra "<<(chk==1?"right brace":";left brace");
  getch();
  exit(1);
 }
 for(int i=0;infix[i];i++)
 {
  if(infix[i]!='('&&infix[i]!=')'&&infix[i]!='+'&&infix[i]!='-'&&infix[i]!='*'&&infix[i]!='/'&&infix[i]!='^')
  postfix[j++]=infix[i];
  else
  if(infix[i]=='(')
  {
     elem=infix[i];
     push(elem);
  }
  else
  if(infix[i]==')')
  {
     while((popped=pop())!='(')
     {
       postfix[j++]=popped;
     }
  }
  else
  {
	elem=infix[i];
	pre=precedence(elem);
	ele=topelement();
	prep=precedence(ele);

 if(pre>prep) push(elem);
 else
 {
  while(prep>=pre)
  {
   if(ele=='#') break;
     popped=pop();
   ele=topelement();
   postfix[j++]=popped;
   prep=precedence(ele);
  }
  push(elem);
  }
 }
}
  while((popped=pop())!='#')
  postfix[j++]=popped;
  postfix[j]='\0';
//  cout<<"\n postfix: "<<postfix<<endl;
//  getch();
}




int precedence(char ch)
{
 switch(ch)
 {
   case '^':return 5;
   case '/':return 4;
   case '*':return 4;
   case '+':return 3;
   case '-':return 3;
   default :return 0;
 }
}

char pop()
{
 char ret;
 if(top!=-1)
 {
   ret=stack[top];
   top--;
   return ret;
 }
 else
 return '#';
}

char topelement()
{
 char ch;
 if(top!=-1)
  ch=stack[top];
 else
  ch='#';
 return ch;
}

void push(char ch)
{
  if(top!=size-1)
  {
    top++;
    stack[top]=ch;
  }
}

int braces(char * s)
{
 int leftbr=0,rightbr=0;
 for(int i=0;s[i];i++)
 {
   if(s[i]=='(')  leftbr++;
   else
   if(s[i]==')')  rightbr++;
 }
 if(leftbr==rightbr)  return 0;
 else
 if(leftbr<rightbr)   return 1;
 else
 return -1;
}

void showaxis()
{
   int gdriver = DETECT, gmode, errorcode;
   int midx,midy;
   char msg[80];

   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   midx=getmaxx()/2;
   midy=getmaxy()/2;

   line(midx,0,midx,getmaxy());
   line(0,midy,getmaxx(),midy);

for(double p=-1;p<getmaxx();p=p+10)
line(p,midy-5,p,midy+5);
for(p=-1;p<getmaxy();p=p+10)
line(midx-5,p,midx+5,p);
}

void filllist()
{
start=ptr=naya=NULL;

for(int i=0;postfix[i];i++)
{
naya=new graph;
naya->next=NULL;
naya->pre=NULL;
naya->pos=i;

if(int(postfix[i])<=58)
naya->f=int(postfix[i])-48;

else naya->c=postfix[i];

if(start==NULL)
{
ptr=start=naya;
}
else
{
naya->pre=ptr;
ptr=ptr->next=naya;
}

}

}

void modifylist(int i,double y)
{
	for(ptr=start;ptr->pos!=i;ptr=ptr->next);

	for(;postfix[i+1];i++)
	{
	 ptr->pre=ptr->next;
	 ptr=ptr->next;
	}

}

void options()
{

cout<<"\n (c) NIHAL GOEL  2013 \n";
cout<<"\n   available functions sin - s";
cout<<"\n                       cos - c";
cout<<"\n                       tan - t";
cout<<"\n                       mod - m";
cout<<"\n       greatest integer [] - g";
cout<<"\n       fractional part  {} - f";
cout<<"\n                       log - l";
cout<<"\n\n  how to use them - sin(x) should be written as (s*x) ... use brackets if u want to replace x by an expression ";
cout<<"\n\n  eg : sin(x^2) is written as (s*(x^2)) \n\n press any key to continue - ";getch();
cout<<endl;

}
