#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main()
{
	int gd=DETECT,gm,x1,x2,y1,y2,p,dx,dy,x,y;
	initgraph(&gd,&gm,"c:\\tc\\BGI");
	printf("enter X1:");
	scanf("%d",&x1);
	printf("enter y1:");
	scanf("%d",&y1);
	printf("enter X2:");
	scanf("%d",&x2);
	printf("enter y2:");
	scanf("%d",&y2);
	x=x1;
	y=y1;
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	while(x<=x2)
	{
		putpixel(x,y,WHITE);
		x=x+1;
		if(p<0)
		{
			p=p+2*dy;
		}
		else
		{
			p=p+2*dy-2*dx;
		y=y+1;
		}
		getch();
		closegraph();
		return 0;
	}
}