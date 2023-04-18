#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;
    cout << endl;

    int** input = new int* [rows];  // создание двумерного динамического массива
    for (int i = 0; i < rows; i++) {
        input[i] = new int[cols];
    }

    // заполнение исходного массива
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            input[i][j] = rand() % 20 + 1;
        }
    }

    // вывод исходной матрицы
    cout << "Исходная матрица" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int n = cols / 2;
    int** output = new int* [rows];  // создание двумерного динамического массива
    for (int i = 0; i < rows; i++) {
        output[i] = new int[n];
    }


    // заполнение выходного массива
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((j + 1) % 2 == 0) {
                output[i][j/2] = input[i][j];
            }
        }
    }

    // вывод выходной матрицы
    cout << "Выходная матрица" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // освобождение памяти, занятой для двумерного динамического массива
    for (int i = 0; i < rows; i++) {
        delete[] input[i];
        delete[] output[i];
    }
    delete[] input;
    delete[] output;

    return 0;
}