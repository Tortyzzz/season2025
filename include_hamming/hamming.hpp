// library

#ifndef HAMMING_HPP
#define HAMMING_HPP

#include <vector>
#include <string>
#include <utility>

using namespace std;

// Вспомогательные функции

inline bool isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0 && n != 0;
}

// Функция для вычисления количества проверочных битов
int calculateRedundantBits(int m);

// Функция кодирования Хэмминга
vector<int> generateHammingCode(const vector<int>& messageBits);

// Функция декодирования Хэмминга с исправлением ошибок
pair<vector<int>, int> decodeHammingCode(const vector<int>& receivedCode);

// Функция для вывода вектора
void printVector(const vector<int>& vec, const string& name);

#endif
