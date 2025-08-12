#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "linha.h"
#include "texto.h"
#include "lista.h"
#include "txt.h"
#include "svg.h" 
 
struct StLinha{
  int i;
  double x1, y1 , x2, y2, grs, dx, dy;
  char cor[50];
};

typedef struct StLinha LinhaImpl;

/*Cria uma linha para os parametros i x1 y1 x2 y2 cor e graus. Graus inicia em 0*/
Linha novaLinha(int id, double xx1, double yy1, double xx2, double yy2, char corr[]){
    LinhaImpl *novo = malloc(sizeof(LinhaImpl));
    novo->i = id;
    novo->x1 = xx1;
    novo->y1 = yy1;
    novo->x2 = xx2;
    novo->y2 = yy2;
    novo->grs = 0;
    strcpy(novo->cor, corr);

    return novo;
}

/*Pegar parametro i da Linha. Retorna -1 em caso de erro.*/
int ParamIdL(Linha l){
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    return linha->i;
  } else {
    return -1;
  }
}

/*Pegar parametro x1 da Linha. Retorna -1 em caso de erro.*/
double ParamX1L(Linha l){
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    return linha->x1;
  } else{
    return -1;
  }
}

/*Pegar parametro y1 da Linha. Retorna -1 em caso de erro.*/
double ParamY1L(Linha l){
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    return linha->y1;
  } else {
    return -1;
  }
}

/*Pegar parametro x2 da Linha. Retorna -1 em caso de erro.*/
double ParamX2L(Linha l){
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    return linha->x2;
  } else {
    return -1;
  }
}

/*Pegar parametro y2 da Linha. Retorna -1 em caso de erro.*/
double ParamY2L(Linha l){
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    return linha->y2;
  } else {
    return -1;
  }
}

/*Pegar parametro graus da Linha. Retorna -1 em caso de erro.*/
double ParamGrausL(Linha l){
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    return linha->grs;
  } else {
    return -1;
  }
}

/*Pegar parametro dx da Linha. Retorna -1 em caso de erro.*/
double ParamDxL(Linha l){
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    return linha->dx;
  } else {
    return -1;
  }
}

/*Pegar parametro dy da Linha. Retorna -1 em caso de erro.*/
double ParamDyL(Linha l){
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    return linha->dy;
  } else {
    return -1;
  }
}

/*Pegar parametro cor da Linha. Retorna NULL em caso de erro.*/
char* ParamCorL(Linha l){
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    return linha->cor;
  } else {
    return NULL;
  }
}

/*Alterar graus da Linha*/
void AlterarGrausL(Linha l, double graus) {
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    linha->grs = graus;
  } 
}

/*Alterar dx da Linha*/
void AlterarDxL(Linha l, double new_dx) {
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    linha->dx = new_dx;
  }
}

/*Alterar dy da Linha*/
void AlterarDyL(Linha l, double new_dy) {
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    linha->dy = new_dy;
  }
}

/*Mover a Linha em dx e dy*/
void MoverLinha(Linha l, double dx, double dy){
    LinhaImpl* linha = (LinhaImpl*) l;
    if(linha != NULL){
      linha->x1 += dx;
      linha->y1 += dy;
      linha->x2 += dx;
      linha->y2 += dy;
    }
}

/*Rotaciona a Linha em graus*/
void rotacionaLinha(Linha l, double grs){
  double auxg;
  if(l != NULL){
    auxg = ParamGrausL(l);
    auxg = auxg + grs;
    
    AlterarGrausL(l, auxg);
  } 
}

/*Copia informacoes da Linha. Retorna NULL em caso de erro.*/
Linha CopiarL(Linha l){
  LinhaImpl* linha = (LinhaImpl*) l;

  if(linha != NULL){

    LinhaImpl *novo = malloc(sizeof(LinhaImpl));
    novo->i = ParamIdL(linha);
    novo->x1 = ParamX1L(linha);
    novo->y1 = ParamY1L(linha);
    novo->x2 = ParamX2L(linha);
    novo->y2 = ParamY2L(linha);
    novo->grs = ParamGrausL(linha);
    strcpy(novo->cor,ParamCorL(linha));

    return novo;

  } else {

    return NULL;

  }
}

/*Atribui uma pontuacao para cada Linha e armazna em "void *Soma". */
void PontuacaoL(Linha l, void *Soma){

  if(l != NULL){
    double aux = sqrt((ParamX2L(l) - ParamX1L(l)) * (ParamX2L(l) - ParamX1L(l)) + (ParamY2L(l) - ParamY1L(l)) * (ParamY2L(l) - ParamY1L(l)));
    
    if(!strcmp(ParamCorL(l), "#FFFF00")){
      
      aux = aux * 3;

    } else if(!strcmp(ParamCorL(l), "#DDFF55")){
      
      aux = aux * 2;

    } else if(!strcmp(ParamCorL(l), "#0000FF")){
      
      aux = aux * 4;

    }

    * (double*) Soma += aux;
  }
}

/*Para alterar Id da Linha*/
void AlteraIL(Linha l, int novo_i) {
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    linha->i = novo_i;
  }
}

/*Para alterar x1 da Linha*/
void AlterarX1L(Linha l, double x) {
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    linha->x1 = x;
  }
}

/*Para alterar y1 da Linha*/
void AlterarY1L(Linha l, double y) {
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    linha->y1 = y;
  }
}

/*Para alterar x2 da Linha*/
void AlterarX2L(Linha l, double x) {
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    linha->x2 = x;
  }
}

/*Para alterar y2 da Linha*/
void AlterarY2L(Linha l, double y) {
  LinhaImpl* linha = (LinhaImpl*) l;
  if(linha != NULL){
    linha->y2 = y;
  }
}

/*Pega o menor x da Linha e armazena em "void *menor". */
void MenorXL(Linha l, void *menor){

  if(l != NULL){

    if(ParamDxL(l)< *(double*)menor){

      *(double*)menor = ParamDxL(l);

    } else if(ParamX2L(l) - ParamX1L(l) + ParamDxL(l)< *(double*)menor){

      *(double*)menor = ParamX2L(l) - ParamX1L(l) + ParamDxL(l);
    }

  }
}

/*Pega o maior x da Linha e armazena em "void *maior". */
void MaiorXL(Linha l, void *maior){

  if(l != NULL){

    if(ParamDxL(l)> *(double*)maior){

      *(double*)maior = ParamDxL(l);

    } else if(ParamX2L(l) - ParamX1L(l) + ParamDxL(l)> *(double*)maior){

      *(double*)maior = ParamX2L(l) - ParamX1L(l) + ParamDxL(l);
    }

  }
}

/*Funçao para saber se Ponto esta na Linha. Retorna verdadeiro caso esteja.
Fonte de estudos: https://www.jeffreythompson.org/collision-detection/line-circle.php
Estudo sobre Calculo de colisoes entre Linhas e Circulos. Funcoes PontoNaLinha, 
PontoNoCirculo e LinhaDentroCirc foram baseadas nesses estudos para serem desenvolvidas.
*/
bool PontoNaLinha(double x1, double y1, double x2, double y2, double PontoX, double PontoY) {

  //Calculando a distancia entre os dois pontos da Linha;
  double dist1, dist2, tamanho;
  dist1 = sqrt((PontoX - x1) * (PontoX - x1) + (PontoY - y1) * (PontoY - y1));
  dist2 = sqrt((PontoX - x2) * (PontoX - x2) + (PontoY - y2) * (PontoY - y2));

  //Calculando tamanho da Linha
  tamanho = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

  double buffer = 0.1;

  /*Caso as duas distancias forem iguais ao tamanho da Linha, o ponto está na Linha*/
  if (dist1 + dist2 >= tamanho - buffer && dist1 + dist2 <= tamanho + buffer) {

    return true; //Retorna verdadeiro

  }

  return false; //Caso contrário, retorna falso.
}

/*Funçao para saber se Ponto esta no Círculo. Retorna verdadeiro caso esteja.
Fonte de estudos: https://www.jeffreythompson.org/collision-detection/line-circle.php
Estudo sobre Calculo de colisoes entre Linhas e Circulos. Funcoes PontoNaLinha, 
PontoNoCirculo e LinhaDentroCirc foram baseadas nesses estudos para serem desenvolvidas.
*/
bool PontoNoCirculo(double PontoX, double PontoY, double CircX, double CircY, double Raio) {

  double distX, distY, distancia;
  //Calculando a distancia entre o Ponto e o Centro do Círculo
  distX = PontoX - CircX;
  distY = PontoY - CircY;
  distancia = sqrt((distX * distX) + (distY * distY));

 //Caso a distancia seja menor do que o Raio do Círculo, então está dentro.
  if (distancia <= Raio) {

    return true; //Retorna Verdadeiro

  }

  return false; //Caso contrario, retorna falso
}

/*Funçao para saber se a Linha esta Colidindo com o Círculo. Retorna verdadeiro caso esteja.
Fonte de estudos: https://www.jeffreythompson.org/collision-detection/line-circle.php
Estudo sobre Calculo de colisoes entre Linhas e Circulos. Funcoes PontoNaLinha, 
PontoNoCirculo e LinhaDentroCirc foram baseadas nesses estudos para serem desenvolvidas.
*/
bool LinhaDentroCirc(double x1, double y1, double x2, double y2, double CircX, double CircY, double Raio) {

  double distX, distY, tamanho, distancia, aux, pertoX, pertoY;
  //Analisando se extremidades da Linha esta dentro do Circulo
  bool dentro1 = PontoNoCirculo(x1, y1, CircX, CircY, Raio);
  bool dentro2 = PontoNoCirculo(x2, y2, CircX, CircY, Raio);

  if (dentro1 || dentro2) {
    return true;
  }

  //Calculando a distancia entre os dois pontos
  distX = x1 - x2;
  distY = y1 - y2;
  tamanho = sqrt( (distX * distX) + (distY * distY) );

  aux = (((CircX - x1) * (x2 - x1)) + ((CircY - y1) * (y2 - y1)))/pow(tamanho, 2);

  //Calculando o ponto da linha mais proximo do centro do circulo
  pertoX = x1 + (aux * (x2 - x1));
  pertoY = y1 + (aux * (y2 - y1));

  //Analisar se o ponto esta sobre a Linha
  bool NaLinha = PontoNaLinha(x1, y1, x2, y2, pertoX, pertoY);

  if (!NaLinha) {
    return false;
  }

  //Calculando distancia até o ponto mais próximo
  distX = pertoX - CircX;
  distY = pertoY - CircY;
  distancia = sqrt( (distX * distX) + (distY * distY) );

  if (distancia <= Raio) {

    return true; //Retorna verdadeiro

  }

  return false; //Retorna falso

}

/*Ve se a Linha foi atingida pela bomba do Caca. */
void ProcuraLinhaCaca(void *arqtxt, Lista Decoracoes, Lista Caca, Lista l, double x, double y, double r){

  Item info;
  Posic posicao = getFirstLst(l);
    
  while(posicao != NULL){

    info = getLst(l, posicao);

    if(info == NULL){

      break;

    } else {

      if(LinhaDentroCirc(ParamX1L(info), ParamY1L(info), ParamX2L(info), ParamY2L(info), x, y, r)){

        int *ptr = malloc(sizeof(int));
        *ptr = ParamIC(info);
        //Linha foi atingida pela Bomba
        LinhaTxt(info, arqtxt);
        insertLst(Caca, (Item) ptr);
        removeLst(l, posicao); //Removendo Linha do banco de Dados
        
        Texto t = novoTexto(1, ParamX1L(info), ParamY1L(info), "#FF0000", "#FF0000", "middle", "x", "normal", "normal", "middle");
        insertLst(Decoracoes, t); //Inserindo decoracao X na ancora x1 y1 da Linha atingida
      } 

      posicao = getNextLst(l, posicao);

    }
  }
}

/*Encontra Linha de Id correspondente.*/
bool AchouIdL(Linha l, void *id){
    return (ParamIdL(l) == *(int*)id);
}

/*Movimenta dx em x da Linha. Retorna NULL em caso de erro.*/
Linha transladaL(Linha l, void *extra){
  LinhaImpl* linha = (LinhaImpl*) l;

  if(linha != NULL){

    LinhaImpl *novo = malloc(sizeof(LinhaImpl));
    novo->i = ParamIdL(linha);
    novo->x1 = ParamX1L(linha) + *(double*) extra;
    novo->y1 = ParamY1L(linha);
    novo->x2 = ParamX2L(linha) + *(double*) extra;
    novo->y2 = ParamY2L(linha);
    novo->grs = ParamGrausL(linha);
    strcpy(novo->cor,ParamCorL(linha));

    return novo;

  } else {

    return NULL;

  }
}