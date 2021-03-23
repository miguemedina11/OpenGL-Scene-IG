// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: esfera.h

//
// #############################################################################

#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

// *****************************************************************************
//
// clases derivadas de Ojeto Revolucion (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
//      Esfera

class Esfera : public ObjRevolucion
{
   public:
   Esfera(const int num_vert_perfil,
            const int num_instancias_perf,
            const float radio,bool tapa_sup, bool tapa_inf) ;

} ;




#endif
