#include "lanc.h"

void cadastrar_cliente(MYSQL *con)
{
		char stat[512], nome[100], cidade[100];
		int cpf;

		printf ("Cadastro de clientes\n");

		printf ("CPf \n-> ");
		scanf (" %d", &cpf);

		printf ("Nome \n-> ");
		scanf (" %[A-Z a-z]", nome);

		printf ("Cidade \n-> ");
		scanf (" %[A-Z a-z]", cidade);

		snprintf(stat, 512, "INSERT INTO cliente VALUES ( %d,'%s','%s')", cpf, nome, cidade);
		if (mysql_query (con, stat)) 
		{
			finish_with_error(con);
		}

}

void cadastrar_conta(MYSQL *con)
{
		char stat[512];
		int num, cod;

		printf ("Cadastro de contas\n");

		printf ("numero da conta \n-> ");
		scanf (" %d", &num);

		printf ("CPF cliente\n-> ");
		scanf (" %d", &cod);

		snprintf(stat, 512, "INSERT INTO conta VALUES ( %d, %f, %d)", num, 0.0, cod);
		if (mysql_query (con, stat)) 
		{
			finish_with_error(con);
		}

}

void saque(MYSQL *con)
{
	char stat[512];
	int num_cont;
	float valor, saldo;
	MYSQL_ROW row;

	printf("Informe o numero da conta que se deseja realizar o saque: \n");
	scanf("%d", &num_cont);
 
	snprintf(stat, 512, "SELECT saldo FROM conta WHERE id = %d", num_cont);

	if (mysql_query(con, stat)) 
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);
  
	if (result == NULL) 
	{
		finish_with_error(con);
	}

	row = mysql_fetch_row(result);
	saldo = atof(row[0]);

	printf("Seu Saldo é de: %.2f\nInforme o valor a ser sacado: \n", saldo);
	scanf("%f", &valor);

	while (valor < 0)
	{
		printf ("Valor invalido, informe um valor valido: \n");
		scanf("%f", &valor);
	}
	
	if (saldo >= valor)
	{
		saldo = saldo - valor;
		snprintf(stat, 512, "UPDATE conta SET saldo = %f WHERE id = %d", saldo, num_cont);
		mysql_query(con, stat);
	}
	else
	{
		printf ("Saldo Insuficiente\a \n");
	}	
	mysql_free_result(result);

}

void deposito(MYSQL *con)
{
	char stat[512];
	int num_cont;
	float valor, saldo;
	MYSQL_ROW row;

	printf("Informe o numero da conta que se deseja realizar o deposito: \n");
	scanf(" %d", &num_cont);
 
	snprintf(stat, 512, "SELECT saldo FROM conta WHERE id = %d", num_cont);

	if (mysql_query(con, stat)) 
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);
  
	if (result == NULL) 
	{
		finish_with_error(con);
	}

	row = mysql_fetch_row(result);
	saldo = atof(row[0]);

	printf("Seu Saldo é de: %.2f\nInforme o valor a ser depositado: \n", saldo);
	scanf("%f", &valor);
	
	while (valor < 0)
	{
		printf ("Valor invalido, informe um valor valido: \n");
		scanf("%f", &valor);
	}

	saldo = saldo + valor;
	snprintf(stat, 512, "UPDATE conta SET saldo = %f WHERE id = %d", saldo, num_cont);
	mysql_query(con, stat);
	
	mysql_free_result(result);

}

void transferencia(MYSQL *con)
{
	int conta1, conta2;
	char stat[512];
	float saldo1, saldo2, valor;
	MYSQL_ROW row;


	/* Vericacao Conta 1 */

	printf("Informe o numero da conta que se deseja realizar a transferencia: \n");
	scanf("%d", &conta1);
 
	printf("Informe o numero da conta que ira receber a transferencia: \n");
	scanf("%d", &conta2);


	snprintf(stat, 512, "SELECT saldo FROM conta WHERE id = %d", conta1);

	if (mysql_query(con, stat)) 
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);
  
	if (result == NULL) 
	{
		finish_with_error(con);
	}

	row = mysql_fetch_row(result);
	saldo1 = atof(row[0]);

	printf("Seu Saldo é de: %.2f\nInforme o valor a ser depositado: \n", saldo1);
	scanf(" %f", &valor);
	while (valor < 0.0)
	{
		printf ("Valor invalido, informe um valor valido: \n");
		scanf(" %f", &valor);
	}


	/* Vericacao Conta 2 */
	snprintf(stat, 512, "SELECT saldo FROM conta WHERE id = %d", conta2);

	if (mysql_query(con, stat)) 
	{
		finish_with_error(con);
	}

	result = mysql_store_result(con);
  
	if (result == NULL) 
	{
		finish_with_error(con);
	}

	row = mysql_fetch_row(result);
	saldo2 = atof(row[0]);

	/* Realiza a transacao */
	if (saldo1 >= valor)
	{
		saldo1 = saldo1 - valor;
		snprintf(stat, 512, "UPDATE conta SET saldo = %f WHERE id = %d", saldo1, conta1);
		mysql_query(con, stat);
	}
	
	saldo2 = saldo2 + valor;
	snprintf(stat, 512, "UPDATE conta SET saldo = %f WHERE id = %d", saldo2, conta2);
	mysql_query(con, stat);

	mysql_free_result(result);
}


void del_conta(MYSQL *con)
{
	char stat[512];
	int num_cont;
	float saldo;
	MYSQL_ROW row;

	printf("Informe o numero da conta que se deseja deletar: \n");
	scanf("%d", &num_cont);
 
	snprintf(stat, 512, "SELECT saldo FROM conta WHERE id = %d", num_cont);

	if (mysql_query(con, stat)) 
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);
  
	if (result == NULL) 
	{
		finish_with_error(con);
	}

	row = mysql_fetch_row(result);
	saldo = atof(row[0]);
	
	if (saldo > 0)
	{
		printf ("Conta possui saldo.Por favor realize um saque.");
	}

	else 
	{
		snprintf(stat, 512, "DELETE FROM conta WHERE id = %d", num_cont);
		mysql_query(con, stat);
	}
	
	mysql_free_result(result);
}

void del_cliente(MYSQL *con)
{
	char stat[512];
	int num;

	printf("Informe o numero do cfp do cliente que se deseja deletar: \n");
	scanf("%d", &num);

	snprintf(stat, 512, "DELETE FROM cliente WHERE cpf = %d", num);
	mysql_query(con, stat);
}


