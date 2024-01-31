#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long

int main(){

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    bool st[3] = {true, false, false};
    vector<pair<ll, ll>> swaps;
    vector<ll> guesses;
    ll nmax = -1;

    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll a, b, g;
        cin >> a >> b >> g;
        swaps.push_back({a-1, b-1});
        guesses.push_back(g-1);
    }

    for(int i = 0; i < 3; i++){
        bool stb[3];
        copy(st, st+3, stb);
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            swap(stb[swaps[i].F], stb[swaps[i].S]);
            if(stb[guesses[i]]) cnt++;
        }
        nmax = max(nmax, cnt);
        next_permutation(st, st+3);
    }
    cout << nmax << "\n";
    return 0;
}