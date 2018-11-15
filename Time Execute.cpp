#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
using namespace std;
template <typename T>
void read(T &x)
{
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-'){
        c = getchar();
        t = true;
    } x = c-'0';
    for(c=getchar(); c>='0'&&c<='9'; c=getchar())
        x=x*10+c-'0';
    if(t) x=-x;
}

std::clock_t __start;
double __duration;
void start_timer() { __start = std::clock(); }
void print_timer() {
    __duration = (std::clock() - __start) / (double)CLOCKS_PER_SEC;
    std::cout << "Duration: " << __duration << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    __start = clock();
    
    
    printf("Duration: %d\n",((clock()-__start)/(double)CLOCKS_PER_SEC));
    return 0;
}



typedef long long ll;

const int MAX = 2e5+6;
const int INF = 1e9+5;
const long long MOD = 1e9+7;
const long double EPS = 1e-6;

long long power (long long a,long long e,long long mod)
{
    if (e == 0)
        return 1ll;
    if (e == 1)
        return a % mod;
    if (e & 1)
        return ((a%mod) * power(a,e-1,mod))%mod;
    else
    {
        long long tmp = power(a,e/2,mod);
        return (tmp*tmp)%mod;
    }
}

long long lcm(long long x,long long y)
{
    return (x*y)/__gcd(x,y);
}

bool prime(long long int x)
{
    if(x<2 && !(x%2))
        return false;
    for(int i=2; i*i <= x; i++)
        if ((x%i) == 0)
            return false;
    return true;
}

