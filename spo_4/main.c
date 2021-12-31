#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M 29
#define A 0.6180339887

char* correction(char* str)
{
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] == '\n') str[i] ='\0';
    return str;
}

struct Hash;
typedef struct Hash* pHash;
typedef struct Hash** ppHash;

struct Hash
{
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

void add(ppHash list, char* elem)
{
    int k = HashMulti(elem);
    pHash hash = list[k];

    if(hash == NULL)
    {
        list[k] = (pHash)malloc(sizeof(struct Hash));
        list[k] -> elem = (char*)malloc(strlen(elem));
        list[k] -> next = NULL;
        strcpy(list[k] -> elem, elem);
    }
    else
    {
        while (hash -> next != NULL) hash = hash -> next;
        hash = hash -> next = (pHash)malloc(sizeof(struct Hash));
        hash -> elem = (char*)malloc(strlen(elem));
        hash -> next = NULL;
        strcpy(hash -> elem, elem);
    }
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

int main(int argc, char* argv[])
{
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");

    char temp[M];

    pHash list[M];
    for(int i = 0; i < M; i++)
        list[i] = NULL;

    while (fgets(temp, M, in) != NULL)
        add(list, correction(temp));

    PrintToFile(list, out);

    fclose(in);
    fclose(out);

    if(find(list, "sub") != NULL) printf("Found!!!");
    else printf("not Found!!!");

    return 0;
}