#include "aux.h"
#include "malla.h"
#include "brazoTrompeta.h"

BrazoTrompeta::BrazoTrompeta(){
   brazoA= new Cubo(1);
   brazoA->setColor(Tupla3f(0.0,0.0,0.0));
   brazoB = new Cilindro(32,32,1,0.5,true,true);
   brazoB->setColor(Tupla3f(0.0,0.0,0.0));
   negroR = new Material(Tupla4f(0.01,0.01,0.01,1.0),Tupla4f(0.4,0.4,0.4,1.0),Tupla4f(0.02,0.02,0.02,1.0),10.0);
   
   brazoA->setMaterial(*negroR);
   brazoB->setMaterial(*negroR);

   trompeta = new Trompeta();
}

void BrazoTrompeta::draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces){
   
   glPushMatrix();
      glTranslatef(0,-1.3,0);
      glScalef(1,2.6,0.2);
      brazoA->draw(modo, visual, ajedrez, tapas, luces);
   glPopMatrix();

   //Brazo Izquierdo B
   
   glPushMatrix();
      glTranslatef(0,-2.6,0);
      glRotatef(giroCodo,1.0,0.0,0.0);
      glPushMatrix();
         glTranslatef(0,-2.5,1.0);
         glRotatef(90.0,0.0,0.0,1.0);
         glRotatef(-90.0,0.0,1.0,0.0);
         glScalef(0.6,0.6,0.6);
         trompeta->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();
      glTranslatef(0,-1.3,0);
      glScalef(1.1,4,0.2);
      glRotatef(90.0,1.0,0.0,0.0);
      brazoB->draw(modo, visual, ajedrez, tapas, luces);
   glPopMatrix();
}

void BrazoTrompeta::setGiro(float valor){
   giroCodo = valor;
}

bool BrazoTrompeta::tocarTrompeta(float valor){
   trompeta->aumentarIncremento(valor);
   bool aux = trompeta->getSiguiente();
   return aux;
}

void BrazoTrompeta::animarTrompeta(float valor){
   trompeta->aumentarIncremento(valor);
}

void BrazoTrompeta::restablecerTrompeta(){
   trompeta->restablecer();
}