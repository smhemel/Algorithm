//
//  main.cpp
//  Depth-first Search
//
//  Created by S M HEMEL on 3/16/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//


#include<iostream>
#include <vector>
using namespace std;
const int MX= 100;
vector <int> g[MX+10];
bool vis[MX+10];
void dfs(int i) {
    printf("In %d\n",i);
    vis[i]=1;
    int len = (int) g[i].size();
    for (int l=0;l<len;++l) {
        if(vis[g[i][l]])
            continue;
        printf("Going %d to %d\n",i,g[i][l]);
        dfs(g[i][l]);
    }
    printf("Out from %d\n",i);
}

int main() {
    //freopen("graph.txt","r",stdin);
    int node,edge;
    scanf("%d%d",&node,&edge);
    while(edge--) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=node;++i)
        if (!vis[i])
            dfs(i);
    return 0;
}


