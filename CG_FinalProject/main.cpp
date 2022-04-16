#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>



float CloudX = 0;
float CloudY = 0;

float CarX_R = 0;
float CarY_R = 0;

float CarX_L = 0;
float CarY_L = 0;

float sunX = 0;
float sunY = 0;

float moonX = 0;
float moonY = 0;
float rain = 0.0;


bool isDay = true;
bool makeItNight = false;
bool makeItDay = false;
bool sunSitThere = false;
bool moonSitThere = false;
bool rainday = false;
bool isRedlight = false;

void wheel(int x, int y, int outer, int inner);

void DrawCircle(float cx, float cy, float r, int num_segments)
{

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void text(int x, int y, char *string)
{
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
    }
}
void Rain(int value)
{

    if (rainday)
    {

        rain += 0.01f;

        glBegin(GL_POINTS);
        for (int i = 1; i <= 10000; i++)
        {
            int x = rand(), y = rand();
            x %= 2000;
            y %= 2000;
            glBegin(GL_LINES);
            glColor3f(0.0, 1.0, 1.0);
            glVertex2d(x, y);
            glVertex2d(x + 5, y + 5);
            glEnd();
        }
    }
}
void Daysky()
{

    glColor3ub(135, 206, 235);
    glBegin(GL_QUADS);
    glVertex2i(0, 600);
    glVertex2i(0, 145);
    glVertex2i(1200, 145);
    glVertex2i(1200, 600);
    glEnd();
}
void EveningSky()
{

    glColor3ub(255, 137, 54);
    glBegin(GL_QUADS);
    glVertex2i(0, 145);
    glVertex2i(1200, 145);
    glColor3ub(219, 223, 226);
    glVertex2i(1200, 600);
    glVertex2i(0, 600);
    glEnd();
}
void Nightsky()
{

    glColor3ub(0, 127, 179);
    glBegin(GL_QUADS);
    glVertex2i(0, 600);
    glVertex2i(0, 145);
    glVertex2i(1200, 145);
    glVertex2i(1200, 600);
    glEnd();
}
void sun()
{
    glPushMatrix();
    glTranslated(0, -300, 0);
    glColor3ub(253, 184, 19);
    DrawCircle(805, 546, 50, 2000);
    glPopMatrix();
}
void moon()
{
    glPushMatrix();
    glTranslated(0, -200, 0);
    glColor3ub(251, 163, 31);
    DrawCircle(972, 402, 30, 2000);
    glColor3ub(0, 127, 179);
    DrawCircle(960, 405, 30, 2000);
    glPopMatrix();
}
void coverTheSun()
{
    glColor3ub(135, 206, 235);
    glBegin(GL_QUADS);
    glVertex2i(730, 590);
    glVertex2i(730, 130);
    glVertex2i(860, 130);
    glVertex2i(860, 590);
    glEnd();
}
void coverThemoon()
{
    glColor3ub(0, 127, 179);
    glBegin(GL_QUADS);
    glVertex2i(710, 530);
    glVertex2i(710, 130);
    glVertex2i(1010, 130);
    glVertex2i(1010, 530);
    glEnd();
}
struct cloud
{
    void drawDayCloud()
    {
        glColor3f(1.0, 1.0, 1.0);
        DrawCircle(246, 486, 23, 2000);
        DrawCircle(290, 509, 40, 2000);
        DrawCircle(350, 494, 36, 2000);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex2i(246, 480);
        glVertex2i(246, 463);
        glVertex2i(350, 459);
        glVertex2i(350, 480);
        glEnd();
    }
    void drawNightCloud()
    {
        glColor3ub(36, 138, 197);
        DrawCircle(246, 486, 23, 2000);
        DrawCircle(290, 509, 40, 2000);
        DrawCircle(350, 494, 36, 2000);
        glColor3ub(36, 138, 197);
        glBegin(GL_QUADS);
        glVertex2i(246, 480);
        glVertex2i(246, 463);
        glVertex2i(350, 459);
        glVertex2i(350, 480);
        glEnd();
    }
};



struct LampPost
{
    void drawdayLampPost()
    {
        glColor3ub(49,46,55);
        glBegin(GL_TRIANGLES);
        glVertex2i(204,120);
        glVertex2i(215,120);
        glVertex2i(210,135);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_QUADS);
        glVertex2i(208,129);
        glVertex2i(212,129);
        glVertex2i(212,200);
        glVertex2i(208,200);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_TRIANGLES);
        glVertex2i(210,195);
        glVertex2i(215,205);
        glVertex2i(205,205);
        glEnd();

        glColor3ub(241,237,216);
        glBegin(GL_QUADS);
        glVertex2i(204,204);
        glVertex2i(215,204);
        glVertex2i(215,213);
        glVertex2i(204,213);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_QUADS);
        glVertex2i(208,214);
        glVertex2i(212,214);
        glVertex2i(212,222);
        glVertex2i(208,222);
        glEnd();

        glColor3ub(49,46,55);
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(204,215);
        glVertex2i(215,215);
        glVertex2i(204,120);
        glVertex2i(215,120);
        glVertex2i(208,204);
        glVertex2i(212,204);
        glEnd();
    }
    void drawnightLampPost()
    {
        glColor3ub(103,154,169);
        glBegin(GL_TRIANGLES);
        glVertex2i(204,120);
        glVertex2i(215,120);
        glVertex2i(210,135);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_QUADS);
        glVertex2i(208,129);
        glVertex2i(212,129);
        glVertex2i(212,200);
        glVertex2i(208,200);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_TRIANGLES);
        glVertex2i(210,195);
        glVertex2i(215,205);
        glVertex2i(205,205);
        glEnd();

        glColor3ub(255,207,88);
        glBegin(GL_QUADS);
        glVertex2i(204,204);
        glVertex2i(215,204);
        glVertex2i(215,213);
        glVertex2i(204,213);
        glEnd();

        glColor3ub(49,46,55);
        glBegin(GL_QUADS);
        glVertex2i(208,214);
        glVertex2i(212,214);
        glVertex2i(212,222);
        glVertex2i(208,222);
        glEnd();

        glColor3ub(49,46,55);
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(204,215);
        glVertex2i(215,215);
        glVertex2i(204,120);
        glVertex2i(215,120);
        glVertex2i(208,204);
        glVertex2i(212,204);
        glEnd();
    }

};

void dayLampPost()
{
    LampPost lp;

    glPushMatrix();
    glTranslated(20, 5, 0);
    lp.drawdayLampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslated(340,5, 0);
    lp.drawdayLampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslated(700, 5, 0);
    lp.drawdayLampPost();
    glPopMatrix();
}

void nightLampPost()
{
    LampPost lp;

    glPushMatrix();
    glTranslated(20, 5, 0);
    lp.drawnightLampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslated(340,5, 0);
    lp.drawnightLampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslated(700, 5, 0);
    lp.drawnightLampPost();
    glPopMatrix();
}


void DayCloud()
{
    cloud c;
    //cloud 1
    glPushMatrix();
    glTranslated(300, -50, 0);
    c.drawDayCloud();
    glPopMatrix();
    //cloud 2
    glPushMatrix();
    glTranslated(-150, 0, 0);
    c.drawDayCloud();
    glPopMatrix();
    //cloud 3
    glPushMatrix();
    glTranslated(200, 50, 0);
    c.drawDayCloud();
    glPopMatrix();
    //cloud 4
    glPushMatrix();
    glTranslated(600, -100, 0);
    c.drawDayCloud();
    glPopMatrix();
}

void NightCloud()
{
    cloud c;
    //cloud 1
    glPushMatrix();
    glTranslated(300, -50, 0);
    c.drawNightCloud();
    glPopMatrix();
    //cloud 2
    glPushMatrix();
    glTranslated(-150, 0, 0);
    c.drawNightCloud();
    glPopMatrix();
    //cloud 3
    glPushMatrix();
    glTranslated(200, 50, 0);
    c.drawNightCloud();
    glPopMatrix();
    //cloud 4
    glPushMatrix();
    glTranslated(600, -100, 0);
    c.drawNightCloud();
    glPopMatrix();
}
struct cars
{
    void dayCarsRight()
    {
        //car01
        glColor3ub(199, 199, 193);
        glBegin(GL_QUADS);
        glVertex2i(104, 26);
        glVertex2i(196, 26);
        glVertex2i(196, 90);
        glVertex2i(104, 90);
        glEnd();

        glColor3ub(180, 204, 201);
        glBegin(GL_POLYGON);
        glVertex2i(196, 26);
        glVertex2i(226, 26);
        glVertex2i(226, 50);
        glVertex2i(210, 65);
        glVertex2i(203, 80);
        glVertex2i(196, 85);
        glEnd();

        glColor3ub(240, 109, 35);
        glBegin(GL_QUADS);
        glVertex2i(104, 32);
        glVertex2i(196, 32);
        glVertex2i(196, 90);
        glVertex2i(104, 90);
        glEnd();

        //car 01 window
        glColor3ub(253, 231, 215);
        glBegin(GL_QUADS);
        glVertex2i(196, 76);
        glVertex2i(196, 61);
        glVertex2i(218, 57);
        glVertex2i(206, 72);
        glEnd();



        wheel(123, 31, 8, 5);
        wheel(175, 31, 8, 5);

        //car03
        glColor3ub(28, 138, 141);
        glBegin(GL_POLYGON);
        glVertex2i(735, 22);
        glVertex2i(725, 22);
        glVertex2i(718, 18);
        glVertex2i(718, 14);
        glVertex2i(718, 14);
        glVertex2i(804, 14);
        glVertex2i(804, 18);
        glVertex2i(799, 22);
        glVertex2i(790, 22);
        glVertex2i(784, 46);
        glVertex2i(741, 46);
        glEnd();

        glColor3ub(153, 200, 209); //car3 window 01
        glBegin(GL_POLYGON);
        glVertex2i(746, 41);
        glVertex2i(741, 22);
        glVertex2i(761, 22);
        glVertex2i(761, 41);
        glEnd();

        glColor3ub(132, 172, 176); //car3 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(746, 41);
        glVertex2i(741, 22);
        glVertex2i(761, 41);
        glEnd();

        glColor3ub(153, 200, 209); //car2 window 02
        glBegin(GL_POLYGON);
        glVertex2i(765, 41);
        glVertex2i(765, 22);
        glVertex2i(784, 22);
        glVertex2i(779, 41);
        glEnd();

        glColor3ub(132, 172, 176); //car3 window 02 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(765, 41);
        glVertex2i(765, 22);
        glVertex2i(779, 41);
        glEnd();
        wheel(740, 14, 4, 2);
        wheel(788, 14, 4, 2);

        //car04
        glColor3ub(238, 84, 59);
        glBegin(GL_POLYGON);
        glVertex2i(895, 22);
        glVertex2i(885, 22);
        glVertex2i(878, 18);
        glVertex2i(878, 14);
        glVertex2i(878, 14);
        glVertex2i(964, 14);
        glVertex2i(964, 18);
        glVertex2i(959, 22);
        glVertex2i(950, 22);
        glVertex2i(944, 46);
        glVertex2i(901, 46);
        glEnd();

        glColor3ub(219, 238, 243); //car4 window 01
        glBegin(GL_POLYGON);
        glVertex2i(906, 41);
        glVertex2i(901, 22);
        glVertex2i(921, 22);
        glVertex2i(921, 41);
        glEnd();

        glColor3ub(182, 190, 184); //car4 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(906, 41);
        glVertex2i(901, 22);
        glVertex2i(921, 41);
        glEnd();

        glColor3ub(219, 238, 243); //car4 window 02
        glBegin(GL_POLYGON);
        glVertex2i(925, 41);
        glVertex2i(925, 22);
        glVertex2i(944, 22);
        glVertex2i(939, 41);
        glEnd();

        glColor3ub(182, 190, 184); //car4 window 02 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(925, 41);
        glVertex2i(925, 22);
        glVertex2i(939, 41);
        glEnd();
        wheel(895, 16, 4, 2);
        wheel(950, 16, 4, 2);
    }
    void dayCarLeft()
    {
        //car02
        glColor3ub(215, 236, 240);
        glBegin(GL_POLYGON);
        glVertex2i(535, 82);
        glVertex2i(525, 82);
        glVertex2i(518, 78);
        glVertex2i(518, 74);
        glVertex2i(518, 74);
        glVertex2i(604, 74);
        glVertex2i(604, 78);
        glVertex2i(599, 82);
        glVertex2i(590, 82);
        glVertex2i(584, 106);
        glVertex2i(541, 106);
        glEnd();

        glColor3ub(44, 136, 133); //car2 window 01
        glBegin(GL_POLYGON);
        glVertex2i(546, 101);
        glVertex2i(541, 84);
        glVertex2i(561, 84);
        glVertex2i(561, 101);
        glEnd();

        glColor3ub(23, 125, 117); //car2 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(546, 101);
        glVertex2i(561, 84);
        glVertex2i(561, 101);
        glEnd();

        glColor3ub(44, 136, 133); //car2 window 02
        glBegin(GL_POLYGON);
        glVertex2i(565, 101);
        glVertex2i(565, 84);
        glVertex2i(585, 84);
        glVertex2i(580, 101);
        glEnd();

        glColor3ub(23, 125, 117); //car2 window 02 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(565, 101);
        glVertex2i(585, 84);
        glVertex2i(580, 101);
        glEnd();
        wheel(540, 74, 4, 2);
        wheel(578, 74, 4, 2);
    }
    void nightCarsRight()
    {
        //car01

        glColor3ub(108, 100, 110); //head light
        glBegin(GL_TRIANGLES);
        glVertex2i(300, 40);
        glVertex2i(300, 15);
        glColor3ub(204, 169, 48);
        glVertex2i(200, 40);
        glEnd();

        glColor3ub(121, 182, 231);
        glBegin(GL_QUADS);
        glVertex2i(104, 26);
        glVertex2i(196, 26);
        glVertex2i(196, 90);
        glVertex2i(104, 90);
        glEnd();

        glColor3ub(121, 182, 231);
        glBegin(GL_POLYGON);
        glVertex2i(196, 26);
        glVertex2i(226, 26);
        glVertex2i(226, 50);
        glVertex2i(210, 65);
        glVertex2i(203, 80);
        glVertex2i(196, 85);
        glEnd();

        glColor3ub(0, 137, 191);
        glBegin(GL_QUADS);
        glVertex2i(104, 32);
        glVertex2i(196, 32);
        glVertex2i(196, 90);
        glVertex2i(104, 90);
        glEnd();

        //car 01 window
        glColor3ub(253, 231, 215);
        glBegin(GL_QUADS);
        glVertex2i(196, 76);
        glVertex2i(196, 61);
        glVertex2i(218, 57);
        glVertex2i(206, 72);
        glEnd();



        wheel(123, 31, 8, 5);
        wheel(175, 31, 8, 5);

        //car03
        glColor3ub(108, 100, 110); //head light
        glBegin(GL_TRIANGLES);
        glVertex2i(860, 25);
        glVertex2i(860, 10);
        glColor3ub(204, 169, 48);
        glVertex2i(785, 20);
        glEnd();

        glColor3ub(6, 177, 213);
        glBegin(GL_POLYGON);
        glVertex2i(735, 22);
        glVertex2i(725, 22);
        glVertex2i(718, 18);
        glVertex2i(718, 14);
        glVertex2i(718, 14);
        glVertex2i(804, 14);
        glVertex2i(804, 18);
        glVertex2i(799, 22);
        glVertex2i(790, 22);
        glVertex2i(784, 46);
        glVertex2i(741, 46);
        glEnd();

        glColor3ub(0, 109, 157); //car3 window 01
        glBegin(GL_POLYGON);
        glVertex2i(746, 41);
        glVertex2i(741, 22);
        glVertex2i(761, 22);
        glVertex2i(761, 41);
        glEnd();

        glColor3ub(9, 36, 43); //car3 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(746, 41);
        glVertex2i(741, 22);
        glVertex2i(761, 41);
        glEnd();

        glColor3ub(0, 109, 157); //car3 window 02
        glBegin(GL_POLYGON);
        glVertex2i(765, 41);
        glVertex2i(765, 22);
        glVertex2i(784, 22);
        glVertex2i(779, 41);
        glEnd();

        glColor3ub(9, 36, 43); //car3 window 02 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(765, 41);
        glVertex2i(765, 22);
        glVertex2i(779, 41);
        glEnd();
        wheel(740, 14, 4, 2);
        wheel(788, 14, 4, 2);

        //car04
        glColor3ub(108, 100, 110); //head light
        glBegin(GL_TRIANGLES);
        glVertex2i(1020, 25);
        glVertex2i(1020, 10);
        glColor3ub(204, 169, 48);
        glVertex2i(950, 20);
        glEnd();

        glColor3ub(79, 183, 223);
        glBegin(GL_POLYGON);
        glVertex2i(895, 22);
        glVertex2i(885, 22);
        glVertex2i(878, 18);
        glVertex2i(878, 14);
        glVertex2i(878, 14);
        glVertex2i(964, 14);
        glVertex2i(964, 18);
        glVertex2i(959, 22);
        glVertex2i(950, 22);
        glVertex2i(944, 46);
        glVertex2i(901, 46);
        glEnd();

        glColor3ub(68, 112, 131); //car4 window 01
        glBegin(GL_POLYGON);
        glVertex2i(906, 41);
        glVertex2i(901, 22);
        glVertex2i(921, 22);
        glVertex2i(921, 41);
        glEnd();

        glColor3ub(7, 18, 14); //car4 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(906, 41);
        glVertex2i(901, 22);
        glVertex2i(921, 41);
        glEnd();

        glColor3ub(68, 112, 131); //car4 window 02
        glBegin(GL_POLYGON);
        glVertex2i(925, 41);
        glVertex2i(925, 22);
        glVertex2i(944, 22);
        glVertex2i(939, 41);
        glEnd();

        glColor3ub(7, 18, 14); //car4 window 02 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(925, 41);
        glVertex2i(925, 22);
        glVertex2i(939, 41);
        glEnd();
        wheel(895, 16, 4, 2);
        wheel(950, 16, 4, 2);
    }
    void nightCarsLeft()
    {
        //car02
        glColor3ub(108, 100, 110); //head light
        glBegin(GL_TRIANGLES);
        glVertex2i(472, 85);
        glVertex2i(472, 70);
        glColor3ub(204, 169, 48);
        glVertex2i(540, 79);
        glEnd();

        glColor3ub(4, 139, 182);
        glBegin(GL_POLYGON);
        glVertex2i(535, 82);
        glVertex2i(525, 82);
        glVertex2i(518, 78);
        glVertex2i(518, 74);
        glVertex2i(518, 74);
        glVertex2i(604, 74);
        glVertex2i(604, 78);
        glVertex2i(599, 82);
        glVertex2i(590, 82);
        glVertex2i(584, 106);
        glVertex2i(541, 106);
        glEnd();

        glColor3ub(6, 99, 157); //car2 window 01
        glBegin(GL_POLYGON);
        glVertex2i(546, 101);
        glVertex2i(541, 84);
        glVertex2i(561, 84);
        glVertex2i(561, 101);
        glEnd();

        glColor3ub(0, 30, 45); //car2 window 01 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(546, 101);
        glVertex2i(561, 84);
        glVertex2i(561, 101);
        glEnd();

        glColor3ub(6, 99, 157); //car2 window 02
        glBegin(GL_POLYGON);
        glVertex2i(565, 101);
        glVertex2i(565, 84);
        glVertex2i(585, 84);
        glVertex2i(580, 101);
        glEnd();

        glColor3ub(0, 30, 45); //car2 window 02 Glitch
        glBegin(GL_TRIANGLES);
        glVertex2i(565, 101);
        glVertex2i(585, 84);
        glVertex2i(580, 101);
        glEnd();
        wheel(540, 74, 4, 2);
        wheel(578, 74, 4, 2);
    }
};
void moveCarRight()

{
    cars c;
    if (isRedlight)
    {
        CarX_R += 0;
    }
    else
    {
        CarX_R += .9;
    }

    if (CarX_R > 1200)
    {
        CarX_R = -800;
    }

    glPushMatrix();
    glTranslatef(CarX_R, CarY_R, 0);
    if (isDay)
    {
        c.dayCarsRight();
    }
    else
    {
        c.nightCarsRight();
    }

    glPopMatrix();
}
void moveCarLeft()

{
    cars c;
    if (isRedlight)
    {
        CarX_L += 0;
    }
    else
    {
        CarX_L -= .9;
    }

    if (CarX_L < -650)
    {
        CarX_L = 650;
    }

    glPushMatrix();
    glTranslatef(CarX_L, CarY_L, 0);
    if (isDay)
    {
        c.dayCarLeft();
    }
    else
    {
        c.nightCarsLeft();
    }

    glPopMatrix();
}
void vehicle()
{
    moveCarLeft();
    moveCarRight();
}
void moveCloud()

{

    CloudX += .3;

    if (CloudX > 1200)
    {
        CloudX = -1200;
    }

    glPushMatrix();
    glTranslatef(CloudX, CloudY, 0);
    if (isDay)
    {
        DayCloud();
    }
    else
    {
        NightCloud();
    }

    glPopMatrix();
}
void sunRise()

{
    if (!sunSitThere)
    {
        sunY += .2;

    }
    if (sunY > 290)
    {

        text(50, 540, "Press N to make Night");
        sunSitThere = true;
    }
    glPushMatrix();
    glTranslatef(sunX, sunY, 0);
    sun();
    glPopMatrix();
}
void sunset()

{

    if (makeItNight)
    {
        sunY -= .2;
    }
    if (sunY < -125)
    {
        isDay = false;
        sunY = 0;
    }

    glPushMatrix();
    glTranslatef(sunX, sunY, 0);
    sun();
    glPopMatrix();
}
void MoonRise()

{
    if (!moonSitThere)
    {
        moonY += .2;

    }
    if (moonY > 290)
    {

        text(50, 540, "Press D to make Day");
        moonSitThere = true;
    }
    glPushMatrix();
    glTranslatef(moonX, moonY, 0);
    moon();
    glPopMatrix();
}


void moonset()

{

    if (makeItDay)
    {
        moonY -= .2;
    }
    if (moonY < -100)
    {
        isDay = true;
        moonY = 0;
    }

    glPushMatrix();
    glTranslatef(moonX, moonY, 0);
    moon();
    glPopMatrix();
}

struct Tree
{
    void drawdayTree()
    {

        glColor3ub(78,148,45);
        glBegin(GL_TRIANGLES);
        glVertex2i(370,271);
        glVertex2i(440,268);
        glVertex2i(400,297);
        glEnd();


        glColor3ub(39,118,37);
        glBegin(GL_TRIANGLES);
        glVertex2i(375,290);
        glVertex2i(432,290);
        glVertex2i(405,315);
        glEnd();


        glColor3ub(119,68,34);
        glBegin(GL_QUADS);
        glVertex2i(400,235);
        glVertex2i(410,235);
        glVertex2i(410,269);
        glVertex2i(400,269);
        glEnd();


    }

    void drawnightTree()
    {
        glColor3ub(26,77,132);
        glBegin(GL_TRIANGLES);
        glVertex2i(370,271);
        glVertex2i(440,268);
        glVertex2i(400,297);
        glEnd();


        glColor3ub(26,77,132);
        glBegin(GL_TRIANGLES);
        glVertex2i(375,290);
        glVertex2i(432,290);
        glVertex2i(405,315);
        glEnd();


        glColor3ub(26,77,132);
        glBegin(GL_QUADS);
        glVertex2i(400,235);
        glVertex2i(410,235);
        glVertex2i(410,269);
        glVertex2i(400,269);
        glEnd();

        glPointSize(2);
        glColor3ub(rand()%255,rand()%255,rand()%255);
        glBegin(GL_POINTS);
        glVertex2i(394,300);
        glVertex2i(406,297);
        glVertex2i(396,271);
        glVertex2i(426,261);
        glVertex2i(415,279);
        glVertex2i(400,279);
        glVertex2i(380,255);
        glEnd();
    }
};

void dayTree()
{
    Tree t;
    glPushMatrix();
    glTranslated(-100, -100, 0);
    t.drawdayTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(60, -95, 0);
    t.drawdayTree();
    glPopMatrix();


    glPushMatrix();
    glTranslated(170, -110, 0);
    t.drawdayTree();
    glPopMatrix();



    glPushMatrix();
    glTranslated(-300, -110, 0);
    t.drawdayTree();
    glPopMatrix();



    glPushMatrix();
    glTranslated(600, -100, 0);
    t.drawdayTree();
    glPopMatrix();

}

void nightTree()
{

    Tree t;
    glPushMatrix();
    glTranslated(-100, -100, 0);
    t.drawnightTree();
    glPopMatrix();

    glPushMatrix();
    glTranslated(60, -95, 0);
    t.drawnightTree();
    glPopMatrix();



    glPushMatrix();
    glTranslated(170, -110, 0);
    t.drawnightTree();
    glPopMatrix();



    glPushMatrix();
    glTranslated(-300, -110, 0);
    t.drawnightTree();
    glPopMatrix();


    glPushMatrix();
    glTranslated(600, -100, 0);
    t.drawnightTree();
    glPopMatrix();
}
void wheel(int x, int y, int outer, int inner)
{
    glPushMatrix();

    glColor3ub(0, 22, 51);
    DrawCircle(x, y, outer, 2000);
    glColor3ub(164, 199, 178);
    DrawCircle(x, y, inner, 2000);
    glPopMatrix();
}
void trafficlights(int x, int y)
{
    glPushMatrix();
    DrawCircle(x, y, 5, 2000);
    glPopMatrix();
}
void trfficText()
{
    if (isRedlight)
    {
        text(50, 560 ,"Press G for Green Light");
    }
    else
    {
        text(50, 560 ,"Press S for Red Light");
    }
}
void trafficlightStand()
{
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(600, 122);
    glVertex2i(605, 122);
    glVertex2i(605, 160);
    glVertex2i(600, 160);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(595, 160);
    glVertex2i(610, 160);
    glVertex2i(610, 190);
    glVertex2i(595, 190);
    glEnd();

    if (isRedlight)
    {
        glColor3ub(255, 0, 0);
        trafficlights(602, 181);
        glColor3ub(0, 80, 0);
        trafficlights(602, 168);
    }
    else
    {
        glColor3ub(80, 0, 0);
        trafficlights(602, 181);
        glColor3ub(0, 255, 0);
        trafficlights(602, 168);
    }
}
void RoadFieldDay()
{
    ///Green Field
    glColor3ub(86, 125, 70);
    glBegin(GL_QUADS);
    glVertex2i(0, 170);
    glVertex2i(0, 122);
    glVertex2i(1200, 122);
    glVertex2i(1200, 170);
    glEnd();
    ///end

    ///Road
    glColor3ub(60, 60, 60);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(1200, 0);
    glVertex2i(1200, 122);
    glVertex2i(0, 122);
    glEnd();


    glLineWidth(5); // road_strip
    glLineStipple(30, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2i(0, 58);
    glVertex2i(1190, 58);
    glEnd();




    ///end
}
void RoadFieldNight()
{
    ///Green Field
    glColor3ub(9, 27, 32);
    glBegin(GL_QUADS);
    glVertex2i(0, 170);
    glVertex2i(0, 122);
    glVertex2i(1200, 122);
    glVertex2i(1200, 170);
    glEnd();
    ///end

    ///Road
    glColor3ub(27, 66, 121);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(1200, 0);
    glVertex2i(1200, 122);
    glVertex2i(0, 122);
    glEnd();


    glLineWidth(5); // road_strip
    glLineStipple(10, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
    glColor3ub(6, 95, 138);
    glBegin(GL_LINES);
    glVertex2i(0, 58);
    glVertex2i(1190, 58);
    glEnd();


    ///end
}



void DayTime()
{
    ///Hill 1
    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 170);
    glVertex2i(200, 300);
    glVertex2i(300, 170);
    glEnd();

    ///Hill 2

    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(270, 170);
    glVertex2i(370, 270);
    glVertex2i(470, 170);
    glEnd();

    ///Hill 3

    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(1050, 170);
    glVertex2i(1150, 300);
    glVertex2i(1300, 170);
    glEnd();

   ///station

    glColor3ub(150,150,150);
    glBegin(GL_QUADS);
    glVertex2i(700,220);
    glVertex2i(700,140);
    glVertex2i(850,140);
    glVertex2i(850,220);
    glEnd();

    glColor3ub(100,100,100);
    glBegin(GL_QUADS);
    glVertex2i(720,240);
    glVertex2i(700,220);
    glVertex2i(850,220);
    glVertex2i(870,240);
    glEnd();

    glColor3ub(0,128,128);
    glBegin(GL_TRIANGLES);
    glVertex2i(700,160);
    glVertex2i(720,239);
    glVertex2i(700,220);
    glEnd();

    glColor3ub(0,128,128);
    glBegin(GL_TRIANGLES);
    glVertex2i(850,160);
    glVertex2i(870,240);
    glVertex2i(850,220);
    glEnd();

    glColor3ub(100,100,100);
    glBegin(GL_QUADS);
    glVertex2i(690,139);
    glVertex2i(690,130);
    glVertex2i(860,130);
    glVertex2i(860,139);
    glEnd();

    glColor3ub(50,50,50);
    glDisable(GL_LINE_STIPPLE);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(720,155);
    glVertex2i(840,155);

    glVertex2i(730,155);
    glVertex2i(730,140);
    glVertex2i(750,155);
    glVertex2i(750,140);
    glVertex2i(770,155);
    glVertex2i(770,140);
    glVertex2i(790,155);
    glVertex2i(790,140);
    glVertex2i(810,155);
    glVertex2i(810,140);
    glVertex2i(830,155);
    glVertex2i(830,140);
    glEnd();

    ///Mall
 glBegin(GL_QUADS);


    glColor3ub(30,144,255);

    glVertex2i(450,150);
    glVertex2i(600,150);

    glVertex2i(600,300);
    glVertex2i(450,300);
    glEnd();

text(475, 275, "Shopping Mall");
    glLineWidth(7.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2i(450,200);
    glVertex2i(600, 200);

     glVertex2i(450,250);
    glVertex2i(600, 250);

     glVertex2i(450,300);
    glVertex2i(600, 300);

   glEnd();




    glBegin(GL_QUADS);
    glColor3ub(30,144,255);
    glVertex2i(600,150);
    glVertex2i(630,160);
    glVertex2i(630,310);
    glVertex2i(600,300);

    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(600,200);
    glVertex2i(630,210);

    glVertex2i(600,250);
    glVertex2i(630,260);

    glVertex2i(600,300);
    glVertex2i(630,310);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2i(600,150);
    glVertex2i(600, 300);

    glEnd();

   glBegin(GL_QUADS);
    glColor3ub(30,144,255);

     glVertex2i(450,304);
    glVertex2i(460,315);
    glVertex2i(632,315);
    glVertex2i(600,304);

    glEnd();

  glBegin(GL_QUADS);
    glColor3ub(175,238,238);

     glVertex2i(500,150);
    glVertex2i(550,150);
    glVertex2i(550,190);
    glVertex2i(500,190);

    glEnd();


  ///billboard
glColor3ub(47,79,79);


  glBegin(GL_QUADS);
    glColor3ub(47,79,79);

     glVertex2i(200,200);
    glVertex2i(350,200);
    glVertex2i(350,290);
    glVertex2i(200,290);


glEnd();

text(250, 245, "Close Up");

glLineWidth(7.5);
     glBegin(GL_LINES);
    glColor3ub(47,79,79);

     glVertex2i(275,150);
    glVertex2i(275,200);

   glEnd();

   ///Front Building - 1
    glColor3ub(10, 7, 8); //right_side
    glBegin(GL_QUADS);
    glVertex2i(41, 170);
    glVertex2i(53, 170);
    glVertex2i(53, 314);
    glVertex2i(41, 314);
    glEnd();

    glColor3ub(0, 113, 168); //main
    glBegin(GL_QUADS);
    glVertex2i(53, 170);
    glVertex2i(94, 170);
    glVertex2i(94, 314);
    glVertex2i(53, 314);
    glEnd();

    glColor3ub(177, 101, 46); //main_window_white
    glBegin(GL_QUADS);
    glVertex2i(59, 175);
    glVertex2i(89, 175);
    glVertex2i(89, 309);
    glVertex2i(59, 309);
    glEnd();

    glColor3ub(10, 7, 8); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(67, 274);
    glVertex2i(89, 274);
    glVertex2i(89, 290);
    glVertex2i(67, 290);
    glEnd();

    glColor3ub(10, 7, 8); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(67, 232);
    glVertex2i(89, 232);
    glVertex2i(89, 253);
    glVertex2i(67, 253);
    glEnd();

    glColor3ub(177, 101, 46);
    glLineWidth(3); //main_window_grill
    glColor3ub(0, 113, 168);
    glBegin(GL_LINES); //1V
    glVertex2i(66, 309);
    glVertex2i(66, 175);
    glEnd();

    glBegin(GL_LINES); //2V
    glVertex2i(75, 309);
    glVertex2i(75, 175);
    glEnd();

    glBegin(GL_LINES); //3V
    glVertex2i(83, 309);
    glVertex2i(83, 175);
    glEnd();

    glBegin(GL_LINES); //1H
    glVertex2i(59, 292);
    glVertex2i(89, 292);
    glEnd();

    glBegin(GL_LINES); //2H
    glVertex2i(59, 273);
    glVertex2i(89, 273);
    glEnd();

    glBegin(GL_LINES); //3H
    glVertex2i(59, 253);
    glVertex2i(89, 253);
    glEnd();

    glBegin(GL_LINES); //4H
    glVertex2i(59, 233);
    glVertex2i(89, 233);
    glEnd();

    glBegin(GL_LINES); //5H
    glVertex2i(59, 213);
    glVertex2i(89, 213);
    glEnd();

    glBegin(GL_LINES); //5H
    glVertex2i(59, 193);
    glVertex2i(89, 193);
    glEnd();

 //1st building

    glBegin(GL_POLYGON);
    glPointSize(10.0);
    glColor3ub(106, 135, 109);
    glVertex2i(310, 250);
    glVertex2i(395, 250);
    glVertex2i(387, 262);
    glVertex2i(318, 262);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(305, 245);
    glVertex2i(400, 245);
    glVertex2i(397, 250);
    glVertex2i(306, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);

    glColor3ub(239, 124, 33);
    glVertex2i(310, 145);
    glVertex2i(395, 145);
    glVertex2i(395, 245);
    glVertex2i(310, 245);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(214, 195, 144);
    glVertex2i(310, 212);
    glVertex2i(395, 212);
    glVertex2i(395, 217);
    glVertex2i(310, 217);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(322, 217);
    glVertex2i(336, 217);
    glVertex2i(336, 238);
    glVertex2i(322, 238);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(322, 232);
    glVertex2i(336, 232);
    glVertex2i(322, 222);
    glVertex2i(336, 222);
    glVertex2i(330, 238);
    glVertex2i(330, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(345, 217);
    glVertex2i(357, 217);
    glVertex2i(357, 238);
    glVertex2i(345, 238);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(345, 232);
    glVertex2i(358, 232);
    glVertex2i(345, 222);
    glVertex2i(358, 222);
    glVertex2i(352, 238);
    glVertex2i(352, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(368, 217);
    glVertex2i(381, 217);
    glVertex2i(381, 238);
    glVertex2i(368, 238);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(368, 232);
    glVertex2i(382, 232);
    glVertex2i(368, 222);
    glVertex2i(382, 222);
    glVertex2i(375, 238);
    glVertex2i(375, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(335, 185);
    glVertex2i(345, 185);
    glVertex2i(345, 205);
    glVertex2i(335, 205);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(335, 200);
    glVertex2i(345, 200);
    glVertex2i(335, 191);
    glVertex2i(345, 191);
    glVertex2i(340, 205);
    glVertex2i(340, 185);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(355, 185);
    glVertex2i(370, 185);
    glVertex2i(370, 205);
    glVertex2i(355, 205);
    glEnd();





     glBegin(GL_QUADS); //red1 b2
    glPointSize(10.0);
    glColor3ub(208, 75, 36);
    glVertex2i(855, 155);
    glVertex2i(865, 155);
    glVertex2i(865, 330);
    glVertex2i(855, 330);
    glEnd();

    glBegin(GL_QUADS); //red2 b2 border
    glPointSize(10.0);
    glColor3ub(208, 75, 36);
    glVertex2i(850, 325);
    glVertex2i(865, 325);
    glVertex2i(865, 335);
    glVertex2i(850, 335);
    glEnd();
    glBegin(GL_QUADS); //green1 b2
    glPointSize(10.0);
    glColor3ub(29, 68, 59);
    glVertex2i(865, 155);
    glVertex2i(925, 155);
    glVertex2i(925, 330);
    glVertex2i(865, 330);
    glEnd();
    glBegin(GL_QUADS); //green2 b2 border
    glPointSize(10.0);
    glColor3ub(29, 68, 59);
    glVertex2i(860, 325);
    glVertex2i(930, 325);
    glVertex2i(930, 335);
    glVertex2i(860, 335);
    glEnd();
    glBegin(GL_QUADS); //w1 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(870, 290);
    glVertex2i(885, 290);
    glVertex2i(885, 310);
    glVertex2i(870, 310);
    glEnd();
    glBegin(GL_QUADS); //w2 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(890, 290);
    glVertex2i(905, 290);
    glVertex2i(905, 310);
    glVertex2i(890, 310);
    glEnd();
    glBegin(GL_QUADS); //w3 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(910, 290);
    glVertex2i(925, 290);
    glVertex2i(925, 310);
    glVertex2i(910, 310);
    glEnd();
    //line border1

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(184, 218, 194);
    glVertex2i(867, 282);
    glVertex2i(923, 282);
    glEnd();

    glBegin(GL_QUADS); //w4 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(870, 255);
    glVertex2i(885, 255);
    glVertex2i(885, 275);
    glVertex2i(870, 275);
    glEnd();
    glBegin(GL_QUADS); //w5 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(890, 255);
    glVertex2i(905, 255);
    glVertex2i(905, 275);
    glVertex2i(890, 275);
    glEnd();

    glBegin(GL_QUADS); //w6 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(910, 255);
    glVertex2i(925, 255);
    glVertex2i(925, 275);
    glVertex2i(910, 275);
    glEnd();
    //line border2
    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(184, 218, 194);
    glVertex2i(867, 244);
    glVertex2i(923, 244);
    glEnd();

    glBegin(GL_QUADS); //w7 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(870, 220);
    glVertex2i(885, 220);
    glVertex2i(885, 240);
    glVertex2i(870, 240);
    glEnd();

    glBegin(GL_QUADS); //w8 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(890, 220);
    glVertex2i(905, 220);
    glVertex2i(905, 240);
    glVertex2i(890, 240);
    glEnd();

    glBegin(GL_QUADS); //w9 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(910, 220);
    glVertex2i(925, 220);
    glVertex2i(925, 240);
    glVertex2i(910, 240);
    glEnd();

    //line border3
    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(184, 218, 194);
    glVertex2i(867, 204);
    glVertex2i(923, 204);
    glEnd();



}
void NightTime()
{

///Hill 1
    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 170);
    glVertex2i(200, 300);
    glVertex2i(300, 170);
    glEnd();

    ///Hill 2

    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(270, 170);
    glVertex2i(370, 270);
    glVertex2i(470, 170);
    glEnd();

    ///Hill 3

    glColor3ub(150, 150, 150);
    glBegin(GL_TRIANGLES);
    glVertex2i(1050, 170);
    glVertex2i(1150, 300);
    glVertex2i(1300, 170);
    glEnd();

   ///station

    glColor3ub(150,150,150);
    glBegin(GL_QUADS);
    glVertex2i(700,220);
    glVertex2i(700,140);
    glVertex2i(850,140);
    glVertex2i(850,220);
    glEnd();

    glColor3ub(100,100,100);
    glBegin(GL_QUADS);
    glVertex2i(720,240);
    glVertex2i(700,220);
    glVertex2i(850,220);
    glVertex2i(870,240);
    glEnd();

    glColor3ub(0,128,128);
    glBegin(GL_TRIANGLES);
    glVertex2i(700,160);
    glVertex2i(720,239);
    glVertex2i(700,220);
    glEnd();

    glColor3ub(0,128,128);
    glBegin(GL_TRIANGLES);
    glVertex2i(850,160);
    glVertex2i(870,240);
    glVertex2i(850,220);
    glEnd();

    glColor3ub(100,100,100);
    glBegin(GL_QUADS);
    glVertex2i(690,139);
    glVertex2i(690,130);
    glVertex2i(860,130);
    glVertex2i(860,139);
    glEnd();

    glColor3ub(50,50,50);
    glDisable(GL_LINE_STIPPLE);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(720,155);
    glVertex2i(840,155);

    glVertex2i(730,155);
    glVertex2i(730,140);
    glVertex2i(750,155);
    glVertex2i(750,140);
    glVertex2i(770,155);
    glVertex2i(770,140);
    glVertex2i(790,155);
    glVertex2i(790,140);
    glVertex2i(810,155);
    glVertex2i(810,140);
    glVertex2i(830,155);
    glVertex2i(830,140);
    glEnd();

    ///Mall
 glBegin(GL_QUADS);
    glColor3ub(30,144,255);

    glVertex2i(450,150);
    glVertex2i(600,150);

    glVertex2i(600,300);
    glVertex2i(450,300);
    glEnd();


    glLineWidth(7.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2i(450,200);
    glVertex2i(600, 200);

     glVertex2i(450,250);
    glVertex2i(600, 250);

     glVertex2i(450,300);
    glVertex2i(600, 300);

   glEnd();




    glBegin(GL_QUADS);
    glColor3ub(30,144,255);
    glVertex2i(600,150);
    glVertex2i(630,160);
    glVertex2i(630,310);
    glVertex2i(600,300);

    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(600,200);
    glVertex2i(630,210);

    glVertex2i(600,250);
    glVertex2i(630,260);

    glVertex2i(600,300);
    glVertex2i(630,310);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2i(600,150);
    glVertex2i(600, 300);

    glEnd();

   glBegin(GL_QUADS);
    glColor3ub(30,144,255);

     glVertex2i(450,304);
    glVertex2i(460,315);
    glVertex2i(632,315);
    glVertex2i(600,304);

    glEnd();

  glBegin(GL_QUADS);
    glColor3ub(175,238,238);

     glVertex2i(500,150);
    glVertex2i(550,150);
    glVertex2i(550,190);
    glVertex2i(500,190);

    glEnd();


  ///billboard
glColor3ub(47,79,79);


  glBegin(GL_QUADS);
    glColor3ub(47,79,79);

     glVertex2i(200,200);
    glVertex2i(350,200);
    glVertex2i(350,290);
    glVertex2i(200,290);


glEnd();

text(250, 245, "Close Up");

glLineWidth(7.5);
     glBegin(GL_LINES);
    glColor3ub(47,79,79);

     glVertex2i(275,150);
    glVertex2i(275,200);

   glEnd();

   ///Front Building - 1
    glColor3ub(10, 7, 8); //right_side
    glBegin(GL_QUADS);
    glVertex2i(41, 170);
    glVertex2i(53, 170);
    glVertex2i(53, 314);
    glVertex2i(41, 314);
    glEnd();

    glColor3ub(0, 113, 168); //main
    glBegin(GL_QUADS);
    glVertex2i(53, 170);
    glVertex2i(94, 170);
    glVertex2i(94, 314);
    glVertex2i(53, 314);
    glEnd();

    glColor3ub(177, 101, 46); //main_window_white
    glBegin(GL_QUADS);
    glVertex2i(59, 175);
    glVertex2i(89, 175);
    glVertex2i(89, 309);
    glVertex2i(59, 309);
    glEnd();

    glColor3ub(10, 7, 8); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(67, 274);
    glVertex2i(89, 274);
    glVertex2i(89, 290);
    glVertex2i(67, 290);
    glEnd();

    glColor3ub(10, 7, 8); //nightwindow
    glBegin(GL_QUADS);
    glVertex2i(67, 232);
    glVertex2i(89, 232);
    glVertex2i(89, 253);
    glVertex2i(67, 253);
    glEnd();

    glColor3ub(177, 101, 46);
    glLineWidth(3); //main_window_grill
    glColor3ub(0, 113, 168);
    glBegin(GL_LINES); //1V
    glVertex2i(66, 309);
    glVertex2i(66, 175);
    glEnd();

    glBegin(GL_LINES); //2V
    glVertex2i(75, 309);
    glVertex2i(75, 175);
    glEnd();

    glBegin(GL_LINES); //3V
    glVertex2i(83, 309);
    glVertex2i(83, 175);
    glEnd();

    glBegin(GL_LINES); //1H
    glVertex2i(59, 292);
    glVertex2i(89, 292);
    glEnd();

    glBegin(GL_LINES); //2H
    glVertex2i(59, 273);
    glVertex2i(89, 273);
    glEnd();

    glBegin(GL_LINES); //3H
    glVertex2i(59, 253);
    glVertex2i(89, 253);
    glEnd();

    glBegin(GL_LINES); //4H
    glVertex2i(59, 233);
    glVertex2i(89, 233);
    glEnd();

    glBegin(GL_LINES); //5H
    glVertex2i(59, 213);
    glVertex2i(89, 213);
    glEnd();

    glBegin(GL_LINES); //5H
    glVertex2i(59, 193);
    glVertex2i(89, 193);
    glEnd();

 //1st building

    glBegin(GL_POLYGON);
    glPointSize(10.0);
    glColor3ub(106, 135, 109);
    glVertex2i(310, 250);
    glVertex2i(395, 250);
    glVertex2i(387, 262);
    glVertex2i(318, 262);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(0, 0, 0);
    glVertex2i(305, 245);
    glVertex2i(400, 245);
    glVertex2i(397, 250);
    glVertex2i(306, 250);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);

    glColor3ub(239, 124, 33);
    glVertex2i(310, 145);
    glVertex2i(395, 145);
    glVertex2i(395, 245);
    glVertex2i(310, 245);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(214, 195, 144);
    glVertex2i(310, 212);
    glVertex2i(395, 212);
    glVertex2i(395, 217);
    glVertex2i(310, 217);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(322, 217);
    glVertex2i(336, 217);
    glVertex2i(336, 238);
    glVertex2i(322, 238);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(322, 232);
    glVertex2i(336, 232);
    glVertex2i(322, 222);
    glVertex2i(336, 222);
    glVertex2i(330, 238);
    glVertex2i(330, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(345, 217);
    glVertex2i(357, 217);
    glVertex2i(357, 238);
    glVertex2i(345, 238);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(345, 232);
    glVertex2i(358, 232);
    glVertex2i(345, 222);
    glVertex2i(358, 222);
    glVertex2i(352, 238);
    glVertex2i(352, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(368, 217);
    glVertex2i(381, 217);
    glVertex2i(381, 238);
    glVertex2i(368, 238);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(368, 232);
    glVertex2i(382, 232);
    glVertex2i(368, 222);
    glVertex2i(382, 222);
    glVertex2i(375, 238);
    glVertex2i(375, 218);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(335, 185);
    glVertex2i(345, 185);
    glVertex2i(345, 205);
    glVertex2i(335, 205);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2i(335, 200);
    glVertex2i(345, 200);
    glVertex2i(335, 191);
    glVertex2i(345, 191);
    glVertex2i(340, 205);
    glVertex2i(340, 185);
    glEnd();

    glBegin(GL_QUADS);
    glPointSize(10.0);
    glColor3ub(253, 253, 253);
    glVertex2i(355, 185);
    glVertex2i(370, 185);
    glVertex2i(370, 205);
    glVertex2i(355, 205);
    glEnd();





     glBegin(GL_QUADS); //red1 b2
    glPointSize(10.0);
    glColor3ub(208, 75, 36);
    glVertex2i(855, 155);
    glVertex2i(865, 155);
    glVertex2i(865, 330);
    glVertex2i(855, 330);
    glEnd();

    glBegin(GL_QUADS); //red2 b2 border
    glPointSize(10.0);
    glColor3ub(208, 75, 36);
    glVertex2i(850, 325);
    glVertex2i(865, 325);
    glVertex2i(865, 335);
    glVertex2i(850, 335);
    glEnd();
    glBegin(GL_QUADS); //green1 b2
    glPointSize(10.0);
    glColor3ub(29, 68, 59);
    glVertex2i(865, 155);
    glVertex2i(925, 155);
    glVertex2i(925, 330);
    glVertex2i(865, 330);
    glEnd();
    glBegin(GL_QUADS); //green2 b2 border
    glPointSize(10.0);
    glColor3ub(29, 68, 59);
    glVertex2i(860, 325);
    glVertex2i(930, 325);
    glVertex2i(930, 335);
    glVertex2i(860, 335);
    glEnd();
    glBegin(GL_QUADS); //w1 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(870, 290);
    glVertex2i(885, 290);
    glVertex2i(885, 310);
    glVertex2i(870, 310);
    glEnd();
    glBegin(GL_QUADS); //w2 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(890, 290);
    glVertex2i(905, 290);
    glVertex2i(905, 310);
    glVertex2i(890, 310);
    glEnd();
    glBegin(GL_QUADS); //w3 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(910, 290);
    glVertex2i(925, 290);
    glVertex2i(925, 310);
    glVertex2i(910, 310);
    glEnd();
    //line border1

    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(184, 218, 194);
    glVertex2i(867, 282);
    glVertex2i(923, 282);
    glEnd();

    glBegin(GL_QUADS); //w4 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(870, 255);
    glVertex2i(885, 255);
    glVertex2i(885, 275);
    glVertex2i(870, 275);
    glEnd();
    glBegin(GL_QUADS); //w5 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(890, 255);
    glVertex2i(905, 255);
    glVertex2i(905, 275);
    glVertex2i(890, 275);
    glEnd();

    glBegin(GL_QUADS); //w6 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(910, 255);
    glVertex2i(925, 255);
    glVertex2i(925, 275);
    glVertex2i(910, 275);
    glEnd();
    //line border2
    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(184, 218, 194);
    glVertex2i(867, 244);
    glVertex2i(923, 244);
    glEnd();

    glBegin(GL_QUADS); //w7 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(870, 220);
    glVertex2i(885, 220);
    glVertex2i(885, 240);
    glVertex2i(870, 240);
    glEnd();

    glBegin(GL_QUADS); //w8 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(890, 220);
    glVertex2i(905, 220);
    glVertex2i(905, 240);
    glVertex2i(890, 240);
    glEnd();

    glBegin(GL_QUADS); //w9 b2
    glPointSize(10.0);
    glColor3ub(184, 218, 194);
    glVertex2i(910, 220);
    glVertex2i(925, 220);
    glVertex2i(925, 240);
    glVertex2i(910, 240);
    glEnd();

    //line border3
    glBegin(GL_LINES);
    glLineWidth(10);
    glColor3ub(184, 218, 194);
    glVertex2i(867, 204);
    glVertex2i(923, 204);
    glEnd();
}




void handleKeyboard(unsigned char key, int x, int y)

{
    switch (key)
    {
    case 'd':
        if (moonSitThere)
        {
            makeItDay = true;
            makeItNight = false;
            sunSitThere = false;
        }
        break;
    case 'n':
        if (sunSitThere)
        {
            makeItNight = true;
            makeItDay = false;
            moonSitThere = false;
        }
        break;
    case 'r':
        rainday = true;
        break;
    case 'f':
        rainday = false;
        break;
    case 's':
        isRedlight = true;
        break;
    case 'g':
        isRedlight = false;
        break;
        default:
        break;

    }

}

void Day()
{
    Daysky();
    if (sunY < -60)
        if (!rainday)
            EveningSky();
    sunRise();
    sunset();
    if (rainday)
    {
        coverTheSun();
        text(50, 580, "Press F to stop Rain");
    }
    else
        text(50, 580, "Press R to start Rain");

    trfficText();
    moveCloud();
    RoadFieldDay();
    DayTime();

    dayTree();
    trafficlightStand();
    vehicle();
    dayLampPost();
}

void Night()
{
    Nightsky();
    trfficText();
    MoonRise();
    moonset();
    if (rainday)
    {
        coverThemoon();
        text(50, 580, "Press F to stop Rain");
    }
    else
        text(50, 580, "Press R to start Rain");

    moveCloud();
    RoadFieldNight();
    NightTime();
    nightTree();
    trafficlightStand();
    vehicle();
    nightLampPost();
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (isDay)
    {
        Day();

    }
    else
    {
        Night();
    }
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();

    glPushMatrix();
    Rain(rain);
    glutPostRedisplay();
    glutTimerFunc(1, Rain, 0);
    glFlush();
    glPopMatrix();


}

void myInit(void)
{
    glClearColor(255, 255, 255, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0.0, 600.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 600);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("A HIGHWAY VIEW");
    glutDisplayFunc(Display);

    glutKeyboardFunc(handleKeyboard);

    myInit();
    glutMainLoop();
}
