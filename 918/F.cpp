#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;


typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> superset; 

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, ans = 0;
        cin >> n;
        vector<pair<ll, bool>> ev;
        map<ll, ll> ends;
        superset opc;
        for(int i = 0; i < n; i++){
            ll a, b;
            cin >> a >> b;
            ev.push_back({a, true});
            ev.push_back({b, false});
            ends[b] = a;
        }

        sort(ev.begin(), ev.end());


        for(int i = 0; i < ev.size(); i++){
            if(ev[i].s) opc.insert(ev[i].f);
            else {
                ans += opc.order_of_key(ends[ev[i].f]);
                opc.erase(ends[ev[i].f]);
            }
        }
        cout << ans << "\n";

    }
    return 0;
}