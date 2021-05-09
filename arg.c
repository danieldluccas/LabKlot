#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void controlematriz(int, int, int);
//void setmatriz (char *, char[][10]);
int clinha (char**);
//int ccoluna (char*);

int main (int argc, char * argv[])
{	
	int padrao = 1;
	char r;
	char s[3];
	//char basem[10][10];
	//char** p;
	//int lin = 0;
	//int col = 0;
	
char matriz1[7][7] = {"******\0",		//7x7
					  "*aDDb*\0",
					  "*aDDb*\0",
					  "*cdde*\0",
					  "*cghe*\0",
					  "*f  i*\0",
					  "**xx**\0"};

char matriz2[7][9] = {"********\0",		//7x8
					  "*DD aab*\0",
					  "*DD acd*\0",
					  "*eefgdd*\0",
					  "*hhijklx\0",
					  "*hiimklx\0",
					  "********\0"};
	
	
	while(--argc>0){													//apuração dos parametros
			r = (*++argv)[0];
			if (r == '-'){
				memset(s, '\0', sizeof(s));								//aplica nulo em todos os espaços de s
				strcpy(s,(++(*argv)));									//copia o argumento apontado pelo argv para s
	
				if(strcmp(s,"c1")==0){									//compara o argumento recebido para definir as configurações
					printf("configuracao 1\n");							//INPUT DA CONFIGURAÇÃO 1
					padrao = 1;
					}
				else if(strcmp(s,"c2")==0){							
					printf("configuracao 2\n");							//INPUT DA CONFIGURAÇÃO 2
					padrao = 0;
					}
				else if ((strcmp(s,"c2")!=0) && (strcmp(s,"c2")!=0)){
					printf("configuração invalida\n");
					padrao = -1;
				}
				else if(strcmp(s,"m")==0){								//INPUT DE MOVIMENTAÇÃO
					int x,y,d;											//COORDENADAS x e Y. DIRECAO D

					x = (*argv)[2]-48;	
					y = (*argv)[4]-48;
					d = (*argv)[6];						
					printf("### movimento de peça ###\n");
					printf("posicao X da peca: %d\n",x);
					printf("posicao Y da peca: %d\n",y);
					printf("mover para: %c\n",d);
					}	
			}
	}
	
	if (padrao == 1){
	for (int i=0; i < 7; i++){
		for (int j=0; j< 7; j++){
			printf ("%2c",matriz1[i][j]);
		}
		printf ("\n");
	}
	
	printf ("\n");
	}
	else if (padrao == 0){
		for (int i=0; i < 7; i++){
			for (int j=0; j< 8; j++){
				printf ("%2c",matriz2[i][j]);
			}
			printf ("\n");
		}
	}	
	
	//controlematriz(padrao, lin, col);
	
	
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
