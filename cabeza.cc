#include "aux.h"
#include "malla.h"
#include "cabeza.h"

Cabeza::Cabeza(){
   cabeza = new Esfera(32,32,0.5,true,true);
   cabeza->setColor(Tupla3f(0.0,0.0,0.0));
   ojo = new Ojo();
   pico = new Esfera(32,32,0.5,true,true);
   pico->setColor(Tupla3f(0.7,0.0,0.0));

   negroR = new Material(Tupla4f(0.01,0.01,0.01,1.0),Tupla4f(0.4,0.4,0.4,1.0),Tupla4f(0.02,0.02,0.02,1.0),10.0);
   rojo = new Material(Tupla4f(0.5,0.0,0.0,1.0),Tupla4f(0.7,0.6,0.6,1.0),Tupla4f(0.0,0.0,0.0,1.0),32.0);

   cabeza->setMaterial(*negroR);
   pico->setMaterial(*rojo);
}

void Cabeza::draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces){
   //Cabeza
   glPushMatrix();
      glScalef(2.6,2.1,1.8);
      cabeza->draw(modo, visual, ajedrez, tapas, luces);
   glPopMatrix();

   //Ojo Der
   glPushMatrix();
      glTranslatef(-0.55,0,0.8);
      glScalef(0.75,0.75,1);
      ojo->draw(modo, visual, ajedrez, tapas, luces);
   glPopMatrix();

   //Ojo Der
   glPushMatrix();
      glTranslatef(0.55,0,0.8);
      glScalef(0.75,0.75,1);
      ojo->draw(modo, visual, ajedrez, tapas, luces);
   glPopMatrix();

   //Pico
   glPushMatrix();
      glTranslatef(0,-0.55,0.7);
      glScalef(1.1,0.5,1);
      pico->draw(modo, visual, ajedrez, tapas, luces);
   glPopMatrix();
}