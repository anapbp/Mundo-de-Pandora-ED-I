#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "retangulo.h"
#include "texto.h"
#include "lista.h"
#include "txt.h"
#include "svg.h"
 
struct StRetangulo{
  int i;
  double x, y , w, h, grs, dx, dy;
  char corb[50], corp[50];
};

typedef struct StRetangulo RetanguloImpl;

//Cria novo Retangulo com os parametros i x y w h corb corp.
Retangulo novoRetangulo(int id, double x1, double y1, double w1, double h1, char cb[], char cp[]){
    RetanguloImpl *novo = malloc(sizeof(RetanguloImpl));
    novo->i = id;
    novo->x = x1;
    novo->y = y1;
    novo->w = w1;
    novo->h = h1;
    novo->grs = 0;
    strcpy(novo->corb, cb);
    strcpy(novo->corp, cp);

    return novo;
}

/*Pega o parametro i do Retangulo. Retorna -1 em caso de erro.*/
int ParamIR(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        return retangulo->i;
    } else {
        return -1;
    }
}

/*Pega o parametro x do Retangulo. Retorna -1 em caso de erro.*/
double ParamX1R(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        return retangulo->x;
    } else {
        return -1;
    }
}

/*Pega o parametro y do Retangulo. Retorna -1 em caso de erro.*/
double ParamY1R(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        return retangulo->y;
    } else {
        return -1;
    }
}

/*Pega o parametro w do Retangulo. Retorna -1 em caso de erro.*/
double ParamW1R(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        return retangulo->w;
    } else {
        return -1;
    }
}

/*Pega o parametro h do Retangulo. Retorna -1 em caso de erro.*/
double ParamH1R(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        return retangulo->h;
    } else {
        return -1;
    }
}

/*Pega o parametro graus do Retangulo. Retorna -1 em caso de erro.*/
double ParamGrausR(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        return retangulo->grs;
    } else {
        return -1;
    }
}

/*Pega o parametro dx do Retangulo. Retorna -1 em caso de erro.*/
double ParamDxR(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        return retangulo->dx;
    } else {
        return -1;
    }
}

/*Pega o parametro dy do Retangulo. Retorna -1 em caso de erro.*/
double ParamDyR(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        return retangulo->dy;
    } else {
        return -1;
    }
}

/*Pega o parametro corb do Retangulo. Retorna NULL em caso de erro.*/
char* ParamCbR(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        return retangulo->corb;
    } else {
        return NULL;
    }
}

/*Pega o parametro corp do Retangulo. Retorna NULL em caso de erro.*/
char* ParamCpR(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        return retangulo->corp;
    } else {
        return NULL;
    }
}

/*Altera o parametro Id do Retangulo. */
void AlteraIR(Retangulo Ret, int novo_i){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        retangulo->i = novo_i;
    }
}


/*Altera o parametro x apos se mover*/
void AlteraX1R(Retangulo Ret, double novo_x){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        retangulo->x = novo_x;
    }
}

/*Altera o parametro y apos se mover*/
void AlteraY1R(Retangulo Ret, double novo_y){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        retangulo->y = novo_y;
    }
}

/*Altera o parametro dx. */
void AlteraDxR(Retangulo Ret, double novo_dx){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        retangulo->dx = novo_dx;
    }
}

/*Altera o parametro dy. */
void AlteraDyR(Retangulo Ret, double novo_dy){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        retangulo->dy = novo_dy;
    }
}

/*Altera o parametro graus apos rotacionar*/
void AlteraGrausR(Retangulo Ret, double novo_grs){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        retangulo->grs = novo_grs;
    }
}

/*Move o Retangulo em dx e dy*/
void moveRetangulo(Retangulo Ret, double dx, double dy){
    double auxx, auxy;
    if(Ret!=NULL){
        auxx = ParamX1R(Ret);
        auxy = ParamY1R(Ret);

        auxx = auxx + dx;
        auxy = auxy + dy;

        AlteraX1R(Ret, auxx);
        AlteraY1R(Ret, auxy);
    }
}

/*Rotaciona o Retangulo em graus*/
void rotacionaRetangulo(Retangulo Ret, double graus){
    double auxg;
    if(Ret!=NULL){
        auxg = ParamGrausR(Ret);
        auxg = auxg + graus;
        AlteraGrausR(Ret, auxg);
    }
}

/*Copia as informacoes do Retangulo. Retorna NULL em caso de erro.*/
Retangulo CopiarR(Retangulo Ret){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;

    if(retangulo!=NULL){

        RetanguloImpl *novo = malloc(sizeof(RetanguloImpl));
        novo->i = ParamIR(retangulo);
        novo->x = ParamX1R(retangulo);
        novo->y = ParamY1R(retangulo);
        novo->w = ParamW1R(retangulo);
        novo->h = ParamH1R(retangulo);
        novo->grs = ParamGrausR(retangulo);
        strcpy(novo->corb, ParamCbR(retangulo));
        strcpy(novo->corp, ParamCpR(retangulo));

        return novo;

    } else {

        return NULL;

    }
}

/*Atribui uma Pontuacao para cada Retangulo e adiciona na variavel "void *Soma". */
void PontuacaoR(Retangulo Ret, void *Soma){

    if(Ret!=NULL){

        double aux = (ParamW1R(Ret) * ParamH1R(Ret))/4;

        if(!strcmp(ParamCbR(Ret),"#800080")){
            
            aux = aux + 10;

        } else if(!strcmp(ParamCbR(Ret),"#AA0088")){
            
            aux = aux + 15;
        }

        if(!strcmp(ParamCpR(Ret),"#008033")){
            
            aux = aux + 20;

        } else if(!strcmp(ParamCpR(Ret),"#FFCC00")){
            
            aux = aux + 30;
        }

        * (double*) Soma += aux;
    }
}

/*Encontra o menor x dos Retangulos e adiciona na variavel "void *menor". */
void MenorXR(Retangulo Ret, void *menor){
    if(Ret!=NULL){
        if(ParamDxR(Ret)< *(double*)menor){
            *(double*)menor = ParamDxR(Ret);
        }
    }
}

/*Encontra o maior x dos Retangulos e adiciona na variavel "void *maior". */
void MaiorXR(Retangulo Ret, void *maior){
    if(Ret!=NULL){
        if(ParamDxR(Ret) + ParamW1R(Ret)> *(double*)maior){
            *(double*)maior = ParamDxR(Ret) + ParamW1R(Ret);
        }
    }
}

/*Ve se o Caca atingiu a bomba no Retangulo. */
void ProcuraRetCaca(FILE* arqtxt, Lista Decoracoes, Lista Caca, Lista ret, double x, double y, double r){

    Item info;
    Posic posicao = getFirstLst(ret);
    
    while(posicao != NULL){

        info = getLst(ret, posicao);
        if(info == NULL){
            break;
        } else {

            if(x>ParamX1R(info) && x<ParamX1R(info) + ParamW1R(info) && y>ParamY1R(info) && y<ParamY1R(info) + ParamH1R(info)){
                
                int *ptr = malloc(sizeof(int));
                *ptr = ParamIR(info);
                //Bomba explodiu Retangulo
                fprintf(arqtxt, "Retangulo de id %d removido. Atributos:\n", *ptr);
                RetanguloTxt(info, arqtxt);
                insertLst(Caca, (Item) ptr);
                removeLst(ret, posicao); //Removendo Retangulo do Banco de Dados

                Texto t = novoTexto(1, ParamX1R(info), ParamY1R(info), "#FF0000", "#FF0000", "middle", "x", "normal", "normal", "middle");
                insertLst(Decoracoes, t); //Inserindo decoracao X no Retangulo destruido

            } else if ((ParamX1R(info) - x) * (ParamX1R(info) - x) + (ParamY1R(info) - y) *(ParamY1R(info) - y) < r * r){
                
                int *ptr = malloc(sizeof(int));
                *ptr = ParamIR(info);
                //Bomba explodiu Retangulo
                fprintf(arqtxt, "Retangulo de id %d removido. Atributos:\n", *ptr);
                RetanguloTxt(info, arqtxt);
                insertLst(Caca, (Item) ptr);
                removeLst(ret, posicao); //Removendo Retangulo do Banco de Dados

                Texto t = novoTexto(1, ParamX1R(info), ParamY1R(info), "#FF0000", "#FF0000", "middle", "x", "normal", "normal", "middle");
                insertLst(Decoracoes, t); //Inserindo decoracao X no Retangulo destruido

            } else if (((ParamX1R(info) + ParamW1R(info)) - x) * ((ParamX1R(info) + ParamW1R(info)) -x) + (ParamY1R(info) - y) *(ParamY1R(info) - y) < r * r){
                
                int *ptr = malloc(sizeof(int));
                *ptr = ParamIR(info);
                //Bomba explodiu Retangulo
                fprintf(arqtxt, "Retangulo de id %d removido. Atributos:\n", *ptr);
                RetanguloTxt(info, arqtxt);
                insertLst(Caca, (Item) ptr);
                removeLst(ret, posicao); //Removendo Retangulo do Banco de Dados
                Texto t = novoTexto(1, ParamX1R(info), ParamY1R(info), "#FF0000", "#FF0000", "middle", "x", "normal", "normal", "middle");
                insertLst(Decoracoes, t); //Inserindo decoracao X no Retangulo destruido

            } else if ((ParamX1R(info) - x) * (ParamX1R(info) - x) + ((ParamY1R(info) + ParamH1R(info)) - y) *((ParamY1R(info) + ParamH1R(info)) - y) < r * r){
                
                int *ptr = malloc(sizeof(int));
                *ptr = ParamIR(info);
                //Bomba explodiu Retangulo
                fprintf(arqtxt, "Retangulo de id %d removido. Atributos:\n", *ptr);
                RetanguloTxt(info, arqtxt);
                insertLst(Caca, (Item) ptr);
                removeLst(ret, posicao); //Removendo Retangulo do Banco de Dados

                Texto t = novoTexto(1, ParamX1R(info), ParamY1R(info), "#FF0000", "#FF0000", "middle", "x", "normal", "normal", "middle");
                insertLst(Decoracoes, t); //Inserindo decoracao X no Retangulo destruido

            } else if (((ParamX1R(info) + ParamW1R(info)) - x) * ((ParamX1R(info) + ParamW1R(info)) - x) + ((ParamY1R(info) + ParamH1R(info)) - y) *((ParamY1R(info) + ParamH1R(info)) - y) < r * r){
                
                int *ptr = malloc(sizeof(int));
                *ptr = ParamIR(info);
                //Bomba explodiu Retangulo
                fprintf(arqtxt, "Retangulo de id %d removido. Atributos:\n", *ptr);
                RetanguloTxt(info, arqtxt);
                insertLst(Caca, (Item) ptr);
                removeLst(ret, posicao); //Removendo Retangulo do Banco de Dados

                Texto t = novoTexto(1, ParamX1R(info), ParamY1R(info), "#FF0000", "#FF0000", "middle", "x", "normal", "normal", "middle");
                insertLst(Decoracoes, t); //Inserindo decoracao X no Retangulo destruido

            } else if(x>ParamX1R(info) - r && x<(ParamX1R(info) + ParamW1R(info)) + r && y>ParamY1R(info) - r && y<(ParamY1R(info) + ParamH1R(info)) + r){
                
                int *ptr = malloc(sizeof(int));
                *ptr = ParamIR(info);
                //Bomba explodiu Retangulo
                fprintf(arqtxt, "Retangulo de id %d removido. Atributos:\n", *ptr);
                RetanguloTxt(info, arqtxt);
                insertLst(Caca, (Item) ptr);
                removeLst(ret, posicao); //Removendo Retangulo do Banco de Dados

                Texto t = novoTexto(1, ParamX1R(info), ParamY1R(info), "#FF0000", "#FF0000", "middle", "x", "normal", "normal", "middle");
                insertLst(Decoracoes, t); //Inserindo decoracao X no Retangulo destruido
            }

            posicao = getNextLst(ret, posicao);
        }
    }
}

/*Altera largura do Retangulo. */
void AlteraW1R(Retangulo Ret, double novo_w){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        retangulo->w = novo_w;
    }
}

/*Altera altura do Retangulo. */
void AlteraH1R(Retangulo Ret, double novo_h){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;
    if(retangulo!=NULL){
        retangulo->h = novo_h;
    }
}

/*Encontra Retangulo de Id correspondente.*/
bool AchouIdR(Retangulo ret, void *id){
    return (ParamIR(ret) == *(int*)id);
}

/* Movimenda dx em x e inverte as cores de Borda e de Preenchimento do Retangulo. */
Retangulo transladaR(Retangulo Ret, void *extra){
    RetanguloImpl* retangulo = (RetanguloImpl*) Ret;

    if(retangulo!=NULL){

        RetanguloImpl *novo = malloc(sizeof(RetanguloImpl));
        novo->i = ParamIR(retangulo);
        novo->x = ParamX1R(retangulo) + *(double*) extra;
        novo->y = ParamY1R(retangulo);
        novo->w = ParamW1R(retangulo);
        novo->h = ParamH1R(retangulo);
        novo->grs = ParamGrausR(retangulo);
        strcpy(novo->corb, ParamCpR(retangulo));
        strcpy(novo->corp, ParamCbR(retangulo));

        return novo;

    } else {

        return NULL;

    }
}