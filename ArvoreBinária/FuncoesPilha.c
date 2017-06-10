#include "head.h"

void push(t_pilha ** pilha,t_arvore * no){
	t_pilha * aux = malloc (sizeof(t_pilha));
	aux->noArv = no;
	aux->prox = * pilha;
	* pilha = aux;
	
}

t_arvore * pop(t_pilha ** pilha){
    t_arvore * no;
    t_pilha * aux = (*pilha)->prox;
    no = (*pilha)->noArv;
    free(*pilha);
    * pilha = aux;
    return no;
}

pilha criaP(){
    pilha topo = (t_pilha *) malloc(sizeof(t_pilha));
    topo->prox = NULL;
    return topo;
}


