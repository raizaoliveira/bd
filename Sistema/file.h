#ifndef _FILE_H_
#define _FILE_H_

#include "tool.h"

typedef struct dados{
	int conta;
	char nome[250], cidade[250];
	float saldo;
}dados;

void open_file(char nome[50], FILE *p, dados row);

void relatorio(MYSQL *con);

#endif


