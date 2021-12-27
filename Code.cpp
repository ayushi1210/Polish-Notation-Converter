//*********** Header Files ********
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>

//************ Global Variables *********
char a[100],b[100];
char n[100];
int topa=-1,topb=-1;
int top=-1;
int e[100];

//******** Function for Case 2 **********
void push(int i)
{
top++;
e[top]=i;
}

//******** Functions for Case 1 *********
//***To push in Stack B ****
void pushb(int i)
{
topb++;
b[topb]=i;
}

//***To push in Stack B ****
void pushb(int i)
{
topb++;
b[topb]=i;
}

//*** To push in Stack A ***
void pusha(int i)
{
topa++;
a[topa]=i;
}

//*** To pop from Stack A ***
void popa()
{
pushb(a[topa]);
topa--;
}

//******* Main Function *********
void main()
{
int driver=DETECT,mode;
//********* Front Page ********
initgraph(&driver,&mode,"c:\\turboc3\\bgi");
settextstyle(4,0,6);
outtextxy(10,20,"D.A.V. PUBLIC SCHOOL");
settextstyle(1,0,4);
setcolor(10);
outtextxy(230,140,"A Project on");
settextstyle(7,0,4);
setcolor(YELLOW);
outtextxy(1900,190,"Polish Notations");
settextstyle(5,0,4);
setcolor(YELLOW);
outtextxy(20,330,"Submitted By :");
setcolor(13);
settextstyle(1,0,3);
outtextxy(20,370,"Ayushi Debnath";);
outtextxy(20,395,"Class XII");
outtextxy(20,420,"Roll No.");
settextstyle(5,0,4);
setcolor(YELLOW);
outtextxy(430,330,"Guided By :-";);
setcolor(13);
settextstyle(1,0,3);
outtextxy(430,370,"Mr. Ajay B. Innes");
outtextxy(430,395,"Computer Science");
outtextxy(430,420," Faculty");
getch();

//********* Starting **********
initgraph(&driver,&mode,"c:\\turboc3\\bgi");
clrscr();
setcolor(RED);
outtextxy(270,220,"STARTING UP..");
for(int u=0;u&lt;3;u++)
{
for(int k=270;k&lt;=379;k++)
{
setfillstyle(SOLID_FILL,BLACK);
bar(270,234,389,231);
rectangle(270,230,390,235);
setfillstyle(1,GREEN);
bar(k,234,k+10,231);
delay(5);
}
}
delay(300);
closegraph();
int choice,i;
clrscr();
do
{
//*********** Main Menu ***********
clrscr();
initgraph(&driver,&mode,"c:\\turboc3\\bgi");
outtextxy(275,116,"MAIN MENU");
setcolor(RED);
rectangle(260,100,360,130);
for(int i=100;i>=80;i--)
{ delay(5);
for(int j=150;j>;=130;j--)
rectangle(270,i,350,j);
}
delay(10);
//////////////////////////////////////////////
for(i=170;i<=525;i++)
{
setcolor(BLACK);
outtextxy(240,196,"LOADING...");
setfillstyle(SOLID_FILL,RED);
bar(170,215,i,185);
delay(1);
}
outtextxy(173,196,"1. Convert Infix to Postfix Expression");
setcolor(GREEN);
rectangle(170,185,525,215);
delay(1);
///////////////////////////////////////////////
for(i=170;i<=525;i++)
{
setcolor(BLACK);
outtextxy(240,230,"LOADING...");
setfillstyle(SOLID_FILL,RED);
bar(170,250,i,220);
delay(1);
}
outtextxy(173,230,"2. Evaluate the Postfix Expression");
setcolor(WHITE);
rectangle(170,220,525,250);
delay(1);
////////////////////////////////////////////
for(i=170;i<=525;i++)
{
setfillstyle(3,RED);
outtextxy(240,267,"LOADING...");
bar(170,256,i,286);
delay(1);
}
outtextxy(173,267,"0. EXIT");
setcolor(14);
rectangle(170,256,525,286);
int choice;
settextstyle(7,0,2);

cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
outtextxy(205,298,"Your Choice");
setcolor(10);
cin>>choice;
closegraph();
if(choice == 0)
break;
switch(choice)
{
case 1:
//********** Case 1:Conversion of Infix to Postfix***************
clrscr();
int driver=DETECT,mode;
initgraph(&driver,&mode,"c:\\turboc3\\bgi");
settextstyle(7,0,1);
setcolor(10);
outtextxy(0,0,"Enter the Postfix Expression");
cout<<"\n\n";
cin>>n;
int l=0,m=0;
//Priority Check for + and -
for(i=0;n[i]!='\0';i++)
{
if(n[i]=='+')
{
break;
}
if(n[i]=='/')
{

l=1;
break;
}
}
//Priority Check for * and /
for(i=0;n[i]!='\0';i++)
{
if(n[i]=='*')
{
break;
}
if(n[i]=='/')
{
m=1;
break;
}
}
for(i=0;n[i]!='\0';i++)
{
if(isalpha(n[i]))
pushb(n[i]);
else
{
//***** Conditions to pop if '+' *****
if(n[i]=='+')
{
if(a[topa]=='-'&& l==1)
popa();
if(a[topa]=='^'||a[topa]=='*'||a[topa]=='/')
popa();
}
//***** Conditions to pop if '-' *****
if(n[i]=='-')
{
if(a[topa]=='+'&& l==0)
popa();
if(a[topa]=='^'||a[topa]=='*';||a[topa]=='/')
popa();
}
//***** Conditions to pop if '*' *****
if(n[i]=='*')
{
if(a[topa]=='/'&& m==1)
popa();
if(a[topa]=='^')
popa();
}
//***** Conditions to pop if '/' *****
if(n[i]=='/')
{
if(a[topa]=='*'&& m==0)
popa();
if(a[topa]=='^')
popa();
}
pusha(n[i]);
////***** Conditions to pop if '()' *****
if(n[i]==')')
{
topa--;
while(a[topa]!='(')
{
popa();
}
topa--;
}
}
}
for(i=topa;i<=0;i--)
{
popa();
}
settextstyle(7,0,1);
outtextxy(0,50,"The Resultant Postfix expression is");
cout<<"\n\n";
for(i=0;i<=topb;i++)
cout<<b[i];
break;
case 2:
//****** Case 2: Evaluation of Postfix Expression **************
int p,q;
clrscr();
closegraph();
initgraph(&driver,&mode,"c:\\turboc3\\bgi");
settextstyle(7,0,1);
setcolor(YELLOW);
outtextxy(0,0,"Enter postfix expression separated by commas ");
cout<<"\n\n";
cin>>n;
int j;
j=strlen(n);
for(i=0;i<j;i++)
{
if(isdigit(n[i]))
{
int s=0;
while(n[i]!=',')
{
s=(s*10)+(n[i]-48);
i++;

}
push(s);
}
else
{
q=e[top--];
p=e[top--];
switch(n[i])
{
case '+':push(p+q);
break;
case '-':push(p-q);
break;
case'*':push(p*q);
break;
case ';':push(p/q);
break;
case '^':push(pow(p,q));
break;
}

i++;
}
}
settextstyle(7,0,1);
outtextxy(0,50,"Result: ");
cout<<"\n\n";
cout<<e[top];
break;
}
getch();
}while(choice!=0);
clrscr();
initgraph(&driver,&mode,"c:\\turboc3\\bgi");
setcolor(RED); int b=640;
outtextxy(270,220,"shutting down..");
for(i=1;i<=320;i++)
{
setfillstyle(SOLID_FILL,RED);
bar(1,480,i,1);
setcolor(BLACK);
settextstyle(7,0,3);
outtextxy(i-90,220,"THANK ");
bar(640,1,b,480);
outtextxy(b+10,220,"YOU ");
delay(20);
b--;
}
delay(2000);
closegraph();
}
