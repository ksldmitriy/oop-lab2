#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class PointsCounter {
private:
  static int GetPointsFromPlace(int place);
  static vector<int> GetPlacesFromVotesCount(vector<int> &votes);

public:
  PointsCounter() = delete;
  static vector<int> CalculatePoints(vector<int> &votes);
};
