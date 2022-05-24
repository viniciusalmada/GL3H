#include "vertex_buffer.hpp"

GL3H::VertexBuffer::VertexBuffer(const void* data, unsigned int size)
    : size(size)
{
  GlCall(glGenBuffers(1, &bufferId));
  GlCall(glBindBuffer(GL_ARRAY_BUFFER, bufferId));
  GlCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
  unbind();
}

void GL3H::VertexBuffer::freeBuffer() { GlCall(glDeleteBuffers(1, &bufferId)); }

void GL3H::VertexBuffer::setData(const void* data, unsigned int newSize)
{
  if (newSize != 0)
    size = newSize;
  bind();
  GlCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
  unbind();
}

void GL3H::VertexBuffer::bind() const
{
  GlCall(glBindBuffer(GL_ARRAY_BUFFER, bufferId));
}

void GL3H::VertexBuffer::unbind() const
{
  GlCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}