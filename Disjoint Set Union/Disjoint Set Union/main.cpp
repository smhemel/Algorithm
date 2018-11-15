//
//  main.cpp
//  Disjoint Set Union
//
//  Created by S M HEMEL on 19/1/18.
//  Copyright © 2018 Eastern University. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#define N 100000
using namespace std;
int parent[N],ranknode[N];
void initializedSet(int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        ranknode[i] = 0;
    }
}
int findroot(int x){
    if(x != parent[x])
        findroot(parent[x]);
    else return x;
}
void UnionSet(int x,int y){
    int Xroot = findroot(x);
    int Yroot = findroot(y);
    if(Xroot==Yroot) return;
    if(ranknode[Yroot]<ranknode[Xroot]) parent[Yroot] = Xroot;
    else if(ranknode[Yroot]>ranknode[Xroot]) parent[Xroot] = Yroot;
    else{
        parent[Yroot] = Xroot;
        ranknode[Xroot]++;
    }
}
int main(){
    int n;
    cin >> n;
    initializedSet(n);
    UnionSet(0,1);
    UnionSet(4,2);
    UnionSet(3,1);
    UnionSet(0,3);
    //UnionSet(0,4);
    for(int i=0; i<n; i++)
        cout << i << " parent is: " << parent[i] << " And Rank is: " << ranknode[i] << endl;
    return 0;
}
