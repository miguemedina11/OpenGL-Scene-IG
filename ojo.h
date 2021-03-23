// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: ojo.h

//
// #############################################################################

#ifndef OJO_H_INCLUDED
#define OJO_H_INCLUDED

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

class Ojo
{
   public:
      Ojo();
      void draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces);

   private:
      Cilindro * pupila = nullptr;
      Cilindro * ojo = nullptr;

      Material * negroP = nullptr;
      Material * blancoP = nullptr;

};




#endif
