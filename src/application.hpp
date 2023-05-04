#pragma once
#include <filesystem>
#include "file_reader.hpp"
#include <iostream>
#include <string>

using namespace std;
namespace fs = filesystem;

class Application {
private:

  vector<fs::path> GetDirectoryFiles(fs::path folder);
  vector<fs::path> GetCSVDirectoryFiles(fs::path folder);
public:
  Application() = default;
  Application(Application &) = delete;
  Application &operator=(Application &) = delete;

  void Run();
};
