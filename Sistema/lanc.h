#ifndef _LANC_H_
#define _LANC_H_

#include "tool.h"

void cadastrar_cliente(MYSQL *con);

void cadastrar_conta(MYSQL *con);

void saque(MYSQL *con);

void deposito(MYSQL *con);

void transferencia(MYSQL *con);


void del_conta(MYSQL *con);

void del_cliente(MYSQL *con);

#endif

