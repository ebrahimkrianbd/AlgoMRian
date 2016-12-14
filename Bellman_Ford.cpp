#include<bits/stdc++.h>
#include<vector>
#define Infinity 999999
using namespace std;

class node{
public:
    int u, v, w;
    node(){
        u = 0;
        v = 0;
        w = 0;
    }
    node(int au, int av, int aw){
        u = au;
        v= av;
        w= aw;
    }
};
vector <node> edge;
int dist[100];

void Relax(int u, int v, int w){
    if(dist[v]>dist[u]+w)
        dist[v] = dist[u]+w;
}

bool Bellman_Ford(int n, int s){

    for(int i=0; i<=n; i++)
        dist[i]=Infinity;
    dist[s] = 0;
    int e = edge.size();
    for(int i=0; i<n; i++)
        for(int j=0; j<e; j++){
            node obj = edge[j];
            Relax(obj.u, obj.v, obj.w);
        }
    for(int i=0; i<e; i++){
        node obj = edge[i];
        if(dist[obj.v] > dist[obj.u]+obj.w)return false;
    }


return true;
}


int main(){

    int n, m;
    cout << "How many vertex?" << endl;
    cin >> n;
    cout << "How many edge?" << endl;
    cin >> m;
    cout << "Enter the values:" << endl;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        node obj(u, v, w);
        edge.push_back(obj);
    }

    int s;
    cout << "Enter the source : " << endl;
    cin >> s;

    bool dec = Bellman_Ford(n, s);

    if(dec==false)cout << "Negative cycle present!" << endl;
    else {
        for(int i=1; i<=n; i++){
            cout << s << " " << i << " " << dist[i] << endl;
        }
    }

return 0;
}
