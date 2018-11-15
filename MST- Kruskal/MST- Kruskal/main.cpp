//
//  main.cpp
//  MST- Kruskal
//
//  Created by S M HEMEL on 20/1/18.
//  Copyright © 2018 Eastern University. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long int
#define MAX 1000
using namespace std;
int parent[MAX],value[MAX];
struct data{
    int u,v,w;
};
bool operator < (data l, data r){
    return l.w < r.w;
}
vector<data>mstVector;
void inatialized(int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        value[i] = 0;
    }
}
int findparent(int x){
    if(x==parent[x]) return x;
    return findparent(parent[x]);
}
void disjoint_Union(int x,int y){
    int Xp = findparent(x);
    int Yp = findparent(y);
    if(Xp==Yp) return;
    else if(value[Xp]<value[Yp]) parent[Xp] = Yp;
    else if(value[Xp]>value[Yp]) parent[Yp] = Xp;
    else{
        parent[Yp] = Xp;
        value[Xp]++;
    }
}
int Kruskal(int n){
    inatialized(n);
    sort(mstVector.begin(),mstVector.end());
    int ans = 0;
    for(auto cut: mstVector){
        if(findparent(cut.u)!=findparent(cut.v)){
            disjoint_Union(parent[cut.u],parent[cut.v]);
            ans += cut.w;
        }
    }
    return ans;
}
int main(){
    int node, edge;
    cin >> node >> edge;
    for(int i=0; i<edge; i++){
        data x;
        cin >> x.u >> x.v >> x.w;
        mstVector.push_back(x);
    }
    cout << "Minimum spanning tree cost is: "<< Kruskal(node) << endl;
    return 0;
}
