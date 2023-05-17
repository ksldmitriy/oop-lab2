#include "points_counter.hpp"

vector<int> PointsCounter::CalculatePoints(vector<int> &votes) {
  vector<int> places = GetPlacesFromVotesCount(votes);

  vector<int> points(votes.size(), 0);
  for (int i = 0; i < votes.size(); i++) {
    points[i] = GetPointsFromPlace(places[i]);
  }

  return points;
}

vector<int> PointsCounter::GetPlacesFromVotesCount(vector<int> &votes) {
  struct Participant {
    int participant;
    int votes;
  };

  vector<Participant> participants(votes.size());
  for (int i = 0; i < votes.size(); i++) {
    participants[i].participant = i;
    participants[i].votes = votes[i];
  }

  sort(participants.begin(), participants.end(),
       [](const Participant &p1, const Participant &p2) {
         return p1.votes > p2.votes;
       });

  vector<int> places(votes.size());

  for (int i = 0; i < votes.size(); i++) {
    places[participants[i].participant] = i + 1;
  }

  return places;
}

int PointsCounter::GetPointsFromPlace(int place) {
  if (place == 1) {
    return 12;
  } else if (place == 2) {
    return 10;
  } else if (place <= 10) {
    return 11 - place;
  }

  return 0;
}
