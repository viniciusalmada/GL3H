#ifndef GL3H_SHADER
#define GL3H_SHADER

#include "gl3h.hpp"

#include <string>
#include <unordered_map>
#include <utility>

namespace GL3H
{
  enum class GL3H_API ShaderType {
    VERTEX = GL_VERTEX_SHADER,
    FRAGMENT = GL_FRAGMENT_SHADER
  };

  struct ShaderSource
  {
    std::string source;
    ShaderType type;
  };

  class Shader
  {
  private:
    unsigned int programId;
    std::unordered_map<std::string, int> uniformLocations;
    std::pair<std::string, std::string> sources;

    GL3H_API unsigned int getUniformLocation(const std::string& name);

    GL3H_API unsigned int compileShader(unsigned int type, std::string source);

    GL3H_API void createProgram();

  public:
    GL3H_API static ShaderSource
    parseShaderString(const std::string& shaderSourcePath, ShaderType type);

  public:
    GL3H_API Shader(const ShaderSource& vertexShaderSource,
                    const ShaderSource& fragmentShaderSource);
    GL3H_API void freeProgram();

    GL3H_API void bind() const;
    GL3H_API void unbind() const;

    GL3H_API unsigned int getId() { return programId; }

    GL3H_API void setUniform1i(const std::string& name, int i);

    GL3H_API void
    setUniform1iv(const std::string& name, int i, const int* data);

    GL3H_API void
    setUniform3f(const std::string& name, float f0, float f1, float f2);

    GL3H_API void setUniformMatrix2fv(const std::string& name,
                                      const float* data);
  };
}

#endif // GL3H_SHADER
