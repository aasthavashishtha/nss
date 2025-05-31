#include<iostream>
#include<vector>
#include<string>
using namespace std;

long long mod_inverse(long long a, long long m){
    for(int i=1; i<m ; i++){
        if((a*i)%m == 1)
            return i;
    }
    return -1;
}

long long gcd(long long a, long long b){
    while(b!=0){
        int t = b;
        b=a%b;
        a=t;
    }
    return a;
}

long long expo(long long base, long long exp, long long mod){
    long long result =1;
    base = base%mod;
    while(exp>0){
        if(exp%2 == 1){
            result = (result*base)%mod;
        }
        exp = exp >> 1;
        base = (base*base)% mod;
    }
    return result;
}

int main(){
    long long p,q;
    cin >>p >> q;
    long long n = p*q;
    long long totient= (p-1)*(q-1);

    long long e=7;
    // for(e=2; e< n ; e++){
    //     if(gcd(e,totient) == 1)
    //         break;
    // }
    long long d = mod_inverse(e,totient);

    cout << e << endl << d << endl;
    // long long  M;
    // do{
    //     cin >> M;
    // }while(M>=n);


    string m;
    cin >> m;
    vector<long long> v;
    for(int i=0; i<m.size() ; i++){
        v.push_back((long long)(m[i]-'A'));
    }
    vector<long long> ans;
    for(long long M:v){
        ans.push_back(expo(M, e, n));
    }
    for(long long M : ans){
        cout << M << "  ";
    }
    cout << endl;
    string res = "";
    for(long long M:ans){
        int val = expo(M, d, n);
        res += ('A'+val);
    }
    cout << res ;
}