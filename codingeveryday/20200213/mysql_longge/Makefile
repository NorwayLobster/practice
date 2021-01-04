con_mysql:query.c delete.c insert.c update.c create_table_user_info_virtual_filesystem.cc
	gcc query.c -o query_mysql -I /usr/include/mysql/ -lmysqlclient
	gcc delete.c -o delete_mysql -I /usr/include/mysql/ -lmysqlclient
	gcc insert.c -o insert_mysql -I /usr/include/mysql/ -lmysqlclient
	gcc update.c -o update_mysql -I /usr/include/mysql/ -lmysqlclient
	g++ create_table_user_info_virtual_filesystem.cc -o create_mysql -I /usr/include/mysql/ -lmysqlclient
clean:
	rm query_mysql delete_mysql insert_mysql update_mysql
