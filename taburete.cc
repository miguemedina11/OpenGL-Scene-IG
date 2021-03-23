#include "aux.h"
#include "malla.h"
#include "taburete.h"

Taburete::Taburete(){
   soporte = new Cubo(1.0);
   soporte->setColor(Tupla3f(0.4078,0.4235,0.4118));
   palo = new Cubo(1.0);
   palo->setColor(Tupla3f(0.4078,0.4235,0.4118));
   asiento = new Cilindro(32,32,1.0,0.5,true,true);
   asiento->setColor(Tupla3f(0.5,0.25,0.0));

   metal = new Material(Tupla4f(0.4,0.4,0.4,1.0),Tupla4f(0.774597,0.774597,0.774597,1.0),Tupla4f(0.25,0.25,0.25,1.0),76.8);
   madera = new Material(Tupla4f(0.4,0.2368,0.1036,1.0),Tupla4f(0.774597,0.458561,0.200621,1.0),Tupla4f(0.25,0.148,0.054,1.0),10.0);
   
   soporte->setMaterial(*metal);
   palo->setMaterial(*metal);
   asiento->setMaterial(*madera);
}

void Taburete::draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces){
   glPushMatrix();

      //soporte
      glPushMatrix();
         glTranslatef(0.0,0.5,0.0);
         glScalef(5.0,1.0,5.0);
         soporte->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();

      //palo
      glPushMatrix();
         glTranslatef(0.0,5.0,0.0);
         glScalef(2.0,8.0,2.0);
         palo->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();

      //asiento
      glPushMatrix();
         glTranslatef(0.0,10.0,0.0);
         glScalef(8.0,2.0,8.0);
         asiento->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();

   glPopMatrix();
}