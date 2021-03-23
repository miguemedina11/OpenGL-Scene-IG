// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: pie.h

//
// #############################################################################

#ifndef PIE_H_INCLUDED
#define PIE_H_INCLUDED

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

class Pie
{
   public:
      Pie();
      void draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces);

   private:
      Cilindro * pata = nullptr;
      Cilindro * pie = nullptr;

      Material * naranja = nullptr;

};




#endif
