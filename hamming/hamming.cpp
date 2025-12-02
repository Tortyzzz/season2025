// Реализация
#include "hamming.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int calculateRedundantBits(int m) {
    int r = 0;
    while (pow(2, r) < m + r + 1) {
        r++;
    }
    return r;
}

vector<int> generateHammingCode(const vector<int>& messageBits) {
    int m = messageBits.size(); // длина кодируемого слова
    int r = calculateRedundantBits(m); // количество проверочных битов
    int n = m + r; // итоговая длина кодируемого слова вместе с проверочными битами

    vector<int> hammingCode(n, 0);

    for (int i = 0; i < r; i++) { // цикл определения мест проверочных битов
        int pos = pow(2, i) - 1;
        if (pos < n) {
            hammingCode[pos] = -1; // для дальнейшего определения проверочных битов отделяем их.
        }
    }

    int messageIndex = 0;
    for (int i = 0; i < n; i++) { // определение информационных битов в закодированном слове
        if (hammingCode[i] != -1) {
            hammingCode[i] = messageBits[messageIndex++];
        }
    }

    for (int i = 0; i < r; i++) { // вычисление проверочных битов при помощи XOR
        int parityPos = pow(2, i) - 1;
        if (parityPos >= n) continue;

        int parity = 0;

        for (int j = parityPos; j < n; j++) {
            if ((((j + 1) >> i) & 1) && hammingCode[j] != -1) {
                parity ^= hammingCode[j];
            }
        }
        hammingCode[parityPos] = parity;
    }

    return hammingCode; // закодированные сообщение
}


pair<vector<int>, int> decodeHammingCode(const vector<int>& receivedCode) {
    int n = receivedCode.size();
    int r = 0;
    while (pow(2, r) < n + 1) { // проверка количества проверочных битов в переданом, закодированном слове
        r++;
    }

    int errorPos = 0;
    for (int i = 0; i < r; i++) { // определение синдрома
        int parityPos = pow(2, i) - 1;
        if (parityPos >= n) continue;

        int parity = 0;
        for (int j = parityPos; j < n; j++) {
            if ((((j + 1) >> i) & 1)) {     // если j-тый бит вляет на синдром то,
                parity ^= receivedCode[j];  // выполняем операцию XOR
            }
        }

        if (parity != 0) { // указание на место ошибки
            errorPos += parityPos + 1;
        }
    }

    // Создаем копию для исправления
    vector<int> correctedCode = receivedCode;

    if (errorPos > 0 && errorPos <= n) {    // исправление ошибки
        correctedCode[errorPos - 1] ^= 1;    // инвертация бита
    }

    vector<int> messageBits;
    for (int i = 0; i < n; i++) {
        if (!isPowerOfTwo(i + 1)) {     // извлечение информационных битов
            messageBits.push_back(correctedCode[i]); // добавление их в декодированное слово
        }
    }

    return make_pair(messageBits, errorPos); // исправленное сообщение и ошибка(если есть...)
}


void printVector(const vector<int>& vec, const string& name) {
    cout << name << ": ";
    for (int bit : vec) {
        cout << bit << " ";
    }
    cout << endl;
}
