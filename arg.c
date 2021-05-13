#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void controlematriz(int, int, int);
//void setmatriz (char *, char[][10]);
int clinha (char**);
//int ccoluna (char*);

char* matrizdin (int,int);
void swap(int , int , char , char , int , int );

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

char matrix[7][9] = {"\0\0\0\0\0\0\0\0\0",		//7x9
					  "\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0",
					  "\0\0\0\0\0\0\0\0\0"};
					  
int main (int argc, char * argv[])
{	
	int padrao = 1;
	char r;
	char s[3];
	int x,y,d;
	//char basem[10][10];
	//char* p = NULL;
	int lin = 0;
	int col = 0;


	

	
	
	while(--argc>0){													//apuração dos parametros
			r = (*++argv)[0];
			if (r == '-'){
				memset(s, '\0', sizeof(s));								//aplica nulo em todos os espaços de s
				strcpy(s,(++(*argv)));									//copia o argumento apontado pelo argv para s
	
				if(strcmp(s,"c1")==0){									//compara o argumento recebido para definir as configurações
					printf("SETANDO CFG 1\n");							//INPUT DA CONFIGURAÇÃO 1
					padrao = 1;
					}
				else if(strcmp(s,"c2")==0){							
					printf("SETANDO CFG 2\n");							//INPUT DA CONFIGURAÇÃO 2
					padrao = 0;
					}
				else if(strcmp(s,"m")==0){								//INPUT DE MOVIMENTAÇÃO
					x = (*argv)[2]-48;									//COORDENADAS x e Y. DIRECAO D
					y = (*argv)[4]-48;
					d = (*argv)[6];						
					printf("### movimento de peça ###\n");
					printf("posicao X da peca: %d\n",x);
					printf("posicao Y da peca: %d\n",y);
					printf("mover para: %c\n",d);
					}	
				else if ((strcmp(s,"c1")!=0) && (strcmp(s,"c2")!=0)){
					printf("configuração invalida\n");
					padrao = -1;
				}
				
			}
	}
//verifica qual foi configuração foi selecionada e verifica as dimensões do
//array para criar a matriz alocada dinamicamente
	
	
//######################## se cfg 1 ########################
	if (padrao == 1){				
		for (int i=0; i < 7; i++){
			for (int j=0; j< 7; j++){
				printf ("%2c",matriz1[i][j]);
				
			}
			printf ("\n");
		}
		
		printf ("\n");
		col = strlen(&matriz1[0][0]);
		
		for (lin = 1; strspn(&matriz1[lin][0],"*")<2; lin++){
		}
		lin = lin+1;
		//printf("%i\n", lin);
		//printf("%i\n", col);
		//printf("letra selecionada %c\n", matriz1[x][y]);
		//swap (x,y,d,matriz1[x][y],lin,col);
		//p  = matrizdin(lin,col);
		
		
		//recebe a coordenada X e Y, a direção C, o caracter d apontado pela coordenada, tamanho da linha e coluna
		//void swap(int x, int y, char d, char c, int lin, int col){


int cont=0;
int temp=0;
	if ((x>=1 && x < lin-1) && (y>=1 && y < col-1)){
		for(int b =1; b<lin; b++){
			for(int c=1; c<col-1; c++){
			//printf("%c\n",matriz1[b][c]);
			if ( matriz1[x][y] == matriz1[b][c])
				cont++;
			}
		}
		printf("%d\n", cont);		
		printf("entrou no if\n");
		
		switch(d){
			case ('T'):
			printf("PARA CIMA\n");
			if (matriz1[x-1][y] == ' ')
					for (int t = 0; t<cont; t++){ 
						temp = matriz1[x][y];
						matriz1[x][y] = ' ';
						matriz1[x-1][y] = temp;
					}	
				else if (matriz1[x-1][y] == matriz1[x][y])
					{}
				else {
					printf("movimento invalido\n");
				}
				for (int i=0; i < 7; i++){
					for (int j=0; j< 7; j++){
						printf ("%2c",matriz1[i][j]);
				}
				printf ("\n");
				}
			
			break;
			case ('B'):
				printf("PARA BAIXO\n");
				//swap
				if (matriz1[x+1][y] == ' ')
					for (int t = 0; t<cont; t++){ 
						temp = matriz1[x][y];
						matriz1[x][y] = ' ';
						matriz1[x+1][y] = temp;
					}	
				else if (matriz1[x+1][y] == matriz1[x][y])
					{}
				else {
					printf("movimento invalido\n");
				}
				for (int i=0; i < 7; i++){
					for (int j=0; j< 7; j++){
						printf ("%2c",matriz1[i][j]);
				}
				printf ("\n");
				}
			break;
			
			case ('E'):
			printf("PARA ESQUERDA\n");
			if (matriz1[x][y-1] == ' ')
				for (int t = 0; t<cont; t++){ 
					temp = matriz1[x][y];
					matriz1[x][y] = ' ';
					matriz1[x][y-1] = temp;
				}	
			else if (matriz1[x][y-1] == matriz1[x][y])
				{}
			for (int i=0; i < 7; i++){
			for (int j=0; j< 7; j++){
				printf ("%2c",matriz1[i][j]);
				
			}
			printf ("\n");
			}
			break;
			case ('D'):
			printf("PARA DIREITA\n");
			if (matriz1[x][y+1] == ' ')
				for (int t = 0; t<cont; t++){ 
					temp = matriz1[x][y];
					matriz1[x][y] = ' ';
					matriz1[x][y+1] = temp;
				}	
			else if (matriz1[x][y+1] == matriz1[x][y])
				{}
			for (int i=0; i < 7; i++){
			for (int j=0; j< 7; j++){
				printf ("%2c",matriz1[i][j]);
				
			}
			printf ("\n");
			}
			break;
			default:
			printf("movimento invalido\n");
			break;
		}
	}
	else {
		printf("movimento invalido\n");
	}
}
	
	
	
//######################## se cfg 2 ########################
	else if (padrao == 0){			
		for (int i=0; i < 7; i++){
			for (int j=0; j< 8; j++){
				printf ("%2c",matriz2[i][j]);
			}
			printf ("\n");
		}
		col = strlen(&matriz2[0][0]);
		for (lin = 1; strspn(&matriz2[lin][0],"*")<2; lin++){
		}
		lin = lin+1;
		printf("%i\n", lin);
		printf("%i\n", col);
		printf("letra selecionada %c\n", matriz2[x][y]);
		swap (x,y,d,matriz2[x][y],lin,col);
	}
	
//cria matriz dinamica com base nos dados lin (linha) e col (coluna)
	
	
	
}
//recebe a coordenada X e Y, a direção C, o caracter d apontado pela coordenada, tamanho da linha e coluna

void swap(int x, int y, char d, char c, int lin, int col){
int cont=0;

	if ((x>=1 && x < lin-1) && (y>=1 && y < col-1)){
		for(int i =1; x<lin-1; x++){
			for(int j=1; j<col-1; j++){
			//if ()
			}
		}		
		printf("entrou no if\n");
		switch(d){
			case ('T'):
			printf("PARA CIMA\n");
			break;
			case ('B'):
			printf("PARA BAIXO\n");
			break;
			case ('E'):
			printf("PARA ESQUERDA\n");
			break;
			case ('D'):
			printf("PARA DIREITA\n");
			break;
			default:
			printf("movimento invalido\n");
			break;
		}
	}
	else {
		printf("movimento invalido\n");
	}
}


char* matrizdin (int l, int c){

//int i,j;

// aloca um vetor com todos os elementos da matriz
return (char *) malloc (l * c * sizeof (char));


/*
// percorre a matriz
for (i=0; i < l; i++)
   for (j=0; j < c; j++)
      mat[(i*c) + j] = 0 ; // calcula a posição de cada elemento

// libera a memória alocada para a matriz
//free (mat) ;*/
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

/*int ccoluna(char **m){
int i;
	
for (i = 0; m[i] != '\n'; i++){
	}
			
return i;
}*/
