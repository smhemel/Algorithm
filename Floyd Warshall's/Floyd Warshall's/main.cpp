//
//  main.cpp
//  Floyd Warshall's
//
//  Created by S M HEMEL on 3/2/18.
//  Copyright © 2018 Eastern University. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 1000000110
#define N 400
using namespace std;
int matrix[N][N],parent[N][N];
void pathfind(int src,int des){
    if(src==des){
        cout << "Path: " << src;
        return;
    }
    pathfind(src, parent[src][des]);
    cout << " " << des;
}
int main(){
    int node,x,y,w;
    cin >> node;
    for(int i=1; i<=node; i++)
        for(int j=1; j<=node; j++){
            if(i==j) matrix[i][j] = 0;
            else matrix[i][j] = inf;
            parent[i][j] = i;
        }
    for(int i=1; i<=node; i++){
        cin >> x >> y >> w;
        matrix[x][y] = w;
    }
    for(int i=1; i<=node; i++)
        for(int j=1; j<=node; j++)
            for(int k=1; k<=node; k++)
                if(matrix[i][j]>(matrix[i][k]+matrix[k][j])){
                    matrix[i][j] = matrix[i][k]+matrix[k][j];
                    parent[i][j] = parent[i][k];
                }
    int source,des;
    cin >> source >> des;
    cout << matrix[source][des] << endl;
    pathfind(source,des);
    return 0;
}
