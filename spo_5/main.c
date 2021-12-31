#include "parsing_str.h"
#include "marker.h"
#include "hash.h"
char* direct[] = {"BEGIN", "END", "DB", "DW", "RB", "RW"};
char* commands[] = {"LDX", "LDA", "ADD", "STA", "HLT"};

int check_num(const char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == 'h')
            continue;
        else return -1;
    return 1;
}

char* make_address(int mc, int adr)
{
    char* res = (char*)malloc(6);
    sprintf(res, "%2x%4x", mc, adr);
    for(int i = 0; i < 6; i++) if(res[i] == ' ') res[i] = '0';

    return res;
}

void first_check(struct Str* pars, int pars_len, struct marker_table *table, int len_m, int begin_address, ppHash list)
{
    int j = 0;
    for(int i = 0; i < pars_len; i++)
    {
        if (pars[i].marker[0] != '\0')
        {
            if (find_address(table, len_m, pars[i].marker) != -1)
                exit(0);

            strcpy(table[j].mark, pars[i].marker);
            table[j].address = begin_address + (i-1) * STEP;
            j++;
        }
    }

    for(int i = 0; i < pars_len; i++)
    {
        printf("%s %x\n", table[i].mark, table[i].address);
        if (find(list, pars[i].operator) == NULL)
            exit(0);

        if(pars[i].operand[0] != '\0')
            if (check_num(pars[i].operand) == -1)
            {

                int fa = find_address(table, len_m, pars[i].operand);
                if (fa != -1)
                    table[fa].sign = 1;
                else
                    exit(0);
            }
    }
}
void create_table(char* argv1, char* argv2, struct Str* pars, int pars_len, struct marker_table* table, int m_len, ppHash list, int begin)
{
    FILE* in = fopen(argv1, "r");
    FILE* out = fopen(argv2, "w");

    fprintf(out, "%3s %6s %6s %10s\n", "num", "adr", "code", "str");
    for(int i = 0; i < pars_len; i++)
    {
        char str[MAXLEN];
        fgets((char *) str, MAXLEN, in);
        pHash hash = find(list, pars[i].operator);
        int s = find_address(table, m_len, pars[i].operand);
        if(i>0)
            fprintf(out, "%3i %6x %s %s", i+1, begin + (i-1) * STEP ,make_address(hash->mc, table[s].address), str);
        else
            fprintf(out, "%3i %6x %s %s", i+1, 0, make_address(hash->mc, table[s].address), str);
    }
    fclose(out);
}
void create_obj_file(struct Str* pars, int pars_len, struct marker_table* table, int m_len, ppHash list, int begin)
{
    pHash hash = find(list, pars[0].operator);
    int s = find_address(table, m_len, pars[0].operand);
    printf("H_%s_0000%x\nT_", make_address(hash->mc, table[s].address), (pars_len-2) * STEP);
    for(int i = 1; i < pars_len - 1; i++)
    {
        hash = find(list, pars[i].operator);
        s = find_address(table, m_len, pars[i].operand);
        printf("%s ", make_address(hash->mc, table[s].address));
    }
    hash = find(list, pars[pars_len-1].operator);
    s = find_address(table, m_len, pars[pars_len-1].operand);
    printf("\nE_%s", make_address(hash->mc, table[s].address));
}

int main(int argc, char* argv[])
{
    //====================================================pars str====================================================//
    int len_asm = file_line(argv[1]);
    struct Str pars[len_asm];
    clear_str(pars, len_asm);
    filling_str(argv[1], pars);
    //==================================================init hash_table===============================================//
    pHash list[M];
    clear_hash(list, M);

    char *temp = direct[0];
    for(int i = 0; temp != NULL; i++, temp = direct[i])
        add(list, temp, 0);

    temp = commands[0];
    for(int i = 0; temp != NULL; i++, temp = commands[i])
        add(list, temp, rand() % MAXLEN);

    //====================================================first pass==================================================//
    int len_m = len_mark(pars, len_asm);
    struct marker_table table[len_m];
    clear_mark(table, len_m);

    int begin_address = address(pars);

    first_check(pars, len_asm, table, len_m, begin_address, list);
    check_table(table, len_m);

    //===================================================second pass==================================================//
    create_table(argv[1], argv[2], pars, len_asm, table, len_m, list, begin_address);
    create_obj_file(pars, len_asm, table, len_m, list, begin_address);
    return 0;
}
