#include<iostream>
#include<string>

using namespace std;

int gcd(int a, int b){
    int t;
    while(b!=0){
        t=b;
        b = a%b;
        a=t;
    }
    return a;
}

string cipher(int a, int b, string s){
    string ans = "";
    for(char c : s){
        if(isalpha(c)){
            char base = isupper(c) ? 'A' :'a';
            ans += (a*(c-base)+b)%26 + base;
        }
        else    
            ans+=c;
    }
    return ans;
}

int a_inverse(int a, int m){
    for(int i=1 ; i<m ; i++){
        if(a*i % m == 1)
            return i;
    }
    return -1;
}

string plain(int a, int b , string s){
    int a_inv = a_inverse(a, 26);
    if(a_inv == -1){
        cout << "a_inv doesn't exists " ;
        return "";
    }
    string ans = "";
    for(char c : s){
        if(isalpha(c)){
            char base = isupper(c) ? 'A' :'a';
            ans += (a_inv*(c-base-b+26))%26 + base;
        }
        else    
            ans+=c;
    }
    return ans;
        
}

int main(){
    int a,b;
    string s;
    cin >> a >> b;
    
    if(gcd(a,26)!= 1){
        cout << "a should be coprime with 26" ;
        return 0;
    }
    cin.ignore();
    getline(cin , s);

    string ct = cipher(a,b,s);
    cout << ct << endl;

    string pt = plain(a,b,ct);
    cout << pt << endl;
}