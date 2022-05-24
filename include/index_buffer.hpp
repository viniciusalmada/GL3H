#ifndef GL3H_INDEX_BUFFER
#define GL3H_INDEX_BUFFER

#include "gl3h.hpp"

namespace GL3H
{
  class IndexBuffer
  {
  private:
    unsigned int bufferId;
    unsigned int count;

  public:
    GL3H_API IndexBuffer(const void* data, unsigned int count);
    GL3H_API void freeBuffer();

    GL3H_API void bind() const;
    GL3H_API void unbind() const;

    GL3H_API unsigned int getCount() const { return count; }

    GL3H_API void setBuffer(const void* data, unsigned int count);
  };
}

#endif // GL3H_INDEX_BUFFER