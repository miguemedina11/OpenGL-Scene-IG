#include "aux.h"
#include "malla.h"
#include "trompeta.h"

Trompeta::Trompeta(){
   tubo = new Cilindro(32,32,1.0,0.5,true,true);
   tubo->setColor(Tupla3f(1.0,1.0,0.0));
   tuboRojo = new Cilindro(32,32,1.0,0.5,true,true);
   tuboRojo->setColor(Tupla3f(1.0,0.70,0.0));
   trompa = new Cono(32,32,1,0.5,true,true);
   trompa->setColor(Tupla3f(1.0,1.0,0.0));
   incremento = 1;

   dorado = new Material(Tupla4f(0.780392,0.568627,0.113725,1.0),Tupla4f(0.992157,0.941176,0.807843,1.0),Tupla4f(0.329412,0.223529,0.027451,1.0),27.8974);
   doradoRojo = new Material(Tupla4f(0.714,0.4284,0.18144,1.0),Tupla4f(0.393548,0.271906,0.166721,1.0),Tupla4f(0.2125,0.1275,0.054,1.0),25.6);

   tubo->setMaterial(*dorado);
   tuboRojo->setMaterial(*doradoRojo);
   trompa->setMaterial(*dorado);
}

void Trompeta::draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces){
   glPushMatrix();

      //cilindro1
      glPushMatrix();
         glTranslatef(-2.25,0,0);
         glScalef(0.5,1.0,0.5);
         tubo->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();

      //cilindro2
      glPushMatrix();
         glTranslatef(0.25,0,0);
         glScalef(0.5,1.0,0.5);
         tubo->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();

      //cilindroRojo1
      glPushMatrix();
         glTranslatef(-1.5,0.75,0);
         glRotatef(90.0,0.0,0.0,1.0);
         glScalef(0.5,3.0,0.5);
         tuboRojo->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();

      //cilindroRojo2
      glPushMatrix();
         glTranslatef(-1,-0.25,0);
         glRotatef(90.0,0.0,0.0,1.0);
         glScalef(0.5,3.0,0.5);
         tuboRojo->draw(modo, visual, ajedrez, tapas, luces);
      glPopMatrix();

      //trompaCompuesta
      glPushMatrix();

         
         if (incremento!=1.0)
            glTranslatef((incremento)/2.0,0.0,0.0);
         glTranslatef(1.25,0.75,0);
         
         //trompa
         glPushMatrix();
            glScalef(1.0,incremento,incremento);
            glRotatef(90.0,0.0,0.0,1.0);
            glScalef(2.0,2.0,2.0);
            trompa->draw(modo, visual, ajedrez, tapas, luces);
         glPopMatrix();

         //canon
         glPushMatrix();
            //glScalef(incremento,1.0,1.0);
            glTranslatef(-1.25,0.0,0.0);
            glRotatef(90.0,0.0,0.0,1.0);
            glScalef(0.5,3.0,0.5);
            tuboRojo->draw(modo, visual, ajedrez, tapas, luces);
         glPopMatrix();

      glPopMatrix();
      
   glPopMatrix();
}

void Trompeta::aumentarIncremento(float valor){
   siguiente = false;
   incremento+= valor;
   //
   int limiteTrompeta = 3;

   if (incremento > 2.5){
      incremento = 1;
      trompeteada++;
   }
   if (incremento < 1){
      incremento = 2.5;
   }
   if (trompeteada==limiteTrompeta){
      trompeteada = 0;
      siguiente = true;
   }
}

void Trompeta::restablecer(){
   incremento = 1;
   siguiente= false;
}

bool Trompeta::getSiguiente(){
   return siguiente;
}