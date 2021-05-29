#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct matrixd{
  char mat [7][10];
  char num;
  struct matrixd *pont;
};


void leituraarquivo(char [20]);
void buscacfg (int , char m[7][10], char [20]);
void imprime (char [7][10], int, int);
void movepeca(char [7][10], int ,int ,char,int, int);
int fmovepeca (char [7][10], int , int , char , int , int );
void addItem (struct matrixd *, char , char [7][10]);
struct matrixd *aloca();
void imprimelista(struct matrixd *, int,int);
int possibilidades (char [7][10], int , int );


int main (int argc, char * argv[]){
//FILE* fp = NULL;

//typedef struct matrizencad me;

char r;
char s[20];
char filename [20];
char com [10];

char matriz1[7][7] = {"******\0",		//7x7
					  "*aDDb*\0",
					  "*aDDb*\0",
					  "*cdde*\0",
					  "*cghe*\0",
					  "*f  i*\0",
					  "**  **\0"};

char matriz2[7][9] = {"********\0",		//7x9
					  "*DD aab*\0",
					  "*DD acd*\0",
					  "*eefgdd*\0",
					  "*hhijkl \0",
					  "*hiimkl \0",
					  "********\0"};

char matrix[7][10] = {"\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0"};

int padrao = 0;
int x,y,d;
	x=y=-1;
	
int col=0;
int lin=0;
int cfgup=0;



//INICIALIZAÇAO DE ARGUMENTOS
//ABERTURA E LEITURA DO ARQUIVO
while(--argc>0){												//apuração dos parametros
	r = (*++argv)[0];
	if (r == '-'){
		memset(s, '\0', sizeof(s));								//aplica nulo em todos os espaços de s
		strcpy(s,(++(*argv)));									//copia o argumento apontado pelo argv para s
	
		if(strcmp(s,"f")==0){									//compara o argumento recebido para definir as configurações
			//printf("SETANDO NOME DO ARQUIVO\n");				//INPUT DA CONFIGURAÇÃO 1
			//filename = *(++argv);
			memset(filename, '\0', sizeof(s));	
			strcpy(filename,(argv[1]));
			//printf("%s \n", filename);
			padrao = 1;
		}				
		else {
			printf("comando não reconhecido\n");
			EXIT_SUCCESS;
		}
	}
}


printf("***************************************************************************\n");
printf("*############################   KLOTSKI    ###############################*\n");
printf("*-------------------------------------------------------------------------*\n");
printf("*############################   COMANDOS   ###############################*\n");
printf("***************************************************************************\n");
printf("\n");
printf("===========================================================================\n");
printf("l -> LISTA OS TABULEIROS\n");
printf("c[n] -> ESCOLHER A CFG. EX: C1\n");
printf("m [linha] [coluna] [c]-> MOVE A PEÇA INDICADA PELA COORDENADA. EX: m 1 1 D\n");
printf("--->  c: 1-6	c: T (cima), B (baixo), E (esquerda), D (direita)    \n");
printf("===========================================================================\n");

struct matrixd dados;
struct matrixd *cabecalista;
cabecalista = &dados;
dados.pont = NULL;
char decisao;
int contador;

contador = 0;

while(1){
	//while((com = gets()) != '\n' ){
	memset(com, '\0', sizeof(com));
	fgets(com, 10, stdin);
	//puts(com);

	if(com [0] == 'l' || com[0] == 'L'){
		switch(padrao){
			case(0): //haikori.txt
			//printf("CASE 0\n");
				strcpy(filename,"haikori.txt");
				leituraarquivo (filename);
			break;
				
			case(1): //meuarquivo.txt
				//printf("CASE 1\n");
				leituraarquivo(filename);
			break;
		}
	}
	else if (com[0] == 'c' || com[0] == 'C')
	{
		if (com[1] == '1')
		{	
			if (cfgup == 1)
			{
				printf("###       JA EXISTE OUTRA CONFIGURAÇÃO SETADA       ###\n");
				printf("###       VOCE DESEJA REALMENTE MUDAR A CFG?        ###\n");
				printf("### CASO SEJA S OS DADOS ANTERIORES SERÃO APAGADOS  ###\n");
				printf("###  [s] ou [n]? 	###\n");
				
				
				while(decisao != 's' && decisao != 'n')
				{
					//printf("### [s] ou [n]?	###\n");
					decisao = getchar();
					
				}
				if (decisao == 's')
				{
					free(dados.pont);
					contador = 0;
					//cfgup = 0;
					col = strlen(&matriz1[0][0]);
				
					for (lin = 1; strspn(&matriz1[lin][0],"*")<2; lin++)
					{
						}	
					lin = lin+1;
						
					for (int i=0; i<lin; i++)
					{
						for (int j=0; j<col; j++)
						{
							matrix[i][j] = matriz1[i][j];
						}
					}
					addItem (cabecalista, 1, matrix);
					
					imprime (matrix,lin,col);
					
				}
				else if (decisao == 'n')
				{
						decisao = 0;
				}
			}
			
			else if (cfgup==0)
			{
				cfgup = 1;
				//printf("tabuleiro 1\n");
				//buscacfg(cfg, matrix, filename);
				//printf("%s\n",matrix[0]);
				col = strlen(&matriz1[0][0]);
				
				for (lin = 1; strspn(&matriz1[lin][0],"*")<2; lin++){
					}	
				lin = lin+1;
					
				for (int i=0; i<lin; i++)
				{
					for (int j=0; j<col; j++)
					{
						matrix[i][j] = matriz1[i][j];
						//printf ("%2c",matrix[i][j]);
					}		
				//printf ("\n");
				}
				addItem (cabecalista, 1, matrix);
				imprime (matrix,lin,col);
					decisao = 0;
				}
				else if (decisao == 'n')
				{
						decisao = 0;
				}

			
		}
		
		
		if (com[1] == '2')
		{
			if (cfgup == 1)
			{
				printf("###       JA EXISTE OUTRA CONFIGURAÇÃO SETADA       ###\n");
				printf("###       VOCE DESEJA REALMENTE MUDAR A CFG?        ###\n");
				printf("### CASO SEJA S OS DADOS ANTERIORES SERÃO APAGADOS  ###\n");
				printf("###  [s] ou [n]? 	###\n");
				char decisao;
				decisao = 0;
				while(decisao != 's' && decisao != 'n')
				{
					//printf("### [s] ou [n]?	###\n");
					decisao = getchar();
					
				}
				if (decisao == 's')
				{
					free(dados.pont);
					contador = 0;
					//cfgup = 0;
					col = strlen(&matriz2[0][0]);
				
					for (lin = 1; strspn(&matriz2[lin][0],"*")<2; lin++){
						}	
					lin = lin+1;
						
					for (int i=0; i<lin; i++)
					{
						for (int j=0; j<col; j++){
							matrix[i][j] = matriz2[i][j];
						}
					}
					addItem (cabecalista, 1, matrix);
					imprime (matrix,lin,col);
					decisao = 0;
				}
				else if (decisao == 'n')
				{
						decisao = 0;
				}
			}
			
			else if(cfgup == 0)
			{
				cfgup = 1;
				//printf("tabuleiro 2\n");
				col = strlen(&matriz2[0][0]);
				
				for (lin = 1; strspn(&matriz2[lin][0],"*")<2; lin++){
					}	
				lin = lin+1;
				for (int i=0; i<lin; i++){
					for (int j=0; j<col; j++){
						matrix[i][j] = matriz2[i][j];
						//printf ("%2c",matrix[i][j]);
					}		
				//printf ("\n");
				}
				imprime (matrix,lin,col);
				addItem (cabecalista, 1, matrix);
			}
		}
	}	
	else if (com[0] == 'm' || com[0] == 'M'){
		if (cfgup == 1){
			x = com[2]-48;
			y = com[4]-48;
			d = com[6];
			printf("### movimento de peça ###\n");
			printf("posicao LINHA da peca: %d\n",x);
			printf("posicao COLUNA da peca: %d\n",y);
			printf("mover para: %c\n",d);
			
			int teste;
			if((teste = fmovepeca(matrix, x, y, d, lin, col)) == 1)
			{
				addItem (cabecalista, 1, matrix);
				contador++;
				printf("Movimento %d\n",contador);
				imprime (matrix,lin,col);
				}
			else if (teste == 0)
			{	
				printf("\n");
				printf("Movimento inválido\n");
				printf("******************\n");
				printf("Possibilidades\n");
				possibilidades(matrix, lin, col);
				}
			
			
		}
		else {
		printf("### SELECIONE UMA CONFIGURAÇÃO ###\n");
		}
		
	}
	else if (com[0] == 'p' || com[0] == 'P')
	{
		
		if (cfgup==1)
		{
			imprimelista(cabecalista,lin,col);
			printf("### FIM DA LISTA ###\n");
			}
		else
			printf("### LISTA VAZIA ###\n");
		}
}

}

void leituraarquivo (char fn[20]){

	FILE *fp;

	//abrindo arquivo para leitura("r") por linha de comando
	fp = fopen(fn, "r");
	
	if (fp == NULL){
		fp = fopen("haikori.txt", "r");
	}
	char c [100];
	int lctrl = 0;
	int cctrl = 1;
	int ncfg = 0;
	int tam = 0;
	while(1){
		fgets(c, 100, fp);
		if (feof(fp)){
			break;
		}
		//faz a leitura da string e identifica como tabuleiro
		//se for linha do tabuleiro
		if (strchr(c, '*') != NULL){
			if ((strspn(c,"**") > 1)){
				//imprime a orientação de coluna antes da primeira linha
				//se primeira linha da matriz
				if (lctrl == 0){
					tam = strlen(c);
					//printf("\n");
					for(int i=0; i<tam-2; i++){
						if (i==0)
							printf("   ");
						if ((i>0) && (i<tam))
							printf("%2i",i);
					}
					printf("\n ");
					lctrl = 1;
					//imprime asteriscos da primeira linha
					for(int i=0; c[i]!= '\n'; i++)
						printf("%2c",c[i]);
				}
				//se última linha da matriz
				else if (lctrl == 1){
					printf(" ");
					for(int i=0; c[i]!= '\n'; i++)
						printf("%2c",c[i]);
					lctrl = 0;
					cctrl = 1;
				}
			}
			else {
				printf("%d",cctrl);
				for(int i=0; c[i]!= '\n'; i++){
					printf("%2c",c[i]);
				}
				cctrl++;
			}
			printf("\n");	
		}
		//compara se é uma linha em branco
		else if(strcmp(c,"\n")==0)
			printf("%s",c);
		//se não, é nome de uma configuração de tabuleiro
		else {
			ncfg++;
			printf("%d\n",ncfg);
			printf("%s",c);
			}
		
	}
	
	fclose (fp);
}

//cf = configuração de jogo (0 = nada; 1 = jogo 1; 2 = jogo = 2)
//m = matriz auxiliar matrix
//fn = filename = argv [1]
//coloca o jogo selecionado na matriz
void buscacfg (int cf, char m[7][10], char fn[20]){
	FILE *fp;

	//abrindo arquivo para leitura("r") por linha de comando
	fp = fopen(fn, "r");
	
	if (fp == NULL){
		fp = fopen("haikori.txt", "r");
	}
	
	//char *smatriz = NULL;
	char c[100];
	//char ch = '*';
	
	/*int lctrl = 0;
	int cctrl = 1;
	int ncfg = 0;
	int tam = 0;
	*/
	
	
	//while(1){
		fgets(c, 100, fp);
		printf("%s",c);
		if (feof(fp)){
			//break;
		}
		//else if(strcmp(c,"\n")==0){}
			//break;

		//else if (strchr(c, '*') != NULL){
			//ncfg++;
			//printf("%d\n",ncfg);
			//printf("%s",c);
			//m[i][0] = c;
			//printf("%s",m);
			//i++;
			
			//}
	//}
	
	fclose (fp);
	
	
}

void imprime (char m[7][10], int l, int co)
{
	
for (int i=0; i<l; i++)
{
	if(i==0)
	{
		for(int r=0; r<co-1; r++)
		{
			if (r==0)
				printf("   ");
			if ((r>0) && (r<co))
				printf("%2i",r);
		}
		printf ("\n");
	}	
	else if(i>0 && i<l-1)
	{
		printf ("%i",i);
		}
	if (i==0 || i==l-1)
	{
		printf(" ");
	}		
	for (int j=0; j<co; j++)
	{
		printf ("%2c",m[i][j]);
	}		
	printf ("\n");
}

}


void movepeca (char matrix[7][10], int x, int y, char d, int lin, int col)
{

int enx [5] = {0,0,0,0,0};
int eny [5] = {0,0,0,0,0};
int cont=0;
int temp=0;
int swap = 0;
int erro;
erro = 0;


	//SE OS DADOS DE ENTRADA FOREM VALIDOS PARA O TABULEIRO
	if ((x>=1 && x < lin-1) && (y>=1 && y < col-1))
	{
		//VARRE O TABULEIRO ATRÁS DA PEÇA E DO SEU TAMANHO
		for(int b =1; b<lin; b++)
		{
			for(int c=1; c<col-1; c++)
			{
			//printf("%c\n",matriz1[b][c]);
				if ( matrix[x][y] == matrix[b][c])
				{
					enx[cont] = b;
					eny[cont] = c;
					//printf("%d,%d\n",enx[cont],eny[cont]);
					cont++;
				}
			}
		}
		
		switch(d)
		{
			case ('T'):
			//printf("PARA CIMA\n");
			
			if ((matrix[x-1][y] == ' ') || (matrix[x-1][y] == matrix[x][y]))
			{
					//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
					//PARA UM MOVIMENTO POSSIVEL
					for (int t = 0; t<cont; t++){ 
						if ((matrix[enx[t]-1][eny[t]] == ' ') || (matrix[enx[t]-1][eny[t]] == matrix[x][y])){
							swap = 1;
							//printf("swap %d\n",swap);
							}
						else {
							swap = 0;
							//printf("swap %d\n",swap);
							t=cont;
						}
					}
				
					if (swap == 1){
						//troca posições
						//limpa as posições da peça com ' ' e em seguida
						// escreve no endereço de destino com o valor da peça
						temp = matrix[x][y];
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]] = ' ';
						for(int t = 0; t<cont; t++)
							matrix[enx[t]-1][eny[t]] = temp;
					}
					else if (swap == 0){
						erro = 1;
						printf("movimento inválido\n");
					}
			}	
			/*
			for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}*/
			if (erro == 1)
				printf("impossivel movimentar peça em %d,%d para cima\n",x,y);
			break;
			
			case ('B'):
			//printf("PARA BAIXO\n");
			
			if ((matrix[x+1][y] == ' ' && x+1<lin-1) || (matrix[x+1][y] == matrix[x][y]))
			{
					//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
					//PARA UM MOVIMENTO POSSIVEL
					for (int t = 0; t<cont; t++)
					{ 
						if ((matrix[enx[t]+1][eny[t]] == ' ') || (matrix[enx[t]+1][eny[t]] == matrix[x][y])){
							swap = 1;
							//printf("swap %d\n",swap);
							}
						else {
							swap = 0;
							//printf("swap %d\n",swap);
							t=cont;
						}
					}
				
					if (swap == 1){
						//troca posições
						//limpa as posições da peça com ' ' e em seguida
						// escreve no endereço de destino com o valor da peça
						temp = matrix[x][y];
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]] = ' ';
						for(int t = 0; t<cont; t++)
							matrix[enx[t]+1][eny[t]] = temp;
					}
					else {
						erro = 1;
						//printf("movimento inválido\n");
					}
			}	
			
			/*for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}*/
			if (erro == 1)
				printf("impossivel movimentar peça em %d,%d para baixo\n",x,y);
			break;
			
			case ('E'):
			//printf("PARA ESQUERDA\n");
			if ((matrix[x][y-1] == ' ') || (matrix[x][y-1] == matrix[x][y])){
					//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
					//PARA UM MOVIMENTO POSSIVEL
					for (int t = 0; t<cont; t++){ 
						if ((matrix[enx[t]][eny[t]-1] == ' ') || (matrix[enx[t]][eny[t]-1] == matrix[x][y])){
							swap = 1;
							//printf("swap %d\n",swap);
							}
						else {
							swap = 0;
							//printf("swap %d\n",swap);
							t=cont;
						}
					}
				
					if (swap == 1){
						//troca posições
						//limpa as posições da peça com ' ' e em seguida
						// escreve no endereço de destino com o valor da peça
						temp = matrix[x][y];
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]] = ' ';
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]-1] = temp;
					}
					else if(swap == 0){
						erro = 1;
						//printf("movimento inválido\n");
					}
			}	
			
			/*for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}*/
			if (erro == 1)
				printf("impossivel movimentar peça em %d,%d para esquerda\n",x,y);
			
			break;
			
			case ('D'):
			//printf("PARA DIREITA\n");
			if ((matrix[x][y+1] == ' ' && y+1<col-1) || (matrix[x][y+1] == matrix[x][y]))
			{
					//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
					//PARA UM MOVIMENTO POSSIVEL
					for (int t = 0; t<cont; t++){ 
						if ((matrix[enx[t]][eny[t]+1] == ' ') || (matrix[enx[t]][eny[t]+1] == matrix[x][y])){
							swap = 1;
							}
						else {
							swap = 0;
							t=cont;
						}
					}
				
					if (swap == 1){
						//troca posições
						//limpa as posições da peça com ' ' e em seguida
						// escreve no endereço de destino com o valor da peça
						temp = matrix[x][y];
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]] = ' ';
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]+1] = temp;
					}
					else if (swap == 0){
						erro=1;
						//printf("movimento inválido\n");
					}
			}	
			
			/*for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}*/
			if (erro == 1)
				printf("impossivel movimentar peça em %d,%d para direita\n",x,y);
				
			break;
			
			default:
			printf("movimento invalido\n");
			break;
		}
		
	}
	/*else if(mctrl == 0){
		printf ("\n");
		} 
	else {
		printf("movimento invalido\n");
	}*/



}

int fmovepeca (char matrix[7][10], int x, int y, char d, int lin, int col)
{

int enx [5] = {0,0,0,0,0};
int eny [5] = {0,0,0,0,0};
int cont=0;
int temp=0;
int swap = 0;
int erro;
erro = 0;


	//SE OS DADOS DE ENTRADA FOREM VALIDOS PARA O TABULEIRO
	if ((x>=1 && x < lin-1) && (y>=1 && y < col-1))
	{
		//VARRE O TABULEIRO ATRÁS DA PEÇA E DO SEU TAMANHO
		for(int b =1; b<lin; b++)
		{
			for(int c=1; c<col-1; c++)
			{
			//printf("%c\n",matriz1[b][c]);
				if ( matrix[x][y] == matrix[b][c])
				{
					enx[cont] = b;
					eny[cont] = c;
					//printf("%d,%d\n",enx[cont],eny[cont]);
					cont++;
				}
			}
		}
		
		switch(d)
		{
			case ('T'):
			//printf("PARA CIMA\n");
			
			if ((matrix[x-1][y] == ' ') || (matrix[x-1][y] == matrix[x][y]))
			{
					//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
					//PARA UM MOVIMENTO POSSIVEL
					for (int t = 0; t<cont; t++){ 
						if ((matrix[enx[t]-1][eny[t]] == ' ') || (matrix[enx[t]-1][eny[t]] == matrix[x][y])){
							swap = 1;
							//printf("swap %d\n",swap);
							}
						else {
							swap = 0;
							//printf("swap %d\n",swap);
							t=cont;
						}
					}
				
					if (swap == 1){
						//troca posições
						//limpa as posições da peça com ' ' e em seguida
						// escreve no endereço de destino com o valor da peça
						temp = matrix[x][y];
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]] = ' ';
						for(int t = 0; t<cont; t++)
							matrix[enx[t]-1][eny[t]] = temp;
						return 1;
					}
					else if (swap == 0){
						erro = 1;
						printf("movimento inválido\n");
						
					}
			}	
			/*
			for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}*/
			if (erro == 1)
				printf("impossivel movimentar peça em %d,%d para cima\n",x,y);
			return 0;
			//break;
			
			case ('B'):
			//printf("PARA BAIXO\n");
			
			if ((matrix[x+1][y] == ' ' && x+1<lin-1) || (matrix[x+1][y] == matrix[x][y]))
			{
					//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
					//PARA UM MOVIMENTO POSSIVEL
					for (int t = 0; t<cont; t++)
					{ 
						if ((matrix[enx[t]+1][eny[t]] == ' ') || (matrix[enx[t]+1][eny[t]] == matrix[x][y])){
							swap = 1;
							//printf("swap %d\n",swap);
							}
						else {
							swap = 0;
							//printf("swap %d\n",swap);
							t=cont;
						}
					}
				
					if (swap == 1){
						//troca posições
						//limpa as posições da peça com ' ' e em seguida
						// escreve no endereço de destino com o valor da peça
						temp = matrix[x][y];
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]] = ' ';
						for(int t = 0; t<cont; t++)
							matrix[enx[t]+1][eny[t]] = temp;
						return 1;
					}
					else {
						erro = 1;
						//printf("movimento inválido\n");
					}
			}	
			
			/*for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}*/
			if (erro == 1)
				printf("impossivel movimentar peça em %d,%d para baixo\n",x,y);
			return 0;
			break;
			
			case ('E'):
			//printf("PARA ESQUERDA\n");
			if ((matrix[x][y-1] == ' ') || (matrix[x][y-1] == matrix[x][y])){
					//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
					//PARA UM MOVIMENTO POSSIVEL
					for (int t = 0; t<cont; t++){ 
						if ((matrix[enx[t]][eny[t]-1] == ' ') || (matrix[enx[t]][eny[t]-1] == matrix[x][y])){
							swap = 1;
							//printf("swap %d\n",swap);
							}
						else {
							swap = 0;
							//printf("swap %d\n",swap);
							t=cont;
						}
					}
				
					if (swap == 1){
						//troca posições
						//limpa as posições da peça com ' ' e em seguida
						// escreve no endereço de destino com o valor da peça
						temp = matrix[x][y];
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]] = ' ';
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]-1] = temp;
						return 1;
					}
					else if(swap == 0){
						erro = 1;
						//printf("movimento inválido\n");
					}
			}	
			
			/*for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}*/
			if (erro == 1)
				printf("impossivel movimentar peça em %d,%d para esquerda\n",x,y);
			return 0;
			break;
			
			case ('D'):
			//printf("PARA DIREITA\n");
			if ((matrix[x][y+1] == ' ' && y+1<col-1) || (matrix[x][y+1] == matrix[x][y]))
			{
					//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
					//PARA UM MOVIMENTO POSSIVEL
					for (int t = 0; t<cont; t++){ 
						if ((matrix[enx[t]][eny[t]+1] == ' ') || (matrix[enx[t]][eny[t]+1] == matrix[x][y])){
							swap = 1;
							}
						else {
							swap = 0;
							t=cont;
						}
					}
				
					if (swap == 1){
						//troca posições
						//limpa as posições da peça com ' ' e em seguida
						// escreve no endereço de destino com o valor da peça
						temp = matrix[x][y];
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]] = ' ';
						for(int t = 0; t<cont; t++)
							matrix[enx[t]][eny[t]+1] = temp;
						return 1;
					}
					else if (swap == 0){
						erro=1;
						//printf("movimento inválido\n");
					}
			}	
			
			/*for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}*/
			if (erro == 1)
				printf("impossivel movimentar peça em %d,%d para direita\n",x,y);
			return 0;	
			break;
			
			default:
			printf("movimento invalido\n");
			return 0;
			break;
		}
		
	}
	else
		return 0;
	/*else if(mctrl == 0){
		printf ("\n");
		} 
	else {
		printf("movimento invalido\n");
	}*/



}


struct matrixd *aloca(){
  return malloc (sizeof (struct matrixd));  
}

void addItem (struct matrixd *head, char n, char matr[7][10]){
  struct matrixd *aux, *novo;
  
  aux = head;
  
  while(aux->pont != NULL){
      aux = aux->pont;
    }
    
    novo = aloca();
    novo->num = n;
    for (int i=0; i<7; i++){
      for(int j=0; j<10; j++){
        novo->mat[i][j] = matr[i][j];
      }
    }
    novo ->pont = NULL;
    
    aux->pont = novo;
}

void imprimelista(struct matrixd *head, int line,int colu){
//struct matrixd *aux;

//aux = head;

 while(head->pont != NULL){
	head = head->pont;
	imprime(head->mat, line, colu);
	printf("\n");
      
    }
	
}

int possibilidades (char matrix[7][10], int lin, int col)
{

int enx [5] = {0,0,0,0,0};
int eny [5] = {0,0,0,0,0};
int endxb [5] = {0,0,0,0,0};
int endyb [5] = {0,0,0,0,0};
char possiv[7] = {0,0,0,0,0,0,0};
int cont=0;
int contpossiv = 0;
//int temp=0;
int swap = 0;
//int erro;
//erro = 0;


for (int m = 1; m <lin-1; m++)
{
	for(int n = 1; n <col-1; n++)
	{
		if (matrix[m][n] == ' ')
		{
			//printf("encontrei espaço\n");
			//printf("coordenada: %d,%d\n",m,n);
			enx[cont] = m;
			eny[cont] = n;
			cont++; 
			}
		}
}

cont=0;
for (int loopespaco=0; loopespaco<2; loopespaco++)
{
	for(int a=1; a!=5; a++)
	{
		cont=0;
		switch(a)
		{
			//testa esquerda
			case(1):
			{
				char peca;
				//confere se a peça na esquerda é um caractere do alfabeto
				if( isalpha(matrix[enx[loopespaco]][eny[loopespaco]-1]))
				{
					peca = matrix[enx[loopespaco]][eny[loopespaco]-1];
					//printf("encontrei letra a esquerda\n");
					//printf("%c\n",peca);
					//varre a matriz a procura por caracteres iguais
					for(int b =1; b<lin-1; b++)
					{
						for(int c=1; c<col-1; c++)
						{	//se na posicao da varredura houver a peça procurada
							//armazena o endereço 
							if ( peca == matrix[b][c])
							{
								endxb[cont] = b;
								endyb[cont] = c;
								cont++;
							}
						}
					}
							//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
							//PARA UM MOVIMENTO POSSIVEL
							for (int t = 0; t<cont; t++)
							{ 
								if ((matrix[endxb[t]][endyb[t]+1] == ' ') || (matrix[endxb[t]][endyb[t]+1] == peca))
								{
									swap = 1;
									
									}
								else {
									swap = 0;
									
									t=cont;
								}
							}
						
							if (swap == 1){
								int teste = 0;
								for (int u=0; u<7; u++)
									if (possiv[u] == peca)
										teste = 1;
								if (teste == 0)
								{
									printf("%c para direita\n",peca);
									possiv[contpossiv] = peca;
									contpossiv++;
								}
								
							}
							else if (swap == 0){
								
							}
					
				}
				break;
			}
			//testa direita
			case(2):
			{
				char peca;
				//confere se a peça na direita é um caractere do alfanumérico
				if( isalpha(matrix[enx[loopespaco]][eny[loopespaco]+1]))
				{
					peca = matrix[enx[loopespaco]][eny[loopespaco]+1];
					
					//varre a matriz a procura por caracteres iguais
					for(int b =1; b<lin-1; b++)
					{
						for(int c=1; c<col-1; c++)
						{	//se na posicao da varredura houver a peça procurada
							//armazena o endereço 
							if ( peca == matrix[b][c])
							{
								endxb[cont] = b;
								endyb[cont] = c;
								cont++;
							}
						}
					}
							//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
							//PARA UM MOVIMENTO POSSIVEL
							for (int t = 0; t<cont; t++)
							{ 
								if ((matrix[endxb[t]][endyb[t]-1] == ' ') || (matrix[endxb[t]][endyb[t]-1] == peca))
								{
									swap = 1;
									
									}
								else {
									swap = 0;
									
									t=cont;
								}
							}
						
							if (swap == 1){
								int teste = 0;
								for (int u=0; u<7; u++)
									if (possiv[u] == peca)
										teste = 1;
								if (teste == 0)
								{
								printf("%c para esquerda\n",peca);
								possiv[contpossiv] = peca;
									contpossiv++;
								}
								
							}
							else if (swap == 0){
								
							}
				}
				break;
			}
			
			//testa cima
			case(3):
			{
				char peca;
				//confere se a peça no topo é um caractere do alfanumérico
				if( isalpha(matrix[enx[loopespaco]-1][eny[loopespaco]]))
				{
					peca = matrix[enx[loopespaco]-1][eny[loopespaco]];
					
					//varre a matriz a procura por caracteres iguais
					for(int b =1; b<lin-1; b++)
					{
						for(int c=1; c<col-1; c++)
						{	//se na posicao da varredura houver a peça procurada
							//armazena o endereço 
							if ( peca == matrix[b][c])
							{
								endxb[cont] = b;
								endyb[cont] = c;
								cont++;
							}
						}
					}
							//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
							//PARA baixo
							for (int t = 0; t<cont; t++)
							{ 
								if ((matrix[endxb[t]+1][endyb[t]] == ' ') || (matrix[endxb[t]+1][endyb[t]] == peca))
								{
									swap = 1;
									
									}
								else {
									swap = 0;
									
									t=cont;
								}
							}
						
							if (swap == 1){
								int teste = 0;
								for (int u=0; u<7; u++)
									if (possiv[u] == peca)
										teste = 1;
								if (teste == 0)
								{
								printf("%c para baixo\n",peca);
								possiv[contpossiv] = peca;
									contpossiv++;
								}
								
								
							}
							else if (swap == 0){
								
							}
				}
				break;
			}
			
			//testa baixo
			case(4):
			{
				char peca;
				//confere se a peça na parte de baixo é um caractere do alfanumérico
				if( isalpha(matrix[enx[loopespaco]+1][eny[loopespaco]]))
				{
					peca = matrix[enx[loopespaco]+1][eny[loopespaco]];
					
					//varre a matriz a procura por caracteres iguais
					for(int b =1; b<lin-1; b++)
					{
						for(int c=1; c<col-1; c++)
						{	//se na posicao da varredura houver a peça procurada
							//armazena o endereço 
							if ( peca == matrix[b][c])
							{
								endxb[cont] = b;
								endyb[cont] = c;
								cont++;
							}
						}
					}
							//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
							//PARA CIMA
							for (int t = 0; t<cont; t++)
							{ 
								if ((matrix[endxb[t]-1][endyb[t]] == ' ') || (matrix[endxb[t]-1][endyb[t]] == peca))
								{
									swap = 1;
									
									}
								else {
									swap = 0;
									
									t=cont;
								}
							}
						
							if (swap == 1){
								int teste = 0;
								for (int u=0; u<7; u++)
									if (possiv[u] == peca)
										teste = 1;
								if (teste == 0)
								{
								printf("%c para cima\n",peca);
								possiv[contpossiv] = peca;
									contpossiv++;
								}
								
							}
							else if (swap == 0){
								
							}
				}
				break;
			}
				 
			default:
			{printf("entrei default");
				break;
				}
				 
				 }
		
		}
		
	}
return 0;
}

