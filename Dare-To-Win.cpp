/*

*********Dare-To-Win************


*/






#include <iostream>
#include <stdio.h>
#include <glut.h>
#include <stdarg.h>
#define yellow 1.0,1.0,0.0
#define red 1.0,0.0,0.0
#define white 1.0,1.0,1.0
#define black 0.0,0.0,0.0
#define green 0.0,255.0,0.0
#define brown 0.5,0.0,0.0
#define grey 0.49,0.49,0.49
#define blue 0.0,0.63,0.90
#define orange 1.0,0.50,0.0


using namespace std;
GLfloat rotation = 90.0;
float posX = 350, posY = 630, posZ = 0;             //POSITION OF BATMAN
float poscar2X=380,poscar2Y=550;                    //POSITION OF CAR in LANE1
float poscar4X=600,poscar4Y=419;                    //POSITION OF CAR in LANE3
float poscar5X=400,poscar5Y=288;                    //POSiTION OF CAR in LANE5
float poscar6X=400,poscar6Y=352;                    //POSiTION OF CAR in LANE4
float poscar1X=350,poscar1Y=485;                    //POSITION OF CAR in LANE2
float poscar3X=350,poscar3Y=224;                    //POSITION OF CAR in LANE6

int chk;
void colution();
void update(int x);                                 //Define update function
void nextlevelboundary();
void nextlevel();

void drawScaledPolygon(float scaleX,float scaleY,float r,float g, float b ,int cx,int cy, int numArgs ,...); //rotate polygon function
void d1rawScaledPolygon(float scaleX,float scaleY,float r,float g, float b ,int cx,int cy, int numArgs ,...);

void d1rawScaledPolygon(float scaleX,float scaleY,float r,float g, float b ,int cx,int cy, int numArgs ,...){
    glPushMatrix();
    glTranslatef(cx,cy,1);
    glScalef(scaleX,scaleY,0);
    va_list points;
    va_start(points,numArgs);
    int i;



    glBegin(GL_POLYGON);
    glColor3f (r,g,b);
    for(i=1;i<numArgs;i+=2){   //collecting points of polygon
        int px,py;

        px=va_arg(points,int);
        py=va_arg(points,int);

        glVertex2i(px,py);
    }
    glEnd();

    va_end(points);
    glFlush();

    glPopMatrix();
}
void nextlevel(void)
{
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();

         glRasterPos2f(320,720);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'X');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'T');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'V');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'O');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'T');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'A');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'D');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Y');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Y');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'T');

}

void colution(){
    cout << "posX : "<<posX<<" posY : "<< posY<<endl;
   // cout << "pos1X : "<<poscarX<<" pos1y : "<< poscarY<<endl;
//    cout << "carX : "<<poscar6X<<" carY : "<< poscar6Y<<endl;



    if((posX<poscar2X-45 || posY>poscar2Y+40 || posY <poscar2Y-40 || posX>poscar2X+55) &&
       (posX<poscar4X-45 || posY>poscar4Y+40 || posY <poscar4Y-40 || posX>poscar4X+55) &&
       (posX<poscar5X-45 || posY>poscar5Y+40 || posY <poscar5Y-40 || posX>poscar5X+55) &&
       (posX<poscar6X-45 || posY>poscar6Y+40 || posY <poscar6Y-40 || posX>poscar6X+55) &&
       (posX<poscar1X-45 || posY>poscar1Y+40 || posY <poscar1Y-40 || posX>poscar1X+55) &&
       (posX<poscar3X-45 || posY>poscar3Y+40 || posY <poscar3Y-40 || posX>poscar3X+55)
       )
        {
            chk=0;
        }
    else{
            chk=1;
        }
    if(posY<140)
        {
            nextlevel();
        }

}
void drawScaledPolygon(float scaleX,float scaleY,float r,float g, float b ,int cx,int cy, int numArgs ,...){
    glPushMatrix();

    glTranslatef(cx,cy,1);
    glScalef(scaleX,scaleY,0);

    glRotatef(180,0,1,0);           //rotating polygons
    glRotatef(180,1,0,0);

    va_list points;
    va_start(points,numArgs);
    int i;



    glBegin(GL_POLYGON);
    glColor3f (r,g,b);
    for(i=1;i<numArgs;i+=2){
        int px,py;

        px=va_arg(points,int);
        py=va_arg(points,int);

        glVertex2i(px,py);
    }
    glEnd();

    va_end(points);
    glFlush();

    glPopMatrix();
}

void nextlevelboundary(float cx ,float cy)
{
        d1rawScaledPolygon(5,5,orange,cx,cy, 8,0,0,120,0,120,10,0,10);
        glColor3f(white);
        glRasterPos2f(340,120);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'X');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'T');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'V');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');

}


void batman(float cx ,float cy)
{
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 8,100,330,100,230,130,210,130,300);
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 8,170,300,170,210,200,230,200,330);
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 8,130,300,130,200,170,200,170,300);
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 8,130,200,120,190,180,190,170,200);
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 8,100,190,100,100,200,100,200,190);
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 8,100,100,100,190,70,190,70,70);
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 8,200,100,230,70,230,190,200,190);
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 8,100,100,100,50,140,50,140,100);
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 8,160,100,160,50,200,50,200,100);
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 6,200,50,220,50,200,60);
        d1rawScaledPolygon(.2,.2,yellow,cx,cy, 6,100,50,100,60,80,50);
}
void road(float cx ,float cy){
        d1rawScaledPolygon(2,2,grey,cx,cy, 8, 1,20,299,20,299,80,1,80);
        d1rawScaledPolygon(2,2,white,cx,cy,8, 1,48,299,48,299,52,1,52);
        d1rawScaledPolygon(2,2,white,cx,cy,8, 1,16,299,16,299,20,1,20);
}
void road2(float cx ,float cy){
        d1rawScaledPolygon(2,2,grey,cx,cy, 8, 1,20,299,20,299,80,1,80);
        d1rawScaledPolygon(2,2,white,cx,cy,8, 1,48,299,48,299,52,1,52);
        d1rawScaledPolygon(2,2,white,cx,cy,8, 1,16,299,16,299,20,1,20);
}
void road3(float cx ,float cy){
        d1rawScaledPolygon(2,2,grey,cx,cy, 8, 1,20,299,20,299,80,1,80);
        d1rawScaledPolygon(2,2,white,cx,cy,8, 1,48,299,48,299,52,1,52);
        d1rawScaledPolygon(2,2,white,cx,cy,8, 1,16,299,16,299,20,1,20);

}
void car1(float cx ,float cy)
{
		glPointSize(10.0);
        d1rawScaledPolygon(.35,.35,blue,cx,cy, 12,70,50,70,150,10,150,0,140,0,60,10,50);
        d1rawScaledPolygon(.35,.35,blue,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,blue,cx,cy, 12,80,150,80,50,210,50,220,60,220,140,210,150);
        d1rawScaledPolygon(.35,.35,blue,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,blue,cx,cy, 8,30,140,20,140,20,120,30,120);
        d1rawScaledPolygon(.35,.35,blue,cx,cy, 8,30,60,30,80,20,80,20,60);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 12,100,130,70,140,60,130,60,70,70,60,100,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,140,130,130,150,130,150,140);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,60,150,60,150,70,130,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,160,70,200,60,200,140,160,130);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,140,210,140,210,120,220,120);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,60,220,80,210,80,210,60);
}
void car2(float cx ,float cy)
{
		glPointSize(10.0);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 12,70,50,70,150,10,150,0,140,0,60,10,50);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 12,80,150,80,50,210,50,220,60,220,140,210,150);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 8,30,140,20,140,20,120,30,120);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 8,30,60,30,80,20,80,20,60);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 12,100,130,70,140,60,130,60,70,70,60,100,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,140,130,130,150,130,150,140);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,60,150,60,150,70,130,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,160,70,200,60,200,140,160,130);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,140,210,140,210,120,220,120);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,60,220,80,210,80,210,60);


}

void car3(float cx ,float cy)
{
		glPointSize(10.0);
        d1rawScaledPolygon(.35,.35,orange,cx,cy, 12,70,50,70,150,10,150,0,140,0,60,10,50);
        d1rawScaledPolygon(.35,.35,orange,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,orange,cx,cy, 12,80,150,80,50,210,50,220,60,220,140,210,150);
        d1rawScaledPolygon(.35,.35,orange,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,orange,cx,cy, 8,30,140,20,140,20,120,30,120);
        d1rawScaledPolygon(.35,.35,orange,cx,cy, 8,30,60,30,80,20,80,20,60);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 12,100,130,70,140,60,130,60,70,70,60,100,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,140,130,130,150,130,150,140);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,60,150,60,150,70,130,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,160,70,200,60,200,140,160,130);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,140,210,140,210,120,220,120);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,60,220,80,210,80,210,60);
}
void car4(float cx ,float cy)
{
		glPointSize(10.0);
        d1rawScaledPolygon(.35,.35,yellow,cx,cy, 12,70,50,70,150,10,150,0,140,0,60,10,50);
        d1rawScaledPolygon(.35,.35,yellow,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,yellow,cx,cy, 12,80,150,80,50,210,50,220,60,220,140,210,150);
        d1rawScaledPolygon(.35,.35,yellow,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 8,30,140,20,140,20,120,30,120);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 8,30,60,30,80,20,80,20,60);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 12,100,130,70,140,60,130,60,70,70,60,100,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,140,130,130,150,130,150,140);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,60,150,60,150,70,130,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,160,70,200,60,200,140,160,130);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,140,210,140,210,120,220,120);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,60,220,80,210,80,210,60);


}
void car5(float cx ,float cy)
{
		glPointSize(10.0);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 12,70,50,70,150,10,150,0,140,0,60,10,50);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 12,80,150,80,50,210,50,220,60,220,140,210,150);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 8,30,140,20,140,20,120,30,120);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 8,30,60,30,80,20,80,20,60);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 12,100,130,70,140,60,130,60,70,70,60,100,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,140,130,130,150,130,150,140);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,60,150,60,150,70,130,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,160,70,200,60,200,140,160,130);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,140,210,140,210,120,220,120);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,60,220,80,210,80,210,60);


}

void car6(float cx ,float cy){
        glPointSize(10.0);
        d1rawScaledPolygon(.35,.35,green,cx,cy, 12,70,50,70,150,10,150,0,140,0,60,10,50);
        d1rawScaledPolygon(.35,.35,green,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,green,cx,cy, 12,80,150,80,50,210,50,220,60,220,140,210,150);
        d1rawScaledPolygon(.35,.35,green,cx,cy, 8,80,160,70,150,70,50,80,40);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 8,30,140,20,140,20,120,30,120);
        d1rawScaledPolygon(.35,.35,white,cx,cy, 8,30,60,30,80,20,80,20,60);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 12,100,130,70,140,60,130,60,70,70,60,100,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,140,130,130,150,130,150,140);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,100,60,150,60,150,70,130,70);
        d1rawScaledPolygon(.35,.35,black,cx,cy, 8,160,70,200,60,200,140,160,130);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,140,210,140,210,120,220,120);
        d1rawScaledPolygon(.35,.35,red,cx,cy, 8,220,60,220,80,210,80,210,60);

}




void boundary()
{
        glColor3f(green);
        glRasterPos2f(100,720);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'V');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '-');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '1');

		glRasterPos2f(520,720);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'V');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'S');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'I');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'O');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ':');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '1');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '.');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0');

        glColor3f(green);
        glPointSize(1.0);
        glBegin(GL_LINES);
        glVertex2i(100,100);
        glVertex2i(700,100);
        glVertex2i(700,100);
        glVertex2i(700,700);
        glVertex2i(700,700);
        glVertex2i(100,700);
        glVertex2i(100,700);
        glVertex2i(100,100);

        glEnd();
        glFlush ();
}

int game_end(void)
{
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
//                glRotatef(-_cameraAngle, 0.0, 1.0, 0.0);

         glRasterPos2f(320,720);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'G');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'A');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'M');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'O');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'V');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');

          return 0;
}





void display(){
    //Clear Window
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    boundary();
    nextlevelboundary(100,100);
    road(100,450);
    road2(100,320);
    road3(100,190);
    car1(poscar1X,poscar1Y);
    car2(poscar2X,poscar2Y);
    car3(poscar3X,poscar3Y);
    car4(poscar4X,poscar4Y);
    car5(poscar5X,poscar5Y);
    car6(poscar6X,poscar6Y);


    batman(posX,posY);
    colution();
    update(10);
    glPopMatrix();
    glFlush();

}

void update(int x){
    if(chk==1){
        game_end();
    }
    else{
        poscar1X-=3;    //speed of lane2 car
        poscar2X-=2;    //speed of lane1 car
        poscar3X-=7;   //speed of lane6 car
        poscar4X-=4;    //speed of lane3 car
        poscar5X-=6;   //speed of lane5 car
        poscar6X-=5;    //speed of lane4 car

        if(poscar2X<=100){
            poscar2X=620;
        }
        if(poscar4X<=100){
            poscar4X=620;
        }
        if(poscar5X<=100){
            poscar5X=620;
        }
        if(poscar6X<=100){
            poscar6X=620;
        }
        if(poscar1X<=100){
            poscar1X=620;
        }
        if(poscar3X<=100){
            poscar3X=620;
        }
            glutPostRedisplay();
        //glutTimerFunc(100000,update,0);
    }
}

void init(){
    // set clear color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // set fill color to white
    glColor3f(1.0, 1.0, 1.0);

    //set up standard orthogonal view with clipping
    //box as cube of side 2 centered at origin
    //This is the default view and these statements could be removed
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,800);

}
float move_unit = 10.0f;
void keyboardown(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:

            cout << posX << endl;
            if(posX==650){
               posX+=0;
            }
            else{
                posX+=move_unit;
            }
            break;

        case GLUT_KEY_LEFT:
            cout << posX << endl;

            if(posX==90){
               posX-=0;
            }
            else{
                 posX-=move_unit;
            }

        break;

        case GLUT_KEY_UP:
            cout << posY << endl;

            if(posY==630){
               posY+=0;
            }
            else{
                 posY+=move_unit;
            }

            break;

        case GLUT_KEY_DOWN:
            cout << posY << endl;

            if(posY==100){
               posY-=0;
            }
            else{
                 posY-=move_unit;
            }

        break;

        default:
         break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv){

    //initialize mode and open a windows in upper left corner of screen
    //Windows tittle is name of program

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("CAR PUZZLE");
    glutDisplayFunc(display);
    init();
    glutSpecialFunc(keyboardown);
    //glutTimerFunc(1000,update,0);
    glutMainLoop();

     return 0;
}
