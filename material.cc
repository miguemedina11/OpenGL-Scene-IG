#include "aux.h"
#include "material.h"

Material::Material(){
   difuso = Tupla4f(0.8,0.8,0.8,1.0);
   especular = Tupla4f(0.0,0.0,0.0,1.0);
   ambiente = Tupla4f(0.2,0.2,0.2,1.0);
   brillo = 0;
}

Material::Material(Tupla4f ndifuso, Tupla4f nespecular, Tupla4f nambiente, float nbrillo){
   difuso = ndifuso;
   especular = nespecular;
   ambiente = nambiente;
   brillo = nbrillo;
}

void Material::aplicar(){

   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiente);
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuso);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especular);

   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo);
}

