#pragma once
#include "csv_parser.hpp"
#include "file_reader.hpp"
#include <filesystem>
#include <iostream>
#include <string>

using namespace std;
namespace fs = filesystem;

class Application {
private:
  void ProcessFile(fs::path filepath);
  bool IsValidTable(CSVTable& table);
  vector<fs::path> GetDirectoryFiles(fs::path folder);
  vector<fs::path> GetCSVDirectoryFiles(fs::path folder);

public:
  Application() = default;
  Application(Application &) = delete;
  Application &operator=(Application &) = delete;

  void Run();
};
