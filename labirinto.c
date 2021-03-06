#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"labirinto.h"


int abrirLabirinto(void){
	FILE *entrada;
	char c='#';
	char nome[50];
	int qtdQueijos = 0, qtdSaidas = 0, qtdEntradas = 0;
	int i, j;
		
	printf("Informe o nome do arquivo:\n");
	scanf("%s", nome);
	
	if ((entrada = fopen(nome, "r")) == NULL) {
    		printf("Erro ao ler labirinto\n");
    		return NAO_FOI_POSSIVEL_LER_O_ARQUIVO;
    	}
    	
    	while(!feof(entrada)){
    		fscanf(entrada, "%c", &c);
    		qtdQueijos = qtdQueijos + ( (c!='C') ? 0 : 1);
    		qtdSaidas = qtdSaidas + ( (c!='S') ? 0 : 1);
    		qtdEntradas = qtdEntradas + ( (c!='E') ? 0 : 1);
    		if((c!='#')&&(c!='C')&&(c!='.')&&(c!='E')&&(c!='S')&&(c!='\n')){   			
    			return CARACTER_INVALIDO;
    		}
    	}
    	
    	if( qtdQueijos == 0 ) { 
    	   return NAO_HA_QUEIJO;
     }
     
     if( qtdEntradas != 1 ) { 
    	   return MAIS_DE_UMA_SAIDA;
     }
     
     if( qtdSaidas != 1 ) { 
    	   return MAIS_DE_UMA_ENTRADA;
     }
     
     //inicializa a matriz com *s
     for(i=0;i<TAM;i++){
     	for(j=0;j<TAM;j++){
     		lab[i][j]=-8;
     		labaux[i][j]='*';
     	}
     }
     
     //Passa o labirinto para a matriz lab
     rewind(entrada);
     for(i=0;!feof(entrada);i++){
     	c='#';
     	for(j=0;(c!='\n')&&(!feof(entrada));j++){
     		fscanf(entrada, "%c", &c);
     		labaux[i][j]=c;
     		if(c=='E'){
     			lab[i][j]=0;
     		}
     		else if(c=='.'){
     			lab[i][j]=-1;
     		}
     		else if(c=='C'){
     			lab[i][j]=-2;
     		}
     		else if(c=='S'){
     			lab[i][j]=-3;
     		}
     		else{
     			lab[i][j]=-4;
     		}
     		
     	}
     }
     
     fclose(entrada);
     
     return OK;
 }
 
 
//Posiciona o rato na entrada do labirinto S
int entrar(void) {
	int i, j;
	int posicionou=0;
   
   	pRato.x=-1;
	pRato.y=-1;
   
	for(i=0;(lab[i][0]!=-8)&&(posicionou==0);i++){
		for(j=0;(lab[i][j]!=-8)&&(posicionou==0);j++){
			if(lab[i][j]==0){
				pRato.x=i;
				pRato.y=j;
				posicionou=1;
			}
		}
	}
   
	return posicionou;
}

//Marca os vizinhos disponiveis, procurando o caminho
int verifica_vizinhos(Posicao p, int qs) {
  //qs=1: procura queijo
  //qs=2: procusa saida
  Posicao aux;
	
	if(qs==1){
		if (lab[p.x+1][p.y] == -2) {
			lab[p.x+1][p.y] = lab[p.x][p.y] + 1;
			aux.x = p.x+1;
			aux.y = p.y;
			comer_queijo(aux);
			return 2;
		} 
		else if (lab[p.x-1][p.y] == -2) {
			lab[p.x-1][p.y] = lab[p.x][p.y] + 1;
			aux.x = p.x-1;
			aux.y = p.y;
			comer_queijo(aux);
			return 2;
		} 
		else if (lab[p.x][p.y+1] == -2) {
			lab[p.x][p.y+1] = lab[p.x][p.y] + 1;
			aux.x = p.x;
			aux.y = p.y+1;
			comer_queijo(aux);
			return 2;
		} 
		else if (lab[p.x][p.y-1] == -2) { 
			lab[p.x][p.y-1] = lab[p.x][p.y] + 1;
			aux.x = p.x;
			aux.y = p.y-1;
			comer_queijo(aux);
			return 2;
		}
	}
	
	else{
		if (lab[p.x+1][p.y] == -3) {
			lab[p.x+1][p.y] = lab[p.x][p.y] + 1;
			aux.x = p.x+1;
			aux.y = p.y;
			sai_lab(aux);
			return 3;
		} 
		else if (lab[p.x-1][p.y] == -3) {
			lab[p.x-1][p.y] = lab[p.x][p.y] + 1;
			aux.x = p.x-1;
			aux.y = p.y;
			sai_lab(aux);
			return 3;
		} 
		else if (lab[p.x][p.y+1] == -3) {
			lab[p.x][p.y+1] = lab[p.x][p.y] + 1;
			aux.x = p.x;
			aux.y = p.y+1;
			sai_lab(aux);
			return 3;
		} 
		else if (lab[p.x][p.y-1] == -3) { 
			lab[p.x][p.y-1] = lab[p.x][p.y] + 1;
			aux.x = p.x;
			aux.y = p.y-1;
			sai_lab(aux);
			return 3;
		}
	}

	if (lab[p.x+1][p.y] == -1) {
		lab[p.x+1][p.y] = lab[p.x][p.y] + 1;
		aux.x = p.x+1;
		aux.y = p.y;
		insere_fila(&f, aux);
	} 
	if (lab[p.x-1][p.y] == -1) {
		lab[p.x-1][p.y] = lab[p.x][p.y] + 1;
		aux.x = p.x-1;
		aux.y = p.y;
		insere_fila(&f, aux);
	} 
	if (lab[p.x][p.y+1] == -1) {
		lab[p.x][p.y+1] = lab[p.x][p.y] + 1;
		aux.x = p.x;
		aux.y = p.y+1;
		insere_fila(&f, aux);
	} 
	if (lab[p.x][p.y-1] == -1) { 
		lab[p.x][p.y-1] = lab[p.x][p.y] + 1;
		aux.x = p.x;
		aux.y = p.y-1;
		insere_fila(&f, aux);
	}
  
  return 1;
}

int percorre_labirinto(void){
	int qs=1;
	int r=2;
	
	abrirLabirinto();
	entrar();
	imprime_labaux();
	while(r==2){
		limpa_labirinto();
		cria_fila(&f);
		r=varre_labirinto(qs);
		if((r==1)&&(qs==1)){
			qs=2;
			r=2;
		}
	}
	
	if(r==3)
		return 1;
	else
		return 2;
}

int varre_labirinto(int qs){
	Posicao p;
	int r = 1;
	
	cria_fila(&f);
	limpa_labirinto();
	insere_fila(&f, pRato);
	while ((!fila_vazia(&f))&&(r==1)) {
    		p = primeiro_fila(&f);
    		r = verifica_vizinhos(p, qs);
   		remove_fila(&f);
  	}
  	
  	return r;
}

int limpa_labirinto(void){
	int i, j;

	for(i=0;lab[i][0]!=-8;i++){
     	for(j=0;lab[i][j]!=-8;j++){
     		if(lab[i][j]>=0){
     			lab[i][j]=-1;
     		}
     	}
     }
     lab[pRato.x][pRato.y]=0;
	
	return 1;
}


int comer_queijo(Posicao p){
	pRato=p;
	printf("Arroto\n");
	backtrack(pRato);
	
	return 1; 
}

int sai_lab(Posicao p){
	pRato=p;
	printf("Rato encontrou a saida");
	backtrack(pRato);
	
	return 1;
}



int backtrack(Posicao p){
	Posicao q;

	q = p;
	while (lab[q.x][q.y] > 0) {
		labaux[q.x][q.y]='o';
		if (lab[q.x+1][q.y] == lab[q.x][q.y] - 1) {
			q.x++;
		}
		else if (lab[q.x-1][q.y] == lab[q.x][q.y] - 1) {
			q.x--;
		} 
		else if (lab[q.x][q.y+1] == lab[q.x][q.y] - 1) {
			q.y++;
		} 
		else if (lab[q.x][q.y-1] == lab[q.x][q.y] - 1) { 
			q.y--;
		}
		else{
			printf("Erro no backtrack\n");
			return 0;
		}
	}
	labaux[q.x][q.y]='o';
	
	return 1; 
	
}

void imprime_lab(void){
	int i, j;
	printf("\n");
	for(i=0;lab[i][0]!=-8;i++){
     	for(j=0;lab[i][j]!=-8;j++){
     		printf("%3i", lab[i][j]);
     	}
     	printf("\n");
     }
}

void imprime_labaux(void){
	int i, j;
	printf("\n");
	for(i=0;labaux[i][0]!='*';i++){
     	for(j=0;labaux[i][j]!='*';j++){
     		printf("%c", labaux[i][j]);
     	}
     	printf("\n");
     }
}



 
 //Funcoes da fila
 
int cria_fila (Fila *F) {
  F->inicio = 0;
  F->fim = 0;
  
  return 1;
}

int fila_vazia (Fila *F) {
  return (F->inicio == F->fim);
}

int fila_cheia (Fila *F) {
  return (F->inicio == (F->fim + 1) % TAM);
}

void insere_fila (Fila *F, Posicao x) {
  if (fila_cheia(F)) {
    printf("Fila cheia!\n");
    exit(EXIT_FAILURE);
  }
  else {
    F->fim = (F->fim + 1) % TAM;
    F->f[F->fim] = x;
  }
}

void remove_fila (Fila *F) {
  if (fila_vazia(F)) {
    printf("Fila vazia!\n");
    exit(EXIT_FAILURE);
  }
  else 
    F->inicio = (F->inicio + 1) % TAM;
}

Posicao primeiro_fila (Fila *F) {
  if (fila_vazia(F)) {
    printf("Fila vazia!\n");
    exit(EXIT_FAILURE);
  }
  else 
    return (F->f[(F->inicio + 1) % TAM]);
}
 
    	
