#ifndef GL3H_VERTEX_BUFFER_LAYOUT
#define GL3H_VERTEX_BUFFER_LAYOUT

#include "gl3h.hpp"

#include <GL/glew.h>

namespace GL3H
{
  class AttribInfo
  {
  public:
    GL3H_API AttribInfo(unsigned int type, int count);

    unsigned int type;
    int count;

  public:
    GL3H_API unsigned long long bytesCount() const;
  };
}

#endif // GL3H_VERTEX_BUFFER_LAYOUT
