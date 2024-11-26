#include "../include/reg.h"

#include <iostream>
#include <string>
#include <cctype>

#include "../include/database.h"

void Register() {
	std::string login, password, password2;

	while (true) {
		while (true) {
			std::cout << "������� ����� (0 - ��� ������): ";
			std::getline(std::cin, login, '\n');

			if (login == "0") {
				break;
			}

			if (CheckForSimilarLogin(login) == true) {
				system("cls");
				std::cout << "������������ � ����� ������� ��� ����������\n";
			}
			else {
				break;
			}
		}

		if (login == "0") {
			break;
		}

		while (true) {
			std::cout << "������� ������ (0 - ��� ������): ";
			std::getline(std::cin, password, '\n');

			if (password == "0") {
				break;
			}
			else if (CheckPassword(password) == true) {
				while (true) {
					std::cout << "��������� ������ (0 - ��� ������): ";
					std::getline(std::cin, password2, '\n');

					if (password == password2) {
						system("cls");
						if (RegisterUser(login, password) == true) {
							std::cout << "������� ������� ������\n";
							std::cout << "������� � �������\n";
							break;
						}
						else {
							std::cout << "������\n";
							break;
						}
					}
					else if (password2 == "0") {
						break;
					}
					else {
						std::cout << "������ ������ ���������\n";
					}
				}
			}
			else {
				std::cout << "������ ������ ���� ������� 8�� ��������, ����� ��������� � ��������� ������� � �����\n";
			}
			break;
		}
		break;
	}
}


bool CheckPassword(const std::string& password) {
	int min_lenght = 8;

	bool has_upper = false;
	bool has_lower = false;
	bool has_digit = false;
	bool has_special = false;

	if (password.length() < min_lenght) {
		return false;
	}

	for (char c : password) {
		if (std::isupper(c)) {
			has_upper = true;
		}
		else if (std::islower(c)) {
			has_lower = true;
		}
		else if (std::isdigit(c)) {
			has_digit = true;
		}
		else if (std::ispunct(c)) {
			has_special = true;
		}
	}

	return has_upper && has_lower && has_digit && has_special;
}