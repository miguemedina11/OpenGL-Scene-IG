#include "aux.h"
#include "cilindro.h"

Cilindro::Cilindro(const int num_vert_perfil, const int num_instancias_perf, const float altura, const float radio,bool tapa_sup, bool tapa_inf)
{

      // inicializar la tabla de vértices
      std::vector<Tupla3f> ver = { {0,(-altura)/2, 0}, //0
                                    {radio, (-altura)/2, 0},   // 1
                                    {radio, (altura)/2, 0}, //2
                                    {0,(altura)/2, 0}}; // 3

      inicializar(ver,num_instancias_perf,tapa_sup,tapa_inf);

      inicializarColores();
      calcular_normales();
}
