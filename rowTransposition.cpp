#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

string ciphertext(string s,vector<int> key){
    int n = key.size();
    int row = (s.size() +n-1)/n;
    vector<vector<char>> v(row, vector<char>(n,'*'));
    int idx =0 ;
    for(int i=0; i<row ; i++){
        for(int j=0 ; j< n && idx<s.size() ; j++){
            v[i][j] = s[idx++];
        }
    }
    map<int,int>m;
    for(int i=0;i<n; i++){
        m.insert({key[i],i});
    }
    string ct = "";
        for(int i=1;i<=n ;i++){
            int col = m[i];
            for(int j=0;j<row;j++){
                ct+= v[j][col];
            }
        }
        
    return ct;
}

string decrypt(string s,vector<int> key){
    int n = key.size();
    int row = (s.size() +n-1)/n;
    map<int ,int> m;
    for(int i=0;i<n; i++){
        m.insert({key[i],i});
    }
    vector<vector<char>> v(row, vector<char>(n,'*'));
    int idx = 0;
    for(int i=1; i<=n ; i++){
        int col = m[i];
        for(int j=0 ; j<row && idx < s.size() ; j++){
            v[j][col] = s[idx++];
        }
    }
    string pt="";
    for(int i=0; i<row ; i++){
        for(int j=0 ; j< n && v[i][j]!='*' ; j++){
            pt+=v[i][j];
        }
    }
    return pt;
}

int main(){
    string s;
    vector<int> key;
    cin >> s;
    int n;
    cin >> n;
    for(int i=0; i<n ; i++){
        int num;
        cin >>num;
        key.push_back(num);
    }
    string ct = ciphertext(s, key);
    cout  << ct;
    cout << decrypt(ct , key) << endl;
}