#include "aux.h"
#include "malla.h"
#include "cuadro.h"

Cuadro::Cuadro(float l, std::string nombre){

   float a = l/2.0;

   v = { {-a, a, 0},   // 0
         {a, a, 0},    // 1
         {a, -a, 0},   // 2
         {-a, -a, 0}}; // 3

   f = { {0,3,1}, {1,3,2}};

   inicializarColores();
   calcular_normales();

   textura = new Textura(nombre);

   ct = {{0,1},   // 0
         {1,1},   // 1
         {0,0},   // 2
         {1,0}};  // 3
}