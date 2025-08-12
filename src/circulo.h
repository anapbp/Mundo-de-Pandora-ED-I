#ifndef _CIRCULOS_
#define _CIRCULOS_

#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

typedef void *Circulo;

/*Cria um Circulo com os parametros i x y r corb corp graus. Inicia com grau 0*/
Circulo novoCirculo(int id, double x1, double y1, double r1, char cb[], char cp[]);

/*Pega parametro i do Circulo. Retorna -1 em caso de erro*/
int ParamIC(Circulo cir);

/*Pega parametro x do Circulo. Retorna -1 em caso de erro*/
double ParamXC(Circulo cir);

/*Pega parametro y do Circulo. Retorna -1 em caso de erro*/
double ParamYC(Circulo cir);

/*Pega parametro r do Circulo. Retorna -1 em caso de erro*/
double ParamRaioC(Circulo cir);

/*Pega parametro graus do Circulo. Retorna -1 em caso de erro*/
double ParamGrausC(Circulo cir);

/*Pega parametro dx do Circulo. Retorna -1 em caso de erro*/
double ParamDxC(Circulo cir);

/*Pega parametro dy do Circulo. Retorna -1 em caso de erro*/
double ParamDyC(Circulo cir);

/*Pega parametro corb do Circulo. Retorna NULL em caso de erro*/
char* ParamCbC(Circulo cir);

/*Pega parametro corp do Circulo. Retorna NULL em caso de erro*/
char* ParamCpC(Circulo cir);

/*Altera Id Circulo*/
void alteraIC(Circulo cir, int newId);

/*Movimenta o circulo em dx e dy*/
void moveCirculo(Circulo cir, double dx, double dy);

/*Altera a posicao do Circulo após ele se mover*/
void alterarPosicaoC(Circulo cir, double novo_x, double novo_y);

/*Altera dx do Circulo*/
void alterarDxC(Circulo cir, double novo_dx);

/*Altera dy do Circulo*/
void alterarDyC(Circulo cir, double novo_dy);

/*Rotaciona o Circulo em graus*/
void rotacionaCirculo(Circulo cir, double grs);

/*Altera graus do circulo apos ele rotacionar*/
void alterarGrausC(Circulo cir, double novo_grs);

/*Copia informacoes do Circulo. Retorna NULL em caso de erro*/
Circulo CopiarC(Circulo cir);

/*Atribui uma pontuacao para o Circulo e armazena em "void *Soma". */
void PontuacaoC(Circulo cir, void *Soma);

/*Encontra menor X do Circulo e armazena em "void *menor". */
void MenorXC(Circulo cir, void *menor);

/*Encontra maior X do Circulo e armazena em "void *maior". */
void MaiorXC(Circulo cir, void *maior);

/*Ve se Caca atingiu a bomba no Circulo. */
void ProcuraCircCaca(void *arqtxt, Lista Decoracoes, Lista Caca, Lista cir, double x, double y, double r);

/*Altera id do Circulo. */
void alterarIdC(Circulo cir, int novo_id);

/*Altera raio do Circulo. */
void alterarRaioC(Circulo cir, double novo_raio);

/*Encontrou Circulo correspondente ao Id*/
bool AchouIdC(Circulo c, void *id);

/*Adiciona dx em x do Circulo e inverte a cor da Borda e a cor de Preenchimento.*/
Circulo transladaC(Circulo cir, void *extra);

#endif