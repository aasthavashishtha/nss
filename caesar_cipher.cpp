#include<iostream>
#include<string>
using namespace std;

string cipher(string s, int key ){
        string ans="";
    for(char c:s){
        if(isalpha(c)){
            char base = isupper(c) ? 'A' : 'a';
            ans+= (c-base + key)%26 + base;
        }
        else
            ans += c;
    }
    return ans;
}

string plain(string s, int key){
    string ans="";
    for(char c:s){
        if(isalpha(c)){
            char base = isupper(c) ? 'A' : 'a';
            ans+= (c-base - key+26)%26 + base;
        }
        else
            ans += c;
    }
    return ans;
}

int main(){
    string s;
    getline(cin , s);
    int key;
    cin >> key;
    string ct = cipher(s, key);
    cout << ct << endl;
    string pt = plain(ct, key);
    cout<< pt << endl;
    return 0;
}