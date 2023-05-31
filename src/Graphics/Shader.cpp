#include "Shader.h"
#include <iostream>
#include "../../src/Util/FileLoader.h"

Shader::Shader(const std::string& shaderPath) {
  m_shaderProgram = glCreateProgram();

  std::string vertexShaderPath = shaderPath + ".vs";
  std::string fragmentShaderPath = shaderPath + ".fs";

  m_vertexShader = createShader(FileLoader::LoadTextFile(vertexShaderPath),
                                ShaderType::VertexShader);
  m_fragmentShader = createShader(FileLoader::LoadTextFile(fragmentShaderPath),
                                  ShaderType::FragmentShader);

  glAttachShader(m_shaderProgram, m_vertexShader);
  glAttachShader(m_shaderProgram, m_fragmentShader);

  glLinkProgram(m_shaderProgram);

  GLint success;
  char infoLog[512];
  glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
    std::cout << "SHADER PROGRAM LINK ERROR: " << infoLog << std::endl;
  }
}

Shader::~Shader() {
  glDetachShader(m_shaderProgram, m_vertexShader);
  glDeleteShader(m_vertexShader);
  glDetachShader(m_shaderProgram, m_fragmentShader);
  glDeleteShader(m_fragmentShader);

  glDeleteProgram(m_shaderProgram);
}

GLuint Shader::createShader(const std::string& shaderSource, ShaderType type) {
  GLuint shader;

  if (type == ShaderType::VertexShader) {
    shader = glCreateShader(GL_VERTEX_SHADER);
  } else if (type == ShaderType::FragmentShader) {
    shader = glCreateShader(GL_FRAGMENT_SHADER);
  }

  const char* shaderContents = shaderSource.c_str();

  glShaderSource(shader, 1, &shaderContents, NULL);

  glCompileShader(shader);

  // Check for errors compiling shader
  GLint success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

  if (!success) {
    // Shader did not compile
    char buffer[512];
    glGetShaderInfoLog(m_vertexShader, 512, NULL, buffer);
    std::cout << "Shader Compiler Error! " << buffer << std::endl;
  } else {
    // std::cout << "Successfuly compiled shader. Shader Id: " << shader
    //           << std::endl;
  }

  return shader;
}

void Shader::use() {
  glUseProgram(m_shaderProgram);
}