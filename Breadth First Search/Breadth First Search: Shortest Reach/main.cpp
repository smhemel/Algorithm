//
//  main.cpp
//  Breadth First Search: Shortest Reach
//
//  Created by S M HEMEL on 4/8/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
vector <int> v[1011];
bool visit[1011];
int dis[1011];
void dfs(int start)
{
    queue <int> q;
    visit[start] = 1;
    dis[start] = 0;
    q.push(start);
    while(!q.empty())
    {
        int start = q.front();
        q.pop();
        for(auto i : v[start])
        {
            if(visit[i])
                continue;
            visit[i] = 1;
            dis[i] = dis[start] + 1;
            q.push(i);
        }
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n,e,start;
        cin >> n >> e;
        for(int i=0; i<e; i++)
        {
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cin >> start;
        dfs(start);
        for(int i=1; i<=n; i++)
        {
            if(i==start)
                continue;
            if(dis[i]==0)
                cout << "-1 ";
            else
                printf("%d ",dis[i]*6);
        }
        cout << endl;
        memset(visit,NULL,sizeof(visit));
        memset(dis,NULL,sizeof(dis));
        memset(v,NULL,sizeof(v));
    }
    return 0;
}
