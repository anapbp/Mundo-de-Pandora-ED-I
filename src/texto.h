#ifndef _TEXTOS_
#define _TEXTOS_

#include "fila.h"
#include "lista.h"

typedef void *Texto;
typedef void *Balao;

/* Cria um novo Texto com seus atributos. */
Texto novoTexto(int id, double x1, double y1, char cb[], char cp[], char anc[], char text[], char font_f[], char font_w[], char font_s[]);

/* Funcao para pegar parametro Tipo do Caca. Retorna -1 em caso de erro.
Tipo do Caca é 0 quando ainda nao atirou.*/
int ParamTipo(Texto t);

/*Altera tipo do Caca quando ele é inicializado e vai realizar seu primeiro tiro.*/
void AlteraTipo(Texto t, double novo_tipo);

/* Pega o parametro id do Texto. Retorna -1 em caso de erro*/
int ParamIT(Texto t);

/* Pega o parametro x do Texto. Retorna -1 em caso de erro*/
double ParamXT(Texto t);

/* Pega o parametro y do Texto. Retorna -1 em caso de erro*/
double ParamYT(Texto t);

/*Altera Id do Texto. */
void AlteraIT(Texto t, int novo_i);

/* Altera dx do Texto. */
void AlteraDxT(Texto t, double novo_dx);

/* Altera dy do Texto. */
void AlteraDyT(Texto t, double novo_dy);

/* Pega o parametro graus do Texto. Retorna -1 em caso de erro*/
double ParamGrausT(Texto t);

/* Pega o parametro dx do Texto. Retorna -1 em caso de erro*/
double ParamDxT(Texto t);

/* Pega o parametro dy do Texto. Retorna -1 em caso de erro*/
double ParamDyT(Texto t);

/* Pega o parametro corb do Texto. Retorna NULL em caso de erro*/
char* ParamCbT(Texto t);

/* Pega o parametro corp do Texto. Retorna NULL em caso de erro*/
char* ParamCpT(Texto t);

/* Pega o parametro texto do Texto. Retorna NULL em caso de erro*/
char* ParamTextoT(Texto t);

/* Pega o parametro Font Family do Texto. Retorna NULL em caso de erro*/
char* ParamFFT(Texto t);

/* Pega o parametro Font Size do Texto. Retorna NULL em caso de erro*/
char* ParamFST(Texto t);

/* Pega o parametro Font Weigth do Texto. Retorna NULL em caso de erro*/
char* ParamFWT(Texto t);

/* Pega o parametro ancora do Texto. Retorna NULL em caso de erro*/
char* ParamAncT(Texto t);

/* Pega o parametro Balao do Texto. Retorna NULL em caso de erro*/
Balao ParamBalaoT(Texto t);

/* Altera x do Texto. */
void AlteraXT(Texto t, double novo_x);

/* Altera y do Texto. */
void AlteraYT(Texto t, double novo_y);

/* Altera graus do Texto. */
void AlteraGrausT(Texto t, double novo_grs);

/* Move o Texto e altera o seu x e o seu y. */
void moveTexto(Texto t, double dx, double dy);

/* Rotaciona Texto e altera o seu grau. */
void rotacionaTexto(Texto t, double graus);

/* Cria um balao com atributos raio, profundidade e altura. */
void createBalao(Texto t, double raio, double prof, double a);

/* Altera atributos raio, profundidade e altura do Balao. */
void AlteraBalao(Texto t, double raio, double prof, double a);

/* Pega o parametro raio do Balao. Retorna -1 em caso de erro*/
double ParamRaioB(Texto t);

/* Pega o parametro profundidade do Balao. Retorna -1 em caso de erro*/
double ParamProfB(Texto t);

/* Pega o parametro altura do Balao. Retorna -1 em caso de erro*/
double ParamAltB(Texto t);

/* Pega o parametro Fila do Balao. Retorna NULL em caso de erro*/
Fila ParamFilaB(Texto t, int i);

/* Copia informacoes do Texto. Retorna NULL em caso de erro*/
Texto CopiarT(Texto t);

/* Atribui uma pontuacao para cada texto e adiciona em "void *Soma". */
void PontuacaoT(Texto t, void *Soma);

/* Encontra o menor x e armazena em "void *menor". */
void MenorXT(Texto t, void *menor);

/* Encontra o maior x e armazena em "void *maior". */
void MaiorXT(Texto t, void *maior);

/* Cria um Caca. */
void createCaca(Texto t);

/* Aumenta tiro em +1 do Caca. */
void aumentaTiro(Texto t);

/* Pega o parametro tiros do Caca. Retorna -1 em caso de erro*/
int ParamTiros(Texto t);

/* Pega o parametro identificadores do Caca. Retorna NULL em caso de erro*/
Lista ParamIdentificadores(Texto t);

/*Encontra Texto correspondente ao Id. */
bool AchouIdT(Texto t, void *id);

/*Movimenta dx em x e inverte as cores de Borda e de Preenchimento do Texto. */
Texto transladaT(Texto t, void *extra);

#endif