#include "hamming.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    vector<vector<int>> testMessages = {
        { 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 0, 0, 1, 0, 1 },
        { 1, 1, 0, 1, 1, 0, 0 },
        { 1, 1, 0, 1, 1, 0, 0 },
        { 1, 1, 0, 1, 1, 1, 1 }
    };

    for (size_t i = 0; i < testMessages.size(); i++) {
        cout << "Тест " << i + 1 << endl;
        printVector(testMessages[i], "Исходное сообщение");

        vector<int> hammingCode = generateHammingCode(testMessages[i]);
        printVector(hammingCode, "Закодированное сообщение для проверки ");

        vector<int> corruptedCode = hammingCode;
        if (hammingCode.size() > 2) {
            corruptedCode[5] ^= 1; // принудительная ошибка
            printVector(corruptedCode, "Принятый код  ");

            auto result = decodeHammingCode(corruptedCode);
            cout << "Ошибка в позиции: " << result.second << endl;
            printVector(result.first, "Исправленное сообщение");
        }
    }

    vector<int> testMessages1 = { 0, 1, 0, 0, 1, 0, 0 };
    cout << "Тест с 2-мя ошибками" << endl;
    printVector(testMessages1, "Исходное сообщение");

    vector<int> hammingCode = generateHammingCode(testMessages1);
    printVector(hammingCode, "Закодированное сообщение для проверки ");

    vector<int> corruptedCode1 = hammingCode;
    if (hammingCode.size() > 2) {
        corruptedCode1[3] ^= 1;
        corruptedCode1[4] ^= 1;// принудительная ошибка
        printVector(corruptedCode1, "Принятый код  ");

        auto result = decodeHammingCode(corruptedCode1);
        cout << "Ошибка в позиции: " << result.second << endl;
        printVector(result.first, "Исправленное сообщение");
    }
}
