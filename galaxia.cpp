/*
g++ -Wall -o  galaxia galaxia.cpp -lglut -lGL -lGLU 
*/

//#include <windows.h>

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#define pi 3.14156295
GLfloat *scrollX;
GLfloat *scrollY;
GLfloat zoom;
int fila=1;
int col=0;
float * menuPuntero=NULL;
int input=0;

#include "astro.cpp"
Astro centro(0,0,"centro",0.1,0.1,0.1,0);
const int NAVES=100;
Astro nave[NAVES]={{30,0,"nave",1,0,0,0}};
Astro nave2[NAVES]={{30,0,"nave2",1,1,0,0}};

#include "lista.cpp"
#include "texto.cpp"

Lista lista;
#include "teclado.cpp"
#include "menu.cpp"

static void resize(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(90.0,1.0,1.0,3000);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0,-20,65,0,0,-5,0,0,1);
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

static void idle(void){
    glutPostRedisplay();
}

Lista *listaCopia;
static void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(90.0,1.0,1.0,3000);
    glMatrixMode(GL_MODELVIEW);
    
    glBegin(GL_QUADS);
        glColor4f(10,1,0,0.5);
        glVertex3f(-100*zoom,+100*zoom,-6);
        glVertex3f(-100*zoom,-100*zoom,-6);
        glVertex3f(+100*zoom,-100*zoom,-6);
        glVertex3f(100*zoom,+100*zoom,-6);
    glEnd();


    centro.dibujar();
    lista.calculo();
    lista.dibujar();

    nave[0].c1=1;
    nave[0].dibNave();
    nave2[0]=nave[0];
    nave[0].c1=0;
    glBegin(GL_LINE_STRIP);
        glColor3f(0,1,0);
        glVertex3f((-*scrollX+nave[0].x)*zoom, (-*scrollY+nave[0].y)*zoom,-5);
        for (int n=1;n<NAVES;n++){
            nave[n]=nave[n-1];
            lista.proyectarNave(&nave[n]);
            // nave[n].dibNave();
            glVertex3f((-*scrollX+nave[n].x)*zoom,(-*scrollY+nave[n].y)*zoom,-5);
        }
    glEnd();

//    listaCopia->dibujar();

    listaCopia=lista.copiar();
    // nave2[0].dibNave();
    // glBegin(GL_POLYGON);
        // glColor3f(0,1,0);
        // glVertex3f((-*scrollX+nave2[0].x)*zoom, (-*scrollY+nave2[0].y)*zoom,-5);
        for (int n=1;n<NAVES;n++){
            listaCopia->dibujar();
            nave2[n]=nave2[n-1];
            listaCopia->proyectarNave(&nave2[n]);
            listaCopia->calculo();
            // nave[n].dibNave();
            // glVertex3f((-*scrollX+nave2[n].x)*zoom,(-*scrollY+nave2[n].y)*zoom,-5);
            nave2[n].dibNave();
        }
    // glEnd();


//    listaCopia.miAstro->x-=1;
    // cout <<listaCopia.miAstro->nombre<<listaCopia.miAstro->x<<"\n";

    //2d

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glOrtho(-120,120,-45,45,-10,170);
    glMatrixMode(GL_MODELVIEW);

    menuDibujar();
    pantalla();
    lista.textear(0);
    // nave[0].textear(7,true);

    // lista2.nodo->miAstro->x=88;
    // lista2.nodo->nodo->miAstro->x=88;
    // lista2.nodo->nodo->nodo->miAstro->x=88;
    // lista2.nodo->nodo->nodo->nodo->miAstro->x=88;
    
    
    
    
    glutSwapBuffers();
    // cout <<"\n-----------\n";
}

void creacion(){
}

int main(int argc, char *argv[]){
    // nave[0].inerciaX=-9;
    zoom=1;
    Astro hipoSol(0,0,"hipoSol",0.1,0.9,0.4,0.000000);
    Astro sol(-50,50,"Sol",90,90,-3,1.000000);
    Astro tierra(50,-50,"tierra",0,0,1,1.000000);
    Astro luna(66,-43,"luna",1,1,1,0.0000000);
    Astro jupiter(80,60,"Jupiter",0,1,0,0.000000);
    Astro pluton(80,5,"Pluton",0.5,0.1,0.1,0.000000);

    sol.inerciaX=0.045;
    tierra.inerciaX=-0.045;
    lista.agregar(&hipoSol);
    lista.agregar(&sol);
    lista.agregar(&tierra);
    lista.agregar(&luna);
    lista.agregar(&jupiter);
    lista.agregar(&pluton);
    lista.agregar(&nave[0]);

    
    // lista.activo=false; //hipo
    //tierra activa;
    lista.nodo->nodo->nodo->activo=false;
    lista.nodo->nodo->nodo->nodo->activo=false;
    lista.nodo->nodo->nodo->nodo->nodo->activo=false;
    

    menuPuntero=&hipoSol.x;
    lista.eje(2);
    scrollX=&centro.x;
    scrollY=&centro.y;

    ////////////////////
    glutInit(&argc, argv);
    glutInitWindowSize(1640,1480);
    glutInitWindowPosition(1,1);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    //glutFullScreen();
    glutCreateWindow("GALAXIA");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);
    glutKeyboardFunc(key);
    glutSpecialFunc(specialKeys);
    // glutKeyboardUpFunc(keyup);
    // glutSpecialUpFunc(keyupS);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
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

    glutMainLoop();

    return EXIT_SUCCESS;
}