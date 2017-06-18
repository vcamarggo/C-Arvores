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
 
 void busca(caixinha *arvore, int k) {
 	if(arvore != NULL){
    if (arvore->letra == k){
       printf("Encontrado");
	   return;	
	   }
    if (arvore->letra > k)
       busca (arvore->esq, k);
    else
       busca (arvore->dir, k);
	}
 }

int main(){
	int x;
	caixinha *arvore=NULL;
	do{
		    
	printf("Insira valor: ");
	scanf("%i", &x);
	fflush(stdin);
	
	inserir(&arvore, x);
	printf("\n");
	}while(x != -1);
	
	printf("Insira valor que deseja buscar: ");
	scanf("%i", &x);
	busca(arvore, x);
}
