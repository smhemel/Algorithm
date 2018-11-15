//
//  main.cpp
//  Bitwise Seive
//
//  Created by S M HEMEL on 11/26/16.
//  Copyright © 2016 S M HEMEL. All rights reserved.
//



#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#define N 10000000
#define check(n) (pri[n>>6] &(1<<((n>>1)&31)))
#define visit(n) (pri[n>>6]|=(1<<((n>>1)&31)))
using namespace std;
int prime[6666666];
unsigned pri[(N>>6)+2];
std::clock_t __start;
double __duration;
void start_timer() { __start = std::clock(); }
void print_timer() {
    __duration = (std::clock() - __start) / (double)CLOCKS_PER_SEC;
    std::cout << "Duration: " << __duration << '\n';
}
void bitwise_seive()
{
    pri[1] = 1,prime[0]=2;
    int i,l;
    int root = sqrt(N)+1;
    for(i=3; i<root; i+=2)
        if(!check(i))
            for(l=i*i; l<N; l+=(i<<1))
                visit(l);
    
    for(i=3, l=1; i<N; i+=2)
        if(!check(i))
            prime[l++]=i;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    start_timer();
    //freopen("input1.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    bitwise_seive();
    //int n, test=100;
    //cin >> test;
    for(int i=0; i<=100; i++) {
        //cin >> n;
        cout << prime[i] <<endl;
    }
    print_timer();
    return 0;
}

