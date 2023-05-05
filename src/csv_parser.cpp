#include "csv_parser.hpp"

Table CSVParser::Parse(vector<string> raw_csv_table) {
  Table table;

  for (string &raw_row : raw_csv_table) {
    if (IsEmptyLine(raw_row)) {
      continue;
    }

    TableRow row = ParseRow(raw_row);
    table.lines.push_back(row);
  }

  return table;
}

bool CSVParser::IsEmptyLine(string line) {
  for (auto i : line) {
    if (isprint(i)) {
      return false;
    }
  }

  return true;
}

TableRow CSVParser::ParseRow(string raw_row) {
  stringstream raw_row_stream(raw_row);
  string raw_element;

  vector<TableElement> elements;

  while (getline(raw_row_stream, raw_element, ',')) {
    TableElement element = ParseElement(raw_element);
    elements.push_back(element);
  }

  return TableRow{elements};
}

TableElement CSVParser::ParseElement(string raw_element) {
  TableElement element;
  bool is_parsed;

  int int_element;
  is_parsed = TryParseInt(raw_element, int_element);
  if (is_parsed) {
    element = int_element;
    return element;
  }

  float float_element;
  is_parsed = TryParseFloat(raw_element, float_element);
  if (is_parsed) {
    element = float_element;
    return element;
  }

  element = raw_element;
  return element;
}

bool CSVParser::TryParseInt(string raw_element, int &number) {
  char *e;
  errno = 0;

  try {
    number = strtoll(raw_element.data(), &e, 0);
  } catch (...) {
    return false;
  }

  return errno == 0 && raw_element.data() + raw_element.size() == e;
}

bool CSVParser::TryParseFloat(string raw_element, float &number) {
  size_t read = 0;
  errno = 0;

  try {
    number = stof(raw_element.data(), &read);
  } catch (...) {
    return false;
  }

  return errno == 0 && raw_element.size() == read;
}
