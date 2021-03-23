// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: luz_posicional.h

//
// #############################################################################

#ifndef LUZPOSICIONAL_H_INCLUDED
#define LUZPOSICIONAL_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "luz.h"

// *****************************************************************************
//
// clases LUZ POSICIONAL
//
// *****************************************************************************

// *****************************************************************************

class LuzPosicional : public Luz
{

public:

    LuzPosicional(Tupla3f pos, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso);
};
#endif
