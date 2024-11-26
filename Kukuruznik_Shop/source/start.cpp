#include "../include/start.h"

#include <iostream>
#include <string>

#include "../include/login.h"
#include "../include/reg.h"

void Start() {
	while (true) {
		std::string choice;

		std::cout << "1 - Войти в аккаун\n";
		std::cout << "2 - Регистрация\n";
		std::cout << "0 - Выйти\n";

		std::cout << "Ввод: ";
		std::getline(std::cin, choice, '\n');

		if (choice == "1") {

		}
		else if (choice == "2") {
			Register();
		}
		else if (choice == "0") {
			break;
		}
		else {
			system("cls");
			std::cout << "Ошибка ввода\n";
		}
	}
}