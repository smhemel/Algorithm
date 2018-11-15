//
//  main.cpp
//  Mehedi Sir
//
//  Created by S M HEMEL on 6/3/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

Name:
OJ:
Link:
Algorithm:
Type:
Difficulty:
Interest:
Additional:
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

const int    inf = (1<<28);
const double pi  = (2.0*acos(0.0));
const double eps = 1e-9;

//typedef long long           lli;
//typedef __int64             lli;
//typedef unsigned long long  llu;
//typedef unsigned __int64    llu;
//typedef pair < int , int >  pii;
//typedef vector < int >      vi;
//typedef vector < string >   vs;

#define CLR( a )  memset(a , 0  , sizeof (a))
#define SET( a )  memset(a , -1 , sizeof (a))
#define SZ ( a )  ((int)a.size())
#define all( a )  a.begin(),a.end()


//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep ( i, a, b, x ) for( i = ( a ) ; i <= ( b ) ; i += x )
#define rep  ( i, n )       _rep( i, 0, n - 1, 1 )
#define _rrep( i, a, b, x ) for( i = (a) ; i >= (b) ; i -= x )
#define rrep ( i, a, b)     _rrep( i, a, b, 1)
#define xrep ( i, a, b)     _rep( i, a, b, 1)

#define SD( a ) scanf("%d",&a)
#define SL( a ) scanf("%lld",&a)
#define SI( a ) scanf("%I64d",&a)
#define SS( a ) scanf("%s",a)

#define pb push_back
#define ff first
#define ss second
/**************************************/
lli modpow(lli b, lli e, lli m)
{
    lli res=1;
    while (e>0)
    {
        if(e&1)res=(res*b)%m;
        e >>= 1; b=(b*b)%m;
    }
    return res;
}
/***************************************/
void decomp(lli a) // prime factoring
{
    int i ,j ,k;
    lli n =a;
    nk=0;
    for(i=0;i<np && prime[i]*prime[i]<=n;i++)
    {
        cnt=0;
        while(!(n%prime[i])) n/=prime[i] , cnt++;
        if(cnt) p[nk] = prime[i] , e[nk]=cnt , nk++;
    }
    if(n!=1) p[nk]=n , e[nk]=1, nk++;
}
/**************************************/
#define chekb(x) (flag[x>>6] & (1<<((x>>1) & 31)))
#define setb(x)  (flag[x>>6] |=(1<<((x>>1) & 31)))
#define isp(x)   ((x==2) || (x>1 && (x&1) && !chekb(x)))
//const int mx = 10000000
//const int S  = sqrt(mx)+1;
//int flag[(mx>>6)+10];
//int prime[700000];
void siv(void)
{
    int i,j,k; np=0;
    setb(0); prime[np++]=2;
    for(i=3;i<=S;i+=2)
        if(!chekb(i))
            for(prime[np++]=i ,j=i*i ,k=(i<<1) ; j<=mx ; j+=k)
                setb(j);
    for(;i<=mx;i+=2) if(!chekb(i)) prime[np++]=i;
}
/**************************************/
//  return modular inverse of num with respect to mod
//  actually solves ax+by=1 and returns x where gcd(a,b)=1
//  There is another code for modular inverse
int modinver(int num, int modulo)
{
    int a=num,b=modulo,x,y,r,s,q,_a,_r,_s;
    s=x=1; r=y=0;
    while(b)
    {
        _a = a; _s = s;
        _r = r; q = a/b;
        
        a = b;  b = _a%b;
        r = x - q*_r;
        s = y - q*_s;
        x = _r; y = _s;
    }
    return (x<0)?x+modulo:x;
}
/**************************************/
pii egcd(int a,int b)
{
    if(b==0) return pii(1,0);
    else
    {
        pii d= egcd(b,a%b);
        return pii(d.ss,d.ff-(d.ss)*(a/b));
    }
}
/**************************************/
// Big Number % int
int bigmodi(char *Bnum , int modulo)
{
    SS(Bnum);
    SD(modulo);
    int i ,ans;
    for(i=ans=0;Bnum[i];i++)
        ans = (ans*10 + Bnum[i]-'0') % modulo;
    return ans;
}
/**************************************/
// Euler's Totient Function - Sieve Version
int mx=5000000;
llu phi[5000010];
bool isnp[5000010];
int a,b;

void PHI()
{
    int i,j,k;
    for(i=2;i<=mx;i++) phi[i]=i;
    phi[1]=0;
    phi[2]=1;
    for(i=4;i<=mx;i+=2)
        phi[i]/=2 , isnp[i]=true;
    for(i=3;i<=mx;i+=2)
        if(!isnp[i])
            for(phi[i]=i-1,j=i<<1;j<=mx;j+=i)
                phi[j]/=i , phi[j]*=(i-1) , isnp[j]=true;
}

/**************************************/
int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}
lli gcd(lli a,lli b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
/**************************************/
// Segmented Prime Count - Naive

void segPrmCount(lli a , lli b)
{
    siv();
    memset(isnp,0,sizeof(isnp));
    lli sqb = sqrt(double(b));
    for(i=0;i<np && prime[i]<=sqb;i++)
    {
        m = ceil(double(a)/double(prime[i]));
        //m = (a+1)/prime[i];
        if(m==1) m++;
        for(n=m*prime[i] ; n<=b ; n+=prime[i])
            isnp[int(n-a)]=true;
    }
    int cnt=0;
    for(i=a;i<=b;i++)
        if(!isnp[int(i-a)])
            cnt++;
    if(a==1) cnt--;
    printf("Case %d: %d\n",++kase,cnt);
}
// Zobayer's
int segmented_sieve(int a, int b)
{
    unsigned i, j, k, cnt = (a<=2 && 2<=b)? 1 : 0;
    if(b<2) return 0;
    if(a<3) a = 3;
    if(a%2==0) a++;
    mset(segment,0);
    for(i=0; sq(primes[i])<=b; i++)
    {
        j = primes[i] * ( (a+primes[i]-1) / primes[i] );
        if(j%2==0) j += primes[i];
        for(k=primes[i]<<1; j<=b; j+=k)
            if(j!=primes[i])
                setC(segment, (j-a));
    }
    for(i=0; i<=b-a; i+=2)
        if(!chkC(segment, i))
            cnt++;
    return cnt;
}
/**************************************/
// josephus problem, iterative solution

int joseph(int n, int k) {
    int ans = 0, i;
    for(i = 2; i <= n; i++) ans = (ans + k) % i;
    return ans;
}
/**************************************/
// All Divisor Generate
lli divisors[10000];
int nk , e[78498+10];
lli p[78498+10];
int cnt;
int countdiv()
{
    int i , j, k , n;
    divisors[0] = 1;
    cnt = 1;
    for (int i = 0; i < nk; i++)
    {
        int n = cnt;
        for (int j = 0; j < e[i]; j++)
            for (int a = 0; a < n; a++) divisors[cnt++] = p[i] * divisors[a + j * n];
    }
    return cnt;
}

if(n!=1) p[nk] = n , e[nk] = 1  , nk++;
// p[] keeps the prime number , and e[] keeps it's power

/**************************************/
lli _floor(lli a, lli b)
{
    if(b < 0) a = -a, b = -b;
    if(a < 0) return -((-a+b-1)/b);
    else return a / b;
}
lli _ceil(lli a, lli b)
{
    if(b < 0) a = -a, b = -b;
    if(a < 0) return a / b;
    else return (a  +b - 1) / b;
}
int ModD(lli x)
{
    if(x<0) x+= ((-x/D)+1)*D;
    return x%D;
}
/**************************************/
int main(void)
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,k,kase=0;
    printf("%I64d\n",modpow(2,12,9));
    return 0;
}
