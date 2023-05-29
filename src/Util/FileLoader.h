#pragma once
#include <fstream>
#include <iostream>
#include <string>

class FileLoader {
 public:
  FileLoader() = default;
  ~FileLoader() = default;

  static std::string LoadTextFile(const std::string& filePath) {
    std::string fileContents = "";
    std::ifstream file(filePath);

    if (!file.is_open()) {
      return nullptr;
    }

    while (file) {
      std::string line;
      std::getline(file, line);
      fileContents += line;
    }

    return std::move(fileContents);
  }
};
