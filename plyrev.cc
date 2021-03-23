#include "aux.h"
#include "plyrev.h"

PlyRev::PlyRev(const std::string & archivo, const int num_instancias_perf, bool tapa_sup, bool tapa_inf)
{

      std::vector<Tupla3f> perfil;
      ply::read_vertices(archivo, perfil);

      //detectarTapas(perfil);


      inicializar(perfil,num_instancias_perf, tapa_sup, tapa_inf);

      inicializarColores();
      calcular_normales();
}


//Funcion para detectar si hay tapas o no. En caso negativo se crean unas tapas
/*void PlyRev::detectarTapas(std::vector<Tupla3f> & perfil){

      if (perfil.front()[0] != 0){
            Tupla3f tapa(0.0, perfil.front()[1], perfil.front()[2]);
            perfil.insert(perfil.begin(),tapa);
      }

      if (perfil.back()[0] != 0){
            Tupla3f tapa(0.0, perfil.back()[1], perfil.back()[2]);
            perfil.push_back(tapa);
      }
}*/
