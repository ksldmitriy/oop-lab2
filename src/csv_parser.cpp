#include "csv_parser.hpp"

CSVTable CSVParser::Parse(vector<string> raw_csv_table) {
  CSVTable table;

  for (string &raw_line : raw_csv_table) {
    CSVLine line = ParseLine(raw_line);
    table.lines.push_back(line);
  }

  return table;
}

CSVLine CSVParser::ParseLine(string raw_line) {
  stringstream raw_line_stream(raw_line);
  string raw_element;

  vector<CSVElement> elements;

  while (getline(raw_line_stream, raw_element, ',')) {
    CSVElement element = ParseElement(raw_element);
    elements.push_back(element);
  }
}

CSVElement CSVParser::ParseElement(string raw_element) {
  CSVElement element;

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
}

bool CSVParser::TryParseInt(string raw_element, int &number) {}

bool CSVParser::TryParseFloat(string raw_element, float &number) {}
