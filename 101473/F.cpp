#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define rep(i,a,n) for(int (i)=(a);(i) < (n);i++)
#define vll vector<ll>
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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    ll n; cin >> n;
    vll a(n);
    rep(i,0,n)
    {
        cin >> a[i];
    }
    vll sum(n);
    sum[0]=a[0];
    set<ll> val;
    val.insert(sum[0]);
    rep(i,1,n)
    {
        sum[i]=sum[i-1]+a[i];
        val.insert(sum[i]);
    }
    if(sum[n-1]%3)
    {
        cout << "0"; return 0;
    }
    ll aux=sum[n-1]/3;
    ll cont=0;
    for(int i=0;sum[i]<=aux;i++)
        if(val.count(sum[i]+aux) && val.count(sum[i]+aux*2))
            cont++;
    cout << cont <<"\n";
    
    return 0;
}