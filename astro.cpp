using namespace std;
class Astro;
extern void texto(int a, Astro *ast, bool activo);
class Astro{
	public:
	Astro(){};
	Astro(float xx, float yy, string nom,float col1,float col2,float col3, float mas){
		masa=mas;
		x=xx;
		y=yy;
		
		nombre=nom;
		c1=col1;
		c2=col2;
		c3=col3;
	}
	string nombre;
	float masa=100000;
	float c1,c2,c3;
	float x=0;
	float y=0;
	float x2=0;
	float y2=0;
	float inerciaX=0.0;
	float inerciaY=0.0;
	float proyeccionX=0.0;
	float proyeccionY=0.0;
	float radio=5;
	void dibujar(){
		if (nombre=="centro"){
			glPushMatrix();
			// if ((-*scrollX+x)*zoom > 100 || (-*scrollX+x)*zoom <-100) zoom-=0.01;
			
			glColor3f(c1,c2,c3);
			glTranslated((-*scrollX+x)*zoom,(-*scrollY+y)*zoom,-4);
		//      glRotated(a,0,0,1);
			glutSolidCube(3*zoom);
    	glPopMatrix();
		}else{

		
			glPushMatrix();
				if ((-*scrollX+x)*zoom > 100 || (-*scrollX+x)*zoom <-100) zoom-=0.01;
				if ((-*scrollY-y)*zoom < -100 ) {
					
				gluLookAt(35,25,20,0,0,0,0,1,0);
					}
				if ((-*scrollY-y)*zoom >100 ) {
					
				gluLookAt(0,1,1,0,0,-5,1,0,1);
					}


				// if ((-*scrollY-y)*zoom < 100 ) zoom-=0.01;//gluLookAt(0,-1,0,0,0,-5,0,0,1);

				glColor3f(c1,c2,c3);
				glTranslated((-*scrollX+x)*zoom,(-*scrollY+y)*zoom,-4);
			//      glRotated(a,0,0,1);
				glutSolidSphere(radio*zoom,13,13);
			glPopMatrix();
		}
	}



	void textear(int i, bool activo){
		texto(i,this, activo);
	}

	void dibNave(){
		glPushMatrix();
			if ((-*scrollX+x)*zoom > 100 || (-*scrollX+x)*zoom <-100) zoom-=0.01;
			
			glColor3f(c1,c2,c3);
			glTranslated((-*scrollX+x)*zoom,(-*scrollY+y)*zoom,-4);
			glutSolidSphere(1.5*zoom,5,5);
    	glPopMatrix();
    	
	}

	void proyectar(){
		// lista.calcular(this);
	}
	Astro *copiar(){
		Astro *copia=new Astro(x,y,nombre,c1,c2, c3,masa);
		copia->x2=0;
		copia->y2=0;
		copia->inerciaX=0.0;
		copia->inerciaY=0.0;
		copia->proyeccionX=0.0;
		copia->proyeccionY=0.0;
		copia->radio=1;



		return copia;
	}
};
