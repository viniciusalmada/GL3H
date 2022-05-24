#ifndef GL3H_HEADER
#define GL3H_HEADER

#ifdef _WIN32
  #ifdef GL3H_DLL_EXPORT
    #define GL3H_API __declspec(dllexport)
  #else
    #define GL3H_API __declspec(dllimport)
  #endif
#else
  #define GL3H_API // nothing
#endif

#include <GL/glew.h>

#define GlCall(x)                                                              \
  GL3H::Log::GLClearError();                                                    \
  x;                                                                           \
  GL3H::Log::GLLogCall(#x, __FILE__, __LINE__)

namespace GL3H
{
  class Log
  {
  private:
    GL3H_API static bool isLogStarted;

    GL3H_API static void GLStartLogger();

  public:
    GL3H_API static void PrintMessage(const char* message);

    GL3H_API static void GLStopLogger();

    GL3H_API static void GLClearError();

    GL3H_API static bool
    GLLogCall(const char* function, const char* file, int line);
  };
}
#endif // !GL3H_HEADER
