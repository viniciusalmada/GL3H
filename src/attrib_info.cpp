#include "attrib_info.hpp"

#include <GL/glew.h>

GL3H::AttribInfo::AttribInfo(unsigned int type, int count)
    : type(type), count(count)
{
}

unsigned long long GL3H::AttribInfo::bytesCount() const
{
  if (type == GL_INT)
    return count * sizeof(int);
  if (type == GL_FLOAT)
    return count * sizeof(float);
  if (type == GL_DOUBLE)
    return count * sizeof(double);
  return 0;
}