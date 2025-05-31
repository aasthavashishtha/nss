#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Key Scheduling Algorithm (KSA)
void KSA(const string &key, vector<int> &S) {
    int j = 0;
    int keyLen = key.length();
    for (int i = 0; i < 256; i++)
        S[i] = i;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % keyLen]) % 256;
        swap(S[i], S[j]);
    }
}

// Pseudo-Random Generation Algorithm (PRGA)
string RC4(const string &key, const string &input) {
    vector<int> S(256);
    KSA(key, S);
    
    int i = 0, j = 0;
    string output;
    
    for (char c : input) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        int k = S[(S[i] + S[j]) % 256];
        output += c ^ k; // XOR with keystream byte
    }
    
    return output;
}

int main() {
    string key, plaintext;
    cout << "Enter key: ";
    getline(cin, key);
    
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    string encrypted = RC4(key, plaintext);
    cout << "\nEncrypted (hex): ";
    for (unsigned char c : encrypted)
        printf("%02X ", c);

    string decrypted = RC4(key, encrypted); // Re-apply RC4 with same key to decrypt
    cout << "\nDecrypted text: " << decrypted << endl;

    return 0;
}
