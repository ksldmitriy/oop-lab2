#pragma once
#include <exception>
#include <string>
#include <variant>
#include <vector>

using namespace std;

enum class TableElementType : size_t {
  StringElement = 0,
  IntElement = 1,
  FloatElement = 2
};

class TableElementAccessException : public exception {
private:
public:
  TableElementAccessException() = default;
  const char *what();
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
