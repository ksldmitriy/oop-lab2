#pragma once
#include <iostream>
#include <array>
#include <map>
#include <string>

using namespace std;

static constexpr int voters_count = 20;

array<int, voters_count> typedef Votes;

class CompetitionResults {
private:
  map<string, Votes> votes;

public:
  CompetitionResults() = default;
  CompetitionResults(map<string, Votes> votes);
};
