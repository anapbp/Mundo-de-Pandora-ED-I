#ifndef _FOTOS_
#define _FOTOS_

#include "lista.h"

typedef void *Foto;

/* Cria uma foto com raio, profundiade e altura (atributos da camera na hora que fotografou). */
Foto createFoto(double r, double p, double a);

/* Pega Lista dos Retangulos contidos na foto. Retorna NULL em caso de erro.*/
Lista GetListRet(Foto f);

/* Pega Lista das Linhas contidas na foto. Retorna NULL em caso de erro.*/
Lista GetListLin(Foto f);

/* Pega Lista dos Textos contidos na foto. Retorna NULL em caso de erro.*/
Lista GetListTxt(Foto f);

/* Pega Lista dos Circulos contidos na foto. Retorna NULL em caso de erro.*/
Lista GetListCirc(Foto f);

/* Pega informacao do y menor da foto. Retorna -1 em caso de erro.*/
double GetYme(Foto f);

/* Pega informacao do y maior da foto. Retorna -1 em caso de erro.*/
double GetYma(Foto f);

/* Pega informacao do x menor da foto. Retorna -1 em caso de erro.*/
double GetXme(Foto f);

/* Pega informacao do x maior da foto. Retorna -1 em caso de erro.*/
double GetXma(Foto f);

/* Pega informacao do raio da foto. Retorna -1 em caso de erro.*/
double GetRaioFt(Foto f);

/* Pega informacao da profundidade da foto. Retorna -1 em caso de erro.*/
double GetProfFt(Foto f);

/* Pega informacao da altura da foto. Retorna -1 em caso de erro.*/
double GetAltFt(Foto f);

/* Altera o x menor da foto. */
void alterarXme(Foto f, double novo_xme);

/* Altera o x maior da foto. */
void alterarXma(Foto f, double novo_xma);

/* Procura os Textos que foram fotografados. */
void ProcuraTxt(Lista Tfoto, Lista t, double x, double y, double r, double a, double p);

/* Analisa se duas linhas se encontram. Retorna verdadeiro se elas se colidem.
Fonte de estudos: https://www.jeffreythompson.org/collision-detection/line-rect.php.
Usado para estudo de colisao de Linhas e Retangulos, entrando também estudos sobre colisoes
de Linhas com Linhas. Funções ColideLinha e ColideLinhaRetangulo foram baseadas neste site 
para desenvolvimento.
*/
bool ColideLinha(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

/* Analisa se ha Linha dentro do Retangulo. Retorna verdadeiro se tiver.
Fonte de estudos: https://www.jeffreythompson.org/collision-detection/line-rect.php.
Usado para estudo de colisao de Linhas e Retangulos, entrando também estudos sobre colisoes
de Linhas com Linhas. Funções ColideLinha e ColideLinhaRetangulo foram baseadas neste site 
para desenvolvimento.
*/
bool ColideLinhaRetangulo(double x1, double y1, double x2, double y2, double rx, double ry, double rw, double rh);

/* Analisa se tem algum Retangulo dentro da foto. */
void ProcuraRet(Lista Tfoto, Lista t, double xb, double yb, double rb, double hb, double pb);

/* Analisa se tem alguma Linha dentro da foto. */
void ProcuraLin(Lista Lin, Lista t, double xb, double yb, double rb, double hb, double pb);

/* Analisa se tem algum Circulo dentro da foto. */
void ProcuraCirc(Lista Circ, Lista t, double x, double y, double r, double a, double p);

#endif