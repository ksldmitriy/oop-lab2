#pragma once
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <exception>
#include <iostream>

using namespace std;
namespace fs = filesystem;

class FileReader {
  static int i;
public:
  FileReader() = delete;
  static vector<string> ReadStringsFromFile(fs::path filepath);
};
