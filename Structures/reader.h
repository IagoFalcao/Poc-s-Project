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

void clear_List(archieveList *list);
void print_List(archieveList *list);

archieveList readArchieveList(const char *input_name);
void readContent(archieveList *archieveList);

#endif

