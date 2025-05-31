#include<iostream>
#include<string>

using namespace std;

string generatekey(string key , string s){
    int n = s.length();
    string ans = "";
    int j=0;
    for(int i=0 ; i<n ;i++){
        if(j==key.length())
            j=0;
            ans += key[j++];
    }
    return ans;
}

string cipher(string key, string s){
    int n = s.length();
    string output = "";
    int i = 0;
    for(char c:s){
        if(isalpha(c)){
            char base = isupper(c) ? 'A':'a';
            char keys = isupper(key[i]) ? key[i]-'A' : key[i]-'a';
            output += (c-base+keys)%26 +base;
        }
        else
            output+= c;
        i++;

    }
    return output;
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
    key = generatekey(key, s);
    string ct = cipher(key, s);
    cout << ct << endl;
    cout << plaintext(ct,key) << endl;
    return 0;
}