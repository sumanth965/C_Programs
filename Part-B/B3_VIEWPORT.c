#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void windowtoviewport(int winx[],int winy[],int n,int xwmin,int ywmin,int xwmax,int ywmax,int xvmin,int yvmin,int xvmax,int yvmax)
{
int i,viewx[10],viewy[10];
float sx,sy;
sx=(float)(xvmax-xvmin)/(xwmax-xwmin);
sy=(float)(yvmax-yvmin)/(ywmax-ywmin);
for(i=0;i<n;i++)
{
viewx[i]=xvmin+(float)((winx[i]-xwmin)*sx);
viewy[i]=yvmin+(float)((winy[i]-ywmin)*sy);
}
setcolor(BLUE);
rectangle(xvmin,yvmin,xvmax,yvmax);
for(i=0;i<n-1;i++)
line(viewx[i],viewy[i],viewx[i+1],viewy[i+1]);
line(viewx[i],viewy[i],viewx[0],viewy[0]);
}
void main()
{
int gd=DETECT,gm;
int n,i,winx[25],winy[25];
int xwmax,ywmax,xwmin,ywmin;
int xvmax,yvmax,xvmin,yvmin;
//int winx[10],winy[10],n,i;
initgraph(&gd,&gm,"C:\\TC\\BGI");
printf("Enter the window coordinates(xmin,ymin,xmax,ymax):");
scanf("%d%d%d%d",&xwmin,&ywmin,&xwmax,&ywmax);
printf("\nEnter viewport coordinates(xmin,ymin,xmax,ymax):");
scanf("%d%d%d%d",&xvmin,&yvmin,&xvmax,&yvmax);
printf("\nEnter no.of vertices:");
scanf("%d",&n);
printf("\nEnter values of vertices:");
for(i=0;i<n;i++)
scanf("%d%d",&winx[i],&winy[i]);
cleardevice();
setcolor(RED);
rectangle(xwmin,ywmin,xwmax,ywmax);
for(i=0;i<n-1;i++)
line(winx[i],winy[i],winx[i+1],winy[i+1]);
line(winx[i],winy[i],winx[0],winy[0]);
getch();
windowtoviewport(winx,winy,n,xwmin,ywmin,xwmax,ywmax,xvmin,yvmin,xvmax,yvmax);
getch();
closegraph();
}


