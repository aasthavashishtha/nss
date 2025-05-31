#include<iostream>
#include<string>

using namespace std;

string generate_key(string str,string key){
    int n= str.length();
    int m = key.length();
    int j=0;
    string ans = "";
    for(int i=0 ; i<n ; i++){
        if(j == m)
            j=0;
        ans +=key[j++];
    }
    return ans;
}

string cipher(string str,string key){
    int n= str.length();
    string ans = "";
    for(int i=0 ; i<n ; i++){
        char x = (str[i] + key[i])%26;
        x += 'A';
        ans += x;
    }
    return ans;
}

string plain(string str,string key){
    int n= str.length();
    string ans = "";
    for(int i=0 ; i<n ; i++){
        char x = (str[i] - key[i] +26)%26;
        x += 'A';
        ans += x;
    }
    return ans;
}

string transform(string str){
    int n = str.size();
    for(int i=0 ; i<n ; i++){
        if( str[i] >= 'a' && str[i] <= 'z')
           str[i] = str[i]-'a' + 'A';
    }
    return str;
}

int main(){
    string key, str;
    cin >> str;
    cin >> key;

    str = transform(str);
    key = transform(key);

    key = generate_key(str, key);
    string ciphertext = cipher(str, key);
    cout << ciphertext << endl;
    string plaintext = plain(ciphertext, key);
    cout << plaintext << endl;
}