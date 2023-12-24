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
    //коммит от сережи
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

    return 0;
}
