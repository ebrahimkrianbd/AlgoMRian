#include<bits/stdc++.h>
using namespace std;
#define MaxN 1000

vector<int> adj[MaxN];
stack<int> output;
bool visit[MaxN];

void DFS(int x){
    visit[x] = true;
    int sz = adj[x].size();
    for(int i=0; i<sz; i++)
        if(visit[adj[x][i]]==false)DFS(adj[x][i]);
    output.push(x);
}


int main(){

    for(int i=0; i<MaxN; i++)adj[i].clear();
    int v, e;
    cout << "How many vertex?" << endl;
    cin >> v;
    cout << "How many edge?" << endl;
    cin >> e;
    cout << "Enter the values:" << endl;
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1; i<=v; i++)
        if(visit[i]==false)DFS(i);

    while(!output.empty()){
        cout << output.top() << " " ;
        output.pop();
    }


return 0;
}
