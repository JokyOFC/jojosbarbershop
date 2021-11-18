#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <curses.h>
 
void finalizar() {

	
	int count;
		do{
			int finalizar;
			printf("\n\t\t\t\t\t\t     Jojo's barbery\t\t\n");
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t     Deseja finalizar o Servico? \t\t\t#\n");
			printf("\t\t\t#########################################################################\n");
			printf("1 - SIM \n2 - NAO\n3 - voltar\n");
			scanf("%d", &finalizar);
			
			switch(finalizar){
				
				case 1:
					printf("\n Servico finalizado com Sucesso \n");
					scanf("%d", &finalizar);
					count = 1;
					system("pause");
				break;					
				case 2:
					printf("\n nao\n");
					scanf("%d", &finalizar);
					system("pause");
					break;
				
				default:
					printf("\nselecione uma opcao valida\n");
					system("@cls||clear");
					count = true;
			}
		
		} while (count != 0);
}


void cancelar()
{
	int count;
		do{
			int cancelar;
			printf("\n\t\t\t\t\t\t     Jojo's barbery\t\t\n");
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t     Deseja Cancelar o Servico? \t\t\t#\n");
			printf("\t\t\t#########################################################################\n");
			printf("1 - SIM \n2 - NAO\n3 - voltar\n");
			scanf("%d", &cancelar);
			
			switch(cancelar){
				
				case 1:
					printf("\n Servico Cancelado com Sucesso \n");
					scanf("%d", &cancelar);
					system("pause");
					
				case 2:
					printf("\n ...\n");
					scanf("%d", &cancelar);
					system("pause");
					break;
				
				default:
					printf("\nselecione uma opcao valida\n");
					system("@cls||clear");
					count = true;
			}
		
		} while (count != 0);
}


void alterar()
{
   	int count;
		do{
			int alterar;
			printf("\n\t\t\t\t\t\t     Jojo's barbery\t\t\n");
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t     Deseja Alterar o Servico?    \t\t\t#\n");
			printf("\t\t\t#########################################################################\n");
			printf("1 - SIM \n2 - NAO\n3 - voltar\n");
			scanf("%d", &alterar);
			
			switch(alterar){
				
				case 1:
					printf("\n Servico Cancelado com Sucesso \n");
					scanf("%d", &alterar);
					system("pause");
					
				case 2:
					printf("\n ...\n");
					scanf("%d", &alterar);
					system("pause");
					break;
				
				default:
					printf("\nselecione uma opcao valida\n");
					system("@cls||clear");
					count = true;
					
					
			}
		
		} while (count != 0);
}

void adicionar()
{
    printf("Qual servico deseja adicionar?\n");
    printf( "1 - Cabelo\n");
    printf( "2 - Barba\n");
    printf( "3 - Combo\n");
    printf( "4 - Sair\n");

}


int main()
{
    int continuar=1;

    do
    {
       printf("\n\t\t\t\t\t\t     Jojo's barbery\t\t\n");
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t\tEscolha a opcao desejada:\t\t\t#\n");
			printf("\t\t\t#########################################################################\n");
        printf("1. Finalizar Pedido\n");
        printf("2. Cancelar Servico\n");
        printf("3. Denifir ou alterar Preco\n");
        printf("4. Adicionar Servico\n");

        scanf("%d", &continuar);
        system("@cls||clear");
        

        switch(continuar)
        {
            case 1:
                finalizar();
                scanf("%d", &continuar);
                system("PAUSE");
               

            case 2:
                cancelar();
                scanf("%d", &continuar);
                system("PAUSE");
                

            case 3:
                alterar();
                scanf("%d", &continuar);
                system("PAUSE");
                

            case 4:
                adicionar();
                scanf("%d", &continuar);
                system("PAUSE");
            

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
}
