#include "voting_results_deserializer.hpp"

void VotingResultsDeserializer::LoadVotesTable(Table &votes_table) {
  try {
    if (votes_table.lines[0].elements[0].GetInt() !=
        votes_table.lines.size() - 1) {
      throw invalid_argument("invalid table passed to votes deserialize");
    }

    for (int i = 1; i < votes_table.lines.size(); i++) {
      TableRow &row = votes_table.lines[i];

      string country = row.elements[0].GetString();

      Votes votes_for_country = ReadVotesFromTableRow(row);

      if (votes.contains(country)) {
        // error
      }

      votes[country] = votes_for_country;
    }
  } catch (...) {
    throw invalid_argument("invalid votes table");
  }
}

map<string, Votes> VotingResultsDeserializer::GetVotes() { return votes; }

Votes VotingResultsDeserializer::ReadVotesFromTableRow(TableRow &table_row) {
  if (table_row.elements.size() != voters_count + 1) {
    throw invalid_argument("invalid votes table");
  }

  Votes votes;

  for (int i = 0; i < voters_count; i++) {
    votes[i] = table_row.elements[i + 1].GetInt();
  }

  return votes;
};
