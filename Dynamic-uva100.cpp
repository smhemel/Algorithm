 #include<iostream>
 #include<cstdio>
 using namespace std;
 int DP[10000000];
 int uva(int n)
 {
    if(n==1)
        return 1;
    if(DP[n]>0)
        return DP[n];
    cout<<DP[n];
    if(n%2==0)
        return DP[n] = uva(n/2)+1;
    else if(n%2==1)
        return DP[n] = uva(3*n+1)+1;
    return DP[n];
 }
 int main()
 {
    int a,b;
    while(cin>>a>>b){
        int top=0;
        for(int i=a; i<=b; i++){
            int x = uva(i);
            if(x>top) top = x;
        }
        cout<<top<<endl;
    }
    return 0;
 }
