#include <iostream>

using namespace std;

struct Consoles {
    char Case;
    union {
        struct {
            char model;
            int price;
        } Playstation;
        struct {
            char model;
            int price;
        } Xbox;
    };
};

Consoles inputInfo(char value) {
    Consoles console{};
    console.Case = value;
    if (console.Case == 1) {
        cout << "Модель: ";
        cin >> console.Playstation.model;
        cout << "Цена: ";
        cin >> console.Playstation.price;
    }
    else {
        cout << "Модель: ";
        cin >> console.Xbox.model;
        cout << "Цена: ";
        cin >> console.Xbox.price;
    }
    return console;
}

void printInfo(Consoles console) {
    if (console.Case == 1) {
        cout << "Playstation" << endl;
        cout << "Модель: " << console.Playstation.model << endl;
        cout << "Цена: " << console.Playstation.price << endl;
    }
    else {
        cout << "Xbox" << endl;
        cout << "Модель: " << console.Xbox.model << endl;
        cout << "Цена: " << console.Xbox.price << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    Consoles data[10], console = { 0, {0, 0} };
    for (int i = 0; i < sizeof(data) / sizeof(Consoles); i++)
        data[i] = console;
    int j, k;
    while (true) {
        cout << "\t Выберите действие:" << endl
            << "1) Ввести информацию о консоли" << endl
            << "2) Вывести информацию о консоли" << endl
            << "3) Вывести всю информацию" << endl
            << "4) Удалить информацию о консоли" << endl
            << "5) Удалить всю информацию" << endl
            << "6) Выйти" << endl << endl;
        cin >> j;
        cout << endl;
        switch (j) {
        case 1:
            cout << "Введите индекс (0-9): ";
            cin >> j;
            cout << "Консоль (1 - Playstation, 2 - Xbox): ";
            cin >> k;
            data[j] = inputInfo(k);
            break;
        case 2:
            cout << "Введите индекс (0-9): ";
            cin >> j;
            printInfo(data[j]);
            break;

        case 3:
            for (int i = 0; i < sizeof(data) / sizeof(Consoles); i++) {
                if (data[i].Case != 0)
                {
                    cout << "Номер консоли " << i + 1 << ":" << endl;
                    printInfo(data[i]);
                    cout << endl;
                }
            }
            break;
        case 4:
            cout << "Введите индекс (0-9): ";
            cin >> j;
            data[j] = console;
            break;
        case 5:
            for (int i = 0; i < sizeof(data) / sizeof(Consoles); i++) {
                data[i] = console;
            }
            break;
        case 6:
            return 1;
        default:
            cout << "Попробуйте снова";
        }
        cout << endl;
    }
    return 0;
}