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
    vector<Token> tokens;

public:
    Parser(Token);

    Parse (vector<Token*> tokens);
    void Scheme(vector<Token*> &tokens, DatalogProgram* &program);
    void Predicate(vector<Token*> &tokens, DatalogProgram* &program, )
    //void Match(TokenType);
};




#endif //INC_236_PROJECT_2_PARSER_H
