#include "gl3h.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

bool GL3H::Log::isLogStarted = false;

void GL3H::Log::GLStartLogger()
{
  if (isLogStarted)
    return;
  isLogStarted = true;
  PrintMessage("--START APPLICATION--");
}

#if defined(_WIN32)
  #pragma warning(push)
  #pragma warning(disable : 4100) // unreferenced formal parameter
#elif defined(__linux__)
  #pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
void GL3H::Log::PrintMessage(const char* message)
{
  if (!isLogStarted)
    return;
#ifdef DEBUG // CMake debug flag
  std::cout << message << std::endl;
#endif
}
#if defined(_WIN32)
  #pragma warning(pop)
#elif defined(__linux__)
  #pragma GCC diagnostic warning "-Wunused-parameter"
#endif

void GL3H::Log::GLStopLogger()
{
  if (isLogStarted)
  {
    PrintMessage("--STOP APPLICATION--");
    isLogStarted = false;
  }
}

void GL3H::Log::GLClearError()
{
  GLStartLogger();
  const int MAX_COUNT = 100;
  int count = 0;
  while (glGetError() != GL_NO_ERROR)
  {
    count++;
    if (count >= MAX_COUNT)
    {
      PrintMessage("[GL3] Has reached maximum calls to GLClearError!");
      break;
    }
  };
}

bool GL3H::Log::GLLogCall(const char* function, const char* file, int line)
{
  while (GLenum error = glGetError())
  {
    std::stringstream ss;
    ss << "[GL3] (0x" << std::setprecision(4) << std::hex << error
       << "): " << function << " " << file << ":" << std::dec << line
       << std::endl;
    PrintMessage(ss.str().c_str());
    return false;
  }
  return true;
}
