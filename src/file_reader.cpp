#include "file_reader.hpp"

vector<string> FileReader::ReadStringsFromFile(fs::path filepath) {
  ifstream file(filepath);

  if (!file) {
    throw ifstream::failbit;
  }

  vector<string> content;

  while (!file.eof()) {
    string line;
    getline(file, line);

    content.push_back(line);
  }

  return content;
}

int FileReader::i = 0;
