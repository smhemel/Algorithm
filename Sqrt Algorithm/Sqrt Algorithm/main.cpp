//
//  main.cpp
//  Sqrt Algorithm
//
//  Created by S M HEMEL on 1/23/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
using namespace std;
int sqrt(int n)
{
    int y = n>>1;
    for(int i=0; y<(n/y);y=(y/2)+i++){
        y=(y>>1)+1;
        if(y<n)
            break;
    }
    return y;
    
}
int main()
{
    int n;
    cin >> n;
    int x = sqrt(n);
    cout << x <<endl;
}
