#include "aux.h"
#include "objrevolucion.h"




// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
   std::vector<Tupla3f> perfil;
   ply::read_vertices(archivo, perfil);

   ObjRevolucion (perfil, num_instancias, tapa_sup, tapa_inf);
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
   inicializar(archivo,num_instancias,tapa_sup,tapa_inf);
}

void ObjRevolucion::inicializar(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf){
   Tupla3f vIni = archivo.front();
   Tupla3f vFin = archivo.back();


   //Hacemos que el vector este en la orientacion adecuada
   if (vFin[1] < vIni[1])
      std::reverse(archivo.begin(),archivo.end());

   //////////////////////////////////////////////////////////
   // Comprobamos si el archivo tiene o no tapa superior e inferior

   tieneTS = !(archivo.front()[0] > 0.2);
   tieneTI = !(archivo.back()[0] > 0.2);

   //Creamos las tapas que se usarian
   Tupla3f tapaS(0.0, archivo.front()[1], archivo.front()[2]);
   Tupla3f tapaI(0.0, archivo.back()[1], archivo.back()[2]);

   if(!tieneTS)
      archivo.insert(archivo.begin(),tapaS);
   if(!tieneTI)
      archivo.push_back(tapaI);

   //Quito las tapas para aniadirlas luego
   tapaSup = archivo.back();;
   archivo.pop_back();
   tapaInf = archivo.front();
   archivo.erase(archivo.begin());

   /////////////////////////////////////////////////////

   crearMalla(archivo,num_instancias);

   int sizeSinTapas = f.size();

   /////////////////////////////////////////////////////


   int N = num_instancias;
   int M = v.size()/N; 
   int nVertOri = v.size();

   //Aniadir Tapa Inferior
   if (tapa_inf){
      v.push_back(tapaInf);
      for(int i=0 ; i<N ; i++){
         Tupla3i triangulo(i*M, v.size()-1, ((i+1)*M)%nVertOri);
         f.push_back(triangulo);
      }
   }

   //Aniadir Tapa Superior
   if (tapa_sup){
      v.push_back(tapaSup);
      for(int i=0 ; i<N ; i++){
         Tupla3i triangulo(v.size()-1, (i*M)+(M-1), (((i+1)*M)+(M-1))%nVertOri);
         f.push_back(triangulo);
      }
   }

   sizeTapas = f.size() - sizeSinTapas;
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
   
   float rotation = 2 * pi / num_instancias; //radianes
   float x,y,z;
   int M = perfil_original.size();
   int N = num_instancias;

   //Completamos la tabla de vertices
   for (int i=0 ; i<N;i++){
      for (int j=0;j<M;j++){
         x = cos(rotation*i)*perfil_original[j][0]+ sin(rotation*i)*perfil_original[j][2];
         y = perfil_original[j][1];
         z = cos(rotation*i)*perfil_original[j][2] - sin(rotation*i)*perfil_original[j][0];

         Tupla3f vAux(x,y,z);
         v.push_back(vAux);
      }
   }

   int a,b;

   //Completamos la tabla de caras
   for (int i=0 ; i<N;i++){
      for (int j=0;j<M-1;j++){
         a = M*i+j;
         b = M *((i+1) % N)+j;
         Tupla3i t1(a,b,b+1);
         Tupla3i t2(a,b+1,a+1);
         f.push_back(t1);
         f.push_back(t2);
      }
   }
}