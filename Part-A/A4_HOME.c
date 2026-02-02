#include<graphics.h>
#include<conio.h>
int main()
{
int gd=DETECT,gm,p[]={20,110,220,10,430,110,20,110};
clrscr();
initgraph(&gd,&gm,"c:\\TC\\BGI");
rectangle(58,110,377,338);
setfillstyle(SOLID_FILL,5);
floodfill(309,165,WHITE);
setfillstyle(HATCH_FILL,4);
fillpoly(4,p);
rectangle(220,110,270,338);
line(220,222,271,222);
circle(245,222,10);
setcolor(10);
rectangle(85,155,211,240);
line(85,195,211,195);
line(85,190,211,190);
line(95,155,95,240);
line(115,155,115,240);
line(135,155,135,240);
line(155,155,155,240);
line(175,155,175,240);
line(195,155,195,240);
setcolor(WHITE);
ellipse(320,230,5,365,20,30);
setfillstyle(XHATCH_FILL,4);
fillellipse(320,230,20,30);
line(200,340,160,376);
line(280,340,240,378);
line(160,376,240,378);
getch();
closegraph();
return 0;
}
