#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define f first
#define s second
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
//----------------------------------------------

ll ar[200005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n, k, x;
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar+n);
    vector<ll> g;
    for(int i = 0; i < n-1; i++) if(ar[i+1] - ar[i] > x) g.push_back(ar[i+1] - ar[i] - 1);
    sort(g.begin(), g.end());
    ll ans = g.size()+1;
    for(auto it: g){
        if(k - (it/x) < 0) break;
        k -= (it/x);
        ans--;
    }
    cout << ans << "\n";
    return 0;
}