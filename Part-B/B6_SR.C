#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
void input();
void output();
void shearing();
void reflection();
int a[10],b[10],i,ch=0,tx,ty,fx,fy,n,axis,sh;
float sx,sy;
void input()
{
	printf("enter the no.of vertices");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the coordinates");
		scanf("%d%d",&a[i],&b[i]);
	}
}
void output()
{
	cleardevice();
	line(0,240,640,240);
	line(320,0,320,480);
	for(i=0;i<n-1;i++)
	line(320+a[i],240-b[i],320+a[i+1],240-b[i+1]);
	line(320+a[i],240-b[i],320+a[0],240-b[0]);
}
void shearing()
{
	output();
	printf("enter the shear value");
	scanf("%d",&sh);
	printf("enter the fixed point");
	scanf("%d%d",&fx,&fy);
	printf("enter the axis for shearing if x-axis then if y-axis the 0:");
	scanf("%d",&axis);

	for(i=0;i<n;i++)
	{
		if(axis==1)
		a[i]=a[i]+sh*(b[i]-fy);
		else
		b[i]=b[i]+sh*(a[i]-fx);
	}
	delay(10);
	output();
	getch();
}
void reflection()
{
	output();
	printf("enter the relection about axis if x-axis then 1 if y-axis then 0:");
	scanf("%d",&axis);
	for(i=0;i<n;i++)
	{
		if(axis==1)
		b[i]=(-1)*b[i];
		else
		a[i]=(-1)*a[i];
	}
	delay(10);
	output();
	getch();
}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	do
	{
		cleardevice();
		printf("\n MENU \n");
		printf("\n 1.shearing");
		printf("\n 2.reflection");
		printf("\n 3.exit");
		printf("\n enter the choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				input();
				shearing();
				break;
			case 2:
				input();
				reflection();
				break;
			case 3:
				exit(0);
		}
	}
	while(ch!=3);
	getch();
	closegraph();
}

