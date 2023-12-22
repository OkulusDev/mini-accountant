#include <iostream>

class Account {
public:
    std::string holder_name;
    unsigned cash = 0;
    char currency{'R'}; // R - рубли, D - доллары
    unsigned income = 0;
    unsigned expenses = 0;

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

    user->holder_name = login();

    return 0;
}

