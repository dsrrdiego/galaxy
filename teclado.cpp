bool tecl[20];
extern const int NAVES;
extern Astro nave[NAVES];

void specialKeys(int key, int x, int y){
    switch (key){
        case GLUT_KEY_RIGHT: 
            if (col<4){
                col++;
                lista.menuApuntaA(col,fila);
            }
            break;
        
        case GLUT_KEY_LEFT: tecl[2]=true;
            if (col>0){
                col--;
                lista.menuApuntaA(col,fila);
            }
            break;
        
        case GLUT_KEY_UP: 
            if (fila>1){
             fila--;
                lista.menuApuntaA(col,fila);
            }
            break;
        
        case GLUT_KEY_DOWN: 
            if (fila<7){
                fila++;
                lista.menuApuntaA(col,fila);
            }
            break;
   
        case GLUT_KEY_F1:
			lista.eje(0);
            break;
        case GLUT_KEY_F2:
			lista.eje(1);
            break;
        case GLUT_KEY_F3:
            lista.eje(2);
            break;
        case GLUT_KEY_F4:
            lista.eje(3);
            break;
        case GLUT_KEY_F5:
            lista.eje(4);
            break;
        case GLUT_KEY_F6:
            lista.eje(5);
            break;
        case GLUT_KEY_F7:
            lista.eje(6);
            break;
        case GLUT_KEY_F8:
            lista.eje(7);
            break;
        case GLUT_KEY_F9:
            lista.eje(10);
            break;
        case GLUT_KEY_F10:
            lista.eje(9);
            break;
        case GLUT_KEY_F11:
            lista.eje(10);
            break;
        case GLUT_KEY_F12:
            lista.eje(11);
            break;
    }
}

static void key(unsigned char key, int x, int y){
    switch (key){
        case 27 :
            exit(0);
            break;
        
        case ' ':
            lista.activar(fila);
            break;
        
        case 'z':
            zoom-=0.1;
            break;
        case 'x':
            zoom+=0.1;
            break;
            
        case '+':
            if (menuPuntero!=NULL) *menuPuntero=*menuPuntero+1;
            break;
        case '-':
            if (input!=0){
                input*=-1;
            }else{
                if (menuPuntero!=NULL)  *menuPuntero=*menuPuntero-1;
            }
            break;

        case 'r': //reset
            lista.resetear(fila);
            break;
        
        
        case '0':
            input=input*10;
            break;
        case '1':
            input=input*10+1;
            break;
        case '2':
            input=input*10+2;
            break;
        case '3':
            input=input*10+3;
            break;
        case '4':
            input=input*10+4;
            break;
        case '5':
            input=input*10+5;
            break;
        case '6':
            input=input*10+6;
            break;
        case '7':
            input=input*10+7;
            break;
        case '8':
            input=input*10+8;
            break;
        case '9':
            input=input*10+9;
            break;

        case 8:
            if (input!=0){
                input/=10;
            }
            break;
        case 13:
            *menuPuntero=input;
            input=0;
            break;

        
        ///controles nave
        case 'a':
            nave[0].proyeccionX-=1;
            break;

        case 'd':
            nave[0].proyeccionX+=1;
            break;

        
        case 'w':
            nave[0].proyeccionY+=1;
            break;

        case 's':
            nave[0].proyeccionY-=1;
            break;

    }


   glutPostRedisplay();
}


