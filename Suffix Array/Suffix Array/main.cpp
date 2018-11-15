//
//  main.cpp
//  Suffix Array
//
//  Created by S M HEMEL on 5/29/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct suffix
{
    int index;
    int rank[2];
};
int cmp(struct suffix a, struct suffix b) {
    return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ?1: 0):
    (a.rank[0] < b.rank[0] ? 1: 0);
}
int *buildSuffixArray(char *txt, int n)
{
    struct suffix suf[n];
    for(int i=0; i<n; i++) {
        suf[i].index = i;
        suf[i].rank[0] = txt[i] - 'a';
        suf[i].rank[1] = ((i+1) < n) ? (txt[i + 1] - 'a'): -1;
    }
    sort(suf, suf+n, cmp);
    int ind[n];
    for (int k = 4; k < 2*n; k = k*2)
    {
        int rank = 0;
        int prev_rank = suf[0].rank[0];
        suf[0].rank[0] = rank;
        ind[suf[0].index] = 0;
        
        for (int i = 1; i < n; i++) {
            if (suf[i].rank[0] == prev_rank &&
                suf[i].rank[1] == suf[i-1].rank[1]) {
                prev_rank = suf[i].rank[0];
                suf[i].rank[0] = rank;
            }
            else {
                prev_rank = suf[i].rank[0];
                suf[i].rank[0] = ++rank;
            }
            ind[suf[i].index] = i;
        }
        
        for (int i = 0; i < n; i++) {
            int nextindex = suf[i].index + k/2;
            suf[i].rank[1] = (nextindex < n)?
            suf[ind[nextindex]].rank[0]: -1;
        }
        sort(suf, suf+n, cmp);
    }
    
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suf[i].index;
    
    // Return the suffix array
    return  suffixArr;
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    char txt[] = "Hemel";
    int n = (int)strlen(txt);
    int *suffixArr = buildSuffixArray(txt,  n);
    cout << "Following is suffix array for " << txt << endl;
    printArr(suffixArr, n);
    return 0;
}
