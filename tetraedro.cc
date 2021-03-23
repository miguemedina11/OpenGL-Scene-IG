#include "aux.h"
#include "malla.h"
#include "tetraedro.h"

Tetraedro::Tetraedro(float a)
{
   float h = a*(sqrt(6)/3.0);

   // inicializar la tabla de vértices
   v = { {0, ((h)*2)/3, 0},   // 0
         {(-a)/2, (-h)/3, h/3},  // 1
         {a/2, (-h)/3, h/3},   // 2
         {0, (-h)/3, ((-h)*2)/3}};   // 3
   
   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)

   f = { {0,1,2},
         {0,3,1},
         {0,2,3},
         {1,3,2}};

      inicializarColores();
      calcular_normales();
}

