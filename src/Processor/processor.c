#include "processor.h"

void readInputs(char *inputPath){

    FILE *inputs;
    int emptyFile = 1;
    if((inputs=fopen(inputPath, "rb"))==NULL) {
        printf("* error while opening file -%s- ..\n",inputPath);
        fclose (inputs);
        exit(-1);
}else{
    printf("Test");
    int i = 0;
    char c[500] = "";
    for(i = 0;fgetc(inputs);i++){
        
        fprintf(inputs,"%s",c);
        emptyFile = 0;

    }
}
fclose(inputs);
    

}