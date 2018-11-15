//
//  main.cpp
//  Super Fast & Memory-tight Sieve By Yarin
//
//  Created by S M HEMEL on 3/23/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//


/*#include <iostream>
#include<cstdio>
#include<cstring>
#define MAXS 10000000
#define MAXSH (MAXS/2)
#define MAXSQ 5000
#define isprime(n) (a[n >> 4] & (1<<(((n)>>1)&7))) //works when n is odd
#define PN 5761455
using namespace std;
char a[MAXS/16+2];
int prime[PN],c;
void seive()
{
    int i,j;
    memset(a,255,sizeof(a));
    a[0]=0xFE;
    for(i=1;i<MAXSQ;i++)
        if (a[i>>3]&(1<<(i&7)))
            for(j=i+i+i+1;j<MAXSH;j+=i+i+1)
                a[j>>3]&=~(1<<(j&7));
    prime[c++]=2;
    for(i=3;i<MAXS;i+=2)
        if(isprime(i)) {
            prime[c++]=i;
            printf("Total prime:%d %d\n",c,prime[c-1]);
        }
}
int main(){
    seive();
    return 0;
}*/




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIEVE 100000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd

//have to check for even numbers
void sieve()
{
    memset(a,255,sizeof(a));
    a[0]=0xFE;
    for(int i=1; i<MAXSQRT; i++)
        if (a[i>>3]&(1<<(i&7)))
            for(int j=i+i+i+1; j<MAXSIEVEHALF; j+=i+i+1)
                a[j>>3]&=~(1<<(j&7));
}


