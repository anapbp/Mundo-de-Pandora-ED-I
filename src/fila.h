#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

typedef void *Fila;
typedef void *ItemF;

/* Cria Fila. */
Fila createFila(int c);

/* Insere elemento na Fila */
void insereFila(Fila f, ItemF v);

/* Remove elemento da fila e o retorna. Retorna NULL em caso de erro. */
ItemF removeFila(Fila f);

/* Retorna verdadeiro se a Fila f estiver vazia */
bool FilaEmpty(Fila f);

/* Retorna verdadeiro se a Fila f estiver cheia */
bool FilaFull(Fila f);

/* Retorna a quantidade de elementos na Fila. Retorna -1 em caso de erro.*/
int ParamQtddFila(Fila f);

#endif