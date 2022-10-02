/*
    Nama:
    Frankie 672019165
    Agnes Cherrly 672019049
    Nodas Constantine Baronio 672019347
    Afiyatar Asyer 672019061
 */
#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>

const double PI = 3.14;

void init(void);
void tampil(void);
void keyboard(unsigned char,int,int);
void ukuran(int,int);
void mouseMotion(int x, int y);
void mouse(int button, int state, int x, int y);
void cylinder(float radius,float jumlah_titik,float x_tengah,float z_tengah,float alas,float tutupatas,float tinggi,float triangle_tinggi, float a, float b, float c, float d, float a1, float b1, float c1, float d1);
void setengahlingkaran(float radius,float jumlah_titik,float y_tengah,float z_tengah,float alas,float tutupatas,float tinggi,float triangle_tinggi, float a, float b, float c, float d, float a1, float b1, float c1, float d1);
void setengahlingkaran1(float radius,float jumlah_titik,float x_tengah,float y_tengah,float alas,float tutupatas,float tinggi,float triangle_tinggi, float a, float b, float c, float d, float a1, float b1, float c1, float d1);
void setengahlingkaran2(float radius,float jumlah_titik,float x_tengah,float y_tengah,float alas,float tutupatas,float tinggi,float triangle_tinggi, float a, float b, float c, float d, float a1, float b1, float c1, float d1);
void dindingmall(float a, float b, float c, float d, float e, float f);
void lingkaran(float radius,float jumlah_titik,float x_tengah,float z_tengah, float tutup_atas, float a1, float b1, float c1, float d1);
void atapmall(float a, float b, float c, float d, float e, float f);
void pagarmall(float a, float b, float c, float d, float e, float f);
void kursi(float x,float y,float z,float x1,float y1,float z1,float y2,float z2);
void persegi(float x, float y, float z, float x1, float y1, float z1);
void gedung(void);


float zpos = -40;

float r,g,b;



void Idle()
{
    if(zpos<=40)
    {
        r = (rand()%9/8);
        g = (rand()%8/8);
        b = (rand()%9/8);
    // moving speed
        zpos += 0.06;
    }


    glutPostRedisplay();
}

void objekBergerak()
{
    // sirine
        glPushMatrix();
        glColor3f(r, g, b);
        glTranslatef(zpos, -14.0, 5.0);
        glScalef(1.5, 1.9, 5.0);
        glutSolidCube(0.2);
        glPopMatrix();
}

void objekBergerak2()
{
    // badan mobil
        glPushMatrix();
       glColor3f(0, 1, 0);
        glTranslatef(zpos, -14.5, 5.0);
        glScalef(3.0, 1.0, 1.5);
        glutSolidCube(0.9);
        glPopMatrix();
}

void objekBergerak3()
{
    //depan mobil
        glPushMatrix();
       glColor3f(0, 1, 0);
        glTranslatef(zpos + 1, -15.0, 5.0);
        glScalef(2.0, 0.5, 1.4);
        glutSolidCube(0.9);
        glPopMatrix();
}

void objekBergerak4()
{
    //belakang mobil
        glPushMatrix();
       glColor3f(0, 1, 0);
        glTranslatef(zpos - 0.5, -15.0, 5.0);
        glScalef(2.4, 0.5, 1.4);
        glutSolidCube(0.9);
        glPopMatrix();
}

void mobilPolisiMinecraft()
{
    objekBergerak();
    objekBergerak2();
    objekBergerak3();
    objekBergerak4();
}



float xrot = 0.0f;
float yrot = 0.0f;
float zrot = 0.0f;
float xx= 0.0;
float yy = 0.0;
float zz = 0.0;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mousDown = false;
int is_depth;


int main(int argc,char**argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("672019049, 672019061, 672019165, 672019347");
    init();

    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}

void init(void)
{

    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);

    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(3.0f);

}

void tampil(void)
{

    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    else
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glLoadIdentity();
        gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
        glRotatef(xrot,1.0f,0.0f,0.0f);
        glRotatef(yrot,0.0f,1.0f,0.0f);
        glRotatef(zrot,0.0f,0.0f,1.0f);
        glTranslatef(xx,yy,zz);

	//jendela
        glBegin(GL_LINES);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-8,-6.5,-18.5);
            glVertex3f(-9.5,-6.5,-19.2);
            glVertex3f(-10.2,-6.5,-19.6);
            glVertex3f(-11.7,-6.5,-20.4);
            glVertex3f(-12.4,-6.5,-20.6);
            glVertex3f(-13.9,-6.5,-21.4);
            glVertex3f(-14.6,-6.5,-21.7);
            glVertex3f(-16.1,-6.5,-22.4);
            glVertex3f(-16.8,-6.5,-22.9);
            glVertex3f(-18.3,-6.5,-23.7);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-12.4,-5,-20.6);
            glVertex3f(-13.9,-5,-21.4);
            glVertex3f(-13.9,-9,-21.4);
            glVertex3f(-12.4,-9,-20.6);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-8,-5,-18.5);
            glVertex3f(-9.5,-5,-19.2);
            glVertex3f(-9.5,-9,-19.2);
            glVertex3f(-8,-9,-18.5);
            glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-10.2,-5,-19.6);
            glVertex3f(-11.7,-5,-20.4);
            glVertex3f(-11.7,-9,-20.4);
            glVertex3f(-10.2,-9,-19.6);
            glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-14.6,-5,-21.7);
            glVertex3f(-16.1,-5,-22.5);
            glVertex3f(-16.1,-9,-22.5);
            glVertex3f(-14.6,-9,-21.7);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-16.8,-5,-22.9);
            glVertex3f(-18.3,-5,-23.7);
            glVertex3f(-18.3,-9,-23.7);
            glVertex3f(-16.8,-9,-22.9);
        glEnd();
        glBegin(GL_QUADS);
            glColor4f(0.0,0.0,0.0,1);
            glVertex3f(-8,-5,-18.5);
            glVertex3f(-9.5,-5,-19.2);
            glVertex3f(-9.5,-9,-19.2);
            glVertex3f(-8,-9,-18.5);

            glVertex3f(-10.2,-5,-19.6);
            glVertex3f(-11.7,-5,-20.4);
            glVertex3f(-11.7,-9,-20.4);
            glVertex3f(-10.2,-9,-19.6);

            glVertex3f(-12.4,-5,-20.6);
            glVertex3f(-13.9,-5,-21.4);
            glVertex3f(-13.9,-9,-21.4);
            glVertex3f(-12.4,-9,-20.6);

            glVertex3f(-14.6,-5,-21.7);
            glVertex3f(-16.1,-5,-22.5);
            glVertex3f(-16.1,-9,-22.5);
            glVertex3f(-14.6,-9,-21.7);

            glVertex3f(-16.8,-5,-22.9);
            glVertex3f(-18.3,-5,-23.7);
            glVertex3f(-18.3,-9,-23.7);
            glVertex3f(-16.8,-9,-22.9);
        glEnd();

	//Jendela2
        glBegin(GL_LINES);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(5,-6.5,-13.5);
            glVertex3f(7,-6.5,-13);
            glVertex3f(3,-6.5,-14);
            glVertex3f(4.5,-6.5,-13.5);
            glVertex3f(7.5,-6.5,-12.5);
            glVertex3f(9,-6.5,-12);
            glVertex3f(9.5,-6.5,-11.8);
            glVertex3f(11,-6.5,-11.3);
            glVertex3f(11.5,-6.5,-11.5);
            glVertex3f(13,-6.5,-10.8);
            glVertex3f(13.5,-6.5,-10.8);
            glVertex3f(15,-6.5,-10);

        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(5,-5,-13.5);
            glVertex3f(7,-5,-13);
            glVertex3f(7,-9,-13);
            glVertex3f(5,-9,-13.5);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(3,-5,-14);
            glVertex3f(4.5,-5,-13.5);
            glVertex3f(4.5,-9,-13.5);
            glVertex3f(3,-9,-14);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(7.5,-5,-12.5);
            glVertex3f(9,-5,-12);
            glVertex3f(9,-9,-12);
            glVertex3f(7.5,-9,-12.5);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(9.5,-5,-11.8);
            glVertex3f(11,-5,-11.3);
            glVertex3f(11,-9,-11.3);
            glVertex3f(9.5,-9,-11.8);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(11.5,-5,-11.5);
            glVertex3f(13,-5,-10.8);
            glVertex3f(13,-9,-10.8);
            glVertex3f(11.5,-9,-11.5);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(13.5,-5,-10.8);
            glVertex3f(15,-5,-10);
            glVertex3f(15,-9,-10);
            glVertex3f(13.5,-9,-10.8);
        glEnd();

        glBegin(GL_QUADS);
            glColor4f(0.0,0.0,0.0,1);
            glVertex3f(9.5,-5,-11.8);
            glVertex3f(11,-5,-11.3);
            glVertex3f(11,-9,-11.3);
            glVertex3f(9.5,-9,-11.8);

            glVertex3f(5,-5,-13.5);
            glVertex3f(7,-5,-13);
            glVertex3f(7,-9,-13);
            glVertex3f(5,-9,-13.5);

            glVertex3f(7.5,-5,-12.5);
            glVertex3f(9,-5,-12);
            glVertex3f(9,-9,-12);
            glVertex3f(7.5,-9,-12.5);

            glVertex3f(11.5,-5,-11.5);
            glVertex3f(13,-5,-10.8);
            glVertex3f(13,-9,-10.8);
            glVertex3f(11.5,-9,-11.5);

            glVertex3f(13.5,-5,-10.8);
            glVertex3f(15,-5,-10);
            glVertex3f(15,-9,-10);
            glVertex3f(13.5,-9,-10.8);

            glVertex3f(3,-5,-14);
            glVertex3f(4.5,-5,-13.5);
            glVertex3f(4.5,-9,-13.5);
            glVertex3f(3,-9,-14);
        glEnd();

	//Jendela3
        glBegin(GL_LINES);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(27,-6.5,-9.5);
            glVertex3f(28.5,-6.5,-9.5);
            glVertex3f(29,-6.5,-9.5);
            glVertex3f(30.5,-6.5,-9.5);
            glVertex3f(31,-6.5,-9.5);
            glVertex3f(32.5,-6.5,-9.5);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(27,-5,-9.5);
            glVertex3f(28.5,-5,-9.5);
            glVertex3f(28.5,-9,-9.5);
            glVertex3f(27,-9,-9.5);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(29,-5,-9.5);
            glVertex3f(30.5,-5,-9.5);
            glVertex3f(30.5,-9,-9.5);
            glVertex3f(29,-9,-9.5);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(31,-5,-9.5);
            glVertex3f(32.5,-5,-9.5);
            glVertex3f(32.5,-9,-9.5);
            glVertex3f(31,-9,-9.5);
        glEnd();

        glBegin(GL_QUADS);
            glColor4f(0.0,0.0,0.0,1);
            glVertex3f(27,-5,-9.5);
            glVertex3f(28.5,-5,-9.5);
            glVertex3f(28.5,-9,-9.5);
            glVertex3f(27,-9,-9.5);

            glVertex3f(29,-5,-9.5);
            glVertex3f(30.5,-5,-9.5);
            glVertex3f(30.5,-9,-9.5);
            glVertex3f(29,-9,-9.5);

            glVertex3f(31,-5,-9.5);
            glVertex3f(32.5,-5,-9.5);
            glVertex3f(32.5,-9,-9.5);
            glVertex3f(31,-9,-9.5);
        glEnd();

        //pintu
        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-13.9,-15,-21.4);
            glVertex3f(-13.9,-12,-21.4);
            glVertex3f(-12.4,-12,-20.6);
            glVertex3f(-12.4,-15,-20.6);
        glEnd();
        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-9.5,-15,-19.2);
            glVertex3f(-9.5,-12,-19.2);
            glVertex3f(-8,-12,-18.5);
            glVertex3f(-8,-15,-18.5);
            glEnd();
        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-11.7,-15,-20.4);
            glVertex3f(-11.7,-12,-20.4);
            glVertex3f(-10.2,-12,-19.6);
            glVertex3f(-10.2,-15,-19.6);
            glEnd();
        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-16.1,-15,-22.5);
            glVertex3f(-16.1,-12,-22.5);
            glVertex3f(-14.6,-12,-21.7);
            glVertex3f(-14.6,-15,-21.7);
        glEnd();
        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(-18.3,-15,-23.7);
            glVertex3f(-18.3,-12,-23.7);
            glVertex3f(-16.8,-12,-22.9);
            glVertex3f(-16.8,-15,-22.9);
        glEnd();
        glBegin(GL_QUADS);
            glColor4f(0.0,0.0,0.0,1);
            glVertex3f(-8,-12,-18.5);
            glVertex3f(-9.5,-12,-19.2);
            glVertex3f(-9.5,-15,-19.2);
            glVertex3f(-8,-15,-18.5);

            glVertex3f(-10.2,-12,-19.6);
            glVertex3f(-11.7,-12,-20.4);
            glVertex3f(-11.7,-15,-20.4);
            glVertex3f(-10.2,-15,-19.6);

            glVertex3f(-12.4,-12,-20.6);
            glVertex3f(-13.9,-12,-21.4);
            glVertex3f(-13.9,-15,-21.4);
            glVertex3f(-12.4,-15,-20.6);

            glVertex3f(-14.6,-12,-21.7);
            glVertex3f(-16.1,-12,-22.5);
            glVertex3f(-16.1,-15,-22.5);
            glVertex3f(-14.6,-15,-21.7);

            glVertex3f(-16.8,-12,-22.9);
            glVertex3f(-18.3,-12,-23.7);
            glVertex3f(-18.3,-15,-23.7);
            glVertex3f(-16.8,-15,-22.9);
        glEnd();

   //Pintu tengah

        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(9.5,-12,-11.8);
            glVertex3f(11,-12,-11.3);
            glVertex3f(11,-15,-11.3);
            glVertex3f(9.5,-15,-11.8);
        glEnd();
        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(5,-12,-13.5);
            glVertex3f(7,-12,-13);
            glVertex3f(7,-15,-13);
            glVertex3f(5,-15,-13.5);
        glEnd();
        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
             glVertex3f(7.5,-12,-12.5);
            glVertex3f(9,-12,-12);
            glVertex3f(9,-15,-12);
            glVertex3f(7.5,-15,-12.5);
        glEnd();
        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
          glVertex3f(11.5,-12,-11.5);
            glVertex3f(13,-12,-10.8);
            glVertex3f(13,-15,-10.8);
            glVertex3f(11.5,-15,-11.5);
        glEnd();
        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(13.5,-12,-10.8);
            glVertex3f(15,-12,-10);
            glVertex3f(15,-15,-10);
            glVertex3f(13.5,-15,-10.8);
        glEnd();
        glBegin(GL_LINE_STRIP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
          glVertex3f(3,-12,-14);
            glVertex3f(4.5,-12,-13.5);
            glVertex3f(4.5,-15,-13.5);
            glVertex3f(3,-15,-14);
        glEnd();
            glBegin(GL_QUADS);
            glColor4f(0.0,0.0,0.0,1);
            glVertex3f(9.5,-12,-11.8);
            glVertex3f(11,-12,-11.3);
            glVertex3f(11,-15,-11.3);
            glVertex3f(9.5,-15,-11.8);

            glVertex3f(5,-12,-13.5);
            glVertex3f(7,-12,-13);
            glVertex3f(7,-15,-13);
            glVertex3f(5,-15,-13.5);

            glVertex3f(7.5,-12,-12.5);
            glVertex3f(9,-12,-12);
            glVertex3f(9,-15,-12);
            glVertex3f(7.5,-15,-12.5);

            glVertex3f(11.5,-12,-11.5);
            glVertex3f(13,-12,-10.8);
            glVertex3f(13,-15,-10.8);
            glVertex3f(11.5,-15,-11.5);

            glVertex3f(13.5,-12,-10.8);
            glVertex3f(15,-12,-10);
            glVertex3f(15,-15,-10);
            glVertex3f(13.5,-15,-10.8);

            glVertex3f(3,-12,-14);
            glVertex3f(4.5,-12,-13.5);
            glVertex3f(4.5,-15,-13.5);
            glVertex3f(3,-15,-14);
        glEnd();

        //Pintu 3
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(27,-12,-9.5);
            glVertex3f(28.5,-12,-9.5);
            glVertex3f(28.5,-15,-9.5);
            glVertex3f(27,-15,-9.5);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(29,-12,-9.5);
            glVertex3f(30.5,-12,-9.5);
            glVertex3f(30.5,-15,-9.5);
            glVertex3f(29,-15,-9.5);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor4f(115/255.f,135/255.f,146/255.f,1);
            glVertex3f(31,-12,-9.5);
            glVertex3f(32.5,-12,-9.5);
            glVertex3f(32.5,-15,-9.5);
            glVertex3f(31,-15,-9.5);
        glEnd();

        glBegin(GL_QUADS);
            glColor4f(0.0,0.0,0.0,1);
            glVertex3f(27,-12,-9.5);
            glVertex3f(28.5,-12,-9.5);
            glVertex3f(28.5,-15,-9.5);
            glVertex3f(27,-15,-9.5);

            glVertex3f(29,-12,-9.5);
            glVertex3f(30.5,-12,-9.5);
            glVertex3f(30.5,-15,-9.5);
            glVertex3f(29,-15,-9.5);

            glVertex3f(31,-12,-9.5);
            glVertex3f(32.5,-12,-9.5);
            glVertex3f(32.5,-15,-9.5);
            glVertex3f(31,-15,-9.5);
        glEnd();

        //bawahAlas

        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
            glVertex3f(-60,-15,10);
            glVertex3f(50,-15,10);
            glVertex3f(50,-15,-80);
            glVertex3f(-60,-15,-80);
        glEnd();

        glColor3f(0,0,0.1);
        glBegin(GL_POLYGON);
            glVertex3f(-60,-14.9,8);
            glVertex3f(50,-14.9,8);
            glVertex3f(50,-14.9,-2);
            glVertex3f(-60,-14.9,-2);
        glEnd();

        //lingkaran besar
        cylinder(8,100,-27,-28,-15,5,-13,5,255/255.f,236/255.f,134/255.f,1,230/255.f,213/255.f,201/255.f,1);
        cylinder(8,720,-27,-28,-15,5,-15,-13,204/255.f,204/255.f,204/255.f,0.9,230/255.f,213/255.f,201/255.f,1);//bawah
        cylinder(8,360,-27,-28,-15,5,-15,-13,255/255.f,236/255.f,134/255.f,1,230/255.f,213/255.f,201/255.f,1);

        lingkaran(8,100,-27,-28,-3,115/255.f,135/255.f,146/255.f,1);
        cylinder(5,100,-27,-28,6,5,5,6,255/255.f,236/255.f,134/255.f,1,115/255.f,135/255.f,146/255.f,0.8);

        //jendela lingkaran kecil
        cylinder(5,100,-3.5,-13,-9,0,-9,0,255/255.f,204/255.f,0/255.f,1,230/255.f,213/255.f,201/255.f,1);
        cylinder(0.3,100,-3.5,-8.5,-15,-9,-15,-9,204/255.f,204/255.f,204/255.f,1,230/255.f,213/255.f,201/255.f,1);//penyangga1
        cylinder(0.3,100,0,-10,-15,-9,-15,-9,204/255.f,204/255.f,204/255.f,1,230/255.f,213/255.f,201/255.f,1);//penyangga2
        cylinder(0.3,100,-7,-10,-15,-9,-15,-9,204/255.f,204/255.f,204/255.f,1,230/255.f,213/255.f,201/255.f,1);//penyangga3
        cylinder(0.3,100,-8,-13,-15,-9,-15,-9,204/255.f,204/255.f,204/255.f,1,230/255.f,213/255.f,201/255.f,1);//penyangga4
        //lingkaran kecil
        cylinder(3,100,-20,-45,-15,-3,-15,-3,255/255.f,236/255.f,134/255.f,1,230/255.f,213/255.f,201/255.f,1);

	//Jendela Lingkaran Kecil2
        cylinder(5,100,21,-8,-9,0,-9,0,255/255.f,204/255.f,0/255.f,1,230/255.f,213/255.f,201/255.f,1);
        cylinder(0.3,100,21,-3.5,-15,-9,-15,-9,204/255.f,204/255.f,204/255.f,1,230/255.f,213/255.f,201/255.f,1);//penyangga1
        cylinder(0.3,100,18,-5.5,-15,-9,-15,-9,204/255.f,204/255.f,204/255.f,1,230/255.f,213/255.f,201/255.f,1);//penyangga2
        cylinder(0.3,100,16.5,-7.5,-15,-9,-15,-9,204/255.f,204/255.f,204/255.f,1,230/255.f,213/255.f,201/255.f,1);//penyangga3
        cylinder(0.3,100,24,-4.5,-15,-9,-15,-9,204/255.f,204/255.f,204/255.f,1,230/255.f,213/255.f,201/255.f,1);//penyangga4
        cylinder(0.3,100,26,-8,-15,-9,-15,-9,204/255.f,204/255.f,204/255.f,1,230/255.f,213/255.f,201/255.f,1);//penyangga5

        //lingkaran2
        cylinder(5,100,-3,-15,-15,0,-13,0,255/255.f,236/255.f,134/255.f,1,230/255.f,213/255.f,201/255.f,1);
        cylinder(5,720,-3,-15,-15,0,-15,-13,204/255.f,204/255.f,204/255.f,0.9,230/255.f,213/255.f,201/255.f,1);
        cylinder(5,-720,-3,-15,-15,0,-15,-13,255/255.f,236/255.f,134/255.f,1,230/255.f,213/255.f,201/255.f,1);
        cylinder(3,100,-3,-30,-15,-3,-15,-3,255/255.f,236/255.f,134/255.f,1,230/255.f,213/255.f,201/255.f,1);

       //stengah lingkaran z
        cylinder(1,100,-3,-15,0,0.8,0.8,0,255/255.f,236/255.f,134/255.f,1,115/255.f,135/255.f,146/255.f,0.8);
        cylinder(5,100,21,-10,-15,0,-15,0,255/255.f,236/255.f,134/255.f,1,230/255.f,213/255.f,201/255.f,1);
        cylinder(3,100,21,-30,-15,-3,-15,-3,255/255.f,236/255.f,134/255.f,1,230/255.f,213/255.f,201/255.f,1);

	//atap
        persegi(-5,-3,-35,-1,-5,-60);
        persegi(15,-3,-40,26,-5,-55);
        persegi(30,-1,-40,38,-5,-55);
      	setengahlingkaran1(5,360,-3,-5,-55,-40,-55,-40,230/255.f,213/255.f,201/255.f,1,115/255.f,135/255.f,146/255.f,0.9);
        cylinder(1,100,21,-10,0,0.8,0.8,0,255/255.f,236/255.f,134/255.f,1,115/255.f,135/255.f,146/255.f,1);

        //lingkaran pojok
        cylinder(6,100,39,-10,-15,-4,-15,-4,255/255.f,236/255.f,134/255.f,1,230/255.f,213/255.f,201/255.f,1);

        //setengahlingkaran(5,100,-3,-15,-15,0,-15);
        //setengahlingkaran1(5,100,-3,-15,-15,0,-15);

        glColor3f(251/255.f,221/255.f,168/255.f);
        dindingmall(-27,-3,-36,-27,-65,-15);
        //
        //1
        dindingmall(-20,-3,-25,-7,-18,-15);

        dindingmall(-27,-3,-65,39,-65,-15);

        //3
        dindingmall(26,-3,-10,33,-10,-15);
        //2
        dindingmall(2,-3,-15,16,-10,-15);


        dindingmall(39,-3,-16,39,-65,-15);


        dindingmall(-27,-3,-65,-40,-65,-15);//DINDING BELAKANG TAMBAHAN

        dindingmall(-55,-3,-38,-40,-65,-15);//DINDING SAMPING

        dindingmall(-50,-3,-33,-27,-33,-15);//DINDING DEPAN

        //DINDING
        cylinder(5,100,-51,-38,-15,0,-15,0,255/255.f,236/255.f,134/255.f,1,230/255.f,213/255.f,201/255.f,1);

        //ATAP ada tonjolan dikit
        //setengahlingkaran1(-5,-360,-3,-3,-55,-40,-55,-40,255/255.f,206/255.f,43/255.f,1,222/255.f,222/255.f,222/255.f,2);


        //ATAP
        //setengahlingkaran1(-5,-360,-3,0,-55,-40,-55,-40,255/255.f,206/255.f,43/255.f,1,222/255.f,222/255.f,222/255.f,2);

        //tower
        setengahlingkaran2(4,360,-77,-32,-15,18,18,16,255/255.f,236/255.f,134/255.f,1,115/255.f,135/255.f,146/255.f,1);
        setengahlingkaran2(4,360,-77,-32,-15,16,16,-13,255/255.f,236/255.f,134/255.f,0.5,115/255.f,135/255.f,146/255.f,1);
        setengahlingkaran2(4,360,-77,-32,-15,-13,-13,-15,255/255.f,236/255.f,134/255.f,1,115/255.f,135/255.f,146/255.f,1);//kanan

        setengahlingkaran2(4,-360,-77,-32,-15,18,18,16,255/255.f,236/255.f,134/255.f,1,115/255.f,135/255.f,146/255.f,1);
        setengahlingkaran2(4,-360,-77,-32,-15,16,16,-13,255/255.f,236/255.f,134/255.f,0.5,115/255.f,135/255.f,146/255.f,1);
        setengahlingkaran2(4,-360,-77,-32,-15,-13,-13,-15,255/255.f,236/255.f,134/255.f,1,115/255.f,135/255.f,146/255.f,1);



        cylinder(1,100,-32,-78,18,23,23,18,255/255.f,206/255.f,43/255.f,1,222/255.f,222/255.f,222/255.f,1);
        cylinder(0.5,100,-32,-78,23,30,30,23,255/255.f,206/255.f,43/255.f,1,222/255.f,222/255.f,222/255.f,1);
        //atapmall kanan
 //lampu lalu lintas
        cylinder(0.3,100,-29,-2,-15,-9,-15,-9,204/255.f,204/255.f,204/255.f,1,230/255.f,213/255.f,201/255.f,1);

    //warna lampu

    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-30.0, -5.0, 0.0);
    glVertex3f(-30.0, -6, 0.0);
    glVertex3f(-28.0, -6, 0.0);
    glVertex3f(-28.0, -5.0, 0.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(242/255.f, 120/255.f, 12/255.f);
    glVertex3f(-30.0, -6.5, 0.0);
    glVertex3f(-30.0, -7.5, 0.0);
    glVertex3f(-28.0, -7.5, 0.0);
    glVertex3f(-28.0, -6.5, 0.0);

    glEnd();

      glBegin(GL_QUADS);
    glColor3f(52/255.f, 242/255.f, 27/255.f);
    glVertex3f(-30.0, -8.0, 0.0);
    glVertex3f(-30.0, -9, 0.0);
    glVertex3f(-28.0, -9, 0.0);
    glVertex3f(-28.0, -8.0, 0.0);

    glEnd();
     //depan
    glBegin(GL_QUADS);
      glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-30.0, -10.0, 0.0);
    glVertex3f(-30.0, -4, 0.0);
    glVertex3f(-28.0, -4, 0.0);
    glVertex3f(-28.0, -10.0, 0.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
  glColor3f(0.0, 0.0, 0.0);
  glVertex3f(-30.0, -10.0, -3.0);
    glVertex3f(-30.0, -4, -3.0);
    glVertex3f(-28.0, -4, -3.0);
    glVertex3f(-28.0, -10.0, -3.0);
    glEnd();


    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
   glVertex3f(-28.0, -4, 0.0);
    glVertex3f(-28.0, -10.0, 0.0);


    glVertex3f(-28.0, -10.0, -3.0);
    glVertex3f(-28.0, -4, -3.0);

    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-30.0, -10.0, 0.0);
    glVertex3f(-30.0, -4, 0.0);

    glVertex3f(-30.0, -4, -3.0);
    glVertex3f(-30.0, -10.0, -3.0);

    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-30.0, -4, 0.0);
    glVertex3f(-28.0, -4, 0.0);
    glVertex3f(-28.0, -4, -3.0);
    glVertex3f(-30.0, -4, -3.0);

    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-30.0, -10.0, 0.0);
    glVertex3f(-28.0, -10.0, 0.0);
    glVertex3f(-28.0, -10.0, -3.0);
    glVertex3f(-30.0, -10.0, -3.0);
    glEnd();

        //Atap Fixxxx
    glBegin(GL_POLYGON);
        glColor4f(115/255.f,135/255.f,146/255.f,1);
        glVertex3f(39,-5, -65);
        glVertex3f(39, -5, -10);
        glVertex3f(17, -5, -10);
        glVertex3f(-5, -5, -17.5);
        glVertex3f(-27, -5, -29);
        glVertex3f(-27, -5, -65);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(242/255.f,242/255.f,242/255.f,1);
        glVertex3f(39,-10, -65);
        glVertex3f(39, -10, -33);
        glVertex3f(17, -10, -33);
        glVertex3f(-3, -10, -33);
        glVertex3f(-17, -10, -45);
        glVertex3f(-17, -10, -65);
    glEnd();

    glColor4f(204/255.f,204/255.f,204/255.f,0.5);
    pagarmall(-17,-10,-65,-17,-45,-8);
    pagarmall(-17,-10,-45,-3,-33,-8);
    pagarmall(-3,-10,-33,39,-33,-8);

    glBegin(GL_POLYGON);
    glColor4f(242/255.f,242/255.f,242/255.f,1);
        glVertex3f(39, -10, -27);
        glVertex3f(-5, -10, -27);
        glVertex3f(-5, -10, -17);
        glVertex3f(21, -10, -10);
        glVertex3f(39, -10, -10);
    glEnd();
    glColor4f(204/255.f,204/255.f,204/255.f,0.5);
    pagarmall(39,-10,-27,-5,-27,-8);

    glBegin(GL_POLYGON);
    glColor4f(242/255.f,242/255.f,242/255.f,1);
        glVertex3f(-3, -10, -17);
        glVertex3f(-27, -10, -29);
        glVertex3f(-27, -10, -36);
        glVertex3f(-27, -10, -42);
        glVertex3f(-23, -10, -42);
        glVertex3f(-3, -10, -25);
    glEnd();
    glColor4f(204/255.f,204/255.f,204/255.f,0.5);
    pagarmall(-5,-10,-27,-23,-42,-8);


    glBegin(GL_POLYGON);
    glColor4f(242/255.f,242/255.f,242/255.f,1);
        glVertex3f(-23, -10, -65);
        glVertex3f(-27, -10, -65);
        glVertex3f(-27, -10, -28);
        glVertex3f(-23, -10, -42);
    glEnd();
    glColor4f(204/255.f,204/255.f,204/255.f,0.5);
    pagarmall(-23,-10,-65,-23,-42,-8);

     //FIREHYDRANT
  //depan
    glBegin(GL_QUADS);
      glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-40.0, -15.0, -40.0);
    glVertex3f(-40.0, -12, -40.0);
    glVertex3f(-38.0, -12, -40.0);
    glVertex3f(-38.0, -15.0, -40.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-40.0, -15.0, -42.0);
    glVertex3f(-40.0, -12, -42.0);
    glVertex3f(-38.0, -12, -42.0);
    glVertex3f(-38.0, -15.0, -42.0);
    glEnd();


    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-38.0, -12, -40.0);
    glVertex3f(-38.0, -15.0, -40.0);
    glVertex3f(-38.0, -15.0, -42.0);
       glVertex3f(-38.0, -12, -42.0);


    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-40.0, -15.0, -40.0);
    glVertex3f(-40.0, -12, -40.0);


    glVertex3f(-40.0, -12, -42.0);
    glVertex3f(-40.0, -15.0, -42.0);

    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-40.0, -12, -40.0);
    glVertex3f(-38.0, -12, -40.0);
    glVertex3f(-38.0, -12, -42.0);
    glVertex3f(-40.0, -12, -42.0);

    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-40.0, -15.0, -40.0);
    glVertex3f(-38.0, -15.0, -40.0);

    glVertex3f(-38.0, -15.0, -42.0);
        glVertex3f(-40.0, -15.0, -42.0);
    glEnd();





        //dindingmall(-27,-3,-,39,-65,-3);
        //dindingmall(39,-3,-15,39,-65,-15);


	glBegin(GL_POLYGON);
        glColor4f(115/255.f,135/255.f,146/255.f,1);
        glVertex3f(-25,-5, -65);
        glVertex3f(-25, -5, -33);
        glVertex3f(-50, -5, -33);
        glVertex3f(-55, -5, -38);
        glVertex3f(-40,- 5 ,-65);
    glEnd();


    glBegin(GL_POLYGON);
    glColor4f(242/255.f,242/255.f,242/255.f,1);
        glVertex3f(-25,-10, -65);
        glVertex3f(-25, -10, -33);
        glVertex3f(-50, -10, -33);
        glVertex3f(-55, -10, -38);
        glVertex3f(-40,- 10 ,-65);
    glEnd();

    //lemari
    glBegin(GL_QUADS);
    glColor4f(112/255.f, 112/255.f, 110/255.f, 1);
        glVertex3f(39,-10,-60);
        glVertex3f(37,-10,-60);
        glVertex3f(37,-10,-52);
        glVertex3f(39,-10,-52);

        glVertex3f(39,-10,-60);
        glVertex3f(37,-10,-60);
        glVertex3f(37,-5,-60);
        glVertex3f(39,-5,-60);

        glVertex3f(39,-10,-52);
        glVertex3f(37,-10,-52);
        glVertex3f(37,-5,-52);
        glVertex3f(39,-5,-52);

        glVertex3f(39,-5,-60);
        glVertex3f(37,-5,-60);
        glVertex3f(37,-5,-52);
        glVertex3f(39,-5,-52);

        glVertex3f(39,-5,-60);
        glVertex3f(39,-10,-60);
        glVertex3f(39,-10,-52);
        glVertex3f(39,-5,-52);

        glVertex3f(37,-5,-60);
        glVertex3f(37,-10,-60);
        glVertex3f(37,-10,-52);
        glVertex3f(37,-5,-52);
    glEnd();
    glBegin(GL_QUADS);
        glColor4f(0.0,0.0,0.0,1);
        glVertex3f(37,-5.5,-59);
        glColor4f(235/255.f, 235/255.f, 235/255.f,1);
        glVertex3f(37,-9.5,-59);
        glColor4f(0.0,0.0,0.0,1);
        glVertex3f(37,-9.5,-53);
        glColor4f(235/255.f, 235/255.f, 235/255.f,1);
        glVertex3f(37,-5.5,-53);
    glEnd();

    //lemari2
    glBegin(GL_QUADS);
    glColor4f(112/255.f, 112/255.f, 110/255.f, 1);
        glVertex3f(39,-10,-48);//bawah
        glVertex3f(37,-10,-48);
        glVertex3f(37,-10,-40);
        glVertex3f(39,-10,-40);

        glVertex3f(39,-10,-48);//samping
        glVertex3f(37,-10,-48);
        glVertex3f(37,-5,-48);
        glVertex3f(39,-5,-48);

        glVertex3f(39,-10,-40);//samping
        glVertex3f(37,-10,-40);
        glVertex3f(37,-5,-40);
        glVertex3f(39,-5,-40);

        glVertex3f(39,-5,-48);//atas
        glVertex3f(37,-5,-48);
        glVertex3f(37,-5,-40);
        glVertex3f(39,-5,-40);

        glVertex3f(39,-5,-48);//belakang
        glVertex3f(39,-10,-48);
        glVertex3f(39,-10,-40);
        glVertex3f(39,-5,-40);

        glVertex3f(37,-5,-48);//depan
        glVertex3f(37,-10,-48);
        glVertex3f(37,-10,-40);
        glVertex3f(37,-5,-40);
    glEnd();
    glBegin(GL_QUADS);
        glColor4f(0.0,0.0,0.0,1);
        glVertex3f(37,-5.5,-47);
        glColor4f(235/255.f, 235/255.f, 235/255.f,1);
        glVertex3f(37,-9.5,-47);
        glColor4f(0.0,0.0,0.0,1);
        glVertex3f(37,-9.5,-41);
        glColor4f(235/255.f, 235/255.f, 235/255.f,1);
        glVertex3f(37,-5.5,-41);
    glEnd();

    //etalase
    glBegin(GL_QUADS);
    glColor4f(138/255.f, 60/255.f, 4/255.f, 1);
        glVertex3f(-14,-10,-54);//bawah
        glVertex3f(-12,-10,-54);
        glVertex3f(-12,-10,-46);
        glVertex3f(-14,-10,-46);

        glVertex3f(-14,-7,-54);//atas
        glVertex3f(-13,-7,-54);
        glVertex3f(-13,-7,-46);
        glVertex3f(-14,-7,-46);

        glVertex3f(-14,-7,-54);//belakang
        glVertex3f(-14,-10,-54);
        glVertex3f(-14,-10,-46);
        glVertex3f(-14,-7,-46);

        glVertex3f(-12,-9,-54);//depan
        glVertex3f(-12,-10,-54);
        glVertex3f(-12,-10,-46);
        glVertex3f(-12,-9,-46);
        glVertex3f(-12,-9,-54);//depan
        glVertex3f(-13,-7,-54);
        glVertex3f(-13,-7,-46);
        glVertex3f(-12,-9,-46);
    glEnd();
    glBegin(GL_POLYGON);
    glColor4f(138/255.f, 68/255.f, 0/255.f, 1);
        glVertex3f(-14,-10,-54);//samping
        glVertex3f(-12,-10,-54);
        glVertex3f(-12,-9,-54);
        glVertex3f(-13,-7,-54);
        glVertex3f(-14,-7,-54);

        glVertex3f(-14,-10,-46);//samping
        glVertex3f(-12,-10,-46);
        glVertex3f(-12,-9,-46);
        glVertex3f(-13,-7,-46);
        glVertex3f(-14,-7,-46);
    glEnd();
    glBegin(GL_QUADS);
        glColor4f(0.0,0.0,0.0,1);
        glVertex3f(-12,-9,-53);
        glColor4f(235/255.f, 235/255.f, 235/255.f,1);
        glVertex3f(-13,-7,-53);
        glColor4f(0.0,0.0,0.0,1);
        glVertex3f(-13,-7,-47);
        glColor4f(235/255.f, 235/255.f, 235/255.f,1);
        glVertex3f(-12,-9,-47);
    glEnd();


    //kursi
    persegi(-3,-10,-37,2,-9,-36.5);
    persegi(-3,-8.2,-35,2,-8.2,-39);
    persegi(10,-10,-37,15,-9,-36.5);
    persegi(10,-8.2,-35,15,-8.2,-39);
    persegi(23,-10,-37,28,-9,-36.5);
    persegi(23,-8.2,-35,28,-8.2,-39);
    kursi(-3,-9,-33,2,-8,-35,-10,-32.5);
    kursi(10,-9,-33,15,-8,-35,-10,-32.5);
    kursi(23,-9,-33,28,-8,-35,-10,-32.5);

//
    for(int a = 0; a <= 3; a++){
    for (int b = 0; b <= 3; b++){
        glPushMatrix();
            glTranslatef(a * 12.0f,0.0f,0.0f);
            gedung();
        glPopMatrix();
            }
    }

            /*
    1=a,    3=b,    0=c,    2=d,    8=e,    5=f

    1,3,0
    2,3,8
    2,5,8
    1,5,0

    glVertex3f(a,b,c);
    glVertex3f(d,b,e);
    glVertex3f(d,f,e);
    glVertex3f(a,f,c);

    */
    glPushMatrix();
    mobilPolisiMinecraft();
    Idle();
    glPopMatrix();
       glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y)
{

     switch(key)
    {
    case 'w':
    case 'W':
        zz += 3.0;

        break;
    case 'd':
    case 'D':
        xx +=3.0;
        break;
    case 's':
    case 'S':
        zz +=-3.0;
        break;

    case 'a':
    case 'A':
        xx+=-3.0;
        break;
    case '7':
           yy+=3.0;
        break;
    case '9':
          yy+=-3.0;
        break;
    case '2':
           xrot+=2.0;
        break;
    case '8':
             xrot+=-2.0;
        break;
    case '6':
           yrot+=2.0;
        break;
    case '4':
             yrot+=-2.0;
        break;

    case '1':
            zrot +=2.0;
        break;
    case '3':
             zrot +=-2.0;
        break;
    case '5':
        if(is_depth)
        {
            is_depth =0;
            glDisable(GL_DEPTH_TEST);
        } else{
            is_depth=1;
            glEnable(GL_DEPTH_TEST);

        }

    }

    tampil();

}

void gedung(void){

 glPushMatrix();
            glColor4f(230/255.f,213/255.f,201/255.f,0.95);
            glTranslatef(-10.0f, -10.0f, -75.0f);
            glutSolidCube(9.0);
            glTranslatef(0.0f, 5.0f, 0.0f);
            glutSolidCube(9.0);
            glTranslatef(0.0f, 5.0f, 0.0f);
            glutSolidCube(9.0);
            glTranslatef(0.0f, 4.5f, 0.0f);
            glutSolidCube(9.0);
            glTranslatef(0.0f, 4.0f, 0.0f);
            glutSolidCube(8.0);
            glTranslatef(0.0f, 3.5f, 0.0f);
            glutSolidCube(7.0);
            glTranslatef(0.0f, 2.0f, 0.0f);
            glutSolidCube(5.0);
    glPopMatrix();



}

void idle(){

    if(!mousDown){

        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();

}

void mouse(int button, int state, int x, int y){

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

        mousDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;

    }
    else{
        mousDown = false;
    }

}

void mouseMotion(int x, int y){

    if(mousDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }

}


void dindingmall(float a, float b, float c, float d, float e, float f){

    /*
    1=a,    3=b,    0=c,    2=d,    8=e,    5=f

    1,3,0
    2,3,8
    2,5,8
    1,5,0
    */
    glBegin(GL_POLYGON);
        glVertex3f(a,b,c);
        glVertex3f(d,b,e);
        glVertex3f(d,f,e);
        glVertex3f(a,f,c);
    glEnd();

}

void pagarmall(float a, float b, float c, float d, float e, float f){

    /*
    1=a,    3=b,    0=c,    2=d,    8=e,    5=f

    1,3,0
    2,3,8
    2,5,8
    1,5,0
    */
    glBegin(GL_POLYGON);
        glVertex3f(a,b,c);
        glVertex3f(d,b,e);
        glVertex3f(d,f,e);
        glVertex3f(a,f,c);
    glEnd();

}

void atapmall(float a, float b, float c, float d, float e, float f){
    glBegin(GL_QUADS);
        glVertex3f(a, b, c);
        glVertex3f(d, b, e);
        glVertex3f(d, f, e);
        glVertex3f(a, f, c);
    glEnd();
}


void cylinder(float radius,float jumlah_titik,float x_tengah,float z_tengah,float alas,float tutupatas,float tinggi,float triangle_tinggi, float a, float b, float c, float d, float a1, float b1, float c1, float d1){

    glColor4f(a,b,c,d);
    glBegin(GL_TRIANGLE_STRIP);
    for(int a = 0; a <= 360; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glVertex3f(x, tinggi, z);
        glVertex3f(x,triangle_tinggi,z);
    }
    glEnd();

    glColor4f(a1,b1,c1,d1);
    glBegin(GL_POLYGON);
        for(int a = 0; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glVertex3f(x, tutupatas, z);
    }
    glEnd();

    glBegin(GL_POLYGON);
        for(int a = triangle_tinggi; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glVertex3f(x,alas, z);
    }
    glEnd();
}


void setengahlingkaran(float radius,float jumlah_titik,float y_tengah,float z_tengah,float alas,float tutupatas,float tinggi,float triangle_tinggi, float a, float b, float c, float d, float a1, float b1, float c1, float d1){

    glColor4f(a,b,c,d);
    glBegin(GL_TRIANGLE_STRIP);
    for(int a = 0; a <= 90; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float y = y_tengah + radius * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glVertex3f(tinggi, y, z);
        glVertex3f(triangle_tinggi,y,z);
    }
    glEnd();

    glColor4f(a1,b1,c1,d1);
    glBegin(GL_POLYGON);
        for(int a = 0; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float y = y_tengah + radius * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glVertex3f(tutupatas, y, z);
    }
    glEnd();

    glBegin(GL_POLYGON);
        for(int a = 0; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float y = y_tengah + radius * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glVertex3f(alas, y, z);
    }
    glEnd();
}


void setengahlingkaran1(float radius,float jumlah_titik,float x_tengah,float y_tengah,float alas,float tutupatas,float tinggi,float triangle_tinggi, float a, float b, float c, float d, float a1, float b1, float c1, float d1){

    glColor4f(a,b,c,d);
    glBegin(GL_TRIANGLE_STRIP);
    for(int a = 0; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x, y, tinggi);
        glVertex3f(x,y,triangle_tinggi);
    }
    glEnd();

    glColor4f(a1,b1,c1,d1);
    glBegin(GL_POLYGON);
        for(int a = 0; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x, y, tutupatas);
    }
    glEnd();

    glBegin(GL_POLYGON);
        for(int a = 0; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex3f(x, y, alas);
    }
    glEnd();
}

void setengahlingkaran2(float radius,float jumlah_titik,float y_tengah,float z_tengah,float alas,float tutupatas,float tinggi,float triangle_tinggi, float a, float b, float c, float d, float a1, float b1, float c1, float d1){

    glColor4f(a,b,c,d);
    glBegin(GL_TRIANGLE_STRIP);
    for(int a = 0; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float y = y_tengah + radius-7 * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glVertex3f(z, tinggi, y);
        glVertex3f(z,triangle_tinggi,y);
    }
    glEnd();

    glColor4f(a1,b1,c1,d1);
    glBegin(GL_POLYGON);
        for(int a = 0; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float y = y_tengah + radius-7 * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glVertex3f(z, tutupatas, y);
    }
    glEnd();

    glBegin(GL_POLYGON);
        for(int a = 0; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float y = y_tengah + radius-7 * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glVertex3f(z, alas, y);
    }
    glEnd();
}

void lingkaran(float radius,float jumlah_titik,float x_tengah,float z_tengah, float tutup_atas, float a1, float b1, float c1, float d1){

    glColor4f(a1,b1,c1,d1);
    glBegin(GL_POLYGON);
        for(int a = 0; a <= 180; a++){
        float sudut = a * (2 * PI/jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glVertex3f(x, tutup_atas, z);
    }
    glEnd();
}


void kursi(float x,float y,float z,float x1,float y1,float z1,float y2,float z2){

    glColor4f(37/255.f,150/255.f,190/255.f,1);
    glLineWidth(3);
    //alas
    glBegin(GL_POLYGON);
        glVertex3f(x,y,z);
        glVertex3f(x1,y,z);
        glVertex3f(x1,y,z1);
        glVertex3f(x,y,z1);
    glEnd();
    //sandaran
    glBegin(GL_POLYGON);
        glVertex3f(x,y,z);
        glVertex3f(x1,y,z);
        glVertex3f(x1,y1,z2);
        glVertex3f(x,y1,z2);
    glEnd();
    //kakikursi
    glBegin(GL_LINES);
        //depan G & H
        glVertex3f(x,y,z1);
        glVertex3f(x,y2,z1);

        glVertex3f(x1,y,z1);
        glVertex3f(x1,y2,z1);

        //belakang I & J
        glVertex3f(x1,y,z);
        glVertex3f(x1,y2,z);

        glVertex3f(x,y,z);
        glVertex3f(x,y2,z);

        glVertex3f(x,y2,z);
        glVertex3f(x1,y,z);

        glVertex3f(x1,y2,z);
        glVertex3f(x,y,z);

    glEnd();


}
void persegi(float x, float y, float z, float x1, float y1, float z1){


    glColor4f(230/255.f,213/255.f,201/255.f,1);
    glBegin(GL_POLYGON);
        glVertex3f(x,y,z);
        glVertex3f(x1,y,z);
        glVertex3f(x1,y,z1);
        glVertex3f(x,y,z1);
    glEnd();
        //garis2(125,-160,-160,        145,-160,-160,         145,-160,-200,              125,-160, -200, -180);

	 glBegin(GL_POLYGON);
        glVertex3f(x,y,z);
        glVertex3f(x,y1,z);
        glVertex3f(x1,y1,z);
        glVertex3f(x1,y,z);
    glEnd();


    //2
    glBegin(GL_POLYGON);
        glVertex3f(x1,y,z);
        glVertex3f(x1,y1,z);
        glVertex3f(x1,y1,z1);
        glVertex3f(x1,y,z1);
        //garis2(125,-160,-160,        145,-160,-160,         145,-160,-200,              125,-160, -200, -180);
    glEnd();


    //3
    glBegin(GL_POLYGON);
        glVertex3f(x1,y,z1);
        glVertex3f(x1,y1,z1);
        glVertex3f(x,y1,z1);
        glVertex3f(x,y,z1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(x,y,z1);
    glVertex3f(x,y1,z1);
    glVertex3f(x,y1,z);
    glVertex3f(x,y,z);
    glEnd();
        //garis2(125,-160,-160,        145,-160,-160,         145,-160,-200,              125,-160, -200, -180);

}




void ukuran(int lebar,int tinggi)
{

    if(tinggi == 0) tinggi =1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(20.0,lebar/tinggi,5.0,700.0);
    glTranslatef(0.0,-5.0,-300.0);
    glMatrixMode(GL_MODELVIEW);
}
