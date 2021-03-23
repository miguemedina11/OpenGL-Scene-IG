#include "aux.h"
#include "esfera.h"

Esfera::Esfera(const int num_vert_perfil, const int num_instancias_perf, const float radio,bool tapa_sup, bool tapa_inf)
{
   float a = (2.0);

   // inicializar la tabla de vértices
   std::vector<Tupla3f> ver;

   float aIni = (3*pi)/2;
   float angulo = pi / (num_vert_perfil -1 );

   double x, y;

   for (int i=0 ; i<num_vert_perfil ; i++){
      x = radio * cos((i * angulo) + aIni);
      y = radio * sin((i * angulo) + aIni);
      Tupla3f aux(x,y,0.0);

      ver.push_back(aux);
   }

   inicializar(ver,num_instancias_perf, tapa_sup,  tapa_inf);

   inicializarColores();
   calcular_normales();
}

