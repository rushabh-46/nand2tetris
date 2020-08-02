#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLENGTH 40
#define MAXENTRIES 10000
#define MAXCHARPERLINE 80

FILE *initializeInterFile(char *fileName)
{
    int i = 0;
    while (fileName[i] != '.')
        i++;
    fileName[i + 1] = 'i';
    fileName[i + 2] = 'n';
    fileName[i + 3] = 't';
    fileName[i + 4] = 'e';
    fileName[i + 5] = 'r';
    fileName[i + 6] = '\0';

    return fopen(fileName, "w");
}

FILE *initializeOutputFile(char *fileName)
{
    int i = 0;
    while (fileName[i] != '.')
        i++;
    fileName[i + 1] = 'h';
    fileName[i + 2] = 'a';
    fileName[i + 3] = 'c';
    fileName[i + 4] = 'k';
    fileName[i + 5] = '\0';

    return fopen(fileName, "w");
}

FILE *openInterFile(char *fileName)
{
    int i = 0;
    while (fileName[i] != '.')
        i++;
    fileName[i + 1] = 'i';
    fileName[i + 2] = 'n';
    fileName[i + 3] = 't';
    fileName[i + 4] = 'e';
    fileName[i + 5] = 'r';
    fileName[i + 6] = '\0';

    return fopen(fileName, "r");
}

struct SymbolTableEntry
{
    char symbol[MAXLENGTH];
    int address;
};

struct SymbolTableEntry SymbolTable[MAXENTRIES];

void InitializeSymbolTable()
{

    strcpy(SymbolTable[0].symbol, "SP");
    strcpy(SymbolTable[1].symbol, "LCL");
    strcpy(SymbolTable[2].symbol, "ARG");
    strcpy(SymbolTable[3].symbol, "THIS");
    strcpy(SymbolTable[4].symbol, "THAT");
    strcpy(SymbolTable[5].symbol, "R0");
    strcpy(SymbolTable[6].symbol, "R1");
    strcpy(SymbolTable[7].symbol, "R2");
    strcpy(SymbolTable[8].symbol, "R3");
    strcpy(SymbolTable[9].symbol, "R4");
    strcpy(SymbolTable[10].symbol, "R5");
    strcpy(SymbolTable[11].symbol, "R6");
    strcpy(SymbolTable[12].symbol, "R7");
    strcpy(SymbolTable[13].symbol, "R8");
    strcpy(SymbolTable[14].symbol, "R9");
    strcpy(SymbolTable[15].symbol, "R10");
    strcpy(SymbolTable[16].symbol, "R11");
    strcpy(SymbolTable[17].symbol, "R12");
    strcpy(SymbolTable[18].symbol, "R13");
    strcpy(SymbolTable[19].symbol, "R14");
    strcpy(SymbolTable[20].symbol, "R15");
    strcpy(SymbolTable[21].symbol, "SCREEN");
    strcpy(SymbolTable[22].symbol, "KBD");

    SymbolTable[0].address = 0;
    SymbolTable[1].address = 1;
    SymbolTable[2].address = 2;
    SymbolTable[3].address = 3;
    SymbolTable[4].address = 4;
    SymbolTable[5].address = 0;
    SymbolTable[6].address = 1;
    SymbolTable[7].address = 2;
    SymbolTable[8].address = 3;
    SymbolTable[9].address = 4;
    SymbolTable[10].address = 5;
    SymbolTable[11].address = 6;
    SymbolTable[12].address = 7;
    SymbolTable[13].address = 8;
    SymbolTable[14].address = 9;
    SymbolTable[15].address = 10;
    SymbolTable[16].address = 11;
    SymbolTable[17].address = 12;
    SymbolTable[18].address = 13;
    SymbolTable[19].address = 14;
    SymbolTable[20].address = 15;
    SymbolTable[21].address = 16384;
    SymbolTable[22].address = 24576;

    for (int i = 23; i < MAXENTRIES; i++)
    {
        strcpy(SymbolTable[i].symbol, "\0");
        SymbolTable[i].address = -1;
    }
}

void getJmpCode(char *inpJmp, char *jmp)
{
    if (strcmp(inpJmp, "JGT") == 0)
        strcpy(jmp, "001");
    if (strcmp(inpJmp, "JEQ") == 0)
        strcpy(jmp, "010");
    if (strcmp(inpJmp, "JGE") == 0)
        strcpy(jmp, "011");
    if (strcmp(inpJmp, "JLT") == 0)
        strcpy(jmp, "100");
    if (strcmp(inpJmp, "JNE") == 0)
        strcpy(jmp, "101");
    if (strcmp(inpJmp, "JLE") == 0)
        strcpy(jmp, "110");
    if (strcmp(inpJmp, "JMP") == 0)
        strcpy(jmp, "111");
}

void getDestCode(char *inpDest, char *dest)
{
    if (strcmp(inpDest, "M") == 0)
        strcpy(dest, "001");
    if (strcmp(inpDest, "D") == 0)
        strcpy(dest, "010");
    if (strcmp(inpDest, "MD") == 0)
        strcpy(dest, "011");
    if (strcmp(inpDest, "DM") == 0)
        strcpy(dest, "011");
    if (strcmp(inpDest, "A") == 0)
        strcpy(dest, "100");
    if (strcmp(inpDest, "AM") == 0)
        strcpy(dest, "101");
    if (strcmp(inpDest, "MA") == 0)
        strcpy(dest, "101");
    if (strcmp(inpDest, "AD") == 0)
        strcpy(dest, "110");
    if (strcmp(inpDest, "DA") == 0)
        strcpy(dest, "110");
    if (strcmp(inpDest, "MAD") == 0)
        strcpy(dest, "111");
    if (strcmp(inpDest, "MDA") == 0)
        strcpy(dest, "111");
    if (strcmp(inpDest, "AMD") == 0)
        strcpy(dest, "111");
    if (strcmp(inpDest, "DMA") == 0)
        strcpy(dest, "111");
    if (strcmp(inpDest, "ADM") == 0)
        strcpy(dest, "111");
    if (strcmp(inpDest, "DAM") == 0)
        strcpy(dest, "111");
}

void getCompCode(char *inpComp, char *comp)
{
    if (strcmp(inpComp, "0") == 0)
        strcpy(comp, "0101010");
    else if (strcmp(inpComp, "1") == 0)
        strcpy(comp, "0111111");
    else if (strcmp(inpComp, "-1") == 0)
        strcpy(comp, "0111010");
    else if (strcmp(inpComp, "D") == 0)
        strcpy(comp, "0001100");
    else if (strcmp(inpComp, "A") == 0)
        strcpy(comp, "0110000");
    else if (strcmp(inpComp, "M") == 0)
        strcpy(comp, "1110000");
    else if (strcmp(inpComp, "!D") == 0)
        strcpy(comp, "0001101");
    else if (strcmp(inpComp, "!A") == 0)
        strcpy(comp, "0110001");
    else if (strcmp(inpComp, "!M") == 0)
        strcpy(comp, "1110001");
    else if (strcmp(inpComp, "-D") == 0)
        strcpy(comp, "0001111");
    else if (strcmp(inpComp, "-A") == 0)
        strcpy(comp, "0110011");
    else if (strcmp(inpComp, "-M") == 0)
        strcpy(comp, "1110011");
    else if (strcmp(inpComp, "D+1") == 0)
        strcpy(comp, "0011111");
    else if (strcmp(inpComp, "1+D") == 0)
        strcpy(comp, "0011111");
    else if (strcmp(inpComp, "A+1") == 0)
        strcpy(comp, "0110111");
    else if (strcmp(inpComp, "1+A") == 0)
        strcpy(comp, "0110111");
    else if (strcmp(inpComp, "M+1") == 0)
        strcpy(comp, "1110111");
    else if (strcmp(inpComp, "1+M") == 0)
        strcpy(comp, "1110111");
    else if (strcmp(inpComp, "D-1") == 0)
        strcpy(comp, "0001110");
    else if (strcmp(inpComp, "-1+D") == 0)
        strcpy(comp, "0001110");
    else if (strcmp(inpComp, "A-1") == 0)
        strcpy(comp, "0110010");
    else if (strcmp(inpComp, "-1+A") == 0)
        strcpy(comp, "0110010");
    else if (strcmp(inpComp, "M-1") == 0)
        strcpy(comp, "1110010");
    else if (strcmp(inpComp, "-1+M") == 0)
        strcpy(comp, "1110010");
    else if (strcmp(inpComp, "D+A") == 0)
        strcpy(comp, "0000010");
    else if (strcmp(inpComp, "A+D") == 0)
        strcpy(comp, "0000010");
    else if (strcmp(inpComp, "M+D") == 0)
        strcpy(comp, "1000010");
    else if (strcmp(inpComp, "D+M") == 0)
        strcpy(comp, "1000010");
    else if (strcmp(inpComp, "D-A") == 0)
        strcpy(comp, "0010011");
    else if (strcmp(inpComp, "-A+D") == 0)
        strcpy(comp, "0010011");
    else if (strcmp(inpComp, "D-M") == 0)
        strcpy(comp, "1010011");
    else if (strcmp(inpComp, "-M+D") == 0)
        strcpy(comp, "1010011");
    else if (strcmp(inpComp, "A-D") == 0)
        strcpy(comp, "0000111");
    else if (strcmp(inpComp, "-D+A") == 0)
        strcpy(comp, "0000111");
    else if (strcmp(inpComp, "M-D") == 0)
        strcpy(comp, "1000111");
    else if (strcmp(inpComp, "-D+M") == 0)
        strcpy(comp, "1000111");
    else if (strcmp(inpComp, "D&A") == 0)
        strcpy(comp, "0000000");
    else if (strcmp(inpComp, "A&D") == 0)
        strcpy(comp, "0000000");
    else if (strcmp(inpComp, "M&D") == 0)
        strcpy(comp, "1000000");
    else if (strcmp(inpComp, "D&M") == 0)
        strcpy(comp, "1000000");
    else if (strcmp(inpComp, "D|A") == 0)
        strcpy(comp, "0010101");
    else if (strcmp(inpComp, "A|D") == 0)
        strcpy(comp, "0010101");
    else if (strcmp(inpComp, "M|D") == 0)
        strcpy(comp, "1010101");
    else if (strcmp(inpComp, "D|M") == 0)
        strcpy(comp, "1010101");
}

int containGetAddress(char *);

void convertToBinary(int n, char a[])
{
    int rema;
    char c;
    int i = 0;
    while (n != 0)
    {
        rema = n % 2;
        if (rema == 0)
            c = '0';
        else
            c = '1';
        a[i] = c;
        i++;
        n = n / 2;
    }
    while (i < 16)
    {
        a[i] = '0';
        i++;
    }
    while (i > 7)
    {
        char p = a[i];
        a[i] = a[15 - i];
        a[15 - i] = p;
        i--;
    }
    //printf(" convertToBin : %s . ",a);
}

int commandTYPE(char *parsedCommand)
{
    if (parsedCommand[0] == '@')
        return 0; //A_COMMAND 0
    if (parsedCommand[0] == '(')
    {
        int i = 1;
        while ((parsedCommand[i] != ')') && (parsedCommand[i] != '\n'))
            i++;

        if (parsedCommand[i] == '\n')
            return -1; // error (...\n  -1
        if (parsedCommand[i + 1] == '\n')
            return 1; //L_COMMAND 1
        if (parsedCommand[i + 1] == '@')
            return 3; //L_AND_A 3
        return 4;     //L_AND_C 4
    }
    else
        return 2; // C_COMMAND 2
}

void addEntry(struct SymbolTableEntry item)
{

    char *symbol = item.symbol;

    int p = containGetAddress(symbol);

    if (p == -4)
    {
        printf("ERROR : SYMBOLTABLE full. p=-4\n");
        exit(-1);
    }

    if (p < 0)
    {

        int i = 0;
        while ((strcmp(SymbolTable[i].symbol, item.symbol) != 0) && (strcmp(SymbolTable[i].symbol, "\0") != 0))
            i++;

        if (p == -3)
        {
            strcpy(SymbolTable[i].symbol, item.symbol);
            SymbolTable[i].address = item.address;
        }
        else
        {
            SymbolTable[i].address = item.address;
        }
    }
}

int containGetAddress(char *symbol)
{
    int i = 0;
    while (i < MAXENTRIES)
    { //&& (SymbolTable[i].address!=-1)) {

        if (strcmp(SymbolTable[i].symbol, "\0") == 0)
            return -3; //NO symbol defined at all

        if (strcmp(SymbolTable[i].symbol, symbol) == 0) //return SymbolTable[i].address;
        {
            if (SymbolTable[i].address == -1)
                return -1; // variable symbol defined but with -1 address
            else
                return SymbolTable[i].address; // LOOP variable defined with positive address
        }

        i++;
    }
    return -4; //Symbol Table full
}

int main(int argc, char **argv)
{
    FILE *inputFile;
    FILE *interFile;
    FILE *outputFile;

    int instructionNumber = 0;
    int lineNumber = 0;
    char nextCommand[MAXCHARPERLINE];

    int i, j, k;
    char parsedCommand[MAXCHARPERLINE];
    char symbol1[MAXLENGTH];
    char symbol2[MAXLENGTH];

    InitializeSymbolTable();
    struct SymbolTableEntry item;

    //for(i=0;i<MAXENTRIES;i++)  {
    //	if(strcmp(SymbolTable[i].symbol,"\0") ==0) break;
    //	printf(" %d : %s  %d\n",i,SymbolTable[i].symbol,SymbolTable[i].address);
    //}

    char *fileName = argv[1];
    inputFile = fopen(fileName, "r");
    interFile = initializeInterFile(fileName);

    int tempC = 0;

    while (fgets(nextCommand, MAXCHARPERLINE, inputFile) != NULL)
    { //Pass1

        lineNumber++;

        //printf("Line %d : %s %d\n",lineNumber,SymbolTable[5].symbol,SymbolTable[5].address);

        parsedCommand[0] = '\0';
        symbol1[0] = '\0';
        symbol2[0] = '\0';

        i = 0;
        j = 0;

        if (tempC == 1)
        {
            while (nextCommand[i] != '\n')
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

        while (nextCommand[i] != '\n')
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
                    k = i + 2;
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
                parsedCommand[j++] = nextCommand[i];
            i++;
        }
        if (tempC != 0)
            continue;
        parsedCommand[j] = '\n';
        parsedCommand[j + 1] = '\0';
        //printf(" %d : %s\n",lineNumber,parsedCommand);
        if (parsedCommand[0] != '\n')
        {

            //instructionNumber++;

            i = commandTYPE(parsedCommand);
            if (i == 1 || i == 3 || i == 4)
            {
                j = 0;
                if ((parsedCommand[1] < '0') || (parsedCommand[1] > '9'))
                { //extracting elements
                    while ((parsedCommand[j + 1] != ')') && (parsedCommand[j + 1] != '\n'))
                    {
                        symbol1[j] = parsedCommand[j + 1];
                        j++;
                    }
                }
                else
                {
                    printf("ERROR : Loop name cant begin with a number. At line number %d\n", lineNumber);
                    exit(-1);
                }
                symbol1[j] = '\0';

                if (parsedCommand[j + 1] != ')')
                {
                    printf("ERROR : Incorrect Instruction at line : %d\n", lineNumber);
                    exit(-1);
                }

                if (containGetAddress(symbol1) == -2)
                {
                    printf("ERROR : LOOP VARIABLE DEFINED AGAIN at line : %d\n", lineNumber);
                    exit(-1);
                }

                strcpy(item.symbol, symbol1);
                item.address = instructionNumber;
                addEntry(item);

                if (i == 3)
                { // L_AND_A
                    j = j + 3;
                    k = 0;
                    if ((parsedCommand[j] < '0') || (parsedCommand[j] > '9'))
                    { // extracting the other variable
                        while (parsedCommand[j] != '\n')
                        {
                            symbol2[k++] = parsedCommand[j++];
                        }
                        symbol2[k] = '\0';

                        if (symbol2[0] == '\0')
                        {
                            printf("ERROR : INCORRECT variable defined at line NUmber : %d\n", lineNumber);
                            exit(-1);
                        }
                        strcpy(item.symbol, symbol2);
                        item.address = -1;
                        addEntry(item);
                    }
                }
            }

            if (i == 0)
            {
                j = 0;
                if ((parsedCommand[1] < '0') || (parsedCommand[1] > '9'))
                { //extracting elements
                    while (parsedCommand[j + 1] != '\n')
                    {
                        symbol1[j] = parsedCommand[j + 1];
                        j++;
                    }
                    symbol1[j] = '\0';

                    strcpy(item.symbol, symbol1);
                    item.address = -1;
                    addEntry(item);
                }
            }

            if (i != 1)
            {

                instructionNumber++;

                if (i == 3 || i == 4)
                {
                    j = 0;
                    //fprintf(interFile,"/* ");
                    while (parsedCommand[j] != ')')
                    {
                        //fprintf(interFile,"%c",parsedCommand[j]);
                        j++;
                    }
                    //fprintf(interFile,") */");
                    j++;
                    while (parsedCommand[j - 1] != '\n')
                    {
                        fprintf(interFile, "%c", parsedCommand[j]);
                        j++;
                    }
                }
                else
                {
                    fprintf(interFile, "%s", parsedCommand);
                }
            }
        }
    }
    //SymbolTable[5].address = 0;
    j = 16;
    for (i = 0; i < MAXENTRIES; i++)
    {
        if ((strcmp(SymbolTable[i].symbol, "\0") != 0) && (SymbolTable[i].address == -1))
            SymbolTable[i].address = j++;
    }

    if (j == MAXENTRIES)
    {
        printf("ERROR : MAXENTRIES REACHED\n");
        exit(-1);
    }

    fclose(inputFile);
    fclose(interFile);
    //PASS 1 ended.

    //for(i=0;i<MAXENTRIES;i++)  {
    //	if(strcmp(SymbolTable[i].symbol,"\0") ==0) break;
    //	printf(" %d : %s  %d\n",i,SymbolTable[i].symbol,SymbolTable[i].address);
    //}

    //PASS 2 begins

    interFile = openInterFile(fileName);
    outputFile = initializeOutputFile(fileName);

    while (fgets(parsedCommand, MAXCHARPERLINE, interFile) != NULL)
    {

        char assembly_instr[16];
        i = commandTYPE(parsedCommand);
        //printf("i = %d  ",i);
        if (i == 0)
        { //A instruction
            assembly_instr[15] = '0';
            j = 0;
            symbol1[0] = '\0';
            while (parsedCommand[j + 1] != '\n')
            {
                symbol1[j] = parsedCommand[j + 1];
                j++;
            }
            symbol1[j] = '\0';
            if (parsedCommand[1] < '0' || parsedCommand[1] > '9')
            {

                int addr = containGetAddress(symbol1);
                if (addr < 0)
                {
                    printf("ERROR : ADDRESS NOT IN the SYMBOL TABLE\n");
                    exit(-1);
                }
                //printf(" address = %d  ",addr);
                convertToBinary(addr, assembly_instr);
            }
            else
            {
                int addr = 0;
                i = j - 1;
                while (i >= 0)
                {
                    int m = symbol1[i] - '0';
                    int p = 1;
                    int run = j - i - 1;
                    while (run > 0)
                    {
                        p = p * 10;
                        run--;
                    }
                    addr += m * p; //printf(" address = %d  ",addr);
                    i--;
                }
                //printf("\n");
                //printf(" address = %d  ",addr);
                convertToBinary(addr, assembly_instr);
            }
        }

        else
        { //C instruction

            char inpDest[10];
            char inpComp[10];
            char inpJmp[10];

            char dest[4];
            char comp[8];
            char jmp[4];

            strcpy(inpDest, "\0");
            strcpy(inpComp, "\0");
            strcpy(inpJmp, "\0");
            strcpy(dest, "\0");
            strcpy(comp, "\0");
            strcpy(jmp, "\0");

            j = 0;

            while ((parsedCommand[j] != '=') && (parsedCommand[j] != ';'))
            {
                inpDest[j] = parsedCommand[j];
                inpComp[j] = parsedCommand[j];
                j++;
            }
            k = 0;
            if (parsedCommand[j] == '=')
            {
                inpDest[j] = '\0';
                j++;
                while (parsedCommand[j] != '\n')
                {
                    inpComp[k] = parsedCommand[j];
                    j++;
                    k++;
                }
                inpComp[k] = '\0';
                jmp[0] = '0';
                jmp[1] = '0';
                jmp[2] = '0';
                getDestCode(inpDest, dest);
                getCompCode(inpComp, comp);
            }
            else
            {
                inpComp[j] = '\0';
                j++;
                while (parsedCommand[j] != '\n')
                {
                    inpJmp[k] = parsedCommand[j];
                    j++;
                    k++;
                }
                inpJmp[k] = '\0';
                dest[0] = '0';
                dest[1] = '0';
                dest[2] = '0';
                getCompCode(inpComp, comp);
                getJmpCode(inpJmp, jmp);
            }

            assembly_instr[0] = '1';
            assembly_instr[1] = '1';
            assembly_instr[2] = '1';
            i = 3;
            while (i < 10)
            {
                assembly_instr[i] = comp[i - 3];
                i++;
            }
            while (i < 13)
            {
                assembly_instr[i] = dest[i - 10];
                i++;
            }
            while (i < 16)
            {
                assembly_instr[i] = jmp[i - 13];
                i++;
            }
        }
        //printf(" %s\n",assembly_instr);
        i = 0;
        while (i < 16)
        {
            fprintf(outputFile, "%c", assembly_instr[i]);
            i++;
        }
        fprintf(outputFile, "\n");
    }

    fclose(interFile);
    fclose(outputFile);
}
