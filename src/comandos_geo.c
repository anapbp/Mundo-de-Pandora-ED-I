#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "leitura.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "circulo.h"
#include "lista.h"
#include "txt.h"
#include "svg.h"
#include "fila.h"
#include "foto.h"
#include "comandos_geo.h" 
#include "comandos_qry.h" 
            
/* Armazena um retangulo em sua respectiva Lista. */
void ArmazenaRetangulo(Lista Retangulos, char **comando, char *linha){

    char aux[50], corb[50], corp[50];
    int i;
    double x, y, w, h;

    getParametroI(comando, linha, 2, aux, 50);
    i = atoi(*comando);
    getParametroI(comando, linha, 3, aux, 50);
    x =strtod(*comando, NULL);
    getParametroI(comando, linha, 4, aux, 50);
    y = strtod(*comando, NULL);
    getParametroI(comando, linha, 5, aux, 50);
    w = strtod(*comando, NULL);
    getParametroI(comando, linha, 6, aux, 50);
    h = strtod(*comando, NULL);
    getParametroI(comando, linha, 7, aux, 50);
    strcpy(corb, *comando);
    getParametroI(comando, linha, 8, aux, 50);
    strcpy(corp, *comando);

    Retangulo* newRet = novoRetangulo(i, x, y, w, h, corb, corp);
    insertLst(Retangulos, (Retangulo*) newRet);
}      

/* Armazena um circulo em sua respectiva Lista. */
void ArmazenaCirculo(Lista Circulos, char **comando, char *linha){

    int i;
    double x, y, r;
    char corb[50], corp[50], aux[50];

    getParametroI(comando, linha, 2, aux, 50);
    i = atoi(*comando);
    getParametroI(comando, linha, 3, aux, 50);
    x = strtod(*comando, NULL);
    getParametroI(comando, linha, 4, aux, 50);
    y = strtod(*comando, NULL);
    getParametroI(comando, linha, 5, aux, 50);
    r = strtod(*comando, NULL);
    getParametroI(comando, linha, 6, corb, 50);
    strcpy(corb, *comando);
    getParametroI(comando, linha, 7, corp, 50);
    strcpy(corp, *comando);

    Circulo* newCirc = novoCirculo(i, x, y, r, corb, corp);
    insertLst(Circulos, (Circulo*) newCirc);
}

/* Armazena uma linha em sua respectiva Lista. */
void ArmazenaLinha(Lista Linhas, char **comando, char *linha){

    int i;
    double x1, y1, x2, y2;
    char cor[50], aux[50];

    getParametroI(comando, linha, 2, aux, 50);
    i = atoi(*comando);
    getParametroI(comando, linha, 3, aux, 50);
    x1 = strtod(*comando, NULL);
    getParametroI(comando, linha, 4, aux, 50);
    y1 = strtod(*comando, NULL);
    getParametroI(comando, linha, 5, aux, 50);
    x2 = strtod(*comando, NULL);
    getParametroI(comando, linha, 6, aux, 50);
    y2 = strtod(*comando, NULL);
    getParametroI(comando, linha, 7, aux, 50);
    strcpy(cor, *comando);

    Linha* newLine = novaLinha(i, x1, y1, x2, y2, cor);
    insertLst(Linhas, (Linha*) newLine);
}

/* Armazena um texto em sua respectiva Lista*/
void ArmazenaTexto(Lista Textos, char **comando, char *linha, char fFamily[], char fWeight[], char fSize[]){

    int i;
    double x1, y1;
    char corb[50], corp[50], a[50], txto[50], aux[50];

    getParametroI(comando, linha, 2, aux, 50);
    i = atoi(*comando);
    getParametroI(comando, linha, 3, aux, 50);
    x1 = strtod(*comando, NULL);
    getParametroI(comando, linha, 4, aux, 50);
    y1 = strtod(*comando, NULL);
    getParametroI(comando, linha, 5, aux, 50);
    strcpy(corb, *comando);
    getParametroI(comando, linha, 6, aux, 50);
    strcpy(corp, *comando);
    getParametroI(comando, linha, 7, aux, 50);
    strcpy(a, *comando);
    getParametroDepoisI(comando, linha, 8, aux, 50);
    strcpy(txto, *comando);

    //Analisando qual sua ancora
    if(strcmp((a), "i") == 0 ){
       
        strcpy(a, "start" );

    } else if(strcmp((a), "m") == 0 ){
        
        strcpy(a, "middle" );

    } else if(strcmp((a), "f") == 0 ){
        
        strcpy(a, "end" );
    }

    Texto* newTxt = novoTexto(i, x1, y1, corb, corp, a, txto, fFamily, fWeight, fSize);
    insertLst(Textos, (Texto*) newTxt);

    //Vendo se o Texto corresponde a um Caca ou a um Balao
    if(strcmp((txto), "v_O_v") == 0){
        
        createBalao((Texto*)newTxt, 0, 0, 0); //Inicializa balao com atributos raio, profundiade e altura iguais a zero.
    
    } else if(strcmp((txto), "|-T-|") == 0){
        
        AlteraTipo((Texto*)newTxt, 0);
       
    } 
}