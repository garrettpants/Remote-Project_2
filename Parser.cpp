//
// Created by garre on 10/4/2022.
//

#include "Parser.h"
#include "DatalogProgram.h"

Parser::Parser(vector<Token *> tokenVector) {
    this->tokens = tokenVector;
}

void Parser::Match(TokenType type) {
    if (tokens[0]->type == type) {
        // TODO tokens.delete
        tokens.erase(tokens.begin());
    } else {
        throw tokens[0];
    }
};


DatalogProgram* Parser::datalogProgram() {
    try {
        Match(TokenType::SCHEMES);
        Match(TokenType::COLON);
        scheme();
        schemeList();
        Match(TokenType::FACTS);
        Match(TokenType::COLON);
        factList();
        Match(TokenType::RULES);
        Match(TokenType::COLON);
        ruleList();
        Match(TokenType::QUERIES);
        Match(TokenType::COLON);
        query();
        queryList();
        Match(TokenType::END_OF_FILE);
    }
    catch (Token *T) {
//TODO add cout

    }
}


void Parser::scheme() {
    if (tokens[0]->type == TokenType::ID) {
    //TODO
    }
    
}

void Parser::Predicate() {

}





/*
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

/*
DatalogProgram* Parse() {
    try {
        DatalogProgram *program = new DatalogProgram;
        Scheme(tokens, program);
        Facts(tokens, program);
        Rules(tokens, program);
        Queries(tokens, program);
        return program;
    } catch (Token* error) {
           // TODO error->failure(error->toString(), error->getDescription(), error)]
           exit(0);
    }
} */


