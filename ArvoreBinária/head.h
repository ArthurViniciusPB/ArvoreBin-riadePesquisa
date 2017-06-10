#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dado {
	int carac;
}t_elemento;

typedef struct noA{
	struct noA * esq;
	t_elemento dado;
	struct noA * dir;
}t_arvore;

typedef struct noP{
	t_arvore * noArv;
	struct noP * prox;
}t_pilha;

typedef t_arvore * arvore;
typedef t_pilha * pilha;

void delArv(t_arvore *);
void preordem_(arvore );
void inordem_(arvore );
void posordem_(arvore );
t_arvore * pop(t_pilha ** pilha);
void push(t_pilha ** ,t_arvore * );
pilha criaP();
t_arvore * criaA();
void inserir(t_arvore ** tree, int carac);
void gotoxy(int coluna, int linha);
void exibirGraficamente(t_arvore * tree, int col, int lin, int desloc);
int rmNoArv(t_arvore * tree,int dado);
t_arvore * pesqArv(t_arvore * tree, int carac);

#if defined(_WIN32) || defined(WIN32)
#define LIMPATELA system("cls")
#define flush fflush(stdin)
#else
#define LIMPATELA system("clear")
#include <stdio_ext.h>
#define flush__fpurge(stdin)
#endif

