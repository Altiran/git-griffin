#include <iostream>
#include "git_utils.h"
#include "commit_analysis.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <repo_path>" << std::endl;
        return 1;
    }

    std::string repo_path = argv[1];

    try {
        auto commits = GitUtils::getCommits(repo_path);
        CommitAnalysis::analyzeCommits(commits);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
