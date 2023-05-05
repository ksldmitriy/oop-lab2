#include "application.hpp"

void Application::Run() {
  vector<fs::path> csv_files = GetCSVDirectoryFiles("input");

  for (auto &filepath : csv_files) {
    ProcessFile(filepath);
  }
}

void Application::ProcessFile(fs::path filepath) {
  vector<string> file_content = FileReader::ReadStringsFromFile(filepath);
  Table table = CSVParser::Parse(file_content);
  if (IsValidTable(table)) {
    cout << "is valid table" << endl;
  }
  cout << endl;
}

bool Application::IsValidTable(Table &table) {
  if (table.lines.size() < 1) {
    return false;
  }
  if (table.lines[0].elements.size() != 1) {
    return false;
  }
  if (table.lines[0].elements[0].index() !=
      (size_t)TableElementType::IntElement) {
    return false;
  }

  int lines_count =
      get<(size_t)TableElementType::IntElement>(table.lines[0].elements[0]);

  if (lines_count + 1 != table.lines.size()) {
    cout << "l " << lines_count + 1 << " " << table.lines.size() << endl;
    return false;
  }

  for (int i = 1; i < table.lines.size(); i++) {
    TableRow &line = table.lines[i];

    if (line.elements.size() != 21) {
      return false;
    }

    if (line.elements[0].index() != (size_t)TableElementType::StringElement) {
      return false;
    }

    cout << 3 << endl;
    for (int j = 1; j < line.elements.size(); j++) {
      if (line.elements[j].index() != (size_t)TableElementType::IntElement) {
        return false;
      }
    }
  }

  return true;
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
