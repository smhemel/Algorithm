#include <bits/stdc++.h>
#define p(x) cout<<x<<endl;
using namespace std;
typedef long long i64;
i64 Hash(string s, int m, i64 B, i64 M)
{
    i64 h = 0 , power = 1;
    for(int i=m-1; i>=0; i--){
        h = h + (s[i]*power) % M;
        h = h % M;
        power = (power*B) % M;
    }
    return h;
}
int match(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    if(n<m || m==0 || n==0)return -1;
    i64 B=347, M=1000000000+7;
    //Calculate B^(m-1)
    i64 power = 1;
    for(int i=1; i<=m-1; i++)
        power=(power*B)%M;
    i64 hash_text = Hash(text, m, B, M);
    i64 hash_pattern = Hash(pattern, m, B, M);

    p(hash_text);
    p(hash_pattern);
    if(hash_text == hash_pattern) return 0;
    for(int i=m;i<n;i++){
        hash_text = (hash_text-(power*text[i-m]) % M) % M;
        hash_text = (hash_text+M) % M; //take care of M of negative value
        hash_text = (hash_text*B) % M;
        hash_text = (hash_text+text[i]) % M;
        if(hash_text==hash_pattern){
            return i - m + 1; //returns the index of the match
             //We should've checked the substrings character by character here as hash collision might happen
        }
    }
    return -1;
}
int main() {
    cout<<match("NayanBiswas", "as")<<endl;
    return 0;
}
