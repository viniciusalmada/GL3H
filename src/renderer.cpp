#include "renderer.hpp"

GL3H::Renderer::Renderer(RendererData data) : rendererData(data) {}

void GL3H::Renderer::freeRenderer()
{
  rendererData.indexBuffer.freeBuffer();
  rendererData.vertexArray.freeVertexArray();
  rendererData.shader.freeProgram();
  GL3H::Log::GLStopLogger();
}

void GL3H::Renderer::updateVertexBuffer(const void* data, unsigned int newSize)
{
  rendererData.vertexArray.updateBuffer(data, newSize);
}

void GL3H::Renderer::updateIndexBuffer(const unsigned int* data,
                                      unsigned int newSize)
{
  rendererData.indexBuffer.setBuffer(data, newSize);
}

void GL3H::Renderer::draw() const
{
  rendererData.shader.bind();
  rendererData.vertexArray.bind();
  rendererData.indexBuffer.bind();

  GlCall(glDrawElements(GL_TRIANGLES,
                        rendererData.indexBuffer.getCount(),
                        GL_UNSIGNED_INT,
                        nullptr));
};