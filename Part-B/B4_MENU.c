#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void bound(int x,int y,int fill,int boun)
{
if(getpixel(x,y)!=boun && getpixel(x,y)!=fill)
{
delay(1);
putpixel(x,y,fill);
bound(x+1,y,fill,boun);
bound(x,y+1,fill,boun);
bound(x-1,y,fill,boun);
bound(x,y-1,fill,boun);
}
}
void floodfill1(int x,int y,int fill,int prev)
{
if(getpixel(x,y)==prev)
{
delay(1);
putpixel(x,y,fill);
floodfill1(x+1,y,fill,prev);
floodfill1(x-1,y,fill,prev);
floodfill1(x,y+1,fill,prev);
floodfill1(x,y-1,fill,prev);
}
}
int main()
{
int gd=DETECT,gm,prev,ch;//points[]={150,100,250,100,250,200,150,200,150,100};
initgraph(&gd,&gm,"C:\\TC\\BGI");
setcolor(4);
//setfillstyle(SOLID_FILL,6);
rectangle(150,100,200,150);
do
{
printf("MENU");
printf("\n1. BOUNDARY FILL");
printf("\n2. FLOOD FILL");
printf("\n3. EXIT");
printf("\nEnter the choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
	bound(180,120,6,4);
	break;
//floodfill(180,120,WHITE);
case 2:
	prev=getpixel(180,120);
	floodfill1(180,120,8,prev);
	break;
case 3:
	exit(0);
}
}
while(ch!=3);
getch();
closegraph();
return 0;
}