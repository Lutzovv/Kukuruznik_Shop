#pragma once
#include <string>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

std::string Hash(const std::string& str);