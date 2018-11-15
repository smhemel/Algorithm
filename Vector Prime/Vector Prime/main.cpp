//
//  main.cpp
//  Vector Prime
//
//  Created by S M HEMEL on 3/17/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> f;
vector<int> factors(int n) {
    for (int x = 2; x*x<=n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if(n>1)
        f.push_back(n);
    return f;
}
int main()
{
    int n;
    cin >> n;
    vector <int> fac = factors(n);
    for(auto m : fac)
        cout << m << endl;
    return 0;
}
