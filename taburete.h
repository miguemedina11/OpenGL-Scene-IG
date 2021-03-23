// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: taburete.h

//
// #############################################################################

#ifndef TABURETE_H_INCLUDED
#define TABURETE_H_INCLUDED

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

class Taburete
{
   public:
      Taburete();
      void draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces);

   private:
      Cubo * soporte;
      Cubo * palo;
      Cilindro * asiento;

      Material * metal = nullptr;
      Material * madera = nullptr;

};




#endif
