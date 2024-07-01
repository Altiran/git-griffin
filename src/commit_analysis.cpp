#include "commit_analysis.h"
#include <iostream>
#include <map>
#include <vector>

void CommitAnalysis::analyzeCommits(const std::vector<GitUtils::Commit> &commits) {
    std::map<std::string, int> authorCommitCount;
    std::map<std::string, int> dateCommitCount;

    for (const auto &commit: commits) {
        authorCommitCount[commit.author]++;
        dateCommitCount[commit.date.substr(0, 10)]++; // count per day
    }

    std::cout << "Commit Analysis Report:" << std::endl;

    std::cout << "\nCommits per Author:" << std::endl;
    for (const auto &entry: authorCommitCount) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    std::cout << "\nCommits per Day:" << std::endl;
    for (const auto &entry: dateCommitCount) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}
