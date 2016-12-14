#include<bits/stdc++.h>
using namespace std;
#define MaxN 1000

vector<int> adj[MaxN];
vector<int> Radj[MaxN];
stack<int> topSort;
bool visit[MaxN];

void DFS(int x){
    visit[x]=true;
    int sz = adj[x].size();
    for(int i=0; i<sz; i++){
        if(visit[adj[x][i]]==false)DFS(adj[x][i]);
    }
    topSort.push(x);
}

void DFS2(int x){
    cout << x << " ";
    visit[x]=false;
    int sz = Radj[x].size();
    for(int i=0; i<sz; i++)
        if(visit[Radj[x][i]])DFS2(Radj[x][i]);

}


int main(){
    for(int i=0; i<MaxN; i++){
        adj[i].clear();
        Radj[i].clear();
    }
    int v, e;
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        Radj[b].push_back(a);
    }

    for(int i=1; i<=v; i++)
        if(visit[i]==false)DFS(i);

    while(!topSort.empty()){
        int n = topSort.top();
        topSort.pop();
        if(visit[n]==true){
            DFS2(n);
            cout << endl;
        }
    }

return 0;
}

