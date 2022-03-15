//
// Created by DEVELOPER on 15.03.2022.
//
#include <vector>
#include <string>

#ifndef QUEENSPUZZLESATWITHC___GENERATESAT_H
#define QUEENSPUZZLESATWITHC___GENERATESAT_H

std::vector<std::string> generateNames(int n);
void makeVertical(int n, const std::vector<std::string> &names, std::vector<std::vector<std::string>> &clauses);
void makeHorizontal(int n, const std::vector<std::string> &names, std::vector<std::vector<std::string>> &clauses);
void makeDiagonal(int n, const std::vector<std::string> &names, std::vector<std::vector<std::string>> &clauses);

#endif //QUEENSPUZZLESATWITHC___GENERATESAT_H
