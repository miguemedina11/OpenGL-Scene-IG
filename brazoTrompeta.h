// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: brazoTrompeta.h

//
// #############################################################################

#ifndef BRAZOTROMPETA_H_INCLUDED
#define BRAZOTROMPETA_H_INCLUDED

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
#include "trompeta.h"

class BrazoTrompeta
{
   public:
      BrazoTrompeta();
      void draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces);
      void setGiro(float valor);
      void animarTrompeta(float valor);
      bool tocarTrompeta(float valor);
      void restablecerTrompeta();

   private:
      Cubo * brazoA = nullptr;
      Cilindro * brazoB = nullptr;
      Trompeta * trompeta = nullptr;

      Material * negroR = nullptr;
      
      float giroCodo = 0;
};




#endif
