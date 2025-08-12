#ifndef _COMANDOSGEO_
#define _COMANDOSGEO_

#include "lista.h"

/* Funcoes para ajudar a manipular o arquivo .geo. */

/* Armazena um retangulo em sua respectiva Lista. */
void ArmazenaRetangulo(Lista Retangulos, char **comando, char *linha);

/* Armazena um circulo em sua respectiva Lista. */
void ArmazenaCirculo(Lista Circulos, char **comando, char *linha);

/* Armazena uma linha em sua respectiva Lista. */
void ArmazenaLinha(Lista Linhas, char **comando, char *linha);

/* Armazena um texto em sua respectiva Lista*/
void ArmazenaTexto(Lista Textos, char **comando, char *linha, char fFamily[], char fWeight[], char fSize[]);

#endif