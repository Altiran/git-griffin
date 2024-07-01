#ifndef COMMIT_ANALYSIS_H
#define COMMIT_ANALYSIS_H

#include "git_utils.h"

namespace CommitAnalysis {
    void analyzeCommits(const std::vector<GitUtils::Commit> &commits);
}

#endif // COMMIT_ANALYSIS_H
