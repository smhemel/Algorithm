//
//  main.cpp
//  Knuth–Morris–Pratt(KMP) Pattern Matching (Substring search)
//
//  Created by S M HEMEL on 3/16/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;
char text[10000], pattern[10000];
int main()
{
    int j = 0;
    printf("Enter string: ");
    cin >> text;
    printf("Enter substring: ");
    cin >> pattern;
    int text_len = (int) strlen(text);
    int pattern_len = (int) strlen(pattern);
    int n = text_len - pattern_len+1;
    for(int i=0; i<n; i++)
    {
        int index = i;
        if(text[i] == pattern[j])
        {
            while(j != pattern_len && text[i] == pattern[j])
                i++,j++;
            if(j == pattern_len) {
                printf("Match found from position %d to %d.\n", index+1, i);
                return 0;
            }
            else {
                i = index+1;
                j = 0;
            }
        }
    }
    printf("No substring match found in the string.\n");
    return 0;
}
