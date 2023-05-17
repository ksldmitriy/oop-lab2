#include "table.hpp"

TableElement::TableElement(string str) { value = str; }

TableElement::TableElement(int number) { value = number; }

TableElement::TableElement(float number) { value = number; }

string TableElement::GetString() {
  if (value.index() != 0) {
	throw invalid_table_elemet_request();
  }

  return get<string>(value);
}

int TableElement::GetInt() {
  if (value.index() != 1) {
	throw invalid_table_elemet_request();
  }

  return get<int>(value);
}

float TableElement::GetFloat() {
  if (value.index() != 2) {
	throw invalid_table_elemet_request();
  }

  return get<float>(value);
}

TableElementType TableElement::GetType() {
  return (TableElementType)value.index();
}
