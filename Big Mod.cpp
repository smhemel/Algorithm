//
//  main.cpp
//  Big Mod
//
//  Created by S M HEMEL on 1/29/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int big_mod(int base, int power, int mod)
{
    if(power==0)    return 1;
    else if(power%2==1)
    {
        int p1 = base % mod;
        int p2 = (big_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else
    {
        int p1 = (big_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
    return 0;
}
/*long long mod_pow(long long a, int b){
    long long ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans*a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ans;
}*/
int modPow(int b, int p, int m)
{
    // Big Mod 2 30 11
    int res = 1;
    while (p != 0)
    {
        res = (res*b*(p&1) + res*((p&1)==0))%m;
        b = (b*b)%m;
        p >>= 1;
    }
    return res;
}
int modpow(int x, int n, int m) {
    if (n == 0)
        return 1%m;
    cout << "asi\n";
    int u = modpow(x,n/2,m);
    cout << "u = " << u << endl;
    u = (u*u)%m;
    if(n%2 == 1)
        u = (u*x)%m;
    cout << "mod u = " << u << endl;
    return u;
}
int main()
{
    int b,p,m;
    while (cin >> b >> p >> m)
    {
        //cout << big_mod(b,p,m) <<endl;
        cout << modpow(b,p,m) <<endl;
    }
    return 0;
}
