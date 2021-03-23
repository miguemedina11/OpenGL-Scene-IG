// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cilindro.h

//
// #############################################################################

#ifndef PLYREV_H_INCLUDED
#define PLYREV_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

// *****************************************************************************
//
// clases derivadas de Ojeto Revolucion (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
//      PLY REV

class PlyRev : public ObjRevolucion
{
   public:
   PlyRev(const std::string & archivo,
            const int num_instancias_perf, bool tapa_sup, bool tapa_inf) ;

} ;




#endif
