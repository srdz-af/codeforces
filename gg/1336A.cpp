#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ans = 0;

struct City{
    bool vis = false;
    ll depth = 0, desc = 0, val = 0; 
    vector<ll> adj;
} road[200005];

bool cmp(struct City c1, struct City c2){
    return c1.val < c2.val;
}

ll dfs(ll n, ll depth){
    road[n].vis = true;
    road[n].depth = depth;
    for(auto it: road[n].adj){
        if(!road[it].vis){
            road[n].desc += dfs(it, depth+1);
        }
    }
    road[n].val = road[n].depth - road[n].desc; 
    return road[n].desc+1;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    ll n, k;
    cin >> n >> k;

    for(ll i = 0; i < n-1; i++){
        ll u, v;
        cin >> u >> v;
        road[u-1].adj.push_back(v-1);
        road[v-1].adj.push_back(u-1);
    }
    
    dfs(0, 0);
    sort(road, road+n, cmp);

    for(ll i = 0; i < n-k; i++){
        ans += (road[i].val);
    }

    cout << -ans << "\n";
}