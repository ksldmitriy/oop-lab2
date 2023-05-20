#include "competition_results.hpp"

CompetitionResults::CompetitionResults(map<string, Votes> votes) {

  for (auto i : votes) {
    this->countries.push_back(i.first);
    this->votes.push_back(i.second);
  }
}

vector<CompetitionPlace> CompetitionResults::CountPoints() {
  vector<int> points(votes.size(), 0);

  for (int i = 0; i < voters_count; i++) {
    CountPointsFromVoter(points, i);
  }

  vector<CompetitionPlace> places;

  for (int i = 0; i < votes.size(); i++) {
    CompetitionPlace place;
    place.country = countries[i];
    place.points = points[i];
    places.push_back(place);
  }

  sort(places.begin(), places.end(),
       [](const CompetitionPlace &p1, const CompetitionPlace &p2) {
         return p1.points > p2.points;
       });

  return places;
}

void CompetitionResults::CountPointsFromVoter(vector<int> &total_points,
                                              int voter) {
  vector<int> votes_from_one_voter(votes.size());
  for (int i = 0; i < votes.size(); i++) {
    votes_from_one_voter[i] = votes[i][voter];
  }

  vector<int> points = PointsCounter::CalculatePoints(votes_from_one_voter);

  for (int i = 0; i < votes.size(); i++) {
    total_points[i] += points[i];
  }
}
