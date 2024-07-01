#include "git_utils.h"
#include <cstdlib>
#include <sstream>
#include <iostream>

std::vector<GitUtils::Commit> GitUtils::getCommits(const std::string &repoPath) {
    std::vector<Commit> commits;
    std::string command = "git -C " + repoPath + " log --pretty=format:'%H;%an;%ad;%s' --date=iso";

    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe) throw std::runtime_error("Failed to run git log command");

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::string line(buffer);
        std::istringstream iss(line);
        std::string token;

        Commit commit;
        std::getline(iss, commit.hash, ';');
        std::getline(iss, commit.author, ';');
        std::getline(iss, commit.date, ';');
        std::getline(iss, commit.message, ';');

        commits.push_back(commit);
    }

    pclose(pipe);
    return commits;
}
