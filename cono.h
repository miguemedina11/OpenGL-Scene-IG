// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cono.h

//
// #############################################################################

#ifndef CONO_H_INCLUDED
#define CONO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

// *****************************************************************************
//
// clases derivadas de Ojeto Revolucion (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
//      Cono

class Cono : public ObjRevolucion
{
   public:
   Cono(const int num_vert_perfil,
            const int num_instancias_perf,
            const float altura,
            const float radio,bool tapa_sup, bool tapa_inf) ;

} ;




#endif
