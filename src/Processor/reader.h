#ifndef READER_H
#define READER_H

typedef struct{
    char *content;
    char *name;
}archieve;

typedef struct{
    int qty;
    archieve* arch;
}archieveList;

void clear_List(archieveList *l);
void print_List(archieveList *l);

#endif

