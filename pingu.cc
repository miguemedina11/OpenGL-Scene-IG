#include "aux.h"
#include "malla.h"
#include "pingu.h"

Pingu::Pingu(){
   
   siguiente = false;
   cuerpo = new Cuerpo();
   brazoD = new Brazo();
   brazoI = new BrazoTrompeta();
   pie = new Pie();
   cabeza = new Cabeza();
}

void Pingu::draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces){
   glPushMatrix();

      glScalef(20,20,20);

      //CUERPO
      cuerpo->draw(modo, visual, ajedrez, tapas, luces);

      //BRAZO DERECHO
      glPushMatrix();

         glTranslatef(-0.9,2.8,0);
         glRotatef(-giroHombroD,1.0,0.0,0.0);
         glRotatef(-35,0.0,0.0,1.0);
         glRotatef(-90,0.0,1.0,0.0);

         brazoD->draw(modo, visual, ajedrez, tapas, luces);

      glPopMatrix();

      //BRAZO IZQUIERDO
      glPushMatrix();

         glTranslatef(0.9,2.8,0);
         glRotatef(-giroHombroI,1.0,0.0,0.0);
         glRotatef(35,0.0,0.0,1.0);
         glRotatef(90,0.0,1.0,0.0);

         brazoI->draw(modo, visual, ajedrez, tapas, luces);
         
      glPopMatrix();

      //PIE DERECHO
      glPushMatrix();

         glTranslatef(-0.9,-3.2,0.0);
         glRotatef(-7,0.0,1.0,0.0);
         pie->draw(modo, visual, ajedrez, tapas, luces);

      glPopMatrix();

      //PIE IZQUIERDO
      glPushMatrix();

         glTranslatef(0.9,-3.2,0.0);
         glRotatef(7,0.0,1.0,0.0);
         pie->draw(modo, visual, ajedrez, tapas, luces);

      glPopMatrix();

      //CABEZA
      glPushMatrix();

         glTranslatef(0,3.85,0);

         //CABEZA OBJETO
         cabeza->draw(modo, visual, ajedrez, tapas, luces);

      glPopMatrix();

   glPopMatrix();
}

void Pingu::girarhombroD(float valor){
   giroHombroD += valor;
   if(giroHombroD > 180)
      giroHombroD = 180;
   if (giroHombroD < -80)
      giroHombroD = -80;
}

void Pingu::girarhombroI(float valor){
   giroHombroI += valor;
   if(giroHombroI > 180)
      giroHombroI = 180;
   if(giroHombroI < -80)
      giroHombroI = -80;
}

void Pingu::girarCodoD(float valor){
   giroCodoD += valor;
   if(giroCodoD > 160)
      giroCodoD = 160;
   if (giroCodoD < 0)
      giroCodoD = 0;
   
   brazoD->setGiro(giroCodoD);
}

void Pingu::girarCodoI(float valor){
   giroCodoI += valor;
   if(giroCodoI > 160)
      giroCodoI = 160;
   if (giroCodoI < 0)
      giroCodoI = 0;

   brazoI->setGiro(giroCodoI);
}

void Pingu::animarTrompeta(float valor){
   brazoI->animarTrompeta(valor);
}

//ANIMACION 1

void Pingu::girarCodos(float valor, float valor2){
   siguiente2 = false;
   int limite = 130;

   giroCodoD += valor;
   if(giroCodoD > limite)
      giroCodoD = limite;

   brazoD->setGiro(giroCodoD);

   giroCodoI += valor2;
   if(giroCodoI > limite)
      giroCodoI = limite;

   if (giroCodoI == limite && giroCodoD == limite)
      siguiente2 = true;

   brazoI->setGiro(giroCodoI);
}

void Pingu::girarHombros(float valor, float valor2){
   int limite = 95;
   siguiente = false;
   giroHombroD += valor;
   if(giroHombroD > limite)
      giroHombroD = limite;
   
   
   giroHombroI += valor2;
   if(giroHombroI > limite)
      giroHombroI = limite;
   

   if (giroHombroD == limite && giroHombroI == limite)
      siguiente = true;
}

void Pingu::tocarTrompeta(float valor){
   if(brazoI->tocarTrompeta(valor)){
      restablecer();
   }
}

bool Pingu::getSiguiente(){
   return (siguiente & siguiente2);
}

void Pingu::restablecer(){
   giroHombroD = 0;
   giroHombroI = 0;
   giroCodoD = 0;
   giroCodoI = 0;
   siguiente = false;
   siguiente2 = false;
   brazoI->restablecerTrompeta();

   brazoD->setGiro(giroCodoD);
   brazoI->setGiro(giroCodoI);
}