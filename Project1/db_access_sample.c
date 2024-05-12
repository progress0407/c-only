#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
// #include <mysql/mysql.h>  // ������ ��� ���� ��ġ

struct DBConnection {
	const char* url;
	const char* db;
	const char* user;
	const char* password;
};

int main() {	

	struct DBConnection DBConn = {
		"localhost",
		"test-db",
		"root",
		"1234"
	};

	MYSQL mysql;

	mysql_init(&mysql);

	if (mysql_real_connect(&mysql, DBConn.url, DBConn.user, DBConn.password, DBConn.db, 3306, NULL, 0)) {
		printf("MYSQL ����: %s \n", mysql_get_client_info());
	}
	else {
		printf("���� \n");
	}

	mysql_close(&mysql);

	return 0;
}
