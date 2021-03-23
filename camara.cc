#include "aux.h"
#include "malla.h"
#include "camara.h"

Camara::Camara(Tupla3f eye, Tupla3f at, Tupla3f up, int tipo, float left, float right, float near, float far, float top, float bottom){
   
   this->eye = eye;
   this->at = at;
   this->up = up;
   this->tipo = tipo;
   this->left = left;
   this->right = right;
   this->near = near;
   this->far = far;
   this->top = top;
   this->bottom = bottom;
}

void Camara::rotarXExaminar(float angle){
   eye = eye - at;
   Tupla3f aux = eye;

   eye(Y) = aux(Y) * cos(angle) - aux(Z) * sin(angle);
   eye(Z) = aux(Y) * sin(angle) + aux(Z) * cos(angle);

   eye = eye + at;
}

void Camara::rotarYExaminar(float angle){
   eye = eye - at;
   Tupla3f aux = eye;

   eye(X) = aux(X) * cos(angle) + aux(Z) * sin(angle);
   eye(Z) = aux(X) * (-1) * sin(angle) + aux(Z) * cos(angle);

   eye = eye + at;
}

void Camara::rotarZExaminar(float angle){
   eye = eye - at;
   Tupla3f aux = eye;

   eye(X) = aux(X) * cos(angle) - aux(Z) * sin(angle);
   eye(Y) = aux(X) * sin(angle) + aux(Z) * cos(angle);

   eye = eye + at;
}

void Camara::rotarXFirstPerson(float angle){
   at = at- eye;
   Tupla3f aux = at;

   at(Y) = aux(Y) * cos(angle) - aux(Z) * sin(angle);
   at(Z) = aux(Y) * sin(angle) + aux(Z) * cos(angle);

   at = at + eye;
}

void Camara::rotarYFirstPerson(float angle){
   at = at- eye;
   Tupla3f aux = at;

   at(X) = aux(X) * cos(angle) + aux(Z) * sin(angle);
   at(Z) = aux(X) * -1 * sin(angle) + aux(Z) * cos(angle);

   at = at + eye;
}

void Camara::rotarZFirstPerson(float angle){
   at = at- eye;
   Tupla3f aux = at;

   at(X) = aux(X) * cos(angle) - aux(Z) * sin(angle);
   at(Y) = aux(X) * sin(angle) + aux(Z) * cos(angle);

   at = at + eye;
}

void Camara::mover(float x, float y, float z){
   at(X) = x;
   at(Y) = y;
   at(Z) = z;

   eye(X) = x;
   eye(Y) = y + 400.0;
   eye(Z) = z + 300.0;
}

void Camara::zoom( float factor){
   left *= factor;
   right *= factor;
   top *= factor;
   bottom *= factor;
}

void Camara::setObserver(){
   gluLookAt(eye(X),eye(Y),eye(Z),at(X),at(Y),at(Z),up(X),up(Y),up(Z));
}

void Camara::setProyeccion(){
   if (tipo == 0)
      glOrtho(left, right, bottom, top, near, far);
   else
      glFrustum(left, right, bottom, top, near, far);
}

void Camara::girar( float x, float y){
   rotarXFirstPerson((-y)*0.25*pi/180.0);
   rotarYFirstPerson((-x)*0.25*pi/180.0);
}