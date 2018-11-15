//
//  main.cpp
//  Finding prime
//
//  Created by S M HEMEL on 3/18/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
using namespace std;
std::clock_t __start;
double __duration;
void start_timer() { __start = std::clock(); }
void print_timer() {
    __duration = (std::clock() - __start) / (double)CLOCKS_PER_SEC;
    std::cout << "Duration: " << __duration << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //start_timer();
    long long int n;
    bool flag = true;
    scanf("%lld",&n);
    int root = sqrt(n)+1;
    for(int i=2; i<=root; i++)
        if(n%i==0)
        {
            flag = false;
            break;
        }
    if(flag==true)
        puts("YES");
    else
        puts("NO");
    print_timer();
    return 0;
}

