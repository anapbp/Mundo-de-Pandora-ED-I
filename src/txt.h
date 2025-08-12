#ifndef ARQTXT__
#define ARQTXT__

#include <stdio.h>
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"

typedef void *ArqTxt;

/*
  Cria o arquivo "fn" para escrita. Substitui o arquivo, caso exista.
  Retorna NULL, caso nao tenha sido possivel criar arquivo.
 */
FILE* abreEscritaTxt(char *fn);

/* Escreve dx e dy do Retangulo. */
void RetTfTxt(Retangulo Ret, void* ftxt);

/* Escreve dx e dy do Texto. */
void TextoTfTxt(Texto t, void* ftxt);

/* Escreve dx e dy da Linha. */
void LinhaTfTxt(Linha l, void* ftxt);

/* Escreve dx e dy do Circulo. */
void CircTfTxt(Circulo cir, void* ftxt);

/* Escreve atributos do Texto. */
void TextoTxt(Texto t, void* ftxt);

/* Escreve atributos do Circulo. */
void CirculoTxt(Circulo c, void* ftxt);

/* Escreve atributos do Retangulo. */
void RetanguloTxt(Retangulo r, void* ftxt);

/* Escreve atributos da Linha. */
void LinhaTxt(Linha l, void* ftxt);

/* Fecha o arquivo fsvg. */
void fechaTxt(ArqTxt ftxt);

#endif