#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


#define space 32
#define up 72
#define down 80
#define right 77
#define left 75
#define Enter 13
#define Esc 27



#define MAXPTS	15

#define NFONTS 11


#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989

int w,j,m,k,d;
 void *l,*v,*s,*u,*f;

void mast();
void welcome();
void lin();
void welcome2();

void galaxy();
void create2();
void created();
void name();

void loading();
void scean();
void ins1();
void level1();
void levelcom();
void scean2();
void bird();
void level2();
void scean3();
void win();
void thank();
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");
mast();
cleardevice();


welcome();
cleardevice();
lin();
cleardevice();
welcome2();
cleardevice();
galaxy();
cleardevice();
create2();

cleardevice();
created();

cleardevice();
name();

getch();
cleardevice();
loading();
cleardevice();

scean();

cleardevice();
ins1();

cleardevice();
level1();
cleardevice();
scean2();
cleardevice();
  bird();
cleardevice();
level2();
getch();
}

void mast()
{
struct PTS
{
  int x, y;
};
double AspectRatio;
int    MaxX, MaxY;
int    MaxColors;

 int xasp, yasp;
   struct viewporttype vp;
  struct PTS points[MAXPTS];
  int i, j, h, w, xcenter, ycenter;
  int radius, angle, step;
  double  rads;


  MaxColors = getmaxcolor() + 1;

  MaxX = getmaxx();
  MaxY = getmaxy();

  getaspectratio( &xasp, &yasp );
  AspectRatio = (double)xasp / (double)yasp;





  xcenter = 640 / 2;
  ycenter = 480 / 2;
  radius  = (480 - 10) / (AspectRatio * 2);
  step	  = 360 / MAXPTS;

  angle = 0;
  for( i=0 ; i<MAXPTS ; ++i )
  {

    rads = (double)angle * PI / 180.0;
    points[i].x = xcenter + (int)( cos(rads) * radius );
    points[i].y = ycenter - (int)( sin(rads) * radius * AspectRatio );
    angle += step;
    delay(50);
  }

  circle( xcenter, ycenter, radius );

  for( i=0 ; i<MAXPTS ; ++i ){
    for( j=i ; j<MAXPTS ; ++j )
    {
      moveto(points[i].x, points[i].y);
	   setcolor(rand());
      lineto(points[j].x, points[j].y);
    delay(50);
    }
  }


  getch();

}



void welcome()
{
int x,y,i;
x=getmaxx()/2;

y=getmaxy()/2;
setbkcolor(5);
for(i=0;i<200;i++)
{
delay(10);
setcolor(i);
arc(0,0,270,360,i+20);
arc(650,0,180,270,i+20);
arc(0,480,0,90,i+20);
arc(650,480,90,180,i+20);
}
for(i=63;i<150;i++)
{
delay(25);
setcolor(i/15);
circle(320,250,i);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
outtextxy(268,230,"WELCOME");
}
getch();
}

void lin()
{
int i;
int midx=640/2,midy=480/2,mr=(480/2)-10;
setbkcolor(0);
     for(i = 0; i < 360; i += 2)

      {

	    setcolor(rand() % 15);

	    line(midx,midy,midx + mr * cos(i * 3.1417 / 180),midy - mr * sin(i * 3.1417 / 180) );

	    delay(20);


      }
      getch();
      }


void welcome2()
{

int i,x,y;
cleardevice();

setcolor(15);
for(i=0;i<=100;i=i+5)
{
//clearviewport();
cleardevice();

settextstyle(4,HORIZ_DIR,4);
outtextxy(50,i,"WELCOME");
settextstyle(4,HORIZ_DIR,4);
outtextxy(300-i,160,"TO");
settextstyle(4,HORIZ_DIR,4);
outtextxy(120+i,220,"COMPUTER SCIENCE");
settextstyle(4,HORIZ_DIR,4);
outtextxy(400,400-i,"DEPARTMENT");
delay(100);

}
setfillstyle(1,1);
floodfill(10,10,15);
getch();
}
void galaxy()
{
int gd = DETECT, gm, x, y, color, angle = 0;
struct arccoordstype a, b;

initgraph(&gd, &gm, "..\\BGI");
//delay(2000);
setbkcolor(0);
while(angle<=360)
{
setcolor(BLACK);

arc(getmaxx()/2,getmaxy()/2,angle,angle+2,170);
setcolor(RED);
getarccoords(&a);
circle(a.xstart,a.ystart,25);
setcolor(BLACK);
arc(getmaxx()/2,getmaxy()/2,angle,angle+2,220);
getarccoords(&a);
setcolor(GREEN);
circle(a.xstart,a.ystart,25);
angle = angle+5;
setcolor(rand());
settextstyle(1,HORIZ_DIR,5);
outtextxy(220,140,"WELCOME");
outtextxy(290,180,"TO");
settextstyle(1,HORIZ_DIR,6);
outtextxy(220,220,"GAMING");
outtextxy(220,280,"GALAXY");
delay(10);
}

//setcolor(rand());
while(!kbhit())
{
putpixel(random(640),random(540),rand());
delay(6);
}

getch();
}

void create2()
{
//      cleardevice();
      int t=0,r=10;
      float x;

      cleardevice();
     // setbkcolor(6);
      while(!kbhit())
      {

     settextstyle(4,0,5);
      setcolor(10);
      outtextxy(250,200,"guided");
      outtextxy(300,250,"By:-");

      settextstyle(8,0,1);
      setcolor(rand());
     outtextxy(130,90,"VINITA");
      outtextxy(155,130," SINGH");
      outtextxy(25,170,"  ANITA");
      outtextxy(25,205,"GAIKWAD");
      outtextxy(320,100,"    KRUTIKA");
       outtextxy(350,140,"    TAWDE");
      outtextxy(455,223,"    PRIYANKA");
      outtextxy(485,255,"  GAWHANE");
      outtextxy(325,345,"     TEJASWEE");
      outtextxy(435,385,"POL");
      outtextxy(150,325,"VAIDEHI");
      outtextxy(145,355,"DESHPANDE");

      x=(3.14159/180)*t;
      setcolor(x);
      circle(320+225*sin(x+180),240+225*cos(x),r);
      circle(320-225*sin(x+180),240-225*cos(x),r);
      circle(300+225*sin(x+180),240+225*cos(x+90),r);
      circle(300-225*sin(x+180),240-225*cos(x+90),r);

      delay(5);
      t=t+2;
      }
//getch();
}

void created()
{
  int x1=40,y1=250,x2=350,y2=250;
   int j=0,k=0;

 cleardevice();
 setcolor(5);
	setbkcolor(3);
  settextstyle(4,0,6);
  outtextxy(x1,y1,"  CREATED ");
  outtextxy(x2,y2,"  BY :-");

 delay(5);


 setcolor(10);
for(j=0; j<=620; j+=20)
{

outtextxy(0+j,-10,"ê");
outtextxy(0,20+k,"ê");
outtextxy(10+j,420,"ê");
outtextxy(610,20+k,"ê");

k+=20;
if(k==340)
k=k;
delay(100);
}

    getch();

}


void name()
{
int i;
//initgraph(&gd,&gm,"..\\bgi");
setbkcolor(10);
setcolor(1);
arc(-150,150,340,21,230);   //1
arc(268,340,150,200,230);    //2
arc(200,595,60,130,230);      //3
arc(450,210,230,300,230);    //4
arc(780,332,150,200,230);     //5
arc(360,150,340,26,230);       //6
arc(210,260,60,128,240);       //8
arc(450,-150,235,301,235);    //7
setfillstyle(11,1);
floodfill(5,5,1);
settextstyle(1,HORIZ_DIR,5);
settextjustify(135,50);

for(i=0;i<5;i++)
{
setcolor(rand());
//cleardevice();
//clearviewport();

outtextxy(125,50+i,"AJAY");
outtextxy(148,90+i,"YADAV");

outtextxy(360,80+i,"RITESH");
outtextxy(383,120+i,"YADAV");

outtextxy(220,170+i,"NEHA");
outtextxy(249,210+i,"CHAUBEY");

outtextxy(90,270+i,"SUMAN");
outtextxy(113,310+i,"YADAV");

outtextxy(395,320+i,"SNEHAL");
outtextxy(423,360+i,"HANDE");
}

getch();
//getch();
//closegraph();

}

void loading()
{
int i,j;
setbkcolor(6);
setcolor(14);
settextstyle(4,0,5);
outtextxy(50,280,"loading");
rectangle(50,350,578,380);

for(i=20;i<=80;i=i+12)
{
setcolor(4);
circle(160+i,320,4);
setfillstyle(1,rand());
floodfill(160+i,320,4);
if(230+i==470)
{
circle(160+i,320,4);
setfillstyle(1,rand());
floodfill(160+i,320,4);
if(230+i==470)
{
break;
}
delay(50);
}
for(i=20;i<=520;i=i+20)
{
setcolor(14);
rectangle(35+i,355,50+i,375);
setfillstyle(1,14);
delay(50);
if(i==520)
break;
}
for(j=1;j<70;j++)
{
if(i<=525)
{
setcolor(14);
settextstyle(4,0,4);
outtextxy(385,400,"PRESS ENTER");
}
delay(10);
}
getch();
//closegraph();
}
}


void scean()
{
int i;
//initgraph(&gd,&gm,"..//bgi");
{
{
setcolor(3);
//rectangle(50,230,160,400);
arc(100,250,60,240,15);
arc(100,240,270,10,8);
arc(100,252,90,230,4);
arc(92,258,250,10,6);
arc(105,245,320,50,8);
line(110,250,111,257);
arc(109,255,210,340,2);
line(108,256,108,260);
line(108,260,106,260);
line(106,260,106,264);
line(106,264,102,264);
line(102,264,102,270);
line(92,264,92,270);
circle(86,240,3);
arc(82,245,80,210,8);
arc(68,252,300,30,8);
arc(77,244,320,30,6);
arc(74,252,260,30,8);
arc(98,268,200,340,6);

setcolor(12);              //top
arc(98,268,200,340,10);
arc(76,280,310,40,8);
line(80,274,90,270);
arc(115,280,120,250,7);
line(102,272,110,276);
arc(70,296,320,40,16);
arc(125,296,140,220,16);
line(82,307,113,307);
setfillstyle(1,12);
floodfill(95,300,12);       //top

line(82,310,113,310);
line(82,307,82,310);
line(115,307,113,310);

setcolor(2);                //skirt
line(82,310,113,310);
line(82,307,70,340);
line(113,307,125,342);
arc(75,338,190,340,7);
arc(87,338,190,340,7);
arc(100,338,190,340,7);
arc(116,338,190,343,9);
setfillstyle(1,2);
floodfill(85,320,2);           //skirt

setcolor(14);
circle(111,330,2);
setfillstyle(1,14);
floodfill(111,330,14);
circle(110,320,2);
floodfill(110,320,14);
circle(100,325,2);
floodfill(100,325,14);
circle(90,330,2);
floodfill(90,330,14);
circle(88,318,2);
floodfill(88,318,14);
circle(80,330,2);
floodfill(80,330,14);

setcolor(11);                  //rl
line(114,342,122,375);
line(104,342,112,375);
line(122,375,130,375);
arc(116,378,100,350,4);
line(120,380,130,380);
line(130,380,128,378);
line(130,375,128,377);
setfillstyle(1,11);
//floodfill(115,360,1);            //rl

line(93,342,84,375);
line(82,342,74,375);
arc(76,380,90,340,4);
line(80,382,90,385);
line(82,376,92,379);
line(90,385,87,382);
line(92,379,89,382);

arc(73,280,300,70,6);
arc(118,280,120,250,6);
line(75,274,60,293);
line(75,285,67,298);
line(60,293,62,315);
line(67,298,69,315);
circle(67,315,4);
//setcolor(4);
arc(118,280,120,250,6);
//line(116,276,132,298);
//line(116,286,130,304);
//line(130,296,140,288);
//line(130,304,148,290);
line(116,276,125,292);
line(116,286,124,300);
line(125,292,135,280);
line(124,300,138,286);

circle(136,284,3);
//setfillstyle(1,3);
//floodfill(123,290,4);
//setcolor(6);
//circle(143,288,4);
//setfillstyle(1,5);
//floodfill(143,288,6);
circle(105,250,1);
putpixel(80,240,2);
//floodfill(100,300,3);
//floodfill(100,240,0);
//clearviewport();
//floodfill(80,300,3);

w=imagesize(60,270,140,385 );
l=malloc(w);
getimage(60,270,140,385,l);
m=imagesize(70,235,115,270);
s=malloc(m);
getimage(70,235,115,270,s);


/*k=imagesize(60,235,140,385);
u=malloc(k);
getimage(60,235,1640,350,u);  */

cleardevice();
putimage(45,370,l,1);
putimage(55,335,s,1);
}
setbkcolor(2);
//nadi
setcolor(1);
line(0,330,0,380);
line(639,190,639,300);
arc(120,470,80,150,180);
arc(120,510,80,150,180);

arc(215,124,248,302,180);
arc(215,164,248,302,180);

arc(420,420,80,130,180);
arc(420,460,80,130,180);

//arc(440,420,50,100,180);
//arc(430,460,80,130,180);
//arc(
arc(515,74,248,340,180);
arc(515,114,248,340,180);

//arc(515,114,248,271,180);
//arc(515,114,300,340,180);
setfillstyle(1,1);
floodfill(10,340,1);
//circle(10,340,1);
}


setcolor(4);
line(100,50,150,0);
line(150,0,200,50);
line(200,50,190,60);
line(190,60,150,20);
line(150,20,110,60);
line(110,60,100,50);
setfillstyle(9,4);
floodfill(150,10,4);

setcolor(14);
line(125,25,120,10);
line(115,35,110,20);
line(120,10,110,20);
setfillstyle(9,14);
//floodfill(117,26,14);
line(115,56,125,105);
line(185,56,175,105);
line(78,105,222,105);
line(190,60,150,20);
line(150,20,110,60);
setcolor(4);
line(78,105,222,105);
arc(55,115,270,25,25);
arc(245,115,155,270,25);
line(50,140,250,140);
setfillstyle(9,4);
floodfill(150,120,4);

setcolor(5);
line(80,140,80,230);
line(220,140,220,230);
line(80,230,220,230);
line(50,140,250,140);
setfillstyle(1,5);
floodfill(100,210,5);

setcolor(7);
rectangle(90,150,120,180);
setfillstyle(8,2);
floodfill(100,170,7);
rectangle(180,150,210,180);
floodfill(200,160,7);
setcolor(9);
ellipse(150,230,0,180,20,60);
line(80,230,220,230);
setfillstyle(1,9);
floodfill(150,200,9);
circle(150,200,2);
setcolor(15);
ellipse(140,60,0,360,7,12);
setfillstyle(1,15);
floodfill(140,60,15);
ellipse(160,60,0,360,7,12);
setfillstyle(1,15);
floodfill(160,60,15);

setcolor(1);
circle(140,60,4);
setfillstyle(1,1);
floodfill(140,60,1);
setcolor(1);
circle(160,60,4);
setfillstyle(1,1);
floodfill(160,60,1);

setcolor(0);
circle(140,60,2);
setfillstyle(1,0);
floodfill(140,60,0);
setcolor(0);
circle(160,60,2);
setfillstyle(1,0);
floodfill(160,60,0);

setcolor(14);
arc(150,82,180,360,14);
arc(150,85,170,10,15);
setfillstyle(9,14);
floodfill(150,98,14);

setcolor(15);
arc(199,70,200,340,20);
arc(199,80,200,340,20);
ellipse(218,85,0,360,4,8);
setfillstyle(1,15);
//floodfill(200,75,15);

line(220,80,240,50);
line(220,89,246,52);

setcolor(2);
ellipse(240,40,0,360,35,15);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(222,35,"welcome");
setfillstyle(1,5);
floodfill(240,40,2);



setbkcolor(0);
setcolor(2);
arc(535,300,90,230,20);     //tree 2
arc(555,280,25,180,20);
arc(590,280,360,144,20);
arc(535,330,132,300,20);
arc(600,298,320,68,20);
arc(600,320,260,40,25);

arc(535,375,0,90,30);
arc(595,375,90,180,30);
setfillstyle(9,2);
floodfill(568,328,2);

setcolor(6);
arc(515,380,300,60,40);
arc(615,380,110,240,40);
arc(535,375,0,90,30);
arc(595,375,90,180,30);

line(500,415,800,415);
setfillstyle(6,6);
floodfill(565,398,6);    //tree 2
//pool
setcolor(6);
{
//line(490,255,490,295);
//line(510,255,510,295);
rectangle(490,255,510,295);
}
setfillstyle(2,6);
floodfill(495,260,6);

/*setviewport(0,0,640,440,1);
for(i=30;i<100;i++)
{
delay(100);
setcolor(i/5);
arc(500,100,10,160,i+10);
}
arc(330,50,90,260,20);  //cloud
arc(350,30,25,180,20);
arc(380,40,280,144,20);
arc(342,58,210,330,20);
arc(365,50,240,0,20);
setfillstyle(1,9);
floodfill(350,44,1);  //cloud*/
setcolor(15);
arc(450,50,90,260,20);  //cloud
arc(470,30,25,180,20);
arc(500,40,280,144,20);
arc(462,58,210,330,20);
arc(485,50,240,0,20);
setfillstyle(1,15);
floodfill(475,44,15);  //cloud

//tunel
line(130,370,270,370);
line(130,440,270,440);
ellipse(130,405,0,360,10,35);
ellipse(270,405,0,360,10,35);
//instruction
setcolor(2);

ellipse(280,150,270,405,20,80);
ellipse(550,150,135,270,20,80);

setcolor(4);
{
ellipse(292,82,0,360,6,15);
ellipse(538,82,0,360,6,15);
setfillstyle(1,14);
floodfill(292,82,4);
floodfill(538,82,4);
}

setcolor(2);
line(290,70,540,70);
line(290,95,538,95);

line(280,230,550,230);

setfillstyle(1,6);
floodfill(320,120,2);
setcolor(4);
setfillstyle(1,2);
floodfill(310,80,4);
//gotoxy(310,100);
setcolor(1);
settextstyle(8,0,1);
outtextxy(320,90,"This is map screen.");
settextstyle(2,0,5);
outtextxy(305,115,"Here you can see how far you");
outtextxy(305,130,"come in the game, what level");
outtextxy(305,145,"is next. It contain 3 levels.");

outtextxy(310,170,"After each level you complete")  ;
outtextxy(305,185,"you will return to this screen");
outtextxy(305,200,"so you can see your progress.");
setcolor(15);
settextstyle(2,0,4);
outtextxy(365,220,"GOOD LUCK");
//void girl()

/*d=imagesize(0,0,640,480);
f=malloc(d);
getimage(0,0,640,480,f);  */
getch();

}

void ins1()
{

putimage(50,200,l,1);
putimage(60,165,s,1);
//putimage(50,165,u,1);
setcolor(1);
settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
outtextxy(150,25,"INSTRUCTIONS");
setcolor(7);
setbkcolor(6);
settextstyle(1,HORIZ_DIR,2);
outtextxy(260,85,": To move RIGHT press RIGHT-KEY.");
outtextxy(260,135,": To move LEFT press LEFT-KEY.");
outtextxy(260,185,": To move UP press UP-KEY.");
outtextxy(260,245,": To move DOWN press DOWN-KEY.");
outtextxy(220,315,"ESC : To EXIT from the game.");
outtextxy(150,385,"SPACE-BAR : To SHOOT press SPACE-BAR.");

line(225,100,255,100);
line(240,95,255,100);
line(240,105,255,100);

line(225,150,255,150);
line(240,145,225,150);
line(240,155,225,150);

line(240,190,240,222);
line(240,190,235,205);
line(240,190,245,205);

line(240,250,240,284);
line(240,284,235,265);
line(240,284,245,265);

setcolor(7);
rectangle(10,10,630,470);
rectangle(5,5,635,475);

getch();
}
void level1()
{
   time_t first, second;
 int x1=60,y1=230,x2=70,y2=195,a,b,c,p1,p2,p3,p4,q1,q2,q3,q4,r1,r2,r3,r4,s1,s2,s3,s4,t1,t2,t3,t4,u1,u2,u3,u4,v1,v2,v3,v4,w1,w2,w3,w4;
int key;
setbkcolor(0);
first=time(NULL);
 printf("press enter one's");
 while(1)

     {
		line(p1=180,p2=180,p3=180,p4=340);
		line(q1=285,q2=0,q3=285,q4=190);
		line(r1=285,r2=370,r3=285,r4=480);
		line(s1=385,s2=180,s3=385,s4=280);
		line(u1=493,u2=0,u3=493,u4=150);
		line(t1=475,t2=340,t3=475,t4=480);

		line(v1=595,v2=0,v3=595,v4=100);
		line(w1=600,w2=200,w3=600,w4=320);
		  key=getch();
		  if(key==up)
		  {
		  y1=y1-4;
		  y2=y2-4;
		  }
		  if(key==right)
		    {
		    x1=x1+4;
		    x2=x2+4;
		    }
		  if(key==left)
		   {
		   x1=x1-4;
		   x2=x2-4;

		   }
		  if(key==down)
		  {
		  y1=y1+4;
		  y2=y2+4;
		  }
		 /* if(key==space)
		  { sound(4500);
		    b=x1,c=y1;
		    putimage(x1,y1,l,XOR_PUT);
		    a=1;
		  } */
		  if(key==Esc)
		  exit(0);
		if( (x1+80)>p1 && (y1+115)>p2 && x1<=p3 && y1<=p4) //first
		goto loss;
	      //	exit(0);

		if((x1+80)>=q1 && y1<=q4 && x1<=q3 )   //second line
	       goto loss;
	     //  exit(0);

		if((x1+80)>=r1 && (y1+115)>=r2 && x1<=r3)   //third line
		 goto loss;
	      //	 exit(0);

		 if( (x1+80)>=s1 && (y1+115)>=s2 && x1<=s3 && y1<=s4 )   //fourth line
		 goto loss;
	      //	 exit(0);

	       if((x1+80)>=u1 && (y1)<=u4 && x1<=u3) //fifth
		goto loss;
	      //	exit(0);

		if((x1+80)>=t1 && (y1+115)>=t2 && x1<=t3 ) // six
		goto loss;
	      //	exit(0);

	      if((x1+80)>=v1 && y1<=v4 && x1<=v3)      // seven
	     goto loss;
	     // exit(0);

	       if((x1+80)>=w1 && (y1+115)>=w2 && x1<=w3 && y1<=w4 )    // eight
	       goto loss;
	      if((x1+80)>=620)
	       goto levcom;

	       if( (x2+55)>p1 && (y2+35)>p2 && x2<=p3 && y2<=p4) //first
		exit(0);

		if((x2+55)>=q1 && y2<=q4 && x2<=q3 )   //second line
	       exit(0);

		if((x2+55)>=r1 && (y2+35)>=r2 && x2<=r3)   //third line
		 exit(0);

		 if( (x2+55)>=s1 && (y2+35)>=s2 && x2<=s3 && y2<=s4 )   //fourth line
		 exit(0);

	       if((x2+55)>=u1 && (y2)<=u4 && x2<=u3) //fifth
		exit(0);

		if((x2+55)>=t1 && (y2+35)>=t2 && x2<=t3 ) // six
		exit(0);

	      if((x2+55)>=v1 && y2<=v4 && x2<=v3)      // seven
	      exit(0);

	       if((x2+55)>=w1 && (y2+35)>=w2 && x2<=w3 && y2<=w4 )    // eight
	       exit(0);

	       if(difftime(second,first)>=30)
		   exit(0);
		  putimage(x1,y1,l,XOR_PUT);
		  putimage(x2,y2,s,1);
	       /*	  if(x1>550)
		  {
		  putimage(x1,y1,l,XOR_PUT);
		  putimage(x2,y2,s,1);
		  x1=520;
		  x2=530;
		  putimage(x1,y1,l,XOR_PUT);
		  putimage(x2,y2,s,1);
		  }      */
		  if(x1<=3)
		  {
		  putimage(x2,y2,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  x1=3;
		  x2=3;
		  putimage(x2,y2,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  }
		  if(y2<=10)
		  {
		  putimage(x2,y2,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  y1=45;
		  y2=10;
		  putimage(x2,y2,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  }
		  if(y1>=370)
		  {
		  putimage(x2,y2,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  y1=370;
		  y2=335;
		  putimage(x2,y2,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  }
		  second = time(NULL);
gotoxy(50,2);
printf(" time= %f ",difftime(second,first));

     }

     loss: //
     {
     cleardevice();
	 while(!kbhit())
{
setcolor(random(16));
setfillstyle(SOLID_FILL,random(16));
setfillstyle(1,random(16));;
settextstyle(7,HORIZ_DIR,8);
outtextxy(140,150,"YOU");
outtextxy(260,220,"LOSE");
putpixel(random(600)+10,random(600)+10,random(16));
setcolor(random(16));
rectangle(0+random(100),0+random(100),640-random(100),480-random(100));

}
exit(0);
} //
//
levcom:
{
int i=0,j=0;

cleardevice();
levelcom();
//scean();
/*setbkcolor(0);
setcolor(2);

while(i<=200)
{
cleardevice();
settextstyle(7,0,5);
setbkcolor(9);
setcolor(14);
outtextxy(190,200," LEVEL - 1:");
outtextxy(194,230,"----------");
outtextxy(194,260,"COMPLETED");
settextstyle(10,0,2);

//delay(20);
i++;

if(kbhit())
break;
getch();
}

*/
}

     }

void level2()
{
 int x1=150,y1=340,x3=160,y3=305,a=0,b=0,c=0,x2=480,y2=50,x4=20,k=0;
 int key;
 setbkcolor(9);
setcolor(2);
//line(0,415,300,415);
//line(400,415,700,415);

arc(535,300,90,230,20);     //tree 2
arc(555,280,25,180,20);
arc(590,280,360,144,20);
arc(535,330,132,300,20);
arc(600,298,320,68,20);
arc(600,320,260,40,25);

arc(535,375,0,90,30);
arc(595,375,90,180,30);
setfillstyle(9,2);
floodfill(568,328,2);

setcolor(6);
arc(515,380,300,60,40);
arc(615,380,110,240,40);
arc(535,375,0,90,30);
arc(595,375,90,180,30);

line(40,415,110,415);
line(520,415,620,415);

//line(0,415,800,415);
setfillstyle(6,6);
floodfill(565,398,6);    //tree 2

setcolor(2);
arc(50,300,90,230,20);     //tree
arc(70,280,25,180,20);
arc(105,280,360,144,20);
arc(50,330,132,300,20);
arc(115,298,320,68,20);
arc(115,320,260,40,25);
arc(50,375,0,90,30);
arc(110,375,90,180,30);
setfillstyle(9,2);
floodfill(83,328,2);

setcolor(6);
arc(30,380,300,60,40);
arc(130,380,110,240,40);
arc(50,375,0,90,30);
arc(110,375,90,180,30);
setfillstyle(6,6);
floodfill(80,378,6);   //tree

setcolor(1);
arc(50,50,90,260,20);  //cloud
arc(70,30,25,180,20);
arc(100,40,280,144,20);
arc(62,58,210,330,20);
arc(85,50,240,0,20);
setfillstyle(1,15);
floodfill(75,44,1);  //cloud

arc(250,50,90,260,20);  //cloud
arc(270,30,25,180,20);
arc(300,40,280,144,20);
arc(262,58,210,330,20);
arc(285,50,240,0,20);
setfillstyle(1,15);
floodfill(275,44,1);  //cloud

arc(450,50,90,260,20);  //cloud
arc(470,30,25,180,20);
arc(500,40,280,144,20);
arc(462,58,210,330,20);
arc(485,50,240,0,20);
setfillstyle(1,15);
floodfill(475,44,1);  //cloud
//setcolor(2);
 //line(50,50,50,100);

 while(1)

     {

	  while(!kbhit())
		  {
		  delay(50);
		  putimage(x2,y2,v,1) ;
		   delay(50);
		   putimage(x2,y2,v,1) ;
		 x2+=x4;
		if(x2==0)
		x4=+20;
		if(x2==500)
		x4=-20;



		  if(a==1)
		{
			setcolor(4);
			line(b+40,c+10,b+40,c+30);
			line(b+40,c+10,b+35,c+20);
		       line(b+40,c+10,b+45,c+20);

		   //  /*  circle(b+5,c+10,2);
			setcolor(9);
			line(b+40,c+40,b+40,c+60);
			line(b+40,c+40,b+35,c+50);
			line(b+40,c+40,b+45,c+50);

		 //  circle(b+5,c+20,2);  */
			nosound();
			if(c>=-20)
			c-=10;

		      k++;

	       }

	    //  if(k==190)
	      // exit(0);
		if((c>=50&&c<=100))
	       {
			if((b+40)>=x2&&(b+40)<=(x2+50))
			{
			scean3();
			win();
			thank();
			}
	       }

}



		  key=getch();
		/*  if(key==up)
		  {
		  y1=y1-10;
		  y3=y3-10;
		  }*/
		  if(key==right)
		    {
		    x1=x1+20;
		    x3=x3+20;
		   }
		  if(key==left)
		   {
		   x1=x1-10;
		   x3=x3-10;
		  }
	      /*	  if(key==down)
		  {
		  y1=y1+10;
		  y3=y3+20;
		  }*/
		  if(key==space)
		  { //sound(4500);
		    b=x1,c=y1;
		    putimage(x1,y1,l,XOR_PUT);
		    putimage(x3,y3,s,1);
		    a=1;
		  }
		  if(key==Esc)
		  exit(0);
		  putimage(x3,y3,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  if(x1>430)
		  {
		  putimage(x3,y3,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  x1=400;
		  x3=410;
		  putimage(x3,y3,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  }
		  if(x1<=130)
		  {
		  putimage(x3,y3,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  x1=130;
		  x3=140;
		  putimage(x3,y3,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  }
		  if(y1<=290)
		  {
		  putimage(x3,y3,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  y1=290;
		  y3=255;

		  putimage(x3,y3,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  }
		  if(y1>=330 )
		  {
		  putimage(x3,y3,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  y1=330;
		  y3=295;
		  putimage(x3,y3,s,1);
		  putimage(x1,y1,l,XOR_PUT);
		  }
     }


}
void levelcom()
{
int i=0;
    for(i = 0; i <=240; i += 2)

      {

	    setcolor(7);//rand() % 15);

	   // circle(320, 240, i);
	   arc(i,i,0,360,i);
	   delay(40);
      }
	  while(!kbhit())
	  {
	  setcolor(rand());
      settextstyle(1,0,7);
      {
      outtextxy(500,50,"L");

      outtextxy(500,110,"E");
      outtextxy(500,170,"V");
      outtextxy(500,230,"E");
      outtextxy(500,290,"L");

       outtextxy(570,10,"C");
      outtextxy(570,70,"O");
      outtextxy(570,130,"M");
      outtextxy(570,190,"P");
      outtextxy(570,250,"L");
      outtextxy(570,310,"E");
      outtextxy(570,370,"T");
      outtextxy(570,420,"E");
      }

      putimage(350,255,s,1);
      putimage(340,290,l,1) ;
       }

      getch();
      }


void bird()
{
setcolor(4);
arc(100,100,90,240,20);
arc(110,100,300,90,20);
line(98,80,93,102);
line(112,80,115,102);
setfillstyle(1,4);
//

setcolor(4);
ellipse(105,110,0,360,20,10);
setfillstyle(1,4);
floodfill(105,110,4);

line(100,80,93,102);
line(110,80,115,102);

setcolor(2);
circle(96,110,4);
circle(115,110,4);
circle(96,110,1);
circle(115,110,1);
setfillstyle(1,0);

setcolor(6);
line(110,120,110,130);
line(100,120,100,130);
line(110,130,106,120);
line(100,130,104,120);
setfillstyle(1,6);

setcolor(15);
circle(120,90,2);
floodfill(120,90,4);
floodfill(90,90,4);
//rectangle(80,80,130,130);
j=imagesize(80,80,130,130) ;
v=malloc(j);
getimage(80,80,130,130,v);
}

void win()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");

while(!kbhit())
{
setcolor(random(16));
setfillstyle(1,random(16));;
settextstyle(4,HORIZ_DIR,8);
outtextxy(50,200,"YOU");
settextstyle(4,HORIZ_DIR,8);
outtextxy(430,200,"WON");
putpixel(random(600)+10,random(600)+10,random(16));
circle(320,240,random(100));
}
getch();
thank();
//exit(0);
//closegraph();

}
void thank()
{
int i,j;
for(i=0,j=0;i<200,j<300;i++,j++)
{
setcolor(14);
setbkcolor(4);
clearviewport();
settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
outtextxy(-180+i,50+i,"THANK YOU");
circle(600-j,16+i,50);
circle(580-j,4+i,8);
circle(620-j,4+i,8);
ellipse(600-j,31+i,180,360,15,10);
ellipse(580-j,4+i,0,180,8,3);
circle(580-j,6+i,2);
ellipse(620-j,4+i,0,180,8,3);
circle(620-j,6+i,2);
setfillstyle(1,14);
floodfill(621-j,7+i,14);
floodfill(581-j,7+i,14);
delay(20);
}
for(i=0;i<270;i++)
{
circle(30,130+i,15);
circle(600,300-i,15);
delay(25);
}
getch();
exit(0);
}
void scean2()
{
int i=0;
setbkcolor(0);
for(i=0;i<=170;i++)
{
cleardevice();
putimage(275+i,370,l,1);
putimage(285+i,335,s,1);
delay(10);
}
for(i=0;i<=40;i++)
{
cleardevice();
putimage(275+170,370-i,l,1);
putimage(285+170,335-i,s,1);
delay(10);
}



{
//setbkcolor(2);
//nadi
setcolor(1);
line(0,330,0,380);
line(639,190,639,300);
arc(120,470,80,150,180);
arc(120,510,80,150,180);

arc(215,124,248,302,180);
arc(215,164,248,302,180);

arc(420,420,80,130,180);
arc(420,460,80,130,180);

//arc(440,420,50,100,180);
//arc(430,460,80,130,180);
//arc(
arc(515,74,248,340,180);
arc(515,114,248,340,180);

//arc(515,114,248,271,180);
//arc(515,114,300,340,180);
setfillstyle(1,1);
floodfill(10,340,1);
//circle(10,340,1);
}


setcolor(4);
line(100,50,150,0);
line(150,0,200,50);
line(200,50,190,60);
line(190,60,150,20);
line(150,20,110,60);
line(110,60,100,50);
setfillstyle(9,4);
floodfill(150,10,4);

setcolor(14);
line(125,25,120,10);
line(115,35,110,20);
line(120,10,110,20);
setfillstyle(9,14);
//floodfill(117,26,14);
line(115,56,125,105);
line(185,56,175,105);
line(78,105,222,105);
line(190,60,150,20);
line(150,20,110,60);
setcolor(4);
line(78,105,222,105);
arc(55,115,270,25,25);
arc(245,115,155,270,25);
line(50,140,250,140);
setfillstyle(9,4);
floodfill(150,120,4);

setcolor(5);
line(80,140,80,230);
line(220,140,220,230);
line(80,230,220,230);
line(50,140,250,140);
setfillstyle(1,5);
floodfill(100,210,5);

setcolor(7);
rectangle(90,150,120,180);
setfillstyle(8,2);
floodfill(100,170,7);
rectangle(180,150,210,180);
floodfill(200,160,7);
setcolor(9);
ellipse(150,230,0,180,20,60);
line(80,230,220,230);
setfillstyle(1,9);
floodfill(150,200,9);
circle(150,200,2);
setcolor(15);
ellipse(140,60,0,360,7,12);
setfillstyle(1,15);
floodfill(140,60,15);
ellipse(160,60,0,360,7,12);
setfillstyle(1,15);
floodfill(160,60,15);

setcolor(1);
circle(140,60,4);
setfillstyle(1,1);
floodfill(140,60,1);
setcolor(1);
circle(160,60,4);
setfillstyle(1,1);
floodfill(160,60,1);

setcolor(0);
circle(140,60,2);
setfillstyle(1,0);
floodfill(140,60,0);
setcolor(0);
circle(160,60,2);
setfillstyle(1,0);
floodfill(160,60,0);

setcolor(14);
arc(150,82,180,360,14);
arc(150,85,170,10,15);
setfillstyle(9,14);
floodfill(150,98,14);

setcolor(15);
arc(199,70,200,340,20);
arc(199,80,200,340,20);
ellipse(218,85,0,360,4,8);
setfillstyle(1,15);
//floodfill(200,75,15);

line(220,80,240,50);
line(220,89,246,52);

setcolor(2);
ellipse(240,40,0,360,35,15);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(222,35,"welcome");
setfillstyle(1,5);
floodfill(240,40,2);



setbkcolor(0);
setcolor(2);
arc(535,300,90,230,20);     //tree 2
arc(555,280,25,180,20);
arc(590,280,360,144,20);
arc(535,330,132,300,20);
arc(600,298,320,68,20);
arc(600,320,260,40,25);

arc(535,375,0,90,30);
arc(595,375,90,180,30);
setfillstyle(9,2);
floodfill(568,328,2);

setcolor(6);
arc(515,380,300,60,40);
arc(615,380,110,240,40);
arc(535,375,0,90,30);
arc(595,375,90,180,30);

line(500,415,800,415);
setfillstyle(6,6);
floodfill(565,398,6);    //tree 2
//pool
setcolor(6);
{
//line(490,255,490,295);
//line(510,255,510,295);
rectangle(490,255,510,295);
}
setfillstyle(2,6);
floodfill(495,260,6);

/*setviewport(0,0,640,440,1);
for(i=30;i<100;i++)
{
delay(100);
setcolor(i/5);
arc(500,100,10,160,i+10);
}
arc(330,50,90,260,20);  //cloud
arc(350,30,25,180,20);
arc(380,40,280,144,20);
arc(342,58,210,330,20);
arc(365,50,240,0,20);
setfillstyle(1,9);
floodfill(350,44,1);  //cloud*/
setcolor(15);
arc(450,50,90,260,20);  //cloud
arc(470,30,25,180,20);
arc(500,40,280,144,20);
arc(462,58,210,330,20);
arc(485,50,240,0,20);
setfillstyle(1,15);
floodfill(475,44,15);  //cloud

//tunel
line(130,370,270,370);
line(130,440,270,440);
ellipse(130,405,0,360,10,35);
ellipse(270,405,0,360,10,35);

//void girl()

/*d=imagesize(0,0,640,480);
//f=malloc(d);
//getimage(0,0,640,480,f);  */


//void girl()
/*d=imagesize(0,0,640,480);
f=malloc(d);
getimage(0,0,640,480,f);  */
getch();

}
void scean3()
{

{
//setbkcolor(2);
//nadi
setcolor(1);
line(0,330,0,380);
line(639,190,639,300);
arc(120,470,80,150,180);
arc(120,510,80,150,180);

arc(215,124,248,302,180);
arc(215,164,248,302,180);

arc(420,420,80,130,180);
arc(420,460,80,130,180);

//arc(440,420,50,100,180);
//arc(430,460,80,130,180);
//arc(
arc(515,74,248,340,180);
arc(515,114,248,340,180);

//arc(515,114,248,271,180);
//arc(515,114,300,340,180);
setfillstyle(1,1);
floodfill(10,340,1);
//circle(10,340,1);
}


setcolor(4);
line(100,50,150,0);
line(150,0,200,50);
line(200,50,190,60);
line(190,60,150,20);
line(150,20,110,60);
line(110,60,100,50);
setfillstyle(9,4);
floodfill(150,10,4);

setcolor(14);
line(125,25,120,10);
line(115,35,110,20);
line(120,10,110,20);
setfillstyle(9,14);
//floodfill(117,26,14);
line(115,56,125,105);
line(185,56,175,105);
line(78,105,222,105);
line(190,60,150,20);
line(150,20,110,60);
setcolor(4);
line(78,105,222,105);
arc(55,115,270,25,25);
arc(245,115,155,270,25);
line(50,140,250,140);
setfillstyle(9,4);
floodfill(150,120,4);

setcolor(5);
line(80,140,80,230);
line(220,140,220,230);
line(80,230,220,230);
line(50,140,250,140);
setfillstyle(1,5);
floodfill(100,210,5);

setcolor(7);
rectangle(90,150,120,180);
setfillstyle(8,2);
floodfill(100,170,7);
rectangle(180,150,210,180);
floodfill(200,160,7);
setcolor(9);
ellipse(150,230,0,180,20,60);
line(80,230,220,230);
setfillstyle(1,9);
floodfill(150,200,9);
circle(150,200,2);
setcolor(15);
ellipse(140,60,0,360,7,12);
setfillstyle(1,15);
floodfill(140,60,15);
ellipse(160,60,0,360,7,12);
setfillstyle(1,15);
floodfill(160,60,15);

setcolor(1);
circle(140,60,4);
setfillstyle(1,1);
floodfill(140,60,1);
setcolor(1);
circle(160,60,4);
setfillstyle(1,1);
floodfill(160,60,1);

setcolor(0);
circle(140,60,2);
setfillstyle(1,0);
floodfill(140,60,0);
setcolor(0);
circle(160,60,2);
setfillstyle(1,0);
floodfill(160,60,0);

setcolor(14);
arc(150,82,180,360,14);
arc(150,85,170,10,15);
setfillstyle(9,14);
floodfill(150,98,14);

setcolor(15);
arc(199,70,200,340,20);
arc(199,80,200,340,20);
ellipse(218,85,0,360,4,8);
setfillstyle(1,15);
//floodfill(200,75,15);

line(220,80,240,50);
line(220,89,246,52);

setcolor(2);
ellipse(240,40,0,360,35,15);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(222,35,"welcome");
setfillstyle(1,5);
floodfill(240,40,2);



setbkcolor(0);
setcolor(2);
arc(535,300,90,230,20);     //tree 2
arc(555,280,25,180,20);
arc(590,280,360,144,20);
arc(535,330,132,300,20);
arc(600,298,320,68,20);
arc(600,320,260,40,25);

arc(535,375,0,90,30);
arc(595,375,90,180,30);
setfillstyle(9,2);
floodfill(568,328,2);

setcolor(6);
arc(515,380,300,60,40);
arc(615,380,110,240,40);
arc(535,375,0,90,30);
arc(595,375,90,180,30);

line(500,415,800,415);
setfillstyle(6,6);
floodfill(565,398,6);    //tree 2
//pool
setcolor(6);
{
//line(490,255,490,295);
//line(510,255,510,295);
rectangle(490,255,510,295);
}
setfillstyle(2,6);
floodfill(495,260,6);

/*setviewport(0,0,640,440,1);
for(i=30;i<100;i++)
{
delay(100);
setcolor(i/5);
arc(500,100,10,160,i+10);
}
arc(330,50,90,260,20);  //cloud
arc(350,30,25,180,20);
arc(380,40,280,144,20);
arc(342,58,210,330,20);
arc(365,50,240,0,20);
setfillstyle(1,9);
floodfill(350,44,1);  //cloud*/
setcolor(15);
arc(450,50,90,260,20);  //cloud
arc(470,30,25,180,20);
arc(500,40,280,144,20);
arc(462,58,210,330,20);
arc(485,50,240,0,20);
setfillstyle(1,15);
floodfill(475,44,15);  //cloud

//tunel
line(130,370,270,370);
line(130,440,270,440);
ellipse(130,405,0,360,10,35);
ellipse(270,405,0,360,10,35);

//void girl()

/*d=imagesize(0,0,640,480);
//f=malloc(d);
//getimage(0,0,640,480,f);  */


//void girl()
/*d=imagesize(0,0,640,480);
f=malloc(d);
getimage(0,0,640,480,f);  */
getch();
}


