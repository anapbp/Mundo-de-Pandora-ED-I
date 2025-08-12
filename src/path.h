#ifndef PATH__
#define PATH__

/* Funcoes para ler argc e argv*/

/* Analisa se é -e -f -o ou -q e atribui seus valores nas variaveis correspondentes.*/
void AnalisaIdentificador(int argc, char **entrada, char **saida, char **arqqry, char **arqgeo, char *argv[]);

/*Pega somente o nome do seu arquivo. Exemplo: blabla/teste.geo ==> teste*/
void PegarNome(char *arquivo, char **nomeArq);

/*Junta o caminho com o arquivo e adiciona / se necessário. */
void NormalizaPath(char *arquivo, char *nomeArq, char **Normalizado);

#endif