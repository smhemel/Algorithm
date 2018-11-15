#include <iostream>
using namespace std;
long long dp[1000][1000];
long long nCr_fast(int n, int r)
{
    if(n<(r*2)) r=n-r;
    long long ans=1;
    for(int i=1; i<=r; (ans*=n, ans/=i), i++, n--);
    return ans;
}
long long nCr(int n, int r)
{
    if(n==r) return 1;
    else if(r==1) return n;
    else if(dp[n][r]>0) return dp[n][r];
    return dp[n][r] = nCr(n-1, r)+ nCr(n-1, r-1);
}
int main()
{
    long long n, r;
    cin>>n>>r;
    cout<<nCr_fast(n,r)<<endl;
    return 0;
}
