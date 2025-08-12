#ifndef PATH__
#define PATH__

#include "path.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Analisa se é -e -f -o ou -q e atribui seus valores nas variaveis correspondentes.*/
void AnalisaIdentificador(int argc, char **entrada, char **saida, char **arqqry, char **arqgeo, char *argv[]){
    
    *entrada = NULL;
    *saida = NULL;
    *arqqry = NULL;
    *arqgeo = NULL;

    for (int i = 0; i < argc; i++) {
    
        if (strcmp(argv[i], "-e") == 0){

            *entrada = argv[i+1];
            i++;
            
        } else if (strcmp(argv[i], "-o") == 0){
            
            *saida = argv[i+1];
            i++;
         
         
        } else if (strcmp(argv[i], "-f") == 0){

            *arqgeo = argv[i+1];
            i++;
        
            
        } else if (strcmp(argv[i], "-q") == 0){

            *arqqry = argv[i+1];
            i++;
        
        }
    }
}

/*Pega somente o nome do seu arquivo. Exemplo: blabla/teste.geo ==> teste*/
void PegarNome(char *arquivo, char **nomeArq){

    char arq[100], nome[100];
    strcpy(arq, arquivo);

    int len = strlen(arq) -1;
    int aux, aux2;
    int inicio =0;
    aux2 = -1;

    while(len>=0) {

        if(arq[len] == '.'){
            
            aux = len;

        }

        if(arq[len] == '/'){

            aux2 = len;
            break;
        }

        len--;
    }

    if(aux2 == -1){
        aux2 = 0;
    } else {
        aux2 = aux2+1;
    }

        for(;aux2<aux; aux2++){

            nome[inicio] = arq[aux2];
            inicio++;
        }

    nome[inicio] = '\0';
    strcpy(*nomeArq, nome);
} 

/*Junta o caminho com o arquivo e adiciona / se necessário. */
void NormalizaPath(char *arquivo, char *nomeArq, char **Normalizado){

    int len;

    if(arquivo[strlen(arquivo) - 1] == '/' || arquivo[strlen(arquivo) - 1] == '\\'){

        if(nomeArq[0]!='.'){

            sprintf(*Normalizado,"%s%s", arquivo, nomeArq);

        } else {

            len = strlen(nomeArq);

            for (int i = 0; i < len; i++) {
                nomeArq[i] = nomeArq[i + 2];
            }

             nomeArq[len - 2] = '\0';

             sprintf(*Normalizado,"%s%s", arquivo, nomeArq);

        }

    } else {

        if(nomeArq[0]!='.'){

            sprintf(*Normalizado,"%s/%s", arquivo, nomeArq);

        } else {

            len = strlen(nomeArq);

            for (int i = 0; i < len; i++) {
                nomeArq[i] = nomeArq[i + 2];
            }

             nomeArq[len - 2] = '\0';

             sprintf(*Normalizado,"%s/%s", arquivo, nomeArq);

        }
    }
}


#endif