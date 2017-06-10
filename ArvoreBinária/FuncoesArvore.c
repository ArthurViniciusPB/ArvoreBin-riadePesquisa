#include"head.h"

void preordem_(arvore arv){
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
    do {
        while (aux != NULL) {
            if(aux->dado.carac != -1)printf("%d ", aux->dado.carac);
            push(&p, aux);
            aux = (aux->esq);
        }
        if (p) {
            aux = pop(&p);
            aux = (aux->dir);
        }
    } while (p->prox || aux);
    printf("\n");

}
void inordem_ (arvore arv) {
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
    do {
        while (aux != NULL) {
            push(&p, aux);
            aux = (aux->esq);
        }
        if (p) {
            aux = pop(&p);
            if(aux->dado.carac != -1)printf("%d ", aux->dado.carac);
            aux = (aux->dir);
        }
    } while (p->prox || aux);
    printf("\n");
}
void posordem_(arvore arv){
	if (arv!=NULL) {
		posordem_(arv->esq);
		posordem_(arv->dir);
		printf("%d ", arv->dado.carac);
	}	
}


void delArv(t_arvore * arv){
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
	int entrou=1;
    do {
        while (aux != NULL && entrou) {
            if(aux->esq){
            	push(&p, aux);
				aux = (aux->esq);
				entrou = 1;
				continue;
			}
            else if (aux->dir){
				push(&p, aux);
				aux = (aux->dir);
				entrou = 1;
				continue;
			}
			entrou = 0;
        }
        if (p) {
			if(p->noArv->esq == aux){
				free(p->noArv->esq);
				p->noArv->esq=NULL;
			}
	
			else if(p->noArv->dir == aux){
				free(p->noArv->dir);
				p->noArv->dir=NULL;	
			}
            aux = pop(&p);
			entrou = 1;
        }
    } while (p && (p->prox || aux));
    printf("\n");
}
t_arvore * criaA(){
  t_arvore * no = (t_arvore*)malloc(sizeof(t_arvore));
  if(no)no->esq=no->dir=NULL;
  return no;
}
void inserir(t_arvore ** tree, int carac){
    if(!(*tree)){
        (*tree)=criaA();
        (*tree)->dado.carac=carac;
    }
    else if((*tree)->dado.carac > carac) inserir(&((*tree)->esq),carac);
    else inserir(&((*tree)->dir),carac);
}
t_arvore * pesqArv(t_arvore * tree, int carac){
	t_arvore * conf=NULL;
	int entrou=0;
	//Caso não encontre nó
	if(!tree)return 0;
	//Pai e verifica folhas
	if(!entrou){
		if(tree->esq){
				if((tree->esq->dado.carac ==  carac) && tree->esq->esq && tree->esq->dir==NULL){
						conf=tree;
						entrou = 2;
				}
				else if((tree->esq->dado.carac ==  carac)&&tree->esq->esq==NULL  && tree->esq->dir){
						conf=tree;
						entrou = 2;
				}
				else if((tree->esq->dado.carac ==  carac) && tree->esq->esq==NULL && tree->esq->dir==NULL){
						conf=tree;			
						entrou = 1;
				}
		}
		if(tree->dir){
				if((tree->dir->dado.carac ==  carac)&&tree->dir->esq &&tree->dir->dir==NULL){
						conf=tree;	
						entrou = 2;
				} 
				else if((tree->dir->dado.carac ==  carac)&&tree->dir->esq==NULL  && tree->dir->dir){
						conf=tree;	
						entrou = 2;
				} 
				else if((tree->dir->dado.carac ==  carac) && tree->dir->esq==NULL && tree->dir->dir==NULL){
						conf=tree;			
						entrou = 1;
				}
		}
	}
    if(!entrou){
		if(tree->dado.carac > carac)conf =  pesqArv(tree->esq,carac);	
		else conf=pesqArv(tree->dir,carac);
	}
	return conf;
}
int rmNoArv(t_arvore * tree,int carac){	
	t_arvore * dir,*esq;
	int entrou=0;
	if(!entrou){
		if(tree->esq){
				if((tree->esq->dado.carac ==  carac) && tree->esq->esq && tree->esq->dir==NULL){
						esq = (tree->esq->esq); 
						free(tree->esq);
						tree->esq = esq;
						
						entrou = 2;
				}
				else if((tree->esq->dado.carac ==  carac)&&tree->esq->esq==NULL  && tree->esq->dir){
						dir = tree->esq->dir; 
						free(tree->esq);
						tree->dir = dir;
						
						entrou = 2;
				} else if((tree->esq->dado.carac ==  carac) && tree->esq->esq==NULL && tree->esq->dir==NULL){ 
						free(tree->esq);	
						tree->esq=NULL;
						
						entrou = 2;
				} 
		}
		if(tree->dir){
				if((tree->dir->dado.carac ==  carac)&&tree->dir->esq &&tree->dir->dir==NULL){
						esq = (tree->dir->esq); 
						free(tree->dir);
						tree->esq = esq;
						
						entrou = 2;
				} 
				else if((tree->dir->dado.carac ==  carac)&&tree->dir->esq==NULL  && tree->dir->dir){
						dir = tree->dir->dir; 
						free(tree->dir);
						tree->dir = dir;
						
						entrou = 2;
				} 
				else if((tree->dir->dado.carac ==  carac) && tree->dir->esq==NULL && tree->dir->dir==NULL){
						free(tree->dir);	
						tree->dir=NULL;
						
						entrou = 1;
				}
		}
	}

	return entrou;
}


