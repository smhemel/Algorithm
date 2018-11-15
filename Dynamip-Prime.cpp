#include<iostream>
#include<math.h>
using namespace std;
int prime[10000000], paici=0;
int sive(int N);
int main()
{
    int x,N;
    while(cin>>N){
        if(N%2==0)
            cout<<"Not Prime"<<endl;
        else {
            x=sive(N);
            if(x==0) cout<<"prime"<<endl;
            else cout<<"Not Prime"<<endl;
        }
    }
    return 0;
}
int sive(int N)
{
    int root = sqrt(9999999)+1;
    if(paici>0) return prime[N];
    cout<<N<<endl;
    for(int i=3; i<=root; i+=2){
        for(int j=i*i; j<=9999999; j+=(i+i)){
            prime[j] = 1;
        }
    }
    paici++;
    return prime[N];
}


