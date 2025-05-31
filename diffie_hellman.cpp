#include<iostream>

using namespace std;

int expo(int base, int exp, int mod){
    base = base%mod;
    int result = 1;
    while(exp>0){
        if(exp%2 == 1){
            result = (result*base)%mod;
        }
        exp = exp >>1;
        base = (base*base)%mod;
    }
    return result;
}

int main(){

    int p,g;
    cin >> p >> g;

    int a, b;
    cin >> a >> b;

    int A = expo(g,a,p);
    int B = expo(g,b,p);
    cout << A << " " << B << endl;
    int s1 = expo(B, a,p);
    int s2 = expo(A, b, p);

    if(s1==s2)
        cout << "key shared";
    cout << s1 << " " << s2;
}