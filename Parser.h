//
// Created by garre on 10/4/2022.
//

#ifndef INC_236_PROJECT_2_PARSER_H
#define INC_236_PROJECT_2_PARSER_H
#include <vector>
#include "Token.h"
#include "DatalogProgram.h"
#include "Parameter.h"
#include "Predicate.h"
#include "P2Rules.h"

class Parser {

private:
    DatalogProgram program;
    vector<Token*> tokens;


public:
    vector<Predicate*> facts;

    Parser(vector<Token*> tokenVector);
    void match(TokenType);
    void scheme();
    void schemeList();
    void fact();
    void factlist();
    void rule();
    void predicate(Predicate* predPtr);
    void stringList(Predicate* predPtr);
    void headPredicate(Predicate* predPtr);
    TokenType peek();

    set<string> domain;


    DatalogProgram* datalogProgram();


};




#endif //INC_236_PROJECT_2_PARSER_H
