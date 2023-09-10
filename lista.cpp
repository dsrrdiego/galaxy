using namespace std;
int numero=0;
class Lista{
	public:
	
	Lista *nodo=NULL;
	Astro *miAstro=NULL;
	int miNumero=0;
	bool activo=true;

	void agregar(Astro *ast){
		if (miAstro==NULL){
			miAstro=ast;
			numero++;
			miNumero=numero;
		}else{
			if (nodo==NULL) nodo=new Lista;
			nodo->agregar(ast);
		}
	}
	
	void dibujar(){
		if (activo) miAstro->dibujar();
		if (nodo!=NULL) nodo->dibujar();
	}

	void influenciadoPor(Astro *ast){
		if (activo){
			float difX = miAstro->x - ast->x;
			float difY = miAstro->y - ast->y;
			// cout <<"\n"<<ast->nombre<<" con "<< miAstro->nombre<<"\n";

			float distancia=sqrt(difX*difX+difY*difY);
			// cout<<"dist: "<<distancia<<"\n";

			float gravedad=0.0;
			if (distancia!=0) gravedad=(ast->masa* miAstro->masa)/(distancia*distancia);
			// cout<<"g "<<gravedad<<"\n";
			
			float relacion=gravedad/distancia;
			// cout<<"relacion "<<relacion <<"\n";

			ast->inerciaX+=difX*relacion;
			ast->inerciaY+=difY*relacion;
			
			miAstro->inerciaX-=difX*relacion;
			miAstro->inerciaY-=difY*relacion;
			
			ast->x+=ast->inerciaX;
			ast->y+=ast->inerciaY;

			miAstro->x+=miAstro->inerciaX;
			miAstro->y+=miAstro->inerciaY;
		}
		if (nodo!=NULL ) nodo->influenciadoPor(ast);
	}	

	void calculo(){
			if (nodo!=NULL) {
				if (activo) nodo->influenciadoPor(miAstro);
				nodo->calculo();
			}
	}
	
	void eje(int x){
		if (x==0){
			scrollX=&centro.x;
			scrollY=&centro.y;
		}else{
			if (x==miNumero){
				scrollX=&miAstro->x;
				scrollY=&miAstro->y;
			}else{
				if (nodo!=NULL) nodo->eje(x);
			}
		}
	}

	void textear(int i){
		miAstro->textear(i,activo);
		i++;
		if (nodo!=NULL) nodo->textear(i);
	}

	void activar(int n){
		if (n==miNumero){
			if (activo){
				activo=false;
			}else{
				activo=true;
			}
		}else{
			if (nodo!=NULL) nodo->activar(n);
		}
	}

	void menuApuntaA(int co, int fil){
		if (fil==miNumero){
			menuPuntero=&zoom;
			if (activo){
				switch (co){
					case 0:
						menuPuntero=&miAstro->x;
						break;
					case 1:
						menuPuntero=&miAstro->y;
						
						break;
					case 2:
						menuPuntero=&miAstro->masa;
						break;
					case 3:
						menuPuntero=&miAstro->inerciaX;
						break;
					case 4:
						menuPuntero=&miAstro->inerciaY;
						break;
				}
			}
		}else{
			if (nodo!=NULL) nodo->menuApuntaA(co,fil);
		}
	}

	void resetear(int fila){
		if (fila==miNumero){
			miAstro->x=0;
			miAstro->y=0;
			miAstro->inerciaX=0;
			miAstro->inerciaY=0;
			miAstro->masa=0;
		}else{
			if (nodo!=NULL) nodo->resetear(fila);
		}
	}

		void proyectarNave(Astro *nave){
		if (activo){
			float difX = miAstro->x - nave->x;
			float difY = miAstro->y - nave->y;
			// cout <<"\n"<<ast->nombre<<" con "<< miAstro->nombre<<"\n";

			float distancia=sqrt(difX*difX+difY*difY);
			// cout<<"dist: "<<distancia<<"\n";

			// float gravedad=0.0;
			// if (distancia!=0) gravedad=(ast->masa* miAstro->masa)/(distancia*distancia);
			// cout<<"g "<<gravedad<<"\n";
			
			float relacion=distancia/0.3*miAstro->masa;
			// cout<<"relacion "<<relacion <<"\n";
			if (relacion!=0){
			nave->proyeccionX+=difX/relacion;
			nave->proyeccionY+=difY/relacion;
			nave->x+=nave->proyeccionX;
			nave->y+=nave->proyeccionY;
			// if (nave->nombre=="nave2") cout << nave->x;
			}


		}
		if (nodo!=NULL ) nodo->proyectarNave(nave);
	}	

	Lista *copiar(){
		Lista *copia=new Lista;
		copia->miAstro=miAstro->copiar();
		if (nodo!=NULL) copia->nodo=nodo->copiar();	
		return copia;
	}

};
