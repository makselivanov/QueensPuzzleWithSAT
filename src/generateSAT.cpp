#include "generateSAT.h"
#include <algorithm>

std::vector<int> generateNames(int n) {
    std::vector<int> names(0);
    for (int i = 0; i < n * n; ++i) {
        names.push_back(i + 1);
    }
    return names;
}

void makeVertical(int n, const std::vector<int> &names, std::vector<std::vector<int>> &clauses) {
    for (int i = 0; i < n; ++i) {
        clauses.emplace_back();
        for (int j = 0; j < n; ++j) {
            clauses.back().push_back(names[j * n + i]);
        }
        for (int first = 0; first < n; ++first) {
            for (int second = 0; second < first; ++second) {
                clauses.emplace_back();
                clauses.back().push_back(-names[first * n + i]);
                clauses.back().push_back(-names[second * n + i]);
            }
        }
    }
}

void makeHorizontal(int n, const std::vector<int> &names, std::vector<std::vector<int>> &clauses) {
    for (int i = 0; i < n; ++i) {
        clauses.emplace_back();
        for (int j = 0; j < n; ++j) {
            clauses.back().push_back(names[i * n + j]);
        }
        for (int first = 0; first < n; ++first) {
            for (int second = 0; second < first; ++second) {
                clauses.emplace_back();
                clauses.back().push_back(-names[i * n + first]);
                clauses.back().push_back(-names[i * n + second]);
            }
        }
    }

}

void makeDiagonal(int n, const std::vector<int> &names, std::vector<std::vector<int>> &clauses) {
    for (int sum = 0; sum < 2 * n - 1; ++sum) {
        for (int first = std::max(0, sum - n + 1); first < std::min(n, sum + 1); ++first) {
            for (int second = std::max(0, sum - n + 1); second < first; ++second) {
                clauses.emplace_back();
                clauses.back().push_back(-names[(sum - first) * n + first]);
                clauses.back().push_back(-names[(sum - second) * n + second]);
            }
        }
    }
    for (int diff = -n + 1; diff < n; ++diff) {
        for (int first = std::max(0, diff); first < std::min(n, n + diff); ++first) {
            for (int second = std::max(0, diff); second < first; ++second) {
                clauses.emplace_back();
                clauses.back().push_back(-names[first * n + first - diff]);
                clauses.back().push_back(-names[second * n + second - diff]);
            }
        }
    }
}