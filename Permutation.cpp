#include<bits/stdc++.h>
using namespace std;
int used[20],number[20];
void permutation(int x, int n);
int main()
{
    int n, m;
    n=1, m=3;
    permutation(n,m);
}
void permutation(int x, int n)
{
    if(x==n+1){
        for(int i=1; i<=n; i++)
            printf("%d ",number[i]);
        cout<<endl<<endl;
        return;
    }
    for(int i=1; i<=n; i++) if(!used[i]){
        used[i] = 1;
        number[x] = i;
        permutation(x+1,n);
        used[i] = 0;
    }
}
