#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> sl; 

void dijkstra(ll s, vector<vector<pair<ll, ll>>> & adj, vector<ll> & d) {
    ll n = adj.size();
    d.assign(n, LLONG_MAX);
    ll sf = sl[s];
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;
            sf = min(sf, sl[v]);
            if (d[v] + len*sf < d[to]k) {
                d[to] = d[v] + len*sf;
                q.push({d[to], to});
            }
        }
    }
}

void dijkstra_de_caja(ll s, vector<vector<pair<ll, ll>>> & adj, vector<ll> & d) {
    ll n = adj.size();
    d.assign(n, LLONG_MAX);
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) continue;

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

vector<vector<ll>> mp;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<vector<pair<ll, ll>>> cmp(n);
        vector<vector<pair<ll, ll>>> adj(n);
        vector<ll> ans;

        for(int i = 0; i < m; i++){
            ll u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        for(int i = 0; i < n; i++){
            ll s;
            cin >> s;
            sl.push_back(s);
        }

        for(int i = 0; i < n; i++){
            vector<ll> d;
            dijkstra(i, adj, d);
            for(int j = 0; j < n; j++){
                cmp[i].push_back({j, d[j]});
                cmp[j].push_back({i, d[j]});
            }
        }

        dijkstra_de_caja(0, cmp, ans);
        cout << ans[n-1] << "\n";
    }
    return 0;
}