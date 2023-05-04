#include <vector>
#include <string>
#include <sstream>
#include <variant>

using namespace std;

variant<string, int, float> typedef CSVElement;

struct CSVLine{
  vector<CSVElement> elements;
};

struct CSVTable{
  vector<CSVLine> lines;
};

class CSVParser{
private:
  bool TryParseInt(string raw_element, int& number);
  bool TryParseFloat(string raw_element, float& number);
  CSVElement ParseElement(string raw_element);
  CSVLine ParseLine(string raw_line);
public:
  CSVParser() = default;
  CSVTable Parse(vector<string> raw_csv_table);
};
