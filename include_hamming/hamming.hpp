#ifndef HAMMING_HPP
#define HAMMING_HPP

#include <vector>
#include <string>
#include <utility>

// Вспомогательные функции

inline bool isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0 && n != 0;
}

// Функция для вычисления количества проверочных битов
int calculateRedundantBits(int m);

// Функция кодирования Хэмминга
std::vector<int> generateHammingCode(const std::vector<int>& messageBits);

// Функция декодирования Хэмминга с исправлением ошибок
std::pair<std::vector<int>, int> decodeHammingCode(const std::vector<int>& receivedCode);

// Функция для вывода вектора
void printVector(const std::vector<int>& vec, const std::string& name);

#endif
