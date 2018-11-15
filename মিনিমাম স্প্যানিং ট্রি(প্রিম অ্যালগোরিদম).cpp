//
//  main.cpp
//  মিনিমাম স্প্যানিং ট্রি(প্রিম অ্যালগোরিদম)
//
//  Created by S M HEMEL on 22/7/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <list>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> iPair;
vector < pair<int,int> > v_pair[10000];
priority_queue<iPair,vector<iPair>,greater<iPair> > pq;
int node,v,u,w,edge;
void primMST(){
    int src = 0;
    vector<int> key(node,INF);
    vector<int> parent(node,-1);
    vector<bool> inMST(node,false);
    pq.push(make_pair(0,src));
    key[src] = 0;
    
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        
        inMST[u] = true;
        for(auto x: v_pair[u]){
            int v = x.first;
            int weight = x.second;
            
            if(!inMST[v] && key[v] > weight){
                key[v] = weight;
                pq.push(make_pair(key[v],v));
                parent[v] = u;
            }
        }
    }
    for(int i=1; i<node; i++){
        cout << parent[i] << " - "  << i << endl;
    }
}
int main(){
    cin >> node >> edge;
    for(int i=0; i<edge; i++){
        cin >> v >> u >> w;
        u--,v--;
        v_pair[v].push_back(make_pair(u,w));
        v_pair[u].push_back(make_pair(v,w));
    }
    primMST();
    return 0;
}
