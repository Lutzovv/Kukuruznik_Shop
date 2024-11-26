#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>

PGconn* Connect();
void FinishWithError (PGconn* conn);
bool CheckForSimilarLogin (const std::string& login);
bool RegisterUser(const std::string& login, const std::string& password);