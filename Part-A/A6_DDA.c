#include<graphics.h>
#include<conio.h>
int main()
{
	int gd=DETECT,gm,x1,y1,x2,y2,m,steps,xinc,yinc,dx,dy,i;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	clrscr();
	printf("enter the x1 value");
	scanf("%d",&x1);
	printf("enter the x2 value");
	scanf("%d",&x2);
	printf("enter the y1 value");
	scanf("%d",&y1);
	printf("enter the y2 value");
	scanf("%d",&y2);
	dx=x2-x1;
	printf("dx=%d\t",dx);

	dy=y2-y1;
	if(abs(dx)>abs(dy))
		steps=dx;
	else
		steps=dy;
	xinc=dx/steps;
	yinc=dy/steps;
	for(i=0;i<steps;i++)
	{
		putpixel(x1,y1,WHITE);
		x1=x1+xinc;
		y1=y1+yinc;
	}
	getch();
	closegraph();
	return 0;
}