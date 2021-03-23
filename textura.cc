#include "aux.h"
#include "textura.h"
#include "jpg_imagen.hpp"

Textura::Textura(std::string archivo){
      jpg::Imagen * pimg = NULL;

      pimg = new jpg::Imagen(archivo);

      tamx = pimg->tamX();
      tamy = pimg->tamY();
      texels = pimg->leerPixels();
}

void Textura::activar(){
      if (textura_id == 0){
            glGenTextures(1, &textura_id);

            glBindTexture(GL_TEXTURE_2D, textura_id);

            gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, tamx, tamy, GL_RGB, GL_UNSIGNED_BYTE, texels);
      }
      else{
            glBindTexture(GL_TEXTURE_2D, textura_id);
      }
}

