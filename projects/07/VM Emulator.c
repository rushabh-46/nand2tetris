#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXCHARPERLINE 80

FILE *initializeO(char *fileName)
{
    int i = 0;
    while (fileName[i] != '.')
        i++;
    fileName[i + 1] = 'a';
    fileName[i + 2] = 's';
    fileName[i + 3] = 'm';
    fileName[i + 4] = '\0';

    return fopen(fileName, "w");
}

int convert(char *arr)
{
    int sii = strlen(arr);
    int sum = 0;
    for (int i = 0; i < sii; i++)
    {
        sum += (arr[i] * (int)(0.5 + pow(10, sii - i - 1)));
    }
    return sum;
}
char *getSegment(char *sym2, char *sym3, char *fileName)
{
    if (strcmp(sym2, "argument") == 0)
        return "ARG";
    else if (strcmp(sym2, "local") == 0)
        return "LCL";
    else if (strcmp(sym2, "this") == 0)
        return "THIS";
    else if (strcmp(sym2, "that") == 0)
        return "THAT";
    else if (strcmp(sym2, "pointer") == 0)
        return "3";
    else if (strcmp(sym2, "temp") == 0)
        return "5";
    else if (strcmp(sym2, "constant") == 0)
        return sym3;
    else if (strcmp(sym2, "static") == 0)
    {

        printf("fiile name is %s  ", fileName);
        /*char s[MAXCHARPERLINE];
            strcpy(s,fileName);
            strcat(s,"_");
            strcat(s,sym3);
            printf("NAME OF STATIC VARIABLE IS  %s  and filename is  %s\n",s,fileName);
            return s;
            */
        char *s = (char *)malloc(sizeof(fileName) + 10);
        int i = 0;
        while (fileName[i] != '\0')
        {
            s[i] = fileName[i];
            i++;
        }
        s[i] = '_';
        i++;
        int j = 0;
        while (sym3[j] != '\0')
        {
            s[i] = sym3[j];
            i++;
            j++;
        }
        s[i] = '\0';
        printf("NAME OF STATIC VARIABLE IS  %s  and filename is  %s\n", s, fileName);
        return s;
    }
    else
    {
        printf("Error : Symbol 2 is incorrect\n");
        exit(-1);
    }
}

void generateCode(FILE *outputFile, char *sym1, char *sym2, char *sym3, int *ALabelNum, int lineNumber, char *fileName)
{
    if ((strcmp(sym1, "push") != 0) && (strcmp(sym1, "pop") != 0))
    {

        //StackArithmetic
        if (strcmp(sym1, "add") == 0)
        {
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "AM=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "A=A-1\n");
            fprintf(outputFile, "M=M+D\n");
        }
        else if (strcmp(sym1, "sub") == 0)
        {
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "AM=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "A=A-1\n");
            fprintf(outputFile, "M=M-D\n");
        }
        else if (strcmp(sym1, "and") == 0)
        {
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "AM=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "A=A-1\n");
            fprintf(outputFile, "M=M&D\n");
        }
        else if (strcmp(sym1, "or") == 0)
        {
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "AM=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "A=A-1\n");
            fprintf(outputFile, "M=M|D\n");
        }
        else if (strcmp(sym1, "not") == 0)
        {
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M-1\n");
            fprintf(outputFile, "M=!M\n");
        }
        else if (strcmp(sym1, "neg") == 0)
        {
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M-1\n");
            fprintf(outputFile, "M=-M\n");
        }
        else if (strcmp(sym1, "eq") == 0)
        {
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "A=A-1\n");
            fprintf(outputFile, "D=M-D\n");
            fprintf(outputFile, "@ALabel_%d\n", *ALabelNum);
            fprintf(outputFile, "D;JEQ\n");
            fprintf(outputFile, "D=0\n");
            fprintf(outputFile, "@ALabel_%d\n", *ALabelNum + 1);
            fprintf(outputFile, "0;JMP\n");
            fprintf(outputFile, "(ALabel_%d)\n", *ALabelNum);
            fprintf(outputFile, "D=-1\n");
            fprintf(outputFile, "(ALabel_%d)\n", *ALabelNum + 1);
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=M-1\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "A=A-1\n");
            fprintf(outputFile, "M=D\n");
            *ALabelNum += 2;
        }
        else if (strcmp(sym1, "gt") == 0)
        {
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "A=A-1\n");
            fprintf(outputFile, "D=M-D\n");
            fprintf(outputFile, "@ALabel_%d\n", *ALabelNum);
            fprintf(outputFile, "D;JGT\n");
            fprintf(outputFile, "D=0\n");
            fprintf(outputFile, "@ALabel_%d\n", *ALabelNum + 1);
            fprintf(outputFile, "0;JMP\n");
            fprintf(outputFile, "(ALabel_%d)\n", *ALabelNum);
            fprintf(outputFile, "D=-1\n");
            fprintf(outputFile, "(ALabel_%d)\n", *ALabelNum + 1);
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=M-1\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "A=A-1\n");
            fprintf(outputFile, "M=D\n");
            *ALabelNum += 2;
        }
        else if (strcmp(sym1, "lt") == 0)
        {
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "A=A-1\n");
            fprintf(outputFile, "D=M-D\n");
            fprintf(outputFile, "@ALabel_%d\n", *ALabelNum);
            fprintf(outputFile, "D;JLT\n");
            fprintf(outputFile, "D=0\n");
            fprintf(outputFile, "@ALabel_%d\n", *ALabelNum + 1);
            fprintf(outputFile, "0;JMP\n");
            fprintf(outputFile, "(ALabel_%d)\n", *ALabelNum);
            fprintf(outputFile, "D=-1\n");
            fprintf(outputFile, "(ALabel_%d)\n", *ALabelNum + 1);
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=M-1\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "A=A-1\n");
            fprintf(outputFile, "M=D\n");
            *ALabelNum += 2;
        }

        else if (strcmp(sym1, "label") == 0)
        {
            fprintf(outputFile, "(%s)\n", sym2);
        }
        else if (strcmp(sym1, "goto") == 0)
        {
            fprintf(outputFile, "@%s\n", sym2);
            fprintf(outputFile, "0;JMP\n");
        }
        else if (strcmp(sym1, "if-goto") == 0)
        {
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "AM=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@%s\n", sym2);
            fprintf(outputFile, "D;JNE\n");
        }
        else if (strcmp(sym1, "function") == 0)
        {
            if (strcmp(sym2, "Sys.init") == 0)
            {
                bootstrap(outputFile);
            }
            else
            {
                fprintf(outputFile, "(%s)\n", sym2);
                fprintf(outputFile, "@%s\n", sym3);
                fprintf(outputFile, "D=A\n");

                fprintf(outputFile, "(LOOP%s_%d)\n", fileName, *ALabelNum);

                fprintf(outputFile, "@FLabel%s_%d\n", fileName, *ALabelNum);
                fprintf(outputFile, "D;JEQ\n");

                fprintf(outputFile, "@SP\n");
                fprintf(outputFile, "A=M\n");
                fprintf(outputFile, "M=0\n");
                fprintf(outputFile, "@SP\n");
                fprintf(outputFile, "M=M+1\n");
                fprintf(outputFile, "D=D-1\n");
                fprintf(outputFile, "@LOOP%s_%d\n", fileName, *ALabelNum);
                fprintf(outputFile, "0;JMP\n");

                fprintf(outputFile, "(FLabel%s_%d)\n", fileName, *ALabelNum);

                *ALabelNum++;
            }
        }

        else if (strcmp(sym1, "call") == 0)
        {

            //push return_address
            fprintf(outputFile, "@CLabel%s_%d\n", fileName, *ALabelNum);
            fprintf(outputFile, "D=A\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "M=D\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=M+1\n");

            //push LCL
            fprintf(outputFile, "@LCL\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "M=D\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=M+1\n");

            //push ARG
            fprintf(outputFile, "@ARG\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "M=D\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=M+1\n");

            //push THIS
            fprintf(outputFile, "@THIS\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "M=D\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=M+1\n");

            //push THAT
            fprintf(outputFile, "@THAT\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "M=D\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=M+1\n");

            //ARG = SP-n-5
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@%s\n", sym3);
            fprintf(outputFile, "D=D-A\n");
            fprintf(outputFile, "@5\n");
            fprintf(outputFile, "D=D-A\n");
            fprintf(outputFile, "@ARG\n");
            fprintf(outputFile, "M=D\n");

            //LCL = SP
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@LCL\n");
            fprintf(outputFile, "M=D\n");

            //goto F
            fprintf(outputFile, "@%s\n", sym2);
            fprintf(outputFile, "0;JMP\n");

            //(return_address)
            fprintf(outputFile, "(CLabel%s_%d)\n", fileName, *ALabelNum);

            (*ALabelNum)++;
        }

        else if (strcmp(sym1, "return") == 0)
        {
            //FRAME = LCL
            //storing in R13
            fprintf(outputFile, "@LCL\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@R13\n");
            fprintf(outputFile, "M=D\n");

            //RET=*(FRAME - 5)
            //Storing in R14
            fprintf(outputFile, "@5\n");
            fprintf(outputFile, "A=D-A\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@R14\n");
            fprintf(outputFile, "M=D\n");

            //*ARG = pop()
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@ARG\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "M=D\n");

            //SP = ARG+1
            fprintf(outputFile, "@ARG\n");
            fprintf(outputFile, "D=M+1\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=D\n");

            //THAT = *(FRAME-1)
            fprintf(outputFile, "@R13\n");
            fprintf(outputFile, "A=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@THAT\n");
            fprintf(outputFile, "M=D\n");

            //THIS = *(FRAME-2)
            fprintf(outputFile, "@R13\n");
            //fprintf(outputFile,"A=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@2\n");
            fprintf(outputFile, "A=D-A\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@THIS\n");
            fprintf(outputFile, "M=D\n");

            //ARG = *(FRAME-3)
            fprintf(outputFile, "@R13\n");
            //fprintf(outputFile,"AM=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@3\n");
            fprintf(outputFile, "A=D-A\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@ARG\n");
            fprintf(outputFile, "M=D\n");

            //LCL = *(FRAME-4)
            fprintf(outputFile, "@R13\n");
            //fprintf(outputFile,"AM=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@4\n");
            fprintf(outputFile, "A=D-A\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@LCL\n");
            fprintf(outputFile, "M=D\n");

            //goto RET
            fprintf(outputFile, "@R14\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "0;JMP\n");
        }

        else
        {
            printf("ERROR : Not Type A and Type B instruction at line %d", lineNumber);
            return;
        }
    }

    else
    {

        //Memory Access
        if (strcmp(sym1, "push") == 0)
        {
            fprintf(outputFile, "@%s\n", getSegment(sym2, sym3, fileName));

            if (strcmp(sym2, "static") == 0)
            {
                fprintf(outputFile, "D=M\n");
            }
            else if (strcmp(sym2, "constant") == 0)
            {
                fprintf(outputFile, "D=A\n");
            }
            else
            {
                if ((strcmp(sym2, "temp") == 0) || (strcmp(sym2, "pointer") == 0))
                    fprintf(outputFile, "D=A\n");
                else
                    fprintf(outputFile, "D=M\n");

                fprintf(outputFile, "@%s\n", sym3);
                fprintf(outputFile, "A=A+D\n");
                fprintf(outputFile, "D=M\n");
            }

            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "M=D\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=M+1\n");
        }

        else
        {
            fprintf(outputFile, "@%s\n", getSegment(sym2, sym3, fileName));

            if (strcmp(sym2, "constant") == 0)
            {
                printf("Error : cannot pop constant at line Number : %d", lineNumber);
                exit(-1);
            }

            if ((strcmp(sym2, "temp") == 0) || (strcmp(sym2, "pointer") == 0) || (strcmp(sym2, "static") == 0))
                fprintf(outputFile, "D=A\n");
            else
                fprintf(outputFile, "D=M\n");

            if ((strcmp(sym2, "static") != 0))
            {
                fprintf(outputFile, "@%s\n", sym3);
                fprintf(outputFile, "D=D+A\n");
            }
            fprintf(outputFile, "@R13\n");
            fprintf(outputFile, "M=D\n");

            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "A=M-1\n");
            fprintf(outputFile, "D=M\n");
            fprintf(outputFile, "@R13\n");
            fprintf(outputFile, "A=M\n");
            fprintf(outputFile, "M=D\n");
            fprintf(outputFile, "@SP\n");
            fprintf(outputFile, "M=M-1\n");
        }
    }
}

void bootstrap(FILE *outputFile)
{
    fprintf(outputFile, "@256\n");
    fprintf(outputFile, "D=A\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "M=D\n");
    fprintf(outputFile, "@LCL\n");
    fprintf(outputFile, "M=D\n");
    fprintf(outputFile, "@ARG\n");
    fprintf(outputFile, "M=D\n");

    fprintf(outputFile, "@CLabel_0\n");
    fprintf(outputFile, "D=A\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "A=M\n");
    fprintf(outputFile, "M=D\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "M=M+1\n");

    //push LCL
    fprintf(outputFile, "@LCL\n");
    fprintf(outputFile, "D=M\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "A=M\n");
    fprintf(outputFile, "M=D\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "M=M+1\n");

    //push ARG
    fprintf(outputFile, "@ARG\n");
    fprintf(outputFile, "D=M\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "A=M\n");
    fprintf(outputFile, "M=D\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "M=M+1\n");

    //push THIS
    fprintf(outputFile, "@THIS\n");
    fprintf(outputFile, "D=M\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "A=M\n");
    fprintf(outputFile, "M=D\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "M=M+1\n");

    //push THAT
    fprintf(outputFile, "@THAT\n");
    fprintf(outputFile, "D=M\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "A=M\n");
    fprintf(outputFile, "M=D\n");
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "M=M+1\n");

    //ARG = SP-n-5
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "D=M\n");
    fprintf(outputFile, "@0\n");
    fprintf(outputFile, "D=D-A\n");
    fprintf(outputFile, "@5\n");
    fprintf(outputFile, "D=D-A\n");
    fprintf(outputFile, "@ARG\n");
    fprintf(outputFile, "M=D\n");

    //LCL = SP
    fprintf(outputFile, "@SP\n");
    fprintf(outputFile, "D=M\n");
    fprintf(outputFile, "@LCL\n");
    fprintf(outputFile, "M=D\n");

    //goto F
    fprintf(outputFile, "@Sys.init\n");
    fprintf(outputFile, "0;JMP\n");

    //(return_address)
    fprintf(outputFile, "(CLabel_0)\n");
}

int main(int argc, char **argv)
{
    FILE *inputFile;
    FILE *outputFile;

    char *fileName = argv[1];

    inputFile = fopen(fileName, "r"); //initializeP(argv[1]);
    outputFile = initializeO(argv[1]);

    if (inputFile == NULL)
    {
        printf("Input File not found\n");
        exit(-1);
    }

    int i, j;
    int ALabelNum = 0;
    int lineNumber = 0;
    char nextCommand[MAXCHARPERLINE];
    char parsedCommand[MAXCHARPERLINE];
    char sym1[MAXCHARPERLINE], sym2[MAXCHARPERLINE], sym3[MAXCHARPERLINE], sym4[MAXCHARPERLINE];
    //char *sym4 ;
    int tempC = 0;
    // 1 denotes /**/ loop
    // 0 means no loop

    int xx = 0;
    while (fileName[xx] != '.')
    {
        sym4[xx] = fileName[xx];
        xx++;
    }
    sym4[xx] = '\0';

    while (fgets(nextCommand, MAXCHARPERLINE, inputFile) != NULL)
    {

        lineNumber++;
        //char parsedCommand[MAXCHARPERLINE];
        //char sym1[MAXCHARPERLINE],sym2[MAXCHARPERLINE],sym3[MAXCHARPERLINE],sym4[MAXCHARPERLINE];

        parsedCommand[0] = '\0';
        sym1[0] = '\0';
        sym2[0] = '\0';
        sym3[0] = '\0';
        //sym4[0]='\0';

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
                break; //parsedCommand[j++]=nextCommand[i];
            i++;
        }
        if (tempC != 0)
            continue;

        while (nextCommand[i] != '\n')
        {
            parsedCommand[j++] = nextCommand[i++];
        }
        parsedCommand[j] = '\n';
        parsedCommand[j + 1] = '\0';
        if (parsedCommand[0] == '\n')
            continue;
        i = 0;
        while ((parsedCommand[i] != ' ') && (parsedCommand[i] != '\n'))
        {
            sym1[i] = parsedCommand[i];
            i++;
        }
        sym1[i] = '\0';
        fprintf(outputFile, "// sym1 : %s\n", sym1);
        while (parsedCommand[i] == ' ')
            i++;

        if (parsedCommand[i] != '\n')
        {
            j = 0;
            while ((parsedCommand[i] != ' ') && (parsedCommand[i] != '\n'))
                sym2[j++] = parsedCommand[i++];
            sym2[j] = '\0';

            while (parsedCommand[i] == ' ')
                i++;

            if (parsedCommand[i] != '\n')
            {
                j = 0;
                while ((parsedCommand[i] != ' ') && (parsedCommand[i] != '\n'))
                    sym3[j++] = parsedCommand[i++];

                sym3[j] = '\0';
            }
        }
        fprintf(outputFile, "// %s", parsedCommand);
        if (sym1[0] != '\0')
        {
            fprintf(outputFile, "// Symbol1 present at line : %d\n", lineNumber);
            generateCode(outputFile, sym1, sym2, sym3, &ALabelNum, lineNumber, sym4);
        }
    }

    fprintf(outputFile, "(ENDD_%s)\n");
    fprintf(outputFile, "@ENDD\n");
    fprintf(outputFile, "0;JMP\n");

    fclose(inputFile);
    fclose(outputFile);
}
