 
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

 	int compara(caixinha *a, caixinha *b){
 	return(a == NULL && b == NULL) ||   
             (a != NULL && b != NULL &&   
               a->letra == b->letra &&   
               compara(a->esq, b->esq) &&   
               compara(a->dir, b->dir));  
	 }

int main(){
	char x;
	caixinha *arvore=NULL;
	caixinha *arvore2=NULL;
	do{
		    
	printf("Insira valor: ");
	scanf("%i", &x);
	fflush(stdin);

	inserir(&arvore, x);
	inserir(&arvore2, x-1);
	printf("%i ", compara(arvore, arvore2));
	}while(x != 'l');

}

