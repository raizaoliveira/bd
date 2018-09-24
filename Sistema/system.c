#include "init.h"
#include "menu.h"
#include "tool.h"

int main()
{
	char root_pswd[250];
	MYSQL *con = mysql_init(NULL);
	if (con == NULL) 
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}

	printf ("Informe a senha do root no mysql: \n");
	scanf (" %s", root_pswd);

	if (mysql_real_connect(con, "localhost", "root", root_pswd, "banco", 0, NULL, 0) == NULL)  
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	printf("\33[H\33[2J");
	/*snprintf(stat, 255, "INSERT INTO funcionario VALUES (%d, '%s', '%s', '%s')", 1, "Alonso", "administrador", "al@comp");
	if (mysql_query (con, stat)) 
	{
		finish_with_error(con);
	}	*/
	login(con);
	
		
	return 0;
}
