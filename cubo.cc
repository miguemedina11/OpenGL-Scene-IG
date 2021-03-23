#include "aux.h"
#include "malla.h"
#include "cubo.h"


Cubo::Cubo(float lado)
{
   float a = (lado/2.0);

   // inicializar la tabla de vértices
   v = { {-a, a, a},   // 0
         {-a, -a, a},  // 1
         {a, -a, a},   // 2
         {a, a, a},    // 3
         {-a, a, -a},  // 4
         {-a, -a, -a}, // 5
         {a, -a, -a},  // 6
         {a, a, -a}};  // 7
   
   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)

   f = { {0,1,2}, {0,2,3},
         {4,5,1}, {4,1,0},
         {7,6,5}, {7,5,4},
         {4,0,3}, {4,3,7},
         {3,2,6}, {3,6,7},
         {1,5,6}, {1,6,2} };

      inicializarColores();
      calcular_normales();
}

Cubo::Cubo(float lado, std::string nombre)
{
   float a = (lado/2.0);

   v = { {-a, a, a},   // 0
         {-a, -a, a},  // 1
         {a, -a, a},   // 2
         {a, a, a},    // 3
         {-a, a, -a},  // 4
         {-a, -a, -a}, // 5
         {a, -a, -a},  // 6
         {a, a, -a},   // 7
         {-a,a,a},     //0b
         {-a,-a,a}};   //1b

   f = { {0,2,1}, {0,3,2},//
         {4,9,5}, {4,8,9},//
         {7,5,6}, {7,4,5},//
         {4,3,0}, {4,7,3},//
         {3,6,2}, {3,7,6},//
         {1,6,5}, {1,2,6} };

      inicializarColores();
      calcular_normales();

      textura = new Textura(nombre);

      ct = {{0,1},  // 0
         {0,0},     // 1
         {0.25,0},  // 2
         {0.25,1},  // 3
         {0.75,1},  //4
         {0.75,0},  //5
         {0.5,0},   //6
         {0.5,1},   //7
         {1,1},     //0b
         {1,0}};    //1b

}

