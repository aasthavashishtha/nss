#include<iostream>
#include<string>
#include<vector>
using namespace std;

void KSA(string &key, vector<int> &s){
    int keylen = key.size();
    for(int i=0 ; i<256 ; i++){
        s[i] = i;
    }
    int j=0;
    for(int i=0 ; i<256 ; i++){
        j = (j+s[i]+key[i%keylen])%256;
        swap(s[i],s[j]);
    }
}

string PRGA(string &key, string &input){
    int n = key.size();
    vector<int> s(256);
    KSA(key,s);
    int i=0,j=0;
    string output = "";
    for(char c : input){
        i = (i+1)%256;
        j = (j+s[i]) %256;
        swap(s[i],s[j]);
        int k = s[(s[i]+s[j])%256];
        output += c^k;
    }
    return output;
}


int main() {
    string key, plaintext;
    cout << "Enter key: ";
    getline(cin, key);
    
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    string encrypted = PRGA(key, plaintext);
    cout << "\nEncrypted (hex): ";
    for (unsigned char c : encrypted)
        printf("%02X ", c);

    string decrypted = PRGA(key, encrypted); // Re-apply RC4 with same key to decrypt
    cout << "\nDecrypted text: " << decrypted << endl;

    return 0;
}
