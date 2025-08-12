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
#include "comandos_geo.h" 
#include "comandos_qry.h" 

/*Função auxiliar para procurar elemento nas Listas das Figuras. Retorna:
1 para identidade i correspondente a um circulo;
2 para identidade i correspondente a um retangulo;
3 para identidade i correspondente a uma Linha;
4 para identidade i correspondente a um Texto;
5 para caso não encontre nada*/
int Tipo(int i, void **pt, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas){

    Iterador itC = createIterador(Circulos, false);
    Iterador itR = createIterador(Retangulos, false);
    Iterador itL = createIterador(Linhas, false);
    Iterador itT = createIterador(Textos, false);
    Item info;

    while(!isIteratorEmpty(Circulos, itC)) {
        info = getIteratorNext(Circulos, itC);
        if (ParamIC(info) == i) {
            *pt = info;
            killIterator(Circulos, itC);
            killIterator(Retangulos, itR);
            killIterator(Linhas, itL);
            killIterator(Textos, itT);
            return 1;
        }
    }

    while(!isIteratorEmpty(Retangulos, itR)) {
        info = getIteratorNext(Retangulos, itR);
        if (ParamIR(info) == i) {
            *pt = info;
            killIterator(Circulos, itC);
            killIterator(Retangulos, itR);
            killIterator(Linhas, itL);
            killIterator(Textos, itT);
            return 2;
        }
    }

    while(!isIteratorEmpty(Linhas, itL)) {
        info = getIteratorNext(Linhas, itL);
        if (ParamIdL(info) == i) {
            *pt = info;
            killIterator(Circulos, itC);
            killIterator(Retangulos, itR);
            killIterator(Linhas, itL);
            killIterator(Textos, itT);
            return 3;
        }
    }

    while(!isIteratorEmpty(Textos, itT)) {
        info = getIteratorNext(Textos, itT);
        if (ParamIT(info) == i) {
            *pt = info;
            killIterator(Circulos, itC);
            killIterator(Retangulos, itR);
            killIterator(Linhas, itL);
            killIterator(Textos, itT);
            return 4;
        }
    }

    return 5;
}

/* ["mv" comando] Move a figura em dx e dy. */
void MoveFigura(FILE *arqtxt, char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas){

    int id, i;
    double dx, dy;
    char aux[50];
    void **ptr = malloc(sizeof(void *));
    int *auxx = malloc(sizeof(int));

    getParametroI(comando, linha, 2, aux, 50);
    id = atoi(*comando); 
    //Usando funcao que descobre qual figura é com base em seu id.
    i = Tipo(id, ptr, Circulos, Retangulos, Textos, Linhas);
    
    fprintf(arqtxt, "[*] %s\n", linha);
            
    if(i==1){ //É circulo

        getParametroI(comando, linha, 3, aux, 50);
        dx = strtod(*comando, NULL);
        getParametroI(comando, linha, 4, aux, 50);
        dy = strtod(*comando, NULL);

        *auxx = id;
        Lista circ = filter(Circulos, AchouIdC, auxx);
        Posic no = getFirstLst(circ);
        Item elemento = getLst(circ, no);

        if(elemento == NULL){
            printf("Erro ao mover figura de id: %d\n", id);
        } else {
            //Escreve no txt posicao original
            fprintf(arqtxt, "Circulo i = %d antes\n", id);
            CirculoTxt((Circulo*)elemento, arqtxt);

            //Move Circulo
            moveCirculo(*ptr, dx, dy);

            //Escreve no txt posicao apos mover
            fprintf(arqtxt, "Circulo i = %d depois\n", id);
            CirculoTxt((Circulo*)elemento, arqtxt);
            fprintf(arqtxt, "--------------------------------------------\n");
        }

    } else if(i==2){ //É retangulo

        getParametroI(comando, linha, 3, aux, 50);
        dx = strtod(*comando, NULL);
        getParametroI(comando, linha, 4, aux, 50);
        dy = strtod(*comando, NULL);

        *auxx = id;
        Lista retang = filter(Retangulos, AchouIdR, auxx);
        Posic no = getFirstLst(retang);
        Item elemento = getLst(retang, no);

        if(elemento == NULL){
            printf("Erro ao mover figura de id: %d\n", id);
        } else {
            //Escreve no txt posicao antes de mover
            fprintf(arqtxt, "Retangulo i = %d antes\n", id);
            RetanguloTxt((Retangulo*)elemento, arqtxt);

            //Move o Retangulo
            moveRetangulo(*ptr, dx, dy); 
            
            //Escreve no txt posicao apos mover
            fprintf(arqtxt, "Retangulo i = %d depois\n", id);
            RetanguloTxt((Retangulo*)elemento, arqtxt);
            fprintf(arqtxt, "--------------------------------------------\n"); 
        }

    } else if(i==3){ //É linha

        getParametroI(comando, linha, 3, aux, 50);
        dx = strtod(*comando, NULL);
        getParametroI(comando, linha, 4, aux, 50);
        dy = strtod(*comando, NULL);
                
        *auxx = id;
        Lista line = filter(Linhas, AchouIdL, auxx);
        Posic no = getFirstLst(line);
        Item elemento = getLst(line, no);

        if(elemento == NULL){
            printf("Erro ao mover figura de id: %d\n", id);
        } else {
            //Escreve no txt posicao original
            fprintf(arqtxt, "Linha i = %d antes\n", id);
            LinhaTxt((Linha*)elemento, arqtxt);

            //Move Linha
            MoverLinha(*ptr, dx, dy);

            //Escreve no txt posicao apos mover
            fprintf(arqtxt, "Linha i = %d depois\n", id);
            LinhaTxt((Linha*)elemento, arqtxt);
            fprintf(arqtxt, "--------------------------------------------\n");
        }

    } else if(i==4){ //É texto

        getParametroI(comando, linha, 3, aux, 50);
        dx = strtod(*comando, NULL);
        getParametroI(comando, linha, 4, aux, 50);
        dy = strtod(*comando, NULL);
             
        *auxx = id;
        Lista tex = filter(Textos, AchouIdT, auxx);
        Posic no = getFirstLst(tex);
        Item elemento = getLst(tex, no);

        if(elemento == NULL){
            printf("Erro ao mover figura de id: %d\n", id);
        } else {
            //Escreve no txt a posicao antes de mover
            fprintf(arqtxt, "Texto i = %d antes\n", id);
            TextoTxt((Texto*)elemento, arqtxt);

            //Move Texto
            moveTexto(*ptr, dx, dy);
                
            //Escreve no txt a posicao depois de mover
            fprintf(arqtxt, "Texto i = %d depois\n", id);
            TextoTxt((Texto*)elemento, arqtxt);
            fprintf(arqtxt, "--------------------------------------------\n");
        }

    } else if(i==5){ 
        printf("Nao encontrou identidade %d no comando mv\n", i);
    }
    free(auxx);
    free(ptr);
}

/* ["g" comando] Rotaciona a figura em determinados graus. */
void RotacionaFigura(FILE *arqtxt, char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas){

    int id, i;
    double graus;
    char aux[50];
    void **ptr = malloc(sizeof(void *));
    int *auxx = malloc(sizeof(int));

    getParametroI(comando, linha, 2, aux, 50);
    id = atoi(*comando);
    //Usando funcao que descobre qual figura é com base em seu id.
    i = Tipo(id, ptr, Circulos, Retangulos, Textos, Linhas);

    fprintf(arqtxt, "[*] %s\n", linha);

    if(i==1){ //É Circulo

        getParametroI(comando, linha, 3, aux, 50);
        graus = strtod(*comando, NULL);

        *auxx = id;
        Lista circ = filter(Circulos, AchouIdC, auxx);
        Posic no = getFirstLst(circ);
        Item elemento = getLst(circ, no);

        if(elemento == NULL){
            printf("Erro ao rotacionar figura de id: %d\n", id);
        } else {
            //Escreve no txt posicao original
            fprintf(arqtxt, "Circulo i = %d antes\n", id);
            CirculoTxt((Circulo*)elemento, arqtxt);

            //Rotaciona Circulo
            rotacionaCirculo(*ptr, graus);
            
            //Escreve no txt apos rotacionar
            fprintf(arqtxt, "Circulo i = %d depois\n", id);
            CirculoTxt((Circulo*)elemento, arqtxt);
            fprintf(arqtxt, "--------------------------------------------\n");
        }
                
    } else if(i==2){ //É Retangulo

        getParametroI(comando, linha, 3, aux, 50);
        graus = strtod(*comando, NULL);

        *auxx = id;
        Lista retang = filter(Retangulos, AchouIdR, auxx);
        Posic no = getFirstLst(retang);
        Item elemento = getLst(retang, no);

        if(elemento == NULL){
            printf("Erro ao rotacionar figura de id: %d\n", id);
        } else {
            //Escreve no txt posicao original
            fprintf(arqtxt, "Retangulo i = %d antes\n", id);
            RetanguloTxt((Retangulo*)elemento, arqtxt);

            //Rotaciona Retangulo
            rotacionaRetangulo(*ptr, graus);
        
            //Escreve no txt apos rotacionar
            fprintf(arqtxt, "Retangulo i = %d depois\n", id);
            RetanguloTxt((Retangulo*)elemento, arqtxt);
            fprintf(arqtxt, "--------------------------------------------\n");
        }

    } else if(i==3){ //É Linha

        getParametroI(comando, linha, 3, aux, 50);
        graus = strtod(*comando, NULL);

        *auxx = id;
        Lista line = filter(Linhas, AchouIdL, auxx);
        Posic no = getFirstLst(line);
        Item elemento = getLst(line, no);

        if(elemento == NULL){
            printf("Erro ao rotacionar figura de id: %d\n", id);
        } else {
            //Escreve no txt posicao original
            fprintf(arqtxt, "Linha i = %d antes\n", id);
            LinhaTxt((Linha*)elemento, arqtxt);

            //Rotaciona Linha
            rotacionaLinha(*ptr, graus);
                
            //Escreve no txt apos rotacionar
            fprintf(arqtxt, "Linha i = %d depois\n", id);
            LinhaTxt((Linha*)elemento, arqtxt);
            fprintf(arqtxt, "--------------------------------------------\n");
        }

    } else if(i==4){ //É Texto

        getParametroI(comando, linha, 3, aux, 50);
        graus = strtod(*comando, NULL);

        *auxx = id;
        Lista tex = filter(Textos, AchouIdT, auxx);
        Posic no = getFirstLst(tex);
        Item elemento = getLst(tex, no);

        if(elemento == NULL){
            printf("Erro ao rotacionar figura de id: %d\n", id);
        } else {
            //Escreve no txt posicao original
            fprintf(arqtxt, "Texto i = %d antes\n", id);
            TextoTxt((Texto*)elemento, arqtxt);

            //Rotaciona Texto
            rotacionaTexto(*ptr, graus);
                
            //Escreve no txt apos rotacionar
            fprintf(arqtxt, "Texto i = %d depois\n", id);
            TextoTxt((Texto*)elemento, arqtxt);
            fprintf(arqtxt, "--------------------------------------------\n");
        }

    } else if(i==5){
        
        printf("Nao encontrou identidade %d no comando G\n", id);

    }
    free(auxx);
    free(ptr);
}

/* ["ff" comando] Ajusta a Camera */
void AjustarCamera(char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas){

    char aux[50];
    int id, i;
    double raio, prof, alt;
    void **ptr = malloc(sizeof(void *));
    //Pegando parametros
    getParametroI(comando, linha, 2, aux, 50);
    id = atoi(*comando);
    getParametroI(comando, linha, 3, aux, 50);
    raio = strtod(*comando, NULL);
    getParametroI(comando, linha, 4, aux, 50);
    prof = strtod(*comando, NULL);
    getParametroI(comando, linha, 5, aux, 50);
    alt = strtod(*comando, NULL);

    i = Tipo(id, ptr, Circulos, Retangulos, Textos, Linhas);

    AlteraBalao(*ptr, raio, prof, alt); //Atribuindo valores a Camera do Balao

    free(ptr);
}

/* ["tf" comando] Tira foto */
void TiraFoto(FILE *arqtxt, char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas, Lista RetCapturas){

    int id, i;
    double raio, prof, alt, *menor, *maior;
    char aux[50];
    int *auxx = malloc(sizeof(int));
    menor = malloc(sizeof(double));
    maior = malloc(sizeof(double));
    *menor = 0;
    //Pegando parametros
    getParametroI(comando, linha, 2, aux, 50);
    id = atoi(*comando);
    getParametroI(comando, linha, 3, aux, 50);
    i = atoi(*comando);
    fprintf(arqtxt, "[*] %s\n", linha);

    *auxx = id;
    
    Lista cmr = filter(Textos, AchouIdT, auxx);
    Posic no = getFirstLst(cmr);
    Item info = getLst(cmr, no);

    //Escrevendo atributos do Balao
    fprintf(arqtxt, "Atributos do Balao e da sua Camera:\n\n");
    TextoTxt(info, arqtxt);
    //Escrevendo atributos da Camera do Balao
    raio = ParamRaioB(info);
    prof = ParamProfB(info);
    alt = ParamAltB(info);
    fprintf(arqtxt, "Raio: %lf Profundidade: %lf Altura: %lf\n\n", raio, prof, alt);

    //Adiciona decoracao para o .svg final
    Retangulo* captura = novoRetangulo(id, ParamXT(info) - raio, ParamYT(info) + prof, 2 * raio, alt, "#FF0000", "none");
    insertLst(RetCapturas, captura);

    Fila fil = ParamFilaB(info, i);
    Foto fotinha = createFoto(raio, prof, alt);
    Lista textoo = GetListTxt(fotinha);
    Lista retanguloo = GetListRet(fotinha);
    Lista linhaa = GetListLin(fotinha);
    Lista circuloo = GetListCirc(fotinha);

    /* Procurando quais elementos foram Capturados na foto e adicionando nas
    Listas dos elementos capturados da foto. */
    ProcuraTxt(textoo, Textos, ParamXT(info), ParamYT(info), raio, alt, prof);
    ProcuraRet(retanguloo, Retangulos, ParamXT(info), ParamYT(info), raio, alt, prof); 
    ProcuraCirc(circuloo, Circulos, ParamXT(info), ParamYT(info), raio, alt, prof);
    ProcuraLin(linhaa, Linhas, ParamXT(info), ParamYT(info), raio, alt, prof);

    //Procurando o menor x da foto.
    fold(circuloo, MenorXC, menor);      
    fold(retanguloo, MenorXR, menor);    
    fold(linhaa, MenorXL, menor);  
    fold(textoo, MenorXT, menor);
                    
    *maior = ParamRaioB(info) + ParamRaioB(info);

    //Procurando o maior x da foto.
    fold(circuloo, MaiorXC, maior); 
    fold(retanguloo, MaiorXR, maior);
    fold(linhaa, MaiorXL, maior);
    fold(textoo, MaiorXT, maior);
    
    //Assim que achar, inserir
    alterarXma(fotinha, *maior);
    alterarXme(fotinha, *menor);
          
    if(!FilaFull(fil)){ //Se a Fila nao estiver cheia, inserir nova foto.
        insereFila(fil, fotinha);
    }

    //Escrevendo no txt as informacoes do dx e do dy dos elementos que foram capturados na foto.
    fprintf(arqtxt, "Elementos da Foto:\n");
    fold(circuloo, CircTfTxt, arqtxt);  
    fold(linhaa, LinhaTfTxt, arqtxt);  
    fold(retanguloo, RetTfTxt, arqtxt);  
    fold(textoo, TextoTfTxt, arqtxt);  
                    
    free(maior);
    free(menor);
    fprintf(arqtxt, "--------------------------------------------\n");
}

/* ["df" comando] Faz Download da foto. */
void DownloadFoto(FILE *arqtxt, char *dft, char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas){

    int id, i;
    double dx, dy, x, y, g, r, h, w, x1, x2, y1, y2, raio, prof, alt;
    char aux[50], corb[50], corp[50], cor[50], a[50], t[50], sufixo[50], *aa, *tt, *cb, *cp, *deco;
    //Pegando parametros
    getParametroI(comando, linha, 2, aux, 50);
    id = atoi(*comando);
    getParametroI(comando, linha, 3, aux, 50);
    i = atoi(*comando);
    getParametroI(comando, linha, 4, aux, 50);
    strcpy(sufixo, *comando);

    double *soma;
    soma = malloc(sizeof(double));
    int numero = 0;

    fprintf(arqtxt, "[*] %s\n", linha);
    fprintf(arqtxt, "Fila de fotos %d do Balao de identificacao %d\n\n", i, id);

    //Procurando Balao correspondente ao Id
    Iterador itT = createIterador(Textos, false);
    Item infoo;
    while(!isIteratorEmpty(Textos, itT)) {
        infoo = getIteratorNext(Textos, itT);
        if (ParamIT(infoo) == id){
            break;
        }
    }
    killIterator(Textos, itT);

    Fila filaFt = ParamFilaB(infoo, i);
    Foto ft;
    Lista textoo;
    Lista retanguloo;
    Lista linhaa;
    Lista circuloo;

    double XC, YC;
    XC = 10;
    YC = 300;

    //Abrindo svg
    char newSvg[500]; 
    sprintf(newSvg, "%s-%s%s", dft, sufixo, ".svg");
    FILE * arqsvg = abreEscritaSvg(newSvg);

    while(!FilaEmpty(filaFt)){

        *soma = 0;
        ft = removeFila(filaFt);
        //Pegando informacoes das Listas de elementos capturados pela Foto.
        textoo = GetListTxt(ft);
        retanguloo = GetListRet(ft);
        linhaa = GetListLin(ft);
        circuloo = GetListCirc(ft);

        Iterador itC = createIterador(circuloo, false);
        Iterador itR = createIterador(retanguloo, false);
        Iterador itL = createIterador(linhaa, false);
        Iterador itT = createIterador(textoo, false);
        Item info;

        XC = XC - GetXme(ft);
        //Escrevendo figuras que foram fotografadas
        while(!isIteratorEmpty(circuloo, itC)) { //Escrevendo Circulos fotografados
            info = getIteratorNext(circuloo, itC);
            escreveCirculoFTSvg(arqsvg, ParamDxC(info) + XC, ParamDyC(info) + 300, ParamRaioC(info), ParamCbC(info), ParamCpC(info), ParamGrausC(info));
        }

        while(!isIteratorEmpty(retanguloo, itR)) { //Escrevendo Retangulos fotografados
            info = getIteratorNext(retanguloo, itR);
            escreveRetanguloFTSvg(arqsvg, ParamDxR(info) + XC, ParamDyR(info) + 300, ParamW1R(info), ParamH1R(info), ParamCpR(info), ParamCbR(info), ParamGrausR(info));
        }

        while(!isIteratorEmpty(linhaa, itL)) { //Escrevendo Linhas fotografadas
            info = getIteratorNext(linhaa, itL);
            escreveLinhaFTSvg(arqsvg, ParamDxL(info) + XC, ParamDyL(info) + 300, ParamX2L(info) - ParamX1L(info) + ParamDxL(info) + XC, ParamY2L(info) - ParamY1L(info) + ParamDyL(info) + 300, ParamCorL(info), ParamGrausL(info));
        }

        while(!isIteratorEmpty(textoo, itT)) { //Escrevendo Textos fotografados
            info = getIteratorNext(textoo, itT);
            escreveTextoFTSvg(arqsvg, ParamDxT(info) + XC, ParamDyT(info) + 300, ParamCbT(info), ParamCpT(info), ParamAncT(info), ParamTextoT(info), ParamGrausT(info), ParamFFT(info), ParamFWT(info), ParamFST(info));
        }

        //Escrevendo o retangulo da borda da foto.
        fprintf(arqsvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" style=\"stroke:Black; fill:none; stroke-width:1;\" />\n", XC, YC, 2 * GetRaioFt(ft), GetAltFt(ft));

        if(GetXma(ft) > 2 * GetRaioFt(ft)){
            XC = XC + GetXma(ft) + 5;
        } else {
            XC = XC + (2 * GetRaioFt(ft)) + 5;
        }

        killIterator(circuloo, itC);
        killIterator(retanguloo, itR);
        killIterator(linhaa, itL);
        killIterator(textoo, itT);

        //Escrevendo no txt os Elementos da foto e somando a pontuacao da foto.
        fprintf(arqtxt, "Elementos da Foto %d:\n", numero);
        fold(circuloo, PontuacaoC, soma);
        fold(circuloo, CircTfTxt, arqtxt);     
        fold(retanguloo, PontuacaoR, soma);
        fold(retanguloo, RetTfTxt, arqtxt);     
        fold(linhaa, PontuacaoL, soma);
        fold(linhaa, LinhaTfTxt, arqtxt);     
        fold(textoo, PontuacaoT, soma);
        fold(textoo, TextoTfTxt, arqtxt);     
        fprintf(arqtxt, "PONTUACAO DA FOTO ----> %lf\n\n", *soma);
        numero++;

        fprintf(arqtxt, "--------------------------------------------\n");  
    }
    free(soma);
    fechaSvg(arqsvg);
}

/* ["d" comando] Um Caca realiza um disparo de capacidade A, B ou C. */
void DisparoCaca(FILE *arqtxt, char **comando, char *linha, Lista Circulos, Lista Retangulos, Lista Textos, Lista Linhas, Lista Decoracoes, Lista Explosoes){
    
    fprintf(arqtxt, "[*] %s\n", linha);
    fprintf(arqtxt, "Elementos que foram acertados:\n\n");
    
    int id;
    double capac, dist, Xbomba, Ybomba;
    char aux[50];
    int *novoId = malloc(sizeof(int));
    double *dx = malloc(sizeof(double));
    //Pegando parametros
    getParametroI(comando, linha, 2, aux, 50);
    id = atoi(*comando);
    getParametroI(comando, linha, 3, aux, 50);
    strcpy(aux, *comando);
    getParametroI(comando, linha, 4, aux, 50);
    dist = strtod(*comando, NULL);
    getParametroI(comando, linha, 5, aux, 50);
    *novoId = atoi(*comando);
    getParametroI(comando, linha, 6, aux, 50);
    *dx = strtod(*comando, NULL);
   
   //Analisando capacidade do disparo
    if(strcmp((aux), "A") == 0 || strcmp((aux), "a") == 0 ){
        capac = 10;
    } else if (strcmp((aux), "B") == 0 || strcmp((aux), "b") == 0 ){
        capac = 15;
    } else {
        capac = 30;
    }

    //Procurando Caca de Id correspondente
    Iterador itT = createIterador(Textos, false);
    Item infoo;
    while(!isIteratorEmpty(Textos, itT)) {
        infoo = getIteratorNext(Textos, itT);
        if (ParamIT(infoo) == id){
            break;
        }
    }
    killIterator(Textos, itT);

    //O centro da área onde a bomba vai explodir.
    Xbomba = ParamXT(infoo) - dist * sin(ParamGrausT(infoo) * 3.14/180);
    Ybomba = ParamYT(infoo) + dist * cos(ParamGrausT(infoo) * 3.14/180);

    createCaca(infoo);
    aumentaTiro(infoo);
    AlteraTipo(infoo, 1);
    Lista idsCaca = ParamIdentificadores(infoo);

    //Adiciona decoracao para o .svg final (opcional)
    //Circulo* exp = novoCirculo(0, Xbomba, Ybomba, capac, "#FF0000", "none");
    //insertLst(Explosoes, exp);

    ProcuraCircCaca(arqtxt, Decoracoes, idsCaca, Circulos, Xbomba, Ybomba, capac);
    ProcuraRetCaca(arqtxt, Decoracoes, idsCaca, Retangulos, Xbomba, Ybomba, capac);
    ProcuraLinhaCaca(arqtxt, Decoracoes, idsCaca, Linhas, Xbomba, Ybomba, capac);
    
    Item info;
    Posic posicao = getFirstLst(Textos);
    Lista cloneR = createLst(-1);
    Lista cloneC = createLst(-1);
    Lista cloneT = createLst(-1);
    Lista cloneL = createLst(-1);

    while(posicao != NULL){

        info = getLst(Textos, posicao);

        if((ParamXT(info) - Xbomba) * (ParamXT(info) - Xbomba) + (ParamYT(info) - Ybomba) * (ParamYT(info) - Ybomba) < capac * capac){

            int *ptr = malloc(sizeof(int));
            *ptr = ParamIT(info);

            if(strcmp(ParamTextoT(info), "v_O_v") == 0){ //Caso for Balao, comecar clonagens

                int ident = *novoId;

                for(int number = 0; number < 10; number++){ 
                    Fila fil = ParamFilaB(info, number);
                    Foto ft;
                    Lista textoo, retanguloo, linhaa, circuloo;

                    while(!FilaEmpty(fil)){
                        ft = removeFila(fil);
                        //Pegando informacoes das Listas de elementos capturados pela Foto.
                        textoo = GetListTxt(ft);
                        retanguloo = GetListRet(ft);
                        linhaa = GetListLin(ft);
                        circuloo = GetListCirc(ft);

                        //Criando uma Lista com os elementos clonados
                        Lista clonadosRet = map(retanguloo, transladaR, dx);
                        Lista clonadosCirc = map(circuloo, transladaC, dx);
                        Lista clonadosLin = map(linhaa, transladaL, dx);
                        Lista clonadosTexto = map(textoo, transladaT, dx);

                        Iterador itC = createIterador(clonadosCirc, false);
                        Iterador itR = createIterador(clonadosRet, false);
                        Iterador itL = createIterador(clonadosLin, false);
                        Iterador itTT = createIterador(clonadosTexto, false);
                        Item auxiliar;

                        /* Inserindo elementos clonados na Lista dos Clones para,
                        apos a explosao, serem adicionados no Banco de Dados. */
                        while(!isIteratorEmpty(clonadosCirc, itC)) {
                            auxiliar = getIteratorNext(clonadosCirc, itC);
                            alteraIC(auxiliar, ident);
                            ident++;
                            insertLst(cloneC, auxiliar);
                        }

                        while(!isIteratorEmpty(clonadosRet, itR)) {
                            auxiliar = getIteratorNext(clonadosRet, itR);
                            AlteraIR(auxiliar, ident);
                            ident++;
                            insertLst(cloneR, auxiliar);
                        }

                        while(!isIteratorEmpty(clonadosLin, itL)) {
                            auxiliar = getIteratorNext(clonadosLin, itL);
                            AlteraIL(auxiliar, ident);
                            ident++;
                            insertLst(cloneL, auxiliar);
                        }

                        while(!isIteratorEmpty(clonadosTexto, itTT)) {
                            auxiliar = getIteratorNext(clonadosTexto, itTT);
                            AlteraIT(auxiliar, ident);
                            ident++;
                            insertLst(cloneT, auxiliar);
                        }
                        
                        killIterator(clonadosCirc, itC);
                        killIterator(clonadosRet, itR);
                        killIterator(clonadosLin, itL);
                        killIterator(clonadosTexto, itTT);
                    }
                }
            }

            //Escrevendo atributos dos Textos que foram atingidos e serão removidos
            fprintf(arqtxt, "Texto de id %d removido. Atributos:\n", *ptr);
            TextoTxt(info, arqtxt);
            insertLst(idsCaca, (Item*) ptr);
            removeLst(Textos, posicao);
            //Adicionando decoracao x na sua ancora
            Texto txtoo = novoTexto(1, ParamXT(info), ParamYT(info), "#FF0000", "#FF0000", "middle", "x", "normal", "normal", "middle");
            insertLst(Decoracoes, txtoo);
        }

        posicao = getNextLst(Textos, posicao);
    }
    fprintf(arqtxt, "Clones:\n\n");
    Iterador itCC = createIterador(cloneC, false);
    Iterador itRR = createIterador(cloneR, false);
    Iterador itLL = createIterador(cloneL, false);
    Iterador itTTT = createIterador(cloneT, false);
    Item auxiliar;

    //Escrevendo atributos dos clones e adicionando-os no Banco de Dados  

    while(!isIteratorEmpty(cloneC, itCC)) {
        auxiliar = getIteratorNext(cloneC, itCC);
        insertLst(Circulos, auxiliar);
        fprintf(arqtxt, "Circulo de id: %d\n", ParamIC(auxiliar));
        CirculoTxt(auxiliar, arqtxt);
    }

    while(!isIteratorEmpty(cloneR, itRR)) {
        auxiliar = getIteratorNext(cloneR, itRR);
        insertLst(Retangulos, auxiliar);
        fprintf(arqtxt, "Retangulo de id: %d\n", ParamIR(auxiliar));
        RetanguloTxt(auxiliar, arqtxt);
    }

    while(!isIteratorEmpty(cloneL, itLL)) {
        auxiliar = getIteratorNext(cloneL, itLL);
        insertLst(Linhas, auxiliar);
        fprintf(arqtxt, "Linha de id: %d\n", ParamIdL(auxiliar));
        LinhaTxt(auxiliar, arqtxt);
    }

    while(!isIteratorEmpty(cloneT, itTTT)) {
        auxiliar = getIteratorNext(cloneT, itTTT);
        insertLst(Textos, auxiliar);
        fprintf(arqtxt, "Texto de id: %d\n", ParamIT(auxiliar));
        TextoTxt(auxiliar, arqtxt);
    }
                        
    killIterator(cloneC, itCC);
    killIterator(cloneR, itRR);
    killIterator(cloneL, itLL);
    killIterator(cloneT, itTTT);

    fprintf(arqtxt, "--------------------------------------------\n");  
}

/* ["b?" comando] Reporta informacoes de todos os Baloes existentes */
void ReportaBaloes(FILE *arqtxt, char **comando, char *linha, Lista Textos){

    fprintf(arqtxt, "[*] %s\n", linha);

    Iterador itT = createIterador(Textos, false);
    Item info;
    Fila fil;
    char *deco = NULL;
    int quantidade;

    while(!isIteratorEmpty(Textos, itT)) {

        info = getIteratorNext(Textos, itT);

        if (strcmp(ParamTextoT(info), "v_O_v") == 0){

            //Escreve informacoes do Balao e da sua Camera;    
            fprintf(arqtxt, "Balao de id %d, seus atributos e atributos da Camera:\n\n", ParamIT(info));
            TextoTxt(info, arqtxt);

            if(ParamRaioB(info) == -1 && ParamProfB(info) == -1 && ParamAltB(info) == -1){
                //Ainda nao inicializou a Camera;
                fprintf(arqtxt, "Raio: 0.0000 Profundidade: 0.0000 Altura: 0.0000\n");

            } else{ //Inicializou a Camera

                fprintf(arqtxt, "Raio: %lf Profundidade: %lf Altura: %lf\n", ParamRaioB(info), ParamProfB(info), ParamAltB(info));
            }

            for(int number = 0; number < 10; number++){ //Passando pelas filas analisando quantas fotos tem
                
                fil = ParamFilaB(info, number);
                quantidade = ParamQtddFila(fil);
                
                if(quantidade == -1){
                    quantidade = 0;
                }
                
                fprintf(arqtxt, "Fila %d: %d fotos\n", number, quantidade);
            }
             fprintf(arqtxt,"\n");
        }
    }
    killIterator(Textos, itT);
    fprintf(arqtxt, "--------------------------------------------\n");  
}

/* ["c?" comando] Reporta informacoes de todos os Cacas existentes */
void ReportaCacas(FILE *arqtxt, char **comando, char *linha, Lista Textos){

    fprintf(arqtxt, "[*] %s\n\n", linha);

    Iterador itT = createIterador(Textos, false);
    Item info, infoID;
    char *deco = NULL;
    Fila fil;
    Lista ids;

    while(!isIteratorEmpty(Textos, itT)) {

        info = getIteratorNext(Textos, itT);

        if (strcmp(ParamTextoT(info), "|-T-|") == 0){

            if(ParamTipo((Texto*)info) == 0){ //Nao realizou nenhum tiro

                fprintf(arqtxt, "Caca de id: %d\nAinda nao atirou\n", ParamIT(info));
                TextoTxt(info, arqtxt);

            } else { //Realizou um ou mais tiros

            //Escreve informacoes do Caca no .txt    
            fprintf(arqtxt, "Atributos do Caca de id %d\n", ParamIT(info));
            fprintf(arqtxt, "Realizou %d tiro(s)\n", ParamTiros(info));
            TextoTxt(info, arqtxt);
                    
            //Escrevendo identificadores dos elementos destruidos pelo Caca no .txt:
            fprintf(arqtxt, "Identificadores dos elementos destruidos:\n");

            ids = ParamIdentificadores(info);
            Iterador itCaca = createIterador(ids, false);

            while(!isIteratorEmpty(ids, itCaca)){

                infoID = getIteratorNext(ids, itCaca);
                fprintf(arqtxt, "Id: %d\n", *(int*)infoID);
            }

            fprintf(arqtxt, "\n");

            } 
        }
    }

    killIterator(Textos, itT);
    fprintf(arqtxt, "--------------------------------------------\n");  
}