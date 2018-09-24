#include "init.h"

void login(MYSQL *con)
{

	char name[100], login[100], stat[512];
	MYSQL_ROW row;

	printf("Nome de usuario:  ");
	scanf(" %s", name);
	printf("login:  ");
	scanf(" %s", login);
 
	snprintf(stat, 512, "SELECT login FROM funcionario WHERE usuario = '%s'", name);

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

	if (strcmp(row[0],login) == 0) 
	{	
		printf("\33[H\33[2J");
		Menu(con);
	}
	else printf ("\aAcesso nao autorizado");
	
	mysql_free_result(result);
}


