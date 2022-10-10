//
// Created by garre on 10/4/2022.
//

#ifndef INC_236_PROJECT_2_PARSER_H
#define INC_236_PROJECT_2_PARSER_H
#include <vector>
#include "Token.h"
#include "DatalogProgram.h"

class Parser {

private:
    DatalogProgram program;
    vector<Token*> tokens;

public:
    Parser(vector<Token*> tokenVector);

    Parse ();
    void scheme();
    void Predicate();
    void Match(TokenType);

    DatalogProgram *datalogProgram();
};




#endif //INC_236_PROJECT_2_PARSER_H
