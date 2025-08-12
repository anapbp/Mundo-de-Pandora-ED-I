#ifndef _LINHAS_
#define _LINHAS_

#include "lista.h"
#include <stdbool.h>

typedef void *Linha;

/*Cria uma linha para os parametros i x1 y1 x2 y2 cor e graus. Graus inicia em 0*/
Linha novaLinha(int id, double xx1, double yy1, double xx2, double yy2, char corr[]);

/*Pegar parametro i da Linha. Retorna -1 em caso de erro.*/
int ParamIdL(Linha l);

/*Pegar parametro x1 da Linha. Retorna -1 em caso de erro.*/
double ParamX1L(Linha l);

/*Pegar parametro y1 da Linha. Retorna -1 em caso de erro.*/
double ParamY1L(Linha l);

/*Pegar parametro x2 da Linha. Retorna -1 em caso de erro.*/
double ParamX2L(Linha l);

/*Pegar parametro y2 da Linha. Retorna -1 em caso de erro.*/
double ParamY2L(Linha l);

/*Pegar parametro graus da Linha. Retorna -1 em caso de erro.*/
double ParamGrausL(Linha l);

/*Pegar parametro dx da Linha. Retorna -1 em caso de erro.*/
double ParamDxL(Linha l);

/*Pegar parametro dy da Linha. Retorna -1 em caso de erro.*/
double ParamDyL(Linha l);

/*Pegar parametro cor da Linha. Retorna NULL em caso de erro.*/
char* ParamCorL(Linha l);

/* Altera Id da Linha. */
void AlteraIL(Linha l, int novo_i);

/*Alterar graus da Linha*/
void AlterarGrausL(Linha l, double graus);

/*Alterar dx da Linha*/
void AlterarDxL(Linha l, double new_dx);

/*Alterar dy da Linha*/
void AlterarDyL(Linha l, double new_dy);

/*Mover a Linha em dx e dy*/
void MoverLinha(Linha l, double dx, double dy);

/*Rotaciona a Linha em graus*/
void rotacionaLinha(Linha l, double grs);

/*Copia informacoes da Linha. Retorna NULL em caso de erro.*/
Linha CopiarL(Linha l);

/*Atribui uma pontuacao para cada Linha e armazna em "void *Soma". */
void PontuacaoL(Linha l, void *Soma);

/*Pega o menor x da Linha e armazena em "void *menor". */
void MenorXL(Linha l, void *menor);

/*Pega o maior x da Linha e armazena em "void *maior". */
void MaiorXL(Linha l, void *maior);

/*Para alterar x1 da Linha*/
void AlterarX1L(Linha l, double x);

/*Para alterar y1 da Linha*/
void AlterarY1L(Linha l, double y);

/*Para alterar x2 da Linha*/
void AlterarX2L(Linha l, double x);

/*Para alterar y2 da Linha*/
void AlterarY2L(Linha l, double y);

/*Funçao para saber se Ponto esta na Linha. Retorna verdadeiro caso esteja.
Fonte de estudos: https://www.jeffreythompson.org/collision-detection/line-circle.php
Estudo sobre Calculo de colisoes entre Linhas e Circulos. Funcoes PontoNaLinha, 
PontoNoCirculo e LinhaDentroCirc foram baseadas nesses estudos para serem desenvolvidas.
*/
bool PontoNaLinha(double x1, double y1, double x2, double y2, double px, double py);

/*Funçao para saber se Ponto esta no Círculo. Retorna verdadeiro caso esteja.
Fonte de estudos: https://www.jeffreythompson.org/collision-detection/line-circle.php
Estudo sobre Calculo de colisoes entre Linhas e Circulos. Funcoes PontoNaLinha, 
PontoNoCirculo e LinhaDentroCirc foram baseadas nesses estudos para serem desenvolvidas.
*/
bool PontoNoCirculo(double px, double py, double cx, double cy, double r);

/*Funçao para saber se a Linha esta Colidindo com o Círculo. Retorna verdadeiro caso esteja.
Fonte de estudos: https://www.jeffreythompson.org/collision-detection/line-circle.php
Estudo sobre Calculo de colisoes entre Linhas e Circulos. Funcoes PontoNaLinha, 
PontoNoCirculo e LinhaDentroCirc foram baseadas nesses estudos para serem desenvolvidas.
*/
bool LinhaDentroCirc(double x1, double y1, double x2, double y2, double cx, double cy, double r);

/*Ve se a Linha foi atingida pela bomba do Caca. */
void ProcuraLinhaCaca(void *arqtxt, Lista Decoracoes, Lista Caca, Lista l, double x, double y, double r);

/*Encontra Linha de Id correspondente.*/
bool AchouIdL(Linha l, void *id);

/*Movimenta dx em x da Linha. Retorna NULL em caso de erro.*/
Linha transladaL(Linha l, void *extra);

#endif