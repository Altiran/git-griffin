cmake_minimum_required(VERSION 3.10)
project(GitGriffin)

set(CMAKE_CXX_STANDARD 11)

add_executable(GitGriffin src/main.cpp src/git_utils.cpp src/commit_analysis.cpp)
