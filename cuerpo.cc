#include "aux.h"
#include "malla.h"
#include "cuerpo.h"

Cuerpo::Cuerpo(){
   cuerpoBlanco = new Esfera(32,32,1,true,true);
   cuerpoBlanco->setColor(Tupla3f(0.95,0.95,0.95));
   cuerpoNegro = new Esfera(32,32,1,true,true);
   cuerpoNegro->setColor(Tupla3f(0.0,0.0,0.0));
   negroR = new Material(Tupla4f(0.01,0.01,0.01,1.0),Tupla4f(0.4,0.4,0.4,1.0),Tupla4f(0.02,0.02,0.02,1.0),10.0);
   blancoR = new Material(Tupla4f(0.5,0.5,0.5,1.0),Tupla4f(0.7,0.7,0.7,1.0),Tupla4f(0.05,0.05,0.05,1.0),10.0);
   cuerpoBlanco->setMaterial(*blancoR);
   cuerpoNegro->setMaterial(*negroR);
}

void Cuerpo::draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces){
   glPushMatrix();
      //Cuerpo Negro
      glPushMatrix();
         glScalef(2,3.3,1.4);
         cuerpoNegro->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();

      //Cuerpo Balnco
      glPushMatrix();
         glTranslatef(0,-0.2,0.5);
         glScalef(1.80,2.95,1);
         cuerpoBlanco->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();
   glPopMatrix();
}