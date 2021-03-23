#include "aux.h"
#include "malla.h"
#include "pie.h"

Pie::Pie(){
   pata = new Cilindro(32,32,1,0.5,true,true);
   pata->setColor(Tupla3f(0.95,0.50,0.0));
   pie = new Cilindro(32,32,1,0.5,true,true);
   pie->setColor(Tupla3f(0.95,0.50,0.0));

   naranja = new Material(Tupla4f(0.7038,0.27048,0.0828,1.0),Tupla4f(0.256777,0.137622,0.086014,1.0),Tupla4f(0.19125,0.0735,0.0225,1.0),10.0);
   
   pata->setMaterial(*naranja);
   pie->setMaterial(*naranja);
}

void Pie::draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces){
   //Pata
   glPushMatrix();
      glTranslatef(0,1,0);
      glScalef(0.2,2,0.2);
      pata->draw(modo, visual, ajedrez, tapas, luces);
   glPopMatrix();

   //Pie
   glPushMatrix();
      glTranslatef(0.0,-0.1,1.5);
      glScalef(1.7,0.2,3.5);
      pie->draw(modo, visual, ajedrez, tapas, luces);
   glPopMatrix();
}