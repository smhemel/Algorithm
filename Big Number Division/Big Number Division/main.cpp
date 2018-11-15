//
//  main.cpp
//  Big Number Division
//
//  Created by S M HEMEL on 3/8/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <string>
#define ll long long int
using namespace std;
string strdiv(string s, ll n)
{
    bool flag = true,check = false;
    ll sum = 0, t;
    string ans;
    for(ll i=0; s[i]; i++)
    {
        sum = sum*10 + (s[i]-'0');
        t = sum / n;
        if(t == 0 && !flag)
        {
            continue;
        }
        else
        {
            if(t!=0 || check){
                check = true;
                ans += (t + '0');
            }
            flag = 1;
            sum = (sum % n);
        }
    }
    if(flag == 0)
        ans = "0";
    return ans;
}
int main()
{
    string s;
    ll n;
    cin >> s >> n;
    cout << strdiv(s,n) << endl;
    return 0;
}
