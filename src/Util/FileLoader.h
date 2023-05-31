#pragma once
#include <filesystem>
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
      std::cout << "Could not open file - "
                << std::filesystem::current_path().append(filePath)
                << std::endl;
      return "";
    }

    while (file) {
      std::string line;
      std::getline(file, line);
      fileContents += line;
      fileContents += '\n';
    }

    return std::move(fileContents);
  }
};
