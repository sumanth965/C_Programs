#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
typedef struct coordinate
{
	int x,y;
	char code[5];
}POINT;
void drawwindow(int,int,int,int);
void drawline(POINT,POINT,int);
POINT setcode(POINT,int,int,int,int);
int visibility(POINT,POINT);
POINT resetndpt(POINT,POINT,int,int,int,int);
void main()
{
	int gd,gm;
	int xmin,ymin,xmax,ymax,c=10,v;
	POINT p1,p2;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("\nEnter the coordinate value for first endpoint of the line:");
	scanf("%d%d",&p1.x,&p1.y);
printf("\n\tEnter the coordinate value for second endpoint of the line:");
scanf("%d%d",&p2.x,&p2.y);
printf("\n\tEnter the values for endpoint of the clip window:");
scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
cleardevice();
printf("\n\tBefore clipping:");
drawwindow(xmin,ymin,xmax,ymax);
getch();
drawline(p1,p2,c);
getch();
p1=setcode(p1,xmin,ymin,xmax,ymax);
p2=setcode(p2,xmin,ymin,xmax,ymax);
v=visibility(p1,p2);
cleardevice();
printf("\n\tAfter clipping:");
switch(v)
{
	case 0:drawwindow(xmin,ymin,xmax,ymax);
		drawline(p1,p2,c);
		break;
	case 1:drawwindow(xmin,ymin,xmax,ymax);
		break;
	case 2:p1=resetndpt(p1,p2,xmin,ymin,xmax,ymax);
		p2=resetndpt(p2,p1,xmin,ymin,xmax,ymax);
		drawwindow(xmin,ymin,xmax,ymax);
		drawline(p1,p2,c);
		break;
}
getch();
closegraph();
}
void drawwindow(int xmin,int ymin,int xmax,int ymax)
{
setcolor(12);
rectangle(xmin,ymin,xmax,ymax);
}
void drawline(POINT p1,POINT p2,int c)
{
setcolor(c);
line(p1.x,p1.y,p2.x,p2.y);
}
int visibility(POINT p1,POINT p2)
{
int i,flag=0;
for(i=0;i<4;i++)
if(p1.code[i]!=0||p2.code[i]!=0)
flag=i;
if(flag==0)
return 0;
for(i=0;i<4;i++)
if(p1.code[i]==p2.code[i]&&p1.code[i]==1)
flag=0;
if(flag==0)
return 1;
else
return 2;
}
POINT setcode(POINT p,int xmin,int ymin,int xmax,int ymax)
{
POINT ptemp;
int i;

for(i=0;i<4;i++)
ptemp.code[i]=0;
if(p.y<ymin)
ptemp.code[0]=1;
if(p.y>ymax)
ptemp.code[1]=1;
if(p.x>xmax)
ptemp.code[2]=1;
if(p.x<xmin)
ptemp.code[3]=1;

ptemp.x=p.x;
ptemp.y=p.y;

return ptemp;
}

POINT resetndpt(POINT p1,POINT p2,int xmin,int ymin,int xmax,int ymax)
{
int i;
float m;
POINT temp;
if(p1.code[3]==1)
temp.x=xmin;
if(p1.code[2]==1)
temp.x=xmax;
if(p1.code[3]==1||p1.code[2]==1)
{
m=(float)(p2.y-p1.y)/(p2.x-p1.x);
temp.y=p1.y+m*(temp.x-p1.x);
for(i=0;i<4;i++)
temp.code[i]=p1.code[i];
if(temp.y>ymin&&temp.y<=ymax)
return temp;
}
if(p1.code[1]==1)
temp.y=ymax;
if(p1.code[0]==1)
temp.y=ymin;
if(p1.code[1]==1||p1.code[0]==1)
{
m=(float)(p2.x-p1.x)/(p2.y-p1.y);
temp.x=p1.x+m*(temp.y-p1.y);
for(i=0;i<4;i++)
temp.code[i]=p1.code[i];
return temp;
}
return p1;
}
