#ifndef _RETANGULOS_
#define _RETANGULOS_

#include "lista.h"
#include <stdbool.h>
#include <stdio.h>

typedef void *Retangulo;

//Cria novo Retangulo com os parametros i x y w h corb corp.
Retangulo novoRetangulo(int id, double x1, double y1, double w1, double h1, char cb[], char cp[]);

/*Pega o parametro i do Retangulo. Retorna -1 em caso de erro.*/
int ParamIR(Retangulo Ret);

/*Pega o parametro x do Retangulo. Retorna -1 em caso de erro.*/
double ParamX1R(Retangulo Ret);

/*Pega o parametro y do Retangulo. Retorna -1 em caso de erro.*/
double ParamY1R(Retangulo Ret);

/*Pega o parametro w do Retangulo. Retorna -1 em caso de erro.*/
double ParamW1R(Retangulo Ret);

/*Pega o parametro h do Retangulo. Retorna -1 em caso de erro.*/
double ParamH1R(Retangulo Ret);

/*Pega o parametro graus do Retangulo. Retorna -1 em caso de erro.*/
double ParamGrausR(Retangulo Ret);

/*Pega o parametro dx do Retangulo. Retorna -1 em caso de erro.*/
double ParamDxR(Retangulo Ret);

/*Pega o parametro dy do Retangulo. Retorna -1 em caso de erro.*/
double ParamDyR(Retangulo Ret);

/*Pega o parametro corb do Retangulo. Retorna NULL em caso de erro.*/
char * ParamCbR(Retangulo Ret);

/*Pega o parametro corp do Retangulo. Retorna NULL em caso de erro.*/
char * ParamCpR(Retangulo Ret);

/*Altera Id do Retangulo. */
void AlteraIR(Retangulo Ret, int novo_i);

/*Move o Retangulo em dx e dy*/
void moveRetangulo(Retangulo Ret, double dx, double dy);

/*Altera o parametro x apos se mover*/
void AlteraX1R(Retangulo Ret, double novo_x);

/*Altera o parametro y apos se mover*/
void AlteraY1R(Retangulo Ret, double novo_y);

/*Altera o parametro dx. */
void AlteraDxR(Retangulo Ret, double novo_dx);

/*Altera o parametro dy. */
void AlteraDyR(Retangulo Ret, double novo_dy);

/*Rotaciona o Retangulo em graus*/
void rotacionaRetangulo(Retangulo Ret, double graus);

/*Altera o parametro graus apos rotacionar*/
void AlteraGrausR(Retangulo Ret, double novo_grs);

/*Copia as informacoes do Retangulo. Retorna NULL em caso de erro.*/
Retangulo CopiarR(Retangulo Ret);

/*Atribui uma Pontuacao para cada Retangulo e adiciona na variavel "void *Soma". */
void PontuacaoR(Retangulo Ret, void *Soma);

/*Encontra o menor x dos Retangulos e adiciona na variavel "void *menor". */
void MenorXR(Retangulo Ret, void *menor);

/*Encontra o maior x dos Retangulos e adiciona na variavel "void *maior". */
void MaiorXR(Retangulo Ret, void *maior);

/*Ve se o Caca atingiu a bomba no Retangulo. */
void ProcuraRetCaca(FILE* arqtxt, Lista Decoracoes, Lista Caca, Lista ret, double x, double y, double r);

/*Altera largura do Retangulo. */
void AlteraW1R(Retangulo Ret, double novo_w);

/*Altera altura do Retangulo. */
void AlteraH1R(Retangulo Ret, double novo_h);

/*Encontra Retangulo correspondente ao Id. */
bool AchouIdR(Retangulo ret, void *id);

/*Movimenta dx em x e inverte as cores de Borda e de Preenchimento do Retangulo. */
Retangulo transladaR(Retangulo Ret, void *extra);

#endif