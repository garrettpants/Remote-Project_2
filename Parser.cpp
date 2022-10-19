//
// Created by garre on 10/4/2022.
//

#include "Parser.h"
#include "DatalogProgram.h"
#include "Parameter.h"
#include "Predicate.h"
#include "P2Rules.h"

Parser::Parser(vector<Token *> tokenVector) {
    this->tokens = tokenVector;
}

void Parser::match(TokenType type) {
    if (tokens[0]->type == type) {
        // TODO tokens.delete
        tokens.erase(tokens.begin());
    } else {
        throw tokens[0];
    }
};


DatalogProgram* Parser::datalogProgram() {
    try {
        match(TokenType::SCHEMES);
        match(TokenType::COLON);
        scheme();
        schemeList();
        match(TokenType::FACTS);
        match(TokenType::COLON);
        factList();
        match(TokenType::RULES);
        match(TokenType::COLON);
        ruleList();
        match(TokenType::QUERIES);
        match(TokenType::COLON);
        query();
        queryList();
        match(TokenType::END_OF_FILE);
    }
    catch (Token *T) {
        cout << "Failure!\n" << tokens[0]->toString(); //TODO double check tostring()
    }
}


void Parser::scheme() {
    match(TokenType::ID);
    Predicate* newPred = new Predicate;
    newPred->addID(tokens[0]->getDescription());
    match(TokenType::LEFT_PAREN);

    if (peek()==TokenType::ID) {
        Parameter* parameter1 = new Parameter(tokens[0]->getDescription());
        newPred->stringPredAdd(parameter1);
    }
    match(TokenType::ID);
    idList(newPred);
    match(TokenType::RIGHT_PAREN);
    schemes.push_back(newPred);
}

void Parser::schemeList() {
    if (peek() == TokenType::FACTS) {
        return;
    } else {
        scheme();
        schemeList();
    }
}

void Parser::fact() {
    match(TokenType::ID);
    Predicate* newPred = new Predicate;
    newPred->addID(tokens[0]->getDescription()); //TODO check if you need to adjust tokens[x]
    match(TokenType::LEFT_PAREN);
    if (peek() == TokenType::STRING) {
        Parameter* parameter1 = new Parameter(tokens[0]->getDescription());
        domain.insert(parameter1->parToString());
        newPred->stringPredAdd(parameter1);
    }
    match(TokenType::STRING);

    stringList(newPred);
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);
    facts.push_back(newPred);
}

void Parser::factlist() {
    if (peek() == TokenType::COLON) {
        return;
    } else {
        fact();
        factlist();
    }
}

void Parser::rule() {
    P2Rules* rules1 = new P2Rules();
    Predicate* newHeadPred = new Predicate;
    headPredicate(newHeadPred);
    rules1->setHeadPredicate(newHeadPred);

    match(TokenType::COLON_DASH);
    Predicate* bodyPred = new Predicate;
    predicate(bodyPred);
    rules1->addBodyPredicate(bodyPred);
}

TokenType Parser::peek() {
    return tokens[1]->getType();
}

void Parser::predicate() {

}





/*
}

void match(TokenType T) { //build match function
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


