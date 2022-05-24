#ifndef GL3H_LAYOUT_HEADER
#define GL3H_LAYOUT_HEADER

#include "attrib_info.hpp"
#include "gl3h.hpp"

#include <vector>

namespace GL3H
{
  class VertexLayout
  {
  public:
    GL3H_API VertexLayout(const std::vector<AttribInfo>&);

    GL3H_API std::vector<AttribInfo> getLayout() const;

    GL3H_API int stride() const;

  private:
    std::vector<AttribInfo> attributes;
  };
}

#endif // GL3H_LAYOUT_HEADER
