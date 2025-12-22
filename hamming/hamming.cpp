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
    int m = messageBits.size(); 
    int r = calculateRedundantBits(m);
    int n = m + r; 

    vector<int> hammingCode(n, 0);

    for (int i = 0; i < r; i++) {
        int pos = pow(2, i) - 1;
        if (pos < n) {
            hammingCode[pos] = -1;
        }
    }

    int messageIndex = 0;
    for (int i = 0; i < n; i++) {
        if (hammingCode[i] != -1) {
            hammingCode[i] = messageBits[messageIndex++];
        }
    }

    for (int i = 0; i < r; i++) { 
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

    return hammingCode; 
}

pair<vector<int>, int> decodeHammingCode(const vector<int>& receivedCode) {
    int n = receivedCode.size();
    int r = 0;
    while (pow(2, r) < n + 1) { 
        r++;
    }

    int errorPos = 0;
    for (int i = 0; i < r; i++) {
        int parityPos = pow(2, i) - 1;
        if (parityPos >= n) continue;

        int parity = 0;
        for (int j = parityPos; j < n; j++) {
            if ((((j + 1) >> i) & 1)) {    
                parity ^= receivedCode[j]; 
            }
        }

        if (parity != 0) { 
            errorPos += parityPos + 1;
        }
    }

    vector<int> correctedCode = receivedCode;

    if (errorPos > 0 && errorPos <= n) {  
        correctedCode[errorPos - 1] ^= 1; 
    }

    vector<int> messageBits;
    for (int i = 0; i < n; i++) {
        if (!isPowerOfTwo(i + 1)) {   
            messageBits.push_back(correctedCode[i]);
        }
    }

    return make_pair(messageBits, errorPos);
    
}

void printVector(const vector<int>& vec, const string& name) {
    cout << name << ": ";
    for (int bit : vec) {
        cout << bit << " ";
    }
    cout << endl;
}
