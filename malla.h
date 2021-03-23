// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "aux.h"
#include "material.h"
#include "textura.h"

typedef enum{INMEDIATO, DIFERIDO} modoDibujado;

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:

   // dibuja el objeto en modo inmediato
   void draw_ModoInmediato(GLenum visual, bool ajedrez, bool tapas, bool luces);

   // dibuja el objeto en modo diferido (usando VBOs)
   void draw_ModoDiferido(GLenum visual, bool ajedrez, bool tapas, bool luces);

   // función que redibuja el objeto
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces) ;

   void setMaterial(Material mat) ;

   void setColor(Tupla3f ncolor);

   protected:

   Material m;

   void calcular_normales() ; // calcula tabla de normales de vértices (práctica 3)

   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
   std::vector<Tupla3f> nv;  //array de normales de vertices
   std::vector<Tupla2f> ct;  //array de coordenadas de texturas

   GLuint CrearVBO(GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram);

   int sizeTapas;

   Textura * textura = nullptr;

   GLuint id_vbo_ver=0;
   GLuint id_vbo_tri=0;
   GLuint id_vbo_rojo=0;
   GLuint id_vbo_verde=0;
   GLuint id_vbo_azul=0;
   GLuint id_vbo_tri1=0;
   GLuint id_vbo_tri2=0;
   GLuint id_vbo_color=0;

   std::vector<Tupla3f> color, colorB, colorR, colorG, colorT1, colorT2;

   //Vectores para el ajedrez
   std::vector<Tupla3i> f1,f2;

   void inicializarColores();
   
} ;


#endif
