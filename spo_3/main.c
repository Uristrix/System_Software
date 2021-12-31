#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 256

const char* dir[] = {"BEGIN", "DIR", "DB", "DW", "RB", "RW"};

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

void ParseStr(char *str, char *marker, char *operator, char *operand, char *comment)
{
    if(strchr(str, '-') == str)
    {
        char temp[strlen(str)];
        memset(temp, 0, strlen(temp));
        str++;

        for(int i = 0; *str != ' ' && *str != '\t' && *str != '\0' ; str++, i++)
            temp[i] = *str;

        strcpy(marker, correction(temp));
    }

    if(strchr(str, ';') != NULL)
    {
        strcpy(comment, correction(strchr(str, ';') + 1));
        memset(strchr(str, ';'), 0, strlen(strchr(str, ';')));
    }

    for(int i = 0;  i < 6; i++)
    {
        if(strstr(str, dir[i]) != NULL)
        {
            strcpy(operator, dir[i]);
            str += strlen(dir[i]) + 2;
            break;
        }
    }
    strcpy(operand, correction(str));
}
int main(int argc, char* argv[])
{
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");

    char str[MAXLEN];
    char temp[4][MAXLEN / 4];

    while (fgets(str, MAXLEN, in) != NULL)
    {
        for(int i = 0; i < 4; i++)
            memset(temp[i], 0, strlen(temp[i])); //очистка массивов

        ParseStr(str, temp[0], temp[1], temp[2], temp[3]);
        fprintf(out,"Marker:%8s Operator:%8s Operand:%8s Comment:%8s\n", temp[0], temp[1], temp[2], temp[3]);
        printf("Marker:%8s Operator:%8s Operand:%8s Comment:%8s\n", temp[0], temp[1], temp[2], temp[3]);
    }

    fclose(in);
    fclose(out);

    return 0;
}
