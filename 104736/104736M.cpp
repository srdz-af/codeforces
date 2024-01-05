#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = LLONG_MAX;
ll g;

void dijkstra(ll s, vector<vector<pair<ll, ll>>> & adj, vector<ll> & d, ll e) {
    ll n = adj.size();
    d.assign(n, INF);

    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v] || v == e)
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    
    ll n, m, p;
    cin >> n >> m >> p >> g;
    p--; g--;

    vector<vector<pair<ll, ll>>> adj(n);
    vector<ll> d1, d2;

    for(ll i = 0; i < m; i++){
        ll u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    dijkstra(p, adj, d1, LLONG_MIN);
    dijkstra(p, adj, d2, g);

    ll f = 0;
    for(ll i = 0; i < n; i++){
        if(d1[g]*2 == d1[i] && d1[i] < d2[i]){
            if(f) cout << " ";
            cout << i+1;
            f++;
        } 
    }

    if(!f) cout << "*";
    cout << "\n";
    return 0;
}