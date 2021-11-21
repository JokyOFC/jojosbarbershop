//#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

#include <conio.h/conio.h> //utilizada no getche()
#include <locale.h> //utilizada para setar o idioma das janelas e permitir o uso de ç e acentuação, além do sleep

#include <iostream>
#include <cstdio> //versão stdio para linux

#include <unistd.h>

#include <cstring>

using namespace std; //utilizada para o cout

/* Idéia para armazenar os dados escolhidos
* 1 - utilizar structs com o nome de clientes
* 2 - nos structs definir cada variáveis como uma linha nova no banco de dados
* 3 - informar cada campo do struct em suas opções para que logo após possa ser acessado pela ultima tela
* https://www.inf.pucrs.br/~pinho/LaproI/Structs/Structs.htm - link sobre structs e exemplo de structs em functions
*/

// Struct utilizado para criação dos pedidos dos funcionarios
struct ficha{
	int preco; // armazena o preço do pedido
	int preco2; // se tiver um segundo preço, ele irá somar essa variavel com o preço
	int senha;
	bool hasDouble; // varivavel para se caso tiver dois pedidos, ele será true
	char selecao; // primeiro pedido do cliente
	char selecao2[]; // segundo pedido do cliente
};

/*
    loop? condição até que apareça um serviço
    TRIGGER?
    INSERT *
    
    -----------------------------------------
    
    ? - Recursividade para ficar chamando a mesma função nela mesma

*/

int senha; // variável utilizada para sistema de senha

void tela_senha(){
	//ultima tela do sistema para voltar para o main
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
	sleep(4); //utilizado para esperar quatro segundos para ir pra próxima linha
    
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
}

void tela_espera(){
	//penultima tela onde carregará a ultima tela (tela_senha)

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

struct ficha pedido;

void menu_final(char ped[], char ped2[], int din) {
	// Ultima tela de seleção para o cliente

	system("@cls||clear");
	
	int count_final; // Variavel utilizada para o loop posterior
	do{
		// Loop utilizado para dar 9 espaçamentos e cemtralizar a tela
		for(int i; i<9; i++){ 
			printf("\n");
		}
        senha++; // Sistema da senha, onde irá ser adicionado +1 a cada pedido
		int opcao; // variavel para captar o input do cliente
		printf("\t\t\t\t\t\t    JoJo's barbershop\n");
		printf("\t\t\t\t\t########################################\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#               senha:%d              #\n", senha);

		// condição para se caso tiver dois serviço ele irá printar o primeiro printf

		if(pedido.hasDouble = true){
			printf("\t\t\t\t\t#        Serviços: %s + %s       #\n", ped, ped2);
		} else {
			printf("\t\t\t\t\t#        Serviços: %s       #\n", ped);
		}

		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#               R$ %d,00               #\n", din);
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#      Deseja confirmar o pedido?      #\n");
		printf("\t\t\t\t\t#       [1 - Sim]      [2 - Não]       #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t########################################\n");
		scanf("%d", &opcao); // input do cliente
		
		switch(opcao){
			case 1:
				system("@cls||clear");
                tela_espera(); // encaminhamento para a proxima etapa
				count_final = 0; // no final da etapa ele irá finalizar o loop para sair do procedimento
			break;
			
			case 2:
			    // caso não confirme o pedido, a senha diminuirá...
                // senha avançado seria se utilizasse a integração com o mysql (pegaria a ultima id utilizada para ver qual seria a senha atual/próxima senha)
                // no sistema avançado a senha seria o id anterior + 1
                // muito bem provavel seria considerado um inteiro de valores altos
				senha-=1;
                system("@cls||clear");
                count_final = 0;
			break;
			
			default:
                // fazer um sistema que fique esperando na tela até 15 segundos para retornar ao menu inicial
				// seria um loop que iria adicionando +1 até que atinja o limite
                system("@cls||clear");
				count_final = 0;
		}
	} while (count_final != 0);
	
}

void menu_escolha(char ped[], char ped2[], int din) {
	system("@cls||clear");
	
	int count_escolha;
	do{

		// Espaçamento utilizado para centralizar o menu
		for(int i; i<9; i++){
			printf("\n"); 
		}
		

		int opcao; // variavel para captar o input do cliente
		printf("\t\t\t\t\t\t    JoJo's barbershop\n");
		printf("\t\t\t\t\t########################################\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#                                      #\n");

		// condição para se caso tiver dois serviço ele irá printar o primeiro printf

		if(pedido.hasDouble = true){
			printf("\t\t\t\t\t#        Serviços: %s + %s       #\n", ped, ped2);
			din = pedido.preco + pedido.preco2;
		} else {
			printf("\t\t\t\t\t#        Serviços: %s       #\n", ped);
		}
		
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#               R$ %d,00               #\n", din);
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t#      Deseja fazer outro pedido?      #\n");
		printf("\t\t\t\t\t#       [1 - Sim]      [2 - Não]       #\n");
		printf("\t\t\t\t\t#                                      #\n");
		printf("\t\t\t\t\t########################################\n");
		scanf("%d", &opcao); // Input do cliente
		
		switch(opcao){
			case 1:
				system("@cls||clear");
				pedido.hasDouble = true; // Se o cliente quiser fazer mais um outro pedido, ele terá dois pedidos
				count_escolha = 0; // no final da etapa ele irá finalizar o loop para sair do procedimento
			break;
			
			case 2:
				system("@cls||clear");
                menu_final(ped, ped2, din); // encaminhar para o menu para confirmar o seu pedido
                // ele automaticamente irá definir como primeiro pedido pois essa tela só encaminhará para a
                // tela do cliente apenas para o primeiro pedido, o segundo pedido irá encaminhar para a tela final
                pedido.hasDouble = false; 
				//senha-1;
				count_escolha = 0;
			break;
			
			default:
				system("@cls||clear");	
				count_escolha = 0;
		}
	} while (count_escolha != 0);
	
}

struct ficha pedidos_menu;

void menu_cabelo() {
	//printf("\nentrou menu cabelo\n");

		//char dis;	
		
		system("@cls||clear");
		
		int count_cabelo;
		do{
			
			printf("\n\t\t\t\t\t\t     JoJo's barbershop\t\t\n");
			int opcao_cab;
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t    Escolha a opção de cabelo desejada:    \t\t#\n");
			printf("\t\t\t#########################################################################\n");
			//printf("\nEscolha a opção de cabelo desejada: \n");
			printf("1 - Degradê R$10,00 \n2 - Simples R$10,00 \n3 - Navalhado R$10,00 \n4 - Pé de cabelo R$10,00 \n5 - A tratar com o barbeiro \n0 - Cancelar pedido\n");
			scanf("%d", &opcao_cab);
			
			//char *corte[25];
			
			switch(opcao_cab){
				
				case 0:
					system("@cls||clear");
					
					//exit(EXIT_FAILURE);
					count_cabelo = 0;
				break;
			
				case 1:
					printf("\n corte Degradê selecionado!  \n");
					sleep(3);
					
					// verificação para setiver dois pedidos
					if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Corte_degradê"; //problema
						pedidos_menu.preco = 10;
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 10);
						//add 

					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Corte_degradê"; //problema
						//Ultimo menu
						pedidos_menu.preco2 = 10;
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2[1], 0);
					}
					//menu_final('teste', 23, 001);
					//menu_final("Corte_casual", 25, 001);
					//system("pause");
					count_cabelo = 0;
				break;
					
				case 2:
					printf("\n corte Simples selecionado!  \n");
                    sleep(3);

                    // verificação para setiver dois pedidos
                    if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Corte_simples"; //problema
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 10);
						pedidos_menu.preco = 10;
					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Corte_simples"; //problema
						//Ultimo menu
						pedidos_menu.preco2 = 10;
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2, 0);
					}

					count_cabelo = 0;
				break;
				
				case 3:
					printf("\n corte Navalhado selecionado!  \n");
                    sleep(3);
                    
                    // verificação para setiver dois pedidos
                    if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Corte_navalhado"; //problema
						pedidos_menu.preco = 10;
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 10);

					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Corte_navalhado"; //problema
						pedidos_menu.preco2 = 10;
						//Ultimo menu
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2, 0);
					}
					
					count_cabelo = 0;
				break;
				
				case 4:
					printf("\n Pé de cabelo selecionado!  \n");
                    sleep(3);
                    
                    if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Pé_cabelo"; //problema
						pedidos_menu.preco = 10;
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 10);

					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Pé_cabelo"; //problema
						//Ultimo menu
						pedidos_menu.preco2 = 10;
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2, 0);
					}
					
					count_cabelo = 0;
				break;
				
				case 5:
					printf("\n A tratar com o barbeiro selecionado!\n");
                    sleep(3);
                    
                    // verificação para setiver dois pedidos
                    if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Barbeiro"; //problema
						pedidos_menu.preco = 0;
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 0);

					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Barbeiro"; //problema
						//Ultimo menu
						pedidos_menu.preco2 = 0;
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2, 0);
					}
					
					count_cabelo = 0;
				break;
				
				default:
                    system("@cls||clear");
					printf("\nSELECIONE UMA OPÇÃO VALIDA!\n");
                    sleep(3);
                    system("@cls||clear");
					//exit(EXIT_FAILURE);
					//return count1 = 1;
					count_cabelo = 1;
			}
		
		} while (count_cabelo != 0);
}

void menu_barba() {

	
	
	system("@cls||clear");
	
	int count_barba;
		do{
			int opcao_barb;
			printf("\n\t\t\t\t\t\t     JoJo's barbershop\t\t\n");
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t     Escolha a opção de barba e bigode desejada:\t\t#\n");
			printf("\t\t\t#########################################################################\n");
			//printf("\nEscolha a opção de barba desejada: \n");
			printf("1 - Barba simples R$5,00 \n2 - Barba alinhada R$ 5,00 \n3 - Pigmentação R$ 5,00 \n4 - A tratar diretamente com o barbeiro \n0 - Cancelar pedido\n");
			scanf("%d", &opcao_barb);
			
			switch(opcao_barb){
				
				case 0:
					system("@cls||clear");
					//exit(EXIT_FAILURE);
					count_barba = 0;
				break;
			

				case 1:
					printf("\n Barba simples selecionado! \n");

					// verificação para setiver dois pedidos
                    if (pedido.hasDouble == false) {
						(char**)pedido.selecao == (char**)"Barba_simples";
						pedidos_menu.preco = 5; 
						menu_escolha((char*)pedido.selecao, (char*)"", 5);

					} else {

						(char**)pedido.selecao2 == (char**)"Barba_simples"; //problema
						pedidos_menu.preco2 = 5;
						//Ultimo menu
						menu_final((char*)pedido.selecao, (char*)pedido.selecao2, 0);
					}
					
					sleep(3);
					count_barba = 0;
				break;
					
				case 2:
					printf("\n Barba alinhada selecionado! \n");
					
					// verificação para setiver dois pedidos
                    if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Barba_alihada"; //problema
						pedidos_menu.preco = 5;
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 5);

					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Barba_alinhada"; //problema
						//Ultimo menu
						pedidos_menu.preco2 = 5;
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2, 0);
					}
					
					sleep(3);
					count_barba = 0;
				break;
				
				case 3:
					printf("\n Pigmentação selecionado! \n");
					
					// verificação para setiver dois pedidos
                    if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Pigmentacao"; //problema
						pedidos_menu.preco = 5;
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 5);

					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Pigmentacao"; //problema
						//Ultimo menu
						pedidos_menu.preco = 10;
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2, 5);
					}
					
					sleep(3);
					count_barba = 0;
				break;
				
				case 4:
					printf("\n A tratar diretamente com o barbeiro selecionado! \n");
					
					// verificação para setiver dois pedidos
                    if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Barbeiro"; //problema
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 20);

					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Barbeiro"; //problema
						//Ultimo menu
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2, 20);
					}
					
					sleep(3);
					count_barba = 0;
				break;

				default:
					printf("\nselecione uma opção valida\n");
					sleep(3);
					system("@cls||clear");
					count_barba = 1;
					//exit(EXIT_FAILURE);
					//return count1 = 1;
			}
		
		} while (count_barba != 0);
}

void menu_sombrancelha() {
	//printf("\nentrou menu combos\n");
	
	system("@cls||clear");
	
	int count_somb;
		do{
			int opcao_barb;
			printf("\n\t\t\t\t\t\t     JoJo's barbershop\t\t\n");
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t\tEscolha dentre as sombrancelhas:\t\t#\n");
			printf("\t\t\t#########################################################################\n");
			//printf("\nEscolha dentre os combos: \n");
			printf("1 - Limpeza e alinhamento R$ 5,00 \n2 - Design R$ 5,00 \n3 - Pigmentação R$ 5,00 \n0 - Cancelar pedido\n");
			scanf("%d", &opcao_barb);
			
			switch(opcao_barb){
			
				case 0:
					system("@cls||clear");
					//exit(EXIT_FAILURE);
					count_somb = 0;
				break;
				
				case 1:
					printf("\n Limpeza e alinhamento selecionado! \n");
					
					// verificação para setiver dois pedidos
                    if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Limp_alin"; //problema
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 5);

					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Limp_alin"; //problema
						//Ultimo menu
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2, 20);
					}
					
					sleep(3);
					count_somb = 0;
				break;
					
				case 2:
					printf("\n Design selecionado! \n");
					
					// verificação para setiver dois pedidos
                    if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Design"; //problema
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 20);

					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Design"; //problema
						//Ultimo menu
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2, 20);
					}
					
					sleep(3);
					count_somb = 0;
				break;
				
				case 3:
					printf("\n Pigmentação selecionado! \n");
					
					// verificação para setiver dois pedidos
                    if (pedidos_menu.hasDouble == false) {
						(char**)pedidos_menu.selecao == (char**)"Pigmentacao"; //problema
						menu_escolha((char*)pedidos_menu.selecao, (char*)"", 20);

					} else {

						(char**)pedidos_menu.selecao2 == (char**)"Pigmentacao"; //problema
						//Ultimo menu
						menu_final((char*)pedidos_menu.selecao, (char*)pedidos_menu.selecao2, 20);
					}
					
					sleep(3);
					count_somb = 0;
				break;
				
				default:
					printf("\nselecione uma opção valida\n");
					sleep(3);
					system("@cls||clear");
					//exit(EXIT_FAILURE);
					//return count1 = 1;
			}
		
		} while (count_somb != 0);

}

void logo(){
	//Procedimento para armazenar a logo do programa
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

	int count1;

    setlocale(LC_ALL, "Portuguese"); 

    bool count; //variavel utilizada para o segundo contador da primeira tela

	do{ // primeiro loop, loop da tela bem-vindo

		/*HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
		SetConsoleTextAttribute(hConsole, 0005);*/
		
		logo();
		
		char dis;
		printf("\n\t\t\t#########################################################################\n");
		printf("\t\t\t#\t\t\tSeja bem vindo a JoJo's barbershop!\t\t#\n");
		printf("\t\t\t#########################################################################\n");
		cout << "\t\t\t\t\tPressione qualquer tecla para continuar...\t\t" << endl;
		
		/*if(!dis){
			dis = " ";
			dis = (const char*)getche();
		} else {
			dis = (const char*)getche();
		}*/

		dis = getche();

        //count = false;

		system("@cls||clear");
		
		//SetConsoleTextAttribute(hConsole, 0007);
		
		do{ // segundo loop, loop de escolha do seriço
			int opcao;
			printf("\n\t\t\t\t\t\t     JoJo's barbershop\t\t\n");
			printf("\n\t\t\t#########################################################################\n");
			printf("\t\t\t#\t\t\tEscolha a opção desejada:\t\t\t#\n");
			printf("\t\t\t#########################################################################\n");
			//printf("\nEscolha a opção desejada: \n");
			printf("1 - Cabelo \n2 - Barba e bigode \n3 - Sombrancelha \n4 - Cancelar\n");
			scanf("%d", &opcao);
			
			switch(opcao){
			
				case 1:
					menu_cabelo();
					count1 = 0;
					count = false; // variavel utilizado para sair do segundo contador e ir para o primeiro menu
					//system("pause");
					//memset(&dis, 0, sizeof(dis));
				break;
				
				case 2:
					menu_barba();
					count1 = 1;
					count = false; // variavel utilizado para sair do segundo contador e ir para o primeiro menu
					//system("pause");
					//memset(&dis, 0, sizeof(dis));
				break;
				
				case 3:
					menu_sombrancelha();
					count1 = 1;
					count = false; // variavel utilizado para sair do segundo contador e ir para o primeiro menu
					//system("pause");
					//memset(&dis, 0, sizeof(dis));
				break;

				case 4:
                    system("@cls||clear");
                    count = false; // variavel utilizado para sair do segundo contador e ir para o primeiro menu
				    count1 = 0;
				    
				    /*if(count == false){
				    	printf("false");
				    } else {
				    	printf("true");
				    }
				    sleep(3);*/

				    //opcao = EOF;
				    //dis != EOF;
                    //fseek(fptr, 0, SEEK_SET);
                    //memset(&dis, 0, sizeof(dis));
				break;
                
				default:
					system("@cls||clear");
                    printf("\n\t\t\t\t\t\t     JoJo's barbershop\t\t\n");
                    printf("\n\t\t\t#########################################################################\n");
			        printf("\t\t\t#\t\t\tSELECIONE UMA OPÇÃO VALIDA!\t\t\t#\n");
			        printf("\t\t\t#########################################################################\n");
                    sleep(3);
                    system("@cls||clear");
					count = true; // Variável para continuar no segundo loop
					count1 = 0;
			}
		
		} while (count != false);

		//count1 = 1;
		
	} while (true);

    	
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
* - Se faz necessário utilização de vetores e/ou matrizes na implementação; V
* 
* - Conter pelo menos 01 tipo abstrato de dados na implementação (struct). V 
*/