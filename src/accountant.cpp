#include <iostream>

class Account {
public:
    std::string holder_name;
    double cash = 0.0;
    char currency{'R'}; // R - рубли, D - доллары
    double income = 0.0;
    double expenses = 0.0;

    void add_income(int money_income) {
        income += money_income;
        cash += money_income;
    }

    void add_expenses(int money_expenses) {
        expenses += money_expenses;
        cash -= money_expenses;
    }
};

std::string login() {
    std::string username;

    std::cout << "Введите ваше имя: ";
    std::cin >> username;

    std::cout << "Вход в аккаунт успешно выполнен" << std::endl;
    
    return username;
}

int main() {
    Account account;
    Account *user = &account;
    char command;

    user->holder_name = login();

	std::cout << "1 - add cash to account; 2 - get cash from account" 
            << std::endl;

    while (true) {
        std::cout << "ATM@" << user->holder_name << "$ ";
        std::cin >> command;

        if (command == '1') {
            double cash_added;
            std::cout << "Added cash to " << user->holder_name << " wallet" 
                        << std::endl;
            std::cout << "Enter count: ";
            std::cin >> cash_added;

            if (cash_added > 0.0) {
                user->add_income(cash_added);
            }

            std::cout << "Cash is added. " << user->holder_name << "balance: " 
                        << user->cash 
                        << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}

