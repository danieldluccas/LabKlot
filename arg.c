#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main (int argc, char * argv[])
{	
	int padrao = 1;
	char r;
	char s[3];
	
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

if (p == 1){
printf("configuracao 1\n");

}

else if (p == 0){
printf("configuracao 2\n");
}

char matriz1[][9] = {"********",
					"*DD aab*",
					"*DD acd*",
					"*eefgdd*",
					"*hhijkl ",
					"*hiimkl ",
					"********",};

}
