//
//  main.cpp
//  LCS(longest Common Subsecquence)
//
//  Created by S M HEMEL on 12/10/16.
//  Copyright © 2016 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int DP[100][100],dir[100][100];
string X,Y;
int LCS(int i,int j)
{
    if(i==0||j==0)
        return 0;
    if(DP[i][j]!=-1)//এই স্টেটটি আগেই ক্যালকুলেট করা হয়ে গিয়েছে
        return DP[i][j];
    if(X[i-1]==Y[j-1])//ম্যাচিং পেলাম।
    {
        DP[i][j]=1+LCS(i-1,j-1);
        dir[i][j]=3;
    }
    else //ম্যাচ করেনি
    {
        int a=0,b=0;
        a=LCS(i-1,j);
        b=LCS(i,j-1);
        if(a>b) {
            DP[i][j]=a;
            dir[i][j]=2;
        }
        else {
            DP[i][j]=b;
            dir[i][j]=1;
        }
    }
    return DP[i][j];
}
int main()
{
    getline(cin,X);
    getline(cin,Y);
    memset(DP,-1,sizeof DP);
    memset(dir,-1,sizeof dir);
    int n=(int)X.size();
    int m=(int)Y.size();
    int k=LCS(n,m);
    string ans;
    cout<<"length of LCS:"<<k<<endl;
    while(1)
    {
        if(dir[n][m]==-1||n==0||m==0)
            break;
        if(dir[n][m]==3)
        {
            ans=ans+X[n-1];
            n--;
            m--;
        }
        else if(dir[n][m]==2)
            n--;
        else if(dir[n][m]==1)
            m--;
    }
    reverse(ans.begin(),ans.end());
    cout<<"LCS for given two strings is "<<ans<<endl;
}
