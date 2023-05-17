#pragma once
#include "points_counter.hpp"
#include <array>
#include <iostream>
#include <map>
#include <string>

using namespace std;

static constexpr int voters_count = 20;

array<int, voters_count> typedef Votes;

class CompetitionResults {
private:
  // map<string, Votes> votes;
  vector<string> countries;
  vector<Votes> votes;

  void CountPointsFromVoter(vector<int> &total_points, int voter);

public:
  CompetitionResults() = default;
  CompetitionResults(map<string, Votes> votes);
  void CountPoints();
};
