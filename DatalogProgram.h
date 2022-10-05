//
// Created by garre on 10/4/2022.
//

#ifndef INC_236_PROJECT_1_DATALOGPROGRAM_H
#define INC_236_PROJECT_1_DATALOGPROGRAM_H

#include <set>
#include "Rules.h"

enum PredicateType{Facts, Queries, Schemes};

class DatalogProgram {
public:
    void SetFacts(vector<Predicate> Fact);
    void SetQueries(vector<Predicate> Query);
    void SetSchemes(vector<Predicate> Scheme);
    void SetRules(vector<Rule> Rule);
    vector<Rule> GetRules();
    vector<Predicate> GetQueries();
    vector<Predicate> GetFacts();
    vector<Predicate> GetSchemes();
    void SetDomain(set<string> Set);
    string ToString();

private:
    vector<Rule> Rules;
    vector<Predicate> Facts;
    vector<Predicate> Queries;
    vector<Predicate> Schemes;
    set<string> Domain;
};

#endif //INC_236_PROJECT_1_DATALOGPROGRAM_H
