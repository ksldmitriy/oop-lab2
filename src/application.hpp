#pragma once
#include "csv_parser.hpp"
#include "file_reader.hpp"
#include <filesystem>
#include <iostream>
#include <string>
#include "voting_results_deserializer.hpp"

using namespace std;
namespace fs = filesystem;

class Application {
private:
  VotingResultsDeserializer voting_results_deserializer;
  CompetitionResults voting_results;

  void ProcessFile(fs::path filepath);
  vector<fs::path> GetDirectoryFiles(fs::path folder);
  vector<fs::path> GetCSVDirectoryFiles(fs::path folder);

public:
  Application() = default;
  Application(Application &) = delete;
  Application &operator=(Application &) = delete;

  void Run();
};
