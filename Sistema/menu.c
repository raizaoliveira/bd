#include "menu.h"


void menu_op(MYSQL *con)
{
	int op, opt;
	do{
		printf("Digite a opcao desejada:\n");
		printf("1 - Cadastros\n");
		printf("2 - Lancamentos\n");
		printf("3 - Relatorios\n");
		scanf( "%d",&op);

	}while((op < 1) || (op > 3));

	switch(op)
	{
		case 1:
				printf("1- Cadastrar cliente\n2- Cadastrar conta\n");
				scanf(" %d", &opt);
				switch(opt)
				{
					case 1 :
							cadastrar_cliente(con);
							break;
					case 2:
							cadastrar_conta(con);
							break;
				}
				break;
		case 2:
				printf("1- Saque\n2- Deposito\n3 -Transferencia\n");
				scanf(" %d", &opt);
				switch(opt)
				{
					case 1 :
							saque(con);
							break;
					case 2:
							deposito(con);
							break;
					case 3:
							transferencia(con);
							break;
				}
				break;
		case 3:
				relatorio(con);
				break;
	}
	printf("\33[H\33[2J");

}



void remover(MYSQL *con)
{
	char opc;
	printf (" 1 - Remover Conta  \n");
	printf (" 2 - Remover Cliente \n");
	printf ("-> ");
	scanf (" %c",&opc);
	switch (opc)
	{
		case '1':
			del_conta(con);
			break;
		case '2':
			del_cliente(con);
			break;
	}
}

void Menu(MYSQL *con)
{
	char opc;
	do {
		printf ("\n - - - - - M E N U - - - - -\n");
		printf (" 1 - Cadastrar/Relatorio    |\n");
		printf (" 2 - Remover                |\n");
		printf (" 3 - Sair                   |\n");
		printf (" - - - - - - - - - - - - - -\n");
		printf ("-> ");
		scanf (" %c",&opc);
		switch (opc)
		{
			case '1':
					menu_op(con);
					break;
			case '2':
					remover(con);
					break;
			case '3':
					exit(0);
					break;
		}
	} while (opc < 1 || opc > 3);
}

