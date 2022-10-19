cmake_minimum_required(VERSION 3.16)
project(236_Project_1)

set(CMAKE_CXXSTANDARD 17)

add_executable(236_Project_1 main.cpp
        Add.h
        Automaton.h
        Colon.h
        ColonDash.h
        Comma.h
        Comment.h
        Facts.h
        ID.h
        Left_Paren.h
        Lexer.cpp
        Lexer.h
        Multiply.h
        Period.h
        Q_Mark.h
        Queries.h
        Right_Paren.h
        Rules.h
        Schemes.h
        String.h
        Token.h
        Parser.h DatalogProgram.h Parser.cpp Predicate.h Parameter.h P2Rules.h)