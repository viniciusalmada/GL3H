#ifndef GL3H_RENDERER
#define GL3H_RENDERER

#include "gl3h.hpp"
#include "index_buffer.hpp"
#include "shader.hpp"
#include "vertex_array.hpp"

namespace GL3H
{
  struct RendererData
  {
    VertexArray vertexArray;
    IndexBuffer indexBuffer;
    Shader shader;
  };

  class Renderer
  {
  private:
    RendererData rendererData;

  public:
    GL3H_API Renderer(RendererData data);
    GL3H_API void freeRenderer();

    GL3H_API void updateVertexBuffer(const void* data,
                                     unsigned int newSize = 0);

    GL3H_API void updateIndexBuffer(const unsigned int* data,
                                    unsigned int newSize = 0);

    GL3H_API void draw() const;

    GL3H_API Shader& getShader() { return rendererData.shader; };
  };
}
#endif // !GL3H_RENDERER
