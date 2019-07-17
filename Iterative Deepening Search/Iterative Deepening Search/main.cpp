////
////  main.cpp
////  Iterative Deepening Search
////
////  Created by S M HEMEL on 16/7/19.
////  Copyright © 2019 S M HEMEL. All rights reserved.
////
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//#define SIZE 10001
//int Graph[SIZE][SIZE];
//int nodes,edges,depth=0,solution,child,goal;
//
//int DLS(int node,int depth)
//{
//    if(depth>=0) {
//        if(node==goal) return goal;
//
//        for(int i=0; i<nodes; i++) {
//            if(Graph[node][i] == 1) {
//                int x = DLS(i, depth-1);
//                if(x == goal) return goal;
//            }
//        }
//    }
//    return 0;
//}
//
//
//bool solve(int root)
//{
//    solution = 0;
//    while(solution <= 0 && depth<nodes) {
//        solution = DLS(root,depth);
//        depth++;
//    }
//    if(depth  == nodes+1) return false;
//    return true;
//}
//
//
//int main()
//{
//    int u,v,source;
//
//    cin >> nodes >> edges;
//    for(int i=0; i<edges; i++) {
//        cin >> u >> v;
//        Graph[u][v] = 1;
//    }
//    puts("Enter Your Source and goal state: ");
//    scanf("%d %d",&source,&goal);
//
//    if(solve(source))
//        printf("Solution Found in depth limit (%d).\n",--depth);
//    else
//        printf("No solution Exist\n");
//    return 0;
//}


#include <iostream>
#include <algorithm>
using namespace std;
int node,edge,x,y,depth,destination,source;
int Graph[111][111];

int visited[111];
int dist[111];

void dfs(int root, int depth) {
    if(depth<0 || root==destination) return;
    visited[root] = 1;
    for(int j=0; j<8; j++){
        if(Graph[root][j]==1 && visited[j]==0) {
            dist[j] = dist[root]+1;
            dfs(j, depth);
        }
    }
}

int main()
{
    scanf("%d%d",&node,&edge);
    
    for(int i=0; i<edge; i++){
        scanf("%d%d",&x,&y);
        Graph[x][y] = 1;
    }
    
    cin >> source >> destination;
    for(int i=0; i<node; i++){
        dfs(source, i);
    }
    cout << dist[destination] << endl;
    return 0;
}
