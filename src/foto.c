#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "foto.h"
#include "lista.h"
#include "texto.h"
#include "retangulo.h"
#include "linha.h"
#include "circulo.h"

struct Ft{
    int id;
    Lista Txt;
    Lista Ret;
    Lista Lin;
    Lista Circ;
    double xme, xma, ymeTDS, ymaTDS, raio, prof, alt;
};

typedef struct Ft FotoImpl;

/* Cria uma foto com raio, profundiade e altura (atributos da camera na hora que fotografou). */
Foto createFoto(double r, double p, double a){
    FotoImpl *newFt = (FotoImpl *) malloc (sizeof(FotoImpl));
    newFt->Txt = createLst(-1);
    newFt->Ret = createLst(-1);
    newFt->Lin = createLst(-1);
    newFt->Circ = createLst(-1);
    newFt->raio = r;
    newFt->prof = p;
    newFt->alt = a;
    return newFt;
}

/* Pega Lista dos Retangulos contidos na foto. Retorna NULL em caso de erro.*/
Lista GetListRet(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->Ret;
    } else {
        return NULL;
    }
}

/* Pega Lista das Linhas contidas na foto. Retorna NULL em caso de erro.*/
Lista GetListLin(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->Lin;
    } else {
        return NULL;
    }
}

/* Pega Lista dos Textos contidos na foto. Retorna NULL em caso de erro.*/
Lista GetListTxt(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->Txt;
    } else {
        return NULL;
    }
}

/* Pega Lista dos Circulos contidos na foto. Retorna NULL em caso de erro.*/
Lista GetListCirc(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->Circ;
    } else {
        return NULL;
    }
}

/* Pega informacao do y menor da foto. Retorna -1 em caso de erro.*/
double GetYme(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->ymeTDS;
    } else {
        return -1;
    }
}

/* Pega informacao do y maior da foto. Retorna -1 em caso de erro.*/
double GetYma(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->ymaTDS;
    } else {
        return -1;
    }
}

/* Pega informacao do x menor da foto. Retorna -1 em caso de erro.*/
double GetXme(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->xme;
    } else {
        return -1;
    }
}

/* Pega informacao do x maior da foto. Retorna -1 em caso de erro.*/
double GetXma(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->xma;
    } else {
        return -1;
    }
}

/* Pega informacao do raio da foto. Retorna -1 em caso de erro.*/
double GetRaioFt(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->raio;
    } else {
        return -1;
    }
}

/* Pega informacao da profundidade da foto. Retorna -1 em caso de erro.*/
double GetProfFt(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->prof;
    } else {
        return -1;
    }
}

/* Pega informacao da altura da foto. Retorna -1 em caso de erro.*/
double GetAltFt(Foto f){
    FotoImpl *ft = (FotoImpl *) f;
    if(ft!=NULL){
        return ft->alt;
    } else {
        return -1;
    }
}

/* Altera o x menor da foto. */
void alterarXme(Foto f, double novo_xme){
    FotoImpl* ft = (FotoImpl*) f;
    if(ft!=NULL){
        ft->xme = novo_xme;
    }
}

/* Altera o x maior da foto. */
void alterarXma(Foto f, double novo_xma){
    FotoImpl* ft = (FotoImpl*) f;
    if(ft!=NULL){
        ft->xma = novo_xma;
    }
}

/* Procura os Textos que foram fotografados. */
void ProcuraTxt(Lista Txt, Lista t, double x, double y, double r, double a, double p){

    Iterador itT = createIterador(t, false);
    Item info;
    double dx, dy;
    
    while(!isIteratorEmpty(t, itT)) {
        info = getIteratorNext(t, itT);
        if(info == NULL){
            break;
        } else {
            if(ParamXT(info)>x-r && ParamXT(info)<x+r && ParamYT(info)>y+p && ParamYT(info)<y+p+a){ 
                //Encontrou Texto.
                Texto novo = CopiarT(info);
                dx = ParamXT(info) - (x-r);
                dy = ParamYT(info) - y - p;
                AlteraDxT(novo, dx);
                AlteraDyT(novo, dy);
                insertLst(Txt, novo); //Inserindo Texto na lista de Textos fotografados
            }
        }
    }
    killIterator(t, itT);
}

/* Analisa se duas linhas se encontram. Retorna verdadeiro se elas se colidem.
Fonte de estudos: https://www.jeffreythompson.org/collision-detection/line-rect.php.
Usado para estudo de colisao de Linhas e Retangulos, entrando também estudos sobre colisoes
de Linhas com Linhas. Funções ColideLinha e ColideLinhaRetangulo foram baseadas neste site 
para desenvolvimento.
*/
bool ColideLinha(double X1PontoA, double Y1PontoA, double X2PontoA, double Y2PontoA, double X1PontoB, double Y1PontoB, double X2PontoB, double Y2PontoB) {

    //Calcula a direção das linhas
    double aux = ((X2PontoB - X1PontoB) * (Y1PontoA - Y1PontoB) - (Y2PontoB - Y1PontoB) * (X1PontoA - X1PontoB)) / ((Y2PontoB - Y1PontoB) * (X2PontoA - X1PontoA) - (X2PontoB - X1PontoB) * (Y2PontoA - Y1PontoA));
    
    double aux1 = ((X2PontoA - X1PontoA) * (Y1PontoA - Y1PontoB) - (Y2PontoA - Y1PontoA) * (X1PontoA - X1PontoB)) / ((Y2PontoB - Y1PontoB) * (X2PontoA - X1PontoA) - (X2PontoB - X1PontoB) * (Y2PontoA - Y1PontoA));

    //Se aux e aux1 estao entre (0) e (1), entao as linhas estao se colidindo.
    if (aux >= 0 && aux <= 1 && aux1 >= 0 && aux1 <= 1) {

        return true; //Como se colidem, retorna verdadeiro.
    }

    return false; //Caso nao entre no laço, entao nao se colidindo, retornando falso
}

/* Analisa se ha Linha dentro do Retangulo. Retorna verdadeiro se tiver.
Fonte de estudos: https://www.jeffreythompson.org/collision-detection/line-rect.php.
Usado para estudo de colisao de Linhas e Retangulos, entrando também estudos sobre colisoes
de Linhas com Linhas. Funções ColideLinha e ColideLinhaRetangulo foram baseadas neste site 
para desenvolvimento.
*/
bool ColideLinhaRetangulo(double X1Linha, double Y1Linha, double X2Linha, double Y2Linha, double XRet, double YRet, double LargRet, double AltRet) {

    //Analisando se há colisoes em alguma borda do Retangulo, ou se algum ponto da linha se encontra dentro dele
    //Analisando borda esquerda;
    bool esquerda = ColideLinha(X1Linha, Y1Linha, X2Linha, Y2Linha, XRet, YRet, XRet, YRet + AltRet);
    //Analisando borda direita;
    bool direita = ColideLinha(X1Linha, Y1Linha, X2Linha, Y2Linha, XRet + LargRet, YRet, XRet + LargRet, YRet + AltRet);
    //Analisando borda de cima;
    bool cima = ColideLinha(X1Linha, Y1Linha, X2Linha, Y2Linha, XRet, YRet, XRet + LargRet, YRet);
    //Analisando borda de baixo;
    bool baixo = ColideLinha(X1Linha, Y1Linha, X2Linha, Y2Linha, XRet, YRet + AltRet, XRet + LargRet, YRet + AltRet);
    //Analisando se esta dentro, nao nas bordas;
    bool dentro = X1Linha > XRet && X1Linha < XRet + LargRet && Y1Linha > YRet && Y1Linha < YRet + AltRet;
    //Segundo caso de caso esteja dentro e nao nas bordas
    bool dentro1 = X2Linha > XRet && X2Linha <XRet + LargRet && Y2Linha > YRet && Y2Linha < YRet + AltRet;

    //Se algum de cima for verdade, então a linha esta dentro do retangulo.
    if (esquerda || direita || cima || baixo || dentro || dentro1) {

        return true; //Retorna verdadeiro pois esta dentro

    } 

    return false; //Retorna falso se nao esta dentro, uma vez que nao entrou no laço
}

/* Analisa se tem algum Retangulo dentro da foto. */
void ProcuraRet(Lista Ret, Lista t, double xb, double yb, double rb, double hb, double pb){

    Iterador itR = createIterador(t, false);
    Item info;
    double dx, dy;

    while(!isIteratorEmpty(t, itR)) {
        info = getIteratorNext(t, itR);
        if(info == NULL){
            break;
        } else {
            if(ColideLinhaRetangulo(ParamX1R(info), ParamY1R(info), ParamX1R(info) + ParamW1R(info), ParamY1R(info) + ParamH1R(info), xb - rb, yb + pb, 2 * rb, hb)||
                ColideLinhaRetangulo(ParamX1R(info), ParamY1R(info) + ParamH1R(info), ParamX1R(info) + ParamW1R(info), ParamY1R(info), xb - rb, yb + pb, 2 * rb, hb)){
                //Encontrou Retangulo
                Retangulo novo = CopiarR(info);
                dx = ParamXT(info) - (xb-rb);
                dy = ParamYT(info) - yb - pb;
                AlteraDxR(novo, dx);
                AlteraDyR(novo, dy);
                insertLst(Ret, novo); //Inserindo Retangulo na lista de Retangulos fotografados
            } 
        }
    }
}

/* Analisa se tem alguma Linha dentro da foto. */
void ProcuraLin(Lista Lin, Lista t, double xb, double yb, double rb, double hb, double pb){

    Iterador itL = createIterador(t, false);
    Item info;
    double dx, dy;

    while(!isIteratorEmpty(t, itL)) {
        info = getIteratorNext(t, itL);
        if(info == NULL){
            break;
        } else {
            if(ColideLinhaRetangulo(ParamX1L(info), ParamY1L(info), ParamX2L(info), ParamY2L(info), xb - rb, yb + pb, 2 * rb, hb)){
                //Encontrou Linha
                Linha novo = CopiarL(info);
                dx = ParamX1L(info) - (xb-rb);
                dy = ParamY1L(info) - yb - pb;
                AlterarDxL(novo, dx);
                AlterarDyL(novo, dy);
                insertLst(Lin, novo); //Inserindo Linha na lista de Linhas fotografadas
            } 
        }
    }
}

/* Analisa se tem algum Circulo dentro da foto. */
void ProcuraCirc(Lista Circ, Lista t, double x, double y, double r, double a, double p){

    Iterador itC = createIterador(t, false);
    Item info;
    double dx, dy;
    
    while(!isIteratorEmpty(t, itC)) {
        info = getIteratorNext(t, itC);
        if(info == NULL){
            break;
        } else {
            if(ParamXC(info)>x-r && ParamXC(info)<x+r && ParamYC(info)>y+p && ParamYC(info)<y+p+a){
                //Encontrou Circulo
                Circulo novo = CopiarC(info);
                dx = ParamXC(info) - (x-r);
                dy = ParamYC(info) - y - p;
                alterarDxC(novo, dx);
                alterarDyC(novo, dy);
                insertLst(Circ, novo); //Inserindo Circulo na Lista de Circulos fotografados

            } else if (((x - r) - ParamXC(info)) * ((x - r) -ParamXC(info)) + ((y + p) - ParamYC(info)) *((y + p) - ParamYC(info)) < ParamRaioC(info) * ParamRaioC(info)){
                //Encontrou Circulo
                Circulo novo = CopiarC(info);
                dx = ParamXC(info) - (x-r);
                dy = ParamYC(info) - y - p;
                alterarDxC(novo, dx);
                alterarDyC(novo, dy);
                insertLst(Circ, novo); //Inserindo Circulo na Lista de Circulos fotografados

            } else if (((x + r) - ParamXC(info)) * ((x + r) -ParamXC(info)) + ((y + p) - ParamYC(info)) *((y + p) - ParamYC(info)) < ParamRaioC(info) * ParamRaioC(info)){
                //Encontrou Circulo
                Circulo novo = CopiarC(info);
                dx = ParamXC(info) - (x-r);
                dy = ParamYC(info) - y - p;
                alterarDxC(novo, dx);
                alterarDyC(novo, dy);
                insertLst(Circ, novo); //Inserindo Circulo na Lista de Circulos fotografados

            } else if (((x - r) - ParamXC(info)) * ((x - r) -ParamXC(info)) + ((y + p + a) - ParamYC(info)) *((y + p + a) - ParamYC(info)) < ParamRaioC(info) * ParamRaioC(info)){
                //Encontrou Circulo
                Circulo novo = CopiarC(info);
                dx = ParamXC(info) - (x-r);
                dy = ParamYC(info) - y - p;
                alterarDxC(novo, dx);
                alterarDyC(novo, dy);
                insertLst(Circ, novo); //Inserindo Circulo na Lista de Circulos fotografados

            } else if (((x + r) - ParamXC(info)) * ((x + r) -ParamXC(info)) + ((y + p + a) - ParamYC(info)) *((y + p + a) - ParamYC(info)) < ParamRaioC(info) * ParamRaioC(info)){
                //Encontrou Circulo
                Circulo novo = CopiarC(info);
                dx = ParamXC(info) - (x-r);
                dy = ParamYC(info) - y - p;
                alterarDxC(novo, dx);
                alterarDyC(novo, dy);
                insertLst(Circ, novo); //Inserindo Circulo na Lista de Circulos fotografados

            } else if(ParamXC(info)>x-r-ParamRaioC(info) && ParamXC(info)<x+r+ParamRaioC(info) && ParamYC(info)>y+p-ParamRaioC(info) && ParamYC(info)<y+p+a+ParamRaioC(info)){
                //Encontrou Circulo
                Circulo novo = CopiarC(info);
                dx = ParamXC(info) - (x-r);
                dy = ParamYC(info) - y - p;
                alterarDxC(novo, dx);
                alterarDyC(novo, dy);
                insertLst(Circ, novo); //Inserindo Circulo na Lista de Circulos fotografados

            }
        }
    }
}