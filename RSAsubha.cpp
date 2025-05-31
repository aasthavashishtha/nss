#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int t=b;
        b = a%b;
        a=t;
    }
    return a;
}

int mod_inv(int a, int m){
    for(int x=2; x<m ; x++){
        if(a*x%m == 1)
            return x;
    }
    return -1;
}

long long expo(int base, int exp,int mod ){
    base = base%mod;
    long long result = 1;
    while(exp>0){
        if(exp%2 ==1){
            result = (result*base )%mod;
        }
        exp = exp >>1;
        base = base*base;
    }
    return result;
}

int main(){
    long long p,q;
    long long e,d,totient,n,M;

    cin >> p >> q;

    n = p*q;
    totient = (p-1)*(q-1);


    for(e=2; e<totient ; e++){
        if(gcd(e,totient) == 1)
            break;
    }

    d = mod_inv(e,totient);
    cin >> M;
    long long E = expo(M,e,n);
    cout << E <<endl;
    long long D = expo(E,d,n);
    cout << D <<endl;
}