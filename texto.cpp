static char label[100];

void inline drawString (char *s){
   unsigned int i;
   for (i=0; i<strlen(s); i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, s[i]);
}


void texto(int fila, Astro *ast, bool activo){
  int x=ast->x;
  int y=ast->y;
  int masa=ast->masa;
  int inerX= ast->inerciaX*1000;
  int inerY= ast->inerciaY*1000;
  int proyX=ast->proyeccionX;
  int proyY=ast->proyeccionY;
  int datos[7]={x,y,masa, inerX, inerY, proyX,proyY};
  glColor3f(1, 0, 0.1);
  int nDeCols=5;
  if (ast->nombre=="nave") nDeCols=7;
  if (activo){ 
    for (int z=0;z<nDeCols;z++){
        sprintf(label,"%d", datos[z]);
        glRasterPos2f(-101+z*8, 62-(fila*3));
        drawString (label);
    }
  }
}

void pantalla(){
    glColor3f(1, 0, 0);
    sprintf(label,"NOMBRE               X            Y         Masa       inerX      inerY  Proyeccion X  Y");
    glRasterPos2f(-115, 65);
    drawString (label);

    sprintf(label,"hipoSol");
    glRasterPos2f(-115, 62);
    drawString (label);

    sprintf(label,"Sol");
    glRasterPos2f(-115, 59);
    drawString (label);

    sprintf(label,"tierra");
    glRasterPos2f(-115, 56);
    drawString (label);

    sprintf(label,"luna");
    glRasterPos2f(-115, 53);
    drawString (label);

    sprintf(label,"jupiter");
    glRasterPos2f(-115, 50);
    drawString (label);
      
    sprintf(label,"pluton");
    glRasterPos2f(-115, 47);
    drawString (label);
      
    sprintf(label,"____________________________________________");
    glRasterPos2f(-115, 46.35);
    drawString (label);
    
    sprintf(label,"Nave");
    glRasterPos2f(-115, 44);
    drawString (label);
    
    if (input){
        sprintf(label,"INPUT:     %d ", input);
        glRasterPos2f(-115, 62-(8*3));
        drawString (label);
    }
  }
