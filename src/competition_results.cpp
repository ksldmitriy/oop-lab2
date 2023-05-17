#include "competition_results.hpp"

void CompetitionResults::LoadVotesTable(Table &votes_table) {
  try {
    for (int i = 1; i < votes_table.lines.size(); i++) {
      TableRow &row = votes_table.lines[i];

      string country = row.elements[0].GetString();
	  

      Votes votes_for_country = ReadVotesFromTableRow(row);

      votes[country] = votes_for_country;
    }
  } catch (...) {
    throw invalid_argument("invalid votes table");
  }
}

CompetitionResults::Votes
CompetitionResults::ReadVotesFromTableRow(TableRow &table_row) {
  Votes votes;

  for (int i = 0; i < voters_count; i++) {
    votes[i] = table_row.elements[i + 1].GetInt();
  }

  return votes;
};
