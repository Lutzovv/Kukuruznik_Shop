#include "../include/database.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>

#include "../include/hash.h"


PGconn* Connect() {
	const char* connect = "dbname=kukuruznik_shop user=postgres password=postgres host=localhost port=5432";
	PGconn* conn = PQconnectdb(connect);

	if (PQstatus(conn) != CONNECTION_OK) {
		FinishWithError(conn);
		}

	return conn;
}


void FinishWithError(PGconn* conn) {
	fprintf(stderr, "Ошибка: %s", PQerrorMessage(conn));
	PQfinish(conn);
	exit(1);
}


bool CheckForSimilarLogin(const std::string& login) {
	PGconn* conn = Connect();

	std::string select = "SELECT login FROM users WHERE login = '" + Hash(login) + "';";

	PGresult* result = PQexec(conn, select.c_str());
	if (PQresultStatus(result) != PGRES_TUPLES_OK) {
		FinishWithError(conn);
	}

	int rows = PQntuples(result);

	if (rows != 0) {
		PQfinish(conn);
		return true;
	}
	else {
		PQfinish(conn);
		return false;
	}
}


bool RegisterUser(const std::string& login, const std::string& password) {
	PGconn* conn = Connect();

	std::string insert = "INSERT INTO users (login, password) VALUES ('" + Hash(login) + "', '" + Hash(password) + "');";

	PGresult* result = PQexec(conn, insert.c_str());
	if (PQresultStatus(result) != PGRES_COMMAND_OK) {
		std::cerr << "Ошибка выполнения запроса: " << PQerrorMessage(conn) << "\n";
		PQfinish(conn);
		return false;
	}
	else {
		PQfinish(conn);
		return true;
	}
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <libpq-fe.h>
//
//void finish_with_error(PGconn* conn) {
//    fprintf(stderr, "Ошибка: %s", PQerrorMessage(conn));
//    PQfinish(conn);
//    exit(1);
//}
//
//int main() {
//    const char* conninfo = "dbname=kukuruznik_shop user=postgres password=postgres host=localhost port=5432";
//    PGconn* conn = PQconnectdb(conninfo);
//
//    if (PQstatus(conn) != CONNECTION_OK) {
//        finish_with_error(conn);
//    }
//
//    PGresult* res = PQexec(conn, "SELECT * FROM users");
//    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
//        finish_with_error(conn);
//    }
//
//    int rows = PQntuples(res);
//    int cols = PQnfields(res);
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            printf("%s\t", PQgetvalue(res, i, j));
//        }
//        printf("\n");
//    }
//
//    PQclear(res);
//    PQfinish(conn);
//    return 0;
//}