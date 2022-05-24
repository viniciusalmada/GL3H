#include "vertex_array.hpp"

GL3H::VertexArray::VertexArray(const VertexBuffer& vb, const VertexLayout& layout)
    : vertexBuffer(vb)
{
  GlCall(glGenVertexArrays(1, &rendererId));
  this->bind();
  vb.bind();
  const std::vector<AttribInfo> attributes = layout.getLayout();
  unsigned long long offset = 0;

  for (unsigned int i = 0; i < attributes.size(); i++)
  {
    const auto& attrib = attributes[i];
    GlCall(glEnableVertexAttribArray(i));
    if (attrib.type == GL_INT)
    {
      GlCall(glVertexAttribIPointer(i,
                                    attrib.count,
                                    attrib.type,
                                    layout.stride(),
                                    (void*)offset));
    }
    else
    {
      GlCall(glVertexAttribPointer(i,
                                   attrib.count,
                                   attrib.type,
                                   false,
                                   layout.stride(),
                                   (void*)offset));
    }
    offset += attrib.bytesCount();
  }
  vb.unbind();
  unbind();
}

void GL3H::VertexArray::freeVertexArray()
{
  vertexBuffer.freeBuffer();
  GlCall(glDeleteVertexArrays(1, &rendererId));
}

void GL3H::VertexArray::updateBuffer(const void* data, unsigned int newSize)
{
  vertexBuffer.setData(data, newSize);
}

void GL3H::VertexArray::bind() const
{
  GlCall(glBindVertexArray(rendererId));
  vertexBuffer.bind();
}

void GL3H::VertexArray::unbind() const
{
  GlCall(glBindVertexArray(0));
  vertexBuffer.unbind();
}