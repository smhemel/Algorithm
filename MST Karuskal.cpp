#include <bits/stdc++.h>
using namespace std;
struct Graph{
    int x, y, w;
    bool operator <(const Graph& p)const{return w<p.w;}
}get;
int check[100];
vector<Graph>V;
vector<Graph>ST;
int Find(int r){
    return (check[r]==r) ? r : Find(check[r]);
}
int MST(int node) {

    int i, len, coun=0, sum=0, x, y, wate;

    sort(V.begin(), V.end());
    for(i=0; i<=node;  check[i]=i, i++);

    for(i=0, len=V.size(); i<len; i++) {
        x = Find(V[i].x);
        //printf("V= %d Find %d\t", V[i].x, x);
        y = Find(V[i].y);
        //printf("V= %d Find %d\n", V[i].y, y);
        if(x!=y){
            wate = V[i].w;
            check[x]=y;
            coun++;
            sum+=wate;

            get.x = V[i].x, get.y = V[i].y, get.w = wate;
            ST.push_back(get);

            if(coun==node) break;
        }
    }
    return sum;
}
int main(){
    int x, y, w, edge, node;
    cin>>node>>edge;
    while(edge--){
        scanf("%d%d%d", &x, &y, &w);
        get.x = x;
        get.y = y;
        get.w = w;
        V.push_back(get);
    }
    cout<<MST(node)<<endl;

    for(int i=0, len=ST.size(); i<len; i++){
        printf("%d to %d wate is %d\n", ST[i].x, ST[i].y, ST[i].w);
    }
    return 0;
}
/**
7 11
1 2 7
1 4 5
2 3 8
2 4 9
2 5 7
3 5 5
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11
*/
