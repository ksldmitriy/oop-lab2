#pragma once
#include "table.hpp"
#include <array>
#include <map>
#include <stdexcept>

using namespace std;

//class 

class CompetitionResults {
private:
  static constexpr int voters_count = 20;
  
  array<int, voters_count> typedef Votes;
  map<string, Votes> votes;

  Votes ReadVotesFromTableRow(TableRow &table_row);

public:
  CompetitionResults() = default;
  void LoadVotesTable(Table &votes_table);
};
