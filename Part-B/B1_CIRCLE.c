#include<conio.h>
#include<graphics.h>
void sym(x,y,a,b)
{
putpixel(x+a,y+b,RED);
putpixel(x+a,-y+b,RED);
putpixel(-x+a,-y+b,RED);
putpixel(-x+a,y+b,RED);
putpixel(y+a,x+b,RED);
putpixel(y+a,-x+b,RED);
putpixel(-y+a,x+b,RED);
putpixel(-y+a,-x+b,RED);
}
int main()
{
int gd=DETECT,gm,x=0,y,r,p,a,b;
initgraph(&gd,&gm,"C:\\TC\\BGI");
printf("Enter the radius: ");
scanf("%d",&r);
printf("Enter the value foe center x and y");
scanf("%d%d",&a,&b);
y=r;
p=1-r;
while(x<y)
{
sym(x,y,a,b);
if(p<0)
p=p+2*x+3;
else
{
p=p+2*(x-y)+5;
y=y-1;
}
x=x+1;
}
getch();
closegraph();
return 0;
}