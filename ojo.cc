#include "aux.h"
#include "malla.h"
#include "ojo.h"

Ojo::Ojo(){
   ojo = new Cilindro(32,32,1.0,0.5,true,true);
   ojo->setColor(Tupla3f(0.95,0.95,0.95));
   pupila = new Cilindro(32,32,1.0,0.5,true,true);
   pupila->setColor(Tupla3f(0.0,0.0,0.0));
   negroP = new Material(Tupla4f(0.01,0.01,0.01,1.0),Tupla4f(0.4,0.4,0.4,1.0),Tupla4f(0.02,0.02,0.02,1.0),10.0);
   blancoP = new Material(Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(1.0,1.0,1.0,1.0),Tupla4f(1.0,1.0,1.0,1.0),100.0);
   ojo->setMaterial(*blancoP);
   pupila->setMaterial(*negroP);
}

void Ojo::draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces){
   glPushMatrix();

      //ojo
      glPushMatrix();
         glRotatef(90,1.0,0.0,0.0);
         glScalef(0.6,0.2,0.6);
         ojo->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();

      //pupila
      glPushMatrix();
         glTranslatef(0.0,-0.05,0.05);
         glRotatef(90,1.0,0.0,0.0);
         glScalef(0.25,0.2,0.25);
         pupila->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();
   glPopMatrix();
}