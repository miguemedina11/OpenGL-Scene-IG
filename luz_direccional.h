// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: luz_direccional.h

//
// #############################################################################

#ifndef LUZDIRECCIONAL_H_INCLUDED
#define LUZDIRECCIONAL_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "luz.h"

// *****************************************************************************
//
// clases LUZ DIRECCIONAL
//
// *****************************************************************************

// *****************************************************************************

class LuzDireccional : public Luz
{
protected:
    float alpha;
    float beta;

public:

    LuzDireccional(Tupla2f direccion, GLenum idLuzOpenGL, Tupla4f colorAmbiente, Tupla4f colorEspecular, Tupla4f colorDifuso);

    void variarAnguloAlpha ( float incremento);
    void variarAnguloBeta (float incremento);
};
#endif
