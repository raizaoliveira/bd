exe:
	gcc -c file.c `mysql_config --cflags --libs` -Wall -Wextra
	gcc -c lanc.c `mysql_config --cflags --libs` -Wall -Wextra
	gcc -c menu.c `mysql_config --cflags --libs` -Wall -Wextra
	gcc -c init.c `mysql_config --cflags --libs` -Wall -Wextra
	gcc -c tool.c `mysql_config --cflags --libs` -Wall -Wextra
	ar rcs libmenu.a *.o
	gcc  system.c -o system  -L. `mysql_config --cflags --libs` -lmenu -std=c99 -Wall -Wextra -pedantic
