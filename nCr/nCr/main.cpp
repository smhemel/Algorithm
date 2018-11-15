//
//  main.cpp
//  nCr
//
//  Created by S M HEMEL on 1/23/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
using namespace std;
//nCr
int nCr(int n,int r)
{
    if(n<(r<<1)) r = n-r;
    int ans = 1;
    for(int i=0; i<r; ans *= (n-i),ans /= (i+1),i++);
    return ans;
}
int main()
{
    int n,r;
    cin >> n >> r;
    cout << nCr(n,r) <<endl;
    return 0;
}
