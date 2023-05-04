#pragma once
#include "file_reader.hpp"
#include "csv_parser.hpp"
#include <filesystem>
#include <iostream>
#include <string>

using namespace std;
namespace fs = filesystem;

class Application {
private:
  vector<fs::path> GetDirectoryFiles(fs::path folder);
  vector<fs::path> GetCSVDirectoryFiles(fs::path folder);
  vector<CSVTable> ParseFiles(vector<fs::path>);

public:
  Application() = default;
  Application(Application &) = delete;
  Application &operator=(Application &) = delete;

  void Run();
};
