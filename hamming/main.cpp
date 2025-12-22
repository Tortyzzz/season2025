#include "hamming.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    vector<vector<int>> testMessages0 = {
        { 0, 1, 0, 0, 1, 0, 0 }
    };
    vector<vector<int>> testMessages4 = {
        { 1, 1, 0, 0, 1, 0, 1 }
    };
    vector<vector<int>> testMessages2 = {
        { 1, 1, 0, 1, 1, 0, 0 }
    };
    vector<vector<int>> testMessages3 = {
        { 1, 1, 0, 1, 1, 0, 0 }
    };

    // Тест 1: Одна ошибка
    for (size_t i = 0; i < testMessages0.size(); i++) {
        cout << "Тест 1" << endl;
        printVector(testMessages0[i], "Исходное сообщение");

        vector<int> hammingCode0 = generateHammingCode(testMessages0[i]);
        printVector(hammingCode0, "Закодированное сообщение для проверки ");

        vector<int> corruptedCode0 = hammingCode0;
        if (hammingCode0.size() > 2) {
            corruptedCode0[1] ^= 1; // принудительная ошибка
            printVector(corruptedCode0, "Принятый код  ");

            auto result = decodeHammingCode(corruptedCode0);
            cout << "Ошибка в позиции: " << result.second << endl;
            printVector(result.first, "Исправленное сообщение");
        }
        cout << endl;
    }
    for (size_t i = 0; i < testMessages4.size(); i++) {
        cout << "Тест 2 " << endl;
        printVector(testMessages4[i], "Исходное сообщение");

        vector<int> hammingCode4 = generateHammingCode(testMessages4[i]);
        printVector(hammingCode4, "Закодированное сообщение для проверки ");

        vector<int> corruptedCode4 = hammingCode4;
        if (hammingCode4.size() > 2) {
            corruptedCode4[4] ^= 1; // принудительная ошибка
            printVector(corruptedCode4, "Принятый код  ");

            auto result = decodeHammingCode(corruptedCode4);
            cout << "Ошибка в позиции: " << result.second << endl;
            printVector(result.first, "Исправленное сообщение");
        }
        cout << endl;
    }
    for (size_t i = 0; i < testMessages3.size(); i++) {
        cout << "Тест 3" << endl;
        printVector(testMessages3[i], "Исходное сообщение");

        vector<int> hammingCode3 = generateHammingCode(testMessages3[i]);
        printVector(hammingCode3, "Закодированное сообщение для проверки ");

        vector<int> corruptedCode3 = hammingCode3;
        if (hammingCode3.size() > 2) {
            corruptedCode3[2] ^= 1; // принудительная ошибка
            printVector(corruptedCode3, "Принятый код  ");

            auto result = decodeHammingCode(corruptedCode3);
            cout << "Ошибка в позиции: " << result.second << endl;
            printVector(result.first, "Исправленное сообщение");
        }
        cout << endl;
    }

    for (size_t i = 0; i < testMessages2.size(); i++) {
        cout << "Тест 4 "<< endl;
        printVector(testMessages2[i], "Исходное сообщение");

        vector<int> hammingCode2 = generateHammingCode(testMessages2[i]);
        printVector(hammingCode2, "Закодированное сообщение для проверки ");

        vector<int> corruptedCode2 = hammingCode2;
        if (hammingCode2.size() > 2) {
            corruptedCode2[5] ^= 1; // принудительная ошибка
            printVector(corruptedCode2, "Принятый код  ");

            auto result = decodeHammingCode(corruptedCode2);
            cout << "Ошибка в позиции: " << result.second << endl;
            printVector(result.first, "Исправленное сообщение");
        }
        cout << endl;
    }

    vector<int> testMessages1 = { 0, 1, 0, 0, 1, 0, 0 };
    cout << "Тест с 2-мя ошибками" << endl;
    printVector(testMessages1, "Исходное сообщение");

    vector<int> hammingCode = generateHammingCode(testMessages1);
    printVector(hammingCode, "Закодированное сообщение для проверки ");

    vector<int> corruptedCode1 = hammingCode;
    if (hammingCode.size() > 2) {
        corruptedCode1[3] ^= 1;
        corruptedCode1[4] ^= 1; // принудительная ошибка
        printVector(corruptedCode1, "Принятый код  ");

        auto result = decodeHammingCode(corruptedCode1);
        cout << "Ошибка в позиции: " << result.second << endl;
        printVector(result.first, "Исправленное сообщение");
    }

    return 0;
}
