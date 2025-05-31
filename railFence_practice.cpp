#include<iostream>
#include<string>
#include<vector>
using namespace std;

string encrypt(string s, int key){
    vector<string> v(key);
    int n = s.size();
    int row = 0;
    bool down = true;
    for(int i=0 ; i< n ; i++){
        v[row] +=s[i];
        if(row==0)
            down = true;
        if(row == key-1)
            down = false;
        row += down ? 1 : -1;
    }
    string ans = "";
    for(string str : v){
        ans += str;
    }
    return ans;
}

string decrypt(string s, int key){
    int n= s.size();
    vector<vector<char>> v(key, vector<char>(n,' '));
    int row = 0;
    bool down = true;
    for(int i=0 ; i<n ; i++){
        v[row][i] = '*';
        if(row == 0)
            down = true;
        if(row == key-1)
            down = false;
        row += down ? 1 : -1;
    }
    int k=0;
    for(int i=0 ; i<key ; i++){
        for(int j=0 ; j<n ; j++){
            if(v[i][j] == '*')
                v[i][j] = s[k++];
        }
    }
    string ans = "";
    row =0;
    down = true;
    for(int i=0 ; i<n ; i++){
        ans += v[row][i];
        if(row == 0)
            down = true;
        if(row == key-1)
            down = false;
        row += down ? 1 : -1;
    }
    return ans;
}

int main(){
    string  str;
    int key;
    // cin >> str;
    getline(cin, str);
    cin >> key;
    string ciphertext = encrypt(str, key);
    cout << ciphertext << endl;
    string plaintext = decrypt(ciphertext, key);
    cout << plaintext << endl;
}