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
    //������ �� ������
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

    return 0;
}
