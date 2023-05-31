#pragma once

#include <gl/glew.h>

#include <string>

class Shader {
 public:
  Shader(const std::string& shaderPath);
  ~Shader();

  void use();

  GLuint getProgram() const { return m_shaderProgram; };

 private:
  enum ShaderType { FragmentShader, VertexShader, GeometryShader };
  GLuint m_vertexShader;
  GLuint m_fragmentShader;
  GLuint m_shaderProgram;

  GLuint createShader(const std::string& shader, ShaderType type);
};
