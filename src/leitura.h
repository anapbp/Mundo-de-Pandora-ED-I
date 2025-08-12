#ifndef _LE_ARQUIVOS__
#define _LE_ARQUIVOS__

#include <stdio.h>

typedef void *ArqCmds;

/*Abre arquivo*/
FILE* abreArquivoCmd(char *fn);

/*Lê os parâmetros do arquivo*/
void getParametroI(char** ret, char *buf, int i, char *paramI, int paramILen);

/*Continua lendo restante da linha, independente de ter " " ou não.
(Exemplo: "aaa bbb ccc oi tudo bem", nesse caso o parametro 4 seria "oi tudo bem")*/
void getParametroDepoisI(char **ret, char *buf, int i, char *paramI, int paramILen);

/*Fecha arquivo*/
void fechaArquivoCmd(ArqCmds ac);

#endif
