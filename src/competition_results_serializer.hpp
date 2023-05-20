#pragma once
#include "competition_results.hpp"
#include <iostream>

using namespace std;

class CompetitionResultsSerialize {
private:
public:
  void Serialize(ofstream &output_stream, vector<CompetitionPlace> places);
};
