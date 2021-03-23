#include "aux.h"
#include "luz_direccional.h"
#include "luz.h"


// *****************************************************************************
//
// Clase Luz Direccional
//
// *****************************************************************************

LuzDireccional::LuzDireccional(Tupla2f direccion, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso){   

   id = idLuzOpenGL;
   this->colorAmbiente= colorAmbiente;
   this->colorEspecular = colorEspecular;
   this->colorDifuso = colorDifuso;
   alpha = direccion[0];
   beta = direccion[1];
   posicion = Tupla4f({float(cos(alpha)*cos(beta)),float(cos(alpha)*sin(beta)),float(sin(alpha)),0.0});
   glLightfv(id, GL_POSITION, posicion);
}

void LuzDireccional::variarAnguloAlpha ( float incremento){
   alpha = alpha + incremento;
   if (alpha>=360)
      alpha = alpha-360;

   posicion = Tupla4f({float(cos(alpha)*cos(beta)),float(cos(alpha)*sin(beta)),float(sin(alpha)),0.0});
   glLightfv(id, GL_POSITION, posicion);
}

void LuzDireccional::variarAnguloBeta ( float incremento){
   beta = beta + incremento;
   if (beta>=360)
      beta = beta-360;

   posicion = Tupla4f({float(cos(alpha)*cos(beta)),float(cos(alpha)*sin(beta)),float(sin(alpha)),0.0});
   glLightfv(id, GL_POSITION, posicion);
}
