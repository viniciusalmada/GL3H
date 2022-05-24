#include "shader.hpp"

#include "fstream"
#include "sstream"

unsigned int GL3H::Shader::getUniformLocation(const std::string& name)
{
  if (uniformLocations.find(name) != uniformLocations.end())
    return uniformLocations[name];

  GlCall(int location = glGetUniformLocation(programId, name.c_str()));
  if (location == -1)
  {
    std::stringstream ss;
    ss << "W: uniform " << name << " doesn't being used!" << std::endl;
    GL3H::Log::PrintMessage(ss.str().c_str());
  }

  uniformLocations[name] = location;
  return location;
}

unsigned int GL3H::Shader::compileShader(unsigned int type, std::string source)
{
  GlCall(unsigned int id = glCreateShader(type));
  auto sourceC = source.c_str();
  GlCall(glShaderSource(id, 1, &sourceC, nullptr));
  GlCall(glCompileShader(id));

  int result;
  GlCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
  if (!result)
  {
    int len;
    GlCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len));
    char* message = new char[len];
    GlCall(glGetShaderInfoLog(id, len, &len, message));
    std::stringstream ss;
    ss << "[GL3] " << message << std::endl;
    GL3H::Log::PrintMessage(ss.str().c_str());
    GlCall(glDeleteShader(id));
    delete[] message;
    return 0;
  }

  return id;
}

void GL3H::Shader::createProgram()
{
  GlCall(programId = glCreateProgram());
  GlCall(unsigned int vs = compileShader(GL_VERTEX_SHADER, sources.first));
  GlCall(unsigned int fs = compileShader(GL_FRAGMENT_SHADER, sources.second));

  GlCall(glAttachShader(programId, vs));
  GlCall(glAttachShader(programId, fs));
  GlCall(glLinkProgram(programId));
  int result;
  GlCall(glGetProgramiv(programId, GL_LINK_STATUS, &result));
  if (!result)
  {
    int len;
    GlCall(glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &len));
    char* message = new char[len];
    GlCall(glGetProgramInfoLog(programId, len, &len, message));
    std::stringstream ss;
    ss << "[GL3] " << message << std::endl;
    GL3H::Log::PrintMessage(ss.str().c_str());
    GlCall(glDeleteProgram(programId));
    programId = 0;
    delete[] message;
  }
  // GlCall(glValidateProgram(programId));

  GlCall(glDeleteShader(vs));
  GlCall(glDeleteShader(fs));

  bind();
}

GL3H::ShaderSource
GL3H::Shader::parseShaderString(const std::string& shaderSourcePath,
                               ShaderType type)
{
  std::stringstream stringStream{};
  std::ifstream ifStream(shaderSourcePath);
  std::string line;
  while (getline(ifStream, line))
  {
    stringStream << line << std::endl;
  }

  return { stringStream.str(), type };
}

GL3H::Shader::Shader(const ShaderSource& vertexShaderSource,
                    const ShaderSource& fragmentShaderSource)
{
  sources = { vertexShaderSource.source, fragmentShaderSource.source };
  createProgram();
}

void GL3H::Shader::freeProgram()
{
  if (glIsProgram(programId))
  {
    GlCall(glDeleteProgram(programId));
  }
}

void GL3H::Shader::bind() const
{
  if (glIsProgram(programId))
  {
    GlCall(glUseProgram(programId));
  }
}

void GL3H::Shader::unbind() const { GlCall(glUseProgram(0)); }

void GL3H::Shader::setUniform1i(const std::string& name, int i)
{
  GlCall(glUniform1i(getUniformLocation(name), i));
}

void GL3H::Shader::setUniform1iv(const std::string& name, int i, const int* data)
{
  GlCall(glUniform1iv(getUniformLocation(name), i, data));
}

void GL3H::Shader::setUniform3f(const std::string& name,
                               float f0,
                               float f1,
                               float f2)
{
  GlCall(glUniform3f(getUniformLocation(name), f0, f1, f2));
}

void GL3H::Shader::setUniformMatrix2fv(const std::string& name,
                                      const float* data)
{
  GlCall(glUniformMatrix2fv(getUniformLocation(name), 1, false, data));
}
