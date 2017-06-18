#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10 //Tamanho máximo da matriz!

typedef struct caixinha{
	int letra;	
	struct caixinha *dir;
	struct caixinha *esq;
}caixinha;

 void inserir(caixinha **arvore, int letra){
     if(*arvore == NULL){
	caixinha *a = (caixinha *) malloc(sizeof(caixinha));
	 	a->esq = NULL;
    	a->dir = NULL;
        a->letra = letra;
        *arvore = a;
        return;
     }
         if(letra < (*arvore)->letra)  {
              inserir(&(*arvore)->esq, letra);
        	 } else  {
              inserir(&(*arvore)->dir, letra);
            }
     return ;
 }

 void printarCrescente(caixinha *arvore){
     if(arvore != NULL){
		printarCrescente(arvore->esq);
		printf("%i ",arvore->letra);
		printarCrescente(arvore->dir);
	}
 }
 
 caixinha *copiar(caixinha *arvore){
 	caixinha *novaArv;
	 if(arvore != NULL){
	 	novaArv=(caixinha *)malloc(sizeof(caixinha));
 		novaArv->letra = arvore->letra;
 		novaArv->esq = copiar(arvore->esq);
 		novaArv->dir = copiar(arvore->dir);
 		return novaArv;
	 }
 }

int main(){
	char x;
	caixinha *arvore=NULL;
	do{
		    
	printf("Insira valor: ");
	scanf("%i", &x);
	fflush(stdin);

	inserir(&arvore, x);
	printarCrescente(copiar(arvore));
	printf("\n");
	}while(x != 'l');

}






