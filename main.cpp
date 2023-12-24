#include <iostream>
#include <map>
using namespace std;

//коммит от Ивановой Дарьи
class Shop {
private:
    map<int, string> products;

public:
    void viewProduct(int number) {
        if (products.count(number) == 0) {
            cout << "Товар с номером " << number << " не существует." << endl;
        } else {
            string name = products[number];
            cout << "Номер: " << number << ", Название: " << name << endl;
        }
    }

    void changeProductNumber(int oldNumber, int newNumber) {
        if (products.count(oldNumber) == 0) {
            cout << "Товар с номером " << oldNumber << " не существует." << endl;
        } else if (products.count(newNumber) != 0) {
            cout << "Товар с номером " << newNumber << " уже существует." << endl;
        } else {
            string name = products[oldNumber];
            products.erase(oldNumber);
            products[newNumber] = name;
            cout << "Номер товара успешно изменен." << endl;
        }
    }
    void addProduct(string name, int number) {
        if (products.count(number) != 0) {
            cout << "Товар с номером " << number << " уже существует." << endl;
        } else {
            products[number] = name;
            cout << "Новый товар успешно добавлен." << endl;
        }
    }
};


int main() {
    setlocale(LC_ALL,"rus");

    //коммит от Новикова Сергея
    string login, password;
    cout << "Логин: ";
    cin >> login;
    cout << "Пароль: ";
    cin >> password;
    if ((login == "admin" && password == "password") || (login == "worker1" && password == "password1")){
        Shop shop;
        shop.addProduct("диван", 1);
        shop.addProduct("кровать", 2);

        int choice;
        do {
            cout << endl;
            cout << "Меню:" << endl;
            cout << "1. Просмотр товара" << endl;
            cout << "2. Изменение номера товара" << endl;
            cout << "3. Добавление нового товара" << endl;
            cout << "0. Выход" << endl;
            cout << "Выберите действие: ";
            cin >> choice;
            cout << endl;
            if (choice == 1) {
                int number;
                cout << "Введите номер товара для просмотра: ";
                cin >> number;
                shop.viewProduct(number);
            } else if (choice == 2) {
                int oldNumber, newNumber;
                cout << "Введите старый номер товара: ";
                cin >> oldNumber;
                cout << "Введите новый номер товара: ";
                cin >> newNumber;
                shop.changeProductNumber(oldNumber, newNumber);
            } else if (choice == 3) {
                string name;
                int number;
                cout << "Введите название товара: ";
                cin >> name;
                cout << "Введите номер товара: ";
                cin >> number;
                shop.addProduct(name, number);
            }

        } while (choice != 0);

    } else {
        cout << "Неверный логин или пароль." << endl;
    }


    return 0;
}
