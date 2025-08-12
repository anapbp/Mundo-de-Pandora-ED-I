#ifndef _COMANDOSQRY_
#define _COMANDOSQRY_

#include <stdio.h>
#include "lista.h"

/* Funcoes auxiliares para manipular arquivo .qry */

/*Função auxiliar para procurar elemento nas Listas das Figuras. Retorna:
1 para identidade i correspondente a um circulo;
2 para identidade i correspondente a um retangulo;
3 para identidade i correspondente a uma Linha;
4 para identidade i correspondente a um Texto;
5 para caso não encontre nada*/
int Tipo(int i, void **pt, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas);

/* ["mv" comando] Move a figura em dx e dy. */
void MoveFigura(FILE *arqtxt, char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas);

/* ["g" comando] Rotaciona a figura em determinados graus. */
void RotacionaFigura(FILE *arqtxt, char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas);

/* ["ff" comando] Ajusta a Camera */
void AjustarCamera(char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas);

/* ["tf" comando] Tira foto */
void TiraFoto(FILE *arqtxt, char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas, Lista RetCapturas);

/* ["df" comando] Faz Download da foto. */
void DownloadFoto(FILE *arqtxt, char *dft , char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas);

/* ["d" comando] Um Caca realiza um disparo de capacidade A, B ou C. */
void DisparoCaca(FILE *arqtxt, char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas, Lista Decoracoes, Lista Explosoes);

/* ["b?" comando] Reporta informacoes de todos os Baloes existentes */
void ReportaBaloes(FILE *arqtxt, char **comando, char *linha, Lista Textos);

/* ["c?" comando] Reporta informacoes de todos os Cacas existentes */
void ReportaCacas(FILE *arqtxt, char **comando, char *linha, Lista Textos);

#endif