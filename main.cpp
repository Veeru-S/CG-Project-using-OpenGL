#include <cstdio>
#include <GL/gl.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>
using namespace std;

int sunstatus=0,cloudstatus=1,waterstatus=1,cyclestatus=1,human2status=1,rainstatus=0,birdstatus=1,start=0;
float sunX=0,sunY=0,cloudX=0,cloudY=0,waterX=0,waterY=0,cycleX=0,cycleY=0,humanX=0,humanY=0,rainX=0,rainY=0,birdsX=0,birdsY=0;
int day=1;


//////draw circle starts//////
 void DrawCircle(float cx, float cy, float r, int num_segments)
 {

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get current angle

		float x = r * cosf(theta);//calculate x
		float y = r * sinf(theta);//calculate y

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
	glFlush();
}
//////draw circle ends//////
void movesun(int x)
{
 //////moving sun////
    if (sunstatus == 1)
    {
            sunX -= 1.5;
            sunY += 0.5;
    }
        if(sunX<=-700)
        {
            day=0;
            sunX=300;
            sunY=-100;
        }
        glutTimerFunc(100000000, movesun, 0);
        glutPostRedisplay();

}

//////moving sun ends////
///////move wave & boat////////
void movewater()
{
    if (waterstatus ==1)
    {
        waterX += 1;
    }
    if (waterX>680)
    {
        waterX = -500;
        waterY = 0;

    }
}
///////move wave & boat ends////////
////clouds//////
void clouds() {
    glColor3ub(200, 220, 220);
	DrawCircle(100, 360, 25, 1000);
	DrawCircle(130, 360, 35, 1000);
	DrawCircle(160, 360, 25, 1000);

    glColor3ub(200, 220, 220);
	DrawCircle(170, 400, 15, 2000);
	DrawCircle(200, 400, 25, 2000);
	DrawCircle(230, 400, 15, 2000);

    glColor3ub(200, 220, 220);
	DrawCircle(300, 420, 25, 2000);
	DrawCircle(330, 420, 35, 2000);
	DrawCircle(360, 420, 25, 2000);

    glColor3ub(200, 220, 220);
	DrawCircle(400, 400, 25, 2000);
	DrawCircle(430, 400, 35, 2000);
	DrawCircle(460, 400, 25, 2000);
	glFlush();
}
/////clouds/////
//////hills/////
void hills(int x,int y,int z)
{

    //glColor3ub(0, 0, 153);
    glColor3ub(x,y,z);
    glBegin(GL_TRIANGLES);
    glVertex2i(80, 255);
    glVertex2i(120, 290);
    glVertex2i(160, 255);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(80, 255);
    glVertex2i(120, 290);
    glVertex2i(120, 290);
    glVertex2i(160, 255);
    glEnd();

    //glColor3ub(0, 0, 153);
    glColor3ub(x,y,z);
    glBegin(GL_TRIANGLES);
    glVertex2i(140, 255);
    glVertex2i(170, 280);
    glVertex2i(200, 255);
    glEnd();

    //glColor3ub(0, 0, 153);
    glColor3ub(x,y,z);
    glBegin(GL_TRIANGLES);
    glVertex2i(180, 255);
    glVertex2i(270, 320);
    glVertex2i(360, 255);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(180, 255);
    glVertex2i(270, 320);

    glVertex2i(270, 320);
    glVertex2i(360, 255);
    glEnd();

    //glColor3ub(0, 0, 153);
    glColor3ub(x,y,z);
    glBegin(GL_TRIANGLES);
    glVertex2i(260, 255);
    glVertex2i(320, 300);
    glVertex2i(380, 255);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(260, 255);
    glVertex2i(320, 300);

    glVertex2i(320, 300);
    glVertex2i(380, 255);
    glEnd();

    //glColor3ub(0, 0, 153);
    glColor3ub(x,y,z);
    glBegin(GL_TRIANGLES);
    glVertex2i(370, 255);
    glVertex2i(420, 275);
    glVertex2i(470, 255);

    glEnd();
    glFlush();
}
//////////

////////move clouds///

void movecloud()
{
	if (cloudstatus == 1)
        {
            cloudX +=0.3;
        }
	if (cloudX>680)
        {
            cloudX = -500;
            cloudY =0;
        }
}
/////////this side tree/////////////
void trees()
{
    //////////////////////////////////////pata
    glColor3ub (51, 204, 51);
    DrawCircle(50, 280, 50, 2000);//1
    DrawCircle(50, 320, 35, 3000);//1
    glEnd();
    glFlush();
    ////////////////////////////////majher daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(40, 155);
    glVertex2i(60, 155);
    glVertex2i(60, 245);
    glVertex2i(40, 245);
    glEnd();
    //////////////////////////////////bam daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(40, 245);
    glVertex2i(50, 245);
    glVertex2i(40, 270);
    glVertex2i(30, 270);
    glEnd();
    /////////////////////////////////right daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(50, 245);
    glVertex2i(60, 245);
    glVertex2i(70, 270);
    glVertex2i(60, 270);
    glEnd();
    glFlush();
/////tree shadow
    glColor3ub (79, 214, 72);
    glBegin(GL_QUADS);
    glVertex2i(15, 120);
    glVertex2i(35, 120);
    glVertex2i(55, 155);
    glVertex2i(40, 155);
    glEnd();

    glColor3ub (79, 214, 72);
    DrawCircle(20,100,30,1000);
    glEnd();

}
   ////////SMALL TREE////////////////
void small_trees(int x,int y,int z)
{


    glColor3ub (x,y,z); //TREE 1
    glBegin(GL_TRIANGLES);//1
    glVertex2i(300,200);
    glVertex2i(312.5,200);
    glVertex2i(312,225);

    glBegin(GL_TRIANGLES);//2
    glVertex2i(300, 187);
    glVertex2i(312.5, 187);
    glVertex2i(312,212);

    glBegin(GL_TRIANGLES);//3
    glVertex2i(300, 175);
    glVertex2i(312.5,175);
    glVertex2i(312, 200);
    glEnd();
    //opposite side
    glColor3ub (x,y,z);
    glBegin(GL_TRIANGLES);//1
    glVertex2i(312,225);
    glVertex2i(312.5,200);
    glVertex2i(325,200);

    glBegin(GL_TRIANGLES);//2
    glVertex2i(312, 212);
    glVertex2i(312.5, 187);
    glVertex2i(325,187);

    glBegin(GL_TRIANGLES);//3
    glVertex2i(312, 200);
    glVertex2i(312.5,175);
    glVertex2i(325, 175);
    glEnd();
   ////////branch////////
    glColor3ub (139,69,19);
    glBegin(GL_QUADS);
    glVertex2i(311, 175);
    glVertex2i(311,162);
    glVertex2i(314, 162);
    glVertex2i(314,175);
    glEnd();

    glColor3ub (x,y,z); //TREE 2
    glBegin(GL_TRIANGLES);//1
    glVertex2i(275, 200);
    glVertex2i(287, 200);
    glVertex2i(287,225);

    glBegin(GL_TRIANGLES);//2
    glVertex2i(275, 187);
    glVertex2i(287, 187);
    glVertex2i(287,212);

    glBegin(GL_TRIANGLES);//3
    glVertex2i(275, 175);
    glVertex2i(287,175);
    glVertex2i(287, 200);

    glColor3ub (x,y,z);//opposite
    glBegin(GL_TRIANGLES);//1
    glVertex2i(287, 225);
    glVertex2i(287, 200);
    glVertex2i(300,200);

    glBegin(GL_TRIANGLES);//2
    glVertex2i(287, 212);
    glVertex2i(287, 187);
    glVertex2i(300,187);

    glBegin(GL_TRIANGLES);//3
    glVertex2i(287, 200);
    glVertex2i(287,175);
    glVertex2i(300, 175);
    glEnd();

    //branch
    glColor3ub (139,69,19);
    glBegin(GL_QUADS);
    glVertex2i(285, 175);
    glVertex2i(285,162);
    glVertex2i(288, 162);
    glVertex2i(288,175);
    glEnd();
}
   ////////SMALL TREE ENDS////////////////
void rocker()
{
    ////////////////////////////////////////rocker//////////////////
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);//branch
    glVertex2i(5,240);
    glVertex2i(5, 235);
    glVertex2i(50,190);
    glVertex2i(50, 205);
    glColor3ub(200, 220, 220);
	DrawCircle(5, 237.5, 3, 10);
	glEnd();

    glColor3ub (233,150,122);
    glBegin(GL_QUADS);//rocker
    glVertex2i(10,185);
    glVertex2i(5, 175);
    glVertex2i(30,175);
    glVertex2i(25, 185);
    glEnd();
    glColor3ub (0,0,0);//rope
    glBegin(GL_LINES);
    glVertex2i(8,180);
    glVertex2i(8,237);
    glBegin(GL_LINES);
    glVertex2i(28, 178);
    glVertex2i(28,222);
    glEnd();
    glColor3ub (0,0,0);
    DrawCircle(8,180, 1.2, 5);
    DrawCircle(28, 178, 1.2, 5);
    glEnd();
}
////////////////rocker ends/////////////////
////////////rivers opposite side village/////////
void oposite_village(int x,int y,int z)
{
    //////////////////////tree 1st/////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(110, 255);
    glVertex2i(110, 270);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(110, 270, 5, 5000);//1
    DrawCircle(110, 274, 3, 5000);//1
    glEnd();
    glFlush();
        //////////////////////tree 2nd////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(200, 255);
    glVertex2i(200, 270);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(200, 270, 5, 5000);//1
    DrawCircle(200, 274, 3, 5000);//1
    glEnd();
    glFlush();
    //////////////////////tree 3rd//////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(250, 255);
    glVertex2i(250, 275);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(250, 275, 5, 5000);
    DrawCircle(250, 279, 3, 6000);
    glEnd();
    glFlush();
    ///////////////////////tree 4th///////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(270, 255);
    glVertex2i(270, 275);
    glEnd();

   // glColor3ub (51, 204, 51);
   glColor3ub (x, y, z);
    DrawCircle(270, 275, 5, 5000);//1
    DrawCircle(270, 279, 3, 6000);//1
    glEnd();
    glFlush();
    ///////////////////////////tree 5th////////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(300, 255);
    glVertex2i(300, 275);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(300, 275, 5, 6000);
    DrawCircle(300, 279, 3, 6000);
    glEnd();
    glFlush();
    ///////////////////////house 1st//////
    glColor3ub (181, 158, 90);
    glBegin(GL_POLYGON);//roof
    glVertex2i(150, 260);
    glVertex2i(165, 260);
    glVertex2i(163, 265);
    glVertex2i(152, 265);
    glEnd();

    glColor3ub(153, 153, 153);
    glBegin(GL_QUADS);//body
    glVertex2i(152, 255);
    glVertex2i(163, 255);
    glVertex2i(163, 260);
    glVertex2i(152, 260);
    glEnd();
    glFlush();
    ///////////////////////////house 2nd///////
    glColor3ub (181, 158, 90);
    glBegin(GL_POLYGON);//roof
    glVertex2i(220, 260);
    glVertex2i(235, 260);
    glVertex2i(233, 265);
    glVertex2i(222, 265);
    glEnd();

    glColor3ub(153, 153, 153);
    glBegin(GL_QUADS);//body
    glVertex2i(222, 255);
    glVertex2i(233, 255);
    glVertex2i(233, 260);
    glVertex2i(222, 260);
    glEnd();
    glFlush();
}

void wave()
{
        /////wave////////////////
    glColor3ub (169, 242, 242);
    glBegin(GL_LINES);
    glVertex2i(200, 220);
    glVertex2i(220, 220);

    glVertex2i(210, 230);
    glVertex2i(220, 230);

    glVertex2i(300, 220);
    glVertex2i(320, 220);

    glVertex2i(400, 220);
    glVertex2i(420, 220);

    glVertex2i(100, 240);
    glVertex2i(120, 240);

    glVertex2i(150, 180);
    glVertex2i(150, 180);

    glVertex2i(0, 190);
    glVertex2i(10, 190);

    glVertex2i(0, 200);
    glVertex2i(10, 200);

    glVertex2i(30, 185);
    glVertex2i(40, 185);

    glVertex2i(100, 250);
    glVertex2i(125, 250);

    glVertex2i(150,240);
    glVertex2i(165,240);

    glVertex2i(90,200);
    glVertex2i(100,200);

    glVertex2i(300,190);
    glVertex2i(320,190);

    glVertex2i(270,235);
    glVertex2i(275,235);

    glVertex2i(500,200);
    glVertex2i(510,200);

    glVertex2i(600,220);
    glVertex2i(615,220);

    glVertex2i(550,200);
    glVertex2i(555,200);

    glVertex2i(520,225);
    glVertex2i(540,225);

    glVertex2i(370,215);
    glVertex2i(380,215);
    glEnd();
}
/////////////////////boat & wave/////////////////////
void boat_wave()
{
    wave();  ////just wave
    ///////////////////boat body///////////////////////
    glColor3ub (150, 129, 117);
    glBegin(GL_QUADS);
    glVertex2i(20, 220);
    glVertex2i(60, 220);
    glVertex2i(70, 230);
    glVertex2i(10, 230);
    glEnd();
    /////////////////boat ar oporer part///////////////
    glColor3ub (206, 175, 109);
    glBegin(GL_POLYGON);
    glVertex2i(27, 230);
    glVertex2i(57, 230);
    glVertex2i(57, 240);
    glVertex2i(27, 240);
    glEnd();
    //////////////pal er chera cloths///////
    glColor3ub (209, 102, 27);
    glBegin(GL_TRIANGLES);
    glVertex2i(57, 230);
    glVertex2i(90, 280);
    glVertex2i(50, 290);
    glEnd();
    /////////boat ar pal ar bamboo//////////
    glColor3ub (206, 175, 109);
    glBegin(GL_LINES);
    glVertex2i(57, 230);
    glVertex2i(73, 290);
    glEnd();
    ///////////////boat shadow////////////
    glColor3ub (149, 187, 198);
    glBegin(GL_QUADS);
    glVertex2i(15, 210);
    glVertex2i(55, 210);
    glVertex2i(60, 220);
    glVertex2i(20, 220);
    glEnd();
}
///////////////////////////water////////////
void water(int x,int y,int z)
{
    glColor3ub(x,y,z);
    glBegin(GL_QUADS);
    glVertex2i(0, 180);
    glVertex2i(640, 180);
    glVertex2i(640, 255);
    glVertex2i(0, 255);
    glEnd();
}
void line()
{
    glColor3ub (153, 153, 102);
    glBegin(GL_QUADS);
    glVertex2i(0, 50);
    glVertex2i(640, 50);
    glVertex2i(640, 60);
    glVertex2i(0, 60);
    glEnd();
}
////////land//////
void land(int x,int y,int z)
{
    glColor3ub (x,y,z);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(640, 0);
    glVertex2i(640, 180);
    glVertex2i(0, 180);
    glEnd();
}
///////land ends////////
///////tree///////////
void tree(int x,int y,int z)
{
    //////////leaf///////////
    glColor3ub(x,y,z);
    DrawCircle(65,280,50,2000);
    DrawCircle(40,280,50,2000);
    DrawCircle(50,320,50,2000);
    //////////leaf ends///////////
    glColor3ub (180, 180, 40);////main guri
    glBegin(GL_QUADS);
    glVertex2i(40, 155);
    glVertex2i(60, 155);
    glVertex2i(60, 245);
    glVertex2i(40, 245);
    glEnd();
    ////////left///////////////////////////
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(40, 245);
    glVertex2i(50, 245);
    glVertex2i(40, 270);
    glVertex2i(30, 270);
    glEnd();
    ///////right /////////
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(50, 245);
    glVertex2i(60, 245);
    glVertex2i(70, 270);
    glVertex2i(60, 270);
    glEnd();
    glFlush();
}
////////tree ends/////

////////road////////////
void road(int x,int y,int z)
{
    glColor3ub (x,y,z);
    glBegin(GL_POLYGON);
    glVertex2i(0, 60);
    glVertex2i(640, 100);
    glVertex2i(640, 175);
    glVertex2i(0, 100);
    glEnd();

    //grass flower1
    glColor3ub (0,100,0);
    glBegin(GL_LINES);
    glVertex2i(525,100);//middle
    glVertex2i(525,107);
    glVertex2i(525,100);//left
    glVertex2i(530,105);
    glVertex2i(525,100);//right
    glVertex2i(520,105);
    glVertex2i(525,100);//ground left
    glVertex2i(520,101);
    glVertex2i(525,100);//ground right
    glVertex2i(530,101);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(525,107,1,5);
    DrawCircle(530,105,1,5);
    DrawCircle(520,105,1,5);
    glEnd();
    //grass flower2
    glColor3ub (0,100,0);
    glBegin(GL_LINES);
    glVertex2i(600,150);//middle
    glVertex2i(600,157);
    glVertex2i(600,150);//left
    glVertex2i(595,155);
    glVertex2i(600,150);//right
    glVertex2i(605,155);
    glVertex2i(600,150);//ground left
    glVertex2i(595,151);
    glVertex2i(600,150);//ground right
    glVertex2i(605,151);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(600,157,1,5);
    DrawCircle(595,155,1,5);
    DrawCircle(605,155,1,5);
    glEnd();
     //grass flower3
    glColor3ub (0,100,0);
    glBegin(GL_LINES);
    glVertex2i(225,100);//middle
    glVertex2i(225,107);
    glVertex2i(225,100);//left
    glVertex2i(220,105);
    glVertex2i(225,100);//right
    glVertex2i(230,105);
    glVertex2i(225,100);//ground left
    glVertex2i(220,101);
    glVertex2i(225,100);//ground right
    glVertex2i(230,101);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(225,107,1,5);
    DrawCircle(220,105,1,5);
    DrawCircle(230,105,1,5);
    glEnd();
    //grass flower4
    glColor3ub (0,100,0);
    glBegin(GL_LINES);
    glVertex2i(375,100);//middle
    glVertex2i(375,107);
    glVertex2i(375,100);//left
    glVertex2i(370,105);
    glVertex2i(375,100);//right
    glVertex2i(380,105);
    glVertex2i(375,100);//ground left
    glVertex2i(370,101);
    glVertex2i(375,100);//ground right
    glVertex2i(380,101);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(375,107,1,5);
    DrawCircle(370,105,1,5);
    DrawCircle(380,105,1,5);
    glEnd();
    //grass flower5
    glColor3ub (0,100,0);
    glBegin(GL_LINES);
    glVertex2i(50,75);//middle
    glVertex2i(50,82);
    glVertex2i(50,75);//left
    glVertex2i(45,80);
    glVertex2i(50,75);//right
    glVertex2i(55,80);
    glVertex2i(50,75);//ground left
    glVertex2i(45,76);
    glVertex2i(50,75);//ground right
    glVertex2i(55,76);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(50,82,1,5);
    DrawCircle(45,80,1,5);
    DrawCircle(55,80,1,5);
    glEnd();
}

////////road ends////////
//////////mosque starts///////////
void mosque(int x,int y,int z)
{
    glColor3ub (x,y,z);
    glBegin(GL_POLYGON);
    glVertex2i(475, 275);
    glVertex2i(475, 258);
    glVertex2i(512, 258);
    glVertex2i(512, 275);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(500,315);
    glVertex2i(500, 275);
    glVertex2i(512, 275);
    glVertex2i(512, 315);
    glEnd();
    DrawCircle(506, 320, 7, 20);
    glBegin(GL_LINES);
    glVertex2i(506,327);
    glVertex2i(506, 335);
    glEnd();
    DrawCircle(487, 278, 10, 30);
    glBegin(GL_LINES);
    glVertex2i(487,288);
    glVertex2i(487,295);
    glEnd();

}
/////////mosque ends//////////////
/////////flower starts///////////
void flower()
{
     //flower 1
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch
    glVertex2i(24,45);
    glVertex2i(24,0);
    glVertex2i(26,0);
    glVertex2i(26,45);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(25,45, 4, 15);
    glColor3ub (255,255,0);
    DrawCircle(26,49, 4.5, 15);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(25,30);
    glVertex2i(25,25);
    glVertex2i(30,33);
    glBegin(GL_TRIANGLES);//leaf2
    glVertex2i(25,20);
    glVertex2i(20,30);
    glVertex2i(25,15);
    glEnd();
    //flower 2
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch
    glVertex2i(47,46);
    glVertex2i(47,0);
    glVertex2i(49,0);
    glVertex2i(49,46);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(48,49, 4, 15);
    glColor3ub (255,255,0);
    DrawCircle(52,50, 3., 10);
    DrawCircle(50,52, 3., 10);
    DrawCircle(48,50, 3., 10);
    DrawCircle(45,51, 3., 10);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(42,40);
    glVertex2i(47,25);
    glVertex2i(47,30);
    glEnd();
    //flower 3
    glColor3ub (0,100,0);
    glBegin(GL_QUADS);//branch main
    glVertex2i(82,48);
    glVertex2i(82,0);
    glVertex2i(85,0);
    glVertex2i(85,48);
    glEnd();
    glColor3ub (139,69,19);//petals
    DrawCircle(83,48, 5, 15);
    glEnd();
    glColor3ub (255,255,0);//petals
    DrawCircle(83,53, 3, 5);
    DrawCircle(80,50, 3, 5);
    glEnd();
    glColor3ub (0,100,0);
    glBegin(GL_TRIANGLES);//leaf1
    glVertex2i(83,35);
    glVertex2i(83,30);
    glVertex2i(90,45);
    glEnd();

}
//////////flower ends////////////////
//////////home 1 starts/////////////
void home1(int x,int y,int z,int m,int n,int o)
{
    //home 1
    glColor3ub (72,61,139);
    glBegin(GL_POLYGON);
    glVertex2i(95, 195);
    glVertex2i(170, 195);
    glVertex2i(225, 250);
    glVertex2i(150, 250);
    glEnd();

    glColor3ub (72,61,139);
    glBegin(GL_LINES);
    glVertex2i(225, 250);
    glVertex2i(280, 200);
    glEnd();

    glColor3ub (m,n,o);
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(100, 150);
    glVertex2i(175, 150);
    glVertex2i(175, 200);
    glEnd();

    glColor3ub (x,y,z);
    glBegin(GL_POLYGON);
    glVertex2i(175, 200);
    glVertex2i(175, 150);
    glVertex2i(275, 150);
    glVertex2i(275, 200);
    glVertex2i(280, 200);
    glVertex2i(225, 250);
    glEnd();

    // door
    glColor3ub (72,61,139);
    glBegin(GL_POLYGON);
    glVertex2i(125, 185);
    glVertex2i(125, 150);
    glVertex2i(150, 150);
    glVertex2i(150, 185);
    glEnd();

    //window
    glColor3ub (72,61,139);
    glBegin(GL_POLYGON);
    glVertex2i(212, 200);
    glVertex2i(212, 175);
    glVertex2i(237, 175);
    glVertex2i(237, 200);
    glEnd();

    glColor3ub (216,191,216);
    glBegin(GL_LINES);
    glVertex2i(225, 200);
    glVertex2i(225, 175);

    glVertex2i(212, 187);
    glVertex2i(237, 187);
    glEnd();

    //pipe

    glColor3ub (72,61,139);
    glBegin(GL_QUADS);
    glVertex2i(250, 250);
    glVertex2i(250, 225);
    glVertex2i(255,220);
    glVertex2i(255, 250);
    glEnd();

    //smoke

    glColor3ub (70,70,70);
    glBegin(GL_POLYGON);
    glVertex2i(252, 250);//1
    glVertex2i(250,255);
    glVertex2i(253,260);
    glVertex2i(256,258);
    glVertex2i(253,256);
    glVertex2i(254,250);
    glEnd();
     ///////////////fence starts/////////////

    // fence 1
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//1
    glVertex2i(15,45);
    glVertex2i(10,40);
    glVertex2i(10,0);
    glVertex2i(15,0);
    glVertex2i(15,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//1
    glVertex2i(15,45);
    glVertex2i(15,0);
    glVertex2i(20,0);
    glVertex2i(20,40);
    glVertex2i(15,45);
    glEnd();
    // fence 2
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//2
    glVertex2i(35,45);
    glVertex2i(30,40);
    glVertex2i(30,0);
    glVertex2i(35,0);
    glVertex2i(35,40);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//2
    glVertex2i(35,45);
    glVertex2i(35,0);
    glVertex2i(40,0);
    glVertex2i(40,40);
    glVertex2i(35,45);
    glEnd();
    // fence 3
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//3
    glVertex2i(55,45);
    glVertex2i(50,40);
    glVertex2i(50,0);
    glVertex2i(55,0);
    glVertex2i(55,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//3
    glVertex2i(55,45);
    glVertex2i(55,0);
    glVertex2i(60,0);
    glVertex2i(60,40);
    glVertex2i(55,45);
    glEnd();
    // fence 4
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//4
    glVertex2i(75,45);
    glVertex2i(70,40);
    glVertex2i(70,0);
    glVertex2i(75,0);
    glVertex2i(75,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//4
    glVertex2i(75,45);
    glVertex2i(75,0);
    glVertex2i(80,0);
    glVertex2i(80,40);
    glVertex2i(75,45);
    glEnd();
    // fence 5
    glColor3ub (184,134,11);
    glBegin(GL_POLYGON);//5
    glVertex2i(95,45);
    glVertex2i(90,40);
    glVertex2i(90,0);
    glVertex2i(95,0);
    glVertex2i(95,45);
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//5
    glVertex2i(95,45);
    glVertex2i(95,0);
    glVertex2i(100,0);
    glVertex2i(100,40);
    glVertex2i(95,45);
    glEnd();
    glColor3ub (218,165,32);
    glBegin(GL_POLYGON);//start
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,40);
    glVertex2i(0,45);
    glEnd();
    glColor3ub (184,134,11);
    glBegin(GL_QUADS);//--
    glVertex2i(0,20);
    glVertex2i(0,15);
    glVertex2i(90,15);
    glVertex2i(90,20);
    glEnd();
    ///////////////FENCE ends/////////////
}
/////////home 1 ends////////////////
    ////////TREE BESIDE HOUS2///////
void beside_house_tree(int x,int y,int z)
{
    glColor3ub (139,69,19);
    glBegin(GL_QUADS);// tree body
    glVertex2i(475,15);
    glVertex2i(478,15);
    glVertex2i(478,70);
    glVertex2i(475,70);
    glBegin(GL_QUADS);// branch left1
    glVertex2i(475,25);
    glVertex2i(475,28);
    glVertex2i(462,37);
    glVertex2i(462,34);
    glBegin(GL_QUADS);// branch right1
    glVertex2i(475,25);
    glVertex2i(475,28);
    glVertex2i(487,37);
    glVertex2i(487,34);
    glBegin(GL_QUADS);// branch left2
    glVertex2i(475,50);
    glVertex2i(475,53);
    glVertex2i(462,62);
    glVertex2i(462,59);
    glBegin(GL_QUADS);// branch right2
    glVertex2i(475,50);
    glVertex2i(475,53);
    glVertex2i(487,62);
    glVertex2i(487,59);
    glEnd();
    glColor3ub(x,y,z);
	DrawCircle(475, 70, 6, 20);// main body
	DrawCircle(462,35, 7, 20); //branch left1
	DrawCircle(487,35, 8, 20);//branch right1
	DrawCircle(462,61, 7.5, 20);//branch left2
	DrawCircle(487,61, 6, 20); //branch right2
	glEnd();
}
    ////////TREE BESIDE HOUSE2 ends///////
    ////////home 2 starts ///////////////
    void home2(int x,int y,int z,int m,int n,int o)
    {
    glColor3ub (x,y,z);
    glBegin(GL_QUADS);//main home
    glVertex2i(540,90);
    glVertex2i(500,50);
    glVertex2i(600,50);
    glVertex2i(625,90);
    glColor3ub (x,y,z);//little home1
    glBegin(GL_QUADS);
    glVertex2i(537,75);
    glVertex2i(550,48);
    glVertex2i(575,48);
    glVertex2i(562,75);
    glBegin(GL_QUADS);// little home2
    glVertex2i(537,75);
    glVertex2i(515,48);
    glVertex2i(518,48);
    glVertex2i(537,72);
    glEnd();
    glColor3ub (m,n,o);
    glBegin(GL_QUADS);// little home3
    glVertex2i(550,48);
    glVertex2i(550,15);
    glVertex2i(575,15);
    glVertex2i(575,48);
    glColor3ub (m,n,o);
    glBegin(GL_QUADS);// little home4
    glVertex2i(575,50);
    glVertex2i(575,15);
    glVertex2i(600,15);
    glVertex2i(600,50);
    glEnd();
    glColor3ub (m,n,o);
    glBegin(GL_POLYGON);// little home5
    glVertex2i(625,90);
    glVertex2i(600,50);
    glVertex2i(600,15);
    glVertex2i(650,15);
    glVertex2i(650,50);
    glVertex2i(625,90);
    glEnd();
    glColor3ub (160,82,45);//circle window
    DrawCircle(625,50, 8, 15);
    glColor3ub (222,184,135);//circle window
    DrawCircle(625,50, 7, 15);
    glEnd();
    glColor3ub (m,n,o);
    glBegin(GL_POLYGON);// little home6
    glVertex2i(537,72);
    glVertex2i(518,48);
    glVertex2i(518,15);
    glVertex2i(550,15);
    glVertex2i(550,48);
    glEnd();
    glColor3ub (m,n,o);
    glBegin(GL_QUADS);// little home6
    glVertex2i(505,50);
    glVertex2i(505,15);
    glVertex2i(518,15);
    glVertex2i(518,50);
    glEnd();
    glColor3ub (x,y,z);
    glBegin(GL_QUADS);// little home door
    glVertex2i(580,40);
    glVertex2i(580,15);
    glVertex2i(595,15);
    glVertex2i(595,40);
    glEnd();
    glColor3ub (160,82,45);//window
    DrawCircle(535,45, 9, 15);
    glColor3ub (245,222,179);
    DrawCircle(535,45, 8, 15);
    glEnd();

    glColor3ub (139,69,19);
    glBegin(GL_QUADS);// little home pipe
    glVertex2i(600,100);
    glVertex2i(600,90);
    glVertex2i(608,90);
    glVertex2i(608,100);
    glEnd();
    }
    /////////home 2 ends////////////////
    /////////move cycle////////////////
    void move_cycle(int x)
    {
        if(cyclestatus==1)
        {
            if(cycleX >640.0f)
            {
                cycleX = -700.0f;
                cycleY=-15.0f;
            }
            cycleX += 0.8f;
            glutPostRedisplay();
            glutTimerFunc(100000, move_cycle, 0);
        }
    }
     /////////move cycle////////////////
    ///////////cycle starts////////////
    void cycle()
{
    glColor3ub (25,25,112);
    glBegin(GL_LINES);
    glVertex2i(400, 125);
    glVertex2i(425,125);
    glBegin(GL_LINES);
    glVertex2i(412, 137);
    glVertex2i(439,137);
    glBegin(GL_LINES);
    glVertex2i(425, 125);
    glVertex2i(439,137);
    glBegin(GL_LINES);
    glVertex2i(400, 125);
    glVertex2i(412,137);
    glBegin(GL_LINES);//seat
    glVertex2i(412, 137);
    glVertex2i(407,145);
    glBegin(GL_LINES);
    glVertex2i(412, 145);
    glVertex2i(400,145);
    glVertex2i(447,125);//handle
    glVertex2i(425,160);
    glVertex2i(425, 159);//handle
    glVertex2i(418,159);
    glEnd();
    ///////////paddle////////////////////
    glColor3ub(10,10,10);
	DrawCircle(420, 125, 3, 10);

	glBegin(GL_LINES);
    glVertex2i(420, 125);
    glVertex2i(423,130);
    glBegin(GL_LINES);
    glVertex2i(420, 125);
    glVertex2i(415,120);
    glEnd();

    //whiles
    glColor3ub(105,105,105);
	DrawCircle(400, 125, 10, 20);
	DrawCircle(450, 125, 10, 20);
    glEnd();

/////////////////////////////////////HUMAN 1 ///////////////////////

   glColor3ub(160,82,45);
   glBegin(GL_TRIANGLES);//body
   glVertex2i(400,145);
   glVertex2i(410, 145);
   glVertex2i(400,160);
   glEnd();
   glColor3ub(0,0,0);//head
   DrawCircle(400, 158, 4, 10);
   glEnd();
   glColor3ub (0,0,0);//hand 1
   //glPointSize(4);
   glBegin(GL_LINES);
   glVertex2i(404, 152);
   glVertex2i(422,160);
   glVertex2i(405,150);// hand 2
   glVertex2i(422,160);
   glEnd();

   glColor3ub (205,133,63);//leg
   glBegin(GL_QUADS);
   glVertex2i(407,145);
   glVertex2i(418, 130);
   glVertex2i(423,130);
   glVertex2i(409,145);
   glEnd();
}
    ///////////cycle ends///////////////
//////////////human 2//////////////////
    /////////move human 2////////////////
    void move_human2(int x)
    {
        if(human2status==1)
        {
            if(humanX >640.0f)
            {
                humanX = -700.0f;
            }
            humanX += 0.5f;
            humanY +=0.5f;
            glutPostRedisplay();
            glutTimerFunc(100000, move_human2, 0);
        }
    }
     /////////move human 2////////////////
void human2()
{
   glColor3ub (0,139,139);//body down
   glBegin(GL_QUADS);
   glVertex2i(120,75);
   glVertex2i(130,75);
   glVertex2i(130,88);
   glVertex2i(120,88);
   glColor3ub (218,165,32);//body up
   glBegin(GL_QUADS);
   glVertex2i(122,100);
   glVertex2i(119.5,88);
   glVertex2i(131,88);
   glVertex2i(128,100);
   glEnd();
   glColor3ub(0,0,0);//head
   DrawCircle(125, 103, 3, 10);
   glEnd();
   glBegin(GL_LINES); //stick
   glVertex2i(110,98);
   glVertex2i(140,98);
   glEnd();
   glBegin(GL_LINES);//left rope
   glVertex2i(112,99.5);
   glVertex2i(112,90);
   glEnd();
   glColor3ub(128,0,0);
   DrawCircle(112, 90, 3, 10);//left bone
   glEnd();
   glBegin(GL_LINES);//right rope
   glVertex2i(139,99.5);
   glVertex2i(139,90);
   glEnd();
   glColor3ub(128,0,0);
   DrawCircle(139, 90, 3, 10);//right bone
   glEnd();
   glBegin(GL_LINES);// left hand
   glVertex2i(112,99.5);
   glVertex2i(110,95);
   glEnd();
   glColor3ub(0,0,0);
   glBegin(GL_LINES);// left hand
   glVertex2i(123,98);
   glVertex2i(118,94);
   glBegin(GL_LINES);// left hand
   glVertex2i(118,94);
   glVertex2i(115,98);
   glEnd();
   glBegin(GL_LINES);// right hand
   glVertex2i(127,98);
   glVertex2i(132,94);
   glBegin(GL_LINES);// right hand
   glVertex2i(132,94);
   glVertex2i(135,98);
   glEnd();
   glBegin(GL_LINES);// left leg
   glVertex2i(122,75);
   glVertex2i(122,73);
   glBegin(GL_LINES);// right leg
   glVertex2i(128,75);
   glVertex2i(128,73);
   glEnd();
}
//////////////human 2 ends/////////////
void Rain(int x)
{

if(rainstatus==1){

    rainY += 0.000000000001f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();

    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();
}
}
/////////////rain ends////////////////
/////////////birds starts////////////
void birds()
{
    ///bird 1
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(70,385);
    glVertex2f(74,395);
    glVertex2f(80,390);
    glVertex2f(84,399);
    glVertex2f(84,389);
    glVertex2f(88,395);
    glVertex2f(84,387);
    glVertex2f(90,387);
    glVertex2f(86,383);
    glVertex2f(80,382);
    glEnd();

    ///bird 2
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(40,385);
    glVertex2f(44,395);
    glVertex2f(50,390);
    glVertex2f(54,399);
    glVertex2f(54,389);
    glVertex2f(58,395);
    glVertex2f(44,387);
    glVertex2f(60,387);
    glVertex2f(46,383);
    glVertex2f(50,382);
    glEnd();

    ///bird 3
        glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(50,365);
    glVertex2f(54,375);
    glVertex2f(60,370);
    glVertex2f(64,379);
    glVertex2f(64,369);
    glVertex2f(68,375);
    glVertex2f(54,367);
    glVertex2f(70,367);
    glVertex2f(56,363);
    glVertex2f(60,362);
    glEnd();


}
////////move birds////////
void move_birds(int x)
{
    if(birdstatus==1)
        {
            if(birdsX <-100.0f)
            {
                birdsX = 700.0f;
            }
            birdsX -= 0.5f;
            glutPostRedisplay();
            glutTimerFunc(100000, move_birds, 0);
        }
}
/////////////birds ends/////////////
void day_night()
{
    if(day==1)
    {
        /////draw sky starts///
            glColor3ub (90, 196, 242);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(640, 255);
            glVertex2i(640, 480);
            glVertex2i(0, 480);
            glEnd();
            glFlush();
        /////draw sky ends///
          /////draw sun/////

            glPushMatrix();
            glTranslatef(sunX, sunY, 0);
            glColor3ub (225,201,34);
            DrawCircle(550, 275, 40, 1000);
            glEnd();
            glFlush();
            glPopMatrix();
        /////draw sun ends////
             movesun(1);
             ////clouds/////
            glPushMatrix();
            glTranslatef(cloudX, cloudY, 0);
            clouds();
            glEnd();
            glFlush();
            glPopMatrix();
            movecloud();
             ////clouds////
             /////opposite grass////
            glColor3ub (46, 148, 49);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(520, 255);
            glVertex2i(520, 258);
            glVertex2i(0, 258);
            glEnd();
            ////draw ends//////////
            hills(208,176,45);
            oposite_village(51, 204, 51);
            mosque(47,79,79);
            water(142, 227, 227);
            /////moving wave & boat//////
            glPushMatrix();
            glTranslatef(waterX, waterY, 0);
            boat_wave();
            glPopMatrix();
            glEnd();
            glFlush();
            movewater();
            /////moving wave & boat ends//////
            land(31, 242, 7);
            tree(58,95,11);
            road(240,230,140);
            flower();
            home1(216,191,216,255, 230, 250);
            rocker();
            small_trees(0,128,0);
            beside_house_tree(0,128,0);
                        /////move human2///////////
            glPushMatrix();
            glTranslatef(humanX,0.0f,0.0f);
            human2();
            glPopMatrix();
            glEnd();
            glFlush();
            move_human2(1);
            /////move human 2 ends//////
            home2(160,82,45,244,164,96);
            /////move cycle starts///////
            glPushMatrix();
            glTranslatef(cycleX,cycleY,0.0f);
            cycle();
            glPopMatrix();
            glEnd();
            glFlush();
            move_cycle(1);
            /////move cycle ends///////
            /////rain starts////////////
            glPushMatrix();
            glTranslatef(0.0f,rainY,0.0f);
            Rain(1);
            glPopMatrix();
            glEnd();
            glFlush();
            ///////rain ends////////////
            ///////move birds starts///////
            glPushMatrix();
            glTranslatef(birdsX,0.0f,0.0f);
            birds();
            glPopMatrix();
            glEnd();
            glFlush();
            move_birds(1);
            ///////move birds end/////////



    }
    else
    {
        /////draw sky ////////
            glColor3ub (0, 0, 0);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(640, 255);
            glVertex2i(640, 480);
            glVertex2i(0, 480);
            glEnd();
        /////draw sky ends///
         /////draw moon/////
            glPushMatrix();
            glTranslatef(sunX, sunY, 0);
            glColor3ub (255,255,255);
            DrawCircle(550, 275, 40, 1000);
            glEnd();
            glFlush();
            glPopMatrix();
        /////draw moon ends////
            movesun(1);//moving moon
            //star 1
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(15,408);
            glVertex2i(10,400);
            glVertex2i(20,400);
            glVertex2i(15,397);
            glVertex2i(10,405);
            glVertex2i(20,405);
            glEnd();
             //star 2
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(35,450);
            glVertex2i(30,442);
            glVertex2i(40,442);
            glVertex2i(35,439);
            glVertex2i(30,447);
            glVertex2i(40,447);
            glEnd();
            //star 3
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(75,311);
            glVertex2i(70,303);
            glVertex2i(80,303);
            glVertex2i(75,300);
            glVertex2i(70,308);
            glVertex2i(80,308);
            glEnd();
            //star 3
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(155,350);
            glVertex2i(150,342);
            glVertex2i(160,342);
            glVertex2i(155,339);
            glVertex2i(150,347);
            glVertex2i(160,347);
            glEnd();

            //star 4
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(205,508);
            glVertex2i(200,500);
            glVertex2i(210,500);
            glVertex2i(205,497);
            glVertex2i(200,505);
            glVertex2i(210,505);
            glEnd();

            //star 5
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(315,388);
            glVertex2i(310,380);
            glVertex2i(320,380);
            glVertex2i(315,377);
            glVertex2i(310,385);
            glVertex2i(320,385);
            glEnd();
            //star6
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(375,515);
            glVertex2i(370,507);
            glVertex2i(380,507);
            glVertex2i(375,504);
            glVertex2i(370,512);
            glVertex2i(380,512);
            glEnd();
            //star7
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(415,398);
            glVertex2i(410,390);
            glVertex2i(420,390);
            glVertex2i(415,387);
            glVertex2i(410,395);
            glVertex2i(420,395);
            glEnd();

             //star8
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(475,350);
            glVertex2i(470,342);
            glVertex2i(480,342);
            glVertex2i(475,339);
            glVertex2i(470,347);
            glVertex2i(480,347);
            glEnd();

            //star9
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(525,450);
            glVertex2i(520,442);
            glVertex2i(530,442);
            glVertex2i(525,439);
            glVertex2i(520,447);
            glVertex2i(530,447);
            glEnd();
            //star10
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(575,398);
            glVertex2i(570,390);
            glVertex2i(580,390);
            glVertex2i(575,387);
            glVertex2i(570,395);
            glVertex2i(580,395);
            glEnd();
            glColor3f(128,128,128);
            /////opposite grass////
            glColor3ub (128,128,128);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(520, 255);
            glVertex2i(520, 258);
            glVertex2i(0, 258);
            glEnd();
            ////draw ends//////////
            hills(0,0,153);
            oposite_village(128,128,128);
            water(0,0,39.9);
            /////moving wave & boat//////
            glPushMatrix();
            glTranslatef(waterX, waterY, 0);
            wave();
            glPopMatrix();
            glEnd();
            glFlush();
            movewater();
            /////moving wave & boat ends//////
            land(85,107,47);
            tree(85,107,47);
            road(112,128,144);
            mosque(112,128,144);
            //flower();
            home1(169,169,169,169,169,169);
            rocker();
            small_trees(85,107,47);
            beside_house_tree(112,128,144);
            home2(105,105,105,119,136,153);
            /////rain starts////////////
            glPushMatrix();
            glTranslatef(0.0f,rainY,0.0f);
            Rain(1);
            glPopMatrix();
            glEnd();
            glFlush();
            ///////rain ends////////////

    }
}

////////////////////////////////////////display village function starts////////////////////////////////////////////////////////////////
void displayvillage(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    day_night();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}
////////////////////////////////////////display village function ends////////////////////////////////////////////////////////////////

void myInit (void)
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
/////////////////////////////////////////keyboard function starts////////////////////////////////////////////////////////////////
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'S':
        case 's':
            sunstatus=1;
            break;
        case 'A':
        case 'a':
            sunstatus=0;
            break;
        case 'N':
        case 'n':
            day=0;
            break;
        case 'D':
        case 'd':
            day=1;
            break;
        case 'C':
        case 'c':
            cloudstatus=1;
            break;
        case 'X':
        case 'x':
            cloudstatus=0;
            break;
        case 'W':
        case 'w':
            waterstatus=1;
            break;
        case 'Q':
        case 'q':
            waterstatus=0;
            break;
        case 'O':
        case 'o':
            cyclestatus=1;
            break;
        case 'P':
        case 'p':
            cyclestatus=0;
            break;
        case 'H':
        case 'h':
            human2status=1;
            break;
        case 'G':
        case 'g':
            human2status=0;
            break;
        case 'K':
        case 'k':
            rainstatus=1;
            break;
        case 'L':
        case 'l':
            rainstatus=0;
            break;
        case 'B':
        case 'b':
            birdstatus=1;
            break;
        case 'V':
        case 'v':
            birdstatus=0;
            break;
    }

}
/////////////////////////////////////////keyboard function ends////////////////////////////////////////////////////////////////



int main(int argc, char** argv)
{
    ///console display///
    cout << endl << "*********** Rural Village Scenario*************" << endl << endl;

    cout << "Press D : For Day Mode" << endl;
    cout << "Press N : For Night Mode" << endl<< endl;
    cout << "Press B : To Fly Birds" << endl;
    cout << "Press V : Stop Flying Birds " << endl<< endl;
    cout << "Press S : For Start Sun or Moon" << endl;
    cout << "Press A : For Stop Sun or Moon" << endl<< endl;
    cout << "Press C : For Flying Clouds " << endl;
    cout << "Press X : For Stop Clouds " << endl << endl;

    cout << "Press W : For Water Flow " << endl;
    cout << "Press Q : For Stop Water Flow " << endl << endl;
    cout << "Press O : To Running Cycle " << endl;
    cout << "Press P : To Stop Cycle " << endl << endl;
    cout << "Press H : To Walk the man " << endl;
    cout << "Press G : To stop the man "<< endl << endl;
    cout << "Press K : For Start Rain " << endl;
    cout << "Press L : For Stop Rain " << endl << endl;


    ///console display///

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Rural Village Scenario");
    glutPostRedisplay();
    glutDisplayFunc(displayvillage); //called display village() function
    glutKeyboardFunc(keyboard); //called keyboard() function
    myInit ();
    glutMainLoop();
    return 0;
}
