#include <iostream>
#include <map>
using namespace std;

//������ �� �������� �����
class Shop {
private:
    map<int, string> products;

public:
    void viewProduct(int number) {
        if (products.count(number) == 0) {
            cout << "����� � ������� " << number << " �� ����������." << endl;
        } else {
            string name = products[number];
            cout << "�����: " << number << ", ��������: " << name << endl;
        }
    }

    void changeProductNumber(int oldNumber, int newNumber) {
        if (products.count(oldNumber) == 0) {
            cout << "����� � ������� " << oldNumber << " �� ����������." << endl;
        } else if (products.count(newNumber) != 0) {
            cout << "����� � ������� " << newNumber << " ��� ����������." << endl;
        } else {
            string name = products[oldNumber];
            products.erase(oldNumber);
            products[newNumber] = name;
            cout << "����� ������ ������� �������." << endl;
        }
    }
    void addProduct(string name, int number) {
        if (products.count(number) != 0) {
            cout << "����� � ������� " << number << " ��� ����������." << endl;
        } else {
            products[number] = name;
            cout << "����� ����� ������� ��������." << endl;
        }
    }
};


int main() {
    setlocale(LC_ALL,"rus");

    //������ �� �������� ������
    string login, password;
    cout << "�����: ";
    cin >> login;
    cout << "������: ";
    cin >> password;
    if ((login == "admin" && password == "password") || (login == "worker1" && password == "password1")){
        Shop shop;
        shop.addProduct("�����", 1);
        shop.addProduct("�������", 2);

        int choice;
        do {
            cout << endl;
            cout << "����:" << endl;
            cout << "1. �������� ������" << endl;
            cout << "2. ��������� ������ ������" << endl;
            cout << "3. ���������� ������ ������" << endl;
            cout << "0. �����" << endl;
            cout << "�������� ��������: ";
            cin >> choice;
            cout << endl;
            if (choice == 1) {
                int number;
                cout << "������� ����� ������ ��� ���������: ";
                cin >> number;
                shop.viewProduct(number);
            } else if (choice == 2) {
                int oldNumber, newNumber;
                cout << "������� ������ ����� ������: ";
                cin >> oldNumber;
                cout << "������� ����� ����� ������: ";
                cin >> newNumber;
                shop.changeProductNumber(oldNumber, newNumber);
            } else if (choice == 3) {
                string name;
                int number;
                cout << "������� �������� ������: ";
                cin >> name;
                cout << "������� ����� ������: ";
                cin >> number;
                shop.addProduct(name, number);
            }

        } while (choice != 0);

    } else {
        cout << "�������� ����� ��� ������." << endl;
    }


    return 0;
}
