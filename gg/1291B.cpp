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

ll a[300005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        bool f = true;
        cin >> n;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            if(max(a[i]-i, a[i]-(n-i-1)) < 0) f = false;
        }

        if(n%2 == 0 && a[n/2] < n/2 && a[n/2-1] < n/2) f = false;
        if(f) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}