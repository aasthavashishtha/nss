#include<iostream>
#include<string>

using namespace std;

string generate_key(string s,string key){
    int n = s.size();
    string newkey = "";
    int j =0 ;
    for( int i=0 ; i<n ; i++){
        if(j==key.size())
            j=0;
        newkey += key[j++];
    }
    return newkey;
}

string ciphertext(string s, string k){
    string result = "";
    int n= s.size();
    int idx = 0;
    for(char c : s){
        if(isalpha(c)){
            char base  = isupper(c) ? 'A':'a';
            char key = isupper(k[idx]) ? k[idx]-'A' : k[idx]-'a';
            result += (c-base+key)%26 + base;
        }
        else
            result+= c;
        idx++;
    }
    return result;
}

string plaintext(string s, string k){
    string result = "";
    int n= s.size();
    int idx = 0;
    for(char c : s){
        if(isalpha(c)){
            char base  = isupper(c) ? 'A':'a';
            char key = isupper(k[idx]) ? k[idx]-'A' : k[idx]-'a';
            result += (c-base-key+26)%26 + base;
            
        }
        else
            result+= c;
        idx++;
    }
    return result;
}

int main(){
    string s;
    getline(cin, s);
    string key ;
    cin >> key;
    key = generate_key(s, key);
    string ct = ciphertext(s, key);
    cout << ct << endl;
    cout << plaintext(ct , key) << endl;
    return 0;
}