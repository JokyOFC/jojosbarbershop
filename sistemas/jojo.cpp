#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h/conio.h>
#include <locale.h>

//#include <curses.h>

#include <iostream>
#include <cstdio>

#include <GL/glut.h>
#include <sys/wait.h>
#include <time.h>

//include\mysq\mysql.h
#include <mysql/mysql.h>

#include <unistd.h>

using namespace std;

//talvez o retorno seja utilizado pelo banco de dados
	
void teste(){
	printf("estou no teste");
}

/*
int menu(){
	int opcao;
	printf("\nEscolha a opção desejada: \n");
	cout << "1 - Cabelo \n2 - Barba \n3 - Combos" << endl;
	opcao = getche();
	return opcao;
}
*/



int count1;

/* Idéia para armazenar os dados escolhidos
* 1 - utilizar structs com o nome de clientes
* 2 - nos structs definir cada variáveis como uma linha nova no banco de dados
* 3 - informar cada campo do struct em suas opções para que logo após possa ser acessado pela ultima tela
* https://www.inf.pucrs.br/~pinho/LaproI/Structs/Structs.htm - link sobre structs e exemplo de structs em functions
*/


MYSQL *con = mysql_init(NULL);

int connect(){

    /* Ideia para tabela unica do banco de dados
     *
     * Muito bem provavel vamos precisar de uma tabela de clientes com
     * dados escolhidos pelo cliente como senha, pedido e preço.
     *
     *  | .._id | senha | pedido | preço |
     *
     * As variaveis terão respectivamentes com os seguintes parametros:
     * (int, auto_incrementable, primary_key); (int, not_null); (char); (float);
     *
     * A tabela se chamará: "pedidos"
     */

    mysql_init(con);
		if( mysql_real_connect(con, "data-lojanutri-proj-do-user-10192926-0.b.db.ondigitalocean.com", "admin", "30CR4z1ponogIUSC", "jojos", 25060, NULL, 0) )
			{
				printf("conectado com sucesso!\n");
				mysql_close(con);
			}
		else
			{
				printf("Falha de conexao\n");
				printf("Erro %d : %s\n", mysql_errno(con), mysql_error(con));
			}

            return 0;

}

//int connect();

struct ficha{
	char selecao;
	int preco;
	int senha;

};

/*
    loop? condição até que apareça um serviço
    TRIGGER?
    INSERT *
    
    -----------------------------------------
    
    ? - Recursividade para ficar chamando a mesma função nela mesma

*/

int senha;

int tela_senha(){
	system("@cls||clear");
	printf("\t\t\t\t\t\t    JoJo's barbershop\n");
	printf("\t\t\t\t\t########################################\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#        Imprimindo sua senha...       #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t########################################\n");
	sleep(4);
    //Criar um file
    //aqui será criado um file com as informações, como um "comprovante" para retirar no totem e prosseguir com atendimento com o barbeiro
    system("@cls||clear");
    printf("\t\t\t\t\t\t    JoJo's barbershop\n");
	printf("\t\t\t\t\t########################################\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#      Senha impressa com sucesso!     #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#           Retire sua senha           #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t#                                      #\n");
	printf("\t\t\t\t\t########################################\n");
    sleep(3);
    return count1 = 1;
}

void tela_espera(char pedi[], int dinh, int passw){

	//vem um if com algum comando sql, muito bem provavel terá uma variável que retornará um select e verificará se uma linha foi adicionada.. ou talvez um log
    //aqui que será totalmente concretizado o pedido no banco de dados, a partir de um insert dos valores pegos da ultima tela para assim prosseguir para proxima tela
		printf("\t\t\t\t\t\t    JoJo's barbershop\n");
		printf("\t\t\t\t\t########################################\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#               Aguarde...             #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t########################################\n");
		sleep(3);
        tela_senha();
}

void menu_final(char ped[], int din) {

    //sistema de senha basico

	system("@cls||clear");
	
	int count;
	do{
		for(int i; i<9; i++){
			printf("\n");
		}
        senha++;
		int opcao;
		printf("\t\t\t\t\t\t    JoJo's barbershop\n");
		printf("\t\t\t\t\t########################################\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#               senha:%d              #\n", senha);
		printf("\t\t\t\t\t#        Serviços: %s       #\n", ped);
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#               R$ %d,00               #\n", din);
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#      Deseja confirmar o pedido?      #\n");
		printf("\t\t\t\t\t#       [1 - Sim]      [2 - Não]       #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t########################################\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				system("@cls||clear");
                //caso não confirme o pedido, a senha diminuirá...
                //senha avançado seria se utilizasse a integração com o mysql (pegaria a ultima id utilizada para ver qual seria a senha atual/próxima senha)
                tela_espera(ped, din, senha);
				count = 0;
			break;
			
			case 2:
                //no sistema avançado a senha seria o id anterior + 1
                //muito bem provavel seria considerado um inteiro de valores altos
				senha-=1;
                system("@cls||clear");
			break;
			
			default:
                //fazer um sistema que fique esperando na tela até 15 segundos para retornar ao menu inicial
				//seria um loop que iria adicionando +1 até que atinja o limite
                system("@cls||clear");
				count = 0;
		}
	} while (count != 0);
	
}

void menu_escolha(char ped[], int din) {
	system("@cls||clear");
	
	int count;
	do{
		for(int i; i<9; i++){
			printf("\n");
		}
		//senha++;
		int opcao;
		printf("\t\t\t\t\t\t    JoJo's barbershop\n");
		printf("\t\t\t\t\t########################################\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#        Serviços: %s       #\n", ped);
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#               R$ %d,00               #\n", din);
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#      Deseja fazer outro pedido?      #\n");
		printf("\t\t\t\t\t#       [1 - Sim]      [2 - Não]       #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t########################################\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				system("@cls||clear");
				count = 0;
			break;
			
			case 2:
				system("@cls||clear");
                menu_final(ped, din);
				//senha-1;
				count = 0;
			break;
			
			default:
				system("@cls||clear");
				count = 0;
		}
	} while (count != 0);
	
}

void menu_cabelo() {
	//printf("\nentrou menu cabelo\n");
	
		char dis;	
		
		system("@cls||clear");
		
		int count;
		do{
			
			printf("\n\t\t\t\t\t\t     JoJo's barbershop\t\t\n");
			int opcao_cab;
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t    Escolha a opção de cabelo desejada:    \t\t#\n");
			printf("\t\t\t#########################################################################\n");
			//printf("\nEscolha a opção de cabelo desejada: \n");
			printf("1 - Casual \n2 - Repicado \n3 - Cabelo 3 \n4 - Cabelo 4 \n5 - A confirmar com o barbeiro \n0 - Cancelar pedido\n");
			scanf("%d", &opcao_cab);
			
			switch(opcao_cab){
				
				case 0:
					system("@cls||clear");
					
					//exit(EXIT_FAILURE);
					count = 0;
				break;
			
				case 1:
					printf("\n corte casual selecionado! Encaminhando para a proxima tela... \n");
					sleep(3);
					//system("@cls||clear");
					menu_escolha((char*)"Corte casual", 20);
					//menu_final('teste', 23, 001);
					//menu_final("Corte_casual", 25, 001);
					//system("pause");
					count = 0;
				break;
					
				case 2:
					printf("\n corte repicado selecionado! Encaminhando para a proxima tela... \n");
                    sleep(3);
                    menu_escolha((char*)"Corte Repicado", 20);
					system("pause");
				break;
				
				case 3:
					printf("\n corte 3 selecionado! Encaminhando para a proxima tela... \n");
                    sleep(3);
                    menu_escolha((char*)"Corte 3", 20);
					system("pause");
				break;
				
				case 4:
					printf("\n corte 4 selecionado! Encaminhando para a proxima tela... \n");
                    sleep(3);
                    menu_escolha((char*)"Corte 4", 20);
					system("pause");
				break;
				
				case 5:
					printf("\n corte 5 selecionado! Encaminhando para a proxima tela... \n");
                    sleep(3);
                    menu_escolha((char*)"Corte 5", 20);
					system("pause");
				break;
				
				default:
                    system("@cls||clear");
					printf("\nSELECIONE UMA OPÇÃO VALIDA!\n");
                    sleep(3);
                    system("@cls||clear");
					//exit(EXIT_FAILURE);
					//return count1 = 1;
					count = 1;
			}
		
		} while (count != 0);
}

void menu_barba() {

	
	
	system("@cls||clear");
	
	int count;
		do{
			int opcao_barb;
			printf("\n\t\t\t\t\t\t     JoJo's barbershop\t\t\n");
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t     Escolha a opção de barba desejada:\t\t\t#\n");
			printf("\t\t\t#########################################################################\n");
			//printf("\nEscolha a opção de barba desejada: \n");
			printf("1 - Barba lenhador \n2 - Barba proporcional \n3 - Barba 3 \n4 - Barba 4 \n5 - A confirmar com o barbeiro \n0 - Cancelar pedido\n");
			scanf("%d", &opcao_barb);
			
			switch(opcao_barb){
				
				case 0:
					system("@cls||clear");
					//exit(EXIT_FAILURE);
					count = 0;
				break;
			
				case 1:
					printf("\n Barba lenhador selecionado! \n");
					system("pause");
				break;
					
				case 2:
					printf("\n Barba proporcional selecionado! \n");
					system("pause");
				break;
				
				case 3:
					printf("\n Barba 3 selecionado! \n");
					system("pause");
				break;
				
				case 4:
					printf("\n Barba 4 selecionado! \n");
					system("pause");
				break;
				
				case 5:
					printf("\n Barba 5 selecionado! \n");
					system("pause");
				break;
				
				default:
					printf("\nselecione uma opção valida\n");
					//exit(EXIT_FAILURE);
					//return count1 = 1;
			}
		
		} while (count != 0);
}

void menu_combos() {
	//printf("\nentrou menu combos\n");
	
	system("@cls||clear");
	
	int count;
		do{
			int opcao_barb;
			printf("\n\t\t\t\t\t\t     JoJo's barbershop\t\t\n");
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t\tEscolha dentre os combos:\t\t\t#\n");
			printf("\t\t\t#########################################################################\n");
			//printf("\nEscolha dentre os combos: \n");
			printf("1 - Barba lenhador \n2 - Barba proporcional \n3 - Barba 3 \n0 - Cancelar pedido\n");
			scanf("%d", &opcao_barb);
			
			switch(opcao_barb){
			
				case 0:
					system("@cls||clear");
					//exit(EXIT_FAILURE);
					count = 0;
				break;
				
				case 1:
					printf("\n Barba lenhador selecionado! \n");
					system("pause");
				break;
					
				case 2:
					printf("\n Barba proporcional selecionado! \n");
					system("pause");
				break;
				
				case 3:
					printf("\n Barba 3 selecionado! \n");
					system("pause");
				break;
				
				default:
					printf("\nselecione uma opção valida\n");
					
					//system("@cls||clear");
					//exit(EXIT_FAILURE);
					//return count1 = 1;
			}
		
		} while (count != 0);

}

void logo(){
		printf("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddhyyhhyyhddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddddddddhhyyyyhhhdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddddhyyssssssssssyyhddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddddddddddhssssssssssssssssyyddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddddddddddyssssssssssssssssssydddddddddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddysssssssssssssssssssssssyyhhddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddyssssssssssssssssssssssssssyyyddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddddddhyyssssssssssssssssssssssssssssssydddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddddyysssssssssssyyyhhhhhdhhhyysssssssssyddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddhyssssssssyyyhhdddddddhhhhdddhysssssssshdddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddysssssssyhhddddddddhyyyhhhhdddyssyyyssshdddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddyssssssyhdhhhhdddddhhdddddddddhsyhddysshdddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddyssssssyhyhddhddddddddhdhddddddyhdddhsyddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddysssssyhhddddddddddddddddddddddddddhydddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddddhysssyhddhhddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddddddhyysyddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddhyddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddhhhhyyddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddddddddddyhyyhhhhhddddddddddhddddddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddddddddddhhddddddddddddddddyyhyhdddddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddhysyhyysssyyddddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddhyyyyhhysssssssyhddddddddddddddddddddddddddddddddddddddd\n");
		printf("dddddddddddddddddddddddddddddddddddddddddddddddddddddhddddddhyyyyyhdyyssssssssyhddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddddddddddyyyhddhyyyyhddhyssssssssssydddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddddddddhyssssyyssyhdddhyssssssssssyddddddddddddddddddddddddddddddddddddddddd\n");
		printf("ddddddddddddddddddddddddddddddddddddddddddddddddddhyyssssssssyhddyyssssssssssyddddddddddddddddddddddddddddddddddddddddd\n");
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    //connect();

	//printf("%s \n", mysql_get_client_info());
	
	//system("119, 31");

    //system("color 0A");
	
    bool count;

	do{

        count = true;
		
		/*HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
		SetConsoleTextAttribute(hConsole, 0005);*/
		
		logo();
		
		char dis;
		printf("\n\t\t\t#########################################################################\n");
		printf("\t\t\t#\t\t\tSeja bem vindo a JoJo's barbershop!\t\t#\n");
		printf("\t\t\t#########################################################################\n");
		cout << "\t\t\t\t\tPressione qualquer tecla para continuar...\t\t" << endl;
		dis = getche();

        //count = false;

		system("@cls||clear");
		
		//SetConsoleTextAttribute(hConsole, 0007);
		
		do{
			
			printf("\n\t\t\t\t\t\t     JoJo's barbershop\t\t\n");
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t\tEscolha a opção desejada:\t\t\t#\n");
			printf("\t\t\t#########################################################################\n");
			
			int opcao;
			//printf("\nEscolha a opção desejada: \n");
			printf("1 - Cabelo \n2 - Barba \n3 - Combos \n4 - Cancelar\n");
			scanf("%d", &opcao);
			
			switch(opcao){
			
				case 1:
					menu_cabelo();
					count1 = 1;
					count = false;
					//system("pause");
				break;
				
				case 2:
					menu_barba();
					count1 = 1;
					count = false;
					//system("pause");
				break;
				
				case 3:
					menu_combos();
					count1 = 1;
					count = false;
					//system("pause");
				break;

				case 4:
                    system("@cls||clear");
                    count = false;
				    count1 = 0;
                    //fseek(fptr, 0, SEEK_SET);
				break;
                
				default:
					system("@cls||clear");
                    printf("\n\t\t\t\t\t\t     JoJo's barbershop\t\t\n");
                    printf("\n\t\t\t#########################################################################\n");
			        printf("\t\t\t#\t\t\tSELECIONE UMA OPÇÃO VALIDA!\t\t\t#\n");
			        printf("\t\t\t#########################################################################\n");
                    sleep(3);
                    system("@cls||clear");
					count = true;
					count1 = 0;
			}
		
		} while (count != false);
		
		//count1 = 1;
		
	} while (count1 != 1);

    	
	//return 1;
	//teste();
}

/*
*/

/*
* - Atender todos os requisitos funcionais mencionados pela equipe; V
* 
* - Conter em sua estrutura um menu para que o usuário tenha opções a serem 
*   escolhidas. Para isso, utilize uma estrutura do tipo switch..case. 
*   Este menu deve ser rotativo e para isto, deve-se utilizar a estrutura do..while
*   ou while em conjunto; V
* 
* - Conter estruturas condicionais (simples e/ou compostas); V
* 
* - Possuir estrutura(s) de repetição (não conta a utilizada no menu); V
* 
* - Se faz necessário o uso de procedimentos e/ou funções no código; V
* 
* - Se faz necessário utilização de vetores e/ou matrizes na implementação; --? -> ["joaquim", 18, "ciencias da computação"]
* 
* - Conter pelo menos 01 tipo abstrato de dados na implementação (struct). --? ~> 
*/