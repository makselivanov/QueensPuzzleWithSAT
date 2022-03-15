#include <iostream>
#include <vector>
#include <stdexcept>
#include "generateSAT.h"
#include "cadical.hpp"
using namespace std;

int main() {
    vector<vector<int>> clauses;
    int n;
    cin >> n;
    vector<int> names = generateNames(n);
    if (names.size() != n * n) {
        throw runtime_error("names size isn't n * n");
    }
    makeVertical(n, names, clauses);
    makeHorizontal(n, names, clauses);
    makeDiagonal(n, names, clauses);

    auto *solver = new CaDiCaL::Solver;

    for (vector<int> &vec : clauses) {
        for (int elem: vec) {
            solver->add(elem);
        }
        solver->add(0);
    }
    int res = solver->solve();

    if (res == 10) {
        cout << "SATISFIED" << endl;
        vector<int> ans;
        for (int i = 0; i < n * n; ++i) {
            if (solver->val(names[i]) > 0) {
                ans.push_back(i);
            }
        }
        cout << "all true values in SAT from 1 to n^2: \n";
        for (int e: ans) {
            cout << names[e] << ' ';
        }
        cout << endl;
        cout << "Corresponding cells from 1 to n: \n";
        for (int e: ans) {
            cout << "(" << e / n + 1 << ", " <<  e % n + 1 << ") ";
        }
        cout << endl;
    } else if (res == 20) {
        cout << "UNSATISFIED" << endl;
    } else {
        cout << "UNSOLVED" << endl;
    }

    delete solver;

    return 0;
}
