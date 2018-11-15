//
//  main.cpp
//  seive
//
//  Created by S M HEMEL on 11/23/16.
//  Copyright © 2016 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <cmath>
#define N 1000000
#define M 1000000
using namespace std;
int a[N];
bool prime[M];
void seive()
{
    prime[2] = 0;
    int root = sqrt(M);
    for (int i=3; i<=root+1; i+=2)
        if(prime[i]==0)
            for (int j=i*i; j<=M; j+=(i+i))
                prime[j] = 1;
    a[1] = 2;
    int l=2;
    for(int i=3; i<=M; i+=2)
        if(prime[i]==0)
            a[l++] = i;
}
int main()
{
    seive();
    int test;
    cin >> test;
    for(int i=0; i<test;i++){
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}
