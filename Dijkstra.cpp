#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
#define Infinity 9999999

struct node{
    int pos, key;
    node(int poS, int keY){
        pos = poS;
        key = keY;
    }

    bool operator <(const struct node a) const{
        return a.key < key;
    }
};

vector<int> adj[MAXN];
priority_queue<node> Q;
int color[MAXN];
int cost[MAXN][MAXN];
int d[MAXN];


void Relax(int u, int v, int w){
    if(d[v]>d[u]+w){
        d[v] = d[u]+w;
        Q.push(node(v, d[v]));
    }
}


void Dijkstra(int s){
    while(!Q.empty()){
        node n = Q.top();
        Q.pop();
        int u = n.pos;
        if(color[u]==1)continue;
        color[u]=1;
        cout << u << " " << d[u] << endl;

        int sz = adj[u].size();
        for(int i=0; i<sz; i++){
            int v = adj[u][i];
            Relax(u, v, cost[u][v]);
        }

    }

}

int main(){

    int n, m;
    cin >> n;
    cin >> m;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        cin >> cost[u][v];
        adj[u].push_back(v);
    }

    cout << "source : " << endl;
    int s; cin >> s;
    for(int i=0; i<n; i++){
        if(i==s){
            Q.push(node(i, 0));
        }else{
            Q.push(node(i, Infinity));
        }

        d[i]=Infinity;
        color[i]=0;
        d[s]=0;
    }


    Dijkstra(s);

}
