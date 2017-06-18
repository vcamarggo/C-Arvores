#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef enum {
	Interno ,  Externo
}TipoNo;

typedef  struct caixinha *TipoArvore ;

typedef  struct caixinha{
	TipoNo tipoDoNo;
	TipoArvore  esq,  dir ;
	unsigned char chave;
}caixinha;

short EExterno(TipoArvore p){
	return (p->tipoDoNo == Externo);
}

unsigned char  Bit (unsigned char  i ,  unsigned char  k){
	int c, j ;
	if(i  == 0){
		return 0 ;
	}
	else{
 		c = k;
		for(j=1; j <= 8-i ;  j ++)
			c /= 2;
		return (c & 1);
	}
}

TipoArvore  CriaNoInt(int i , TipoArvore *Esq, TipoArvore *Dir){
	TipoArvore p;
	p = (TipoArvore) malloc(sizeof(caixinha));
	p->tipoDoNo = Interno;
	p->esq = *Esq;
	p->dir = *Dir;
	p->chave = i;
	return p;
}

TipoArvore CriaNoExt(unsigned char k){
	TipoArvore p;
	p = (TipoArvore) malloc(sizeof(caixinha));
	p->tipoDoNo = Externo;
	p->chave = k;
	return p;
}

TipoArvore InsereEntre(unsigned char k , TipoArvore *t, int i){
	TipoArvore p;
	if(EExterno(*t) || i < (*t)->chave){
		p = CriaNoExt(k);
		if(Bit(i,k) == 1){
			return (CriaNoInt(i,t,&p));
		}
		else{
			return(CriaNoInt(i,&p,t));
		}
	}
	else{
		if(Bit((*t)->chave,k) == 1){
			(*t)->dir = InsereEntre (k,&(*t)->dir,i);
		}
		else {
			(*t)->esq = InsereEntre(k,&(*t)->esq,i);
		}
	return (*t);
	}
}

TipoArvore Insere(unsigned char k ,  TipoArvore *t){
	TipoArvore p;
	int i;
	if(*t  == NULL){
		return(CriaNoExt(k));
	}
	else{
		p = *t;
		while(!EExterno(p)){
			if(Bit(p->chave, k) == 1){
				p = p->dir;
			}
			else{
				p =  p->esq;
			}
		}
		i = 1;
		while((i <= 8) & (Bit((int) i, k) == Bit((int) i, p->chave))){
			i++;
		}
		if(i > 8){
			printf("\nTroca ai, esse ja tem... \n" );
			return (*t);
		}
		else{
			return(InsereEntre(k, t, i));
		}
	}
}

void printa(TipoArvore t){
	if(t != NULL){
        if (!EExterno(t))
	    	printa(t->esq);
    }
    if (EExterno(t)) {
        printf("%c ", t->chave);
    }
    else{
        printf("%i", t->chave);
        printf("i ");
    }
    if(!EExterno(t))
        printa(t->dir);
}

int main(){
	char x;
	TipoArvore a = NULL;
  	unsigned char c;
  	printf("   *******************\n   * ARVORE PATRICIA *\n   *******************\n");
	do{
		printf("\n 1 - Limpa tela\n 0 - Finaliza Programa\n");
		printf("\n Insira caractere qualquer presente na tabela ASC: ");
		scanf("%c", &x);
		fflush(stdin);
		if(x == '1'){
			system("cls");
			printf("   *******************\n   * ARVORE PATRICIA *\n   *******************\n");
		}else{
			a = Insere(x, &a);
			printa(a);
			printf("\n");
		}
	}while(x != '0');

}






