//
//  main.cpp
//  Dijkstra’s algorithm
//
//  Created by S M HEMEL on 3/25/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
#define M 100001
#define INF (1<<20)
struct comp {
    bool operator() (const pair< int, int > &a, const pair< int, int > &b) {
        return a.second > b.second;
    }
};
int dis[M];
bool check[M];
vector< pair < int, int > > G[M];
priority_queue< pair< int, int >, vector< pair< int, int > >, comp > Q;
int main()
{
    int u, v, w,node, edge, start;
    scanf("%d %d", &node, &edge);
    for(int i=0; i<edge; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back(make_pair(v, w));
        //G[v].push_bcak(make_pair(u,w));
    }
    scanf("%d", &start);
    for(int i=1; i<=node; dis[i] = INF,i++);
    dis[start] = 0;
    Q.push(make_pair(start, 0));
    while(!Q.empty())
    {
        u = Q.top().first;
        Q.pop();
        if(check[u])
            continue;
        for(auto i: G[u])
        {
            v = i.first;
            w = i.second;
            if(!check[v] && dis[u]+w<dis[v])
            {
                dis[v] = dis[u] + w;
                Q.push(make_pair(v, dis[v]));
            }
        }
        check[u] = 1;
    }
    for(int i=1; i<=node; i++)
        printf("Node %d, min weight = %d\n", i, dis[i]);
    return 0;
}
