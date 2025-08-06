#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"


void clear_List(archieveList *list){
    if(list == NULL){
        return;
    }

    for(int i = 0; i< list->qty; i++){
        free(list->arch[i].content);
        free(list->arch[i].name);
    }
    free(list->arch);   
    free(list);
}




void print_List(archieveList *l);

archieveList* readArchieveList(const char *input_name){
    FILE *fptr;
    fptr = fopen(input_name, "r");
    if(!fptr) {
        printf("error");
        return NULL;
    }

    archieveList* list = malloc(sizeof(archieveList));
    if(!list) {
        printf("error"); 
        fclose(fptr); 
        return NULL;
    }

    if(fscanf(fptr, "%d\n", &list->qty) != 1) {
        printf("error reading quantity");
        free(list);
        fclose(fptr);
        return NULL;
    }

    list->arch = malloc(list->qty * sizeof(archieve));
    if(!list->arch) {
        printf("error");
        free(list);
        fclose(fptr);
        return NULL;
    }
}

void readContent(archieveList *archieveList){

}
