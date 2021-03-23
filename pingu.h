// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: pingu.h

//
// #############################################################################

#ifndef PINGU_H_INCLUDED
#define PINGU_H_INCLUDED

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
#include "cuerpo.h"
#include "brazo.h"
#include "brazoTrompeta.h"
#include "pie.h"
#include "cabeza.h"

class Pingu
{
   public:
      Pingu();
      void draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces);
      void girarhombroD(float valor);
      void girarhombroI(float valor);
      void girarCodoD(float valor);
      void girarCodoI(float valor);
      bool getSiguiente();
      void girarCodos(float valor, float valor2);
      void girarHombros(float valor, float valor2);
      void animarTrompeta(float valor);
      void tocarTrompeta(float valor);

      void restablecer();

   private:
      
      Cuerpo * cuerpo = nullptr;
      Brazo * brazoD = nullptr;
      BrazoTrompeta * brazoI = nullptr;
      Pie * pie = nullptr;
      Cabeza * cabeza = nullptr;      

      float giroHombroD = 0;
      float giroHombroI = 0;
      float giroCodoD = 0;
      float giroCodoI = 0;

      bool siguiente;
      bool siguiente2 = false;
};




#endif
