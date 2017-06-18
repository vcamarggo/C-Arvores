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
 
 int isNotLista(caixinha *arvore){
 	int numero = 0;
     if(arvore != NULL){
 			isNotLista(arvore->dir);
			isNotLista(arvore->esq);
     		if((arvore->esq != NULL && arvore->dir != NULL)){
			return 1;
		 	}
	}
	return numero;
 }

int main(){
	char x;
	caixinha *arvore=NULL;
	do{
		    
	printf("Insira valor: ");
	scanf("%i", &x);
	fflush(stdin);

	inserir(&arvore, x);

	printf("%i ", isNotLista(arvore));
	printf("\n");
	}while(x != 'l');

}
