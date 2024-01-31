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


ll red[100005];
ll blue[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n, nmin = LLONG_MAX, nmax = LLONG_MIN;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> red[i]:
    for(int i = 0; i < n; i++) cin >> blue[i]:
    sort(red, red+n);
    sort(blue, blue+n, greater<ll>());

    for(int i = 0; i < n; i++){
        nmin = min(nmin, blue[i]+red[i]);
        nmax = max(nmax, blue[i]+red[i]);
    }

    cout << nmax-nmin << "\n";
    return 0;
}