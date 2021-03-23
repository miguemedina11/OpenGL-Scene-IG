// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: camara.h

//
// #############################################################################

#ifndef CAMARA_H_INCLUDED
#define CAMARA_H_INCLUDED

#include "aux.h"

class Camara
{

   Tupla3f eye;
   Tupla3f at;
   Tupla3f up;

   int tipo; //Ortogonal (0) o Perspectiva (1)
   float left, right, near, far, bottom, top;

   public:

      Camara(Tupla3f eye, Tupla3f at, 
      Tupla3f up, int tipo, float left, 
      float right, float near, float far, 
      float bottom, float top);
      
      void rotarXExaminar(float angle);
      void rotarYExaminar(float angle);
      void rotarZExaminar(float angle);
      void rotarXFirstPerson(float angle);
      void rotarYFirstPerson(float angle);
      void rotarZFirstPerson(float angle);

      void mover(float x, float y, float z);
		void zoom(float factor);

		void setObserver();
		void setProyeccion();

      void girar( float x, float y);
};

#endif
