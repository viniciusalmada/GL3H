#ifndef GL3H_TEXTURE
#define GL3H_TEXTURE

#include "gl3h.hpp"

namespace GL3H
{
  class Texture
  {
  private:
    unsigned int textureId;
    int width;
    int height;

  public:
    GL3H_API Texture() : textureId(0), width(0), height(0){};
    GL3H_API Texture(unsigned char* buffer, int w, int h);
    GL3H_API void freeTexture();

    GL3H_API void bind(unsigned int slot) const;

    GL3H_API inline int getWidth() const { return width; }
    GL3H_API inline int getHeight() const { return height; }
  };
}

#endif // !GL3H_TEXTURE
