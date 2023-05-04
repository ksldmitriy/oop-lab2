#include "application.hpp"

void Application::Run() {
  vector<fs::path> csv_files = GetCSVDirectoryFiles("input");

  for (auto &filepath : csv_files) {
    ProcessFile(filepath);
  }
}

void Application::ProcessFile(fs::path filepath) {
  vector<string> file_content = FileReader::ReadStringsFromFile(filepath);
  CSVTable table = CSVParser::Parse(file_content);
}

vector<fs::path> Application::GetCSVDirectoryFiles(fs::path folder) {
  vector<fs::path> files = GetDirectoryFiles(folder);

  vector<fs::path> csv_files;

  for (auto &file : files) {
    if (file.extension() == ".csv") {
      csv_files.push_back(file);
    }
  }

  return csv_files;
}

vector<fs::path> Application::GetDirectoryFiles(fs::path folder) {
  vector<fs::path> files;

  for (auto &folder_entery : fs::directory_iterator(folder)) {
    if (folder_entery.is_regular_file()) {
      files.push_back(folder_entery.path());
    }
  }

  return files;
}
