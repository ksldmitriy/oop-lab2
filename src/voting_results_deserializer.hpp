#pragma once
#include "table.hpp"
#include "competition_results.hpp"
#include <stdexcept>

using namespace std;

class VotingResultsDeserializer {
private:
  map<string, Votes> votes;

  Votes ReadVotesFromTableRow(TableRow &table_row);

public:
  VotingResultsDeserializer() = default;

  void LoadVotesTable(Table &votes_table);
  map<string, Votes>  GetVotes();
};
