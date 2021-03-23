// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cabeza.h

//
// #############################################################################

#ifndef CABEZA_H_INCLUDED
#define CABEZA_H_INCLUDED

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
#include "ojo.h"

class Cabeza
{
   public:
      Cabeza();
      void draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces);

   private:
      Esfera * cabeza = nullptr;
      Ojo * ojo = nullptr;
      Esfera * pico = nullptr;

      Material * negroR = nullptr;
      Material * rojo = nullptr;

};




#endif
