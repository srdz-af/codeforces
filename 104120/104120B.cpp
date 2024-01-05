#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

ll n, m;
ll mat[105][105];
ll mov[4] = {0, 0, 1, -1};
set<ll> used;
bool vis[105][105];
ll rh, ch, rw, cw;

bool check(ll x, ll y){
    return (x >= 0 && x < n && y >= 0 && y < m); 
}


ll dfs(ll x, ll y){
    if(x == rh && y == ch) return 0;
    ll nmin = 444;
    used.insert(mat[x][y]);
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        ll nextx, nexty;
		nextx = x + mov[i];
		nexty = y + mov[3-i];
        if(check(nextx, nexty) && !vis[nextx][nexty])
            nmin = min(dfs(nextx, nexty)+(mat[x][y] != mat[nextx][nexty] || !used.count(mat[nextx][nexty])), nmin);
    }
    return nmin;    
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

    cin >> n >> m >> rh >> ch >> rw >> cw;
    rh--; ch--; rw--; cw--;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    cout << dfs(rw, cw) << "\n";

    return 0;
}