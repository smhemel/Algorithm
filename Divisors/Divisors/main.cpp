//
//  main.cpp
//  Codeforces Round #319 (Div. 2) - A. Multiplication Table
//
//  Created by S M HEMEL on 21/7/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int printDivisors(int n)
{
    int ans = 0;
    vector<int> v;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            if (n/i == i)
                ans++;
            else
            {
                ans++;
                v.push_back(n/i);
            }
        }
    }
    for (int i=(int)v.size()-1; i>=0; i--)
        ans++;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << printDivisors(n) << endl;
    return 0;
}
