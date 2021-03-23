#include "aux.h"
#include "luz_posicional.h"
#include "luz.h"
#include "malla.h"


// *****************************************************************************
//
// Clase Luz Posicional
//
// *****************************************************************************

LuzPosicional::LuzPosicional(Tupla3f pos, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso){
   
   id = idLuzOpenGL;
   this->colorAmbiente= colorAmbiente;
   this->colorEspecular = colorEspecular;
   this->colorDifuso = colorDifuso;
   posicion = Tupla4f(pos[0],pos[1],pos[2],1.0);
}
