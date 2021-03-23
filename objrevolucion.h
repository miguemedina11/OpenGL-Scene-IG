// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "ply_reader.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************

class ObjRevolucion : public Malla3D
{
   public:
    ObjRevolucion();
    ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup=true, bool tapa_inf=true) ;
    ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup=true, bool tapa_inf=true) ;
private:
    void crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias);
    void quitarTapas(std::vector<Tupla3f> &perfil, bool tapa_sup, bool tapa_inf);
    
    Tupla3f tapaSup,tapaInf;
    bool tieneTS, tieneTI;

protected:
    void inicializar(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup=true, bool tapa_inf=true);

} ;




#endif
