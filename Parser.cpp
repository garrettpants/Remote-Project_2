//
// Created by garre on 10/4/2022.
//

#include "Parser.h"
#include "DatalogProgram.h"

void Match(TokenType type);

DatalogProgram* Parse(vector<Token*> tokens) {
    try {
        DatalogProgram *program = new DatalogProgram;
        Scheme(tokens, program);
        Facts(tokens, program);
        Rules(tokens, program);
        Queries(tokens, program);
        return program;
    } catch (Token* error) {
           // error->failure(error->toString(), error->getDescription(), error)]
           exit(0);
    }
}


void Parser::Scheme(vector<Token*> &tokens, DatalogProgram* &program) {
    if (tokens[0]->type == TokenType::SCHEMES) {
        tokens.erase(tokens.begin());
    } else {
        throw(tokens[0]);
    }
    if (tokens[0]->type == TokenType::COLON) {
        tokens.erase(tokens.begin());
    } else {
        throw(tokens[0]);
    }
    if (tokens[0]->type == TokenType::ID) {
        Predicate(tokens, program, "")

    }


}


/*
try {
Match(TokenType::SCHEMES);
Match(TokenType::COLON);
currentState = TokenType::SCHEMES;
scheme();
schemeList();
Match(TokenType::FACTS);
Match(TokenType::COLON);
currentState = TokenType::FACTS;
factList();
Match(TokenType::RULES);
Match(TokenType::COLON);
currentState = TokenType::RULES;
ruleList();
Match(TokenType::QUERIES);
Match(TokenType::COLON);
currentState = TokenType::QUERIES;
query();
queryList();
Match(TokenType::END_OF_FILE);
}
catch (Token* T) {

}

void Match(TokenType T) { //build match function
    if (T == tokens[index1]->type) {
        if (T == TokenType::STRING && currentState == TokenType::Facts) {
            domainList.insert(tokens[index1]->description);
        }
        index1++;
    }
    else {
        throw (tokens[index1]);
    }
} */


