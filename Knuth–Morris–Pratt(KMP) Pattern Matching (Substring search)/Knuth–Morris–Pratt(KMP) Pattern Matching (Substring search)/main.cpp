//
//  main.cpp
//  Knuth–Morris–Pratt(KMP) Pattern Matching (Substring search)
//
//  Created by S M HEMEL on 4/10/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int lps[10000];
string text,pattern;
void get_lps(int len1)
{
    int i=0,j=1;
    lps[0] = 0;
    while(j<len1)
    {
        if(pattern[i]==pattern[j]){
            lps[j] = i+1;
            j++,i++;
        }
        else {
            if(i==0)
                lps[j] = 0,j++;
            else
                i = lps[i-1];
        }
    }
}
void kmp(int len, int len1)
{
    int i=0,j=0;
    while (i<len)
    {
        if(text[i]==pattern[j])
            i++,j++;
        if (j==len1) {
            printf("Found pattern at index %d \n", i-j);
            //j = lps[j-1];
            break;
        }
        else if(pattern[j] != text[i]) {
            if(j==0)
                i++;
            else
                j = lps[j-1];
        }
    }
}
int main()
{
    while (getline(cin,text))
    {
        getline(cin,pattern);
        int len = (int)text.length();
        int len1 = (int)pattern.length();
        get_lps(len1);
        kmp(len,len1);
        text.clear();
        pattern.clear();
    }
    return 0;
}




/*#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <string>
using namespace std;
string pat = "";
string txt =
void computeLPSArray(char *pat, int M, int *lps);
void KMPSearch(char *pat, char *txt)
{
    int pat_len = (int)strlen(pat);
    int txt_len = (int)strlen(txt);
    int *lps = (int *)malloc(sizeof(int)*pat_len);
    int j  = 0;
    computeLPSArray(pat, pat_len, lps);
    int i = 0;
    while(i<txt_len)
    {
        if(pat[j] == txt[i])
            j++,i++;
        if (j == pat_len) {
            printf("Found pattern at index %d \n", i-j);
            j = lps[j-1];
        }
        else if(pat[j] != txt[i])
        {
            if(j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    free(lps);
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    int i;
    lps[0] = 0;
    i = 1;
    while(i<M)
    {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len!=0)
                len = lps[len-1];
            else
                lps[i] = 0,i++;
        }
    }
}
int main()
{
    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}*/
