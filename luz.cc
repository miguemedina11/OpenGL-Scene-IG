#include "aux.h"
#include "luz.h"


// *****************************************************************************
//
// Clase Luz
//
// *****************************************************************************

/*Luz::Luz (Tupla4f pos, GLenum nid, Tupla4f colorA, Tupla4f colorD, Tupla4f colorE){
    posicion = pos;
    id = nid;
    colorAmbiente = colorA;
    colorDifuso = colorD;
    colorEspecular = colorE;
}*/

void Luz::activar(){
   glEnable(GL_LIGHTING);
   glLightfv(id, GL_AMBIENT, colorAmbiente);
   glLightfv(id, GL_SPECULAR, colorEspecular);
   glLightfv(id, GL_DIFFUSE, colorDifuso);
   glLightfv(id, GL_POSITION, posicion);
}

void Luz::apagar(){
    glDisable (id);
}

void Luz::encender(){
    glEnable (id);
}
