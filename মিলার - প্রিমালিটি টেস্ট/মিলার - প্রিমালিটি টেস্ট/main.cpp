//
//  main.cpp
//  মিলার - প্রিমালিটি টেস্ট
//
//  Created by S M HEMEL on 5/9/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
using namespace std;
//miller_rabin(n,18)
typedef unsigned long long ll;
ll mulmod(ll a, ll b, ll c){
    ll x = 0,y = a%c;
    while(b>0) {
        if(b&1)
            x = (x+y)%c;
        y = (y<<1)%c;
        b >>= 1;
    }
    return x;
}

ll pow(ll a, ll b, ll c){
    ll x = 1, y = a;
    while(b>0){
        if(b&1) x = mulmod(x,y,c);
        y = mulmod(y,y,c);
        b >>= 1;
    }
    return x;
}

bool miller_rabin(ll p, int it)
{
    if(p<2 || !(p&1)) return false;
    if(p==2) return true;
    ll s = p-1;
    while(s%2==0) s >>= 1;
    while(it--){
        ll a = rand()%(p-1)+1,temp = s;
        ll mod = pow(a,temp,p);
        if(mod==-1 || mod==1) continue;
        while(temp!=p-1 && mod!=p-1){
            mod = mulmod(mod,mod,p);
            temp <<= 1;
        }
        if(mod!=p-1) return false;
    }
    return true;
}
int main(){
    int test;
    unsigned long long n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%llu",&n);
        printf("%s\n",miller_rabin(n,18) ? "YES" : "NO");
    }
    return 0;
}

