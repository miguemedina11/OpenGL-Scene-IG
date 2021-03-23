// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cuerpo.h

//
// #############################################################################

#ifndef CUERPO_H_INCLUDED
#define CUERPO_H_INCLUDED

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

class Cuerpo
{
   public:
      Cuerpo();
      void draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces);

   private:
      Esfera * cuerpoNegro = nullptr;
      Esfera * cuerpoBlanco = nullptr;

      Material * blancoR = nullptr;
      Material * negroR = nullptr;

};

#endif
