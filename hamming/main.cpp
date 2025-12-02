#include "hamming.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    vector<vector<int>> testMessages = {
        { 0, 1, 0, 0, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 1, 0, 1 },
        { 1, 1, 0, 1, 1, 0, 0 },
        { 1, 1, 0, 1, 1, 0, 0 },
        { 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1 }
    };

    for (size_t i = 0; i < testMessages.size(); i++) {
        cout << "Тест " << i + 1 << endl;
        printVector(testMessages[i], "Исходное сообщение");

        vector<int> hammingCode = generateHammingCode(testMessages[i]);
        printVector(hammingCode, "Закодированное сообщение для проверки ");

        vector<int> corruptedCode = hammingCode;
        if (hammingCode.size() > 2) {
            corruptedCode[4] ^= 1; // принудительная ошибка
            printVector(corruptedCode, "Принятый код  ");

            auto result = decodeHammingCode(corruptedCode);
            cout << "Ошибка в позиции: " << result.second << endl;
            printVector(result.first, "Исправленное сообщение");
        }
    }
}
