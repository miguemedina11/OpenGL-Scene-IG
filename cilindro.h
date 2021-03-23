// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cilindro.h

//
// #############################################################################

#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

// *****************************************************************************
//
// clases derivadas de Ojeto Revolucion (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
//      Cilindro

class Cilindro : public ObjRevolucion
{
   public:
   Cilindro(const int num_vert_perfil,
            const int num_instancias_perf,
            const float altura,
            const float radio, bool tapa_sup, bool tapa_inf) ;

} ;




#endif
