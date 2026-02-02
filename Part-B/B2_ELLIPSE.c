#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
void midpoint_ellipse(float,float,float,float,int);
void ellipsepoints(float,float,float,float,int);
void main()
{
int gd=DETECT,gm,c;
float a,b,xc,yc;
clrscr();
initgraph(&gd,&gm,"C:\\TC\\BGI");
printf("\n\tEnter the values for x radius and y radius:");
scanf("%f%f",&a,&b);
printf("\n\tEnter the value for color:");
scanf("%d",&c);
printf("\n\tEnter center points of the ellipse:");
scanf("%f%f",&xc,&yc);

detectgraph(&gd,&gm);
midpoint_ellipse(a,b,xc,yc,c);
getch();
closegraph();
}
void midpoint_ellipse(float rx,float ry,float xc,float yc,int c)
{
float rx2=rx*rx;
float ry2=ry*ry;
float tworx2=2*rx2;
float twory2=2*ry2;
float p,x=0,y=ry,p1,p2;
float px=0,py=tworx2*y;
ellipsepoints(xc,yc,x,y,c);
p1=ry2-(rx2*ry)+(0.25*rx2);
while(px<py)
{
x++;
px+=twory2;
if(p1<0)
p1+=ry2+px;
else
{
y--;
py-=tworx2;
p1+=ry2+px-py;
}
ellipsepoints(xc,yc,x,y,c);
}
p2=(ry2*(x+0.5)*(x+0.5))+(rx2*(y-1)*(y-1))-rx2*ry2;
while(y>0)
{
y--;
py-=tworx2;
if(p2>0)
p2+=rx2-py;
else
{
x++;
px+=twory2;
p2+=rx2-py+px;
}
ellipsepoints(xc,yc,x,y,c);
}
}
void ellipsepoints(float xc,float yc,float x,float y,int c)
{
putpixel(xc+x,yc+y,c);
delay(1);
putpixel(xc-x,yc+y,c);
delay(1);
putpixel(xc-x,yc-y,c);
delay(1);
putpixel(xc+x,yc-y,c);
}


