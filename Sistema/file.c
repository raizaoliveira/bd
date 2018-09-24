#include "file.h"


void open_file(char nome[50], FILE *p, dados row)
{
	//abre o arquivo onde salvara o aconteceu
	if ((p=fopen(nome,"a+")) == NULL)
	{
		printf ("nao foi possivel abrir o arquivo");
		exit(1);
	}

	else
	{
		fprintf( p,"\n");
		fprintf( p,"%s;		%s;			%d;			%f", row.nome, row.cidade, row.conta, row.saldo);
	}
	fclose(p);
}

void relatorio(MYSQL *con)
{
	dados cliente;
	char stat[512];
	int cpf;
	MYSQL_ROW row, aux;
	MYSQL_RES *result, *clin;
	FILE *pt;

	if (mysql_query(con, "SELECT * FROM conta")) 
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1); 
	}

	result = mysql_store_result(con);
  
	if (result == NULL) 
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1); 
	}

	if ((pt = fopen("Cliente.txt","w")) != NULL)
	{
		fprintf( pt,"Clientes\n");
		fprintf( pt,"Nome;		Cidade;			N° Conta;			Saldo");
		fclose(pt);
	}
	else printf("\nErro ao abrir arquivo");

	while ((row = mysql_fetch_row(result))) 
	{
		cliente.conta = atof(row[0]);
		cliente.saldo = atof(row[1]);
		cpf = atof(row[2]);

		snprintf(stat, 512,"SELECT nome, cidade FROM cliente WHERE cpf = %d", cpf);
		mysql_query(con, stat);
		clin = mysql_store_result(con);
		aux = mysql_fetch_row(clin);

		strcpy(cliente.nome, aux[0]);
		strcpy(cliente.cidade, aux[1]);
		
		open_file("Cliente.txt", pt, cliente);

	}

	mysql_free_result(result);
}
