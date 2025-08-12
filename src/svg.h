#ifndef ARQSVG__
#define ARQSVG__

#include <stdio.h>
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "circulo.h"

/*
  Provê operações para escrita de arquivos básicos no formato SVG.

  O arquivo deve ser criado por abreEscritaSvg. A seguir, círculos,
retângulos, linhas e textos podem ser acrescentados ao arquivo.

  Por fim, o arquivo deve ser fechado por meio da operacao fechaSvg.
Note que nao existem operacoes para modificacao de um arquivo existente.
*/

typedef void *ArqSvg;

/*
  Cria o arquivo "fn" para escrita. Substitui o arquivo, caso exista.
  Retorna NULL, caso nao tenha sido possivel criar arquivo.
 */
FILE* abreEscritaSvg(char *fn);

/* Escreve Retangulo da Captura realizada pela Camera.*/
void escreveRetanguloCapturaSvg(Retangulo ret, void* fsvg);

/*Escreve Texto Svg. */
void TextoSvg(Texto t, void* fsvg);

/*Escreve Texto Svg com parametros.*/
void escreveTextoFTSvg(void* fsvg, double x, double y, char corb[], char corp[], char anc[], char text[], double grs, char ff[], char fw[], char fs[]);

/*Escreve Retangulo Svg. */
void RetanguloSvg(Retangulo ret, void *fsvg);

/*Escreve Retangulo Svg com parametros */
void escreveRetanguloFTSvg(void* fsvg, double x, double y, double larg, double alt, char corp[], char corb[], double grs);

/*Escreve Circulo Svg */
void CirculoSvg(Circulo cir, void* fsvg);

/*Escreve Circulo Svg com parametros */
void escreveCirculoFTSvg(void* fsvg, double xc, double yc, double r, char corb[], char corp[], double grs);

/*Escreve Linha Svg */
void LinhaSvg(Linha l, void* fsvg);

/*Escreve Linha Svg com parametros */
void escreveLinhaFTSvg(void* fsvg, double x1, double y1, double x2, double y2, char cor[], double grs);

/* Fecha o arquivo fsvg. */
void fechaSvg(ArqSvg fsvg);

#endif