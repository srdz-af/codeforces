#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    
    ll t;
    cin >> t;
    while(t--){
        map<ll, vector<ll>> pos;
        ll n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            ll a;
            cin >> a;
            pos[a].push_back(i);
        }

        for(int i = 0; i < k; i++){
            ll a, b;
            cin >> a >> b;
            if(pos.count(a) && pos.count(b) && (pos[b][pos[b].size()-1] > pos[a][0])){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}

