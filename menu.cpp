void menuDibujar(){
    GLfloat xIni=-105;
    GLfloat yIni=67;
    GLfloat z=0;
    GLfloat ancho=8;
    GLfloat alto=3;

    GLfloat x=xIni+col*ancho;
    GLfloat y=yIni-fila*alto;

     glBegin(GL_QUADS);
        glColor3f(1,1.9,1.9);
        glVertex3f(x,y, z);
        glVertex3f(x,y-alto,z);
        glVertex3f(x+ancho,y-alto,z);
        glVertex3f(x+ancho,y,z);
    glEnd();
}