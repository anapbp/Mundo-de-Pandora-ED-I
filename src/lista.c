#include "lista.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct StNode{
  struct StNode *prox, *ant;
  Item info;
};

struct StLista{
  struct StNode *prim, *ult;
  int capac;
  int length;
};

typedef struct StLista ListaImpl;
typedef struct StNode Node;


struct StIterator{
  Node *curr;
  bool reverso;
};

typedef struct StIterator IteratorImpl;

/** Retorna uma lista vazia. A lista pode definir um limite maximo de 
elementos armazenados (capacidade). Caso capacidade < 0, o tamanho da lista é 
ilimitado */
Lista createLst(int capacidade){
    ListaImpl *newLista = (ListaImpl *) malloc (sizeof(ListaImpl));
    newLista->prim = NULL;
    newLista->ult = NULL;
    newLista->capac = capacidade;
    newLista->length = 0;
    return newLista;
}

/** Retorna o numero de elementos da lista. Retorna -1 em caso de erro.*/
int lengthLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;

  if(lst!=NULL){
    return lst->length;
  } else {
      return -1;
  }
}

/** Retorna a capacidade da lista. Retorna -1, se a capacidade é ilimitada */
int maxLengthLst(Lista L){
    ListaImpl *lst = ( ListaImpl *)L;

  if(lst!=NULL){
    return lst->capac;
  } else {
    return -1;
  }
}

/** Retorna verdadeiro se a lista L estiver vazia */
bool isEmptyLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->length == 0;
}

/** Retorna verdadeiro se a lista L estiver cheia. Ou seja, se a lista
tiver sido criada com uma capacidade máxima e lenght(L) == maxLength(L). */
bool isFullLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->length == lst->capac;
}

/**  Insere o item info no final da lista L. O comprimento da
lista e' acrescido de 1 elemento. 
Retorna um indicador para o elemento acrescentado; ou NIL, se a lista estiver
cheia */
void insertLst(Lista L, Item inf){
  
  ListaImpl *lst = ( ListaImpl *)L;

  if(lst != NULL){
    Node *newNode = (Node *) malloc (sizeof(Node));
    newNode->info = inf;
    newNode->prox = NULL;

      if (isEmptyLst(L)){
        lst->prim = newNode;
      }
      else{
        lst->ult->prox = newNode;
      }
          
    newNode->ant = lst->ult;
    lst->ult = newNode;
    lst->length++;
  }   
}

/** Remove e retorna o primeiro elemento da lista L. 
A lista nao pode  estar vazia */
Item popLst(Lista L){
  ListaImpl *lst = (ListaImpl *)L;
  Item item = lst->prim->info;
  Node *paux;
  paux = lst->prim;
  lst->prim = paux->prox;

  if(paux->prox == NULL){
    // lista vai ficar vazia
    lst->ult = NULL;
  }
  else{
    paux->prox->ant = NULL;
  }

  lst->length--;
  free(paux);
  return item;
}

/** Retorna o indicador do primeiro elemento de L. Se
length(L)=0, retorna NIL. */
Posic getFirstLst(Lista L){
  ListaImpl *lst = (ListaImpl *)L;

    if(lst != NULL){
      return lst->prim;
    } else {
      return NULL;
    }
}


/** Remove o elemento da lista L indicado por p.  
 * p deve indicar um elemento existente em L. O comprimento da lista e' diminuido de 1 elemento. */
void removeLst(Lista L, Posic p){
  ListaImpl *lst = (ListaImpl *)L;

  if(lst != NULL){

    Node *n = (Node *)p;
    
    if (n == NULL) return; //Verifica se a posição é válida

    //Atualiza os ponteiros do nó anterior e posterior
    if (n->ant != NULL) n->ant->prox = n->prox;
    else lst->prim = n->prox;
    
    if (n->prox != NULL) n->prox->ant = n->ant;
    else lst->ult = n->ant;
    
    lst->length--; //Atualiza o tamanho da lista
  }
}

/** Retorna o valor do item da lista indicado por p.
    p deve indicar um elemento existente em L. */
Item getLst(Lista L, Posic p){
  ListaImpl *lst = ( ListaImpl *)L;

    if(lst!=NULL){

      Node *pp = (Node *)p;
      return pp->info;

    } else {

      return NULL;

    }
}

/** Retorna o indicador do elemento de L seguinte ao elemento
indicado por p. Se p for o ultimo elemento da lista, retorna NIL.
p deve indicar um elemento existente em L.*/
Posic getNextLst(Lista L, Posic p){
  ListaImpl *lst = ( ListaImpl *)L;

    if(lst != NULL){

      Node *pp = (Node *)p;
      return pp->prox;

    } else {

      return NULL;
      
    }
}

/** Insere o item info na posicao imediatamente anterior ao
item indicado por p. O comprimento da lista e' acrescido de 1 elemento.
Retorna um indicador para o elemento acrescentado. p deve indicar um 
elemento existente em L.*/
Posic insertBefore(Lista L,Posic p, Item info){
  ListaImpl *lst = (ListaImpl *)L;
  Node *pp = (Node *)p;

  Node *novo;
  novo = (Node *) malloc(sizeof(Node));
  novo->info = info;
  novo->prox = pp;
  novo->ant = pp->ant;
  pp->ant = novo;

    if(novo->ant == NULL){
        lst->prim = novo;
    } else{
        novo->ant->prox = novo;
    }

  lst->length++;
  return novo;
}
 

/** Insere o item info na posicao imediatamente posterior ao
item indicado por p. O comprimento da lista e' acrescido de 1 elemento.
Retorna um indicador para o elemento acrescentado. p deve indicar um 
elemento existente em L.*/
Posic insertAfterLst(Lista L,Posic p, Item info){
  ListaImpl *lst = (ListaImpl *)L;
  Node *pp = (Node *)p;

  Node *novo;
  novo = (Node *) malloc(sizeof(Node));
  novo->info = info;
  novo->prox = pp->prox;
  novo->ant = pp;
  pp->prox = novo;

    if(novo->prox == NULL){
        lst->ult = novo;
    } else{
        novo->prox->ant = novo;
    }

  lst->length++;
  return novo;

}

/** Retorna o indicador do ultimo elemento de L. Se
length(L)=0, retorna NIL.*/
Posic getLastLst(Lista L){
  ListaImpl *lst = (ListaImpl *)L;
  return lst->ult;
}

/** Libera toda memoria alocada pela lista. */
void killLst(Lista L){
  ListaImpl *lst = (ListaImpl *)L;
  Node *curr = lst->prim;

    while(curr != NULL){
      Node *next = curr->prox;
      free(curr);
      curr = next;
    }

  lst->prim = NULL;
  lst->ult = NULL;
  lst->length = 0;
  lst->capac = 0;
}

/* Iterador */

/**
   Retorna um iterador sobre a lista L. 
   O iterador "anda" do inicio ate' o fim, caso reverso for falso;
   do fim para o inicio, se reverso for verdadeiro.
 */
Iterador createIterador(Lista L, bool reverso){
  IteratorImpl* it = (IteratorImpl*) malloc(sizeof(IteratorImpl));
  ListaImpl * lst = (ListaImpl*) L;

  if(lst != NULL){

    it->curr = reverso ? lst->ult : lst->prim;
    it->reverso = reverso;
    return it;

  } else {

    return NULL;

  }
}

/**
   Retorna verdadeiro caso o iterador esteja esgotado,
   i.e., todos os item ja' tenham sido retornados; falso,
   caso contrario.
 */
bool isIteratorEmpty(Lista L, Iterador it){
  if((IteratorImpl*)it!=NULL){
  return ((IteratorImpl*)it)->curr == NULL;
  }
}

/**
   Retorna o proximo item. O iterador nao deve estar esgotado.
   Caso o item retornado seja o ultima, subsequentes invocacoes
   a isIteratorEmpty retornam verdadeiro.
 */
Item getIteratorNext(Lista L, Iterador it){
  IteratorImpl * iter = ((IteratorImpl*)it);

    if(iter!=NULL){

      Node* curr = iter->curr;
      Item item = curr->info;
      iter->curr = iter->reverso ? curr->ant : curr->prox;
      return item;

    } else {

      return NULL;
    }
}

/** Retorna o indicador do elemento de L anterior ao elemento
indicado por p. Se p for o primeiro elemento da lista, retorna NIL.
p deve indicar um elemento existente em L. */
Posic getPreviousLst(Lista L,Posic p){
  ListaImpl *lst = (ListaImpl *)L;
  Node *pp = (Node *)p;

    if(pp == NULL || pp == lst->prim){
        return NULL;
    }
    else{
        return pp->ant;
    }
}

/**
   Libera os recursos usados pelo iterador.
 */
void killIterator(Lista L, Iterador it){
  free((IteratorImpl*)it);
}



 /* High-order functions */
 
 /** Cria uma nova lista. Aplica a funcao f a cada item de L
    e insere o resultado na nova lista.
 */
Lista map(Lista L, Apply f, void *extra){
  ListaImpl *lst = ( ListaImpl *)L;
  ListaImpl *nova = (ListaImpl *)createLst(lst->capac);
  Item novoItem;

  for (Node *curr = lst->prim; curr != NULL; curr = curr->prox){
    novoItem = f(curr->info, extra);
    insertLst(nova,novoItem);
  }

  return nova;
}

/**
   Cria uma nova lista contendo os itens de L para os quais a
   invocacao da funcao f retornar verdeira.
 */
Lista filter(Lista L, Check f, void *extra){
  Lista tempLst = createLst(maxLengthLst(L));

  Iterador it = createIterador(L, false);

  while(!isIteratorEmpty(L, it)){

    Item temp = getIteratorNext(L, it);

      if(f(temp, extra)){
        insertLst(tempLst, temp);
      }
  }

  return tempLst;
}

/**
   Aplica a funcao f a cada elemento de L, possivelmente, atualizando
   o conteudo de c.
 */
void fold(Lista L, ApplyClosure f, Clausura c){
  ListaImpl *lst = ( ListaImpl *)L;
  Item novoItem;

    for (Node *curr = lst->prim; curr != NULL; curr = curr->prox){
        f(curr->info, c);
    }
  
}

int getlengthLst(Lista L){
  ListaImpl *lst = ( ListaImpl *)L;
  return lst->length;
}
