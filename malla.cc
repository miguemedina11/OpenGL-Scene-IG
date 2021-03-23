#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************

// Visualización en modo inmediato con 'glDrawElements'

void Malla3D::draw_ModoInmediato(GLenum visual, bool ajedrez, bool tapas, bool luces)
{
      glEnableClientState( GL_VERTEX_ARRAY );
      
      glEnableClientState (GL_COLOR_ARRAY);
      glPolygonMode(GL_FRONT_AND_BACK,visual);

   if (!luces){
      glDisable(GL_LIGHTING);
      if (!ajedrez){
         glVertexPointer( 3, GL_FLOAT, 0, v.data()); 
         
         switch (visual){
            case GL_POINT:
               glColorPointer(3, GL_FLOAT, 0, colorR.data());
               break;
            case GL_LINE:
               glColorPointer(3, GL_FLOAT, 0, colorG.data());
               break;
            case GL_FILL:
               glColorPointer(3, GL_FLOAT, 0, color.data());
               break;
         }

         // visualizar la malla usando glDrawElements,
         if (tapas){
            glDrawElements( GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, f.data());
         }else{
            glDrawElements( GL_TRIANGLES, (f.size()-sizeTapas)*3, GL_UNSIGNED_INT, f.data());
         }
      }
      else{
         glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

         glVertexPointer( 3, GL_FLOAT, 0, v.data()); 

         if (tapas){
            glColorPointer(3, GL_FLOAT, 0, colorG.data());
            glDrawElements( GL_TRIANGLES, f1.size()*3, GL_UNSIGNED_INT, f1.data());
            glColorPointer(3, GL_FLOAT, 0, colorR.data());
            glDrawElements( GL_TRIANGLES, f2.size()*3, GL_UNSIGNED_INT, f2.data());
         }else{
            glColorPointer(3, GL_FLOAT, 0, colorG.data());
            glDrawElements( GL_TRIANGLES, (f1.size()-sizeTapas/2)*3, GL_UNSIGNED_INT, f1.data());
            glColorPointer(3, GL_FLOAT, 0, colorR.data());
            glDrawElements( GL_TRIANGLES, (f2.size()-sizeTapas/2)*3, GL_UNSIGNED_INT, f2.data());
         }
         
      }

   }
   else{
      glEnable(GL_LIGHTING);
      glNormalPointer(GL_FLOAT, 0, nv.data());
      glVertexPointer( 3, GL_FLOAT, 0, v.data());
      if (tapas){
         glDrawElements( GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, f.data()); 
      }
      else{
         glDrawElements( GL_TRIANGLES, (f.size()-sizeTapas)*3, GL_UNSIGNED_INT, f.data()); 
      }
   }   

   glDisableClientState( GL_VERTEX_ARRAY );
}
// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)

//FUncion para crear VBOs

GLuint Malla3D::CrearVBO(GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram){

   GLuint id_vbo;
   glGenBuffers(1,&id_vbo);
   glBindBuffer(tipo_vbo, id_vbo);
   glBufferData(tipo_vbo,tamanio_bytes, puntero_ram,GL_STATIC_DRAW);
   glBindBuffer(tipo_vbo, 0);

   return id_vbo;
}


void Malla3D::draw_ModoDiferido(GLenum visual, bool ajedrez, bool tapas, bool luces)
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   if (id_vbo_ver==0)
      id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, sizeof (float)* v.size()*3, v.data());

   if (id_vbo_tri==0)
      id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, sizeof (int)* f.size()*3, f.data());

   //VBOs colores

   if (id_vbo_rojo==0)
      id_vbo_rojo = CrearVBO(GL_ARRAY_BUFFER, sizeof (float)* colorR.size()*3, colorR.data());

   if (id_vbo_verde==0)
      id_vbo_verde = CrearVBO(GL_ARRAY_BUFFER, sizeof (float)* colorG.size()*3, colorG.data());

   if (id_vbo_azul==0)
      id_vbo_azul = CrearVBO(GL_ARRAY_BUFFER, sizeof (float)* colorB.size()*3, colorB.data());

   if (id_vbo_color==0)
      id_vbo_color = CrearVBO(GL_ARRAY_BUFFER, sizeof (float)* color.size()*3, color.data());


   //VBOs ajedrez

   if (id_vbo_tri1==0)
      id_vbo_tri1 = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, sizeof (int)* f1.size()*3, f1.data());

   if (id_vbo_tri2==0)
      id_vbo_tri2 = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, sizeof (int)* f2.size()*3, f2.data());



   //especificar localizacion y formato tabla vertices 
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver);
   glVertexPointer(3,GL_FLOAT,0,0);
   glBindBuffer(GL_ARRAY_BUFFER,0);
   glEnableClientState(GL_VERTEX_ARRAY);

   glPolygonMode(GL_FRONT_AND_BACK,visual);
   
   if(!luces){
      glDisable(GL_LIGHTING);
      if (!ajedrez){
         switch (visual){
            case GL_POINT:
               glBindBuffer(GL_ARRAY_BUFFER, id_vbo_rojo);
               break;
            case GL_LINE:
               glBindBuffer(GL_ARRAY_BUFFER, id_vbo_verde);
               break;
            case GL_FILL:
               glBindBuffer(GL_ARRAY_BUFFER, id_vbo_color);
               break;
         }
         glColorPointer( 3, GL_FLOAT,0,0);
         glBindBuffer(GL_ARRAY_BUFFER,0);
         glEnableClientState(GL_COLOR_ARRAY);

         //VisuallizarTriangulos
         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri);
         if (tapas){
            glDrawElements( GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, 0);
         }else{
            glDrawElements( GL_TRIANGLES, (f.size()-sizeTapas)*3, GL_UNSIGNED_INT, 0);
         }
      }
      else{

         glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

         //TRIANGULOS VERDES
         glBindBuffer(GL_ARRAY_BUFFER, id_vbo_verde);
         glColorPointer( 3, GL_FLOAT,0,0);
         glBindBuffer(GL_ARRAY_BUFFER,0);
         glEnableClientState(GL_COLOR_ARRAY);
         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri1);
         if (tapas){
            glDrawElements(GL_TRIANGLES,3*f.size()/2, GL_UNSIGNED_INT,0);
         }
         else{
            glDrawElements(GL_TRIANGLES,3*(f.size()-sizeTapas)/2, GL_UNSIGNED_INT,0);
         }

         //TRIANGULOS ROJOS
         glBindBuffer(GL_ARRAY_BUFFER, id_vbo_rojo);
         glColorPointer( 3, GL_FLOAT,0,0);
         glBindBuffer(GL_ARRAY_BUFFER,0);
         glEnableClientState(GL_COLOR_ARRAY);
         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri2);
         if (tapas){
            glDrawElements(GL_TRIANGLES,3*f.size()/2, GL_UNSIGNED_INT,0);
         }
         else{
            glDrawElements(GL_TRIANGLES,3*(f.size()-sizeTapas)/2, GL_UNSIGNED_INT,0);
         }
      }
   }
   else{
      glEnable(GL_LIGHTING);
      glEnableClientState(GL_NORMAL_ARRAY);
      glNormalPointer(GL_FLOAT,0,nv.data());
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri);
      if (tapas){
         glDrawElements( GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, 0);
      }else{
         glDrawElements( GL_TRIANGLES, (f.size()-sizeTapas)*3, GL_UNSIGNED_INT, 0);
      }
   }

   
   

   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
   glDisableClientState(GL_VERTEX_ARRAY);
}
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw(modoDibujado modo, GLenum visual, bool ajedrez, bool tapas, bool luces)
{
   glPointSize(4);
   glEnable(GL_CULL_FACE); 
   glEnable(GL_NORMALIZE);
   m.aplicar();

   if (ct.size() != 0){
      glTexCoordPointer(2,GL_FLOAT,0,ct.data());
      glEnable(GL_TEXTURE_2D);
      textura->activar();
      glEnableClientState( GL_TEXTURE_COORD_ARRAY);
   }

   if (modo==modoDibujado::INMEDIATO)
      draw_ModoInmediato(visual, ajedrez, tapas, luces);
   else 
      draw_ModoDiferido(visual, ajedrez, tapas, luces);

   if (ct.size() != 0){
      glDisableClientState( GL_TEXTURE_COORD_ARRAY);
      glDisable(GL_TEXTURE_2D);
   }
}

void Malla3D::inicializarColores(){

   Tupla3f rojo(1,0,0); //ROJO
   Tupla3f verde(0,1,0); //VERDE
   Tupla3f azul(0,0,1); //AZUL
   for (int i=0; i<v.size();i++){
      colorR.push_back(rojo);
      colorG.push_back(verde);
      colorB.push_back(azul);
      color.push_back(azul);
   }

   for (int i=0 ; i<f.size() ; i+=2){
      f1.push_back(f[i]);
      f2.push_back(f[i+1]);
   }
}

void Malla3D::calcular_normales(){
   
   std::vector<Tupla3f> nf;
   Tupla3f a,b,mc,nc;
   Tupla3f q,p,r;

   for (int i=0 ; i<f.size() ; i++){
      p= v[f[i][X]];
      q= v[f[i](Y)];
      r= v[f[i](Z)];

      a = q-p;
      b = r-p;

      mc = a.cross(b);
      nc = mc.normalized();

      nf.push_back(nc);
   }

   nv.resize(v.size());

   for (int i=0 ; i<v.size(); i++){
      nv[i](X)=0;
      nv[i](Y)=0;
      nv[i](Z)=0;
   }

   for (int i=0 ; i<f.size() ; i++){
      nv[f[i](X)] = nf[i] + nv[f[i](X)];
      nv[f[i](Y)] = nf[i] + nv[f[i](Y)];
      nv[f[i](Z)] = nf[i] + nv[f[i](Z)];
   }

   for (int i=0 ; i<nv.size(); i++){
      nv[i] = nv[i].normalized();
      //std::cout << nv[i]<<std::endl;
   }
}

void Malla3D::setMaterial(Material  mat){
   m = mat;
}

void Malla3D::setColor(Tupla3f ncolor){

   std::vector<Tupla3f> aux;

   for (int i=0; i<v.size();i++){
      aux.push_back(ncolor);
   }

   id_vbo_color=0;

   color = aux;
}