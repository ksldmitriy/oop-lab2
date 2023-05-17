#pragma once
#include <exception>
#include <string>
#include <variant>
#include <vector>

using namespace std;

class invalid_table_elemet_request : public exception {};

enum class TableElementType : size_t {
  StringElement = 0,
  IntElement = 1,
  FloatElement = 2
};

class TableElement {
private:
  variant<string, int, float> value;

public:
  TableElement() = default;
  TableElement(string str);
  TableElement(int number);
  TableElement(float number);

  string GetString();
  int GetInt();
  float GetFloat();

  TableElementType GetType();
};

struct TableRow {
  vector<TableElement> elements;
};

struct Table {
  vector<TableRow> lines;
};
