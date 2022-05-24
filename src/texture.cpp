#include "texture.hpp"

GL3H::Texture::Texture(unsigned char* buffer, int w, int h)
    : textureId(0), width(w), height(h)
{
  if (!buffer)
    return;

  GlCall(glGenTextures(1, &textureId));
  GlCall(glBindTexture(GL_TEXTURE_2D, textureId));

  GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
  GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
  GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
  GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

  GlCall(glTexImage2D(GL_TEXTURE_2D,
                      0,
                      GL_RGBA,
                      width,
                      height,
                      0,
                      GL_RGBA,
                      GL_UNSIGNED_BYTE,
                      buffer));
  GlCall(glGenerateMipmap(GL_TEXTURE_2D));

  delete[] buffer;
}

void GL3H::Texture::freeTexture() { GlCall(glDeleteTextures(1, &textureId)); }

void GL3H::Texture::bind(unsigned int slot) const
{
  GlCall(glActiveTexture(slot));
  GlCall(glBindTexture(GL_TEXTURE_2D, textureId));
}
