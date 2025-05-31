#include<iostream>
#include<string>
#include<vector>

using namespace std;

string cipher(string s, int key){
    int n= s.size();
    vector<string> rail(key);
    int row = 0;
    bool down = true;
    for(char c:s){
        rail[row]+=c;
        if(row == 0)
            down = true;
        if(row == key-1)
            down = false;
        row += down ? 1 : -1;
    }
    string ans = "";
    for(string str : rail){
        ans+=str;
    }
    return ans;
    // vector<vector<char>> v(key, vector<char>(n, '*'));
    // int i=0;
    // while(i<n){
    //     for(int j=0; j<key ; j++){
    //         if(i==n)
    //             break;
    //         v[i][j] = s[i++];
    //     }
    //     for(int j=key-1; j>=0 ; j--){
    //         if(i==n)
    //             break;
    //         v[i][j] = s[i++];
    //     }
    // }
    // string ans="";
    // for(i=0; i<key ; i++){
    //     for(int j=0; j<n ; j++){
    //         if(v[i][j] != '*')
    //             ans+=v[i][j];
    //     }
    // }
    // return ans;
}

string decrypt (string s, int key){
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
    string ciphertext = cipher(str, key);
    cout << ciphertext << endl;
    string plaintext = decrypt(ciphertext, key);
    cout << plaintext << endl;
}