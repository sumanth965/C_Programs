#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
void main()
{
	int gd=DETECT,gm;
	int car[]={110,120,120,120,125,110,145,110,150,120,160,120,160,130,110,130,110,120};
	int r1x1=123,r1y1=115,r1x2=130,r1y2=120;
	int r2x1=140,r2y1=115,r2x2=147,r2y2=120;
	int temp[18],i=3,j;
	int c1x1=125,c1y1=130,c2x1=145,c2y1=130;

	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	for(j=0;j<18;j++)
		temp[j]=car[j];
	do
	{
		//car
		setcolor(1);
		drawpoly(9,car);
		//window
		setfillstyle(SOLID_FILL,6);
			rectangle(r1x1+i,r1y1,r1x2+i,r1y2);
			rectangle(r2x1+i,r2y1,r2x2+i,r2y2);
			floodfill(r1x1+i+1,r1y1+1,BLUE);
			floodfill(r2x1+i+1,r2y1+1,BLUE);
			//wheels
			setcolor(WHITE);
			setfillstyle(8,MAGENTA);
			circle(c1x1+i,c1y1,4);
			circle(c2x1+i,c2y1,4);
			floodfill(c1x1+i,c1y1,WHITE);
			floodfill(c2x1+i,c2y1,WHITE);
			delay(100);
			cleardevice();
			i=i+3;
			for(j=0;j<18;j=j+2)
			car[j]=temp[j]+i;
	}while(!kbhit()&&i<500);

		getch();
		closegraph();
}
