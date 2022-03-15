#include <iostream>
#include <vector>
#include <stdexcept>
#include "generateSAT.h"
using namespace std;

int main() {
    vector<vector<string>> clauses;
    int n;
    cin >> n;
    vector<string> names = generateNames(n);
    if (names.size() != n * n) {
        throw runtime_error("names size isn't n * n");
    }
    makeVertical(n, names, clauses);
    makeHorizontal(n, names, clauses);
    makeDiagonal(n, names, clauses);

    return 0;
}