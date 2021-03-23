// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: textura.h

//
// #############################################################################

#ifndef TEXTURA_H_INCLUDED
#define TEXTURA_H_INCLUDED

#include "aux.h"

class Textura
{
   private:
      GLuint textura_id = 0;
      unsigned char * texels;
      int tamx, tamy;

   public:
      Textura (std::string archivo);
      void activar();
} ;




#endif
