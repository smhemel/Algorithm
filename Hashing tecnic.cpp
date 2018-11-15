#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
map<string, int>mp;
int main()
{
    char ch[100][100];
    int n, j, i;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>ch[i];
        if(mp[ch[i]]==0)
            j++;
        mp[ch[i]]++;
    }
    for(i=0; i<j; i++){
        cout<<ch[i]<<" = "<<mp[ch[i]]<<endl;
    }
    return 0;
}
