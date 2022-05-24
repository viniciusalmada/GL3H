#include "index_buffer.hpp"

GL3H::IndexBuffer::IndexBuffer(const void* data, unsigned int count)
{
  this->count = count;
  GlCall(glGenBuffers(1, &bufferId));
  GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId));
  GlCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                      count * sizeof(unsigned int),
                      data,
                      GL_STATIC_DRAW));
  unbind();
}

void GL3H::IndexBuffer::freeBuffer() { GlCall(glDeleteBuffers(1, &bufferId)); }

void GL3H::IndexBuffer::bind() const
{
  GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId));
}

void GL3H::IndexBuffer::unbind() const
{
  GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void GL3H::IndexBuffer::setBuffer(const void* data, unsigned int new_count)
{
  bind();
  this->count = new_count;
  GlCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                      count * sizeof(unsigned int),
                      data,
                      GL_STATIC_DRAW));
  unbind();
}