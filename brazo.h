// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: brazo.h

//
// #############################################################################

#ifndef BRAZO_H_INCLUDED
#define BRAZO_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "esfera.h"
#include "ejes.h"
#include "cubo.h"
#include "tetraedro.h"
#include "cilindro.h"
#include "objply.h"
#include "cono.h"
#include "objrevolucion.h"
#include "plyrev.h"
#include "luz.h"
#include "luz_direccional.h"
#include "luz_posicional.h"

class Brazo
{
   public:
      Brazo();
      void draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces);
      void setGiro(float valor);

   private:
      Cubo * brazoA = nullptr;
      Cilindro * brazoB = nullptr;

      Material * negroR = nullptr;
      
      float giroCodo = 0;
};




#endif
