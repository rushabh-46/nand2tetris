#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXCHARPERLINE 500
#define MAXINLINE 300
typedef struct SymbolTableElement STE;

FILE *initializeO1(char *fileName)
{
    int i = 0;
    while (fileName[i] != '.')
        i++;
    fileName[i + 1] = 't';
    fileName[i + 2] = 'o';
    fileName[i + 3] = 'k';
    fileName[i + 4] = '\0';

    return fopen(fileName, "w");
}

FILE *initializeE(char *fileName)
{
    int i = 0;
    while (fileName[i] != '.')
        i++;
    fileName[i + 1] = 'e';
    fileName[i + 2] = 'r';
    fileName[i + 3] = 'r';
    fileName[i + 4] = '\0';
    return fopen(fileName, "w");
}

FILE *initializeinput2(char *fileName)
{
    int i = 0;
    while (fileName[i] != '.')
        i++;
    fileName[i + 1] = 't';
    fileName[i + 2] = 'o';
    fileName[i + 3] = 'k';
    fileName[i + 4] = '\0';

    return fopen(fileName, "r");
}

FILE *initializeO2(char *fileName)
{
    int i = 0;
    while (fileName[i] != '.')
        i++;
    fileName[i + 1] = 'x';
    fileName[i + 2] = 'm';
    fileName[i + 3] = 'l';
    fileName[i + 4] = '\0';
    return fopen(fileName, "w");
}

int checkforKeyword(char *symbol)
{
    if ((strcmp(symbol, "class") == 0) || (strcmp(symbol, "constructor") == 0) || (strcmp(symbol, "method") == 0) || (strcmp(symbol, "function") == 0) || (strcmp(symbol, "int") == 0) || (strcmp(symbol, "boolean") == 0) || (strcmp(symbol, "char") == 0) || (strcmp(symbol, "void") == 0) || (strcmp(symbol, "var") == 0) || (strcmp(symbol, "static") == 0) || (strcmp(symbol, "field") == 0) || (strcmp(symbol, "true") == 0) || (strcmp(symbol, "false") == 0) || (strcmp(symbol, "null") == 0) || (strcmp(symbol, "this") == 0) || (strcmp(symbol, "return") == 0) || (strcmp(symbol, "while") == 0) || (strcmp(symbol, "else") == 0) || (strcmp(symbol, "if") == 0) || (strcmp(symbol, "do") == 0) || (strcmp(symbol, "let") == 0))
    {
        return 1;
    }
    return 0;
}

int checkforSymbol(char c)
{
    if (c == ')' || c == '(' || c == ']' || c == '[' || c == '}' || c == '{' || c == ',' || c == '.' || c == ';' || c == '=' || c == '+' || c == '-' ||
        c == '*' || c == '/' || c == '&' || c == '|' || c == '~' || c == '<' || c == '>' || c == '{' || c == '}')
        return 1;
    else
        return 0;
}

FILE *inputFile2;
FILE *outputFile2;
FILE *errorFile;
bool ERRROR = false;

int spaces = 0;
char command[MAXCHARPERLINE];
char lex[20];
char name[20];

///
/////////////////
///

FILE *inputFile;
FILE *outputFile;

FILE *initializefinalInput(char *fileName)
{
    int i = 0;
    while (fileName[i] != '.')
        i++;
    fileName[i + 1] = 'x';
    fileName[i + 2] = 'm';
    fileName[i + 3] = 'l';
    fileName[i + 4] = '\0';

    return fopen(fileName, "r");
}

FILE *initializefinalOutput(char *fileName)
{
    int i = 0;
    while (fileName[i] != '.')
        i++;
    fileName[i + 1] = 'v';
    fileName[i + 2] = 'm';
    fileName[i + 3] = '\0';

    return fopen(fileName, "w");
}

char comm[MAXINLINE];
char inside[50];
char outside[MAXCHARPERLINE];

struct SymbolTableElement
{
    char name[MAXCHARPERLINE];
    char kind[MAXCHARPERLINE];
    char type[MAXCHARPERLINE];
    int index;
};

STE ClassSTE[100];
STE SubSTE[2000];
int SS = 0; // keep the track of SubSTE
int CC = 0;
int labelNum = 0;
int field_count = 0;
int static_count = 0;
int Total_count = 0;
char ClassName[MAXCHARPERLINE];
char SubRoutineName[MAXCHARPERLINE];
char SubRoutineType[MAXCHARPERLINE];
int local_count = 0;
int arg_count = 0;
int total_count = 0;

void CompClass();
void CompClassVarDec();
void CompSubroutineDec();
void CompParameterList();
void CompSubroutineBody();
void CompVarDec();
void CompStatements();
void CompWhileStatement();
void CompIfStatement();
void CompDoStatement();
void CompLetStatement();
void CompReturnStatement();
int CompExpressionList();
void CompExpression();
void CompTerm();

///
/////////////
///

void getCommands();
void compileClass();
void compileClassVarDec();
void compileSubroutineDec();
void compileParameterList();
void compileSubroutineBody();
void compileVarDec();
void compileStatements();
void compileWhileStatement();
void compileIfStatement();
void compileDoStatement();
void compileLetStatement();
void compileReturnStatement();
void compileExpressionList();
void compileExpression();
void compileTerm();
void compileSubroutineCall();

void print(char *sssss)
{
    for (int i = 0; i < spaces; i++)
        fprintf(outputFile2, " ");
    fprintf(outputFile2, "%s", sssss);
}

int checkop(char *name)
{
    if (strcmp(name, "+") == 0)
        return 1;
    else if (strcmp(name, "-") == 0)
        return 1;
    else if (strcmp(name, "*") == 0)
        return 1;
    else if (strcmp(name, "/") == 0)
        return 1;
    else if (strcmp(name, "=") == 0)
        return 1;
    else if (strcmp(name, "&amp;") == 0)
        return 1;
    else if (strcmp(name, "|") == 0)
        return 1;
    else if (strcmp(name, "&lt;") == 0)
        return 1;
    else if (strcmp(name, "&gt;") == 0)
        return 1;
    return 0;
}
void getCommands()
{
    fgets(command, MAXCHARPERLINE, inputFile2);
    int i = 1;
    lex[0] = '\0';
    name[0] = '\0';
    char lex1[MAXCHARPERLINE];
    char name1[MAXCHARPERLINE];
    int j = 0;
    while (command[i] != '>')
    {
        lex1[j] = command[i];
        j++;
        i++;
    }
    lex1[j] = '\0';
    j = 0;
    i = i + 2;
    while (command[i] != ' ')
    {
        name1[j] = command[i];
        j++;
        i++;
    }
    name1[j] = '\0';
    strcpy(lex, lex1);
    strcpy(name, name1);
    //printf("Lex : %s.. Name : %s..\n",lex,name);
}

int checkTERM()
{
    if (strcmp(lex, "symbol") == 0)
    {
        if (!((strcmp(name, "~") == 0) || (strcmp(name, "-") == 0) || (strcmp(name, "(") == 0)))
        {
            return 0;
        }
    }
    else if (strcmp(lex, "keyword") == 0)
    {
        if (!((strcmp(name, "true") == 0) || (strcmp(name, "false") == 0) || (strcmp(name, "this") == 0) || (strcmp(name, "null") == 0)))
        {
            return 0;
        }
    }
    return 1;
}

void compileTerm()
{
    ///YES YES
    ///check_expression will remain 0 if there is a term.
    if (strcmp(lex, "integerConstant") == 0)
    {
        print(command);
        getCommands();
    }
    else if (strcmp(lex, "stringConstant") == 0)
    {
        print(command);
        getCommands();
    }
    else if (strcmp(lex, "keyword") == 0)
    { ///keywordConstant
        if (!((strcmp(name, "true") == 0) || (strcmp(name, "false") == 0) || (strcmp(name, "this") == 0) || (strcmp(name, "null") == 0)))
        {
            fprintf(errorFile, "ERROR: %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
        getCommands();
    }
    else if (strcmp(lex, "symbol") == 0)
    {
        if ((strcmp(name, "~") == 0) || (strcmp(name, "-") == 0))
        {
            print(command);
            getCommands();
            if (checkTERM() == 0)
            {
                fprintf(errorFile, "ERROR: %s\n", name);
                ERRROR = true;
                return;
            }
            print("<term>\n");
            spaces += 2;
            compileTerm();
            if (ERRROR)
                return;
            spaces -= 2;
            print("</term>\n");
        }
        else if (strcmp(name, "(") == 0)
        {
            print(command);
            getCommands();
            print("<expression>\n");
            spaces += 2;
            compileExpression();
            if (ERRROR)
                return;
            spaces -= 2;
            print("</expression>\n");
            if (strcmp(name, ")") != 0)
            {
                if (strcmp(lex, "symbol") == 0)
                    fprintf(errorFile, "ERROR: %s\n", name);
                else
                    fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
                ERRROR = true;
                return;
            }
            print(command);
            getCommands();
        }
        else
        {
            //printf("ERROR : Expected a correct symbol in beginning of term.\n");
            fprintf(errorFile, "ERROR: %s\n", name);
            ERRROR = true;
            return;
        }
    }
    else
    {
        ///identifier
        print(command);
        getCommands();
        if (strcmp(name, "[") == 0)
        { ///varName [expression]
            print(command);
            getCommands();
            if (checkTERM() == 0)
            {
                fprintf(errorFile, "ERROR: %s\n", name);
                ERRROR = true;
                return;
            }
            print("<expression>\n");
            spaces += 2;
            compileExpression();
            if (ERRROR)
                return;
            spaces -= 2;
            print("</expression>\n");
            if (strcmp(name, "]") != 0)
            {
                if (strcmp(lex, "symbol") == 0)
                    fprintf(errorFile, "ERROR: %s\n", name);
                else
                    fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
                ERRROR = true;
                return;
            }
            print(command);
            getCommands();
        }
        else if (strcmp(name, "(") == 0)
        {
            print(command);
            print("<expressionList>\n");
            spaces += 2;
            compileExpressionList();
            if (ERRROR)
                return;
            spaces -= 2;
            print("</expressionList>\n");
            if (strcmp(name, ")") != 0)
            {
                if (strcmp(lex, "symbol") == 0)
                    fprintf(errorFile, "ERROR: %s\n", name);
                else
                    fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
                ERRROR = true;
                return;
            }
            print(command);
            getCommands();
        }
        else if (strcmp(name, ".") == 0)
        {
            print(command);
            getCommands();
            if (strcmp(lex, "identifier") != 0)
            {
                fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
                ERRROR = true;
                return;
            }
            print(command);
            getCommands();
            if (strcmp(name, "(") != 0)
            {
                if (strcmp(lex, "symbol") == 0)
                    fprintf(errorFile, "ERROR: %s\n", name);
                else
                    fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
                ERRROR = true;
                return;
            }
            print(command);
            print("<expressionList>\n");
            spaces += 2;
            compileExpressionList();
            if (ERRROR)
                return;
            spaces -= 2;
            print("</expressionList>\n");
            if (strcmp(name, ")") != 0)
            {
                if (strcmp(lex, "symbol") == 0)
                    fprintf(errorFile, "ERROR: %s\n", name);
                else
                    fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
                ERRROR = true;
                return;
            }
            print(command);
            getCommands();
        }
    }
}

void compileExpression()
{
    ///YES YES
    print("<term>\n");
    spaces += 2;
    compileTerm();
    if (ERRROR)
        return;
    spaces -= 2;
    print("</term>\n");
    //getCommands();
    while (checkop(name) == 1)
    {
        print(command);
        getCommands();
        print("<term>\n");
        spaces += 2;
        compileTerm();
        if (ERRROR)
            return;
        spaces -= 2;
        print("</term>\n");
        //getCommands();
    }
}

void compileExpressionList()
{
    ///NO YES
    getCommands();
    if (checkTERM() == 1)
    {
        print("<expression>\n");
        spaces += 2;
        compileExpression(); ///we already have the term.
        if (ERRROR)
            return;
        spaces -= 2;
        print("</expression>\n");
        ///Now also we have called next token.
        while (strcmp(name, ",") == 0)
        {
            print(command);
            getCommands();
            print("<expression>\n");
            spaces += 2;
            compileExpression(); ///we already have the term.
            if (ERRROR)
                return;
            spaces -= 2;
            print("</expression>\n");
        }
    }
}

void compileSubroutineCall()
{
    getCommands();
    if (strcmp(lex, "identifier") != 0)
    {
        fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    if (strcmp(name, "(") == 0)
    {
        print(command);
        print("<expressionList>\n");
        spaces += 2;
        compileExpressionList();
        if (ERRROR)
            return;
        spaces -= 2;
        print("</expressionList>\n");
        ////getCommands();
        if (strcmp(name, ")") != 0)
        {
            if (strcmp(lex, "symbol") == 0)
                fprintf(errorFile, "ERROR: %s\n", name);
            else
                fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
    }
    else if (strcmp(name, ".") == 0)
    {
        print(command);
        getCommands();
        if (strcmp(lex, "identifier") != 0)
        {
            fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
        getCommands();
        if (strcmp(name, "(") != 0)
        {
            if (strcmp(lex, "symbol") == 0)
                fprintf(errorFile, "ERROR : %s\n", name);
            else
                fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
        print("<expressionList>\n");
        spaces += 2;
        compileExpressionList();
        if (ERRROR)
            return;
        spaces -= 2;
        print("</expressionList>\n");
        ////getCommands();
        if (strcmp(name, ")") != 0)
        {
            if (strcmp(lex, "symbol") == 0)
                fprintf(errorFile, "ERROR: %s\n", name);
            else
                fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
    }
    else
    {
        fprintf(errorFile, "ERROR: %s\n", name);
        ERRROR = true;
        return;
    }
}

void compileLetStatement()
{
    print(command);
    getCommands();
    if (strcmp(lex, "identifier") != 0)
    {
        fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    if (strcmp(name, "[") == 0)
    { ///array variable .  i.e. varName[expression]
        print(command);
        getCommands();
        print("<expression>\n");
        spaces += 2;
        compileExpression();
        if (ERRROR)
            return;
        spaces -= 2;
        print("</expression>\n");
        if (strcmp(name, "]") != 0)
        {
            if (strcmp(lex, "symbol") == 0)
                fprintf(errorFile, "ERROR : %s\n", name);
            else
                fprintf(errorFile, "ERROR : Expecting <symbol> but %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
        getCommands();
    }
    if (strcmp(name, "=") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR : %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    print("<expression>\n");
    spaces += 2;
    compileExpression();
    if (ERRROR)
        return;
    spaces -= 2;
    print("</expression>\n");
    if (strcmp(name, ";") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR : %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
}

void compileDoStatement()
{
    print(command);
    //getCommands();
    compileSubroutineCall();
    if (ERRROR)
        return;
    getCommands();
    if (strcmp(name, ";") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
}

void compileWhileStatement()
{
    print(command);
    getCommands();
    if (strcmp(name, "(") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    //getCommands();
    print("<expression>\n");
    spaces += 2;
    compileExpression();
    if (ERRROR)
        return;
    spaces -= 2;
    print("</expression>\n");
    //getCommands();
    if (strcmp(name, ")") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    if (strcmp(name, "{") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    print("<statements>\n");
    spaces += 2;
    compileStatements();
    if (ERRROR)
        return;
    spaces -= 2;
    print("</statements>\n");
    if (strcmp(name, "}") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
}

void compileIfStatement()
{
    print(command);
    getCommands();
    if (strcmp(name, "(") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    print("<expression>\n");
    spaces += 2;
    compileExpression();
    if (ERRROR)
        return;
    spaces -= 2;
    print("</expression>\n");
    //getCommands();
    if (strcmp(name, ")") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    if (strcmp(name, "{") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    print("<statements>\n");
    spaces += 2;
    compileStatements();
    if (ERRROR)
        return;
    spaces -= 2;
    print("</statements>\n");
    if (strcmp(name, "}") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    while (strcmp(name, "else") == 0)
    {
        print(command);
        getCommands();
        if (strcmp(name, "{") != 0)
        {
            if (strcmp(lex, "symbol") == 0)
                fprintf(errorFile, "ERROR: %s\n", name);
            else
                fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
        getCommands();
        print("<statements>\n");
        spaces += 2;
        compileStatements();
        if (ERRROR)
            return;
        spaces -= 2;
        print("</statements>\n");
        if (strcmp(name, "}") != 0)
        {
            if (strcmp(lex, "symbol") == 0)
                fprintf(errorFile, "ERROR: %s\n", name);
            else
                fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
        getCommands();
    }
}

void compileReturnStatement()
{
    print(command);
    getCommands();
    if (strcmp(name, ";") != 0)
    {
        print("<expression>\n");
        spaces += 2;
        compileExpression();
        if (ERRROR)
            return;
        spaces -= 2;
        print("</expression>\n");
    }
    if (strcmp(name, ";") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
}

void compileStatements()
{
    while ((strcmp(name, "let") == 0) || (strcmp(name, "while") == 0) || (strcmp(name, "do") == 0) || (strcmp(name, "return") == 0) || (strcmp(name, "if") == 0))
    {
        if (strcmp(name, "let") == 0)
        {
            print("<letStatement>\n");
            spaces += 2;
            compileLetStatement();
            spaces -= 2;
            print("</letStatement>\n");
        }
        else if (strcmp(name, "while") == 0)
        {
            print("<whileStatement>\n");
            spaces += 2;
            compileWhileStatement();
            spaces -= 2;
            print("</whileStatement>\n");
        }
        else if (strcmp(name, "if") == 0)
        {
            print("<ifStatement>\n");
            spaces += 2;
            compileIfStatement();
            spaces -= 2;
            print("</ifStatement>\n");
        }
        else if (strcmp(name, "do") == 0)
        {
            print("<doStatement>\n");
            spaces += 2;
            compileDoStatement();
            spaces -= 2;
            print("</doStatement>\n");
        }
        else
        {
            print("<returnStatement>\n");
            spaces += 2;
            compileReturnStatement();
            spaces -= 2;
            print("</returnStatement>\n");
        }
        if (ERRROR)
            return;
        //getCommands();
    }
}

void compileVarDec()
{
    print(command);
    getCommands();
    if (strcmp(lex, "keyword") == 0)
    {
        if (!((strcmp(name, "int") == 0) || (strcmp(name, "boolean") == 0) || (strcmp(name, "char") == 0)))
        {
            fprintf(errorFile, "ERROR: %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
    }
    else if (strcmp(lex, "identifier") == 0)
    {
        print(command);
    }
    else
    {
        fprintf(errorFile, "ERROR: Expecting <type> but %s\n", name);
        ERRROR = true;
        return;
    }
    getCommands();
    if (strcmp(lex, "identifier") != 0)
    {
        fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    while (strcmp(name, ",") == 0)
    {
        print(command);
        getCommands();
        if (strcmp(lex, "identifier") != 0)
        {
            fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
        getCommands();
    }
    if (strcmp(name, ";") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
}

void compileSubroutineBody()
{
    ///call first token here. Don't call the token after the routine.
    getCommands();
    if (strcmp(name, "{") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    while (strcmp(name, "var") == 0)
    {
        print("<varDec>\n");
        spaces += 2;
        compileVarDec();
        if (ERRROR)
            return;
        spaces -= 2;
        print("</varDec>\n");
    }
    ///statements*
    print("<statements>\n");
    spaces += 2;
    compileStatements();
    if (ERRROR)
        return;
    spaces -= 2;
    print("</statements>\n");
    if (strcmp(name, "}") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
}

void compileParameterList()
{
    ///called when () is not empty
    //Type
    if (strcmp(name, ")") == 0)
        return;
    if (strcmp(lex, "keyword") == 0)
    {
        if (!((strcmp(name, "int") == 0) || (strcmp(name, "boolean") == 0) || (strcmp(name, "char") == 0)))
        {
            fprintf(errorFile, "ERROR: %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
    }
    else if (strcmp(lex, "identifier") == 0)
    {
        //type of varName is 'className' type
        print(command);
    }
    else
    {
        fprintf(errorFile, "ERROR: Expecting <type> but %s\n", name);
        ERRROR = true;
        return;
    }
    //varName
    getCommands();
    if (strcmp(lex, "identifier") != 0)
    {
        fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    while (strcmp(name, ",") == 0)
    {
        print(command);
        getCommands();
        //Type
        if (strcmp(lex, "keyword") == 0)
        {
            if (!((strcmp(name, "int") == 0) || (strcmp(name, "boolean") == 0) || (strcmp(name, "char") == 0)))
            {
                fprintf(errorFile, "ERROR: %s\n", name);
                ERRROR = true;
                return;
            }
            print(command);
        }
        else if (strcmp(lex, "identifier") == 0)
        {
            //type of varName is 'className' type
            print(command);
        }
        else
        {
            fprintf(errorFile, "ERROR: Expecting <type> but %s\n", name);
            ERRROR = true;
            return;
        }
        //varName
        getCommands();
        if (strcmp(lex, "identifier") != 0)
        {
            fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
        getCommands();
    }
}

void compileSubroutineDec()
{
    print(command);
    getCommands();
    if (strcmp(lex, "keyword") == 0)
    {
        if (!((strcmp(name, "void") == 0) || (strcmp(name, "int") == 0) || (strcmp(name, "boolean") == 0) || (strcmp(name, "char") == 0)))
        {
            fprintf(errorFile, "ERROR: %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
    }
    else if (strcmp(lex, "identifier") == 0)
    {
        //'className' type
        print(command);
    }
    else
    {
        printf("ERROR: Type of subroutineDec is incorrect.\n");
        ERRROR = true;
        return;
    }
    getCommands();
    //subroutineName
    if (strcmp(lex, "identifier") != 0)
    {
        fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    // '{' parameterList '}'
    if (strcmp(name, "(") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    print("<parameterList>\n");
    spaces += 2;
    compileParameterList();
    if (ERRROR)
        return;
    spaces -= 2;
    print("</parameterList>\n");
    if (strcmp(name, ")") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    print("<subroutineBody>\n");
    spaces += 2;
    compileSubroutineBody();
    if (ERRROR)
        return;
    spaces -= 2;
    print("</subroutineBody>\n");
}

void compileClassVarDec()
{
    print(command);
    getCommands();
    //Type
    if (strcmp(lex, "keyword") == 0)
    {
        if (!((strcmp(name, "int") == 0) || (strcmp(name, "boolean") == 0) || (strcmp(name, "char") == 0)))
        {
            fprintf(errorFile, "ERROR: %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
    }
    else if (strcmp(lex, "identifier") == 0)
    {
        //type of varName is 'className' type
        print(command);
    }
    else
    {
        fprintf(errorFile, "ERROR: Expecting <type> but %s\n", name);
        ERRROR = true;
        return;
    }
    //varName
    getCommands();
    if (strcmp(lex, "identifier") != 0)
    {
        fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    while (strcmp(name, ",") == 0)
    {
        // Multiple classVarDec's i.e. (',' varName)*
        print(command);
        getCommands();
        if (strcmp(lex, "identifier") != 0)
        {
            fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
            ERRROR = true;
            return;
        }
        print(command);
        getCommands();
    }
    if (strcmp(name, ";") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
}

void compileClass()
{
    getCommands();
    if (strcmp(name, "class") != 0)
    {
        if (strcmp(lex, "keyword") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <keyword> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    ///className
    if (strcmp(lex, "identifier") != 0)
    {
        fprintf(errorFile, "ERROR: Expecting <identifier> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    if (strcmp(name, "{") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
    getCommands();
    /// Inside { }  of class.

    while ((strcmp(name, "static") == 0) || (strcmp(name, "field") == 0))
    {
        ///classVarDec
        print("<classVarDec>\n");
        spaces += 2;
        compileClassVarDec();
        if (ERRROR)
            return;
        spaces -= 2;
        print("</classVarDec>\n");
        getCommands();
    }
    while ((strcmp(name, "constructor") == 0) || (strcmp(name, "method") == 0) || (strcmp(name, "function") == 0))
    {
        ///subroutineDec
        print("<subroutineDec>\n");
        spaces += 2;
        compileSubroutineDec();
        if (ERRROR)
            return;
        spaces -= 2;
        print("</subroutineDec>\n");
        //getCommands();
    }
    if (strcmp(name, "}") != 0)
    {
        if (strcmp(lex, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", name);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", name);
        ERRROR = true;
        return;
    }
    print(command);
}

///
/////////////
///

void getComms()
{
    char comm1[MAXINLINE];
    fgets(comm1, MAXINLINE, inputFile);
    int i = 0;
    while (comm1[i] == ' ')
        i++;
    char comm2[MAXINLINE];
    int j = 0;
    while (comm1[i] != '\n')
    {
        comm2[j] = comm1[i];
        j++;
        i++;
    }
    comm2[j] = '\0';
    strcpy(comm, comm2);
    ///comm doesn't contain '\n'
    i = 1;
    char lex1[MAXCHARPERLINE];
    char name1[MAXCHARPERLINE];
    j = 0;
    while (comm[i] != '>')
    {
        lex1[j] = comm[i];
        j++;
        i++;
    }
    lex1[j] = '\0';
    j = 0;
    i++;
    name1[j] = '\0';
    if (comm[i] != '\0')
    {
        i++;
        while (comm[i] != ' ')
        {
            name1[j] = comm[i];
            j++;
            i++;
        }
        name1[j] = '\0';
    }
    strcpy(inside, lex1);
    strcpy(outside, name1);
    //printf("Inside : %s.. Outside : %s..\n",inside,outside);
}

int checkOPP(char *s)
{
    if (strcmp(s, "+") == 0)
        return 1;
    else if (strcmp(s, "-") == 0)
        return 1;
    else if (strcmp(s, "*") == 0)
        return 1;
    else if (strcmp(s, "/") == 0)
        return 1;
    else if (strcmp(s, "|") == 0)
        return 1;
    else if (strcmp(s, "=") == 0)
        return 1;
    else if (strcmp(s, "&amp;") == 0)
        return 1;
    else if (strcmp(s, "&gt;") == 0)
        return 1;
    else if (strcmp(s, "&lt;") == 0)
        return 1;
    else
        return 0;
}

void convertOPP(char *d, char *s)
{
    if (strcmp(s, "+") == 0)
        strcpy(d, "add");
    else if (strcmp(s, "-") == 0)
        strcpy(d, "sub");
    else if (strcmp(s, "*") == 0)
        strcpy(d, "call Math.multiply 2");
    else if (strcmp(s, "/") == 0)
        strcpy(d, "call Math.divide 2");
    else if (strcmp(s, "|") == 0)
        strcpy(d, "or");
    else if (strcmp(s, "=") == 0)
        strcpy(d, "eq");
    else if (strcmp(s, "&amp;") == 0)
        strcpy(d, "and");
    else if (strcmp(s, "&gt;") == 0)
        strcpy(d, "gt");
    else if (strcmp(s, "&lt;") == 0)
        strcpy(d, "lt");
    else
        return;
}

int checkSTE(char *naam)
{
    for (int i = SS + total_count - 1; i >= SS; i--)
    {
        if (strcmp(naam, SubSTE[i].name) == 0)
            return 1;
    }
    for (int i = CC + Total_count - 1; i >= CC; i--)
    {
        if (strcmp(naam, ClassSTE[i].name) == 0)
            return 1;
    }
    return 0;
}

STE getSTE(char *naam)
{
    STE temp;
    strcpy(temp.name, naam);
    for (int i = SS + total_count - 1; i >= SS; i--)
    {
        if (strcmp(naam, SubSTE[i].name) == 0)
        {
            temp = SubSTE[i];
            return temp;
        }
    }
    for (int i = CC + Total_count - 1; i >= CC; i--)
    {
        if (strcmp(naam, ClassSTE[i].name) == 0)
        {
            temp = ClassSTE[i];
            return temp;
        }
    }
    fprintf(errorFile, "Declaration error: %s undeclared\n", naam);
    ERRROR = true;
}

void CompTerm()
{
    if (ERRROR)
        return;
    //printf("I am in term\n");
    char unOp = 'X';
    getComms();
    if ((strcmp(outside, "-") == 0) || (strcmp(outside, "~") == 0))
    {
        unOp = outside[0];
        getComms(); //<term>
        CompTerm(); //</term>
        if (unOp == '-')
            fprintf(outputFile, "neg\n");
        else
            fprintf(outputFile, "not\n");
        getComms();
    }
    else if (strcmp(outside, "(") == 0)
    {
        getComms(); //<expression>
        CompExpression();
        // </expression>
        getComms(); // ")"
        getComms();
    }
    else if (strcmp(inside, "integerConstant") == 0)
    {
        fprintf(outputFile, "push constant %s\n", outside);
        getComms();
    }
    else if (strcmp(inside, "keyword") == 0)
    {
        if (strcmp(outside, "true") == 0)
        {
            fprintf(outputFile, "push constant 0\n");
            fprintf(outputFile, "not\n");
        }
        else if ((strcmp(outside, "false") == 0) || (strcmp(outside, "null") == 0))
            fprintf(outputFile, "push constant 0\n");
        else if (strcmp(outside, "this") == 0)
            fprintf(outputFile, "push pointer 0\n");
        else
        {
            fprintf(errorFile, "ERROR: %s\n", outside);
            ERRROR = true;
            return;
        }
        getComms();
    }
    else if (strcmp(inside, "stringConstant") == 0)
    {
        int commsii = strlen(comm) - 35;
        char tst[MAXCHARPERLINE];
        int pp = 0;
        //int qq=0;
        //while(comm[qq]!='>') qq++;
        //qq+=2;
        while (pp < commsii)
        {
            tst[pp] = comm[pp + 17];
            pp++;
        }
        tst[pp] = '\0';
        //printf("STRING constant : %d %s..",commsii,tst);
        //int sii=strlen(outside);
        //printf("STRING constant : %d %s..\n",sii,outside);
        fprintf(outputFile, "push constant %d\n", commsii);
        fprintf(outputFile, "call String.new 1\n");
        for (int j = 0; j < commsii; j++)
        {
            fprintf(outputFile, "push constant %d\n", tst[j]);
            fprintf(outputFile, "call String.appendChar 2\n");
        }
        getComms();
    }
    else if (strcmp(inside, "identifier") == 0)
    {
        char id1[MAXCHARPERLINE]; //varName
        strcpy(id1, outside);
        getComms();
        if (strcmp(inside, "/term") == 0)
        { ///varName
            STE varN = getSTE(id1);
            if (ERRROR)
                return;
            fprintf(outputFile, "push %s %d\n", varN.kind, varN.index);
        }
        else if (strcmp(outside, "[") == 0)
        {               ///varName[expression]
            getComms(); //<expression>
            CompExpression();
            // </expression>
            getComms(); // "]"
            STE varN = getSTE(id1);
            if (ERRROR)
                return;
            fprintf(outputFile, "push %s %d\n", varN.kind, varN.index);
            fprintf(outputFile, "add\n");
            fprintf(outputFile, "pop pointer 1\n");
            fprintf(outputFile, "push that 0\n");
            getComms();
        }
        else if ((strcmp(outside, "(") == 0) || (strcmp(outside, ".") == 0))
        {
            if (strcmp(outside, ".") == 0)
            {
                getComms();
                char id2[MAXCHARPERLINE];
                strcpy(id2, outside);
                getComms(); //  "(")
                int ttt = 0;
                STE varName;
                if (checkSTE(id1) == 1)
                {
                    ttt = 1;
                    varName = getSTE(id1);
                    if (ERRROR)
                        return;
                    fprintf(outputFile, "push %s %d\n", varName.kind, varName.index);
                }
                getComms(); // <expressionList>
                int np = CompExpressionList();
                if (ERRROR)
                    return;
                // </expressionList>
                getComms();
                //")"

                if (ttt == 1)
                { ///id1 is in symboltables
                    fprintf(outputFile, "call %s.%s %d\n", varName.type, id2, np + 1);
                }
                else
                {
                    fprintf(outputFile, "call %s.%s %d\n", id1, id2, np);
                }
            }
            else
            { //if(outside[0]=='(') {
                fprintf(outputFile, "push pointer 0\n");
                getComms();
                int nP = CompExpressionList();
                if (ERRROR)
                    return;
                getComms(); //   ")"
                fprintf(outputFile, "call %s.%s %d\n", ClassName, id1, nP + 1);
            }
            getComms();
        }
    }
    else
    {
        fprintf(errorFile, "ERROR: %s\n", outside);
        ERRROR = true;
        return;
    }
}

void CompExpression()
{
    if (ERRROR)
        return;
    //printf("I am in Expression\n");
    getComms(); //must be <term>
    CompTerm();
    ///  </term>
    getComms();
    while (checkOPP(outside) == 1)
    {
        char oppp[7];
        strcpy(oppp, outside);
        getComms(); //<term>
        CompTerm(); //</term>
        if (ERRROR)
            return;
        char oppppp[15];
        convertOPP(oppppp, oppp);
        fprintf(outputFile, "%s\n", oppppp);
        getComms();
    }
}

int CompExpressionList()
{
    if (ERRROR)
        return -1;
    //printf("I am in Expression List\n");
    int np = 0;
    getComms();
    while (strcmp(inside, "expression") == 0)
    {
        np++;
        CompExpression();
        if (ERRROR)
            return -1;
        ///  </expression>
        getComms(); //  ","
        if (strcmp(outside, ",") == 0)
        {
            getComms();
            continue;
        }
        break;
    }
    return np;
}

void CompDoStatement()
{
    if (ERRROR)
        return;
    //printf("I am in Do Statement\n");
    getComms(); //"do"
    getComms(); //identifier
    char id1[MAXCHARPERLINE];
    strcpy(id1, outside);
    getComms();
    if (outside[0] == '.')
    {
        getComms();
        char id2[MAXCHARPERLINE];
        strcpy(id2, outside);
        getComms(); //  "(")
        int ttt = 0;
        STE varName;
        if (checkSTE(id1) == 1)
        {
            ttt = 1;
            varName = getSTE(id1);
            if (ERRROR)
                return;
            fprintf(outputFile, "push %s %d\n", varName.kind, varName.index);
        }
        getComms(); // <expressionList>
        int np = CompExpressionList();
        // </expressionList>
        getComms(); //")"

        if (ttt == 1)
        { ///id1 is in symboltables
            fprintf(outputFile, "call %s.%s %d\n", varName.type, id2, np + 1);
            fprintf(outputFile, "pop temp 0\n");
        }
        else
        {
            fprintf(outputFile, "call %s.%s %d\n", id1, id2, np);
            fprintf(outputFile, "pop temp 0\n");
        }
    }
    else if (outside[0] == '(')
    {
        fprintf(outputFile, "push pointer 0\n");
        //  "("
        getComms();
        int nP = CompExpressionList();
        // </expressionList>
        getComms();
        //")"
        fprintf(outputFile, "call %s.%s %d\n", ClassName, id1, nP + 1);
        fprintf(outputFile, "pop temp 0\n");
    }
    else
    {
        if (strcmp(inside, "symbol") == 0)
            fprintf(errorFile, "ERROR: %s\n", outside);
        else
            fprintf(errorFile, "ERROR: Expecting <symbol> but %s\n", outside);
        ERRROR = true;
        return;
    }
    if (ERRROR)
        return;
    getComms(); // ";"
}

void CompLetStatement()
{
    if (ERRROR)
        return;
    //printf("I am in Let Statement\n");
    getComms(); ///  "let"
    getComms();
    char naam[MAXCHARPERLINE];
    strcpy(naam, outside);
    STE varName = getSTE(naam);
    if (ERRROR)
        return;
    getComms();
    int bruh = 0;
    if (strcmp(outside, "[") == 0)
    {
        bruh = 1;
        getComms(); /// <expression>
        CompExpression();
        getComms(); //  "]"
        fprintf(outputFile, "push %s %d\n", varName.kind, varName.index);
        fprintf(outputFile, "add\n");
        getComms();
    }
    // "="
    getComms(); ///<expression>
    CompExpression();
    ///  </expression>
    if (bruh == 1)
    {
        fprintf(outputFile, "pop temp 0\n");
        fprintf(outputFile, "pop pointer 1\n");
        fprintf(outputFile, "push temp 0\n");
        fprintf(outputFile, "pop that 0\n");
    }
    else
        fprintf(outputFile, "pop %s %d\n", varName.kind, varName.index);
    getComms(); // ";"
    if (ERRROR)
        return;
}

void CompIfStatement()
{
    if (ERRROR)
        return;
    //printf("I am in If Statement\n");
    int tlabelNum = labelNum;
    labelNum += 2;
    getComms(); // "if"
    getComms(); // "("
    getComms(); //<expression>
    CompExpression();
    getComms(); //")"
    getComms(); //"{"
    fprintf(outputFile, "not\n");
    fprintf(outputFile, "if-goto %s.%d\n", ClassName, tlabelNum);
    getComms();
    CompStatements();
    /// </statements>
    getComms(); // "}"
    fprintf(outputFile, "goto %s.%d\n", ClassName, tlabelNum + 1);
    fprintf(outputFile, "label %s.%d\n", ClassName, tlabelNum);
    getComms();
    if (strcmp(outside, "else") == 0)
    {
        getComms(); // "{"
        getComms();
        CompStatements();
        getComms(); // "}"
        getComms();
    }
    fprintf(outputFile, "label %s.%d\n", ClassName, tlabelNum + 1);
    if (ERRROR)
        return;
}

void CompWhileStatement()
{
    if (ERRROR)
        return;
    //printf("I am in While Statement\n");
    int tlabelNum = labelNum;
    labelNum += 2;
    getComms(); //"while"
    getComms(); //"("
    fprintf(outputFile, "label %s.%d\n", ClassName, tlabelNum);
    getComms();
    CompExpression();
    /// </expression>
    getComms(); //")"
    fprintf(outputFile, "not\n");
    fprintf(outputFile, "if-goto %s.%d\n", ClassName, tlabelNum + 1);
    getComms(); //"{"
    getComms();
    CompStatements();
    /// </statements>
    getComms(); //"}"
    fprintf(outputFile, "goto %s.%d\n", ClassName, tlabelNum);
    fprintf(outputFile, "label %s.%d\n", ClassName, tlabelNum + 1);
    if (ERRROR)
        return;
}

void CompReturnStatement()
{
    if (ERRROR)
        return;
    //printf("I am in Return Statement\n");
    getComms(); //<return>
    getComms();
    if (strcmp(inside, "expression") == 0)
    {
        CompExpression();
        /// </expression>
        fprintf(outputFile, "return\n");
        getComms();
    }
    else
    {
        fprintf(outputFile, "push constant 0\n");
        fprintf(outputFile, "return\n");
    }
    // ";"
    if (ERRROR)
        return;
}

void CompStatements()
{
    if (ERRROR)
        return;
    //printf("I am in Statements\n");
    getComms();
    while ((strcmp(inside, "letStatement") == 0) || (strcmp(inside, "returnStatement") == 0) || (strcmp(inside, "whileStatement") == 0) || (strcmp(inside, "ifStatement") == 0) || (strcmp(inside, "doStatement") == 0))
    {
        if (strcmp(inside, "letStatement") == 0)
        {
            CompLetStatement();
            getComms(); ///</LetStatement
        }
        else if (strcmp(inside, "returnStatement") == 0)
        {
            CompReturnStatement();
            getComms();
        }
        else if (strcmp(inside, "whileStatement") == 0)
        {
            CompWhileStatement();
            getComms();
        }
        else if (strcmp(inside, "ifStatement") == 0)
        {
            CompIfStatement();
            //getComms();
        }
        else
        {
            CompDoStatement();
            getComms();
        }
        getComms();
        if (ERRROR)
            return;
    }
}
void CompVarDec()
{
    if (ERRROR)
        return;
    //printf("I am in VarDec\n");
    getComms(); /// 'var'
    getComms(); ///type
    char tyyp[MAXCHARPERLINE];
    strcpy(tyyp, outside);
    getComms();
    char naam[MAXCHARPERLINE];
    strcpy(naam, outside);
    if (checkSTE(naam) != 0)
    {
        fprintf(errorFile, "Declaration error: %s already declared\n", naam);
        ERRROR = true;
        return;
    }
    strcpy(SubSTE[SS + total_count].name, naam);
    char l[] = "local";
    strcpy(SubSTE[SS + total_count].kind, l);
    strcpy(SubSTE[SS + total_count].type, tyyp);
    SubSTE[SS + total_count].index = local_count;
    local_count++;
    total_count++;
    getComms();
    while (strcmp(outside, ",") == 0)
    {
        getComms();
        strcpy(naam, outside);
        if (checkSTE(naam) != 0)
        {
            fprintf(errorFile, "Declaration error: %s already declared\n", naam);
            ERRROR = true;
            return;
        }
        strcpy(SubSTE[SS + total_count].name, naam);
        strcpy(SubSTE[SS + total_count].kind, l);
        strcpy(SubSTE[SS + total_count].type, tyyp);
        SubSTE[SS + total_count].index = local_count;
        local_count++;
        total_count++;
        getComms();
    }
    ///   ';'
}

void CompSubroutineBody()
{
    if (ERRROR)
        return;
    //printf("I am in SubroutineBody\n");
    getComms(); /// '{'
    getComms();
    while (strcmp(inside, "varDec") == 0)
    {
        CompVarDec();
        if (ERRROR)
            return;
        getComms();
        getComms();
    }
    fprintf(outputFile, "function %s.%s %d\n", ClassName, SubRoutineName, local_count);
    if (strcmp(SubRoutineType, "constructor") == 0)
    {
        fprintf(outputFile, "push constant %d\n", field_count);
        fprintf(outputFile, "call Memory.alloc 1\n");
        fprintf(outputFile, "pop pointer 0\n");
    }
    else if (strcmp(SubRoutineType, "method") == 0)
    {
        fprintf(outputFile, "push argument 0\n");
        fprintf(outputFile, "pop pointer 0\n");
    }
    else
        ;
    ///<statements>
    CompStatements();
    if (ERRROR)
        return;
    ///</statements>
    getComms(); ///  '}'
}

void CompParameterList()
{
    if (ERRROR)
        return;
    //printf("I am in ParameterList\n");
    getComms();
    if (strcmp(inside, "/parameterList") == 0)
        return;
    char tyyp[MAXCHARPERLINE];
    strcpy(tyyp, outside);
    getComms();
    char naam[MAXCHARPERLINE];
    strcpy(naam, outside);
    if (checkSTE(naam) != 0)
    {
        fprintf(errorFile, "Declaration error: %s already declared\n", naam);
        ERRROR = true;
        return;
    }
    strcpy(SubSTE[arg_count + SS].name, naam);
    char t[] = "argument";
    strcpy(SubSTE[arg_count + SS].kind, t);
    strcpy(SubSTE[arg_count + SS].type, tyyp);
    SubSTE[arg_count + SS].index = arg_count;
    arg_count++;
    total_count++;
    getComms();
    while (strcmp(outside, ",") == 0)
    {
        getComms();
        strcpy(tyyp, outside);
        getComms();
        strcpy(naam, outside);
        if (checkSTE(naam) != 0)
        {
            fprintf(errorFile, "Declaration error: %s already declared\n", naam);
            ERRROR = true;
            return;
        }
        strcpy(SubSTE[SS + arg_count].name, naam);
        strcpy(SubSTE[SS + arg_count].kind, t);
        strcpy(SubSTE[SS + arg_count].type, tyyp);
        SubSTE[SS + arg_count].index = arg_count;
        arg_count++;
        total_count++;
        getComms();
    }
}

void CompSubroutineDec()
{
    if (ERRROR)
        return;
    //printf("I am in SubroutineDec\n");
    getComms(); ///constructor|method|function
    strcpy(SubRoutineType, outside);
    getComms(); ///void|type
    char tyyp[MAXCHARPERLINE];
    strcpy(tyyp, outside);
    getComms();
    ///subRoutineName
    strcpy(SubRoutineName, outside);
    SS = SS + total_count;
    local_count = 0;
    arg_count = 0;
    total_count = 0;
    if (strcmp(SubRoutineType, "method") == 0)
    {
        char t1[] = "this";
        strcpy(SubSTE[SS].name, t1);
        char t2[] = "argument";
        strcpy(SubSTE[SS].kind, t2);
        strcpy(SubSTE[SS].type, tyyp);
        SubSTE[SS].index = 0;
        arg_count++;
        total_count++;
    }
    getComms(); // "("
    getComms(); ///<parameterList>
    CompParameterList();
    if (ERRROR)
        return;
    getComms(); ///    ')'
    getComms(); ///<subroutineBody>
    CompSubroutineBody();
    if (ERRROR)
        return;
    getComms(); ///</subroutineBody>
}

void CompClassVarDec()
{
    if (ERRROR)
        return;
    //printf("I am in ClassVarDec\n");
    char sf[8];
    char tyype[MAXCHARPERLINE];
    char naam[MAXCHARPERLINE];
    getComms();
    strcpy(sf, outside);
    getComms();
    strcpy(tyype, outside);
    getComms();
    strcpy(naam, outside);
    if (checkSTE(naam) != 0)
    {
        fprintf(errorFile, "Declaration error: %s already declared\n", naam);
        ERRROR = true;
        return;
    }
    if (strcmp(sf, "static") == 0)
    {
        strcpy(ClassSTE[CC + Total_count].name, naam);
        strcpy(ClassSTE[CC + Total_count].type, tyype);
        strcpy(ClassSTE[CC + Total_count].kind, "static");
        ClassSTE[CC + Total_count].index = static_count;
        static_count++;
    }
    else if (strcmp(sf, "field") == 0)
    {
        strcpy(ClassSTE[CC + Total_count].name, naam);
        strcpy(ClassSTE[CC + Total_count].type, tyype);
        strcpy(ClassSTE[CC + Total_count].kind, "this");
        ClassSTE[CC + Total_count].index = field_count;
        field_count++;
    }
    else
    {
        fprintf(errorFile, "ERROR : Expected <static> or <field> but %s\n", sf);
        ERRROR = true;
        return;
    }
    Total_count++;
    getComms();
    while (strcmp(outside, ",") == 0)
    {
        getComms();
        strcpy(naam, outside);
        if (checkSTE(naam) != 0)
        {
            fprintf(errorFile, "Declaration error: %s already declared\n", naam);
            ERRROR = true;
            return;
            return;
        }
        if (strcmp(sf, "static") == 0)
        {
            strcpy(ClassSTE[CC + Total_count].name, naam);
            strcpy(ClassSTE[CC + Total_count].type, tyype);
            strcpy(ClassSTE[CC + Total_count].kind, "static");
            ClassSTE[CC + Total_count].index = static_count;
            static_count++;
        }
        else if (strcmp(sf, "field") == 0)
        {
            strcpy(ClassSTE[CC + Total_count].name, naam);
            strcpy(ClassSTE[CC + Total_count].type, tyype);
            strcpy(ClassSTE[CC + Total_count].kind, "this");
            ClassSTE[CC + Total_count].index = field_count;
            field_count++;
        }
        else
        {
            fprintf(errorFile, "ERROR : Expected <static> or <field> but %s\n", sf);
            ERRROR = true;
            return;
        }
        Total_count++;
        getComms();
    }
    //no need ...here we have ';'
}

void CompClass()
{
    //printf("I am in Class\n");
    getComms(); //"class"
    getComms(); //className
    ///copy class Name
    strcpy(ClassName, outside);

    getComms(); //"{"
    getComms();
    CC = CC + Total_count;
    static_count = 0;
    field_count = 0;
    Total_count = 0;
    while (strcmp(inside, "classVarDec") == 0)
    {
        CompClassVarDec();
        if (ERRROR)
            return;
        getComms(); ///   </..>
        getComms();
    }

    while (strcmp(inside, "subroutineDec") == 0)
    {
        CompSubroutineDec();
        if (ERRROR)
            return;
        getComms(); ///   </..>
        getComms();
    }
    //no need to getComms() again
}

///
/////////
///

int main(int argc, char **argv)
{
    //printf("%d %s\n",argc,argv[2]);
    for (int xxxx = 2; xxxx < argc; xxxx++)
    {

        ERRROR = false;
        FILE *inputFile1;
        FILE *outputFile1;

        char *fileName = argv[xxxx];

        inputFile1 = fopen(fileName, "r");
        outputFile1 = initializeO1(argv[xxxx]);
        errorFile = initializeE(argv[xxxx]);
        outputFile = initializefinalOutput(argv[xxxx]);

        fprintf(outputFile1, "<tokens>\n");
        char nextCommand[MAXCHARPERLINE];
        char parsedCommand[MAXCHARPERLINE];
        char symbol[MAXCHARPERLINE];
        int tempC = 0;
        int i = 0, j = 0;
        int lineNumber = 0;
        //
        //Start to read...............
        while (fgets(nextCommand, MAXCHARPERLINE, inputFile1) != NULL)
        {
            lineNumber++;
            i = 0;
            j = 0;
            parsedCommand[0] = '\0';
            symbol[0] = '\0';
            if (tempC == 1)
            {
                while (nextCommand[i] != '\n' && nextCommand[i] != EOF)
                {
                    if (nextCommand[i] == '*')
                    {
                        if (nextCommand[i + 1] == '/')
                        {
                            i = i + 2;
                            tempC = 0;
                            break;
                        }
                    }
                    i++;
                }
            }
            if (tempC == 1)
                continue;
            if (tempC != 0)
                tempC = 0;

            while (nextCommand[i] != '\n' && nextCommand[i] != EOF)
            {

                if (nextCommand[i] == '/')
                {
                    if (nextCommand[i + 1] == '/')
                    { //type command
                        tempC = -1;
                        break;
                    }
                    if (nextCommand[i + 1] == '*')
                    { /*type command*/
                        tempC = 1;
                        int k = i + 2;
                        while (nextCommand[k] != '\n')
                        {
                            if (nextCommand[k] == '*')
                            {
                                if (nextCommand[k + 1] == '/')
                                {
                                    tempC = 0;
                                    i = k + 2;
                                    break;
                                }
                            }
                            k++;
                        }
                        if (tempC == 1)
                            break;
                    }
                }
                if ((nextCommand[i] != ' ') && (nextCommand[i] != '\t'))
                    break;
                i++;
            }
            if (tempC != 0)
                continue;

            while (nextCommand[i] != '\n' && nextCommand[i] != EOF)
            {
                if (nextCommand[i] == '/' && nextCommand[i + 1] == '/')
                    break;
                parsedCommand[j++] = nextCommand[i++];
            }
            parsedCommand[j] = '\n';
            parsedCommand[j + 1] = '\0';
            //Parsed command created with not a space at its beginning
            i = 0;
            size_t len = strlen(parsedCommand);
            while (parsedCommand[i] != '\n' && i < len)
            {

                char start = parsedCommand[i];
                j = 0;
                symbol[0] = '\0';
                if (start == '_' || (start >= 'a' && start <= 'z') || (start >= 'A' && start <= 'Z'))
                {
                    //keyword or identifier
                    //copying in symbol
                    while (parsedCommand[i] == '_' || (parsedCommand[i] >= 'a' && parsedCommand[i] <= 'z') || (parsedCommand[i] >= 'A' && parsedCommand[i] <= 'Z') || (parsedCommand[i] >= '0' && parsedCommand[i] <= '9'))
                    {
                        symbol[j] = parsedCommand[i];
                        j++;
                        i++;
                    }
                    symbol[j] = '\0';
                    if (checkforKeyword(symbol) == 1)
                    { // KEYWORD
                        fprintf(outputFile1, "<keyword> %s </keyword>\n", symbol);
                    }
                    else
                    { // IDENTIFIER
                        fprintf(outputFile1, "<identifier> %s </identifier>\n", symbol);
                    }
                }

                else if (start == '\"')
                { // String Constant
                    i++;
                    while (parsedCommand[i] != '\n' && parsedCommand[i] != '\"')
                    {
                        symbol[j] = parsedCommand[i];
                        j++;
                        i++;
                    }
                    symbol[j] = '\0';
                    if (parsedCommand[i] == '\n' && !ERRROR)
                    {
                        //printf("ERROR : At line %d : String constant was not defined properly\n",lineNumber);
                        fprintf(errorFile, "ERROR: %s\n", symbol);
                        // ERRROR=true;return;
                        ERRROR = true;
                    }
                    fprintf(outputFile1, "<stringConstant> %s </stringConstant>\n", symbol);
                    i++;
                }

                else if (start >= '0' && start <= '9')
                { // Integer Constant
                    while (parsedCommand[i] >= '0' && parsedCommand[i] <= '9')
                    {
                        symbol[j] = parsedCommand[i];
                        j++;
                        i++;
                    }
                    symbol[j] = '\0';
                    fprintf(outputFile1, "<integerConstant> %s </integerConstant>\n", symbol);
                }
                else
                {
                    if (checkforSymbol(start) == 1)
                    {
                        if (start == '<')
                            fprintf(outputFile1, "<symbol> &lt; </symbol>\n");
                        else if (start == '>')
                            fprintf(outputFile1, "<symbol> &gt; </symbol>\n");
                        else if (start == '\"')
                            fprintf(outputFile1, "<symbol> &quot; </symbol>\n");
                        else if (start == '&')
                            fprintf(outputFile1, "<symbol> &amp; </symbol>\n");
                        else
                            fprintf(outputFile1, "<symbol> %c </symbol>\n", start);
                        i++;
                    }
                    else
                    {
                        fprintf(errorFile, "ERROR: %c\n", start);
                        ERRROR = true;
                    }
                }
                while (parsedCommand[i] == ' ' || parsedCommand[i] == '\t')
                    i++;
                if (ERRROR)
                    break;
            }
            if (ERRROR)
                break;
        }
        fprintf(outputFile1, "</tokens>\n");

        fclose(inputFile1);
        fclose(outputFile1);

        if (ERRROR)
            continue;

        inputFile2 = initializeinput2(argv[xxxx]);
        outputFile2 = initializeO2(argv[xxxx]);

        fgets(command, MAXCHARPERLINE, inputFile2);
        if (strcmp(command, "<tokens>\n") != 0 && !ERRROR)
        {
            fprintf(errorFile, "ERROR: Expecting <tokens> but %s\n", name);
            ERRROR = true;
        }
        print("<class>\n");
        spaces = 2;
        compileClass();
        spaces = 0;
        print("</class>\n");

        fclose(inputFile2);
        fclose(outputFile2);

        if (ERRROR)
            continue;

        inputFile = initializefinalInput(argv[xxxx]);
        //outputFile = initializefinalOutput(argv[xxxx]);
        labelNum = 0;
        getComms();
        CompClass();
        getComms();

        fclose(inputFile);
        fclose(outputFile);
        fclose(errorFile);

        labelNum = 0;
    }
    return 0;
}
