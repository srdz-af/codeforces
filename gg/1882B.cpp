#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef unordered_map<ll, ll, custom_hash> safemap;
typedef gp_hash_table<ll, ll, custom_hash> safehash;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordset; 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> multiset; 



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n; 
        cin >> n;
        ll ans = 0;
        set<ll> unn;
        vector<set<ll>> sts(n);
        rep(i, 0, n){
            ll a; cin >> a;
            rep(j, 0, a){
                ll e; cin >> e;
                sts[i].insert(e);
                unn.insert(e);
            }
        }
        for(auto it: unn){
            set<ll> aux;
            rep(j, 0, n) if(!sts[j].count(it)) aux.insert(all(sts[j]));
            ans = max(ans, (ll)aux.size());
        }
        cout << ans << "\n";
    }
    return 0;
}