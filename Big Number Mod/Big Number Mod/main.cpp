//
//  main.cpp
//  Big Number Mod
//
//  Created by S M HEMEL on 3/8/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#define LL long long int
using namespace std;
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
int main()
{
    string s;
    LL n;
    cin >> s >> n;
    cout << strmod(s, n) << endl;
    return 0;
}
