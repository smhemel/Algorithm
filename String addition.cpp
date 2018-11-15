//
//  main.cpp
//  String addition
//
//  Created by S M HEMEL on 1/31/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
    char s[10000],s1[10000],s3[10000];
    while (cin >> s >> s1)
    {
        int len = (int) strlen(s);
        int len1 = (int) strlen(s1);
        if(len<len1)
        {
            int t = len1;
            len1 = len;
            len = t;
            strcpy(s3,s1);
            strcpy(s1,s);
            strcpy(s,s3);
        }
        int temp = 0,x = 0;
        for (int i=len-1,l=len1-1; i>=0; i--,l--)
        {
            temp = (l<0) ? (s[i]-'0') : s[i]
        }
    }
    return 0;
}
