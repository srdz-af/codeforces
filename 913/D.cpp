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
        vector<pair<ll, ll>> seg;

        rep(i, 0, n){
            ll l, r;
            cin >> l >> r;
            seg.push_back({l, r});
        }

        ll l = -1, r = 1e9, mid;

        while(r-l > 1){
            bool f = true;
            mid = (l+r)/2;

            ll lf = 0, rg = 0;
            for(int i = 0; i < n; i++){
                lf = max(lf - mid, seg[i].F);
                rg = min(rg + mid, seg[i].S);
                if(lf > rg){
                    f = false;
                    break;
                }
            }

            if(f) r = mid;
            else l = mid;
        }

        cout << r << "\n";
    }
    return 0;
}