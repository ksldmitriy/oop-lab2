#pragma once
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = filesystem;

class FileFinder {
private:
public:
  FileFinder() = delete;
  static vector<fs::path> FindFilesInFolder(fs::path folder, string extension = "");
};
