#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "txt.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"

/*
  Cria o arquivo "fn" para escrita. Substitui o arquivo, caso exista.
  Retorna NULL, caso nao tenha sido possivel criar arquivo.
 */
FILE* abreEscritaTxt(char *fn){
    FILE *arquivo = fopen(fn, "w");
    
    if(arquivo == NULL){
        printf("nao foi possivel criar arquivo\n");
        return NULL;
    } else {
        fprintf(arquivo, "ARQUIVO TXT:\n--------------------------------------------\n");
        return arquivo;
    }
}

/* Escreve dx e dy do Retangulo. */
void RetTfTxt(Retangulo Ret, void* ftxt){
    if(Ret!=NULL){
        int id = ParamIR(Ret);
        double dx = ParamDxR(Ret);
        double dy = ParamDyR(Ret);
        fprintf((FILE*)ftxt, "Retangulo\ti = %d\tdx = %lf\tdy = %lf\n", id, dx, dy);
    }
}

/* Escreve dx e dy do Texto. */
void TextoTfTxt(Texto t, void* ftxt){
    if(t!=NULL){
        int id = ParamIT(t);
        double dx = ParamDxT(t);
        double dy = ParamDyT(t);
        fprintf((FILE*)ftxt, "Texto\ti = %d\tdx = %lf\tdy = %lf\n", id, dx, dy);
    }
}

/* Escreve dx e dy da Linha. */
void LinhaTfTxt(Linha l, void* ftxt){
    if(l!=NULL){
        int id = ParamIdL(l);
        double dx = ParamDxL(l);
        double dy = ParamDyL(l);
        fprintf((FILE*)ftxt, "Linha\ti = %d\tdx = %lf\tdy = %lf\n", id, dx, dy);
    }
}

/* Escreve dx e dy do Circulo. */
void CircTfTxt(Circulo cir, void* ftxt){
    if(cir!=NULL){
        int id = ParamIC(cir);
        double dx = ParamDxC(cir);
        double dy = ParamDyC(cir);
        fprintf((FILE*)ftxt, "Circulo\ti = %d\tdx = %lf\tdy = %lf\n", id, dx, dy);
    }
}

/* Escreve atributos do Texto. */
void TextoTxt(Texto t, void* ftxt){
    if(t!=NULL){
        int id = ParamIT(t);
        double grs = ParamGrausT(t);
        double x = ParamXT(t);
        double y = ParamYT(t);
        char corp[50], corb[50], txt[50], anc[50], fntf[50], fnts[50], fntw[50];
        strcpy(corp, ParamCpT(t));
        strcpy(corb, ParamCbT(t));
        strcpy(anc, ParamAncT(t));
        strcpy(txt, ParamTextoT(t));
        
        fprintf((FILE*)ftxt, "Texto = %s\nx = %lf\ny = %lf\nGraus = %lf\nCorb = %s\nCorp = %s\nAncora = %s\n\n", txt, x, y, grs, corb, corp, anc);
    }
}

/* Escreve atributos do Circulo. */
void CirculoTxt(Circulo c, void* ftxt){
    if(c!=NULL){
        int id = ParamIC(c);
        double grs = ParamGrausC(c);
        double xc = ParamXC(c);
        double yc = ParamYC(c);
        double r = ParamRaioC(c);
        char corb[50], corp[50];
        strcpy(corb, ParamCbC(c));
        strcpy(corp, ParamCpC(c));
        
        fprintf((FILE*)ftxt, "x = %lf\ny = %lf\nRaio = %lf\nCor da Borda = %s\nCor de Preenchimento = %s\nGraus = %lf\n\n", xc, yc, r, corb, corp, grs);
    }
}

/* Escreve atributos do Retangulo. */
void RetanguloTxt(Retangulo r, void* ftxt){
    if(r!=NULL){
        int id = ParamIR(r);
        double grs = ParamGrausR(r);
        double x = ParamX1R(r);
        double y = ParamY1R(r);
        double larg = ParamW1R(r);
        double alt = ParamH1R(r);
        char corp[50], corb[50];
        strcpy(corp, ParamCpR(r));
        strcpy(corb, ParamCbR(r));

        fprintf((FILE*)ftxt, "x = %lf\ny = %lf\nLargura = %lf\nAltura = %lf\nCor da Borda = %s\nCor de Preenchimento = %s\nGraus = %lf\n\n", x, y, larg, alt, corb, corp, grs);
    }
}

/* Escreve atributos da Linha. */
void LinhaTxt(Linha l, void* ftxt){
  if(l!=NULL){
    int id = ParamIdL(l);
    double grs = ParamGrausL(l);
    double x1 = ParamX1L(l);
    double y1 = ParamY1L(l);
    double x2 = ParamX2L(l);
    double y2 = ParamY2L(l);
    char cor[50];
    strcpy(cor, ParamCorL(l));
    
    fprintf(ftxt, "x1 = %lf\ny1 = %lf\nx2 = %lf\ny2 = %lf\nCor = %s\nGraus = %lf\n\n", x1, y1, x2, y2, cor, grs);
  }
}

/* Fecha o arquivo fsvg. */
void fechaTxt(ArqTxt ftxt){
    fclose(ftxt);
}