#include<iostream>
#include<string>

using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int t= b;
        b =a%b;
        a=t;
    }
    return a;
}

string ciphertext(string s, int a, int b){
    string result;
    for(char c:s){
        if(isalpha(c)){
            char base = isupper(c) ? 'A':'a';
            result += (a*(c-base)+b)%26 +base;
        }
        else
            result += c;
    }
    return result;
}

int a_inverse(int a, int m){
    for(int x=1; x<m ; x++){
        if(a*x%m ==1)
            return x;
    }
    return -1;
}
string plaintext(string s, int a, int b){
    int a_inv = a_inverse(a, 26);
    if(a_inv == -1)
        cout << "no";

    string result;
    for(char c:s){
        if(isalpha(c)){
            char base = isupper(c) ? 'A':'a';
            result += (a_inv*(c-base-b+26))%26 +base;
        }
        else
            result += c;
    }
    return result;

}

int main(){

    int a ,b;
    cin >> a >> b;
    if(gcd(a, 26)!= 1){
        cout << "a should be coprime " << endl;
        return 0;
    }
    cin.ignore();
    string s;
    getline(cin, s);
    
    string ct = ciphertext(s, a,b);
    cout << ct << endl;
    cout << plaintext(ct , a, b) << endl;
    return 0;
}