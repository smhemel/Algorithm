//
//  main.cpp
//  Square Root Manual
//
//  Created by S M HEMEL on 3/25/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
using namespace std;
double sqrt_root(double a)
{
    if(a<0) return -1;
    if(a==0 || a==1) return a;
    double precision = 0.00001;
    double start = 0;
    double end = a;
    while(end-start>precision)
    {
        double mid = (start+end)/2;
        double midSqr = mid*mid;
        if(midSqr==a)
            return mid;
        else if(midSqr<a)
            start = mid;
        else
            end = mid;
    }
    return (start+end)/2;
}

int main()
{
    int n;
    cin >> n;
    printf("%lf\n",sqrt_root(n));
    return 0;
}
