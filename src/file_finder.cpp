#include "file_finder.hpp"

vector<fs::path> FileFinder::FindFilesInFolder(fs::path folder,
                                               string extension) {
  vector<fs::path> files;

  for (auto &folder_entery : fs::directory_iterator(folder)) {
    if (!folder_entery.is_regular_file()) {
      continue;
    }

    fs::path filename = folder_entery.path();

    if (filename.extension() == extension) {
      files.push_back(folder_entery.path());
    }
  }

  return files;
}
