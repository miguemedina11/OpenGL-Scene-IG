// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: trompeta.h

//
// #############################################################################

#ifndef TROMPETA_H_INCLUDED
#define TROMPETA_H_INCLUDED

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

class Trompeta
{
   public:
      Trompeta();
      void draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces);
      void aumentarIncremento(float valor);
      void restablecer();
      bool getSiguiente();

   private:
      Cilindro * tubo = nullptr;
      Cilindro * tuboRojo = nullptr;
      Cono * trompa = nullptr;

      float incremento;
      int trompeteada = 0;
      bool siguiente = false;
      
      Material * dorado = nullptr;
      Material * doradoRojo = nullptr;

};




#endif
