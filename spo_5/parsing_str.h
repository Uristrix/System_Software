#ifndef SPO_5_PARSING_STR_H
#define SPO_5_PARSING_STR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 256

const char* dir[] = {"BEGIN", "END", "DB", "DW", "RB", "RW", "LDX", "LDA", "ADD", "STA", "HLT"};

struct Str
{
    char marker[MAXLEN/4];
    char operator[MAXLEN/4];
    char operand[MAXLEN/4];
    char comment[MAXLEN/4];
};
int file_line(char* argv)
{
    FILE* in = fopen(argv, "r");

    int i = 1;
    while (!feof(in))
        if(fgetc(in) == '\n')
            i++;

    fclose(in);
    return i;
}

void clear_str(struct Str *res, int i)
{
    for(int j = 0; j < i; j++)
    {
        memset(res[j].marker, 0, strlen(res[j].marker));
        memset(res[j].operand, 0, strlen(res[j].operand));
        memset(res[j].operator, 0, strlen(res[j].operator));
        memset(res[j].comment, 0, strlen(res[j].comment));
    }
}

char* correction(char* str)
{
    char* temp = malloc(strlen(str));
    memset(temp, 0, strlen(temp));

    for(int i = 0; *str != '\n' && *str != '\0'; str++, i++)
    {
        if (*str == ' ' || *str == '\t')
            continue;
        temp[i] = *str;
    }
    return temp;
}

void ParseStr(char *str, struct Str *res, int s)
{
    if(strchr(str, '-') == str)
    {
        char temp[strlen(str)];
        memset(temp, 0, strlen(temp));
        str++;

        for(int i = 0; *str != ' ' && *str != '\t' && *str != '\0' ; str++, i++)
            temp[i] = *str;
        strcpy(res[s].marker, correction(temp));
    }
    while(*str ==' ' || *str == '\t') str++;
    if(strchr(str, ';') != NULL)
    {
        strcpy(res[s].comment, correction(strchr(str, ';') + 1));
        memset(strchr(str, ';'), 0, strlen(strchr(str, ';')));
    }
    while(*str == ' ' || *str == '\t') str++;
    for(int i = 0;  i < 11; i++)
    {
        if (strstr(str, dir[i]) != NULL)
        {
            strcpy(res[s].operator, dir[i]);
            str += strlen(dir[i]) + 1;
            break;
        }
    }
    while(*str == ' ' || *str == '\t')str++;
    strcpy(res[s].operand, correction(str));
}

void filling_str(char* argv, struct Str *res)
{
    FILE* in = fopen(argv, "r");
    char str[MAXLEN];

    int i = 0;
    while (fgets(str, MAXLEN, in) != NULL)
    {
        ParseStr(str, res, i);
//        printf("Marker:%8s Operator:%8s Operand:%8s Comment:%8s\n",
  //             res[i].marker, res[i].operator, res[i].operand, res[i].comment);
        i++;
    }
    fclose(in);
}

int len_mark(struct Str *pars, int s)
{
    int j = 0;
    for(int i = 0; i < s; i++)
    {
        if(pars[i].marker[0] != '\0')
            j++;
    }
    return j;
}

int address(struct Str *res)
{
    if (strcmp(res[0].operator, dir[0]) == 0)
    {
        if(res[0].operand[0] == '\0')
            return 0;
        else
            return strtol(res[0].operand, NULL, 16);
    }
    else
        exit(0);
}
#endif //SPO_5_PARSING_STR_H
