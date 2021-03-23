

#include "aux.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;

    ejes.changeAxisSize( 5000 );
    
    esCubo=true;
    esTetraedro=true;
    esCono=true;
    esCilindro=true;
    esPly=true;
    esEsfera=true;
    esRevolucion=true;
    
    dibujado=DIFERIDO;
    solido = true;
    lineas = false;
    puntos = false;
    ajedrez = false;
    vertapas = true;
    luces = false;
    animacionAuto = true;
    luzAnimada = false;

    luz0= true;
    luz1= true;

    practica = 19;
    gradoLibertad=0;
    velAnimacion0 = 0.5;
    velAnimacion1 = 0.5;
    velAnimacion2 = 0.5;
    velAnimacion3 = 0.5;
    velAnimacion4 = 0.01;
    animacionLuz = 0;

   camaraActual = 0;
   estadoRaton = MOVIENDO_CAMARA_FIRSTPERSON;

   // P1
   cubo= new Cubo (40);
   tetraedro = new Tetraedro(50);
   // P2
   objetoply = new ObjPLY("plys/ant.ply");
      // Revolucion
      cilindro = new Cilindro(4,32,40,25,true,true);
      cono = new Cono(3,32,40,25,true, true);
      esfera = new Esfera(50,32,30, true, true);
      revolucion = new PlyRev("plys/peon.ply",32,true, true);
   // P3
      luzD = new LuzDireccional(Tupla2f(0.0,0.0),GL_LIGHT0,Tupla4f(0.0,1.0,0.0,1.0),Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(1.0,1.0,1.0,1.0));
      luzP = new LuzPosicional(Tupla3f(0.0,100.0,100.0),GL_LIGHT1,Tupla4f(0.0,0.0,0.0,1.0),Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(1.0,1.0,1.0,1.0));
      posluz = new Esfera(16,16,4,true,true);
      peon1 = new PlyRev("plys/peon.ply",32,true, true);
      peon2 = new PlyRev("plys/peon.ply",32,true, true);
      m1 = new Material(Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(0.0,0.0,0.0,0.0),Tupla4f(0.0,0.0,0.0,0.0),10);
      m2 = new Material(Tupla4f(0.0,0.0,0.0,1.0),Tupla4f(0.0,0.0,0.0,1.0),Tupla4f(0.0,0.0,0.0,0.0),10);
      peon1->setMaterial(*m1);
      peon2->setMaterial(*m2);

   //P4
      pingu = new Pingu();

   //P5
      cuadro = new Cuadro(1000, "suelo.jpg");
      skybox = new Cubo(1000, "fondoFINAL.jpg"); 

   //P6
      Camara cam0(Tupla3f(0.0, -200.0, 500.0), Tupla3f(0.0,-300.0,0.0), Tupla3f(0.0,1.0,0.0), 0, -600, 600, Front_plane, Back_plane, 600.0, -600.0);
      Camara cam1(Tupla3f(0.0,200.0,-490.0), Tupla3f(0.0,-100.0,0.0),Tupla3f(0.0,1.0,0.0),1,-45,45,Front_plane,Back_plane,45.0,-45.0);
      Camara cam2(Tupla3f(300.0,400.0,400.0), Tupla3f(0.0,0.0,0.0),Tupla3f(0.0,1.0,0.0),1,-80,80,Front_plane,Back_plane,80.0,-80.0);
      
      vCamaras.push_back(cam0);
      vCamaras.push_back(cam1);
      vCamaras.push_back(cam2);

      //COLOR DE LOS QUE SE PUEDEN SELECCIONAR
      cubo->setColor(seleccionable);
      tetraedro->setColor(seleccionable);
      cilindro->setColor(seleccionable);
      cono->setColor(seleccionable);
      esfera->setColor(seleccionable);
      revolucion->setColor(seleccionable);
      objetoply->setColor(seleccionable);

      //COLOR NO SELECCIONABLE

      peon1->setColor(noSeleccionable);
      peon2->setColor(noSeleccionable);

      //MATERIALES
      matSelecionable = new Material(Tupla4f(0.4,0.5,0.4,1.0),Tupla4f(0.04,0.7,0.04,1.0),Tupla4f(0.0,0.05,0.0,1.0),10);
      matSeleccionado = new Material(Tupla4f(0.5,0.5,0.4,1.0),Tupla4f(0.7,0.7,0.04,1.0),Tupla4f(0.05,0.05,0.05,1.0),10);

      cubo->setMaterial(*matSelecionable);
      tetraedro->setMaterial(*matSelecionable);
      cilindro->setMaterial(*matSelecionable);
      cono->setMaterial(*matSelecionable);
      esfera->setMaterial(*matSelecionable);
      revolucion->setMaterial(*matSelecionable);
      objetoply->setMaterial(*matSelecionable);

      //PRACTICA FINAL
      
      taburete = new Taburete();
      conoFin = new Cono(3,32,40,25,true, true);
      tetraFin = new Tetraedro(50);
      plyFin = new ObjPLY("plys/ant.ply");

      conoFin->setColor(Tupla3f(1.0,0.5,0.0));
      tetraFin->setColor(Tupla3f(0.9255,0.8863,0.7765));
      plyFin->setColor(Tupla3f(0.1098,0.051,0.0078));

      naranja = new Material(Tupla4f(0.7038,0.27048,0.0828,1.0),Tupla4f(0.256777,0.137622,0.086014,1.0),Tupla4f(0.19125,0.0735,0.0225,1.0),12.8);
      arena = new Material(Tupla4f(0.75164,0.60648,0.22648,1.0),Tupla4f(0.628281,0.555802,0.366065,1.0),Tupla4f(0.24725,0.1995,0.0745,1.0),51.2);

      conoFin->setMaterial(*naranja);
      tetraFin->setMaterial(*arena);
      plyFin->setMaterial(*m2);

      sol = new LuzPosicional(Tupla3f(-300.0,300.0,300.0),GL_LIGHT2,Tupla4f(0.0,0.0,0.0,1.0),Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(1.0,1.0,1.0,1.0));
      posSol = new Esfera(128,128,100,true,true);

      matSol = new Material(Tupla4f(0.780392,0.56627,0.113725,1.0),Tupla4f(0.992157,0.941176,0.807843,1.0),Tupla4f(0.329412,0.223529,0.027451,1.0),27.8974);
      posSol->setColor(Tupla3f(1.0,0.8,0.2));
      posSol->setMaterial(*matSol);
}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer
   glDisable( GL_TEXTURE_2D);

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );

   

   printf("\n\n\n\nPracticas Miguel Medina\nOPCIONES:\n 'O' --- Seleccion de Objeto\n 'V' --- Seleccion de Modo de Visualizacion\n 'D' --- Seleccion de Modo de Dibujado\n 'X' --- Seleccion de Escena\n 'M' --- Modo Animacion Manual\n 'A' --- Modo Animacion Automatica\n 'C' --- Modo Seleccion de Camara\n 'Q' --- Atras/Salir\n");
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
   glDisable(GL_LIGHTING);
   ejes.draw();

  ////////////////////////////////////////
 //            PRACTICA 3              //
////////////////////////////////////////

   if (practica == 3 || practica == 4 || practica == 5){
      if (luces){
         luzD->activar();
         if (luz1){
            glPushMatrix();
            glTranslatef(animacionLuz,100,100);
            posluz->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
            luzP->activar();
            glPopMatrix();
         }
      }
   }


if (practica ==3){

   // CUBO
   if (esCubo){
      glPushMatrix();
         glTranslatef(-180,0,-100);
         if (lineas)
            cubo->draw(dibujado,GL_LINE,ajedrez,vertapas,luces);
         if (puntos)
            cubo->draw(dibujado,GL_POINT,ajedrez,vertapas,luces);
         if (solido)
            cubo->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         if (ajedrez)
            cubo->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
      glPopMatrix();
   }
   

   // TETRAEDRO
   if (esTetraedro){
      glPushMatrix();
         glTranslatef(-120,0,-100);
         if (lineas)
            tetraedro->draw(dibujado,GL_LINE,ajedrez,vertapas,luces);
         if (puntos)
            tetraedro->draw(dibujado,GL_POINT,ajedrez,vertapas,luces);
         if (solido)
            tetraedro->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         if (ajedrez)
            tetraedro->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
      glPopMatrix();
   }

   // CILINDRO
   if (esCilindro){
      glPushMatrix();
         glTranslatef(-60,0,-100);
         if (lineas)
            cilindro->draw(dibujado,GL_LINE,ajedrez,vertapas,luces);
         if (puntos)
            cilindro->draw(dibujado,GL_POINT,ajedrez,vertapas,luces);
         if (solido)
            cilindro->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         if (ajedrez)
            cilindro->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);  
      glPopMatrix();
   }

   // CONO
   if (esCono){
      glPushMatrix();
         glTranslatef(0,0,-100);
         if (lineas)
            cono->draw(dibujado,GL_LINE,ajedrez,vertapas,luces);
         if (puntos)
            cono->draw(dibujado,GL_POINT,ajedrez,vertapas,luces);
         if (solido)
            cono->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         if (ajedrez)
            cono->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
      glPopMatrix();
   }
   // ESFERA
   if (esEsfera){
      glPushMatrix();
         glTranslatef(60,0,-100);
         if (lineas)
            esfera->draw(dibujado,GL_LINE,ajedrez,vertapas,luces);
         if (puntos)
            esfera->draw(dibujado,GL_POINT,ajedrez,vertapas,luces);
         if (solido)
            esfera->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         if (ajedrez)
            esfera->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
      glPopMatrix();
   }

   // REVOLUCION
   if (esRevolucion){
      glPushMatrix();
         glTranslatef(120,0,-100);
         glScalef(25.0,25.0,25.0);
         if (lineas)
            revolucion->draw(dibujado,GL_LINE,ajedrez,vertapas,luces);
         if (puntos)
            revolucion->draw(dibujado,GL_POINT,ajedrez,vertapas,luces);
         if (solido)
            revolucion->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         if (ajedrez)
            revolucion->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
      glPopMatrix();
   }

   // OBJETO PLY
   if (esPly){
      glPushMatrix();
         glTranslatef(180,0,-100);
         glScalef(2.0,2.0,2.0);
         if (lineas)
            objetoply->draw(dibujado,GL_LINE,ajedrez,vertapas,luces);
         if (puntos)
            objetoply->draw(dibujado,GL_POINT,ajedrez,vertapas,luces);
         if (solido)
            objetoply->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         if (ajedrez)
            objetoply->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
      glPopMatrix();
   }

      

      // PEON 1
      glPushMatrix();
         glTranslatef(30,0,20);
         glScalef(25.0,25.0,25.0);
         peon1->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
      glPopMatrix();

      //PEON 2
      glPushMatrix();
         glTranslatef(-30,0,20);
         glScalef(25.0,25.0,25.0);
         peon2->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
      glPopMatrix();
   
   

}

   
  ////////////////////////////////////////
 //            PRACTICA 4              //
////////////////////////////////////////

if (practica == 4 || practica == 5){
   glPushMatrix();
      if (lineas)
         pingu->draw(dibujado,GL_LINE,ajedrez,vertapas,luces);
      if (puntos)
         pingu->draw(dibujado,GL_POINT,ajedrez,vertapas,luces);
      if (solido)
         pingu->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
      if (ajedrez)
         pingu->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
   glPopMatrix();
}

  ////////////////////////////////////////
 //            PRACTICA 5/6            //
////////////////////////////////////////

if (practica == 5){
   glPushMatrix();
         glPushMatrix();
            cuadro->setColor(Tupla3f(1.0,1.0,1.0));
            glTranslatef(0,-490,0);
            glRotatef(-90,1.0,0.0,0.0);
            cuadro->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         glPopMatrix();

         glPushMatrix();
            skybox->setColor(Tupla3f(1.0,1.0,1.0));
            glRotatef(180,1.0,0,0);
            skybox->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         glPopMatrix();
         
   glPopMatrix();
}

  ////////////////////////////////////////
 //          PRACTICA FINAL            //
////////////////////////////////////////

if(practica==19){

   glPushMatrix();
         //Suelo
         glPushMatrix();
            cuadro->setColor(Tupla3f(1.0,1.0,1.0));
            glTranslatef(0,-499,0);
            glRotatef(-90,1.0,0.0,0.0);
            cuadro->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         glPopMatrix();

         //Skybox
         glPushMatrix();
            skybox->setColor(Tupla3f(1.0,1.0,1.0));
            glRotatef(180,1.0,0,0);
            skybox->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         glPopMatrix();

         //Pingu
         glPushMatrix();
            glTranslatef(0.0,-385.0,-350.0);
            glScalef(1.5,1.5,1.5);
            if (lineas)
               pingu->draw(dibujado,GL_LINE,ajedrez,vertapas,luces);
            if (puntos)
               pingu->draw(dibujado,GL_POINT,ajedrez,vertapas,luces);
            if (solido)
               pingu->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
            if (ajedrez)
               pingu->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
         glPopMatrix();

         //TABURETES
         glPushMatrix();

            glTranslatef(0.0,0.0,200.0);

            glPushMatrix();
               glTranslatef(-200.0, -499.0, 0.0);
               glScalef(10.0,10.0,10.0);
               taburete->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
            glPopMatrix();

            glPushMatrix();
               glTranslatef(0.0, -499.0, 0.0);
               glScalef(10.0,10.0,10.0);
               taburete->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
            glPopMatrix();

            glPushMatrix();
               glTranslatef(200.0, -499.0, 0.0);
               glScalef(10.0,10.0,10.0);
               taburete->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
            glPopMatrix();
            
         glPopMatrix();

         //PUBLICO
         glPushMatrix();

            glTranslatef(0.0,0.0,200.0);

            glPushMatrix();
               glTranslatef(-200.0, -349.0, 0.0);
               glScalef(2.0,2.0,2.0);
               conoFin->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
            glPopMatrix();

            glPushMatrix();
               glTranslatef(0.0, -379.0, 0.0);
               glScalef(4.0,4.0,4.0);
               glRotatef(180.0,0.0,1.0,0.0);
               plyFin->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
            glPopMatrix();

            glPushMatrix();
               glTranslatef(200.0, -359.0, 0.0);
               glScalef(2.0,2.0,2.0);
               tetraFin->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
            glPopMatrix();
            
         glPopMatrix();

         //SOL
         glPushMatrix();
         sol->activar();
            glTranslatef(-400,400,400);
            posSol->draw(dibujado,GL_FILL,ajedrez,vertapas,luces);
            
         glPopMatrix();
         
   glPopMatrix();

}


}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;
   switch( toupper(tecla) )
   {
      case 'Q' :
         if (modoMenu!=NADA){
            modoMenu=NADA;
            printf("\n\n\n\nPracticas Miguel Medina\nOPCIONES:\n 'O' --- Seleccion de Objeto\n 'V' --- Seleccion de Modo de Visualizacion\n 'D' --- Seleccion de Modo de Dibujado\n 'X' --- Seleccion de Escena\n 'M' --- Modo Animacion Manual\n 'A' --- Modo Animacion Automatica\n 'C' --- Modo Seleccion de Camara\n 'Q' --- Atras/Salir\n");
         }
         else {
            salir=true ;
         }
         break ;
      case 'O' :
         // ESTAMOS EN MODO SELECCION DE OBJETO
         modoMenu=SELOBJETO; 
         printf("Modo Seleccion de Objeto\nOPCIONES:\n 'C' --- Cubo \n 'T' --- Tetraedro \n 'L' --- Cilindro \n 'N' --- Cono \n 'E' --- Esfera \n 'Y' --- Objeto PLY \n 'R' --- Objeto Revolucion \n 'Q' --- Salir \n");
         break ;
      case 'V' :
         // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
         modoMenu=SELVISUALIZACION;
         printf("Modo Seleccion de Modo de Visualizacion\nOPCIONES ACTIVAR o DESACTIVAR:\n 'P' --- Modo Puntos\n 'L' --- Modo Lineas\n 'S' --- Modo Solido\n 'A' --- Modo Ajedrez\n 'T' --- Ver/No ver Tapas\n 'I' --- Iluminaciones\n '3' --- Sombreado Suave\n '4' --- Sombreado Plano\n 'Q' --- Salir\n");
         break ;
      case 'D' :
         // ESTAMOS EN MODO SELECCION DE DIBUJADO
         modoMenu=SELDIBUJADO;
         printf("Modo Seleccion de Modo de Dibujado\nOPCIONES:\n '1' --- Modo inmediato\n '2' --- Modo Diferido\n 'Q' --- Salir\n");
         break ;
         // COMPLETAR con los diferentes opciones de teclado
      case 'X' :
         // ESTAMOS EN MODO SELECCION DE ESCENA
         modoMenu=SELESCENA; 
         printf("Modo Seleccion de Practica\nOPCIONES:\n '3' --- Practica 3/ Seleccion de Objeto P6 \n '4' --- Practica 4\n '5' --- Practica 5/6\n 'F' --- Practica FINAL\n 'Q' --- Salir \n");
         break ;
      case 'M' :
         // ESTAMOS EN MODO ANIMACION MANUAL
         modoMenu=SELMANUAL; 
         animacionAuto=false;
         pingu->restablecer();
         printf("Modo Animacion Manual\nOPCIONES:\n '0' --- Grado Libertad 0 \n '1' --- Grado Libertad 1 \n '2' --- Grado Libertad 2 \n '3' --- Grado Libertad 3\n '4' --- Grado Libertad 4 \n 'T' --- Todos los Grados \n '+' --- Aumentar Valor Grado Libertad \n '-' --- Disminuir Valor Grado Libertad \n 'Q' --- Salir \n");
         break ;
      case 'A':
         // ESTAMOS EN MODO ANIMACION AUTOMATICA
         modoMenu=SELAUTO;
         animacionAuto = true;
         printf("Modo Animacion Automatico\nOPCIONES: \n '0' --- Grado Libertad 0 \n '1' --- Grado Libertad 1 \n '2' --- Grado Libertad 2 \n '3' --- Grado Libertad 3\n '4' --- Grado Libertad 4 \n 'T' --- Todos los Grados \n '+' --- Aumentar Velocidad de Animacion \n '-' --- Disminuir Velocidad de Animacion \n 'Q' --- Salir \n");
         
         if (modoMenu==SELVISUALIZACION)
            ajedrez = !ajedrez;
         if (modoMenu==SELILUMINACION)
            anguloActual = 'a';
         break;
      case 'C':
         // ESTAMOS EN MODO CAMARA
         modoMenu=SELCAM;
         printf("Modo Seleccion de Camara\nOPCIONES: \n '0-2' --- Elegir Camaras \n 'Q' --- Salir \n");
         
         if (modoMenu==SELOBJETO){
            esCubo = !esCubo;
         }
         break;
      case 'T':
         if (modoMenu==SELOBJETO)
            esTetraedro =!esTetraedro;
         if (modoMenu==SELVISUALIZACION)
            vertapas = !vertapas;
         if (modoMenu==SELMANUAL || modoMenu==SELAUTO){
            gradoLibertad = 99;
         }
         break;
      case 'E':
         if (modoMenu==SELOBJETO)
            esEsfera =!esEsfera;
         break;
      case 'Y':
         if (modoMenu==SELOBJETO)
            esPly =!esPly;
         break;
      case 'N':
         if (modoMenu==SELOBJETO)
            esCono =!esCono;
         break;
      case 'R':
         if (modoMenu==SELOBJETO)
            esRevolucion =!esRevolucion;
         break;
      case 'P':
         if (modoMenu==SELVISUALIZACION){
            puntos = !puntos;
            ajedrez = false;
            luces = false;
         }
         if (modoMenu==SELILUMINACION){
            luzAnimada = !luzAnimada;
         }
         break;
      case 'L':
         if (modoMenu==SELVISUALIZACION){
            lineas = !lineas;
            ajedrez = false;
            luces = false;
         }
         if (modoMenu==SELOBJETO)
            esCilindro =!esCilindro;
         break;
      case 'S':
         if (modoMenu==SELVISUALIZACION)
            solido = !solido;
            ajedrez = false;
            luces = false;
         break;
      case '0':
         if (modoMenu==SELILUMINACION){
            if(luz0){
               luzD->apagar();
            }
            else{
               luzD->encender();
            }
            luz0 = !luz0;
         }
         if (modoMenu==SELMANUAL || modoMenu==SELAUTO){
            gradoLibertad = 0;
         }
         if (modoMenu==SELCAM){
            camaraActual = 0;
            change_observer();
            change_projection(1.0);
         }
         break;
      case '1':
         if (modoMenu==SELDIBUJADO)
            dibujado=INMEDIATO;
         if (modoMenu==SELILUMINACION){
            if(luz1){
               luzP->apagar();
            }
            else{
               luzP->encender();
            }
            luz1 = !luz1;
         }
         if (modoMenu==SELMANUAL || modoMenu==SELAUTO){
            gradoLibertad = 1;
         }
         if (modoMenu==SELCAM){
            camaraActual = 1;
            change_observer();
            change_projection(1.0);
         }
         break;
      case '2':
         if (modoMenu==SELDIBUJADO)
            dibujado=DIFERIDO;
         if (modoMenu==SELMANUAL || modoMenu==SELAUTO){
            gradoLibertad = 2;
         }
         if (modoMenu==SELCAM){
            camaraActual = 2;
            change_observer();
            change_projection(1.0);
         }
         break;
      case '3':
         if (modoMenu==SELVISUALIZACION){
            luces = true;
            glShadeModel(GL_SMOOTH);
         }
         if (modoMenu==SELESCENA)
            practica= 3;
         if (modoMenu==SELMANUAL || modoMenu==SELAUTO){
            gradoLibertad = 3;
         }         
         break;
      case '4':
         if (modoMenu==SELVISUALIZACION){
            luces = true;
            glShadeModel(GL_FLAT);
         }
         if (modoMenu==SELESCENA)
            practica= 4;
         if (modoMenu==SELMANUAL || modoMenu==SELAUTO){
            gradoLibertad = 4;
         }
         break;
      case '5':
         if (modoMenu==SELESCENA)
            practica= 5;
         break;
      case 'I':
         if (modoMenu==SELVISUALIZACION || modoMenu==SELILUMINACION){
            luces = !luces;
            if (practica == 19){
               sol->encender();
               //luzD->encender();
            }
            else{
               luzD->encender();
               luzP->encender();
            }
            modoMenu=SELILUMINACION;
            printf("Modo de Iluminacion\nOPCIONES:\n '0-1' --- Activar/Des Luces \n 'A' --- Modo variacion Alpha\n 'B' --- Modo variacion Beta\n '>' --- Aumenta Angulo\n '<' --- Decrementa Angulo\n 'P' --- Animacion Luz Puntual \n 'Q' --- Salir \n");
            }
         break;
      case 'B':
         if (modoMenu==SELILUMINACION){
            anguloActual = 'b';
         std::cout<<anguloActual<<std::endl;
         }
         break;
      case 'F':
         if (modoMenu==SELESCENA){
            practica = 19;
         }
         break;
      case '>':
         if (modoMenu==SELILUMINACION){
            if (anguloActual=='a')
               luzD->variarAnguloAlpha(5);
            if (anguloActual=='b')
               luzD->variarAnguloBeta(5);
         }
         break;
      case '<':
         if (modoMenu==SELILUMINACION){
            if (anguloActual=='a')
               luzD->variarAnguloAlpha(-5);
            if (anguloActual=='b')
               luzD->variarAnguloBeta(-5);
         }
         break;
      case '+':
         if (modoMenu==SELMANUAL){
            switch (gradoLibertad){
               case 0:
                  pingu->girarhombroD(10);
                  break;
               case 1:
                  pingu->girarhombroI(10);
                  break;
               case 2:
                  pingu->girarCodoD(10);
                  break;
               case 3:
                  pingu->girarCodoI(10);
                  break;
               case 4:
                  pingu->animarTrompeta(0.5);
                  break;
               case 99:
                  pingu->girarhombroD(10);
                  pingu->girarhombroI(10);
                  pingu->girarCodoD(10);
                  pingu->girarCodoI(10);
                  pingu->animarTrompeta(0.5);
                  break;
            }
         }
         if (modoMenu==SELAUTO){
            switch (gradoLibertad){
               case 0:
                  velAnimacion0 += 0.05;
                  if (velAnimacion0>10.0)
                     velAnimacion0=10.0;
                  break;
               case 1:
                  velAnimacion1 += 0.05;
                  if (velAnimacion1>10.0)
                     velAnimacion1=10.0;
                  break;
               case 2:
                  velAnimacion2 += 0.05;
                  if (velAnimacion2>10.0)
                     velAnimacion2=10.0;
                  break;
               case 3:
                  velAnimacion3 += 0.05;
                  if (velAnimacion3>10.0)
                     velAnimacion3=10.0;
                  break;
               case 4:
                  velAnimacion4 += 0.001;
                  if (velAnimacion4>0.3)
                     velAnimacion4=0.3;
                  break;
               case 99:
                  velAnimacion0 += 0.05;
                  if (velAnimacion0>10.0)
                     velAnimacion0=10.0;
                  velAnimacion1 += 0.05;
                  if (velAnimacion1>10.0)
                     velAnimacion1=10.0;
                  velAnimacion2 += 0.05;
                  if (velAnimacion2>10.0)
                     velAnimacion2=10.0;
                  velAnimacion3 += 0.05;
                  if (velAnimacion3>10.0)
                     velAnimacion3=10.0;
                  velAnimacion4 += 0.001;
                  if (velAnimacion4>0.3)
                     velAnimacion4=0.3;
                  break;
            }
         }
         break;
      case '-':
         if (modoMenu==SELMANUAL){
            switch (gradoLibertad){
               case 0:
                  pingu->girarhombroD(-10);
                  break;
               case 1:
                  pingu->girarhombroI(-10);
                  break;
               case 2:
                  pingu->girarCodoD(-10);
                  break;
               case 3:
                  pingu->girarCodoI(-10);
                  break;
               case 4:
                  pingu->animarTrompeta(-0.5);
                  break;
               case 99:
                  pingu->girarhombroD(-10);
                  pingu->girarhombroI(-10);
                  pingu->girarCodoD(-10);
                  pingu->girarCodoI(-10);
                  pingu->animarTrompeta(-0.5);
                  break;
            }
         }
         if (modoMenu==SELAUTO){
            switch (gradoLibertad){
               case 0:
                  velAnimacion0 -= 0.01;
                  if (velAnimacion0<0.01)
                     velAnimacion0=0.01;
                  break;
               case 1:
                  velAnimacion1 -= 0.01;
                  if (velAnimacion1<0.01)
                     velAnimacion1=0.01;
                  break;
               case 2:
                  velAnimacion2 -= 0.01;
                  if (velAnimacion2<0.01)
                     velAnimacion2=0.01;
                  break;
               case 3:
                  velAnimacion3 -= 0.01;
                  if (velAnimacion3<0.01)
                     velAnimacion3=0.01;
                  break;
               case 4:
                  velAnimacion4 -= 0.0005;
                  if (velAnimacion4<0.0005)
                     velAnimacion4=0.0005;
                  break;
               case 99:
                  velAnimacion0 -= 0.01;
                  if (velAnimacion0<0.01)
                     velAnimacion0=0.01;
                  velAnimacion1 -= 0.01;
                  if (velAnimacion1<0.01)
                     velAnimacion1=0.01;
                  velAnimacion2 -= 0.01;
                  if (velAnimacion2<0.01)
                     velAnimacion2=0.01;
                  velAnimacion3 -= 0.01;
                  if (velAnimacion3<0.01)
                     velAnimacion3=0.01;
                  velAnimacion4 -= 0.0005;
                  if (velAnimacion4<0.0005)
                     velAnimacion4=0.0005;
                  break;
            }
         }
         break;
   }
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         vCamaras[camaraActual].rotarYExaminar(-2.0 * pi/180.0);
         break;
	   case GLUT_KEY_RIGHT:
         vCamaras[camaraActual].rotarYExaminar(2.0 * pi/180.0);
         break;
	   case GLUT_KEY_UP:
         vCamaras[camaraActual].rotarXExaminar(2.0 * pi/180.0);
         break;
	   case GLUT_KEY_DOWN:
         vCamaras[camaraActual].rotarXExaminar(-2.0 * pi/180.0);
         break;
	   case GLUT_KEY_PAGE_UP:
         vCamaras[camaraActual].zoom(1/1.2);
         change_projection(1.0);
         break;
	   case GLUT_KEY_PAGE_DOWN:
         vCamaras[camaraActual].zoom(1.2);
         change_projection(1.0);
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   vCamaras[camaraActual].setProyeccion();   
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   vCamaras[camaraActual].setObserver();
}
void Escena::animarModeloJerarquico(){
   if (animacionAuto){
      pingu->girarHombros(velAnimacion0,velAnimacion1);
      pingu->girarCodos(velAnimacion2, velAnimacion3);
      if (pingu->getSiguiente()) 
         pingu->tocarTrompeta(velAnimacion4);
   }
   
}

void Escena::animarLuz(){
   if (luzAnimada == true){
      animacionLuz += 0.5;
      if (animacionLuz>= 300)
         animacionLuz = -300;
   }
   else{
      animacionLuz = 0;
   }
}

void Escena::clickRaton(int boton, int estado, int x, int y){
   if (boton == GLUT_RIGHT_BUTTON){
      if (estado == GLUT_DOWN){
         xant = x;
         yant = y;
         //estadoRaton = MOVIENDO_CAMARA_FIRSTPERSON;
      }
   }
   if (boton == GLUT_LEFT_BUTTON)
      if (estado == GLUT_DOWN){
         dibujaSeleccion();
         analizaColor(x,y);
      }
}

void Escena::ratonMovido(int x, int y){
   
   if(estadoRaton == CAMARA_EN_OBJETO){
      vCamaras[camaraActual].rotarXExaminar(-0.25*(y-yant)*pi/180.0);
      vCamaras[camaraActual].rotarYExaminar(-0.25*(x-xant)*pi/180.0);
      xant=x;
      yant=y;
   }
   else{
      vCamaras[camaraActual].girar(x-xant, y-yant);
      xant=x;
      yant=y;
   }
}

void Escena::dibujaSeleccion(){

   change_observer();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glDisable(GL_LIGHTING);

   glDisable(GL_DITHER);


   glPushMatrix();
      cubo->setColor(Tupla3f(0.1,0.0,0.0));
      glTranslatef(-180,0,-100);   
      cubo->draw(dibujado,GL_FILL,false,true,false);
   glPopMatrix();

   glPushMatrix();
      tetraedro->setColor(Tupla3f(0.2,0.0,0.0));
      glTranslatef(-120,0,-100);  
      tetraedro->draw(dibujado,GL_FILL,false,true,false);
   glPopMatrix();

   glPushMatrix();
      cilindro->setColor(Tupla3f(0.3,0.0,0.0));
      glTranslatef(-60,0,-100);   
      cilindro->draw(dibujado,GL_FILL,false,true,false);
   glPopMatrix();

   glPushMatrix();
      cono->setColor(Tupla3f(0.4,0.0,0.0));
      glTranslatef(0,0,-100);   
      cono->draw(dibujado,GL_FILL,false,true,false);
   glPopMatrix();

   glPushMatrix();
      esfera->setColor(Tupla3f(0.5,0.0,0.0));
      glTranslatef(60,0,-100);   
      esfera->draw(dibujado,GL_FILL,false,true,false);
   glPopMatrix();

   glPushMatrix();
      revolucion->setColor(Tupla3f(0.6,0.0,0.0));
      glTranslatef(120,0,-100);
      glScalef(25.0,25.0,25.0); 
      revolucion->draw(dibujado,GL_FILL,false,true,false);
   glPopMatrix();

   glPushMatrix();
      objetoply->setColor(Tupla3f(0.7,0.0,0.0));
      glTranslatef(180,0,-100);
      glScalef(2.0,2.0,2.0);  
      objetoply->draw(dibujado,GL_FILL,false,true,false);
   glPopMatrix();

   glEnable(GL_DITHER);
}

void Escena::analizaColor(int x,int y){
   glDisable(GL_DITHER);
   glDisable(GL_TEXTURE);
   glEnable(GL_LIGHTING);

   GLfloat pixel[3];
   GLint viewport[4];
   estadoRaton = MOVIENDO_CAMARA_FIRSTPERSON;

   glGetIntegerv(GL_VIEWPORT,viewport);
   glReadPixels(x,viewport[3]-y,1,1,GL_RGB,GL_FLOAT,pixel);

   if (pixel[0] > 0.09 && pixel[0] < 0.11){
      std::cout << "\n** CUBO SELECCIONADO **\n";
      estadoRaton = CAMARA_EN_OBJETO;
      vCamaras[camaraActual].mover(-180,0,-100);
      cubo->setColor(seleccionado);
      cubo->setMaterial(*matSeleccionado);
   }
   else{
      cubo->setColor(seleccionable);
      cubo->setMaterial(*matSelecionable);
   }

   if (pixel[0] > 0.19 && pixel[0] < 0.21){
      std::cout << "\n** TETRAEDRO SELECCIONADO **\n";
      estadoRaton = CAMARA_EN_OBJETO;
      vCamaras[camaraActual].mover(-120,0,-100);
      tetraedro->setColor(seleccionado);
      tetraedro->setMaterial(*matSeleccionado);
   }
   else{
      tetraedro->setColor(seleccionable);
      tetraedro->setMaterial(*matSelecionable);
   }

   if (pixel[0] > 0.29 && pixel[0] < 0.31){
      std::cout << "\n** CILINDRO SELECCIONADO **\n";
      estadoRaton = CAMARA_EN_OBJETO;
      vCamaras[camaraActual].mover(-60,0,-100);
      cilindro->setColor(seleccionado);
      cilindro->setMaterial(*matSeleccionado);
   }
   else{
      cilindro->setColor(seleccionable);
      cilindro->setMaterial(*matSelecionable);
   }

   if (pixel[0] > 0.39 && pixel[0] < 0.41){
      std::cout << "\n** CONO SELECCIONADO **\n";
      estadoRaton = CAMARA_EN_OBJETO;
      vCamaras[camaraActual].mover(0,0,-100);
      cono->setColor(seleccionado);
      cono->setMaterial(*matSeleccionado);
   }
   else{
      cono->setColor(seleccionable);
      cono->setMaterial(*matSelecionable);
   }

   if (pixel[0] > 0.49 && pixel[0] < 0.51){
      std::cout << "\n** ESFERA SELECCIONADO **\n";
      estadoRaton = CAMARA_EN_OBJETO;
      vCamaras[camaraActual].mover(60,0,-100);
      esfera->setColor(seleccionado);
      esfera->setMaterial(*matSeleccionado);
   }
   else{
      esfera->setColor(seleccionable);
      esfera->setMaterial(*matSelecionable);
   }

   if (pixel[0] > 0.59 && pixel[0] < 0.61){
      std::cout << "\n** REVOLUCION SELECCIONADO **\n";
      estadoRaton = CAMARA_EN_OBJETO;
      vCamaras[camaraActual].mover(120,0,-100);
      revolucion->setColor(seleccionado);
      revolucion->setMaterial(*matSeleccionado);
   }
   else{
      revolucion->setColor(seleccionable);
      revolucion->setMaterial(*matSelecionable);
   }

   if (pixel[0] > 0.69 && pixel[0] < 0.71){
      std::cout << "\n** OBJETO PLY SELECCIONADO **\n";
      estadoRaton = CAMARA_EN_OBJETO;
      vCamaras[camaraActual].mover(180,0,-100);
      objetoply->setColor(seleccionado);
      objetoply->setMaterial(*matSeleccionado);
   }
   else{
      objetoply->setColor(seleccionable);
      objetoply->setMaterial(*matSelecionable);
   }
}