#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>
#include <stdlib.h>
#include <windows.h>
#include<mmsystem.h>
#include<stdio.h>

static bool Limit = false;
GLfloat angle = 25.0f;
GLfloat angleForEars = 25.0f;
GLfloat pressToRotate = 0.0f;

int translateY=0;
void display();
void reshape(int w,int h);
void timer(int);
void idleFunc();
void drawtetrahedron();
void face();
void keyboard(unsigned char Key, int x, int y);
void drawHands(double x, double y,double z);
void drawLegs(double x, double y,double z);
void drawHedronsInMiddle(double x, double y, double z);
void timer(int);
void drawStars(double x,double y, double z);
void init(){
    glClearColor(0.0,0.0,0.0,0.0);
}
void LargeCube();
void smallCube();
void verticalCube();
void texture (void){
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(190,90);
    glutInitWindowSize(1000,1500);

    glutCreateWindow("Elza Morgan 18100260 - Youssef El Tabib 18102698");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idleFunc);
    glutTimerFunc(1000,timer,0);
    glutKeyboardFunc(keyboard);
    init();
    texture();
    PlaySound(TEXT("mars.wav"),NULL,SND_ASYNC);
    glutMainLoop();

}
float step=0;

        void display()
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();


        glPushMatrix();
          glTranslated(0+step,0+translateY,0);
        glRotatef(pressToRotate,0,0,1);

                //RIGHT LEG
            glPushMatrix();
                drawLegs(-0.4,-0.25,-7.8);
            glPopMatrix();

                //LEFT LEG
            glPushMatrix();
                drawLegs(0.3,-0.25,-8.1);
            glPopMatrix();

            //small cube
            glPushMatrix();
                smallCube();
            glPopMatrix();


        //vertical cube
            glPushMatrix();
                verticalCube();
            glPopMatrix();

        //for creating the whole face features
            face();

        //LEFT hand torus
        glPushMatrix();
            drawHands(0.3,1.5,-8);
        glPopMatrix();

        //RIGHT hand torus
            glPushMatrix();
                drawHands(-0.65,1.4,-7.8);
            glPopMatrix();

            //THERE ARE THE FOUR TETRAHEDRONES

            //FIRST
            glPushMatrix();
                drawHedronsInMiddle(0,0.66,-7.0);
            glPopMatrix();

            //SECOND
            glPushMatrix();
                drawHedronsInMiddle(0.45,0.1,-7.8);
            glPopMatrix();

            //THIRD
            glPushMatrix();
                drawHedronsInMiddle(0,1.1,-7.4);
            glPopMatrix();

            //FOURTH
            glPushMatrix();
                drawHedronsInMiddle(0.25,1.65,-7.5);
            glPopMatrix();

        glPopMatrix();

        //call for the large cube function
        glPushMatrix();
            glTranslated(3,-1.3,-8);
            glRotatef(100,1,0,0);
            LargeCube();
        glPopMatrix();

        //this is used to draw the stares at the background
        //firstStar
        glPushMatrix();
        drawStars(-2.5,2.5,-9);
        glPopMatrix();
        //secondStar
        glPushMatrix();
        drawStars(1,0.5,-9);
        glPopMatrix();
        //thirdStar
        glPushMatrix();
        drawStars(2,1.5,-9);
        glPopMatrix();
        //fourthStar
        glPushMatrix();
        drawStars(-1.5,1,-9);
        glPopMatrix();

        //fifthStar
        glPushMatrix();
        drawStars(-2,0,-9);
        glPopMatrix();

        //sixthStar
        glPushMatrix();
        drawStars(-2,2,-9);
        glPopMatrix();

        //seventhStar
        glPushMatrix();
        drawStars(-3,1,-9);
        glPopMatrix();

        //eightthStar
        glPushMatrix();
        drawStars(0,3,-9);
        glPopMatrix();

        //ninthStar
        glPushMatrix();
        drawStars(3,2,-9);
        glPopMatrix();

        //tenthStar
        glPushMatrix();
        drawStars(4,0.5,-9);
        glPopMatrix();

        //eleventhStar
        glPushMatrix();
        drawStars(3,3,-9);
        glPopMatrix();

        //twelvethStar
        glPushMatrix();
        drawStars(0,1,-9);
        glPopMatrix();

            //this function is used to make them rotate
            glutSwapBuffers();
            angle+=0.2;
            angleForEars+=0.2;
        }

//this function is used to draw the end both left and right side
void drawHands(double x, double y,double z){
    glTranslated(x,y,z);
    glRotatef(angle,1,0,0);
    glColor3f(0.807, 0.827, 0.372);
    glutSolidTorus(0.08,0.2,3,6);

}

//this function is used to draw the features of the face
void face()
{
    //head sphere
    glPushMatrix();
        glTranslated(-0.15,2.2,-7.9);
        glColor3f(0.976, 0.792, 0.345);
        glutSolidSphere(0.35,35,20);
    glPopMatrix();

    //Eye
    glPushMatrix();
        glTranslated(-0.03,2.27,-7.5);
        glRotatef(25,0 ,1,0);
        glColor3f(0,0,0);
        glutSolidSphere(0.1,35,30);
    glPopMatrix();

    //EYE IRES
    glPushMatrix();
        glTranslated(0,2.23,-7.4);
        glRotatef(25,0 ,1,0);
        glColor3f(1,1,1);
        glutSolidSphere(0.04,35,30);
    glPopMatrix();

    //NOSE
    glPushMatrix();
        glTranslated(0,2.1,-7.6);
        glRotatef(25,0 ,1,0);
        glColor3f(0.850, 0.854, 0.745);
        glutSolidCone(0.07,0.2,100,100);
    glPopMatrix();

    // LEFT EAR
    glPushMatrix();
        glTranslated(0.0,2.65,-8.2);
        glRotatef(15,1 ,0,0);
        glRotatef(-40,0,0,1);
        glRotatef(angleForEars,0,1,0);
        drawtetrahedron();
    glPopMatrix();


//RIGHT EAR
    glPushMatrix();
        glTranslated(-0.35,2.40,-7.5);
        glRotatef(20,1,0,0);
        glRotatef(45,0,0,1);
        glRotatef(angleForEars,0,1,0);
        drawtetrahedron();
    glPopMatrix();
 }

 //this is used to draw the legs of the robot
void drawLegs(double x, double y,double z){

glTranslated(x,y,z);
  glRotatef(-80,1,0,0);
  glColor3f(0.807, 0.827, 0.372);
  glutSolidCone(0.2,0.3,30,30);

}
//this is used to draw the stars which are on the background
void drawStars(double x,double y,double z){
glColor3f(1,1, 1);
glTranslated(x,y,z);
glScalef(0.1,0.1,0.1);
glRotated(angleForEars,1,1,0);
glutSolidOctahedron();
}
//this is used to draw the shapes which are onto the robot
void drawHedronsInMiddle(double x, double y, double z){
    glTranslated(x,y,z);
    glColor3f(0.345, 0.733, 0.517);
    glScalef(0.1,0.1,0.1);
    glutSolidIcosahedron();
}

void drawtetrahedron(){

glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(0.501, 0.501, 0.501);
      glVertex3f( 0.0f, 0.10f, 0.0f);
      glVertex3f(0.15f, -0.10f, 0.15f);
      glVertex3f(-0.15f, -0.10f, 0.15f);

      // Right
      glColor3f(0.501, 0.501, 0.501);
      glVertex3f(0.0f, 0.10f, 0.0f);
      glVertex3f(0.0f, -0.10f, -0.15f);
      glVertex3f(0.15f, -0.10f, 0.15f);

      // LEFT
      glColor3f(0.501, 0.501, 0.501);
      glVertex3f(0.0f, 0.10f, 0.0f);
      glVertex3f(-0.15f, -0.10f, 0.15f);
      glVertex3f(0.0f, -0.10f, -0.15f);

      // BOTTOM
      glColor3f(0.501, 0.501, 0.501);
      glVertex3f(-0.15f, -0.10f, 0.15);
      glVertex3f(0.15f, -0.10f, 0.15f);
      glVertex3f(0.0f, -0.10f, -0.15f);
   glEnd();

}
void verticalCube(){
    glTranslated(-0.2,1.5,-8);
    glRotatef(15,1 ,0,0);
    glRotatef(30,0,1,0);
    glBegin(GL_QUADS);

    //front
    glColor3f(0.274, 0.603, 0.627);
    glVertex3f(-0.3,0.4,0.5);
    glVertex3f(-0.3,-0.4,0.5);
    glVertex3f(0.3,-0.4,0.5);
    glVertex3f(0.3,0.4,0.5);
    //back
    glColor3f(0.066, 0.250, 0.333);
    glVertex3f(0.3,0.4,-0.5);
    glVertex3f(0.3,-0.4,-0.5);
    glVertex3f(-0.3,-0.4,-0.5);
    glVertex3f(-0.3,0.4,-0.5);
    //right
    glColor3f(0.635, 0.713, 0.427);
    glVertex3f(0.3,0.4,0.5);
    glVertex3f(0.3,-0.4,0.5);
    glVertex3f(0.3,-0.4,-0.5);
    glVertex3f(0.3,0.4,-0.5);
    //left
    glColor3f(0.635, 0.713, 0.427);
    glVertex3f(-0.3,0.4,-0.5);
    glVertex3f(-0.3,-0.4,-0.5);
    glVertex3f(-0.3,-0.4,0.5);
    glVertex3f(-0.3,0.4,0.5);
    //top
    glColor3f(0.066, 0.250, 0.333);
    glVertex3f(-0.3,0.4,-0.5);
    glVertex3f(-0.3,0.4,0.5);
    glVertex3f(0.3,0.4,0.5);
    glVertex3f(0.3,0.4,-0.5);
    //bottom
    glColor3f(0.066, 0.250, 0.333);
    glVertex3f(-0.3,-0.4,-0.5);
    glVertex3f(-0.3,-0.4,0.5);
    glVertex3f(0.3,-0.4,0.5);
    glVertex3f(0.3,-0.4,-0.5);

    glEnd();
}
void smallCube(){
    glTranslated(-0.15,0.5,-8);
    glRotatef(15,1,0,0);
    glRotatef(40,0,1,0);
    glBegin(GL_QUADS);
    //front
    glColor3f(10.921, 0.886, 0.156);
    glVertex3f(-0.5,0.5,0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.5,0.5,0.5);
    //back
    glColor3f(0.921, 0.886, 0.156);
    glVertex3f(0.5,0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,0.5,-0.5);
    //right
    glColor3f(0.635, 0.713, 0.427);
    glVertex3f(0.5,0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,0.5,-0.5);
    //left
    glColor3f(0.635, 0.713, 0.427);
    glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,0.5,0.5);
    //top
    glColor3f(0.921, 0.886, 0.156);
    glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(-0.5,0.5,0.5);
    glVertex3f(0.5,0.5,0.5);
    glVertex3f(0.5,0.5,-0.5);
    //bottom
    glColor3f(0.921, 0.886, 0.156);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glEnd();
}
void LargeCube(){
glBegin(GL_QUADS);
    //front
    glColor3f(0.274, 0.603, 0.627);
    glVertex3f(-7.0,1.0,1.0);
    glVertex3f(-7.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    //back
    glColor3f(0.274, 0.603, 0.627);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-7.0,-1.0,-1.0);
    glVertex3f(-7.0,1.0,-1.0);
    //right
    glColor3f(0.274, 0.603, 0.627);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    //left
    glColor3f(0.274, 0.603, 0.627);
    glVertex3f(-7.0,1.0,-1.0);
    glVertex3f(-7.0,-1.0,-1.0);
    glVertex3f(-7.0,-1.0,1.0);
    glVertex3f(-7.0,1.0,1.0);
    //top
    glColor3f(0.274, 0.603, 0.627);
    glVertex3f(-7.0,1.0,-1.0);
    glVertex3f(-7.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,1.0,-1.0);
    //bottom
    glColor3f(0.274, 0.603, 0.627);
    glVertex3f(-7.0,-1.0,-1.0);
    glVertex3f(-7.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glEnd();
}


void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)w/(GLdouble)h,0.5,40.0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-25,25,-25,25);
glMatrixMode(GL_MODELVIEW);

}
void idleFunc ()
{
    glutPostRedisplay();
}

void timer(int)
{
    glutPostRedisplay();
    if(!Limit){
        if(step<=3){
            step+=0.2;
        }else {
            Limit =true;
        }
    }else{
        if(step>=-3){
            step-=0.2;
        }else{
            Limit=false;
        }
    }
    glutTimerFunc(1000/15,timer,0);

}
void keyboard(unsigned char Key, int x, int y){

    switch(Key){

        case 'w' : translateY++;
        break;

        case 's' : if(translateY>0)translateY--;
        break;

        case 'f' : glutFullScreen();
        break;

        case 'a' :pressToRotate=pressToRotate+5;
        break;

          case 'd' :pressToRotate=pressToRotate-5;
        break;

        case 27 : exit(0);
        break;
    }
}


