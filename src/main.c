#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "leitura.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "circulo.h"
#include "lista.h"
#include "txt.h"
#include "svg.h"
#include "fila.h"
#include "foto.h"
#include "path.h"
#include "comandos_geo.h" 
#include "comandos_qry.h" 


/*Função para ler arquivo Geo e armazenar as figuras lidas em suas respectivas Listas*/
void processaArquivoGeo(char *arq, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas){
    
    char linha[500], paramI[50];
    char fFamily[50] = "Times New Roman";
    char fWeight[50] = "normal";
    char fSize[50] = "middle";
    char **figura = malloc(sizeof(char *));
    char **comando = malloc(sizeof(char *));

    FILE* arqgeo = abreArquivoCmd(arq);

    while (fgets(linha, 500, arqgeo)){
        
        getParametroI(figura, linha, 1, paramI, 50);
    
        if (strcmp(*figura,"r")==0){ //É retangulo

            ArmazenaRetangulo(Retangulos, comando, linha);

        } else if (strcmp(*figura,"c")==0){ //É circulo
 
            ArmazenaCirculo(Circulos, comando, linha);

        } else if (strcmp(*figura,"ts")==0){ //Pega atributos para texto (fFamily fWeight fSize)

            getParametroI(comando, linha, 2, paramI, 50);
            strcpy(fFamily, *comando);
            getParametroI(comando, linha, 3, paramI, 50);
            strcpy(fWeight, *comando);
            getParametroI(comando, linha, 4, paramI, 50);
            strcpy(fSize, *comando);

        } else if (strcmp(*figura,"l")==0){ //É linha

            ArmazenaLinha(Linhas, comando, linha);

        } else if (strcmp(*figura,"t")==0){ //É texto

            ArmazenaTexto(Textos, comando, linha, fFamily, fWeight, fSize);
        }
    }
    free(figura);
    free(comando);
}


void processaArquivoQry(char* arq, char *txt, char *dft, Lista Circulos, Lista Retangulos, Lista Linhas, Lista Textos, Lista RetCapturas, Lista Decoracoes, Lista Explosoes){

    void **ptr = malloc(sizeof(void *));
    char **comando = malloc(sizeof(char *));
    char **cmd = malloc(sizeof(char *));
    char linha[500], aux[50];

    FILE *arqtxt = abreEscritaTxt(txt);
    FILE* arqqry = abreArquivoCmd(arq);

    while (fgets(linha, 500, arqqry)){
        
        getParametroI(cmd, linha, 1, aux, 50);

        if (strcmp(*cmd,"mv")==0){ //Move figura

            MoveFigura(arqtxt, comando, linha, Circulos, Retangulos, Textos, Linhas);

        } else if (strcmp(*cmd,"g")==0){ //Rotaciona figura

            RotacionaFigura(arqtxt, comando, linha, Circulos, Retangulos, Textos, Linhas);

        } else if (strcmp(*cmd,"ff")==0){ //Ajusta camera do Balao

            AjustarCamera(comando, linha, Circulos, Retangulos, Textos, Linhas);
            
        } else if (strcmp(*cmd,"tf")==0){ //Balao tira foto

            TiraFoto(arqtxt, comando, linha, Circulos, Retangulos, Textos, Linhas, RetCapturas);

        } else if (strcmp(*cmd,"df")==0){ //Download das fotos para a Base
            
            DownloadFoto(arqtxt, dft, comando, linha, Circulos, Retangulos, Textos, Linhas);

        } else if (strcmp(*cmd,"d")==0){ //Caca dispara
 
            DisparoCaca(arqtxt, comando, linha, Circulos, Retangulos, Textos, Linhas, Decoracoes, Explosoes);

        } else if (strcmp(*cmd,"b")==0 || strcmp(*cmd,"b\n")==0 || strcmp(*cmd,"b\0")==0 || strcmp(*cmd,"b/0")==0){
            //Reporta atributos dos Baloes existentes
            ReportaBaloes(arqtxt, comando, linha, Textos);

        } else if (strcmp(*cmd,"c")==0 || strcmp(*cmd,"c\n")==0 || strcmp(*cmd,"c/0")==0 || strcmp(*cmd,"c\0")==0){
            //Reporta atributos dos Cacas existentes
            ReportaCacas(arqtxt, comando, linha, Textos);
        }
    }

    free(ptr);
    free(cmd);
    free(comando);
    fechaArquivoCmd(arqqry);
    fechaTxt(arqtxt);
}

int main(int argc, char *argv[]) {

    Lista Circulos = createLst(-1);
    Lista Retangulos = createLst(-1);
    Lista Linhas = createLst(-1);
    Lista Textos = createLst(-1);
    Lista RetCapturas = createLst(-1);
    Lista Decoracoes = createLst(-1);
    Lista Explosoes = createLst(-1);
    char *entrada, *saida, *arqgeo, *arqqry, *nomeGeo, *nomeQry, *caminhoGeo, *caminhoQry, *caminhoTxt, *caminhoSvg, *arqfotos;
    char nomeFt[200];

    //Analisa se é -e -f -q -o
    AnalisaIdentificador(argc, &entrada, &saida, &arqqry, &arqgeo, argv);

    nomeGeo = malloc(strlen(arqgeo) * sizeof(char));
    PegarNome(arqgeo, &nomeGeo);

    if(arqqry != NULL){

        nomeQry = malloc(strlen(arqqry) * sizeof(char));
        PegarNome(arqqry, &nomeQry);

    }

    if(entrada != NULL){

            caminhoGeo = malloc((strlen(entrada) + strlen(arqgeo) + 202) * sizeof(char));
            caminhoSvg = malloc((strlen(saida) + strlen(nomeGeo) + 202) * sizeof(char));
            caminhoTxt = malloc((strlen(saida) + strlen(nomeGeo) + 202) * sizeof(char));
            NormalizaPath(entrada, arqgeo, &caminhoGeo);
            NormalizaPath(saida, nomeGeo, &caminhoSvg);
            NormalizaPath(saida, nomeGeo, &caminhoTxt);

            //Lendo arquivo Geo e armazenando figuras no Banco de Dados
            processaArquivoGeo(caminhoGeo, Circulos, Retangulos, Textos, Linhas);

        if(arqqry!=NULL){

            caminhoQry = malloc((strlen(entrada) + strlen(arqqry) + 2) * sizeof(char));
            NormalizaPath(entrada, arqqry, &caminhoQry);
            sprintf(nomeFt, "%s-%s", nomeGeo, nomeQry);
            arqfotos = malloc((strlen(saida) + strlen(nomeFt) + 2) * sizeof(char));
            NormalizaPath(saida, nomeFt, &arqfotos);

            sprintf(caminhoSvg, "%s-%s.svg", caminhoSvg, nomeQry);
            sprintf(caminhoTxt, "%s-%s.txt", caminhoTxt, nomeQry);

            //Lendo consulta qry e realizando seus comandos
            processaArquivoQry(caminhoQry, caminhoTxt, arqfotos, Circulos, Retangulos, Linhas, Textos, RetCapturas, Decoracoes, Explosoes);
        } else{
            sprintf(caminhoSvg, "%s.svg", caminhoSvg);
            sprintf(caminhoTxt, "%s.txt", caminhoTxt);
        }

    } else {
        
        caminhoSvg = malloc((strlen(saida) + strlen(nomeGeo) + 202) * sizeof(char));
        caminhoTxt = malloc((strlen(saida) + strlen(nomeGeo) + 202) * sizeof(char));
        NormalizaPath(saida, nomeGeo, &caminhoSvg);
        NormalizaPath(saida, nomeGeo, &caminhoTxt);

        //Lendo arquivo Geo e armazenando figuras no Banco de Dados
        processaArquivoGeo(arqgeo, Circulos, Retangulos, Textos, Linhas);

        if(arqqry!=NULL){

            sprintf(nomeFt, "%s-%s", nomeGeo, nomeQry);
            arqfotos = malloc((strlen(saida) + strlen(nomeFt) + 2) * sizeof(char));
            NormalizaPath(saida, nomeFt, &arqfotos);

            sprintf(caminhoSvg, "%s-%s.svg", caminhoSvg, nomeQry);
            sprintf(caminhoTxt, "%s-%s.txt", caminhoTxt, nomeQry);

            //Lendo consulta qry e realizando seus comandos
            processaArquivoQry(arqqry, caminhoTxt, arqfotos, Circulos, Retangulos, Linhas, Textos, RetCapturas, Decoracoes, Explosoes);
        } else {
            sprintf(caminhoSvg, "%s.svg", caminhoSvg);
            sprintf(caminhoTxt, "%s.txt", caminhoTxt);
        }

    }
    
    //Escrevendo SVG final.
    FILE * arqsvg = abreEscritaSvg(caminhoSvg);

    fold(Circulos, CirculoSvg, arqsvg);  
    fold(Linhas, LinhaSvg, arqsvg);  
    fold(Retangulos, RetanguloSvg, arqsvg);  
    fold(Textos, TextoSvg, arqsvg); 
    fold(RetCapturas, escreveRetanguloCapturaSvg, arqsvg); 
    fold(Decoracoes, TextoSvg, arqsvg);
    fold(Explosoes, CirculoSvg, arqsvg);  

    fechaSvg(arqsvg);
    return 0;
}