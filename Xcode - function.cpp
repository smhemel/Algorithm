//All Divisor
int printDivisors(int n)
{
    int ans = 0;
    vector<int> v;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            if (n/i == i)
                ans++;
            else
            {
                ans++;
                v.push_back(n/i);
            }
        }
    }
    for (int i=(int)v.size()-1; i>=0; i--)
        ans++;
    return ans;
}

//Big Integer Factorial
int fac[2000];
void big_factorial(int n){
    int temp = 0,m = 1,x;;
    fac[0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0;j<m;j++)
        {
            x = fac[j]*i+temp;
            fac[j]=x%10;
            temp = x/10;
        }
        while(temp>0)
        {
            fac[m]=temp%10;
            temp = temp/10;
            m++;
        }
    }
    for(int i=m-1;i>=0;i--)
        printf("%d",fac[i]);
}
//Big Number Mod
int bigmod(char s[] , int modulo)
{
    int ans = 0;
    for(int i=0; s[i]; i++)
        ans = (ans*10 + s[i]-'0') % modulo;
    return ans;
}
//How Many Divisors
int check[32000],prime[10000];
void sieve()
{
    for(int i=3; i<=180; i+=2)
        if(!check[i])
            for(int j=i*i; j<=32000; j+=i)
                check[j]=1;
    prime[0] = 2;
    for(int i=3,j=1;i<=32000;i+=2)
        if(!check[i])
            prime[j++]=i;
}
int how_may_divisor(int n){
    int total = 1,k=0;
    for(int j=prime[k]; j*j<=n; j=prime[++k]) {
        int cnt=0;
        while(n%j==0) {
            cnt++;
            n/=j;
        }
        total *=cnt+1;
    }
    if(total!=1)
        return total <<= 1;
    else
        return 1;
}
//kth Shortest Path
//sol_kpath(u, v, 2, node);
//adjacency list undirected graph
struct edge {
    int to, v;
    edge(int a, int b):
    to(a), v(b) {}
};
vector<edge> g[105];
#define oo 0xfffffff
void spfa(int st, int n, int dis[]) {
    int i, tn;
    int used[105] = {};
    queue<int> Q;
    for(i = 0; i < n; i++)
        dis[i] = oo;
    dis[st] = 0;
    Q.push(st);
    while(!Q.empty()) {
        tn = Q.front();
        Q.pop();
        used[tn] = 0;
        for(vector<edge>::iterator it = g[tn].begin();
            it != g[tn].end(); it++) {
            if(dis[it->to] > dis[tn] + it->v) {
                dis[it->to] = dis[tn] + it->v;
                if(used[it->to] == 0) {
                    used[it->to] = 1;
                    Q.push(it->to);
                }
            }
        }
    }
}
struct E {
    int node, g, h;
    E(int a, int b, int c):
    node(a), g(b), h(c) {}
    bool operator<(const E &a) const {
        return g + h > a.g + a.h;
    }
};
void sol_kpath(int st, int ed, int k, int node) {
    int H[105];
    int cntkpath[105], kpath[105];
    spfa(ed, node, H);
    for(int i=0; i<node; i++){
        cntkpath[i] = 0;
        kpath[i] = -1;
    }
    cntkpath[st] = 0;
    kpath[st] = -1;
    priority_queue<E, vector<E> > pQ;
    E tn(0,0,0);
    pQ.push(E(st,0,H[st]));
    while(!pQ.empty()) {
        tn = pQ.top();
        pQ.pop();
        //printf("%d %d %d\n", tn.node, tn.g, tn.h);
        if(cntkpath[tn.node] >= k ||
           kpath[tn.node] == tn.g+tn.h)
            continue;
        cntkpath[tn.node]++;
        kpath[tn.node] = tn.g+tn.h;
        if(tn.node == ed && cntkpath[tn  .node] == k) {
            printf("%d\n", tn.g);
            return;
        }
        for(auto it : g[tn.node]) {
            pQ.push(E(it.to, tn.g + it.v, H[it.to]));
        }
    }
}
//Milar Primality test
//call by miller_rabin(n,18)
typedef unsigned long long ll;
ll mulmod(ll a, ll b, ll c){
    ll x = 0,y = a%c;
    while(b>0){
        if(b&1)
            x = (x+y)%c;
        y = (y<<1)%c;
        b >>= 1;
    }
    return x;
}

ll pow(ll a, ll b, ll c){
    ll x = 1, y = a;
    
    while(b>0){
        if(b&1) x = mulmod(x,y,c);
        y = mulmod(y,y,c);
        b >>= 1;
    }
    return x;
}

bool miller_rabin(ll p, int it)
{
    if(p<2 || !(p&1)) return false;
    if(p==2) return true;
    
    ll s = p-1;
    while(s%2==0)
        s >>= 1;
    
    while(it--){
        ll a = rand()%(p-1)+1,temp = s;
        ll mod = pow(a,temp,p);
        if(mod==-1 || mod==1)
            continue;
        while(temp!=p-1 && mod!=p-1){
            mod = mulmod(mod,mod,p);
            temp <<= 1;
        }
        if(mod!=p-1)
            return false;
    }
    return true;
}
//Mod Power
#define ll long long int
ll modpow(ll base, ll power, ll mod)
{
    ll ans=1;
    while(power>0)
    {
        if(power&1)
            ans = (ans*base)%mod;
        power >>= 1;
        base=(base*base)%mod;
    }
    return ans;
}
//nCr
int nCr(int n,int r)
{
    if(n<(r<<1)) r = n-r;
    int ans = 1;
    for(int i=0; i<r; ans *= (n-i),ans /= (i+1),i++);
    return ans;
}
//Pair Sort
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first<b.first;
}
//Sieve Function
#define isp(x)   ((x==2) || (x>1 && (x&1) && !chekb(x)))
#define check(x) (flag[x>>6] & (1<<((x>>1) & 31)))
#define sign(x)  (flag[x>>6] |=(1<<((x>>1) & 31)))
const int M = 10000000;
int flag[(M>>6)+10];
int prime[700000];
int c = 0;
void sieve(void)
{
    const int root = sqrt(M)+1;
    int i,j,k;
    sign(0);
    prime[c++]=2;
    for(i=3; i<=root; i+=2)
        if(!check(i))
            for(prime[c++]=i ,j=i*i ,k=(i<<1); j<=M; j+=k)
                sign(j);
    for( ; i<=M; i+=2)
        if(!check(i))
            prime[c++]=i;
}
//String Division
string str_division(string s, ll n)
{
    bool flag = true,check = false;
    ll sum = 0, t;
    string ans;
    for(ll i=0; s[i]; i++)
    {
        sum = sum*10 + (s[i]-'0');
        t = sum / n;
        if(!t && !flag)
            continue;
        else
        {
            if(t!=0 || check){
                check = true;
                ans += (t + '0');
            }
            flag = 1;
            sum = (sum % n);
        }
    }
    if(!flag) ans = "0";
    return ans;
}
//String Multiplication
string stradd(string s1, string s2)
{
    string a;
    if(s2.size() < s1.size())
        swap(s1, s2);
    int s=0, c=0;
    int l=(int)s1.size();
    int ll = (int)s2.size();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    for(int i=l; i<ll; i++)
        s1 += "0";
    for(int i=0; i<ll; i++) {
        s = (s1[i]-'0') + (s2[i] - '0')+c;
        c = s / 10;
        a += (s % 10) + '0';
    }
    if(c > 0)
        a += c % 10 + '0';
    
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(a.begin(), a.end());
    return a;
}

string strmul(string s1, string s2)
{
    string m, a;
    int l, ll, j, c, s=0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    if(s1.size() > s2.size())
        swap(s1, s2);
    
    l = (int)s1.size();
    ll = (int)s2.size();
    
    j=0;
    m = "", a = "";
    for(int i=0; i<ll; i++) {
        c = 0;
        m = "";
        for(int j=0; j<l; j++) {
            s = (s1[j]-'0') * (s2[i] - '0') + c;
            c = s / 10;
            m += (s % 10) + '0';
        }
        if(c > 0)
            m += c % 10 + '0';
        reverse(m.begin(), m.end());
        
        for(int k=j; k<j+i; k++)
            m += "0";
        reverse(m.begin(), m.end());
        if(i==0)
            a=m;
        if(i != 0) {
            c = 0;
            reverse(a.begin(), a.end());
            reverse(m.begin(), m.end());
            a = stradd(a, m);
            reverse(a.begin(), a.end());
        }
    }
    
    bool flag = true;
    for(int i=0; i<a.size(); i++) {
        if(a[i] != '0') {
            flag = false;
            break;
        }
    }
    if(flag)
        a = "0";
    
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(a.begin(), a.end());
    return a;
}
//String Summation
string str_summation(string s1, string s2)
{
    string ans;
    if(s2.size()<s1.size())
        swap(s1, s2);
    int len = (int)s1.size();
    int len1 = (int)s2.size();
    int s = 0,c = 0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    for(int j=len; j<len1; j++)
        s1 += "0";
    for(int j=0; j<len1; j++) {
        s = (s1[j]-'0') + (s2[j]-'0')+c;
        c = s / 10;
        ans += (s % 10) + '0';
    }
    if(c>0)
        ans += c%10+'0';
    reverse(ans.begin(), ans.end());
    return ans;
}
