#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "tetraedro.h"
#include "cilindro.h"
#include "objply.h"
#include "cono.h"
#include "esfera.h"
#include "objrevolucion.h"
#include "plyrev.h"
#include "luz.h"
#include "luz_direccional.h"
#include "luz_posicional.h"
#include "pingu.h"
#include "cuadro.h"
#include "camara.h"
#include "taburete.h"

typedef enum {NADA, SELOBJETO,SELVISUALIZACION,SELDIBUJADO,SELESCENA,SELILUMINACION,SELMANUAL,SELAUTO,SELCAM} menu;
typedef enum {MOVIENDO_CAMARA_FIRSTPERSON, CAMARA_EN_OBJETO} ratonEST;

class Escena
{

   private:

   

 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection( const float ratio_xy );
	void change_observer();
    
    

   void clear_window();

   menu modoMenu=NADA;
   // Objetos de la escena
   Ejes ejes;
   Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
   Tetraedro * tetraedro= nullptr ; // es importante inicializarlo a 'nullptr'
   Cilindro * cilindro= nullptr ;
   ObjPLY * objetoply=nullptr;
   Cono * cono = nullptr;
   Esfera * esfera = nullptr;
   PlyRev * revolucion = nullptr;
   PlyRev * peon1 = nullptr;
   PlyRev * peon2 = nullptr;
   Esfera * posluz = nullptr;
   Pingu * pingu = nullptr;

   //Luces
   LuzPosicional * luzP = nullptr;
   LuzDireccional * luzD = nullptr;

   //Materiales
   Material * m1 = nullptr;
   Material * m2 = nullptr;
   Material * matSelecionable = nullptr;
   Material * matSeleccionado = nullptr;  

   //Texturas
   Cuadro * cuadro = nullptr;
   Cubo * skybox = nullptr;

   //Camaras
   std::vector<Camara> vCamaras;
   int camaraActual;
   ratonEST estadoRaton;

   //PRACTICA FINAL
   Taburete * taburete = nullptr;
   Tetraedro * tetraFin = nullptr;
   Cono * conoFin = nullptr;
   ObjPLY * plyFin = nullptr;
   Esfera * posSol = nullptr;

   Material * naranja = nullptr;
   Material * arena = nullptr;
   Material * matSol= nullptr;
   LuzPosicional * sol = nullptr;

   ///////////////////////////////////////////////////////

   modoDibujado dibujado;

   bool solido, lineas, puntos;
   bool ajedrez;
   bool vertapas;
   bool luces;
   bool animacionAuto;

   int practica;
   int gradoLibertad;
   char anguloActual;
   float velAnimacion0, velAnimacion1,velAnimacion2,velAnimacion3, velAnimacion4;
   float animacionLuz;
   
   bool esCubo, esTetraedro, esCilindro, esCono, esEsfera, esPly, esRevolucion; 
   bool luz0, luz1, luzAnimada;

   int xant, yant;

   //Colores
   Tupla3f seleccionable= {0.0,0.0,1.0};
   Tupla3f noSeleccionable= {0.5,0.5,1.0};
   Tupla3f seleccionado= {1.0,1.0,0.0};
   
   public:

    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );
    void animarModeloJerarquico();
    void animarLuz();

    //Camaras
    void clickRaton(int boton, int estado, int x , int y);
    void ratonMovido(int x, int y);
    void dibujaSeleccion();
    void analizaColor(int x,int y);
};
#endif
