#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "circulo.h"
#include "svg.h"


typedef void *ArqSvg;

/*
  Cria o arquivo "fn" para escrita. Substitui o arquivo, caso exista, e retorna 0.
  Retorna 1, caso nao tenha sido possivel criar arquivo.
 */
FILE *abreEscritaSvg(char *fn){
    FILE *arquivo = fopen(fn, "w");
    
    if(arquivo == NULL){
        printf("nao foi possivel criar arquivo\n");
        return NULL;
    } else {
        fprintf(arquivo, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\"	xmlns=\"http://www.w3.org/2000/svg\"	version=\"1.1\">\n");
        return arquivo;
    }

}

/* Escreve Retangulo da Captura realizada pela Camera.*/
void escreveRetanguloCapturaSvg(Retangulo ret, void* fsvg){
  if(ret!=NULL){
   double x = ParamX1R(ret);
   double y = ParamY1R(ret); 
   double larg = ParamW1R(ret);
   double alt = ParamH1R(ret);
        
    fprintf((FILE*)fsvg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" style=\"stroke:Red; fill:none; stroke-dasharray:5;\" />\n", x, y, larg, alt);
    return;
  }
}

/*Escreve Texto Svg. */
void TextoSvg(Texto t, void* fsvg){
  if(t!=NULL){

    double x = ParamXT(t);
    double y = ParamYT(t);
    double grs = ParamGrausT(t);
    char corb[50], corp[50], anc[50], text[50], ff[50], fs[50], fw[50];
    char *cb = ParamCbT(t);
    char *cp = ParamCpT(t);
    char *a = ParamAncT(t);
    char *txto = ParamTextoT(t);
    strcpy(corb, cb);
    strcpy(corp, cp);
    strcpy(anc, a);
    strcpy(text, txto);
    strcpy(ff, ParamFFT(t));
    strcpy(fs, ParamFST(t));
    strcpy(fw, ParamFWT(t));
    
    fprintf((FILE*)fsvg, "\t<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" transform=\"rotate(%lf, %lf, %lf)\" text-anchor=\"%s\" font-family=\"%s\" font-weight=\"%s\" font-size=\"%s\">%s</text>\n", x, y, corp, corb, grs, x, y, anc, ff, fw, fs, text);
    return;
  }
}

/*Escreve Texto Svg com parametros.*/
void escreveTextoFTSvg(void* fsvg, double x, double y, char corb[], char corp[], char anc[], char text[], double grs, char ff[], char fw[], char fs[]){
  fprintf((FILE*)fsvg, "\t<text x=\"%lf\" y=\"%lf\" fill=\"%s\" stroke=\"%s\" transform=\"rotate(%lf, %lf, %lf)\" text-anchor=\"%s\" font-family=\"%s\" font-weight=\"%s\" font-size=\"%s\">%s</text>\n", x, y, corp, corb, grs, x, y, anc, ff, fw, fs, text);
  return;
}

/*Escreve Retangulo Svg. */
void RetanguloSvg(Retangulo ret, void *fsvg){
  if(ret!=NULL){
    double x = ParamX1R(ret);
    double y = ParamY1R(ret);
    double larg = ParamW1R(ret); 
    double alt = ParamH1R(ret); 
    double grs = ParamGrausR(ret);
    char corp[50], corb[50];
    char *cb = ParamCbR(ret);
    char *cp = ParamCpR(ret);
    strcpy(corb, cb);
    strcpy(corp, cp);

    fprintf((FILE*)fsvg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" transform=\"rotate(%lf, %lf, %lf\" fill=\"%s\" stroke=\"%s\" />\n", x, y, larg, alt, grs, x, y, corp, corb);
  }
  return;
}

/*Escreve Retangulo Svg com parametros */
void escreveRetanguloFTSvg(void* fsvg, double x, double y, double larg, double alt, char corp[], char corb[], double grs){

    fprintf((FILE*)fsvg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" transform=\"rotate(%lf, %lf, %lf\" fill=\"%s\" stroke=\"%s\" />\n", x, y, larg, alt, grs, x, y, corp, corb);
    return;
}

/*Escreve Circulo Svg */
void CirculoSvg(Circulo cir, void* fsvg){
  if(cir!=NULL){
    double xc = ParamXC(cir);
    double yc = ParamYC(cir);
    double r = ParamRaioC(cir);
    double grs = ParamGrausC(cir);
    char *cb = ParamCbC(cir);
    char *cp = ParamCpC(cir);
    char corb[50], corp[50];
    strcpy(corb, cb);
    strcpy(corp, cp);

    fprintf((FILE*)fsvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" transform=\"rotate(%lf, %lf, %lf\" stroke=\"%s\" fill=\"%s\" />\n", xc, yc, r, grs, xc, yc, corb, corp);
  }
  return;
}

/*Escreve Circulo Svg com parametros */
void escreveCirculoFTSvg(void* fsvg, double xc, double yc, double r, char corb[], char corp[], double grs){

    fprintf((FILE*)fsvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" transform=\"rotate(%lf, %lf, %lf\" stroke=\"%s\" fill=\"%s\" />\n", xc, yc, r, grs, xc, yc, corb, corp);
    return;
}

/*Escreve Linha Svg */
void LinhaSvg(Linha l, void* fsvg){
  if(l!=NULL){
    double x1 = ParamX1L(l);
    double y1 = ParamY1L(l);
    double x2 = ParamX2L(l);
    double y2 = ParamY2L(l);
    double grs = ParamGrausL(l);
    char *c = ParamCorL(l);
    char cor[50];
    strcpy(cor, c);

    fprintf((FILE*)fsvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" transform=\"rotate(%lf, %lf, %lf\" stroke=\"%s\" />\n", x1, y1, x2, y2, grs, x1, y1, cor);
  }
  return;

}

/*Escreve Linha Svg com parametros */
void escreveLinhaFTSvg(void* fsvg, double x1, double y1, double x2, double y2, char cor[], double grs){
        
  fprintf((FILE*)fsvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" transform=\"rotate(%lf, %lf, %lf\" stroke=\"%s\" />\n", x1, y1, x2, y2, grs, x1, y1, cor);
  return;

}

/* Fecha o arquivo fsvg. */
void fechaSvg(ArqSvg fsvg){
  fprintf(fsvg, "</svg>\n");
    fclose(fsvg);
}