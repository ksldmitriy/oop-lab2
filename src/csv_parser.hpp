#include <iostream>
#include <sstream>
#include <string>
#include <variant>
#include <vector>
#include "table.hpp"

using namespace std;

class CSVParser {
private:
  static bool IsEmptyLine(string line);
  static bool TryParseInt(string raw_element, int &number);
  static bool TryParseFloat(string raw_element, float &number);
  static TableElement ParseElement(string raw_element);
  static TableRow ParseRow(string raw_row);

public:
  CSVParser() = delete;
  static Table Parse(vector<string>& raw_csv_table);
};
