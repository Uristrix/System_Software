#ifndef SPO_5_HASH_H
#define SPO_5_HASH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M 29
#define A 0.6180339887

struct Hash;
typedef struct Hash* pHash;
typedef struct Hash** ppHash;

struct Hash
{
    int mc;
    char* elem;
    pHash next;
};

int HashMulti(char* key)
{
    unsigned int K = 0, w = strlen(key);
    for(int i = 0; i < w; i++)
        K ^= (unsigned int) key[i];

    return (int)(M * fmod(A / w * K, 1));
}

pHash find(ppHash list, char* elem)
{
    for(pHash hash = list[HashMulti(elem)]; hash != NULL; hash = hash -> next)
        if(strcmp(elem, hash -> elem) == 0)
            return hash;

    return NULL;
}

void add(ppHash list, char* elem, int mc)
{
    int k = HashMulti(elem);
    pHash hash = list[k];

    if(hash == NULL)
    {
        list[k] = (pHash)malloc(sizeof(struct Hash));
        list[k] -> elem = (char*)malloc(strlen(elem));
        list[k] -> next = NULL;
        list[k] -> mc = mc;
        strcpy(list[k] -> elem, elem);
    }
    else
    {
        while (hash -> next != NULL) hash = hash -> next;
        hash = hash -> next = (pHash)malloc(sizeof(struct Hash));
        hash -> elem = (char*)malloc(strlen(elem));
        hash -> next = NULL;
        hash -> mc = mc;
        strcpy(hash -> elem, elem);
    }
}
void clear_hash(ppHash list, int s)
{
    for(int i = 0; i < s; i++)
        list[i] = NULL;
}
void PrintToFile(ppHash list, FILE* out)
{
    for(int i = 0; i < M; i++)
    {
        fprintf(out,"%2i: ", i);
        for(pHash hash = list[i]; hash != NULL; hash = hash -> next)
            fprintf(out, "%10s -> ", hash -> elem);

        fprintf(out, "%10s\n", "NONE");
    }
}

void Print(ppHash list)
{
    for(int i = 0; i < M; i++)
    {
        printf("%2i: ", i);
        for(pHash hash = list[i]; hash != NULL; hash = hash -> next)
            printf( "%10s -> ", hash -> elem);

        printf( "%10s\n", "NONE");
    }
}

void Print_mc(ppHash list)
{
    for(int i = 0; i < M; i++)
    {
        printf("%2i: ", i);
        for(pHash hash = list[i]; hash != NULL; hash = hash -> next)
            printf( "%10i -> ", hash -> mc);

        printf( "%10s\n", "NONE");
    }
}
#endif //SPO_5_HASH_H
