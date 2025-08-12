#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "circulo.h"
#include "texto.h"
#include "lista.h"
#include "txt.h"
#include "svg.h"
 
struct StCirculo{
  int i;
  double x, y , r, grs, dx, dy;
  char corb[50], corp[50];
};

typedef struct StCirculo CirculoImpl;

/*Cria um Circulo com os parametros i x y r corb corp graus. Inicia com grau 0*/
Circulo novoCirculo(int id, double x1, double y1, double r1, char *cb, char *cp){
    CirculoImpl *novo = malloc(sizeof(CirculoImpl));
    novo->i = id;
    novo->x = x1;
    novo->y = y1;
    novo->r = r1;
    novo->grs = 0;
    strcpy(novo->corb, cb);
    strcpy(novo->corp, cp);
    return novo;
}

/*Pega parametro i do Circulo. Retorna -1 em caso de erro. */
int ParamIC(Circulo cir){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        return circulo->i;
    } else {
        return -1;
    }
}

/*Pega parametro x do Circulo. Retorna -1 em caso de erro*/
double ParamXC(Circulo cir){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        return circulo->x;
    } else {
        return -1;
    }
}

/*Pega parametro y do Circulo. Retorna -1 em caso de erro*/
double ParamYC(Circulo cir){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        return circulo->y;
    } else {
        return -1;
    }
}

/*Pega parametro r do Circulo. Retorna -1 em caso de erro*/
double ParamRaioC(Circulo cir){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        return circulo->r;
    } else {
        return -1;
    }
}

/*Pega parametro graus do Circulo. Retorna -1 em caso de erro*/
double ParamGrausC(Circulo cir){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        return circulo->grs;
    } else {
        return -1;
    }
}

/*Pega parametro dx do Circulo. Retorna -1 em caso de erro*/
double ParamDxC(Circulo cir){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        return circulo->dx;
    } else {
        return -1;
    }
}

/*Pega parametro dy do Circulo. Retorna -1 em caso de erro*/
double ParamDyC(Circulo cir){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        return circulo->dy;
    } else {
        return -1;
    }
}

/*Pega parametro corb do Circulo. Retorna NULL em caso de erro*/
char* ParamCbC(Circulo cir){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        return circulo->corb;
    } else {
        return NULL;
    }
}

/*Pega parametro corp do Circulo. Retorna NULL em caso de erro*/
char* ParamCpC(Circulo cir){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        return circulo->corp;
    } else {
        return NULL;
    }
}

/*Altera a posicao do Circulo após ele se mover.*/
void alterarPosicaoC(Circulo cir, double novo_x, double novo_y){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        circulo->x = novo_x;
        circulo->y = novo_y;
    }
}

/*Altera dx do Circulo*/
void alterarDxC(Circulo cir, double novo_dx){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        circulo->dx = novo_dx;
    }
}

/*Altera dy do Circulo*/
void alterarDyC(Circulo cir, double novo_dy){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        circulo->dy = novo_dy;
    }
}

/*Altera graus do circulo apos ele rotacionar*/
void alterarGrausC(Circulo cir, double novo_grs){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
    circulo->grs = novo_grs;
    }
}

/*Altera Id do Circulo*/
void alteraIC(Circulo cir, int newId){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
    circulo->i = newId;
    }
}

/*Movimenta o circulo em dx e dy*/
void moveCirculo(Circulo cir, double dx, double dy){
  double auxx, auxy;
  if(cir!=NULL){
    auxx = ParamXC(cir);
    auxy = ParamYC(cir);

    auxx = auxx + dx;
    auxy = auxy + dy;

    alterarPosicaoC(cir, auxx, auxy);
  }
}

/*Rotaciona o Circulo em graus*/
void rotacionaCirculo(Circulo cir, double grs){
  double auxg;
    if(cir!=NULL){
        auxg = ParamGrausC(cir);
        auxg = auxg + grs;
        
        alterarGrausC(cir, auxg);
    }
}

/*Copia informacoes do Circulo. Retorna NULL em caso de erro*/
Circulo CopiarC(Circulo cir){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        CirculoImpl *novo = malloc(sizeof(CirculoImpl));
        novo->i = ParamIC(circulo);
        novo->x = ParamXC(circulo);
        novo->y = ParamYC(circulo);
        novo->r = ParamRaioC(circulo);
        novo->grs = ParamGrausC(circulo);
        strcpy(novo->corb, ParamCbC(circulo));
        strcpy(novo->corp, ParamCpC(circulo));
        
        return novo;
    } else {
        return NULL;
    }
}

/*Atribui uma pontuacao para o Circulo e armazena em "void *Soma". */
void PontuacaoC(Circulo cir, void *Soma){

    if(cir!=NULL){
        double aux = (3.14 * ParamRaioC(cir) * ParamRaioC(cir))/2;

        if(!strcmp(ParamCbC(cir),"#FFFFFF") && !strcmp(ParamCpC(cir),"#FFFF00")){
            
            aux = aux * 8;

        } else if(!strcmp(ParamCbC(cir),"#D45500") && !strcmp(ParamCpC(cir),"#FF7F2A")){
           
            aux = aux * 2;

        } else if(!strcmp(ParamCbC(cir),"#AA0000") && !strcmp(ParamCpC(cir),"#DE8787")){
            
            aux = aux * 4;
        }

        if(!strcmp(ParamCbC(cir),"#FFFFFF") && !strcmp(ParamCpC(cir),"#B3B3B3")){
            
            aux = 0;
        }

        * (double *) Soma += aux;
    }
}

/*Encontra menor X do Circulo e armazena em "void *menor". */
void MenorXC(Circulo cir, void *menor){
    if(cir!=NULL){

        if(ParamDxC(cir) - ParamRaioC(cir)< *(double*)menor){
            *(double*)menor = ParamDxC(cir) - ParamRaioC(cir);
        }
    }
}

/*Encontra maior X do Circulo e armazena em "void *maior". */
void MaiorXC(Circulo cir, void *maior){
    if(cir!=NULL){
        if(ParamDxC(cir) + ParamRaioC(cir)> *(double*)maior){
            *(double*)maior = ParamDxC(cir) + ParamRaioC(cir);
        }
    }
}

/*Ve se Caca atingiu a bomba no Circulo. */
void ProcuraCircCaca(void *arqtxt, Lista Decoracoes, Lista Caca, Lista cir, double x, double y, double r){

    Item info;
    Posic posicao = getFirstLst(cir);

    while(posicao != NULL){

        info = getLst(cir, posicao);
        /* Caso a distancia entre os centros do Circulo e do centro da Bomba for menor que a soma
        de seus raios, entao a Bomba atingiu o Circulo. */
        if(sqrt((ParamXC(info) - x) * (ParamXC(info) - x) + (ParamYC(info) - y) * (ParamYC(info) - y)) < ParamRaioC(info) + r){
            //Bomba atingiu o circulo.
            int *ptr = malloc(sizeof(int));
            *ptr = ParamIC(info);

            fprintf((FILE*)arqtxt, "Circulo de id %d removido. Atributos:\n", *ptr);
            CirculoTxt(info, (FILE*) arqtxt);
            insertLst(Caca, (Item) ptr);
            removeLst(cir, posicao); //Removendo Circulo do Banco de Dados
            Texto t = novoTexto(1, ParamXC(info), ParamYC(info), "#FF0000", "#FF0000", "middle", "x", "normal", "normal", "middle");
            insertLst(Decoracoes, t); //Inserindo X de decoracao na ancora do Circulo removido
        } 

        posicao = getNextLst(cir, posicao);
    }
}


/*Altera id do Circulo. */
void alterarIdC(Circulo cir, int novo_id){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        circulo->i = novo_id;
    }
}

/*Altera raio do Circulo. */
void alterarRaioC(Circulo cir, double novo_raio){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        circulo->r = novo_raio;
    }
}

/*Encontrou Circulo correspondente ao Id*/
bool AchouIdC(Circulo c, void *id){
    return (ParamIC(c) == *(int*)id);
}

/*Adiciona dx em x do Circulo e inverte a cor da Borda e a cor de Preenchimento.*/
Circulo transladaC(Circulo cir, void *extra){
    CirculoImpl* circulo = (CirculoImpl*) cir;
    if(circulo!=NULL){
        CirculoImpl *novo = malloc(sizeof(CirculoImpl));
        novo->i = ParamIC(circulo);
        novo->x = ParamXC(circulo) + *(double*) extra;
        novo->y = ParamYC(circulo);
        novo->r = ParamRaioC(circulo);
        novo->grs = ParamGrausC(circulo);
        strcpy(novo->corb, ParamCbC(circulo));
        strcpy(novo->corp, ParamCpC(circulo));
        
        return novo;
    } else {
        return NULL;
    }
}