#ifndef GIT_UTILS_H
#define GIT_UTILS_H

#include <vector>
#include <string>
#include <stdexcept>

namespace GitUtils {
    struct Commit {
        std::string hash;
        std::string author;
        std::string date;
        std::string message;
    };

    std::vector<Commit> getCommits(const std::string &repoPath);
}

#endif // GIT_UTILS_H
