#ifndef GL3H_VERTEX_BUFFER
#define GL3H_VERTEX_BUFFER

#include "gl3h.hpp"

namespace GL3H
{
  class VertexBuffer
  {
  private:
    unsigned int bufferId;
    unsigned int size;

  public:
    GL3H_API VertexBuffer(const void* data, unsigned int size);
    GL3H_API void freeBuffer();

    GL3H_API void setData(const void* data, unsigned int newSize);

    GL3H_API void bind() const;
    GL3H_API void unbind() const;
  };
}

#endif // GL3H_VERTEX_BUFFER