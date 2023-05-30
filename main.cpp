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

struct List {
private:
    struct Node {
        Consoles data{};
        Node* next;
        Node(Consoles data) {
            this->data = data;
            this->next = nullptr;
        }
    };
    int size;
    Node* head;
public:
    List() {
        head = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    Consoles get(int index) {
        Node* current = this->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void push_back(int index, Consoles data) {
        if (index >= 0 || index < this->size) {
            if (index == 0) {
                Node* newNode = new Node(data);
                newNode->next = head->next;
                head = newNode;
            }
            else {
                Node* prev = this->head;
                for (int i = 0; i < index - 1; i++) {
                    prev = prev->next;
                }
                Node* newNode = new Node(data);
                newNode->next = prev->next->next;
                prev->next = newNode;
            }
        }
    }

    void push_back(Consoles data) {
        if (head == nullptr) {
            head = new Node(data);
        }
        else {
            Node* current = this->head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(data);
        }
        size++;
    }
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
    List data;
    Consoles console = { 0, {0, 0} };
    for (int i = 0; i < 10; i++)
        data.push_back(console);
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
                data.push_back(j, inputInfo(k));
                break;
            case 2:
                cout << "Введите индекс (0-9): ";
                cin >> j;
                printInfo(data.get(j));
                break;

            case 3:
                for (int i = 0; i < 10; i++) {
                    if (data.get(i).Case != 0)
                    {
                        cout << "Номер консоли " << i + 1 << ":" << endl;
                        printInfo(data.get(i));
                        cout << endl;
                    }
                }
                break;
            case 4:
                cout << "Введите индекс (0-9): ";
                cin >> j;
                data.push_back(j, console);
                break;
            case 5:
                for (int i = 0; i < 10; i++) {
                    data.push_back(i, console);
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
