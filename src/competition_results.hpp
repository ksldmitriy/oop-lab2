#pragma once
#include "points_counter.hpp"
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

static constexpr int voters_count = 20;

array<int, voters_count> typedef Votes;

struct CompetitionPlace {
  string country;
  int points;
};

class CompetitionResults {
private:
  vector<string> countries;
  vector<Votes> votes;

  void CountPointsFromVoter(vector<int> &total_points, int voter);

public:
  CompetitionResults() = default;
  CompetitionResults(map<string, Votes> votes);
  vector<CompetitionPlace> CountPoints();
};
