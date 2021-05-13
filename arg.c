#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void controlematriz(int, int, int);
int clinha (char**);
void swap(int , int , char , char , int , int );

int main (int argc, char * argv[])
{	
	int padrao = 1;
	char r;
	char s[3];
	int x,y,d;
	x=y=-1;
	
	int lin = 0;
	int col = 0;
	int mctrl = 0;
	
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

char matrix[7][10] = {"\0\0\0\0\0\0\0\0\0\0",		//7x9
					  "\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0\0"};

	

	
	
	while(--argc>0){													//apuração dos parametros
		r = (*++argv)[0];
			if (r == '-'){
				memset(s, '\0', sizeof(s));								//aplica nulo em todos os espaços de s
				strcpy(s,(++(*argv)));									//copia o argumento apontado pelo argv para s
	
				if(strcmp(s,"c1")==0){									//compara o argumento recebido para definir as configurações
					//printf("SETANDO CFG 1\n");							//INPUT DA CONFIGURAÇÃO 1
					padrao = 1;
					}
				else if(strcmp(s,"c2")==0){							
					//printf("SETANDO CFG 2\n");							//INPUT DA CONFIGURAÇÃO 2
					padrao = 0;
					}
				else if(strcmp(s,"m")==0){								//INPUT DE MOVIMENTAÇÃO
					x = (*argv)[2]-48;									//COORDENADAS x e Y. DIRECAO D
					y = (*argv)[4]-48;
					d = (*argv)[6];
					mctrl = 1;						
					//printf("### movimento de peça ###\n");
					//printf("posicao X da peca: %d\n",x);
					//printf("posicao Y da peca: %d\n",y);
					//printf("mover para: %c\n",d);
					}	
				else if ((strcmp(s,"c1")!=0) && (strcmp(s,"c2")!=0)){
					printf("configuração invalida\n");
					padrao = -1;
				}
			}
	}
//verifica qual foi configuração foi selecionada e verifica as dimensões do
//array para alocar numa matriz base

//USA CONFIG 1
if (padrao == 1){
	col = strlen(&matriz1[0][0]);
		
	for (lin = 1; strspn(&matriz1[lin][0],"*")<2; lin++){
		}	
	lin = lin+1;
		
	for (int i=0; i<lin; i++){
		for (int j=0; j<col; j++){
			matrix[i][j] = matriz1[i][j];
			printf ("%2c",matrix[i][j]);
		}		
	printf ("\n");
	}
	printf ("\n");	
}

//USA CONFIG 2
else if (padrao == 0){ 
col = strlen(&matriz2[0][0]);		
	for (lin = 1; strspn(&matriz2[lin][0],"*")<2; lin++){
		}	
	lin = lin+1;	
	for (int i=0; i<lin; i++){
		for (int j=0; j<col; j++){
			matrix[i][j] = matriz2[i][j];
			printf ("%2c",matrix[i][j]);
		}		
	printf ("\n");
	}
	printf ("\n");		
}

//recebe a coordenada X e Y, a direção C, o caracter d apontado pela coordenada, tamanho da linha e coluna

int enx [5] = {0,0,0,0,0};
int eny [5] = {0,0,0,0,0};
int cont=0;
int temp=0;
int swap = 0;
int erro;
erro = 0;


	//SE OS DADOS DE ENTRADA FOREM VALIDOS PARA O TABULEIRO
	if ((x>=1 && x < lin-1) && (y>=1 && y < col-1)){
		//VARRE O TABULEIRO ATRÁS DA PEÇA E DO SEU TAMANHO
		for(int b =1; b<lin; b++){
			for(int c=1; c<col-1; c++){
			//printf("%c\n",matriz1[b][c]);
				if ( matrix[x][y] == matrix[b][c]){
					enx[cont] = b;
					eny[cont] = c;
					//printf("%d,%d\n",enx[cont],eny[cont]);
					cont++;
				}
			}
		}
		
		switch(d){
			case ('T'):
			//printf("PARA CIMA\n");
			
			if ((matrix[x-1][y] == ' ') || (matrix[x-1][y] == matrix[x][y])){
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
			
			for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}
			if (erro == 1)
				printf("impossivel movimentar peça em %d,%d para cima\n",x,y);
			break;
			case ('B'):
			//printf("PARA BAIXO\n");
			
			if ((matrix[x+1][y] == ' ') || (matrix[x+1][y] == matrix[x][y])){
					//VERIFICA SE TODOS OS ENDEREÇOS DA PEÇA SE DIRECIONAM
					//PARA UM MOVIMENTO POSSIVEL
					for (int t = 0; t<cont; t++){ 
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
			
			for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}
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
			
			for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}
			if (erro == 1){
				printf("impossivel movimentar peça em %d,%d para esquerda\n",x,y);
			}
			break;
			
			case ('D'):
			//printf("PARA DIREITA\n");
			if ((matrix[x][y+1] == ' ') || (matrix[x][y+1] == matrix[x][y])){
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
			
			for (int i=0; i<lin; i++){
				for (int j=0; j<col; j++){
					printf ("%2c",matrix[i][j]);
				}		
			printf ("\n");
			}
			if (erro == 1)
				printf("impossivel movimentar peça em %d,%d para direita\n",x,y);
				
			break;
			
			default:
			printf("movimento invalido\n");
			break;
		}
		
	}
	else if(mctrl == 0){
		printf ("\n");
		} 
	else {
		printf("movimento invalido\n");
	}
}

void controlematriz (int p, int l, int c){

/*char matriz1[][7] ={"******\n",
					  "*aDDb*\n",
					  "*aDDb*\n",
					  "*cdde*\n",
					  "*cghe*\n",
					  "*f00i*\n",
					  "**  **\n"};

char matriz2[][9] = {"********\n",
					  "*DD0aab*\n",
					  "*DD0acd*\n",
					  "*eefgdd*\n",
					  "*hhijkl \n",
					  "*hiimkl \n",
					  "********\n"};*/


	if (p == 1){
		printf("configuracao 1\n");
		//setmatriz(matriz1,m);
		//l = clinha(matriz1);
		//c = ccoluna(matriz1);
	}

	

	else if (p == 0){
		printf("configuracao 2\n");
		//setmatriz(matriz2,m);
	}
						 
	else if (p==-1){
	printf("configuração invalida\n");
	}

}

int clinha(char **m){
int i;
int r=0;
	
for (i = 0; *m[i] != '\0'; i++){
	if (*m[i] == '\n'){
	r++;
	}
}	
return r;
}
