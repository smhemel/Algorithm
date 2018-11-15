#include <bits/stdc++.h>
#define N 20000
using namespace std;
char x[N], dp[N][N+N];
char a[N], b[N];
void add(char a[], char b[]);
/*This is my summation function*/
void store_fib();
/*This function for store my Fibonacci*/
int main()
{
    store_fib();
    int n;
    while(cin>>n){
        cout<<dp[n-1]<<endl;
    }
    return 0;
}
void add(char a[], char b[])
{
    int i, j, k, len, top_len;
    top_len = strlen(a);
    len = strlen(b);
    memset(x,0,sizeof(x));
    if(top_len<len)
        return add(b,a);
    int sum=0;
    for(i=top_len-1,j=0,k=len-1; i>=0; i--, k--){
        if(k<0) sum+=(a[i]-48);
        else sum+=((a[i]-48)+(b[k]-48));
        x[j++] = (sum%10)+48;
        sum/=10;
    }
    if(sum>0) x[j++]=(sum+48);
    for(i=0,k=j-1; i<=(j/2); i++,k--){
        if(i<k){
            char temp = x[i];
            x[i] = x[k];
            x[k] = temp;
        }
    }
}
void store_fib()
{
    a[0]='1',b[0]='1';
    for(int i=0; i<N; i++){
        add(a,b);
        /*Call for addition*/
        strcpy(a,b);
        strcpy(b,x);
        strcpy(dp[i],a);
    }
}
