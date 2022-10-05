//
// Created by garre on 10/4/2022.
//

#ifndef INC_236_PROJECT_2_PARSER_H
#define INC_236_PROJECT_2_PARSER_H
#include <vector>
#include "Token.h"

class Parser {

private:
    DatalogProgram program;
    vector<Token> tokens;

public:
    Parser();
    void Match();
};

DatalogProgram Parser::Parse() {

}



#endif //INC_236_PROJECT_2_PARSER_H
