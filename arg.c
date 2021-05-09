#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void controlematriz(int);
//void setmatriz (char *, char[][10]);

int main (int argc, char * argv[])
{	
	int padrao = 1;
	char r;
	char s[3];
	//char basem[10][10];
	//char** p;
	
	
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
	
	controlematriz(padrao);
	
}


void controlematriz (int p){

char matriz1[][7] =  {"******\n",
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
					  "********\n"};


	if (p == 1){
		printf("configuracao 1\n");
		//setmatriz(matriz1,m);
	}

	

	else if (p == 0){
		printf("configuracao 2\n");
		//setmatriz(matriz2,m);
	}
						 
	else if (p==-1){
	printf("configuração invalida\n");
	}

}

/*void setmatriz(char * a, char *b){
	

}*/
