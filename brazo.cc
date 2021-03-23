#include "aux.h"
#include "malla.h"
#include "brazo.h"

Brazo::Brazo(){
   brazoA= new Cubo(1);
   brazoA->setColor(Tupla3f(0.0,0.0,0.0));
   brazoB = new Cilindro(32,32,1,0.5,true,true);
   brazoB->setColor(Tupla3f(0.0,0.0,0.0));
   negroR = new Material(Tupla4f(0.01,0.01,0.01,1.0),Tupla4f(0.4,0.4,0.4,1.0),Tupla4f(0.02,0.02,0.02,1.0),10.0);
   brazoA->setMaterial(*negroR);
   brazoB->setMaterial(*negroR);
}

void Brazo::draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces){
   
   //Brazo Derecho A
   glPushMatrix();
      glTranslatef(0,-1.3,0);
      glScalef(1,2.6,0.2);
      brazoA->draw(modo, visual, ajedrez, tapas, luces);
   glPopMatrix();

   //Brazo Derecho B
   glPushMatrix();
      glTranslatef(0,-2.6,0);
      //Rotacion x
      glRotatef(giroCodo,1.0,0.0,0.0);
      glTranslatef(0,-1.3,0);
      glScalef(1.1,4,0.2);
      glRotatef(90.0,1.0,0.0,0.0);
      brazoB->draw(modo, visual, ajedrez, tapas, luces);
   glPopMatrix();
}

void Brazo::setGiro(float valor){
   giroCodo = valor;
}