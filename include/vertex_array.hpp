#ifndef GL3H_VERTEX_ARRAY
#define GL3H_VERTEX_ARRAY

#include "gl3h.hpp"
#include "vertex_buffer.hpp"
#include "vertex_layout.hpp"

namespace GL3H
{
  class VertexArray
  {
  private:
    unsigned int rendererId;
    VertexBuffer vertexBuffer;

  public:
    GL3H_API VertexArray(const VertexBuffer& vb, const VertexLayout& layout);
    GL3H_API void freeVertexArray();

    GL3H_API void updateBuffer(const void* data, unsigned int newSize);

    GL3H_API void bind() const;
    GL3H_API void unbind() const;
  };
}

#endif // !GL3H_VERTEX_ARRAY
