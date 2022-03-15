//
// Created by DEVELOPER on 15.03.2022.
//
#include <vector>
#include <string>

#ifndef QUEENSPUZZLESATWITHC___GENERATESAT_H
#define QUEENSPUZZLESATWITHC___GENERATESAT_H

std::vector<int> generateNames(int n);
void makeVertical(int n, const std::vector<int> &names, std::vector<std::vector<int>> &clauses);
void makeHorizontal(int n, const std::vector<int> &names, std::vector<std::vector<int>> &clauses);
void makeDiagonal(int n, const std::vector<int> &names, std::vector<std::vector<int>> &clauses);

#endif //QUEENSPUZZLESATWITHC___GENERATESAT_H
