#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

struct FlFila {
	int capacidade, prim, ult, quantidade;
	ItemF *it;
};

typedef struct FlFila FilaImpl;

/* Cria Fila */
Fila createFila(int c){ 
	FilaImpl *new = (FilaImpl *) malloc (sizeof(FilaImpl));
	new->capacidade = c;
	new->quantidade = 0;
	new->prim = 0;
	new->ult = -1;
	new->it = (ItemF*) malloc (new->capacidade * sizeof(ItemF));
	return new;
}

/* Insere elemento na Fila */
void insereFila(Fila f, ItemF v){
	FilaImpl *fl = (FilaImpl*) f;

	if(fl!=NULL){

		if(fl->ult == fl->capacidade-1)
			fl->ult = -1;

		fl->ult++;
		fl->it[fl->ult] = v; //Incrementa ultimo elemento e insere
		fl->quantidade++; //Mais um item inserido
	}
}

/* Remove elemento da fila e o retorna. Retorna NULL em caso de erro.*/
ItemF removeFila(Fila f){ //Pega o item do começo da fila
	FilaImpl *fl = (FilaImpl*) f;
	if(fl!=NULL){
		ItemF temp = fl->it[fl->prim++]; //Pega o valor e incrementa o primeiro

		if(fl->prim == fl->capacidade)
			fl->prim = 0;

		fl->quantidade--;  //Um item retirado
		return temp;
	} else {
		return NULL;
	}
}

/** Retorna verdadeiro se a fila está vazia */
bool FilaEmpty(Fila f){ 
    FilaImpl* fl = (FilaImpl*) f;
	if(fl==NULL){
		return true;
	}
	return (fl->quantidade == 0);
}

/** Retorna verdadeiro se a fila está cheia */
bool FilaFull(Fila f){ 
    FilaImpl* fl = (FilaImpl*) f;
	
	if (fl == NULL || fl->capacidade <= 0) {
        return false;
    }
	
	return (fl->quantidade == fl->capacidade);

}

/* Retorna a quantidade de elementos na Fila. Retorna -1 em caso de erro.*/
int ParamQtddFila(Fila f){
    FilaImpl* fl = (FilaImpl*) f;
	if(fl!=NULL){
		return fl->quantidade;
	} else {
		return -1;
	}
}