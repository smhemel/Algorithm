//
//  main.cpp
//  Breadth-first search
//
//  Created by S M HEMEL on 3/17/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector < int > v[1000];
bool visit[1000];
int dis[1000];
queue <int> q;
void bfs(int start)
{
    visit[start] = 1;
    dis[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int start = q.front();
        q.pop();
        for(auto i: v[start])
        {
            if(visit[i]) continue;
            visit[i] = 1;
            dis[i] = dis[start] + 1;
            q.push(i);
        }
    }
}
void view(int s,int N)
{
    cout << "Distance From " << s << " is: \n";
    for (int i=0; i<N; i++)
        cout << "Node :" << i+1 <<"-->" <<dis[i+1] <<endl;
}
int main()
{
    int n,m,start,last;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    //cin >> start >> last;
    cin >> start;
    bfs(start);
    view(start,n);
    //cout << dis[last] << endl;
    return 0;
}
