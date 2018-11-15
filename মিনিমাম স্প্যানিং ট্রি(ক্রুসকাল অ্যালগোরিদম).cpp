//
//  main.cpp
//  মিনিমাম স্প্যানিং ট্রি(ক্রুসকাল অ্যালগোরিদম)
//
//  Created by S M HEMEL on 23/7/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
vector<pair <int,pair <int, int> > > edges;
int father[10000];
int find(int x){
    if(father[x]==x) return x;
    return find(father[x]);
}
void unite(int x, int y){
    int fx = find(x);
    int fy = find(y);
    father[fx] = fy;
}
int MTS(int n,int m){
    int mst_weight = 0, mst_edges = 0;
    int mst_ni = 0;
    while(mst_edges<n-1 || mst_ni<m)
    {
        int v = edges[mst_ni].second.first;
        int u = edges[mst_ni].second.second;
        int w = edges[mst_ni].first;
        if(find(v) != find(u)){
            unite(v,u);
            mst_weight += w;
            cout << u << " " << w << endl;
            mst_edges++;
        }
        mst_ni++;
    }
    return mst_weight;
}
int main()
{
    for(int i=0; i<100; i++)
        father[i] = i;
    int node,edge,v,u,w;
    cin >> node >> edge;
    for(int i=0; i<edge; i++){
        scanf("%d%d%d", &v,&u,&w);
        edges.push_back(make_pair(w, make_pair(v,u)));
    }
    sort(edges.begin(),edges.end());
    for(int i=0; i<9; i++){
        cout << edges[i].first << " "<<edges[i].second.first << " " << edges[i].second.second << endl;
    }
    cout << "Weight of the MST is: " << MTS(node,edge) << endl;
    return 0;
}
