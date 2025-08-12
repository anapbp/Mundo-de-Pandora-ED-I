#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "leitura.h"

/* Abre arquivo*/
FILE* abreArquivoCmd(char *fn){
    FILE *arquivo = fopen(fn, "r");
    
    if(arquivo == NULL){
        printf("nao foi possivel abrir arquivo %s\n", fn);
        return NULL;
    } else {
        printf("abriu arquivo %s\n", fn);
        return arquivo;
    }
}


/* Lê os parâmetros do arquivo*/
void getParametroI(char** ret, char *buf, int i, char *paramI, int paramILen){
    paramI = malloc(sizeof(char) * paramILen);
    int s = 0;
    for (int n = 0; n < i - 1; n++) {

        while(buf[s] == ' ') s++;

        while(buf[s] != '\n' && buf[s] != ' ' && buf[s] != '\0') {
            s++;
        }
    }

    while(buf[s] == ' ') s++;

    int n = 0;
    while(buf[s] != '\n' && buf[s] != ' ' && buf[s] != '\0' && buf[s] != '?' && buf[s] != '\r') {
        paramI[n++] = buf[s];
        s++;
    }
    
    paramI[n] = '\0';
    *ret = paramI;
}
    
/*Continua lendo restante da linha, independente de ter " " ou não.
(Exemplo: "aaa bbb ccc oi tudo bem", nesse caso o parametro 4 seria "oi tudo bem")*/
void getParametroDepoisI(char **ret, char *buf, int i, char *paramI, int paramILen){
    paramI = malloc(sizeof(char) * paramILen);
    int s = 0;
    for (int n = 0; n < i - 1; n++) {

        while(buf[s] == ' ') s++;

        while(buf[s] != '\n' && buf[s] != ' ' && buf[s] != '\0') {
            s++;
        }
    }

    while(buf[s] == ' ') s++;

    int n = 0;
    while(buf[s] != '\n' && buf[s] != '\0' && buf[s] != '\r') {
        paramI[n++] = buf[s];
        s++;
    }
    
    paramI[n] = '\0';
    *ret = paramI;
}

/* Fecha arquivo. */
void fechaArquivoCmd(ArqCmds ac){
    fclose(ac);
}
