#include<stdio.h>
#include<stdlib.h>
//#ifndef LABIRINTO_H
//#define LABIRINTO_H

#define TAM 						50
#define NAO_FOI_POSSIVEL_LER_O_ARQUIVO 	-1
#define CARACTER_INVALIDO              	-2
#define NAO_HA_QUEIJO                 	-3
#define MAIS_DE_UMA_SAIDA		    	-4
#define MAIS_DE_UMA_ENTRADA			-5
#define OK                             	 1

//int entrada = -1;
//int saida   = -1;


typedef struct{
	int x;
	int y;
} Posicao;

typedef struct {
	Posicao f[TAM];
	int inicio, fim;
} Fila;

int lab[TAM][TAM];
char labaux[TAM][TAM];
Posicao pRato;
Fila f;

int  abrirLabirinto(void);
int entrar(void);
int verifica_vizinhos(Posicao p, int qs);
int varre_labirinto(int qs);
int limpa_labirinto(void);
int backtrack(Posicao q);
int comer_queijo(Posicao p);
int percorre_labirinto(void);
int sai_lab(Posicao p);
void imprime_lab(void);
void imprime_labaux(void);


//Funcoes da fila
int cria_fila (Fila *F);
int fila_vazia (Fila *F);
int fila_cheia (Fila *F);
void insere_fila (Fila *F, Posicao x);
void remove_fila (Fila *F);
Posicao primeiro_fila (Fila *F);

//#endif
