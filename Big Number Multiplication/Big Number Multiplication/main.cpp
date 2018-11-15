//
//  main.cpp
//  Big Number Multiplication
//
//  Created by S M HEMEL on 3/8/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string stradd(string s1, string s2)
{
    string a;
    if(s2.size() < s1.size())
        swap(s1, s2);
    int s=0, c=0;
    int l=(int)s1.size();
    int ll = (int)s2.size();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    for(int i=l; i<ll; i++)
        s1 += "0";
    for(int i=0; i<ll; i++) {
        s = (s1[i]-'0') + (s2[i] - '0')+c;
        c = s / 10;
        a += (s % 10) + '0';
    }
    if(c > 0)
        a += c % 10 + '0';
    
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(a.begin(), a.end());
    return a;
}

string strmul(string s1, string s2)
{
    string m, a;
    int l, ll, j, c, s=0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    if(s1.size() > s2.size())
        swap(s1, s2);
    
    l = (int)s1.size();
    ll = (int)s2.size();
    
    j=0;
    m = "", a = "";
    for(int i=0; i<ll; i++) {
        c = 0;
        m = "";
        for(int j=0; j<l; j++) {
            s = (s1[j]-'0') * (s2[i] - '0') + c;
            c = s / 10;
            m += (s % 10) + '0';
        }
        if(c > 0)
            m += c % 10 + '0';
        reverse(m.begin(), m.end());
        
        for(int k=j; k<j+i; k++)
            m += "0";
        reverse(m.begin(), m.end());
        if(i==0)
            a=m;
        if(i != 0) {
            c = 0;
            reverse(a.begin(), a.end());
            reverse(m.begin(), m.end());
            a = stradd(a, m);
            reverse(a.begin(), a.end());
        }
    }
    
    bool flag = true;
    for(int i=0; i<a.size(); i++) {
        if(a[i] != '0') {
            flag = false;
            break;
        }
    }
    if(flag)
        a = "0";
    
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(a.begin(), a.end());
    return a;
}
int main()
{
    string a, b;
    cin >> a >> b;
    /* String Multiplication */
    cout << strmul(a, b) << endl;
    /* String Addition */
    cout << stradd(a, b) << endl;
    return 0;
}
