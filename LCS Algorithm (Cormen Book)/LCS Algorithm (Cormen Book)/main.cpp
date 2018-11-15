//
//  main.cpp
//  LCS Algorithm (Cormen Book)
//
//  Created by S M HEMEL on 2/4/18.
//  Copyright © 2018 Eastern University. All rights reserved.
//

#include<iostream>
#include<cstring>
using namespace std;
int c[20][20];
char b[20][20];
void print_lcs(int x,int y)
{
    if(x==0 || y==0) return;
    if(b[x][y]=='c') {
        print_lcs(x-1,y-1);
        printf("%c",str[x-1]);
    }
    else if(b[x][y]=='u') print_lcs(x-1,y);
    else print_lcs(x,y-1);
}
string str="algorithm";
string pattern="alignment";
void lcs() {
    int m = (int)str.size();
    int n = (int)pattern.size();
    for(int i=0; i<=m; i++) c[i][0]=0;
    for(int i=0; i<=n; i++) c[0][i]=0;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) {
            if(str[i-1]==pattern[j-1]) {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
            }
            else if(c[i-1][j]>c[i][j-1]) {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    print_lcs(m,n);
}
int main()
{
    printf("longest common subsequence is : ");
    lcs();
    puts("");
    return 0;
}
