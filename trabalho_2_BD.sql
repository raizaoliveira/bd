CREATE DATABASE banco;

CREATE TABLE cliente
(
	cpf int not null,
	nome varchar (100) not null,
	cidade varchar (100) not null,
	primary key (cpf)
);

CREATE TABLE conta
(
	id int not null,
	saldo float not null,
	cod_cliente int not null,
	primary key (id),
	foreign key (cod_cliente) references cliente (cpf)
);

CREATE TABLE funcionario
(
	id int not null,
	nome varchar (100),
	usuario varchar (100),
	login varchar (100),
	primary key (id)
);
