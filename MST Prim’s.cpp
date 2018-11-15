#include <bits/stdc++.h>
#define p(n) cout<<n<<endl;
#define NEW cout<<endl;
#define MAX 9999
using namespace std;
int graph[100][100], parent[100], Node;
bool visit[100];
void primMST()
{
    int i, u, J, k, Min, key[Node+5];
    for(i=0; i<=Node; i++) key[i]=99999;
    key[0]=key[1]=0;
    parent[0]=parent[1]=-1;
    for(i=1; i<Node; i++){
        for(k=1, Min=MAX; k<=Node; k++)
            if(visit[k]==false && key[k]<Min)
                Min=key[i], u=k;

        visit[u] = true;
        for(J=1; J<=Node; J++)
            if(graph[u][J]>0 && visit[J]==false && graph[u][J]<key[J])
                parent[J]=u, key[J]=graph[u][J];
    }
}
int main()
{
    freopen("graph.txt", "r", stdin);
    int x, y, wate, edge, i, J;
    cin>>Node>>edge;
    while(edge--){
        cin>>x>>y>>wate;
        graph[x][y]=wate;
        graph[y][x]=wate;
    }
    primMST();
    printf("Edge   Weight\n");
    for(int i=2; i<=Node; i++)
        printf("%d - %d    %d \n", i, parent[i], graph[i][parent[i]]);
    return 0;
}
