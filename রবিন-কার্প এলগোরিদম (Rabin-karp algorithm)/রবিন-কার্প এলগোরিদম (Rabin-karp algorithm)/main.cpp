//
//  main.cpp
//  রবিন-কার্প এলগোরিদম (Rabin-karp algorithm)
//
//  Created by S M HEMEL on 3/30/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include <string>
#define d 256
using namespace std;
// call search("i am hemel", "hemel",101)
bool search(string pat,string txt, int q) {
    int len_pat = (int)pat.size();
    int len_txt = (int)txt.size();
    int p = 0,t = 0,h = 1,j;
    for(int i=0; i<len_pat-1; i++) h = (h*d)%q;
    for(int i=0; i<len_pat; i++) {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
    for(int i=0; i<=len_txt-len_pat; i++) {
        if(p==t){
            for(j=0; j<len_pat; j++) {
                if (txt[i+j] != pat[j])
                    break;
            }
            if(j==len_pat) {
                printf("Pattern found at index %d \n", i);
                return true;
            }
        }
        if (i<len_txt-len_pat) {
            t = (d*(t-txt[i]*h) + txt[i+len_pat])%q;
            if(t<0) t = (t+q);
        }
    }
    return false;
}
int main()
{
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    int q = 101;
    if(search(pat, txt, q)) puts("String Match");
    else puts("Not Match");
    return 0;
}
