//
// Created by garre on 10/4/2022.
//

#ifndef INC_236_PROJECT_1_DATALOGPROGRAM_H
#define INC_236_PROJECT_1_DATALOGPROGRAM_H
//test comment
#include <set>
#include "Rules.h"
#include "Token.h"

enum PredicateType{Facts, Queries, Schemes};

class DatalogProgram {
public:

private:
    vector<Rule> Rules;
    vector<Predicate> Facts;
    vector<Predicate> Queries;
    vector<Predicate> Schemes;
    set<string> Domain;

};

#endif //INC_236_PROJECT_1_DATALOGPROGRAM_H
