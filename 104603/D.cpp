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
    
    ll n;
    cin >> n;

    ll a[n],b[n];

    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];
    
    ll ini = 0, fin = 1000000000;
    ll ans = 0;
    while(ini <= fin){
        ll mid = (ini + fin)/2;
        ll resto = 0;
        bool sepuede = true;
        for(int i = 0; i < n; i++){
            if(a[i]*mid > resto + b[i]){
                sepuede = false;
                break;
            }else{
                resto = resto + b[i] - a[i]*mid;
            }
        }
        if(sepuede){
            ans = mid;
            ini = mid + 1;
        }else fin = mid - 1;
    }

    cout << ans << '\n';
    
    return 0;
}