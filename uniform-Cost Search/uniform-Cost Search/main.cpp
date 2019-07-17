'//
//  main.cpp
//  uniform-Cost Search
//
//  Created by S M HEMEL on 2/7/19.
//  Copyright © 2019 S M HEMEL. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
vector<pi> graph[211];
int node,edge,x,y,w,destination;
int cost[9999];

void uniform_cost_search(int start)
{
    priority_queue<pi, vector<pi>, greater<pi> > q;
    q.push(make_pair(0,start));
    cost[start] = 0;
    
    while(!q.empty()) {
        int str = q.top().second;
        int cos = q.top().first;
        q.pop();
        
        for(int i=0; i<graph[str].size(); i++){
            if(cost[graph[str][i].first]>cos+graph[str][i].second){
                cost[graph[str][i].first] = cos+graph[str][i].second;
                q.push(make_pair(cos+graph[str][i].second,graph[str][i].first));
                if(graph[str][i].first == destination) break;
            }
        }
    }
    
}

int main()
{
    cin >> node >> edge;
    for(int i=0; i<edge; i++){
        cin >> x >> y >> w;
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }
    for(int i=0; i<9999; i++) cost[i] = 9999999;
    
    cin >> destination;
    uniform_cost_search(1);
    cout << cost[destination] << endl;
    
    return 0;
}
