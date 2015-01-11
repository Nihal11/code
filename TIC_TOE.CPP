#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
//#include"passs.cpp"
int ch2,cox[10],i,m=1,line,turn=1,md,corn,excorn,cent,medium;
char str1[15],str2[15]="computer",noy,ch1,ch3,ch4;
void welcome();
void circle(int);
void cross(int);
void et(int);
void space();
void getu();
void result();
void madeby();
void compeas();
void comphard();
void compmedium();
void compturn(int&,int&);
void comprand();
void compmid();
void midelse();
void corner();
void checkcorn();
void checkexcorn();
void excorner();
void centroid();
void textcolor(int color);
void main()
{textcolor(18);
clrscr();
//pass();
clrscr();
welcome();
cout<<"\n\n\t\t\tenter your name user - ";
cin>>str1;
clrscr();
start:
str2[0]='c';str2[1]='o';str2[2]='m';str2[3]='p';str2[4]='u';str2[5]='t';str2[6]='e';str2[7]='r';
clrscr();
int ch=0;
int lev=0;
choice:
clrscr();
welcome();
cout<<"\n\n\n\n\n\t\t\t1- Player vs Player\n\t\t\t2- Player vs Computer \n\n\t\t\t3- Exit\n\n\t\t\tenter your choice - ";cin>>ch;clrscr();
if(ch==3)
{cout<<"\n\nARE YOU SURE YOU WANT TO EXIT!(y/n):  ";cin>>ch1;
if(ch1=='y'||ch1=='Y')
{exit(1);}
else goto start;
}
if(ch==1)
{
cout<<"\n\n\t\t\tPress:\n\n\t\t\t1 To enter your name\n\n\t\t\t2 To exit\n\n\t\t\t3 To go back to the choice menu\n\n\t\t\t";cin>>ch2;
if(ch2==1)
     {
     cout<<"\n\n\t\t\tENTER YOUR NAME USER 2 -  ";
     cin>>str2;
     }
else if(ch2==2)
     {cout<<"\n\nARE YOU SURE YOU WANNA EXIT!(y/n):  ";cin>>ch3;
	if(ch3=='y'||ch3=='Y')
		{exit(1);}
	else goto start;
     }
else if(ch2==3)
     {goto choice;}

}

clrscr();

if(ch==2)
{welcome();cout<<"\n\n\n\n\n\n\n\n\n\t\t\t Choose your difficulty level: \n\n\t\t\t1- To play at the MOST EASY LEVEL\n\n\t\t\t2- To play at MEDIUM LEVEL\n\n\t\t\t3-To play at the LEGENDARY ( UNBEATABLE ) LEVEL\n\n\t\t\t4- Go Back to the choice menu\n\n\t\t\t5- exit\n\n\t\t\t  enter the choice- ";cin>>lev;clrscr();
randomize();
switch(lev)
{
case 1:m=2;break;
case 2:m=random(100);break;
case 3:m=1;break;
case 4:goto choice;break;
case 5:{cout<<"\n\nARE YOU SURE YOU WANNA EXIT!(y/n):  ";cin>>ch4;if(ch4=='Y'||ch4=='y')exit(1);else goto choice;}break;
default:cout<<"\n\nWRONG CHOICE";clrscr();getch();goto start;break;
}
}
for(int st=1;st<=9;cox[st]=0,st++);
turn=1;
corn=0;md=0;cent=0;excorn=0;medium=0;
noy='n';

clrscr();

int p=0;

do
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n";
for(int h=0,i=1;h<3;h++,i=i+3)
{
	for(line=1;line<=5;line++,i=i-3)
	{ space();
		for(int k=0;k<3;k++,++i)
		{
			if(cox[i]==1)
			circle(i);
			else if(cox[i]==2)
			cross(i);
			else if(line==3)
			{cout<<"   "<<i<<"   ";et(i);}
			else {cout<<"       ";et(i);}
		}

	}

 space();
 if(i<7)
 cout<<"-----------------------\n";

}
result();
if(noy=='y'||noy=='Y')
goto start;
p++;
if(ch==1)
getu();
else if(ch==2)
switch(lev)
{
case 1:compeas();break;
case 2:compmedium();break;
case 3:comphard();break;
}
}while(p<10);
}

void circle(int i)
{
	switch(line)
	{
	case 1:cputs("   *   ");break;
	case 2:cputs("  * *  ");break;
	case 3:cputs(" *   * ");break;
	case 4:cputs("  * *  ");break;
	case 5:cputs("   *   ");break;
	}et(i);
}
void cross(int i)
{
	switch(line)
	{
	case 1:cputs(" *   * ");break;
	case 2:cputs("  * *  ");break;
	case 3:cputs("   *   ");break;
	case 4:cputs("  * *  ");break;
	case 5:cputs(" *   * ");break;
	}et(i);
}
void et(int i)
{
int w=i;
if(w%3!=0)
cout<<"|";
else
{cout<<"\n";}
}
void space()
{
for(int sp=0;sp<=25;sp++)
cout<<" ";
}

void getu()
{
int f;
	if(m%2==0)
	{
	re1:
	cout<<"\nenter your choice "<<str1<<" - ";
	cin>>f;
	if(cox[f]!=0)
	{cout<<str1<<" \nsorry cannot do that \n\n";
	goto re1;}
	cox[f]=1;
	}
	else
	{re2:
	cout<<"\nenter your choice "<<str2<<" - ";
	cin>>f;
	if(cox[f]!=0)
	{cout<<str2<<" \nsorry cannot do that \n\n";
	 goto re2;}
	cox[f]=2;}
	m++;
}

void result()
{
int win=0;
for(int var=1;var<=3;var++)
if(cox[var]==cox[var+3]&&cox[var]==cox[var+6]&&cox[var]!=0)
win=cox[var];

for(var=1;var<=7;var=var+3)
if(cox[var]==cox[var+1]&&cox[var+1]==cox[var+2]&&cox[var]!=0)
win=cox[var];

if(cox[1]==cox[5]&&cox[5]==cox[9]&&cox[1]!=0)
win=cox[1];

if(cox[3]==cox[5]&&cox[5]==cox[7]&&cox[3]!=0)
win=cox[3];

if(win==1)
{cout<<"oh yes!!! The winner is "<<str1<<" the awesome (circle)";
getch();
madeby();
cout<<"\nwanna play more (y/n) - ";cin>>noy;
if(noy=='n'||noy=='N')
exit(1);}

if(win==2)
{cout<<"\noh yes!!! The winner is "<<str2<<" the awesome (cross)";
getch();
madeby();
cout<<"\nwanna play more (y/n)- ";cin>>noy;
if(noy=='n'||noy=='N')
exit(1);}

if(cox[1]!=0&&cox[2]!=0&&cox[3]!=0&&cox[4]!=0&&cox[5]!=0&&cox[6]!=0&&cox[7]!=0&&cox[8]!=0&&cox[9]!=0)
{cout<<"\n\nOH! no!!! the match is a draaaawwww !!!!";
getch();
madeby();
cout<<"\n\nwanna play more (y/n)- ";cin>>noy;
if(noy=='n'||noy=='N')
exit(1);}

}
void welcome()
{
  cout<<"\n\t\t*     *  ***  *    ***  ***  * * * *  ***\n";
  cout<<"\t\t * * *   **   *   *     * *  *  *  *  ** \n";
  cout<<"\t\t  ***    ***  ***  ***  ***  *     *  ***\n";
  cout<<"\n\n";
  cout<<"\t\t	      *****   ***     \n";
  cout<<"\t\t		*     * *     \n";
  cout<<"\t\t		*     ***     \n";
  cout<<"\n\n";
  cout<<"\t\t***** *   * ***     *     * ***  **** *   ***  \n";
  cout<<"\t\t  *   * * * **       * * *  * *  * *  *   *  * \n";
  cout<<"\t\t  *   *   * ***       ***   ***  *  * *** ***  \n";
  cout<<"\n\n";
  cout<<"\t\t	       ***   ***    \n";
  cout<<"\t\t	       * *   **      \n";
  cout<<"\t\t	       ***   *       \n";
  cout<<"\n\n";
  cout<<"\t\t***** *  ***   *****   *    ***    *****  ***  *** \n";
  cout<<"\t\t  *   * *        *    ***  *         *    * *  **  \n";
  cout<<"\t\t  *   *  ***     *    * *   ***      *    ***  *** \n\n";
}
void madeby()
{
clrscr();
 cout<<"\n\t\t**   **   **   **    ****     ****  *    *           \n";
 cout<<"\t\t* * * *  *  *  *  *  *        *  *   *  *   ::       \n";
 cout<<"\t\t*  *  *  ****  *  *  ***      ***      *      >>>>>>>\n";
 cout<<"\t\t*     *  *  *  *  *  *        *  *    *     ::       \n";
 cout<<"\t\t*     *  *  *  ***   ****     ***    *               \n";
 cout<<"\n\n";
 cout<<"\t\t\t**   *  *  *  *    **   *   \n";
 cout<<"\t\t\t**   *  *  *  *   *  *  *   \n";
 cout<<"\t\t\t* *  *  *  ****   ****  *   \n";
 cout<<"\t\t\t*  * *  *  *  *   *  *  *   \n";
 cout<<"\t\t\t*   **  *  *  *   *  *  ****\n";
 cout<<"\n\n";
 cout<<"\t\t\t **   **  *  ***  \n";
 cout<<"\t\t\t*  *  **  *  *  * \n";
 cout<<"\t\t\t****  * * *  *  * \n";
 cout<<"\t\t\t*  *  *  **  ***  \n";
 cout<<"\n\n";
 cout<<"\t\t\t **   ***   ***** *  *  **   *\n";
 cout<<"\t\t\t*  *  *  *    *   *  *  **   *\n";
 cout<<"\t\t\t****  * *     *   *  *  * *  *\n";
 cout<<"\t\t\t*  *  *  *  * *   *  *  *  * *\n";
 cout<<"\t\t\t*  *  *  *   **   ****  *   **\n";

}
void compeas()
{

int f,k=1,ind=0,ijk=0;;
int comp[11];
for(int i=1;i<=10;i++)
if(cox[i]==1)
{comp[k]=i;k++;}


	if(m%2==0)
	{
	re:
	cout<<"enter your choice "<<str1<<" - ";
	cin>>f;
	if(cox[f]!=0)
	{cout<<str1<<" \n sorry cannot do that \n\n";
	goto re;}
	cox[f]=1;
	}
	else
	{	ind=2;
		compturn(ind,ijk);
		ind=1;
		if(ijk!=1)
		compturn(ind,ijk);
		if(ijk!=1)
		comprand();
	}
	m++;
}

void compturn(int &ind,int &ijk)
{

	for(int var=1,k=6;var<=6;var++)
	{
		if(var>=4)
		k=-3;
		if(cox[var]==cox[var+3]&&cox[var]==ind)
		if(cox[var+k]==0)
		{cox[var+k]=2;ijk=1;}
	}
	if(ijk!=1)
	for(var=1,k=2;var!=3;var=var+3)
	{
		if(var>7)
		{var=var-8;k=-1;}
		if(cox[var]==cox[var+1]&&cox[var]==ind)
		if(cox[var+k]==0)
		{cox[var+k]=2;ijk=1;}
	}

if(ijk!=1)
{
if(cox[1]==cox[9]&&cox[1]==ind&&cox[5]==0)
{cox[5]=2;ijk=1;}
else if(cox[1]==cox[3]&&cox[1]==ind&&cox[2]==0)
{cox[2]=2;ijk=1;}
else if(cox[4]==cox[6]&&cox[4]==ind&&cox[5]==0)
{cox[5]=2;ijk=1;}
else if(cox[7]==cox[9]&&cox[7]==ind&&cox[8]==0)
{cox[8]=2;ijk=1;}
else if(cox[1]==cox[7]&&cox[1]==ind&&cox[4]==0)
{cox[4]=2;ijk=1;}
else if(cox[2]==cox[8]&&cox[2]==ind&&cox[5]==0)
{cox[5]=2;ijk=1;}
else if(cox[3]==cox[9]&&cox[3]==ind&&cox[6]==0)
{cox[6]=2;ijk=1;}
else if(cox[3]==cox[7]&&cox[3]==ind&&cox[5]==0)
{cox[5]=2;ijk=1;}
else if(cox[1]==cox[5]&&cox[1]==ind&&cox[9]==0)
{cox[9]=2;ijk=1;}
else if(cox[5]==cox[9]&&cox[5]==ind&&cox[1]==0)
{cox[1]=2;ijk=1;}
else if(cox[3]==cox[5]&&cox[3]==ind&&cox[7]==0)
{cox[7]=2;ijk=1;}
else if(cox[5]==cox[7]&&cox[5]==ind&&cox[3]==0)
{cox[3]=2;ijk=1;}
}
}

void comprand()
{
rerandom:
randomize();
int xyz=(random(100))%10;
if(cox[xyz]==0)
cox[xyz]=2;
else
goto rerandom;
}

void comphard()
{
int f,k=1,ind=0,ijk=0;
int comp[11];
for(int i=1;i<=10;i++)
if(cox[i]==1)
{comp[k]=i;k++;}

	if(m%2==0)
	{
	cout<<"enter your choice "<<str1<<" - ";
	cin>>f;
	if(cox[f]!=0)
	{cout<<str1<<" \nyou lose !!! (cheated) ";
	getch();exit(1);}
	cox[f]=1;
	 if(turn==2&&(cox[2]==1||cox[4]==1||cox[6]==1||cox[8]==1))
	 md=1;
	 else if(turn==2&&cox[5]==1)
	 cent=1;
	 else checkcorn();
	 checkexcorn();

	}
	else
	{ if(turn==1)
	 { randomize();
	   int f;
	   f=random(100);
	   f=f%4;
		switch(f)
		{
		case 0:cox[1]=2;break;
		case 1:cox[3]=2;break;
		case 2:cox[7]=2;break;
		case 3:cox[9]=2;break;
		}
	 }

	 if(md==1)
	 compmid();
	 else if(corn==1)
	 corner();
	 else if(excorn==1)
	 excorner();
	 else if(cent==1)
	 centroid();
	}
	m++;turn++;
}

void compmid()
{
int ijk=0,ind=0;

if(turn==3)
{cox[5]=2;ijk=1;}
else if(turn==5)
       {ind=2;
	compturn(ind,ijk);
	ind=1;
	compturn(ind,ijk);
	if(ijk!=1)
	midelse();ijk=1;
       }
ind=2;
if(ijk!=1)
compturn(ind,ijk);
ind=1;
if(ijk!=1)
compturn(ind,ijk);
}

void midelse()
{
if(cox[7]==2&&cox[4]==1)
cox[9]=2;
else if(cox[7]==2&&cox[8]==1)
cox[1]=2;
else if(cox[1]==2&&cox[2]==1)
cox[7]=2;
else if(cox[1]==2&&cox[4]==1)
cox[3]=2;
else if(cox[3]==2&&cox[2]==1)
cox[9]=2;
else if(cox[3]==2&&cox[6]==1)
cox[2]=2;
else if(cox[9]==2&&cox[8]==1)
cox[3]=2;
else if(cox[9]==2&&cox[6]==1)
cox[7]=2;
else if(cox[3]==2&&cox[6]==1)
cox[5]=2;
else if(cox[7]==2&&cox[8]==1)
cox[1]=2;
}

void corner()
{
int ind=0,ijk=0;
   if(turn==3)
   {

      if(cox[7]==2&&(cox[9]==1||cox[1]==1))
      cox[3]=2;

      else

      if(cox[1]==2&&(cox[3]==1||cox[7]==1))
      cox[9]=2;

      else

      if(cox[3]==2&&(cox[9]==1||cox[1]==1))
      cox[7]=2;

      else

      if(cox[9]==2&&(cox[3]==1||cox[7]==1))
      cox[1]=2;

      ijk=1;
   }
 else
 {
   ind=2;
   compturn(ind,ijk);
   ind=1;
   if(ijk!=1)
   compturn(ind,ijk);
 }

}

void checkcorn()
{
if(turn==2)
{
if(cox[3]==2&&(cox[1]==1||cox[9]==1))
corn=1;
else if(cox[1]==2&&(cox[3]==1||cox[7]==1))
corn=1;
else if(cox[7]==2&&(cox[1]==1||cox[9]==1))
corn=1;
else if(cox[9]==2&&(cox[3]==1||cox[7]==1))
corn=1;
}

}

void excorner()
{
int ijk=0,ind=0;
if(turn==3||turn==5)
{
if(cox[1]==2&&cox[9]==1)
{ if(turn==3)
  cox[7]=2;
  else if(turn==5)
  {
  if(cox[4]==0)
  cox[4]=2;
  else
  cox[3]=2;
  }
}
else if(cox[3]==2&&cox[7]==1)
{ if(turn==3)
  cox[9]=2;
  else if(turn==5)
  {
  if(cox[6]==0)
  cox[6]=2;
  else
  cox[1]=2;
  }
}
else if(cox[7]==2&&cox[3]==1)
{ if(turn==3)
  cox[9]=2;
  else if(turn==5)
  {
  if(cox[8]==0)
  cox[8]=2;
  else
  cox[1]=2;
  }
}
else if(cox[9]==2&&cox[1]==1)
{ if(turn==3)
  cox[3]=2;
  else if(turn==5)
  {
  if(cox[6]==0)
  cox[6]=2;
  else
  cox[7]=2;
  }
}

}
else
{
ind=2;
compturn(ind,ijk);
ind=1;
if(ijk!=1)
compturn(ind,ijk);
}

}
void checkexcorn()
{
if(turn==2)
{
if(cox[1]==2&&cox[9]==1)
excorn=1;
if(cox[3]==2&&cox[7]==1)
excorn=1;
if(cox[7]==2&&cox[3]==1)
excorn=1;
if(cox[9]==2&&cox[1]==1)
excorn=1;
}

}

void centroid()
{
int ijk=0,ind=0;
if(turn==3)
{
if(cox[1]==2&&cox[5]==1)
cox[9]=2;
else if(cox[3]==2&&cox[5]==1)
cox[7]=2;
else if(cox[7]==2&&cox[5]==1)
cox[3]=2;
else if(cox[9]==2&&cox[5]==1)
cox[1]=2;
}
else
{
ind=2;
compturn(ind,ijk);
ind=1;
if(ijk!=1)
compturn(ind,ijk);
}

}
void compmedium()
{
if(turn==1)
if(m%2==0)
medium=1;

if(medium==1)
compeas();
else
comphard();

}