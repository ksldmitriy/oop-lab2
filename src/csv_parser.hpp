#include <sstream>
#include <string>
#include <variant>
#include <vector>
#include <iostream>

using namespace std;

enum class CSVElementType {
  StringElement = 0,
  IntElement = 1,
  FloatElement = 2
};

variant<string, int, float> typedef CSVElement;

struct CSVLine {
  vector<CSVElement> elements;
};

struct CSVTable {
  vector<CSVLine> lines;
};

class CSVParser {
private:
  static bool TryParseInt(string raw_element, int &number);
  static bool TryParseFloat(string raw_element, float &number);
  static CSVElement ParseElement(string raw_element);
  static CSVLine ParseLine(string raw_line);

public:
  CSVParser() = delete;
  static CSVTable Parse(vector<string> raw_csv_table);
};
