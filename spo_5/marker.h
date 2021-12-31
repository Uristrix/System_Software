#ifndef SPO_5_MARKER_H
#define SPO_5_MARKER_H
#define STEP 3
#include "hash.h"
struct marker_table
{
    int sign;
    int address;
    char mark[MAXLEN/4];

};
void clear_mark(struct marker_table *table, int i)
{
    for(int j = 0; j < i; j++)
    {
        table[j].sign = 0;
        table[j].address = 0;
        memset(table[j].mark, 0, strlen(table[j].mark));
    }
}

void check_table(struct marker_table *mark, int len_m)
{
    for(int i = 0; i < len_m; i++)
    {
        if(mark[i].sign == 0)
            exit(0);
    }
}
int  find_address(struct marker_table* table, int len_m, char* mark)
{
    for(int i = 0; i < len_m; i++)
    {
        if(strcmp(table[i].mark, mark) == 0)
            return i;
    }
    return -1;
}
#endif //SPO_5_MARKER_H
