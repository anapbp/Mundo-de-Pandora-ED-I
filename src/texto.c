#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "circulo.h"
#include "lista.h"
#include "txt.h"
#include "svg.h"
#include "fila.h"
#include "foto.h"
 
struct StBalao{
    double r, p, alt;
    Fila *fotos;
};

struct StCaca{
    Lista identificadores;
    int tiros;
};

struct StTexto{
    int aux;
    int i;
    double x, y, grs, dx, dy;
    char corb[50], corp[50], a[20], txt[50], ff[50], fw[50], fs[50];
    Balao BC;
};

typedef struct StBalao BalaoImpl;
typedef struct StCaca CacaImpl;
typedef struct StTexto TextoImpl;

/* Cria um novo Texto com seus atributos. */
Texto novoTexto(int id, double x1, double y1, char cb[], char cp[], char anc[], char text[], char font_f[], char font_w[], char font_s[]){
    TextoImpl *novo = malloc(sizeof(TextoImpl));
    novo->i = id;
    novo->x = x1;
    novo->y = y1;
    novo->grs = 0;
    novo->aux = 0;
    strcpy(novo->corb, cb);
    strcpy(novo->corp, cp);
    strcpy(novo->a, anc);
    strcpy(novo->txt, text);
    strcpy(novo->ff, font_f);
    strcpy(novo->fw, font_w);
    strcpy(novo->fs, font_s);
    return novo;
}

/*Altera tipo do Caca quando ele é inicializado e vai realizar seu primeiro tiro.*/
void AlteraTipo(Texto t, double novo_tipo){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        texto->aux = novo_tipo;
    }
}

/* Funcao para pegar parametro Tipo do Caca. Retorna -1 em caso de erro.
Tipo do Caca é 0 quando ainda nao atirou.*/
int ParamTipo(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->aux;
    } else {
        return -1;
    }
}

/* Pega o parametro id do Texto. Retorna -1 em caso de erro.*/
int ParamIT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->i;
    } else {
        return -1;
    }
}

/* Pega o parametro x do Texto. Retorna -1 em caso de erro.*/
double ParamXT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->x;
    } else {
        return -1;
    }
}

/* Pega o parametro y do Texto. Retorna -1 em caso de erro.*/
double ParamYT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->y;
    } else {
        return -1;
    }
}

/* Pega o parametro graus do Texto. Retorna -1 em caso de erro.*/
double ParamGrausT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->grs;
    } else {
        return -1;
    }
}

/* Pega o parametro dx do Texto. Retorna -1 em caso de erro.*/
double ParamDxT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->dx;
    } else {
        return -1;
    }
}

/* Pega o parametro dy do Texto. Retorna -1 em caso de erro.*/
double ParamDyT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->dy;
    } else {
        return -1;
    }
}

/* Pega o parametro corb do Texto. Retorna NULL em caso de erro.*/
char* ParamCbT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->corb;
    } else {
        return NULL;
    }
}

/* Pega o parametro corp do Texto. Retorna NULL em caso de erro.*/
char* ParamCpT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->corp;
    } else {
        return NULL;
    }
}

/* Pega o parametro texto do Texto. Retorna NULL em caso de erro.*/
char* ParamTextoT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->txt;
    } else {
        return NULL;
    }
}

/* Pega o parametro Font Family do Texto. Retorna NULL em caso de erro.*/
char* ParamFFT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->ff;
    } else {
        return NULL;
    }
}

/* Pega o parametro Font Size do Texto. Retorna NULL em caso de erro.*/
char* ParamFST(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->fs;
    } else {
        return NULL;
    }
}

/* Pega o parametro Font Weigth do Texto. Retorna NULL em caso de erro.*/
char* ParamFWT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->fw;
    } else {
        return NULL;
    }
}

/* Pega o parametro ancora do Texto. Retorna NULL em caso de erro.*/
char* ParamAncT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->a;
    } else {
        return NULL;
    }
}

/* Pega o parametro Balao do Texto. Retorna NULL em caso de erro.*/
Balao ParamBalaoT(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        return texto->BC;
    } else {
        return NULL;
    }
}

/* Altera x do Texto. */
void AlteraXT(Texto t, double novo_x){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        texto->x = novo_x;
    } 
}

/* Altera y do Texto. */
void AlteraYT(Texto t, double novo_y){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        texto->y = novo_y;
    }
}

/* Altera dx do Texto. */
void AlteraDxT(Texto t, double novo_dx){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        texto->dx = novo_dx;
    }
}

/* Altera dy do Texto. */
void AlteraDyT(Texto t, double novo_dy){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        texto->dy = novo_dy;
    }
}

/* Altera graus do Texto. */
void AlteraGrausT(Texto t, double novo_grs){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        texto->grs = novo_grs;
    }
}

/* Altera graus do Texto. */
void AlteraIT(Texto t, int novo_i){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        texto->i = novo_i;
    }
}

/* Move o Texto e altera o seu x e o seu y. */
void moveTexto(Texto t, double dx, double dy){
    double auxx, auxy;
    if(t!=NULL){
        auxx = ParamXT(t);
        auxy = ParamYT(t);

        auxx = auxx + dx;
        auxy = auxy + dy;

        AlteraXT(t, auxx);
        AlteraYT(t, auxy);
    }
}

/* Rotaciona Texto e altera o seu grau. */
void rotacionaTexto(Texto t, double graus){
    double auxg;
    if(t!=NULL){
        auxg = ParamGrausT(t);
        auxg = auxg + graus;

        AlteraGrausT(t, auxg);
    }
}

/* Cria um balao com atributos raio, profundidade e altura. */
void createBalao(Texto t, double raio, double prof, double a){
    TextoImpl* texto = (TextoImpl*) t;

    if(texto!=NULL){
        BalaoImpl *novo = malloc(sizeof(BalaoImpl));
        if(novo == NULL){
            printf("Erro ao criar balao\n");
        } else {
            novo->p = prof;
            novo->r = raio;
            novo->alt = a;
            novo->fotos = malloc(sizeof(Fila) * 10);

            for(int i = 0; i<10; i++){
                novo->fotos[i] = malloc(sizeof(Fila));
                novo->fotos[i] = createFila(15);
            }

            texto->BC = novo;
        }
    }
}

/* Altera atributos raio, profundidade e altura do Balao. */
void AlteraBalao(Texto t, double raio, double prof, double a){
    TextoImpl* texto = (TextoImpl*) t;
    BalaoImpl* bal = (BalaoImpl*)texto->BC;
    
    if(bal!=NULL){
        bal->p = prof;
        bal->r = raio;
        bal->alt = a;
    } 
}

/* Pega o parametro raio do Balao. Retorna -1 em caso de erro.*/
double ParamRaioB(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    BalaoImpl* bal = (BalaoImpl*)texto->BC;
    if(bal!=NULL){
        return bal->r;
    } else {
        return -1;
    }
}

/* Pega o parametro profundidade do Balao. Retorna -1 em caso de erro.*/
double ParamProfB(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    BalaoImpl* bal = (BalaoImpl*)texto->BC;
    if(bal!=NULL){
        return bal->p;
    } else {
        return -1;
    }
}

/* Pega o parametro altura do Balao. Retorna -1 em caso de erro.*/
double ParamAltB(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    BalaoImpl* bal = (BalaoImpl*)texto->BC;
    if(bal!=NULL){
        return bal->alt;
    } else {
        return -1;
    }
}

/* Pega o parametro Fila do Balao. Retorna NULL em caso de erro.*/
Fila ParamFilaB(Texto t, int i){
    TextoImpl* texto = (TextoImpl*) t;
    BalaoImpl* bal = (BalaoImpl*)texto->BC;
    if(bal!=NULL){
        return bal->fotos[i];
    } else {
        return NULL;
    }
}

/* Copia informacoes do Texto. Retorna NULL em caso de erro.*/
Texto CopiarT(Texto t){ 
    TextoImpl *tt = malloc(sizeof(TextoImpl));
    TextoImpl* texto = (TextoImpl*) t;

    if(texto != NULL){

        tt->i = ParamIT(texto);
        tt->x = ParamXT(texto);
        tt->y = ParamYT(texto);
        tt->grs = ParamGrausT(texto);
        strcpy(tt->corb, ParamCbT(texto));
        strcpy(tt->corp, ParamCpT(texto));
        strcpy(tt->a, ParamAncT(texto));
        strcpy(tt->txt, ParamTextoT(texto));

        return tt;

    } else {

        return NULL;
    }
}

/* Atribui uma pontuacao para cada texto e adiciona em "void *Soma". */
void PontuacaoT(Texto t, void *Soma){

    if(t!=NULL){

        double aux = strlen(ParamTextoT(t)) - 1;
        
        if(!strcmp((ParamTextoT(t)), "|-T-|")){

            aux = 100;
        }

        *(double*)Soma += aux;
    }
}

/* Encontra o menor x e armazena em "void *menor". */
void MenorXT(Texto t, void *menor){
    if(t!=NULL){
        if(ParamDxT(t)< *(double*)menor){
            *(double*)menor = ParamDxT(t);
        } 
    }
}

/* Encontra o maior x e armazena em "void *maior". */
void MaiorXT(Texto t, void *maior){
    if(t!=NULL){
        if(ParamDxT(t)> *(double*)maior){
            *(double*)maior = ParamDxT(t);
        } 
    }
}

/* Cria um Caca. */
void createCaca(Texto t){
    TextoImpl* texto = (TextoImpl*) t;

    if(texto!=NULL){

        CacaImpl *novo = malloc(sizeof(CacaImpl));
        novo->tiros = 0;
        novo->identificadores = createLst(-1);
        texto->aux = 1;
        texto->BC = novo;
    }
}

/*Aumenta tiro do Caca em +1. */
void aumentaTiro(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    if(texto!=NULL){
        CacaImpl* c = (CacaImpl*)texto->BC;
        c->tiros++;
    }
}

/* Pega o parametro tiros do Caca. Retorna -1 em caso de erro.*/
int ParamTiros(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    CacaImpl* c = (CacaImpl*)texto->BC;
    if(c!=NULL){
        return c->tiros;
    } else {
        return -1;
    }
}

/* Pega o parametro identificadores do Caca. Retorna NULL em caso de erro.*/
Lista ParamIdentificadores(Texto t){
    TextoImpl* texto = (TextoImpl*) t;
    CacaImpl* c = (CacaImpl*)texto->BC;

    if(c!=NULL){

        return c->identificadores;

    } else {

        return NULL;
    }
}

/*Encontra Texto correspondente ao Id.*/
bool AchouIdT(Texto t, void *id){
    return (ParamIT(t) == *(int*)id);
}

/*Movimenta dx no eixo x do Texto e inverte as cores de Borda e de Preenchimento. */
Texto transladaT(Texto t, void *extra){ 

    TextoImpl *tt = malloc(sizeof(TextoImpl));
    TextoImpl* texto = (TextoImpl*) t;

    if(texto!=NULL){

        tt->i = ParamIT(texto);
        tt->x = ParamXT(texto) + *(double*)extra;
        tt->y = ParamYT(texto);
        tt->grs = ParamGrausT(texto);
        strcpy(tt->corb, ParamCpT(texto));
        strcpy(tt->corp, ParamCbT(texto));
        strcpy(tt->a, ParamAncT(texto));
        strcpy(tt->txt, ParamTextoT(texto));
        
        return tt;

    } else {

        return NULL;
        
    }
}