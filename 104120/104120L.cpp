#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, x;
ll cnt = 0;

void bfs(ll v, vector<vector<ll>> &adj, vector<ll> &vis,vector<ll> &dist){
    queue<ll> trav;
    dist[v] = 0;
    trav.push(v);
    while(!trav.empty()){
        ll curr = trav.front();
        trav.pop();
        cnt++;
        vector<ll> to = {};
        for(auto u: adj[curr]){
            if(!vis[u]){
                dist[u] = dist[curr]+1;
                if(u == x){
                    to.clear();
                    break;
                }
                to.push_back(u);
            }
        }
        for(auto it: to) trav.push(it);
        vis[curr] = true;
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    cin >> n >> x;
    x--;
    vector<vector<ll>> adj(n);
    vector<ll> vis(n, 0);
    vector<ll> dist(n, -1);

    for(int i = 0; i < n-1; i++){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
    bfs(0, adj, vis, dist);

    cout << 2*cnt - dist[x] << "\n";
    return 0;
}