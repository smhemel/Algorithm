//
//  main.cpp
//  Big Number GCD
//
//  Created by S M HEMEL on 3/8/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <string>
#define LL long long int
using namespace std;

LL gcd(LL x, LL y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

LL strmod(string s, LL n)
{
    LL i, sum = 0;
    for(i=0; i<s.size(); i++)
    {
        sum = sum * 10 + (s[i]-'0');
        sum %= n;
    }
    return sum;
}

LL BigNumberGCD(LL x, string y)
{
    LL tmpy = strmod(y, x);
    return gcd(x, tmpy);
}


int main()
{
    string y;
    // y is a very big number
    LL x;
    cin >> x >> y;
    cout << BigNumberGCD(x, y) << endl;
    return 0;
}
