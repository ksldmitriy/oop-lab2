#include <string>
#include <vector>
#include <variant>

using namespace std;

enum class TableElementType : size_t {
  StringElement = 0,
  IntElement = 1,
  FloatElement = 2
};

variant<string, int, float> typedef TableElement;

struct TableRow {
  vector<TableElement> elements;
};

struct Table {
  vector<TableRow> lines;
};
