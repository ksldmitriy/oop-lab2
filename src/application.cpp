#include "application.hpp"

void Application::Run() {
  vector<fs::path> csv_files = FileFinder::FindFilesInFolder("input", ".csv");

  for (auto &filepath : csv_files) {
    ProcessFile(filepath);
  }

  CompetitionResults competition_results(
      voting_results_deserializer.GetVotes());
  vector<CompetitionPlace> places = competition_results.CountPoints();
}

void Application::ProcessFile(fs::path filepath) {
  vector<string> file_content = FileReader::ReadStringsFromFile(filepath);

  cout << filepath << endl;
  Table table = CSVParser::Parse(file_content);

  voting_results_deserializer.LoadVotesTable(table);
}
