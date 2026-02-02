#include<graphics.h>
#include<conio.h>
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	//person
	circle(125,200,30);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(125,200,WHITE);
	setcolor(2);
	line(125,230,125,330);

	//hand
	line(125,260,150,230);
	line(125,260,100,230);

	//leg
	line(125,330,100,370);
	line(125,330,150,370);
	setcolor(15);

	//eyes
	ellipse(135,190,0,360,3,6);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(135,190,WHITE);
	ellipse(115,190,0,360,3,6);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(115,190,WHITE);

	//mouth
	pieslice(125,215,0,180,8);

	//nose
	rectangle(123,200,125,205);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(124,201,WHITE);
	setcolor(15);

	//fish
	ellipse(400,375,0,360,40,20);
	setfillstyle(SOLID_FILL,3);
	floodfill(400,375,WHITE);

	//tail
	sector(450,375,30,330,20,10);
	setfillstyle(SOLID_FILL,RED);
	floodfill(450,374,WHITE);
	arc(360,375,325,40,30);
	setcolor(0);
	circle(370,373,2);
	setcolor(15);
	pieslice(400,355,55,200,13);
	setfillstyle(SOLID_FILL,2);
	floodfill(400,354,15);
	pieslice(400,395,160,310,13);
	line(360,377,363,376);

	//lake
	setcolor(15);
	rectangle(300,300,550,450);
	setfillstyle(SLASH_FILL,1);
	floodfill(350,440,WHITE);

	//rope
	line(150,230,350,375);

	//crow1
	arc(150,50,0,90,20);
	arc(190,50,90,180,20);

	//crow2
	arc(350,50,0,90,20);
	arc(390,50,90,180,20);

	getch();
	closegraph();
}