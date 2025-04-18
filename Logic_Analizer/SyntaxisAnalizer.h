#ifndef SYNTACSISANALIZER
#define SYNTACSISANALIZER

#include "LogicAnalizer.h"
#include <iostream>

class SyntaxisAnalizer :
    protected LogicAnalizer
{
public:
    void startAnalisis(std::string& logic)
    {
        analisis(logic);
        if (!returnErrors().size())
            PROG();
    }

private:

    int cursor = 0;

    void PROG()
    {
        if (transformedLogic.substr(cursor, 7) == "<VARIA>")
        {
            MOVECURSOR();
            ANNOUNC();
            BLOCK();
        }
        else
            ERROR("ERROR IN PROGRAMM BLOCK, 'var' IS NOT FOUND");

        if (cursor != transformedLogic.length())
            ERROR("FOUND EXPRESIONS AFTER PROGRAMM BLOCK");
    }

    void ANNOUNC()
    {
        ID();
        if (transformedLogic.substr(cursor, 7) == "<CLOSE>")
        {
            MOVECURSOR();
            ANNOUNC();
        }
    }

    void BLOCK()
    {
        if (transformedLogic.substr(cursor, 7) == "<B_BEG>")
        {
            MOVECURSOR();
            OP_SQ();
            if (transformedLogic.substr(cursor, 7) != "<B_END>")
                ERROR("END NOT FOUND IN BEGIN-END BLOCK");
            MOVECURSOR();
        }
        else
            ERROR("BEGIN EXPECTED");
    }

    void OP_SQ()
    {
        OP();
        if (transformedLogic.substr(cursor, 7) == "<CLOSE>")
        {
            MOVECURSOR();
            OP_SQ();
        }
    }

    void OP()
    {
        if (transformedLogic.substr(cursor, 7) == "<STA_C>")
        {
            MOVECURSOR();
            OP_ASSIGN();
            if (transformedLogic.substr(cursor, 7) != "<MID_C>")
                ERROR("OPERATOR 'to' EXPECTED");
            MOVECURSOR();
            NUM();
            if (transformedLogic.substr(cursor, 7) != "<END_C>")
                ERROR("OPERATOR 'do' EXPECTED");
            MOVECURSOR();
            BLOCK();
        }
        else
            OP_ASSIGN();
    }

    void OP_ASSIGN()
    {
        
        ID();
        if (transformedLogic.substr(cursor, 7) != "<ASSIG>")
            ERROR("OPERATOR ':=' EXPECTED");
        MOVECURSOR();
        EXPR();
    }

    void FACTOR_EXP()
    {
        if (transformedLogic.substr(cursor, 7) == "<EXCLA>")
        {
            MOVECURSOR();
            FACTOR();
        }
        else
            FACTOR();                                           
    }

    void FACTOR()
    {
        PRIM();
        if (transformedLogic.substr(cursor, 7) == "<AMPER>")
        {
            MOVECURSOR();
            FACTOR();
        }
    }

    void EXPR()
    {
        
        FACTOR_EXP();
        std::string i = transformedLogic.substr(cursor, 7);
        if (transformedLogic.substr(cursor, 7) == "<SHARP>")
        {
            MOVECURSOR();
            EXPR();
        }
    }

    void PRIM()
    {
        NUM();
        ID();
    }

    void NUM()
    {
        if (transformedLogic.substr(cursor, 7) == "<DIGIT>")
        {
            MOVECURSOR();
            NUM();
        }
    }

    void ID()
    {
        if (transformedLogic.substr(cursor, 7) == "<ALPHA>")
        {
            MOVECURSOR();
            ID();
        }
    }

    void ERROR(std::string errorType)
    {
        std::cout << "ERROR TYPE:" << errorType << " :: ANALIZATOR CLOSURE" << std::endl;
        exit(1);
    }

    void MOVECURSOR()
    {
        cursor += 7;
    }
};

#endif 

