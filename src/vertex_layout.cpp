#include "vertex_layout.hpp"

GL3H::VertexLayout::VertexLayout(const std::vector<AttribInfo>& attrs)
    : attributes(attrs)
{
}

int GL3H::VertexLayout::stride() const
{
  unsigned long strideSize = 0;
  for (const AttribInfo& attribInfo : attributes)
  {
    switch (attribInfo.type)
    {
    case GL_INT:
      strideSize += sizeof(int) * attribInfo.count;
      break;
    case GL_DOUBLE:
      strideSize += sizeof(double) * attribInfo.count;
      break;
    case GL_FLOAT:
      strideSize += sizeof(float) * attribInfo.count;
      break;
    }
  }
  return static_cast<int>(strideSize);
}

std::vector<GL3H::AttribInfo> GL3H::VertexLayout::getLayout() const
{
  return attributes;
}