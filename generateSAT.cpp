#include "generateSAT.h"
#include <algorithm>

std::string getPrefix(int i) {
    int m = 'z' - 'a' + 1;
    std::string prefix;
    if (i == 0)
        prefix = "a";
    while (i > 0) {
        int r = i % m;
        prefix += char('a' + r);
        i /= m;
    }
    std::reverse(prefix.begin(), prefix.end());
    return prefix;
}

std::string getSuffix(int i) {
    int m = 10;
    std::string suffix;
    if (i == 0)
        suffix = "0";
    while (i > 0) {
        int r = i % m;
        suffix += char('0' + r);
        i /= m;
    }
    std::reverse(suffix.begin(), suffix.end());
    return suffix;
}

std::vector<std::string> generateNames(int n) {
    std::vector<std::string> names(0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            names.push_back(getPrefix(i) + getSuffix(j));
        }
    }
    return names;
}

void makeVertical(int n, const std::vector<std::string> &names, std::vector<std::vector<std::string>> &clauses) {
    for (int i = 0; i < n; ++i) {
        clauses.emplace_back();
        for (int j = 0; j < n; ++j) {
            clauses.back().push_back(names[j * n + i]);
        }
    }
}

void makeHorizontal(int n, const std::vector<std::string> &names, std::vector<std::vector<std::string>> &clauses) {
    for (int i = 0; i < n; ++i) {
        clauses.emplace_back();
        for (int j = 0; j < n; ++j) {
            clauses.back().push_back(names[i * n + j]);
        }
    }
}

void makeDiagonal(int n, const std::vector<std::string> &names, std::vector<std::vector<std::string>> &clauses) {
    for (int sum = 0; sum < 2 * n - 1; ++sum) {
        clauses.emplace_back();
        for (int j = std::max(0, sum - n + 1); j < std::min(n, sum + 1); ++j) {
            clauses.back().push_back(names[(sum - j) * n + j]);
        }
    }
    for (int diff = -n + 1; diff < n; ++diff) {
        clauses.emplace_back();
        for (int i = std::max(0, diff); i < std::min(n, n + diff); ++i) {
            clauses.back().push_back(names[i * n + (i - diff)]);
        }
    }
}