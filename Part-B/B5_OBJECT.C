#include<stdio.h>
#include<graphics.h>
#include<math.h>
int x[5],y[5],i,n;
void drawpoly1()
{
	for(i=0;i<n;i++)
	{
		if(i==n-1)
		{
			line(x[i],y[i],x[0],y[0]);
		}
		else
		{
			line(x[i],y[i],x[i+1],y[i+1]);
		}
	}
}
void trans()
{
	int tx,ty;
	printf("Enter the value for tx and ty:");
	scanf("%d\t%d",&tx,&ty);
	for(i=0;i<n;i++)
	{
		x[i]=x[i]+tx;
		y[i]=y[i]+ty;
	}
}
void scale()
{
	int xf,yf,sx,sy;
	xf=x[0];
	yf=y[0];
	printf("Enter the scaling factor x");
	scanf("%d",&sx);
	printf("Enter the scaling factor y");
	scanf("%d",&sy);
	for(i=0;i<n;i++)
	{
		x[i]=x[i]*sx+xf*(1-sx);
		y[i]=y[i]*sy+yf*(1-sy);
	}
}
void rotate()
{
	int xr,yr,angle,newx,newy;
	float theta;
	printf("Enter the angle");
	scanf("%d",&angle);
	theta=(3.14/180)*angle;
	//xr=x[0];
	//yr=x[0];
	for(i=0;i<=n;i++)
	{
		newx=(x[i]-x[0])*cos(theta)-(y[i]-y[0])*sin(theta)+x[0];
		newy=(y[i]-y[0])*cos(theta)+(x[i]-x[0])*sin(theta)+y[0];
		x[i]=newx;
		y[i]=newy;
	}
}
void main()
{
	int gd=DETECT,gm,ch;
	clrscr();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter x[%d]:",i);
		scanf("%d",&x[i]);
		printf("\nEnter y[%d]:",i);
		scanf("%d",&y[i]);
	}
	do
	{
	printf("\nMENU");
	printf("\n1 TRANSLATIOn \n2 SCALING \n3 ROTATION \n4 EXIT");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		drawpoly1();
		trans();
		drawpoly1();
		break;
	case 2:
		drawpoly1();
		scale();
		drawpoly1();
		break;
	case 3:
		drawpoly1();
		rotate();
		drawpoly1();
		break;
	case 4:
		exit(0);
}
}
while(ch!=4);
	getch();
	closegraph();
}