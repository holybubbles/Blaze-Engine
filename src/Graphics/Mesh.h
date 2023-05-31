#pragma once

#include <GL/glew.h>
#include <vector>

class Mesh {
 public:
  Mesh(const std::vector<float>& vertices);

  void draw();
  ~Mesh();

 private:
  GLuint m_vbo;
  GLuint m_vao;
  const std::vector<float> m_vertices;
};
